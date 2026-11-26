# Ziel: 677 → 255 (Fernschuss)

Angaben aus dem Scouting vom 26.11.2026. Was nicht als nachgerechnet markiert ist, stammt aus den
Berichten der Scouts und ist nicht geprüft. Die Scouts haben den Zulip-Thread nur in Auszügen und
über Zusammenfassungen gelesen.

## Steckbrief

- **Eintrag:** `FormalConjectures/Other/EquationalTheories_677_255.lean`, Deklaration
  `Finite.Equation677_implies_Equation255` (Zeile 67, Markierung `research open, question` Zeile 66),
  Stand Commit `9097e2f` (24.11.2026)
- **Quelle:** Equational Theories Project (Tao u. a.), Abschlussbericht arXiv:2512.07087;
  Blueprint-Kapitel 13, https://teorth.github.io/equational_theories/blueprint/677-chapter.html ;
  Zulip-Thread „FINITE: 677 -> 255“,
  https://leanprover-community.github.io/archive/stream/458659-Equational/topic/FINITE.3A.20677.20-.3E.20255.html
- **Aussage für Laien:** Ein Magma ist eine Menge mit einer beliebigen Verknüpfungstafel x◇y.
  Gefragt ist, ob in jeder endlichen Tafel, in der immer x = y◇(x◇((y◇x)◇y)) gilt (Gleichung 677),
  automatisch auch immer x = ((x◇x)◇x)◇x gilt (Gleichung 255).
- **Lean-Aussage:** behauptet die Implikation. Das Projekt vermutet vorsichtig, dass sie falsch ist.
  Dann wäre das Ergebnis ein endliches Gegenmodell und die Lean-Aussage wäre zu verneinen.
- **Gewicht:** die einzige von 22 028 942 Implikationen, die das Projekt nicht entscheiden konnte.

## Bekannt (laut Scouts, ungeprüft)

| Aussage | Fundstelle |
|---|---|
| Für unendliche Magmen ist die Implikation falsch | Lean-Datei Zeile 48; Paper Abschnitt 5.5 |
| In endlichen 677-Magmen sind alle Linksmultiplikationen bijektiv | Blueprint, Lemma 13.1 |
| 255 gilt bei x genau dann, wenn R_x y = x lösbar ist; ein Gegenbeispiel ist also nicht rechtskürzbar | Blueprint, Lemma 13.2 |
| Lineare Modelle erfüllen 255; lineare, kohomologische und stückweise affine Erweiterungen liefern kein Gegenbeispiel | Blueprint 13.3, 13.4; Zulip |
| Keine 677-Magmen der Ordnungen 2, 3, 4, 6, 8; Ordnung 9 ohne Gegenbeispiel | Zulip |
| 677 zusammen mit 2910 impliziert 255 im Endlichen | Zulip, Dezember 2025 |
| Seit November 2025 sind nicht rechtskürzbare 677-Magmen bekannt (u. a. Größen 25, 49, 55, 77), keines ist ein Gegenbeispiel | Zulip |
| Letzter sichtbarer Beitrag im Thread: 10.02.2026 | Zulip-Archiv |

## Regeln nur für dieses Ziel

1. **Runde 1 liest nur.** Ergebnis ist eine Karte der bekannten Sackgassen und eine Liste dessen,
   was nachweislich noch niemand versucht hat. Kein Beweis- und kein Suchversuch.
2. **Budget:** Stufe 2 höchstens 8 Runden.
3. **Abbruch:** Entdecken zwei Runden in Folge nur wieder, was der Thread schon enthält, ruht das
   Ziel. Dazwischen liegt eine Ideenrunde nach Abschnitt 6 des Protokolls.
4. Jeder Ansatz nennt die Stelle im Thread oder Blueprint, an der er über das Bekannte hinausgeht.

## Risiken

1. Eine große Gruppe hat rund 14 Monate mit SAT-Lösern und Beweisern daran gearbeitet; das Paper
   nennt das Problem „immune“ gegen die Techniken des Projekts.
2. Unklar, welche Richtung stimmt.
3. Nicht alle Arbeit ist öffentlich sichtbar; Überholtwerden ist möglich.

## Meldeweg

Das Projekt war offen für Mitarbeit. Ein Gegenmodell wäre eine Tafel, die Lean per `decide` prüft.
Meldung über Palomar und einen Pull Request in formal-conjectures; ob zusätzlich das Repo des
Projekts oder Zulip, entscheidet Justus. Auf Zulip sind vom Sprachmodell verfasste Beiträge nicht
erlaubt.

## Quellen für die Stand-Wache

Git-Verlauf der Datei; Zulip-Archiv des Threads und des Kanals „Equational“; Repo
`teorth/equational_theories` (per `git`, nur lesen); arXiv und Websuche zu „677 255 finite magma
equational theories“; Palomar.
