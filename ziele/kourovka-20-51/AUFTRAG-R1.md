# Kourovka 20.51, Runde 1 (Stufe 0, Vortest)

Der Koordinator vergibt diese Aufträge parallel. Höchstens ein halber Tag. Danach anhalten und an
Justus berichten.

## R1-01 Stand-Wache

Prüfe nach Abschnitt 7 des Protokolls. Lies den Wortlaut von 20.51 und 20.52 in der neuesten Fassung
des Kourovka-Hefts vollständig und suche dort und in der Literatur nach Teilergebnissen (MacHale,
Buckley–MacHale, Vera-López, Arbeiten zur Klassenzahl bei ungerader Ordnung). Ergebnis nach
`STATUS.md`.

## R1-02 Lean-Projekt und Aussage

1. Lean-Projekt unter `lean/`, das in GitHub Actions baut; Fragen aus Abschnitt 10 des Protokolls
   klären und mit Fundstelle festhalten.
2. Aussage wörtlich aus formal-conjectures (Commit nennen) nach `Challenge.lean`, mit `sorry`.
3. Lean-Aussage gegen den Wortlaut im Heft lesen. Jede Abweichung ist ein Befund.

Zieldatei: `versuche/r1-02-lean.md`

## R1-03 Positivkontrolle in Lean

Beweise in Lean, dass die nicht abelsche Gruppe der Ordnung 21 genau 5 Konjugationsklassen hat, also
den Fall t = 5 der Aussage. Das zeigt, ob Klassenzählen in Lean mit vertretbarem Aufwand geht.
Berichte den Aufwand ehrlich und schätze, was eine ganze Familie kosten würde.

Zieldatei: `lean/` und `versuche/r1-03-ordnung21.md`

## R1-04 Familien-Landkarte, erstes Programm

Berechne für Gruppen ungerader Ordnung bis zu einer sinnvollen Grenze (GAP mit SmallGroups, falls
installierbar, sonst eigene Aufzählung metazyklischer und Frobenius-Gruppen) die Klassenzahlen.
Liefere je ungeradem t ≤ 199: kleinste gefundene Gruppe, ihre Bauart, und welche Familien t treffen.
Prüfe dabei die Angaben aus `ZIEL.md` nach (Produktregel, Frobenius-Formel, Kongruenz modulo 16).

Zieldatei: `rechnung/r1-04/` und `versuche/r1-04-landkarte.md`

## R1-05 Familien-Landkarte, zweites Programm

Wie R1-04, unabhängig und ohne R1-04 zu lesen. Beide Tabellen müssen übereinstimmen.

Zieldatei: `rechnung/r1-05/` und `versuche/r1-05-landkarte.md`

## Fertig, wenn

- beide Landkarten übereinstimmen, das Lean-Projekt baut und die Positivkontrolle bewiesen ist, oder
- ein Befund vorliegt, der das Ziel beendet.

## Abbruch

Kein Abbruch in dieser Runde. Gelingt R1-03 nicht, ist das der Hauptbefund des Vortests. Der
Koordinator schlägt dann eine zweite Vortest-Runde nur für das Klassenzählen in Lean vor, mit einem
anderen Zugang, bevor über das Ziel entschieden wird.
