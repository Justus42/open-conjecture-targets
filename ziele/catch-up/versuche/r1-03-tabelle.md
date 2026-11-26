# catch-up R1-03: Wertetabelle, Programm 1

Rolle: Sucher. Stand: 26.11.2026. Runde vom Koordinator angehalten (Abbruchregel 3); der Auftrag war zu dem
Zeitpunkt inhaltlich fertig, nur Bericht und Commit fehlten. Status aller Zahlen: **behauptet** (ein Programm; 5.2 verlangt ein zweites
Programm und einen Prüfer).

## Ergebnis

Das C++-Programm (`rechnung/r1-03/catchup.cpp`, exakte Rückwärtsanalyse mit Speicher über
(Restmenge, Rückstand)) gibt für N = 3 … 20 genau die Werte aus Tabelle 2 des Papers aus. Alle N mit
gerader Summe bis 20 sind Remis.

| N | Summe | Wert (für P1) | beste erste Züge von P1 | Anzahl |
|---|---|---|---|---|
| 1 | 1 ungerade | +1 P1 gewinnt | 1 | 1 |
| 2 | 3 ungerade | +1 P1 gewinnt | 2 | 1 |
| 3 | 6 gerade | 0 Remis | 1, 3 | 2 |
| 4 | 10 gerade | 0 Remis | 1, 2 | 2 |
| 5 | 15 ungerade | +1 P1 gewinnt | 3 | 1 |
| 6 | 21 ungerade | +1 P1 gewinnt | 2 | 1 |
| 7 | 28 gerade | 0 Remis | 1, 2, 3, 4 | 4 |
| 8 | 36 gerade | 0 Remis | 1 … 8 (alle) | 8 |
| 9 | 45 ungerade | −1 P2 gewinnt | (jeder Zug verliert) | 9 |
| 10 | 55 ungerade | −1 P2 gewinnt | (jeder Zug verliert) | 10 |
| 11 | 66 gerade | 0 Remis | 1 … 9, 11 (nicht 10) | 10 |
| 12 | 78 gerade | 0 Remis | 1 … 12 (alle) | 12 |
| 13 | 91 ungerade | +1 P1 gewinnt | 1 | 1 |
| 14 | 105 ungerade | −1 P2 gewinnt | (jeder Zug verliert) | 14 |
| 15 | 120 gerade | 0 Remis | 1 … 15 (alle) | 15 |
| 16 | 136 gerade | 0 Remis | 1 … 16 (alle) | 16 |
| 17 | 153 ungerade | +1 P1 gewinnt | 3 | 1 |
| 18 | 171 ungerade | −1 P2 gewinnt | (jeder Zug verliert) | 18 |
| 19 | 190 gerade | 0 Remis | 1 … 19 (alle) | 19 |
| 20 | 210 gerade | 0 Remis | 1 … 20 (alle) | 20 |

„Beste erste Züge“ = erste Züge, nach denen der Spielwert erhalten bleibt. Werte jedes einzelnen
ersten Zugs stehen in `rechnung/r1-03/table.tsv` (Spalte `first_move_values`).

## Regeln (aus dem Paper, Regelkasten S. 38)

Zug = Menge T. Legal, wenn T alles Übrige ist und der Ziehende selbst damit nicht aufholen kann
(Regel 3), oder wenn sum(T) ≥ Rückstand D und |T| = 1 oder sum(T) − max(T) < D (größte Zahl zuletzt
genommen). Bei Gleichstand (auch erster Zug) also genau eine Zahl.

## Abgleich mit dem Paper

- Tabelle 2 (N = 3 … 20) und Wertspalte von Tabelle 5 (N = 3 … 18): alle gleich.
- Beispielstellungen (Positionsmodus `catchup pos …`): Fig. 2/Abschn. 2.1 ({1,2,3,4} Remis; nach ⟨3⟩
  gewinnt P2 mit ⟨2,4⟩; nach ⟨2⟩ erzwingt P2 mit ⟨1,4⟩ Remis), Fig. 3a (⟨1,2,7⟩ einziger Gewinnzug,
  1 Remis-, 6 Verlustzüge von 8), Fig. 3b (⟨1,6⟩ gewinnt, ⟨3,6⟩ Remis, ⟨3,4⟩ verliert), Fig. 4 (P2
  gewinnt) — alle von Hand im Lauf gesehen.
- Zweites Modell im selben Ordner (`literal.py`, Zahl für Zahl nach dem Wortlaut, Python): stimmt
  für N ≤ 10 in Wert und in jedem ersten Zug mit dem C++-Programm überein (Handlauf) und trifft
  Tabelle 5 (Sieg/Remis/Niederlage-Anteile aller Partien, Mindesttiefe, maximale Verzweigung) für
  N = 3 … 10. Das ist kein unabhängiges Programm im Sinn von 5.2 (gleiche Sitzung).
- Fig. 5 (Multimenge {2,2,2,3,3}): P1 gewinnt mit ⟨2⟩ (wörtliches Modell). Abschn. 2.4 (N = 5,
  Zugfolge ⟨5⟩, ⟨1,3,4⟩, ⟨2⟩ legal, Endstand 7–8).
- `compare.py` fasst alles zusammen: **80 PASS, 0 FAIL** (`rechnung/r1-03/compare.txt`).
- **Negativkontrolle:** dieselbe Prüfung mit der absichtlich falschen Regel (`-DMIN_LAST`) ergibt
  17 FAIL, u. a. N = 9, 10, 18 (`rechnung/r1-03/negative_control.txt`). Das Prüfwerkzeug schlägt an.

## Laufzeit, Wiederholung

`bash ziele/catch-up/rechnung/r1-03/run.sh` (g++ 13.3, Python 3.13). Gesamtlauf 57 s auf einem Kern
(davon C++-Tabelle N = 1 … 20 rund 22 s, N = 20 allein 16 s unter Last; Rest wörtliches Modell und
Negativkontrolle). Speicher rund 22 MB.

## Abweichungen und eigene Fehler

1. Erste Fassung prüfte sum(T) − **min**(T) < D (kleinste Zahl zuletzt). Das schließt legale Züge
   wie ⟨2,4⟩ gegen Rückstand 3 aus und ergab für N = 9, 10, 13 falsche Werte (+1 statt −1 bei 9, 10).
   Gefunden durch den Abgleich mit Tabelle 2 und `literal.py`. Diese Fassung bleibt als
   `-DMIN_LAST` im Code und dient als Negativkontrolle.
2. Beim Umbau fehlte kurz der Fall „Spiel endet nach Regel 3 mit Rückstand des Ziehenden“
   (Endstand-Vorzeichen); sofort an den Figuren-Stellungen aufgefallen und behoben.

## Offen

- Zweites unabhängiges Programm (R1-04) und Prüfer nach 5.2.
