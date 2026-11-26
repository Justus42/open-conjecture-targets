# Befund: Zelinskys Vermutung 32 ist vermutlich kurz beweisbar

Stand 26.11.2026. Nicht gemeldet, kein Lean-Beweis geschrieben. Ein Scout und ein Gegenleser fanden
die Konstruktion unabhängig voneinander.

## Stelle

`FormalConjectures/Wikipedia/RefactorableNumber.lean` (Commit `9097e2f`), Satz
`zelinsky_refactorable_progression_conjecture` (Zeilen 75 bis 79), markiert `research open`.
Die Datei kam am 23.11.2026 mit einem Sammel-Pull-Request (#8058) ins Repo.

Aussage: Für jedes m ≥ 1 und jede refaktorisierbare Zahl n₀ gibt es eine refaktorisierbare Zahl
n > n₀ mit n ≡ n₀ (mod m). Refaktorisierbar heißt: Die Anzahl der Teiler von n teilt n.

Quelle: J. Zelinsky, „Tau Numbers: A Partial Proof of a Conjecture and Other Results“, Journal of
Integer Sequences 5 (2002), Article 02.2.8, Conjecture 32.

## Das Argument

1. Wähle eine Primzahl q mit q ≡ 1 (mod m), die n₀ nicht teilt. Solche gibt es unendlich viele.
2. Setze n = n₀ · q^(q−1).
3. Weil q kein Teiler von n₀ ist, hat n genau τ(n₀) · q Teiler.
4. τ(n₀) teilt n₀ (Voraussetzung), und q teilt q^(q−1). Also teilt die Teilerzahl von n die Zahl n.
5. Aus q ≡ 1 (mod m) folgt q^(q−1) ≡ 1 (mod m), also n ≡ n₀ (mod m). Außerdem n > n₀.

Beispiel: n₀ = 2, m = 3, q = 7. Dann n = 2 · 7⁶ = 235298 mit 14 Teilern; 235298 = 14 · 16807, und
235298 ≡ 2 (mod 3).

## Belege

- Nachgerechnet in 975 Fällen (25 refaktorisierbare n₀, m von 1 bis 39) von der Scouting-Leitung und
  in 1050 Fällen vom Gegenleser, jeweils ohne Fehler.
- Benötigt nur: unendlich viele Primzahlen ≡ 1 modulo m, Multiplikativität der Teilerzahl. Der
  Mathlib-Name für den ersten Punkt ist nicht nachgeschlagen.

## Vorbehalte

1. **Wortlaut prüfen.** Beide Agenten haben Zelinskys Arbeit nur über eine Zusammenfassung gelesen.
   Dass ein Zahlentheoretiker ein so kurzes Argument übersieht, ist möglich, aber auffällig. Vor
   jedem Schritt die Vermutung im Original lesen.
2. Ob das Argument schon veröffentlicht ist, wurde nicht gesucht.
3. Für Palomar ist das zu klein. Der Weg wäre ein kurzer Beweis direkt im Repo.
4. Die Datei ist neu; ein anderer Beitragender kann den Eintrag jederzeit schließen.

## Meldeweg

Nach dem Verfahren des Repos: erst ein Issue mit der Absicht, dabei sehen, ob schon jemand
zugewiesen ist; dann ein Pull Request mit dem Lean-Beweis. Dafür ist die Lizenzvereinbarung von
Google nötig. Texte schreibt Justus selbst, mit Angabe der KI-Nutzung.
