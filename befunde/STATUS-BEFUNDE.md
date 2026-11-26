# Befunde: Einträge mit möglicherweise veraltetem Status oder kleinen Abweichungen

Stand 26.11.2026, Repo-Commit `9097e2f`. Alle Angaben stammen aus den Berichten der Scouts und sind
**ungeprüft**. Nichts davon ist gemeldet. Vor jeder Meldung die genannte Literatur im Volltext lesen.

## Als offen markiert, laut Literatur vermutlich nicht mehr offen

| Eintrag | Angabe des Scouts | Vorbehalt |
|---|---|---|
| `Arxiv/2507.17780/3.lean`, `tx_graffiti_conjecture_3` | widerlegt durch einen kubischen Graphen mit 50 Ecken (arXiv:2609.10783) | Primärquelle des Gegenbeispiels nicht identifiziert |
| `Arxiv/2605.02731/DeanCycles.lean`, Fall k = 5 | Beweis beansprucht (Zenodo 22182448, August 2026) | Autorenangaben widersprüchlich, Beweis ungeprüft |
| `Wikipedia/EulerBrick.lean`, `cuboidTwo` | vollständiger Beweis beansprucht (arXiv:2610.25319) | Preprint, nicht begutachtet |
| `GreensOpenProblems/35.lean`, `green_35.lower` | folgt bei p = 2 aus bekannten Schranken (White, arXiv:2210.16437) | Normierung vom Scout verglichen, nicht nachgerechnet |
| `GreensOpenProblems/84.lean`, `green_84.variants.ultraflat_mod` | vermutlich Ja nach Katz 1989 | nur Lesart des Scouts, nicht durchgerechnet |

## Kleinere Abweichungen und Auffälligkeiten

| Eintrag | Beobachtung |
|---|---|
| `Wikipedia/EulerBrick.lean`, `n_dim_euler_brick_existence` | Docstring fragt „für irgendein n > 3“, Lean behauptet es für alle n > 3 |
| `Wikipedia/Agrawal.lean`, Popovych-Variante | Jahr im Docstring passt nicht zur zitierten Quelle; Zusatzvoraussetzung nicht gegen die Quelle geprüft |
| `Arxiv/2501.03234/ArithmeticSumS.lean` | Nummerierung folgt arXiv v1; in v2 sind die Vermutungen anders nummeriert und teils anders gefasst |
| `Other/VCDimConvex.lean` | Name sagt „two“, Aussage sagt „höchstens 3“; keine Quelle zitiert |
| `Paper/WeakTiling.lean`, `problem_4_2` | Einschränkung auf mindestens drei Intervalle im Original nicht wörtlich gefunden |
| `OpenQuantumProblems/35.lean` | mehrere gelöste Sätze tragen weiter das Suffix `_open` |

## Einordnung

„Als gelöst markieren“ und „Formalisierung korrigieren“ sind im Repo ausdrücklich erwünschte
Beiträge. Sie sind Prüfarbeit, kein neues Ergebnis. Ob und was davon gemeldet wird, entscheidet
Justus; die Texte schreibt er selbst.
