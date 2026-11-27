# R1-01 Stand-Wache, 27.11.2026

Ausgeführt im Begleit-Chat, nicht in einem Zielprojekt, ohne Subagenten. Nur gelesen.

## Ergebnis

Das Problem ist nach unserem Stand vom 27.11.2026 weiter offen. Es wird aber sichtbar und mit
neuem Stand daran gearbeitet, von mehreren Leuten, mit eigenen Werkzeugen und mit KI-Agenten.
Damit greift die Haltebedingung aus `AUFTRAG-R1.md`: R1-02 bis R1-05 wurden nicht vergeben.

Die Angabe aus dem Scouting, der letzte sichtbare Beitrag im Thread sei vom 10.02.2026, war
falsch. Im Archiv folgen danach 224 Beiträge, der letzte vom 22.10.2026.

## Was geprüft wurde

| Nr. | Quelle | Befund | Beleg |
|---|---|---|---|
| 1 | formal-conjectures | Datei seit `9097e2f` unverändert, Markierung `research open, question` (Zeile 66), kein `formal_proof` | `git diff 9097e2f ea8e3e1` leer; `ea8e3e1` vom 26.11.2026 |
| 2 | Palomar | kein Treffer in den ersten 34 Einträgen von `recent.json` (alle vom 26.11.2026) | Rest der Datei und Suche nicht lesbar |
| 3 | arXiv, Websuche | kein Treffer, der die Frage entscheidet | zwei Suchen, 27.11.2026 |
| 4 | fremde Repos | acht Repos und Zweige, siehe unten | per `git` geklont |
| 5 | Zulip-Archiv | 855 Beiträge, 05.12.2024 bis 22.10.2026 | `leanprover-community/archive`, Commit `4a4a212` vom 25.10.2026, Datei `zulip_json/458659-Equational/FINITE.3A.20677.20-.3E.20255.json` |
| 6 | `teorth/equational_theories` | letzter Commit `02b063b` vom 22.11.2026; zu 677 seit Februar drei Commits (`d69afe6` 05.04., `3f3999d` 01.06., `0e3b4fd` 12.06.); Issue #1517 vom 10.10.2026 offen | `git log --since=2026-02-01` |

## Aktivität im Thread

| Zeitraum | Beiträge |
|---|---|
| bis 10.02.2026 | 631 |
| 11.02. bis 31.07.2026 | 193, davon 139 im Mai |
| August bis 22.10.2026 | 31 |

Daneben gibt es seit 05.05.2026 ein zweites Thema „Dedicated finite+677 graph“ mit 63 Beiträgen.

Im Wortlaut gelesen habe ich die Beiträge 818 bis 854 (11.07. bis 22.10.2026), dazu vier vom
April und Mai (633, 634, 637, 644). Den Rest habe ich nur gezählt und nach Links durchsucht.

## Neuer Stand seit dem Scouting-Bild (laut Thread, nicht nachgerechnet)

| Datum | Wer | Was |
|---|---|---|
| 05.04.2026 | McKenna | Lean-Lemmata zu Kapitel 13, „mostly with Claude“; Tao begrüßt Pull Requests mit Lean-Beweisen zu Blueprint-Lemmata |
| 24.04.2026 | Renshaw | Datenbank endlicher 677-Magmen, https://eq677.icarm.cloud/, nimmt Einreichungen an |
| 30.09.2026 | Hyun | Lean-Beweis: kein 677-Magma der Ordnung 6; Lean-Beweis: für jedes n ≥ 164475 gibt es eines |
| 30.09.2026 | Buzzard, Hyun | Für Untermagmen S, T von M gilt 3\|S\| + 2\|T\| ≤ 2\|M\|. Buzzard: von Codex, von ihm ungeprüft |
| 01.10.2026 | Schneider | vollständige Suche bis Ordnung 11 ohne Gegenbeispiel, kein formaler Beweis |
| 02.10.2026 | Chuks-Onah | 737 Modelle der Datenbank ausgewertet, kein Untermagma verletzt 255 |
| 11. und 14.10.2026 | Padilla | zwei bedingte Sätze (677 plus Zusatzbedingung ergibt 255) |
| 14.10.2026 | McKenna | alle Tafeln seiner Kopie, die Padillas erste Bedingung erfüllen, sind Quasigruppen; dort gilt 255 ohnehin |
| 21.10.2026 | McKenna | sieben formalisierte Schranken; ein kleinstes Gegenbeispiel mit echter Kongruenz hat mindestens 24 Elemente |

Alle bekannten Beispiele erfüllen 255 (Startseite der Datenbank, gelesen 27.11.2026).

## Fremde Repos

| Repo | Letzter Commit | Inhalt | Mitarbeit |
|---|---|---|---|
| `memoryleak47/eq677` | 17.07.2026, 646 Commits | Suchprogramm eigens für 677 (`c_dpll`), Tafeln, Apache-Lizenz | Commits von Renshaw und Reinke |
| `icarm/Equation-677-Database` | 28.10.2026, 133 Commits | Webseite und Datenbank | Einreichung über GitHub-Anmeldung auf der Seite |
| `Timeroot/equational_theories` (vermutlich Meiburgs Fork, der Zweigname passt) | Zweige `dedicated-677`, `definability-negative` | Spektrum der Ordnungen, „agents“; Inhalt nicht gelesen | Meiburg bittet im Thread um Pull Requests |
| `hawkaiglai/equational_theories` | Zweige `e677-*` | Suchskripte, Lean-Prüfung | nicht gelesen |
| `mysticflounder/d6-exact-base-e677` | 01.05.2026 | Teilfall mit Lean und Notiz | nicht gelesen |
| `qawbecrdtey/magma_dimacs_cnf`, `MagmaExplorer` | 19.05. und 17.10.2026 | SAT-Kodierung, Anzeige der Datenbank | nicht gelesen |
| Prove2Me, Mission „E677 → E255 (finite case)“ | kein Datum sichtbar | 58 Sätze, 4 aktive Nutzer, Beweis- und Widerlegungsziel | offen für Menschen mit eigenen Agenten |

KI-Werkzeuge, die dort ausdrücklich genannt werden: Codex (Buzzard), ChatGPT 6 Pro und Claude
(McKenna), „agents“ (Meiburg), KI-erzeugter Lean-Code (Padilla).

## Nicht erreicht

- Zulip nach dem 25.10.2026 (Stand des Archivs).
- Issues und Pull Requests auf GitHub außer #1517; die Kommentare dort waren nicht sichtbar.
- Palomar über die ersten 34 Einträge hinaus.
- Inhalt der Zweige in den Forks von Meiburg und Chuks-Onah.
- 814 der 855 Beiträge im Wortlaut.

## Fehler im Scouting

Scout und Gegenleser haben die Archivseite über Zusammenfassungen gelesen und beim Beitrag vom
10.02.2026 aufgehört. Das ist nach `catch-up` der zweite Fall, in dem das Scouting laufende
fremde Arbeit übersehen hat. Die Stand-Wache sollte das Zulip-Archiv künftig per `git` aus
`leanprover-community/archive` lesen, nicht über die Webseite.
