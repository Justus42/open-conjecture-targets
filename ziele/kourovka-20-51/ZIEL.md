# Ziel: Kourovka 20.51

Angaben aus dem Scouting vom 26.11.2026. Was nicht als nachgerechnet markiert ist, stammt aus den
Berichten der Scouts und ist nicht geprüft.

## Steckbrief

- **Eintrag:** `FormalConjectures/Kourovka/20_51.lean`, Deklaration `kourovka_20_51` (Zeile 37,
  Markierung `research open` Zeile 36), Stand Commit `9097e2f` (24.11.2026). Datei im Repo seit
  19.11.2026 (Commit `d15c47a`).
- **Quelle:** Kourovka Notebook, Problem 20.51 (D. MacHale), https://arxiv.org/abs/1401.0300
- **Aussage für Laien:** Die Elemente einer endlichen Gruppe zerfallen in Konjugationsklassen.
  Gefragt ist, ob es zu jeder ungeraden Zahl t > 3 eine nicht kommutative Gruppe mit ungerade vielen
  Elementen gibt, die genau t Klassen hat.
- **Lean-Aussage:** `∀ t > 3, Odd t → ∃ G, Finite G ∧ (nicht kommutativ) ∧ Odd (Nat.card G) ∧
  Nat.card (ConjClasses G) = t`. Sie behauptet „ja“; wäre die Antwort „nein“, wäre sie unbeweisbar.
- **Fachgebiet:** endliche Gruppen, Klassenzahl

## Bekannt

| Aussage | Belegart | Fundstelle |
|---|---|---|
| Für abelsches A gilt k(G×A) = k(G)·|A|. Es genügen deshalb die Primzahlen t ≥ 5 und t = 9 | Herleitung (Gegenleser) | `scouting/2026-11-26/RANGLISTE.md` |
| Frobenius-Gruppe A⋊C_m mit abelschem Kern, m ungerade, hat m + (\|A\|−1)/m Klassen. Beispiele: 7:3 hat 5, 13:3 hat 7, 19:3 hat 9 | Herleitung (Gegenleser) | ebenda |
| Jedes ungerade t in [5, 20000] wird so erreicht: es gibt ein ungerades m mit m(t−m)+1 Primzahlpotenz | voll für diesen Bereich, zwei unabhängige Programme (Gegenleser, Scouting-Leitung) | ebenda |
| Das Kourovka-Heft führt 20.51 ohne Lösungsvermerk (Fassung v50 vom 03.11.2026) | laut Gegenleser | arXiv:1401.0300 |
| Für Gruppen ungerader Ordnung gilt k(G) ≡ \|G\| mod 16 | aus dem Gedächtnis, unbelegt | nachschlagen |

## Der Kern des Problems

Für „alle t“ braucht man zu jedem t ein passendes m, also eine Primzahlpotenz in einer dünnen
Menge. Eine solche Aussage kann niemand allgemein beweisen. Gesucht ist deshalb eine Konstruktion,
die ohne Primzahlannahme auskommt: andere Gruppenfamilien (p-Gruppen, metazyklische Gruppen,
Produkte und Erweiterungen), deren Klassenzahlen zusammen alle Primzahlen t ≥ 5 und t = 9 treffen.
Ob es das gibt, ist offen.

## Angriffsideen (aus dem Scouting, ungeprüft)

- **Beweis:** Klassenzahlformeln mehrerer Familien sammeln, rechnerisch erkunden, welche t jede
  trifft, und eine Überdeckung ohne Primzahlannahme suchen. Mathlib hat `ConjClasses`,
  `SemidirectProduct`, `ZMod`.
- **Gegenbeispiel:** praktisch nicht verfügbar. Ein t ohne solche Gruppe verlangte eine vollständige
  Klassifikation. Das Ziel ist einseitig.

## Risiken

1. Der allgemeine Fall hängt womöglich doch an einer unbeweisbaren Primzahlfrage. Dann bleibt nur
   „für alle t bis N“, und das ist ein Rechenrekord unter Palomars Schwelle.
2. Klassenzahlformeln einer Gruppenfamilie in Lean zu beweisen ist echte Arbeit.
3. Die Datei ist neu im Repo, das Kourovka-Heft wird 2026 sichtbar von KI-Kampagnen bearbeitet
   (laut Gegenleser nennt v50 mehrere Lösungen von 2026).

## Quellen für die Stand-Wache

Git-Verlauf der Datei; neueste Fassung von arXiv:1401.0300 (Problem 20.51 und 20.52); arXiv und
Websuche zu „number of conjugacy classes odd order non-abelian MacHale Kourovka 20.51“; Palomar.
