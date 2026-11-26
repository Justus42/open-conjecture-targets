# open-conjecture-targets

Attempts to settle a small number of open entries of
[google-deepmind/formal-conjectures](https://github.com/google-deepmind/formal-conjectures)
with machine-checked Lean 4 proofs or exactly verified counterexamples.

**Status:** set up on 26 November 2026. No result yet. See [STATUS.md](STATUS.md).

## Targets

| Folder | Entry in formal-conjectures | Question | State |
|---|---|---|---|
| [`ziele/catch-up`](ziele/catch-up/ZIEL.md) | `Paper/CatchUpConjecture.lean` | Is the game Catch-Up always a draw when 1 + … + N is even? | not started |
| [`ziele/kourovka-20-51`](ziele/kourovka-20-51/ZIEL.md) | `Kourovka/20_51.lean` | Is there, for every odd t > 3, a non-abelian group of odd order with exactly t conjugacy classes? | not started |
| [`ziele/677-255`](ziele/677-255/ZIEL.md) | `Other/EquationalTheories_677_255.lean` | Does equation 677 imply equation 255 in every finite magma? | not started |

The questions and their Lean statements are not ours. Sources and credit are listed in each
target's `ZIEL.md`.

## How this project works

This is an experiment in AI-driven mathematical research, run by a non-mathematician.

- The mathematical work is done by AI models: one coordinating Claude session per target assigns
  single tasks to further Claude sessions (proof search, counterexample search, review).
- No claim counts because a model says so. A proof counts only as a Lean 4 proof of the statement
  taken verbatim from formal-conjectures, built without `sorry` and with the three standard axioms
  only. A counterexample or a computed value counts only if two independently written programs
  confirm it.
- Failed approaches are kept, with the reason why they failed.
- The words "proved" and "solved" are used only for items with status **geprüft** (verified).
- Nothing is reported to other projects without a decision of the repository owner.

Working rules (German): [PROTOKOLL.md](PROTOKOLL.md) and [CLAUDE.md](CLAUDE.md).

## Status words

| German (used in this repo) | Meaning |
|---|---|
| vermutet | idea without evidence |
| behauptet | claimed, not yet verified |
| geprüft | verified by the rules above |
| widerlegt | refuted |
| aufgegeben | stopped, with the reason recorded |

## Side findings

Observations made while choosing the targets (a probably mis-stated entry, an entry that looks
easy, entries whose status may be outdated) are collected in [`befunde/`](befunde/). They are
unreported and partly unverified.

## License

See [LICENSE](LICENSE). Third-party material keeps its own license.
