# Befund: Rudins Eindeutigkeitsaussage ist vermutlich falsch formalisiert

Stand 26.11.2026. Nicht gemeldet. Gefunden von einem Scout, Zahlen von der Scouting-Leitung
nachgerechnet.

## Stelle

`FormalConjectures/Wikipedia/RudinsConjecture.lean` in `google-deepmind/formal-conjectures`
(Commit `9097e2f`), Satz `rudins_conjecture_unique` (Zeilen 118 bis 120):

```lean
theorem rudins_conjecture_unique (N : ℕ) (hN : 6 ≤ N) (q a : ℕ)
    (hqa : IsNontrivial q a) (hmax : Q N q a = Qmax N) : q = 24 := by
  sorry
```

`Q N q a` zählt die Quadratzahlen unter den ersten N Gliedern von q·n + a (n = 0, …, N−1).
`IsNontrivial q a` verlangt q, a ≥ 1, ggT(q, a) = 1 und (q, a) ≠ (1, 1).

## Fakten für N = 6

| Folge | erste sechs Glieder | Quadratzahlen | Anzahl |
|---|---|---|---|
| 24n + 1 | 1, 25, 49, 73, 97, 121 | 1², 5², 7², 11² | 4 |
| 120n + 49 | 49, 169, 289, 409, 529, 649 | 7², 13², 17², 23² | 4 |
| 168n + 121 | 121, 289, 457, 625, 793, 961 | 11², 17², 25², 31² | 4 |

- ggT(120, 49) = 1 und ggT(168, 121) = 1, beide Paare sind also nichttrivial im Sinn der Datei.
- Eine Suche über alle nichttrivialen (q, a) mit q < 400 und a < 3000 findet als Maximum 4 und genau
  diese drei Paare (`scouting/2026-11-26/RANGLISTE.md`, Abschnitt Nachrechnungen).
- Ist das Maximum bei N = 6 gleich 4, erfüllen (120, 49) und (168, 121) die Voraussetzung `hmax`,
  aber nicht den Schluss q = 24. Die Aussage wäre dann für N = 6 falsch.

## Worauf sich das stützt und was fehlt

- Dass das Maximum bei N = 6 gleich 4 ist, steht laut Scout in der zitierten Quelle (González-Jiménez,
  Xarles, arXiv:1301.5122: Q(N) = Q(N; 24, 1) für 6 ≤ N ≤ 52). Der Scout hat nur das Abstract gelesen.
  **Vor einer Meldung im Volltext nachsehen.**
- Laut Abstract behauptet die Quelle Eindeutigkeit nur „bis auf Äquivalenz“ und nur für bestimmte N.
  Wie die richtige Lean-Aussage lauten müsste, ist nicht geklärt; das sollten die Betreuer entscheiden.

## Meldeweg

Issue in `google-deepmind/formal-conjectures`. Fehlerhafte Formalisierungen zu melden ist dort
ausdrücklich erwünscht (`CONTRIBUTING.md`, „Fix misformalisations“). Den Text schreibt Justus selbst,
mit Angabe der KI-Nutzung. Vorher nachsehen, ob es das Issue schon gibt.
