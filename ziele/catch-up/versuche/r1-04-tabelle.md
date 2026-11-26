# catch-up R1-04: Wertetabelle Catch-Up({1, …, N}), Programm 2 (C++)

Status: behauptet (ein Programm; geprüft erst nach Abgleich mit R1-03 und Wiederholung durch einen
Prüfer, Protokoll 5.2). Der Auftrag ist fertig. Die Runde wurde vom Koordinator angehalten, als die
Arbeit schon beendet war, daher ist nichts offen geblieben.

## Ergebnis

Für alle N = 1 … 20 stimmen die Werte mit Tabelle 2 des Papers überein (N = 3 … 20). Jedes N mit
gerader Summe (3, 4, 7, 8, 11, 12, 15, 16, 19, 20) endet bei bestem Spiel remis. Außerdem stimmen
alle Spalten von Tabelle 5 (N = 3 … 18) genau. Die Spalte zur Zustandsraumgröße stimmte aber erst,
nachdem ich die Zähldefinition nachträglich angepasst hatte (siehe Abweichungen).

## Regeln (aus dem Paper, Regelkasten S. 38)

1. Beide Spieler beginnen mit 0 Punkten. P1 nimmt zuerst eine Zahl.
2. Danach nimmt der Spieler am Zug Zahlen einzeln, bis seine Summe die des Gegners erreicht oder
   übertrifft. Dann ist der andere dran.
3. Geht das nicht mehr, bekommt der Spieler am Zug alle restlichen Zahlen. Die höhere Summe gewinnt,
   bei Gleichstand ist es remis.

Modell: Zustand = (Restmenge R, Rückstand k ≥ 0 des Spielers am Zug). Er nimmt eine Zahl x. Mit
e = x − k gilt: Ist e ≥ 0, endet der Zug, und der Gegner ist mit Rückstand e am Zug. Sonst nimmt
derselbe Spieler weiter, mit Rückstand k − x. Regel 3 ergibt sich daraus von selbst. Die Werte
werden rückwärts über alle Teilmengen von {1..20} und alle k = 0..20 ausgerechnet.

## Tabelle (Wert aus Sicht von P1; bester erster Zug = jeder erste Zug, der den Spielwert hält)

| N | Summe | Wert | beste erste Züge | Anzahl | Paper Tab. 2 |
|---|---|---|---|---|---|
| 1 | 1 ungerade | P1 gewinnt | 1 | 1 | – |
| 2 | 3 ungerade | P1 gewinnt | 2 | 1 | – |
| 3 | 6 gerade | remis | 1, 3 | 2 | 0 ✓ |
| 4 | 10 gerade | remis | 1, 2 | 2 | 0 ✓ |
| 5 | 15 ungerade | P1 gewinnt | 3 | 1 | 1 ✓ |
| 6 | 21 ungerade | P1 gewinnt | 2 | 1 | 1 ✓ |
| 7 | 28 gerade | remis | 1, 2, 3, 4 | 4 | 0 ✓ |
| 8 | 36 gerade | remis | 1–8 (alle) | 8 | 0 ✓ |
| 9 | 45 ungerade | P2 gewinnt | alle (P1 verliert sowieso) | 9 | −1 ✓ |
| 10 | 55 ungerade | P2 gewinnt | alle | 10 | −1 ✓ |
| 11 | 66 gerade | remis | 1–9, 11 (nicht 10) | 10 | 0 ✓ |
| 12 | 78 gerade | remis | 1–12 (alle) | 12 | 0 ✓ |
| 13 | 91 ungerade | P1 gewinnt | 1 | 1 | 1 ✓ |
| 14 | 105 ungerade | P2 gewinnt | alle | 14 | −1 ✓ |
| 15 | 120 gerade | remis | 1–15 (alle) | 15 | 0 ✓ |
| 16 | 136 gerade | remis | 1–16 (alle) | 16 | 0 ✓ |
| 17 | 153 ungerade | P1 gewinnt | 3 | 1 | 1 ✓ |
| 18 | 171 ungerade | P2 gewinnt | alle | 18 | −1 ✓ |
| 19 | 190 gerade | remis | 1–19 (alle) | 19 | 0 ✓ |
| 20 | 210 gerade | remis | 1–20 (alle) | 20 | 0 ✓ |

Alle Zahlen stehen in `rechnung/r1-04/ausgabe.txt`.

## Kontrollen

- **Positivkontrolle A:** Die Beispielpartien aus Abb. 1, Abschnitt 2.1 und Abschnitt 2.4 laufen mit
  genau den Zügen und Endständen des Papers ab (4–6, 5–5, 7–8).
- **Positivkontrolle B:** Die Stellungen aus Abb. 2 bis 5 stimmen. {1,2,3,4} ist remis. Abb. 3a:
  8 Züge, davon gewinnt nur {1,2,7}, einer ist remis, sechs verlieren. Abb. 3b: ⟨1,6⟩ gewinnt,
  ⟨3,6⟩ ist remis, ⟨3,4⟩ verliert. Abb. 4: verloren, und nach ⟨3⟩ gewinnt nur ⟨7⟩. Abb. 5
  ({2,2,2,3,3}, Multimenge): P1 gewinnt mit ⟨2⟩. {2,4,6,8,10} ist nicht remis.
- **Kontrolle C:** Ein zweiter, generischer Löser auf Multimengen im selben Programm stimmt mit dem
  Bitmasken-Löser überein: alle Teilmengen von {1..10} mal k = 0..10, dazu Spielanfang und alle
  ersten Züge für N ≤ 13, zusammen 11 368 Zustände, 0 Abweichungen.
- **Abgleich mit Tabelle 5 (N = 3 … 18):** Spielwert, Zustandsraumgröße, größte Verzweigung
  (gezählt als geordnete Zugfolgen), kleinste Tiefe sowie Sieg-, Remis- und Verlustanteile über alle
  N! Reihenfolgen stimmen alle genau. Ebenso Abschnitt 4.3: höchstens 2N − 2 Punkte in P2s erstem
  Zug.
- **Negativkontrolle:** Mit `--strict` gilt eine absichtlich falsche Regel: Der Zug endet erst, wenn
  der Spieler echt führt. Damit schlagen 9 Prüfungen an, darunter Tabelle 2 (z. B. N = 9, 10, 14, 18
  werden zu Siegen für P1) und Abb. 3a, 3b und 5 (`ausgabe-strict.txt`). Für sich allein erkennt die
  Prüfung „alle geraden N remis“ die falsche Regel nicht, denn auch unter ihr sind die geraden N
  remis.

## Laufzeit und Wiederholung

Ein Kern, etwa 1,4 s für den ganzen Lauf (Werte bis N = 20 etwa 0,6 s), Speicher ungefähr 170 MB.
Übersetzt mit g++ 13.3.0.

```
cd ziele/catch-up/rechnung/r1-04
mkdir -p build && g++ -O2 -std=c++17 -o build/catchup catchup.cpp
./build/catchup > ausgabe.txt            # muss mit "SUMMARY: PASS" enden, Exit 0
./build/catchup --strict                 # Negativkontrolle, muss FAIL melden, Exit 1
```

sha256 von `ausgabe.txt`: `51d787cba052f45be33f8fdd0a2b746138689c00fbc6c2e37d2770de7ccb6be1`

## Abweichungen und eigene Fehler

- **Zustandsraumgröße nachträglich angepasst.** Mein erster Zählansatz lag für N ≥ 4 um 2 bis 18
  unter den Werten des Papers. Danach habe ich die Definition gesucht, die die Werte des Papers genau
  trifft. Sie zählt Zuganfangszustände (R, k, wer am Zug ist) und Endzustände, unterschieden nach
  Enddifferenz und danach, wer zuletzt gezogen hat. Mit ihr stimmen alle 16 Werte. Die Definition
  ist an die Daten angepasst, also kein unabhängiger Beleg. Sie berührt die Spielwerte nicht.
- Kontrolle C ist kein zweites Programm im Sinn von 5.2, weil sie in derselben Datei und derselben
  Sitzung entstand.
- Im Text zu Abb. 3a steht „P1's optimal move“. Nach der beschriebenen Vorgeschichte (P1 ⟨3⟩, P2 ⟨5⟩,
  P1 ⟨6⟩) ist dort aber P2 am Zug. Ich halte das für einen Schreibfehler im Paper und habe die
  Stellung so geprüft, dass P2 zieht.
- Nichts aus R1-03 gelesen und keine Lean-Datei benutzt.

## Offene Punkte

- Abgleich mit R1-03 und Wiederholung durch einen Prüfer (5.2).
- N > 20 nicht gerechnet (nicht beauftragt).
