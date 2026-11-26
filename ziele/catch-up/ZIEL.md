# Ziel: Catch-Up

Angaben aus dem Scouting vom 26.11.2026. Was nicht als nachgerechnet markiert ist, stammt aus den
Berichten der Scouts und ist nicht geprüft.

## Steckbrief

- **Eintrag:** `FormalConjectures/Paper/CatchUpConjecture.lean`, Deklaration
  `CatchUp.value_of_even_mul_succ_self_div_two` (Zeile 182, Markierung `research open` Zeile 181),
  Stand Commit `9097e2f` (24.11.2026)
- **Quelle:** A. Isaksen, M. Ismail, S. J. Brams, A. Nealen, „Catch-Up: A Game in Which the Lead
  Alternates“, Game & Puzzle Design 1(2), 38–49 (2015),
  https://mpra.ub.uni-muenchen.de/108784/1/MPRA_paper_108784.pdf
- **Aussage für Laien:** Zwei Spieler nehmen abwechselnd Zahlen aus {1, …, N}. Wer zurückliegt,
  nimmt so lange weitere Zahlen, bis er gleichzieht oder führt. Am Ende gewinnt die höhere Summe.
  Vermutung: Ist 1 + … + N gerade (N durch 4 teilbar oder mit Rest 3), endet das Spiel bei
  beidseitig bestem Spiel immer unentschieden.
- **Fachgebiet:** kombinatorische Spieltheorie

## Bekannt

| Aussage | Belegart | Fundstelle |
|---|---|---|
| Remis für alle N ≤ 20 mit gerader Summe | voll (Quelle) | MPRA-PDF |
| Remis für N = 3, 4, 7, 8, 11, 12, 15, 16 | voll, eigenes Programm im Scouting | `scouting/2026-11-26/RANGLISTE.md` |
| Remis für N = 23, 24, 27 | voll, ein Programm eines Gegenlesers, nicht wiederholt | ebenda |
| Bei ungerader Summe kein Muster, wer gewinnt (N = 1, 2, 5, 6, 13 Anziehender; 9, 10, 14 Nachziehender) | voll, eigenes Programm | ebenda |
| Für beliebige Zahlenmengen mit gerader Summe ist die Aussage falsch (Beispiel {2,2,2,3,3}) | laut Gegenleser aus der Quelle, ungeprüft | Quelle |
| Arbeit zu Endspielen mit 3 oder 4 Restzahlen | ungeprüft | Honors Thesis Feng 2024 (CUNY) |

## Zur Lean-Aussage

- `valueAux` und `value` sind `noncomputable`. Die Datei enthält keine Testsätze für kleine N; die
  Definition ist im Repo also nicht gegen die Tabelle der Quelle geprüft.
- Scout und Gegenleser haben die Regeln unabhängig gegen die Quelle gelesen und keine Abweichung
  gefunden (erster Zug genau eine Zahl, Zugende bei Gleichstand oder Führung, wer nicht mehr aufholen
  kann, verliert).

## Angriffsideen (aus dem Scouting, ungeprüft)

- **Beweis:** stärkere Aussage ohne Parität anpeilen, etwa „jeder Spieler kann erzwingen, mit
  höchstens einem Punkt Rückstand zu enden“. Aus den besten Zügen kleiner N eine Strategie ablesen
  und per Induktion über die Restmenge beweisen. Der Beweis muss die Gestalt {1, …, N} benutzen.
- **Gegenbeispiel:** exakte Rückwärtsanalyse für größere N. Praktisch wenig aussichtsreich, alles
  bis 27 ist Remis. Für Lean bräuchte man eine berechenbare Fassung samt Äquivalenzbeweis.

## Risiken

1. Palomars Relevanzschwelle ist hier knapp (Quelle ist eine Spieldesign-Zeitschrift).
2. Seit 2015 keine Strukturtheorie; eine einfache geschlossene Strategie gibt es womöglich nicht.
3. Die Lean-Definition ist nicht ausführbar.

## Quellen für die Stand-Wache

Git-Verlauf der Datei in formal-conjectures; Palomar; arXiv und Websuche zu „Catch-Up game Brams
Isaksen Ismail Nealen conjecture draw“.
