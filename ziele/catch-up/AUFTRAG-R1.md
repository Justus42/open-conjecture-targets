# Catch-Up, Runde 1 (Stufe 0, Vortest)

Der Koordinator vergibt diese Aufträge parallel. Höchstens ein halber Tag. Danach anhalten und an
Justus berichten.

## R1-01 Stand-Wache

Prüfe nach Abschnitt 7 des Protokolls, ob die Vermutung inzwischen gelöst ist oder jemand sichtbar
daran arbeitet. Ergebnis mit Datum und nicht erreichten Quellen nach `STATUS.md`.

## R1-02 Lean-Projekt und Aussage

1. Lege unter `lean/` ein Lean-Projekt an, das in GitHub Actions baut. Kläre dabei die Fragen aus
   Abschnitt 10 des Protokolls (welche Lean-Version Palomar annimmt, Modulsystem) und halte die
   Antworten mit Fundstelle fest.
2. Übernimm Definitionen und Aussage wörtlich aus formal-conjectures (Commit nennen) in eine Datei
   `Challenge.lean`, mit `sorry` als Beweis.
3. Lies die Definitionen gegen die Regeln im Paper (Volltext, nicht Zusammenfassung). Jede
   Abweichung ist ein Befund.

Zieldatei: `versuche/r1-02-lean.md`

## R1-03 Wertetabelle, erstes Programm

Schreibe ein Programm, das den Spielwert für alle N ≤ 20 berechnet (beide Paritäten der Summe), und
vergleiche mit der Tabelle des Papers. Gib zu jedem N mit gerader Summe mindestens einen besten
ersten Zug und die Zahl der besten ersten Züge aus.

Zieldatei: `rechnung/r1-03/` und `versuche/r1-03-tabelle.md`

## R1-04 Wertetabelle, zweites Programm

Wie R1-03, in einer anderen Sprache und ohne R1-03 zu lesen. Das ist die Positivkontrolle: Beide
Tabellen müssen untereinander und mit dem Paper übereinstimmen.

Zieldatei: `rechnung/r1-04/` und `versuche/r1-04-tabelle.md`

## R1-05 Berechenbare Fassung in Lean

Schreibe in Lean eine ausführbare Fassung des Spielwerts und formuliere (ohne Beweis) den Satz,
dass sie mit `value` aus der Aussage übereinstimmt. Prüfe mit `decide` oder `#eval` die Fälle
N = 3 und N = 4 gegen das Paper. Schätze ein, wie aufwendig der Äquivalenzbeweis wird.

Zieldatei: `lean/` und `versuche/r1-05-berechenbar.md`

## Fertig, wenn

- beide Tabellen übereinstimmen, das Lean-Projekt baut und die Aussage wörtlich übernommen ist, oder
- ein Befund vorliegt, der das Ziel beendet (Aussage weicht von der Quelle ab, Vermutung gelöst).

## Abbruch

Stimmen die Tabellen nicht mit dem Paper überein, wird nicht weitergerechnet, sondern die Abweichung
aufgeklärt und berichtet.
