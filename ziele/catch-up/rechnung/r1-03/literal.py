"""Literal one-number-at-a-time model of Catch-Up({1..N}), used to cross-check catchup.cpp.

Rules as in the paper's rule box (p. 38): P1 removes one number; then the acting player
removes numbers one by one until her score equals or exceeds the opponent's; if the set
runs out first, the game ends (rule 3: she receives the remaining numbers anyway).

A node is (remaining mask, mover score - opponent score, turn_started).  The mover picks
any remaining number.  After a pick: if the set is empty the game ends; if the mover is
level or ahead the turn passes; otherwise the same player continues.

Besides the minimax value this computes, for comparison with Table 5 of the paper:
  - number of complete play sequences (must be N!) and win/tie/loss counts for P1,
  - minimum game depth in turns,
  - max branching factor = max(N, max over first moves of the number of P2 reply sequences).

Usage: python3 literal.py NMAX
"""
import sys
from functools import lru_cache


def analyse(n):
    full = (1 << n) - 1

    @lru_cache(maxsize=None)
    def value(rem, diff, p1_to_move):
        """Minimax value for P1 (+1 win, 0 draw, -1 loss).  diff = mover - opponent."""
        if rem == 0:
            p1_diff = diff if p1_to_move else -diff
            return (p1_diff > 0) - (p1_diff < 0)
        vals = []
        for x in range(1, n + 1):
            if not rem >> (x - 1) & 1:
                continue
            r2, d2 = rem & ~(1 << (x - 1)), diff + x
            if r2 == 0:
                p1_diff = d2 if p1_to_move else -d2
                vals.append((p1_diff > 0) - (p1_diff < 0))
            elif d2 >= 0:
                vals.append(value(r2, -d2, not p1_to_move))
            else:
                vals.append(value(r2, d2, p1_to_move))
        return max(vals) if p1_to_move else min(vals)

    @lru_cache(maxsize=None)
    def counts(rem, diff, p1_to_move):
        """(win, tie, loss, min_turns_remaining) over all play sequences, P1's view."""
        w = t = l = 0
        best_depth = None
        for x in range(1, n + 1):
            if not rem >> (x - 1) & 1:
                continue
            r2, d2 = rem & ~(1 << (x - 1)), diff + x
            if r2 == 0:
                p1_diff = d2 if p1_to_move else -d2
                cw, ct, cl, dep = (p1_diff > 0), (p1_diff == 0), (p1_diff < 0), 1
            elif d2 >= 0:
                cw, ct, cl, dep = counts(r2, -d2, not p1_to_move)
                dep += 1
            else:
                cw, ct, cl, dep = counts(r2, d2, p1_to_move)
            w, t, l = w + cw, t + ct, l + cl
            best_depth = dep if best_depth is None else min(best_depth, dep)
        return w, t, l, best_depth

    @lru_cache(maxsize=None)
    def turn_sequences(rem, diff):
        """Number of distinct pick sequences that make up one turn from this node."""
        total = 0
        for x in range(1, n + 1):
            if not rem >> (x - 1) & 1:
                continue
            r2, d2 = rem & ~(1 << (x - 1)), diff + x
            total += 1 if (r2 == 0 or d2 >= 0) else turn_sequences(r2, d2)
        return total

    v = value(full, 0, True)
    first = {x: value(full & ~(1 << (x - 1)), -x, False) for x in range(1, n + 1)}
    w, t, l, depth = counts(full, 0, True)
    replies = max(turn_sequences(full & ~(1 << (x - 1)), -x) for x in range(1, n + 1)) if n > 1 else 0
    return v, first, (w, t, l), depth, max(n, replies)


def multiset_value(numbers):
    """Literal minimax for an arbitrary multiset S (paper Fig. 5).

    Returns (value for P1, {first number: value for P1})."""

    @lru_cache(maxsize=None)
    def value(rem, diff, p1_to_move):
        if not rem:
            p1_diff = diff if p1_to_move else -diff
            return (p1_diff > 0) - (p1_diff < 0)
        vals = []
        for i, x in enumerate(rem):
            if i > 0 and rem[i - 1] == x:
                continue  # equal numbers are interchangeable
            r2, d2 = rem[:i] + rem[i + 1:], diff + x
            if not r2:
                p1_diff = d2 if p1_to_move else -d2
                vals.append((p1_diff > 0) - (p1_diff < 0))
            elif d2 >= 0:
                vals.append(value(r2, -d2, not p1_to_move))
            else:
                vals.append(value(r2, d2, p1_to_move))
        return max(vals) if p1_to_move else min(vals)

    rem = tuple(sorted(numbers))
    first = {}
    for i, x in enumerate(rem):
        first[x] = value(rem[:i] + rem[i + 1:], -x, False)
    return value(rem, 0, True), first


def main():
    nmax = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    print("N\tvalue\tfirst_move_values\tsequences\twin%\ttie%\tloss%\tmin_depth\tmax_branch")
    for n in range(1, nmax + 1):
        v, first, (w, t, l), depth, br = analyse(n)
        tot = w + t + l
        fm = ",".join(f"{x}:{first[x]:+d}" for x in sorted(first))
        print(f"{n}\t{v:+d}\t{fm}\t{tot}\t{100*w/tot:.2f}\t{100*t/tot:.2f}\t{100*l/tot:.2f}\t{depth}\t{br}")
        sys.stdout.flush()


if __name__ == "__main__":
    main()
