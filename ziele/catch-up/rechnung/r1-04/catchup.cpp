// catch-up R1-04: exact solver for Catch-Up({1,...,N}), N = 1..20.
//
// Rules (Isaksen, Ismail, Brams, Nealen, "Catch-Up: A Game in Which the Lead
// Alternates", Game & Puzzle Design 1(2), 2015, rules box on p. 38):
//   1. Both scores start at 0. P1 starts by removing one number from S.
//   2. Players then take turns removing one or more numbers from S, one by one,
//      until the acting player's score equals or exceeds the opponent's score.
//   3. When this is no longer possible, the acting player receives all remaining
//      numbers. Higher score wins; equal scores are a draw.
//
// State model used here: (remaining set R, k) where k >= 0 is the deficit of
// the acting player (opponent score minus acting score). The acting player
// removes one number x at a time. With e = x - k:
//   e >= 0  -> the turn ends, the opponent becomes acting with deficit e;
//   e <  0  -> the same player continues with deficit k - x.
// Rule 3 is covered automatically: a player who cannot catch up keeps taking
// numbers until R is empty (every order gives the same final score).
// P1's first move is a single number because k = 0 at the start.
// Value V(R,k) is from the acting player's view: +1 win, 0 draw, -1 loss.
//
// The scores themselves are not needed: s1 + s2 = T(N) - sum(R), and k gives the
// difference.
//
// Option --strict switches to a deliberately WRONG rule (turn ends only when the
// acting player is strictly ahead). It exists as a negative control: the
// comparison with the paper must fail under it.
//
// Build: g++ -O2 -std=c++17 -o build/catchup catchup.cpp
// Run:   ./build/catchup            (paper rules)
//        ./build/catchup --strict   (negative control, must report FAIL)

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

static bool g_strict = false;
static inline bool ends_turn(int e) { return g_strict ? (e > 0) : (e >= 0); }

static const int NMAX = 20;          // values for all N <= 20
static const int KDIM = NMAX + 1;    // k in 0..20
static const int NCOUNT = 18;        // permutation counts / state space up to N = 18

static std::vector<int8_t> V;        // V[mask*KDIM + k]
static std::vector<uint8_t> LMIN;    // minimal number of further turns

static inline size_t idx(uint32_t mask, int k) { return (size_t)mask * KDIM + k; }

// ---------------------------------------------------------------------------
// 1. Bitmask solver (bit i-1 <-> number i). Bottom-up: a child mask is
//    numerically smaller than its parent, so increasing order is valid.
// ---------------------------------------------------------------------------
static void solve_values() {
    const uint32_t FULL = 1u << NMAX;
    V.assign((size_t)FULL * KDIM, 0);
    LMIN.assign((size_t)FULL * KDIM, 0);
    for (uint32_t mask = 0; mask < FULL; ++mask) {
        for (int k = 0; k <= NMAX; ++k) {
            if (mask == 0) {
                V[idx(0, k)] = (k > 0) ? -1 : 0;
                LMIN[idx(0, k)] = 0;
                continue;
            }
            int best = -2;
            int lmin = 255;
            for (uint32_t m = mask; m; m &= m - 1) {
                int b = __builtin_ctz(m);
                int x = b + 1;
                uint32_t m2 = mask & ~(1u << b);
                int e = x - k;
                int v, l;
                if (ends_turn(e)) {
                    v = -V[idx(m2, e)];
                    l = (m2 == 0) ? 0 : 1 + LMIN[idx(m2, e)];
                } else {
                    v = V[idx(m2, k - x)];
                    l = LMIN[idx(m2, k - x)];
                }
                if (v > best) best = v;
                if (l < lmin) lmin = l;
            }
            V[idx(mask, k)] = (int8_t)best;
            LMIN[idx(mask, k)] = (uint8_t)lmin;
        }
    }
}

// ---------------------------------------------------------------------------
// 2. Outcome counts over all N! removal orders (paper Table 5, win/tie/loss %).
//    W, T = number of orders that end in a win / draw for the acting player.
// ---------------------------------------------------------------------------
static const int KC = NCOUNT + 1;
static std::vector<uint64_t> CW, CT;
static uint64_t fact[NMAX + 1];

static void solve_counts() {
    fact[0] = 1;
    for (int i = 1; i <= NMAX; ++i) fact[i] = fact[i - 1] * (uint64_t)i;
    const uint32_t FULL = 1u << NCOUNT;
    CW.assign((size_t)FULL * KC, 0);
    CT.assign((size_t)FULL * KC, 0);
    for (uint32_t mask = 0; mask < FULL; ++mask) {
        for (int k = 0; k <= NCOUNT; ++k) {
            size_t id = (size_t)mask * KC + k;
            if (mask == 0) {
                CW[id] = 0;
                CT[id] = (k == 0) ? 1 : 0;
                continue;
            }
            uint64_t ctot = fact[__builtin_popcount(mask) - 1];
            uint64_t w = 0, t = 0;
            for (uint32_t m = mask; m; m &= m - 1) {
                int b = __builtin_ctz(m);
                int x = b + 1;
                uint32_t m2 = mask & ~(1u << b);
                int e = x - k;
                if (ends_turn(e)) {
                    size_t c = (size_t)m2 * KC + e;
                    w += ctot - CW[c] - CT[c];  // opponent's losses
                    t += CT[c];
                } else {
                    size_t c = (size_t)m2 * KC + (k - x);
                    w += CW[c];
                    t += CT[c];
                }
            }
            CW[id] = w;
            CT[id] = t;
        }
    }
}

// ---------------------------------------------------------------------------
// 3. Reachable state space for one N.
//    The paper (Sec. 4.5) tracks "current player, current score and numbers
//    remaining" and draws its trees with one node per turn. The counting rule
//    that reproduces Table 5 exactly (identified in this run, see report):
//      non-terminal states at the START of a turn, keyed (R, k, player to move)
//    + terminal states, keyed (final s1 - s2, player who made the last move).
//    flag bits per (mask,k): 1 = turn start, P1 to move; 2 = turn start, P2;
//                            4 = mid-turn, P1 acting;    8 = mid-turn, P2.
// ---------------------------------------------------------------------------
struct StateCounts {
    uint64_t turn_nonterminal;  // (R nonempty, k, player) at turn starts
    uint64_t terminals;         // (final difference, last mover)
    uint64_t paper_def;         // sum of the two (paper's definition)
    uint64_t all_with_mid;      // every reachable (R, k, player), incl. mid-turn and terminal
};

static StateCounts count_states(int N) {
    const uint32_t FULL = 1u << N;
    const int K = N + 1;
    std::vector<uint8_t> flag((size_t)FULL * K, 0);
    std::vector<uint64_t> stack;  // encoded (mask, k, p)
    std::set<std::pair<int, int>> terms;
    auto enc = [&](uint32_t mask, int k, int p) { return ((uint64_t)mask << 8) | ((uint64_t)k << 1) | (uint64_t)p; };
    auto mark = [&](uint32_t mask, int k, int p, bool turnstart) {
        uint8_t &f = flag[(size_t)mask * K + k];
        uint8_t seen = (uint8_t)(p ? 10 : 5);
        bool fresh = (f & seen) == 0;
        f |= (uint8_t)(turnstart ? (p ? 2 : 1) : (p ? 8 : 4));
        if (fresh) stack.push_back(enc(mask, k, p));
    };
    mark(FULL - 1, 0, 0, true);
    while (!stack.empty()) {
        uint64_t s = stack.back();
        stack.pop_back();
        uint32_t mask = (uint32_t)(s >> 8);
        int k = (int)((s >> 1) & 127);
        int p = (int)(s & 1);
        for (uint32_t m = mask; m; m &= m - 1) {
            int b = __builtin_ctz(m);
            int x = b + 1;
            uint32_t m2 = mask & ~(1u << b);
            int e = x - k;
            int lead;  // acting player's lead after this removal
            if (ends_turn(e)) {
                mark(m2, e, 1 - p, true);
                lead = e;
            } else {
                mark(m2, k - x, p, false);
                lead = -(k - x);
            }
            if (m2 == 0) terms.insert({p == 0 ? lead : -lead, p});
        }
    }
    StateCounts c{0, 0, 0, 0};
    for (uint32_t mask = 0; mask < FULL; ++mask)
        for (int k = 0; k < K; ++k) {
            uint8_t f = flag[(size_t)mask * K + k];
            if (!f) continue;
            c.all_with_mid += ((f & 5) ? 1 : 0) + ((f & 10) ? 1 : 0);
            if (mask != 0) c.turn_nonterminal += ((f & 1) ? 1 : 0) + ((f & 2) ? 1 : 0);
        }
    c.terminals = terms.size();
    c.paper_def = c.turn_nonterminal + c.terminals;
    return c;
}

// ---------------------------------------------------------------------------
// 4. Turn enumeration from a turn-start state: number of ordered sequences,
//    number of distinct sets taken, maximal points in one turn.
// ---------------------------------------------------------------------------
struct TurnEnum {
    uint64_t sequences = 0;
    std::unordered_set<uint32_t> sets;
    int maxpoints = 0;
};

static void enum_turn(uint32_t mask, int k, uint32_t taken, int pts, TurnEnum &te) {
    if (mask == 0) {  // ran out of numbers (rule 3)
        te.sequences++;
        te.sets.insert(taken);
        te.maxpoints = std::max(te.maxpoints, pts);
        return;
    }
    for (uint32_t m = mask; m; m &= m - 1) {
        int b = __builtin_ctz(m);
        int x = b + 1;
        uint32_t m2 = mask & ~(1u << b);
        int e = x - k;
        if (ends_turn(e)) {
            te.sequences++;
            te.sets.insert(taken | (1u << b));
            te.maxpoints = std::max(te.maxpoints, pts + x);
        } else {
            enum_turn(m2, k - x, taken | (1u << b), pts + x, te);
        }
    }
}

// ---------------------------------------------------------------------------
// 5. Independent generic solver on multisets (slow, map-memoised). Used for
//    the paper's figures (including the multiset {2,2,2,3,3}) and to
//    cross-check the bitmask solver.
// ---------------------------------------------------------------------------
using MS = std::vector<int>;  // sorted multiset
static std::map<std::pair<MS, int>, int> gmemo;

static int gvalue(const MS &r, int k) {
    if (r.empty()) return (k > 0) ? -1 : 0;
    auto key = std::make_pair(r, k);
    auto it = gmemo.find(key);
    if (it != gmemo.end()) return it->second;
    int best = -2;
    for (size_t i = 0; i < r.size(); ++i) {
        if (i > 0 && r[i] == r[i - 1]) continue;
        MS r2 = r;
        r2.erase(r2.begin() + (long)i);
        int x = r[i];
        int e = x - k;
        int v = ends_turn(e) ? -gvalue(r2, e) : gvalue(r2, k - x);
        best = std::max(best, v);
    }
    gmemo[key] = best;
    return best;
}

// All turn options from (r, k) as multisets taken, with the value for the
// acting player after taking them.
static void genum(const MS &r, int k, MS taken, std::map<MS, int> &out) {
    if (r.empty()) {
        out[taken] = (k > 0) ? -1 : 0;
        return;
    }
    for (size_t i = 0; i < r.size(); ++i) {
        if (i > 0 && r[i] == r[i - 1]) continue;
        MS r2 = r;
        r2.erase(r2.begin() + (long)i);
        MS t2 = taken;
        t2.push_back(r[i]);
        std::sort(t2.begin(), t2.end());
        int x = r[i];
        int e = x - k;
        if (ends_turn(e)) out[t2] = -gvalue(r2, e);
        else genum(r2, k - x, t2, out);
    }
}

static std::string ms_str(const MS &m) {
    std::string s = "{";
    for (size_t i = 0; i < m.size(); ++i) s += (i ? "," : "") + std::to_string(m[i]);
    return s + "}";
}

// ---------------------------------------------------------------------------
// 6. Play a fixed removal order and report turns and final scores.
// ---------------------------------------------------------------------------
static std::string trace(const std::vector<int> &order, int &s1, int &s2) {
    int s[2] = {0, 0};
    int p = 0;
    std::string out = "[";
    bool newturn = true;
    for (size_t i = 0; i < order.size(); ++i) {
        if (newturn) out += (i ? "] [" : "");
        else out += ",";
        newturn = false;
        out += std::to_string(order[i]);
        s[p] += order[i];
        if (s[p] - s[1 - p] >= 0 && !(g_strict && s[p] == s[1 - p])) {
            p = 1 - p;
            newturn = true;
        }
    }
    out += "]";
    s1 = s[0];
    s2 = s[1];
    return out;
}

// ---------------------------------------------------------------------------
// Paper data (Table 2 and Table 5), index by N.
// ---------------------------------------------------------------------------
static const int PAPER_T2[21] = {99, 99, 99, 0, 0, 1, 1, 0, 0, -1, -1, 0, 0, 1, -1, 0, 0, 1, -1, 0, 0};
struct T5 { int N; long long states; int value; int branch; int depth; double win, tie, loss; };
static const T5 PAPER_T5[] = {
    {3, 11, 0, 3, 2, 16.67, 66.67, 16.67},
    {4, 33, 0, 6, 2, 33.33, 33.33, 33.33},
    {5, 90, 1, 16, 3, 50.00, 0.00, 50.00},
    {6, 236, 1, 36, 3, 50.00, 0.00, 50.00},
    {7, 591, 0, 78, 3, 38.57, 22.86, 38.57},
    {8, 1453, 0, 150, 4, 38.93, 22.14, 38.93},
    {9, 3484, -1, 272, 4, 50.00, 0.00, 50.00},
    {10, 8174, -1, 474, 4, 50.00, 0.00, 50.00},
    {11, 18799, 0, 886, 5, 41.90, 16.19, 41.90},
    {12, 42587, 0, 1470, 5, 42.47, 15.06, 42.47},
    {13, 95126, 1, 2448, 5, 50.00, 0.00, 50.00},
    {14, 210064, -1, 3894, 6, 50.00, 0.00, 50.00},
    {15, 459225, 0, 6158, 6, 43.86, 12.28, 43.86},
    {16, 995349, 0, 10284, 6, 44.23, 11.53, 44.23},
    {17, 2141652, 1, 16048, 6, 50.00, 0.00, 50.00},
    {18, 4579850, -1, 24762, 7, 50.00, 0.00, 50.00},
};

static int fails = 0;
static void check(bool ok, const char *what) {
    std::printf("  [%s] %s\n", ok ? "ok" : "FAIL", what);
    if (!ok) fails++;
}

static const char *vname(int v) { return v > 0 ? "P1 wins" : (v < 0 ? "P2 wins" : "draw"); }

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i)
        if (std::strcmp(argv[i], "--strict") == 0) g_strict = true;
    auto t0 = std::chrono::steady_clock::now();
    auto secs = [&]() { return std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count(); };

    std::printf("Catch-Up({1..N}) solver, rule variant: %s\n\n",
                g_strict ? "STRICT (negative control, intentionally wrong)" : "paper (turn ends when score >= opponent)");

    // --- Positive control A: example games from the paper (traces) ---------
    std::printf("== Control A: example games (Fig. 1, Sec. 2.1, Sec. 2.4) ==\n");
    {
        int a, b;
        std::string t = trace({3, 2, 4, 1}, a, b);
        std::printf("  3,2,4,1 -> turns %s, final %d-%d\n", t.c_str(), a, b);
        check(t == "[3] [2,4] [1]" && a == 4 && b == 6, "Fig. 1: P2 wins 4-6 with turns <3>,<2,4>,<1>");
        t = trace({2, 1, 4, 3}, a, b);
        std::printf("  2,1,4,3 -> turns %s, final %d-%d\n", t.c_str(), a, b);
        check(t == "[2] [1,4] [3]" && a == 5 && b == 5, "Sec. 2.1: draw 5-5 with <2>,<1,4>,<3>");
        t = trace({5, 1, 3, 4, 2}, a, b);
        std::printf("  5,1,3,4,2 -> turns %s, final %d-%d\n", t.c_str(), a, b);
        check(t == "[5] [1,3,4] [2]" && a == 7 && b == 8, "Sec. 2.4: P1 loses 7-8 with <5>,<1,3,4>,<2>");
    }

    // --- Positive control B: positions from the figures (generic solver) --
    std::printf("\n== Control B: positions from Figs. 2-5 (generic multiset solver) ==\n");
    {
        int v = gvalue({1, 2, 3, 4}, 0);
        std::printf("  Fig. 2 {1,2,3,4}:0 value for P1 = %d\n", v);
        check(v == 0, "Fig. 2: Catch-Up({1,2,3,4}) is a draw");

        std::map<MS, int> mv;
        genum({1, 2, 4, 7}, 4, {}, mv);
        int nw = 0, nd = 0, nl = 0;
        std::string wins, draws;
        for (auto &kv : mv) {
            if (kv.second > 0) { nw++; wins += ms_str(kv.first); }
            else if (kv.second == 0) { nd++; draws += ms_str(kv.first); }
            else nl++;
        }
        std::printf("  Fig. 3a {1,2,4,7}:4 moves=%zu win=%d %s draw=%d %s loss=%d\n", mv.size(), nw, wins.c_str(), nd,
                    draws.c_str(), nl);
        check(mv.size() == 8 && nw == 1 && nd == 1 && nl == 6 && mv[MS{1, 2, 7}] == 1,
              "Fig. 3a: 8 moves, only {1,2,7} wins, one draws, six lose");

        mv.clear();
        genum({1, 3, 4, 6}, 4, {}, mv);
        std::printf("  Fig. 3b {1,3,4,6}:4 {1,6}=%d {3,6}=%d {3,4}=%d value=%d\n", mv[MS{1, 6}], mv[MS{3, 6}],
                    mv[MS{3, 4}], gvalue({1, 3, 4, 6}, 4));
        check(mv[MS{1, 6}] == 1 && mv[MS{3, 6}] == 0 && mv[MS{3, 4}] == -1,
              "Fig. 3b: <1,6> wins, <3,6> draws, <3,4> loses");

        mv.clear();
        genum({3, 4, 7}, 2, {}, mv);
        std::printf("  Fig. 4 {3,4,7}:2 value=%d, {3}=%d {4}=%d {7}=%d\n", gvalue({3, 4, 7}, 2), mv[MS{3}], mv[MS{4}],
                    mv[MS{7}]);
        check(gvalue({3, 4, 7}, 2) == -1 && mv[MS{7}] == -1 && mv[MS{3}] == -1 && mv[MS{4}] == -1,
              "Fig. 4: acting player (P1) loses with every move");
        // after <3>: P2 at {4,7} with deficit 1 must take 7 to win
        mv.clear();
        genum({4, 7}, 1, {}, mv);
        check(mv[MS{7}] == 1 && mv[MS{4}] != 1, "Fig. 4: after <3>, P2 must choose <7> to win");

        mv.clear();
        genum({2, 2, 2, 3, 3}, 0, {}, mv);
        std::printf("  Fig. 5 {2,2,2,3,3}:0 value=%d, first <2>=%d, first <3>=%d\n", gvalue({2, 2, 2, 3, 3}, 0),
                    mv[MS{2}], mv[MS{3}]);
        check(gvalue({2, 2, 2, 3, 3}, 0) == 1 && mv[MS{2}] == 1, "Fig. 5: P1 forces a win by first choosing <2>");

        int v2 = gvalue({2, 4, 6, 8, 10}, 0);
        std::printf("  Sec. 2.6 {2,4,6,8,10}:0 value=%d\n", v2);
        check(v2 != 0, "Sec. 2.6: {2,4,6,8,10} cannot be a draw");
    }

    // --- Main computation ---------------------------------------------------
    double ts = secs();
    solve_values();
    double tv = secs() - ts;
    std::printf("\nbitmask values for all subsets of {1..20}: %.2f s\n", tv);

    // --- Cross-check bitmask solver vs generic solver ------------------------
    std::printf("\n== Control C: bitmask solver vs generic solver ==\n");
    {
        long long cmp = 0, bad = 0;
        for (uint32_t mask = 0; mask < (1u << 10); ++mask)
            for (int k = 0; k <= 10; ++k) {
                MS r;
                for (int i = 0; i < 10; ++i)
                    if (mask >> i & 1) r.push_back(i + 1);
                cmp++;
                if (gvalue(r, k) != V[idx(mask, k)]) bad++;
            }
        for (int N = 1; N <= 13; ++N) {
            MS r;
            for (int i = 1; i <= N; ++i) r.push_back(i);
            uint32_t full = (1u << N) - 1;
            cmp++;
            if (gvalue(r, 0) != V[idx(full, 0)]) bad++;
            for (int x = 1; x <= N; ++x) {
                MS r2 = r;
                r2.erase(r2.begin() + (x - 1));
                cmp++;
                if (gvalue(r2, x) != V[idx(full & ~(1u << (x - 1)), x)]) bad++;
            }
        }
        std::printf("  compared %lld states, mismatches %lld\n", cmp, bad);
        check(bad == 0, "all subsets of {1..10} x k=0..10, and roots/first moves for N<=13 agree");
    }

    ts = secs();
    solve_counts();
    double tc = secs() - ts;

    // --- Results table --------------------------------------------------------
    std::printf("\n== Results: Catch-Up({1..N}), optimal play ==\n");
    std::printf("| N | T(N) | parity | value (P1) | best first moves | count | paper Table 2 |\n");
    std::printf("|---|---|---|---|---|---|---|\n");
    int t2_bad = 0, even_nondraw = 0;
    for (int N = 1; N <= NMAX; ++N) {
        uint32_t full = (1u << N) - 1;
        int v = V[idx(full, 0)];
        std::string best;
        int nb = 0;
        for (int x = 1; x <= N; ++x) {
            int vx = -V[idx(full & ~(1u << (x - 1)), x)];
            if (vx == v) {
                best += (nb ? "," : "") + std::to_string(x);
                nb++;
            }
        }
        int T = N * (N + 1) / 2;
        std::string paper = (N >= 3) ? std::to_string(PAPER_T2[N]) : "-";
        if (N >= 3 && PAPER_T2[N] != v) t2_bad++;
        if (T % 2 == 0 && v != 0) even_nondraw++;
        std::printf("| %d | %d | %s | %+d (%s) | %s | %d | %s |\n", N, T, T % 2 ? "odd" : "even", v, vname(v),
                    best.c_str(), nb, paper.c_str());
    }

    std::printf("\n== Control D: comparison with paper ==\n");
    check(t2_bad == 0, "Table 2 (N = 3..20): all optimal-play values agree");
    check(even_nondraw == 0, "Sec. 3.1: every even-sum N <= 20 is a draw");

    // Table 5
    std::printf("\n| N | state space (paper def.) | = turn starts + terminals | all incl. mid-turn | value | max branch (seq/sets) | min depth | win%% | tie%% | loss%% | P2 max pts (2N-2) |\n");
    std::printf("|---|---|---|---|---|---|---|---|---|---|---|\n");
    double tstate = 0;
    int t5_bad_value = 0, t5_bad_states = 0, t5_bad_branch = 0, t5_bad_depth = 0, t5_bad_pct = 0, bad_2n2 = 0;
    for (const T5 &p : PAPER_T5) {
        int N = p.N;
        uint32_t full = (1u << N) - 1;
        double tt = secs();
        StateCounts sc = count_states(N);
        tstate += secs() - tt;
        uint64_t maxseq = N, maxsets = N;
        int p2max = 0;
        for (int x = 1; x <= N; ++x) {
            TurnEnum te;
            enum_turn(full & ~(1u << (x - 1)), x, 0, 0, te);
            maxseq = std::max<uint64_t>(maxseq, te.sequences);
            maxsets = std::max<uint64_t>(maxsets, te.sets.size());
            p2max = std::max(p2max, te.maxpoints);
        }
        int depth = 1 + LMIN[idx(full, 0)];
        size_t id = (size_t)full * KC;
        double w = 100.0 * (double)CW[id] / (double)fact[N];
        double t = 100.0 * (double)CT[id] / (double)fact[N];
        double l = 100.0 - w - t;
        int v = V[idx(full, 0)];
        if (v != p.value) t5_bad_value++;
        if ((long long)sc.paper_def != p.states) t5_bad_states++;
        if ((long long)maxseq != p.branch) t5_bad_branch++;
        if (depth != p.depth) t5_bad_depth++;
        if (std::fabs(w - p.win) > 0.0051 || std::fabs(t - p.tie) > 0.0051 || std::fabs(l - p.loss) > 0.0051) t5_bad_pct++;
        if (p2max != 2 * N - 2) bad_2n2++;
        std::printf("| %d | %llu (paper %lld) | %llu + %llu | %llu | %+d | %llu / %llu (paper %d) | %d (paper %d) | %.2f | %.2f | %.2f | %d (%d) |\n",
                    N, (unsigned long long)sc.paper_def, p.states, (unsigned long long)sc.turn_nonterminal,
                    (unsigned long long)sc.terminals, (unsigned long long)sc.all_with_mid, v,
                    (unsigned long long)maxseq, (unsigned long long)maxsets, p.branch, depth, p.depth, w, t, l, p2max,
                    2 * N - 2);
    }
    check(t5_bad_value == 0, "Table 5: P1 optimal play value N = 3..18");
    check(t5_bad_states == 0, "Table 5: state-space size (turn starts with player + terminals by (diff, last mover)) N = 3..18");
    check(t5_bad_branch == 0, "Table 5: max branching factor (ordered sequences) N = 3..18");
    check(t5_bad_depth == 0, "Table 5: minimal game depth N = 3..18");
    check(t5_bad_pct == 0, "Table 5: win/tie/loss % over all N! removal orders N = 3..18");
    check(bad_2n2 == 0, "Sec. 4.3: max points of P2 on his first turn = 2N-2, N = 3..18");

    std::printf("\nTiming: values %.2f s, counts %.2f s, state spaces %.2f s, total %.2f s\n", tv, tc, tstate, secs());
    std::printf("\nSUMMARY: %s (%d failed checks)\n", fails ? "FAIL" : "PASS", fails);
    return fails ? 1 : 0;
}
