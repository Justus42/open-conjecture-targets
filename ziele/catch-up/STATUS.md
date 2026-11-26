# Status: Catch-Up

Zuletzt geändert: 26.11.2026 (Runde 1 angehalten). Diese Datei bleibt auf einer Bildschirmseite;
Älteres nach `archiv/`.

## Aktuell

- **Stufe:** 0 (Vortest), Runde 1 **angehalten nach Abbruchregel 3** (Protokoll 6), Ziel **ruht**
- **Runden verbraucht:** 1 von 1 (R1-05 nicht vergeben, R1-02 unvollständig)
- **Nächster Schritt:** Entscheidung von Justus: ruhen lassen, oder anderer Ansatz mit neuem Auftrag

## Stand-Wache

| Datum | Ergebnis | Nicht erreicht |
|---|---|---|
| 26.11.2026 (Scouting) | kein Beweis, keine Widerlegung gefunden | GitHub-Issues und PRs, Palomar großteils |
| 26.11.2026 (R1-01) | Vermutung offen, Lean-Datei inhaltlich unverändert seit `9097e2f`, kein Palomar-Eintrag, nichts auf arXiv. **Aber:** `bocowgill-collaborations/catch-up-research` (aktiv bis mind. 27.10.2026) arbeitet mit unseren beiden Spuren (berechenbare Lean-Fassung mit Äquivalenzbeweis, Strategie/Induktion mit über 100 Lean-Modulen) und ist laut eigener Angabe weiter. Einzelheiten: `versuche/r1-01-stand.md` (Zweig `catch-up/R1-01`) | Git-Verlauf der Datei (git/GitHub-API gesperrt), fc-Issues #1324, #4834, LSE-PDF, Thesis Feng |

## Geprüft

Nichts.

## Behauptet

- Remis für alle N ≤ 20 mit gerader Summe; Werte N = 3 … 20 wie Tabelle 2 des Papers. Zwei
  getrennte Programme (R1-03, R1-04) ergeben dieselben Werte und dieselben besten ersten Züge.
  Beide in C++, Prüfer-Wiederholung nach 5.2 fehlt.
- Lean-Aussage entspricht den Regeln des Papers (R1-02, Zeile für Zeile gelesen; Projekt noch nicht
  gebaut).

## Offen

- Ob die Vermutung stimmt.
- R1-02: Bau, Positiv-/Negativkontrolle, Workflow-Vorschlag.

## Negativbefunde

| Befund | Belegart | Fundstelle |
|---|---|---|

## Korrekturen (später gilt)

| früher | später | Quelle |
|---|---|---|
| Datei seit 19.10.2026 unverändert | letzter Commit an der Datei 18.09.2026 (`6fbb54f2`), laut Klon des Koordinators | `git log` in formal-conjectures, 26.11.2026 |
| Bekannt: Remis bis N = 27 | öffentlich gerechnet bis N = 34 (von Stengel 2019), laut Dritten; nicht nachgeprüft | R1-01 |

## Verbrauch

| Runde | Subagenten | Dauer | Fremdmodell-Anfragen |
|---|---|---|---|
| 1 | 4 (R1-01 bis R1-04) | ca. 15 Min. Rechenzeit, 26.11.2026 | 0 |
