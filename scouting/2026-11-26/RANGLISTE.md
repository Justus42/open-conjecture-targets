# Scouting vom 26.11.2026: Ergebnis

Eine Runde, nur lesen. Sechs Scouts (je ein Ordner aus `FormalConjectures/`, Repo-Commit `9097e2f`),
danach zwei Gegenleser, die nur die Steckbriefe bekamen. Aufträge: `AUFTRAG.md`, `GEGENLESER.md`.
Steckbriefe aller 13 Vorschläge: `steckbriefe.md`.

Abweichungen vom Auftrag: Wikipedia auf zwei Scouts geteilt; die Quantenprobleme liefen im
Sammel-Scout; zwei Gegenleser statt einem; Scouts und Gegenleser haben entgegen der Regel kleine
Rechnungen und eine Beweisskizze gemacht.

## Urteile

| Vorschlag | Eintrag | Gegenleser | Stärkster Einwand |
|---|---|---|---|
| Paper-1 | Catch-Up | hält | Relevanz knapp, keine bekannte Beweisidee |
| Arxiv-2 | Kristalle (biharmonisches Mittel) | hält knapp | Nischenbegriff aus einer einzigen Arbeit |
| Sammel-2 | Kourovka 20.51 | wackelt | hängt evtl. an Primzahlfrage, nur Beweisspur |
| Arxiv-1 | Gowers–Long, F(n) ≤ n^(3/2) | wackelt | nur Gegenbeispiel realistisch; fremder PR #7052 betrifft die Aussage |
| Paper-3 | Fusible Zahlen, Vermutung 7.1 | wackelt | viel Theorie wäre erst zu formalisieren |
| WikiA-1 | Hyperperfekte Zahlen (McCranie) | wackelt | reine Rechensuche |
| WikiB-1 | Sidorenko für Turniere, Bäume | fällt | mehrere aktive Gruppen |
| Green-1 | Green 24, γ = 1/3 | fällt | aktive Arbeit vom September 2026 |
| Green-2 | Green 28, 0–1-Polynome | fällt | drei Preprints in drei Monaten |
| Paper-2 | Latin Tableau | fällt | impliziert eine seit 2002 offene Vermutung |
| Sammel-3 | AME(8,4) | fällt | mehrere Kampagnen in derselben Datei |
| Sammel-1 | 677 → 255 | fällt | 14 Monate Arbeit einer großen Gruppe |
| WikiB-2 | Zelinsky, Vermutung 32 | fällt | zu leicht, siehe `befunde/ZELINSKY.md` |

## Entscheidung von Justus (26.11.2026)

Gestartet werden Catch-Up, Kourovka 20.51 und 677 → 255. Kristalle bleibt aus. 677 → 255 läuft trotz
des Urteils „fällt“ als ausgewiesener Fernschuss mit eigenen Regeln (`ziele/677-255/ZIEL.md`).

## Nachrechnungen der Scouting-Leitung

Eigene Programme, unabhängig von denen der Gegenleser, nicht zertifiziert:

- **Catch-Up:** Wert für den Anziehenden bei N = 1 bis 16. Gerade Summe (N = 3, 4, 7, 8, 11, 12, 15,
  16): immer Remis. Ungerade Summe: Anziehender gewinnt bei N = 1, 2, 5, 6, 13, Nachziehender bei
  N = 9, 10, 14.
- **Kristalle:** unter den ungeraden n ≤ 3 000 000 gibt es 134 Zerlegungen und keine Zahl mit zwei.
- **Kourovka 20.51:** für jedes ungerade t in [5, 20000] gibt es ein ungerades m mit 3 ≤ m < t, für
  das m(t−m)+1 eine Primzahlpotenz ist.
- **Zelinsky:** Konstruktion n = n₀·q^(q−1) in 975 Fällen ohne Fehler.
- **Rudin:** bei N = 6 erreichen (24, 1), (120, 49) und (168, 121) je vier Quadratzahlen; Maximum im
  Suchbereich q < 400, a < 3000 ist 4.

Rechnungen der Gegenleser, nicht wiederholt: Catch-Up Remis für N = 23, 24, 27; Kristalle ohne
Dublette unter rund einer Million Zerlegungen mit kleinerer Komponente bis 2·10⁶.

## Was nicht geprüft werden konnte

- GitHub-Issues und Pull Requests (aus der Umgebung nicht erreichbar).
- Das Palomar-Register war nur zu etwa einem Sechstel lesbar.
- Die Literaturangaben der Scouts sind nicht gegengelesen; viele Arbeiten wurden nur über
  Zusammenfassungen oder in Auszügen gelesen.
