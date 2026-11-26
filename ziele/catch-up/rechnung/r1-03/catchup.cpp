// Catch-Up({1..N}) solver: game value under optimal play for both players.
//
// Rules (Isaksen, Ismail, Brams, Nealen, "Catch-Up: A Game in Which the Lead
// Alternates", Game & Puzzle Design 1(2), 2015, rule box on p. 38):
//   1. Both scores start at 0. P1 removes one number from S and adds it to her score.
//   2. Players then alternate; on a turn the acting player removes one or more
//      numbers, one by one, until her score equals or exceeds the opponent's.
//   3. If that is no longer possible, the acting player receives all remaining
//      numbers. Higher score wins; equal scores is a draw.
//
// State at the start of a turn: R = remaining numbers (bitmask, bit i-1 = number i),
// D = opponent score minus mover score (always >= 0 by rule 2).
// A turn takes a set T of numbers. T is legal iff
//   (a) sum(R) < D and T = R                      (rule 3: cannot catch up, takes rest), or
//   (b) sum(R) >= D, T nonempty, sum(T) >= D, and T can be ordered so that every
//       proper prefix has sum < D, i.e. |T| = 1 or sum(T) - max(T) < D.
//       (Put max(T) last; the longest proper prefix then has the smallest possible sum,
//       so this is the weakest prefix condition. With D = 0, i.e. a tied start incl.
//       P1's first move, only |T| = 1 is possible, matching rule 1.)
// After the turn the opponent faces R \ T with deficit sum(T) - D.
// Value V(R, D) in {-1, 0, +1} from the mover's view:
//   R empty: 0 if D == 0, -1 if D > 0, +1 if D < 0 (D < 0 only after rule 3).
//
// Usage:
//   catchup [NMIN NMAX]          table for N = NMIN..NMAX (default 1 20)
//   catchup pos N D a b c ...    position: remaining {a,b,c,...} from {1..N}, mover has
//                                deficit D; prints the value and every legal move's value.
// Compile with -DMIN_LAST to get a deliberately WRONG rule (prefix condition
// sum(T) - min(T) < D, i.e. smallest number last). It is the bug found in the first
// version of this program and serves as the negative control for compare.py.
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <string>
#include <vector>

static int N;
static std::vector<int8_t> memo;  // index R*(N+1)+D, value+1 stored, 3 = unknown
static uint64_t evaluated = 0;

static int sumMask(uint32_t R) {
  int s = 0;
  for (int i = 1; i <= N; ++i)
    if (R >> (i - 1) & 1u) s += i;
  return s;
}

// Calls f(T) for every legal move T (bitmask) from (R, D), R nonempty. Stops when f
// returns true. Each legal set T is produced exactly once.
using MoveFn = std::function<bool(uint32_t)>;

// S grows in increasing element order over [startElem, hi]; invariant sum(S) < D.
static bool extend(uint32_t R, int D, int m, int startElem, int hi, int sumS, uint32_t Smask,
                   const MoveFn &f) {
  if (sumS + m >= D && f(Smask | (1u << (m - 1)))) return true;
  for (int e = startElem; e <= hi; ++e) {
    if (!(R >> (e - 1) & 1u)) continue;
    if (sumS + e >= D) break;  // larger elements also violate sum(S) < D
    if (extend(R, D, m, e + 1, hi, sumS + e, Smask | (1u << (e - 1)), f)) return true;
  }
  return false;
}

static void forEachMove(uint32_t R, int D, const MoveFn &f) {
  if (sumMask(R) < D) {  // rule 3: cannot catch up, receives all remaining numbers
    f(R);
    return;
  }
  for (int m = 1; m <= N; ++m) {
    if (!(R >> (m - 1) & 1u)) continue;
#ifdef MIN_LAST
    if (extend(R, D, m, m + 1, N, 0, 0, f)) return;  // WRONG on purpose (negative control)
#else
    if (extend(R, D, m, 1, m - 1, 0, 0, f)) return;  // m = max(T) is taken last
#endif
  }
}

static int V(uint32_t R, int D) {
  // Game over. D < 0 happens after rule 3: the previous mover took all and ended behind.
  if (R == 0) return D == 0 ? 0 : (D > 0 ? -1 : 1);
  int8_t &cell = memo[(size_t)R * (N + 1) + D];
  if (cell != 3) return cell - 1;
  ++evaluated;
  int best = -2;
  forEachMove(R, D, [&](uint32_t T) {
    int v = -V(R & ~T, sumMask(T) - D);
    if (v > best) best = v;
    return best == 1;
  });
  cell = (int8_t)(best + 1);
  return best;
}

static std::string setStr(uint32_t T) {
  std::string s = "{";
  for (int i = 1; i <= N; ++i)
    if (T >> (i - 1) & 1u) s += (s.size() > 1 ? "," : "") + std::to_string(i);
  return s + "}";
}

static int position(int argc, char **argv) {
  N = atoi(argv[2]);
  int D = atoi(argv[3]);
  uint32_t R = 0;
  for (int i = 4; i < argc; ++i) R |= 1u << (atoi(argv[i]) - 1);
  memo.assign((size_t)(1u << N) * (N + 1), 3);
  printf("position %s deficit %d: value %+d (mover's view)\n", setStr(R).c_str(), D, V(R, D));
  forEachMove(R, D, [&](uint32_t T) {
    printf("  move %s -> %s:%d  value %+d\n", setStr(T).c_str(), setStr(R & ~T).c_str(),
           sumMask(T) - D, -V(R & ~T, sumMask(T) - D));
    return false;
  });
  return 0;
}

int main(int argc, char **argv) {
  if (argc > 1 && strcmp(argv[1], "pos") == 0) return position(argc, argv);
  int nmin = argc > 1 ? atoi(argv[1]) : 1;
  int nmax = argc > 2 ? atoi(argv[2]) : 20;
  printf("N\tsum\tparity\tvalue\tresult\tbest_first_moves\tcount_best\tfirst_move_values\tstates\tseconds\n");
  for (N = nmin; N <= nmax; ++N) {
    auto t0 = std::chrono::steady_clock::now();
    memo.assign((size_t)(1u << N) * (N + 1), 3);
    evaluated = 0;
    uint32_t full = (1u << N) - 1;
    int val = V(full, 0);
    // Value of each first move (P1 takes exactly one number x; P2 then has deficit x).
    std::vector<int> fv(N + 1);
    for (int x = 1; x <= N; ++x) fv[x] = -V(full & ~(1u << (x - 1)), x);
    double secs = std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
    int s = N * (N + 1) / 2;
    const char *res = val == 1 ? "P1 wins" : (val == -1 ? "P2 wins" : "draw");
    std::string best, all;
    int cnt = 0;
    for (int x = 1; x <= N; ++x) {
      if (fv[x] == val) {
        best += (cnt ? "," : "") + std::to_string(x);
        ++cnt;
      }
      all += (x > 1 ? "," : "") + std::to_string(x) + ":" + (fv[x] > 0 ? "+" : "") +
             std::to_string(fv[x]);
    }
    printf("%d\t%d\t%s\t%+d\t%s\t%s\t%d\t%s\t%llu\t%.2f\n", N, s, s % 2 ? "odd" : "even", val,
           res, best.c_str(), cnt, all.c_str(), (unsigned long long)evaluated, secs);
    fflush(stdout);
  }
  return 0;
}
