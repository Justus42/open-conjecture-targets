"""Compare catchup.cpp output with the statements of the paper (positive control).

Paper: Isaksen, Ismail, Brams, Nealen, "Catch-Up: A Game in Which the Lead Alternates",
Game & Puzzle Design 1(2), 2015 (MPRA paper 108784).

Usage: python3 compare.py SOLVER_BINARY [LITERAL_NMAX]
Exit code 0 iff every check passes.  Run with the -DMIN_LAST build as negative control:
that build must fail.
"""
import importlib.util
import math
import os
import subprocess
import sys

# Table 2 (p. 42): optimal play value for P1, N = 3..20.
TABLE2 = {3: 0, 4: 0, 5: 1, 6: 1, 7: 0, 8: 0, 9: -1, 10: -1, 11: 0, 12: 0, 13: 1, 14: -1,
          15: 0, 16: 0, 17: 1, 18: -1, 19: 0, 20: 0}
# Table 5 (p. 45), column "P1 optimal play value", N = 3..18.
TABLE5_VALUE = {3: 0, 4: 0, 5: 1, 6: 1, 7: 0, 8: 0, 9: -1, 10: -1, 11: 0, 12: 0, 13: 1,
                14: -1, 15: 0, 16: 0, 17: 1, 18: -1}
# Table 5: max branch factor, min depth, win %, tie %, loss % (N = 3..10 checked here).
TABLE5_STATS = {3: (3, 2, 16.67, 66.67, 16.67), 4: (6, 2, 33.33, 33.33, 33.33),
                5: (16, 3, 50.00, 0.00, 50.00), 6: (36, 3, 50.00, 0.00, 50.00),
                7: (78, 3, 38.57, 22.86, 38.57), 8: (150, 4, 38.93, 22.14, 38.93),
                9: (272, 4, 50.00, 0.00, 50.00), 10: (474, 4, 50.00, 0.00, 50.00)}

failures = []


def check(name, ok, detail=""):
    print(f"{'PASS' if ok else 'FAIL'}  {name}{('  -- ' + detail) if detail else ''}")
    if not ok:
        failures.append(name)


def run(args):
    return subprocess.run(args, capture_output=True, text=True, check=True).stdout


def parse_table(text):
    rows = {}
    lines = text.strip().splitlines()
    header = lines[0].split("\t")
    for line in lines[1:]:
        r = dict(zip(header, line.split("\t")))
        fm = {int(a): int(b) for a, b in (p.split(":") for p in r["first_move_values"].split(","))}
        rows[int(r["N"])] = (int(r["value"]), fm)
    return rows


def parse_pos(text):
    lines = text.strip().splitlines()
    value = int(lines[0].split("value ")[1].split()[0])
    moves = {}
    for line in lines[1:]:
        t = line.split("move ")[1].split(" ->")[0]
        moves[t] = int(line.split("value ")[1])
    return value, moves


def main():
    solver = sys.argv[1]
    lit_nmax = int(sys.argv[2]) if len(sys.argv) > 2 else 10
    here = os.path.dirname(os.path.abspath(__file__))
    spec = importlib.util.spec_from_file_location("literal", os.path.join(here, "literal.py"))
    literal = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(literal)

    table = parse_table(run([solver, "1", "20"]))

    # 1. Table 2 and Table 5 value column.
    for n, v in TABLE2.items():
        check(f"Table 2, N={n}: value {v:+d}", table[n][0] == v, f"program {table[n][0]:+d}")
    for n, v in TABLE5_VALUE.items():
        check(f"Table 5 value, N={n}: {v:+d}", table[n][0] == v, f"program {table[n][0]:+d}")
    # Section 2.6/3.1: even-sum N <= 20 are draws.
    for n in range(1, 21):
        if (n * (n + 1) // 2) % 2 == 0:
            check(f"Sec. 3.1, even sum N={n} is a draw", table[n][0] == 0)

    # 2. Example positions from the figures (mover's view, solver position mode).
    v, mv = parse_pos(run([solver, "pos", "4", "0", "1", "2", "3", "4"]))
    check("Fig. 2: Catch-Up({1..4}) is a draw", v == 0)
    v, mv = parse_pos(run([solver, "pos", "4", "3", "1", "2", "4"]))
    check("Fig. 1/2: after <3>, P2 wins with <2,4>", mv.get("{2,4}") == 1 and v == 1, str(mv))
    v, mv = parse_pos(run([solver, "pos", "4", "2", "1", "3", "4"]))
    check("Sec. 2.1: after <2>, P2 can force a draw (<1,4>)", v == 0 and mv.get("{1,4}") == 0,
          str(mv))
    v, mv = parse_pos(run([solver, "pos", "7", "4", "1", "2", "4", "7"]))
    vals = sorted(mv.values())
    check("Fig. 3a: {1,2,4,7}:4 winning, <1,2,7> wins, 1 win / 1 draw / 6 losses of 8",
          v == 1 and mv.get("{1,2,7}") == 1 and vals == [-1] * 6 + [0, 1], str(mv))
    v, mv = parse_pos(run([solver, "pos", "7", "4", "1", "3", "4", "6"]))
    check("Fig. 3b: {1,3,4,6}:4, <1,6> wins, <3,6> draws, <3,4> loses",
          v == 1 and mv.get("{1,6}") == 1 and mv.get("{3,6}") == 0 and mv.get("{3,4}") == -1,
          str(mv))
    v, mv = parse_pos(run([solver, "pos", "7", "2", "3", "4", "7"]))
    check("Fig. 4: {3,4,7}:2, P2 forces a win, <7> loses to <3,4>",
          v == -1 and mv.get("{7}") == -1, str(mv))

    # 3. Literal one-number-at-a-time model (independent of the move characterisation).
    for n in range(1, lit_nmax + 1):
        lv, lfirst, (w, t, l), depth, br = literal.analyse(n)
        cv, cfirst = table[n]
        check(f"literal model = solver, N={n} (value and every first move)",
              lv == cv and lfirst == cfirst, f"literal {lv:+d} {lfirst}, solver {cv:+d} {cfirst}")
        tot = w + t + l
        check(f"game-tree size N={n} is N!", tot == math.factorial(n))
        if n in TABLE5_STATS:
            pb, pd, pw, pt, pl = TABLE5_STATS[n]
            got = (br, depth, round(100 * w / tot, 2), round(100 * t / tot, 2),
                   round(100 * l / tot, 2))
            check(f"Table 5 stats N={n} (branch, depth, win/tie/loss %)",
                  got == (pb, pd, pw, pt, pl), f"got {got}")

    # 4. Fig. 5: multiset {2,2,2,3,3}, even sum, P1 wins by choosing <2>.
    v, first = literal.multiset_value((2, 2, 2, 3, 3))
    check("Fig. 5: {2,2,2,3,3} is a P1 win via <2>", v == 1 and first[2] == 1, f"{v} {first}")
    # Sec. 2.4: N=5, MaxScore line <5>, <1,3,4>, <2> ends 7-8 (legality by literal rules).
    s1, s2 = 5, 0
    seq_ok = True
    for x in (1, 3, 4):
        seq_ok &= s2 < s1  # P2 must still be behind before each pick
        s2 += x
    seq_ok &= s2 >= s1  # turn ends
    s1 += 2
    check("Sec. 2.4: N=5 line <5>,<1,3,4>,<2> is legal and ends 7-8", seq_ok and (s1, s2) == (7, 8))

    print(f"\n{len(failures)} failure(s)")
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    main()
