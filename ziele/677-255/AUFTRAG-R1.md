# 677 → 255, Runde 1 (Stufe 0, nur Lesen)

Der Koordinator vergibt diese Aufträge parallel. In dieser Runde gibt es keinen Beweis- und keinen
Suchversuch. Danach anhalten und an Justus berichten.

## R1-01 Stand-Wache

Prüfe nach Abschnitt 7 des Protokolls, zusätzlich: Klone `teorth/equational_theories` (nur lesen)
und suche dort nach allem zu 677 und 255 seit Februar 2026. Ergebnis nach `STATUS.md`.

## R1-02 Thread, erste Hälfte

Lies die erste Hälfte des Zulip-Threads „FINITE: 677 -> 255“ vollständig im Wortlaut, in Abschnitten,
nicht über Zusammenfassungen. Halte je Ansatz fest: wer, wann, was versucht wurde, mit welchem
Werkzeug, mit welchem Ergebnis, und warum es nicht weiterging. Belegart je Negativbefund angeben
(Protokoll 5.4).

Zieldatei: `versuche/r1-02-thread-teil1.md`

## R1-03 Thread, zweite Hälfte

Wie R1-02 für die zweite Hälfte. Überlappe mit R1-02 um einen Abschnitt, damit nichts fehlt.

Zieldatei: `versuche/r1-03-thread-teil2.md`

## R1-04 Blueprint, Paper, Repo

Lies Blueprint-Kapitel 13 vollständig, im Abschlussbericht (arXiv:2512.07087) alle Stellen zu 677
und zu endlichen Implikationen, und im Repo des Projekts die zugehörigen Lean- und Datendateien.
Liefere: alle bewiesenen Lemmata mit Fundstelle, alle bekannten endlichen 677-Magmen (Größe,
Bauart, wo die Tafel liegt), und die Liste der Konstruktionen, die nachweislich kein Gegenbeispiel
liefern können.

Zieldatei: `versuche/r1-04-blueprint.md`

## R1-05 Lean-Projekt und Positivkontrolle

1. Lean-Projekt unter `lean/`, das in GitHub Actions baut; Fragen aus Abschnitt 10 des Protokolls
   klären. Aussage wörtlich aus formal-conjectures nach `Challenge.lean`, mit `sorry`.
2. Positivkontrolle für spätere Suchen: Nimm ein bekanntes endliches 677-Magma aus dem Projekt
   (möglichst ein nicht rechtskürzbares) und bestätige mit zwei unabhängig geschriebenen Programmen,
   dass es 677 und 255 erfüllt. Kleinster Fall zusätzlich in Lean per `decide`.

Zieldatei: `lean/`, `rechnung/r1-05/` und `versuche/r1-05-kontrolle.md`

## Danach, durch den Koordinator

Führe R1-02 bis R1-04 zu einer Datei `versuche/landkarte.md` zusammen: links die bekannten
Sackgassen mit Belegart, rechts, was nachweislich niemand versucht hat. Zu jedem Punkt rechts die
Frage: Warum sollte das dieser Gruppe entgangen sein?

## Fertig, wenn

die Landkarte vorliegt, das Lean-Projekt baut und die Positivkontrolle besteht.

## Abbruch

Kein Abbruch in dieser Runde. Bleibt die rechte Spalte der Landkarte leer, schlägt der Koordinator
als Nächstes eine Ideenrunde vor (Protokoll, Abschnitt 6): neue Ansätze aus anderen Gebieten und
von Blind-Suchern. Erst wenn auch die nichts bringt, empfiehlt er, das Ziel ruhen zu lassen.
