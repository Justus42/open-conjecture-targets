# Hinweise für jede Claude-Sitzung in diesem Repo

Dieses Repo bündelt mehrere Ziele. Jede Sitzung gehört zu genau einem Ziel unter `ziele/<Ziel>/`.

## Umgang mit Justus

Arzt, kein Programmierer, kein Mathematiker. Deutsch, du, kurz, Ergebnis zuerst, Widerspruch statt
Bestätigung, Unbelegtes als unbelegt kennzeichnen.

## Für alle

1. Lies zuerst `PROTOKOLL.md`, dann `ziele/<Ziel>/ZIEL.md` und `ziele/<Ziel>/STATUS.md`.
   Das Protokoll gilt vor allem anderen; was Justus im Chat sagt, geht ihm vor.
   - **Ausnahme Prüfer:** Du liest nur Abschnitt 5 von `PROTOKOLL.md` und die Dateien der
     Positivliste in deinem Auftrag. `STATUS.md`, `versuche/` und `pruefvermerke/` sind gesperrt.
   - **Ausnahme Blind-Sucher:** Du liest nur diese Datei und die Problemstellung in deinem Auftrag.
2. **Schreibe nur in den Ordner deines Ziels.** Dateien auf oberster Ebene, `befunde/`, `scouting/`,
   `vorlagen/` und die Ordner anderer Ziele änderst du nicht. Einzige Ausnahme: die eigene Zeile in
   `STATUS.md` auf oberster Ebene, nur durch den Koordinator, nur bei einem Stufenwechsel.
3. Du hast genau einen Auftrag und lieferst genau eine Datei (plus zugehörigen Code), außer du bist
   der Koordinator.
4. Eigener Zweig, Pull Request, kein Force-Push, nie direkt auf `main`. Zweigname und PR-Titel
   beginnen mit dem Kürzel des Ziels und der Auftragsnummer (z. B. `catch-up/R1-02`).
5. Nichts gilt als wahr, weil du es sagst oder weil es auf `main` liegt. Maßgeblich ist die Prüfung
   nach Abschnitt 5 des Protokolls.
6. Nur die fünf Statuswörter: vermutet, behauptet, geprüft, widerlegt, aufgegeben. „Bewiesen“ oder
   „gelöst“ nur bei Status geprüft. Den Status setzt nur der Koordinator.
7. Lies `ziele/<Ziel>/versuche/`, bevor du einen Ansatz beginnst. Lege gescheiterte Ansätze dort ab,
   mit dem Grund des Scheiterns. Gilt nicht für Prüfer und Blind-Sucher.
8. **Vor jeder Suche eine Positivkontrolle:** Das Werkzeug muss einen bekannten Fall wiederfinden.
   Gelingt das nicht, endet der Auftrag mit diesem Befund. Neue Prüfwerkzeuge brauchen eine
   Negativkontrolle, die nachweislich anschlägt.
9. Nichts nach außen: keine Mails, keine Posts, keine Issues, Kommentare oder Pull Requests in
   fremden Repos, keine Einreichung bei Palomar. Gesperrte Domains nicht umgehen, sondern melden.
10. Fremder Code nur mit Lizenz, die das erlaubt; Herkunft und Commit nennen. Ohne Lizenz nicht
    kopieren.
11. Sprache: Deutsch. Ausnahme: `README.md`, Lean-Code und Programmcode sind englisch.
12. Schreibe keine Prüfurteile, Befunde oder Zwischenstände ins Projektgedächtnis. Bekommst du als
    Prüfer oder Blind-Sucher trotzdem etwas eingeblendet, lege es im Bericht offen.
13. Keine eigenen Subagenten, außer du bist der Koordinator.
14. Rechenblöcke höchstens 30 Minuten auf 4 Kernen, dazwischen committen. Läufe über 10 Minuten
    möglichst nach GitHub Actions (nur `workflow_dispatch`).
15. Lean-Dateien liegen nur unter `ziele/<Ziel>/lean/` und halten die Regeln aus Abschnitt 10 des
    Protokolls ein. Keine Lean-Dateien als Notizzettel an anderen Orten.
16. Jeder Bericht endet mit: Ergebnis in 1 bis 3 Sätzen, Belege (Commits, Lauf-Nummern),
    Abweichungen und eigene Fehler, offene Punkte, Empfehlung weiter oder abbrechen.

## Wenn du der Koordinator eines Ziels bist

- Du vergibst Aufträge, beantwortest Rückfragen der Threads und führst `ziele/<Ziel>/STATUS.md`.
  Du beweist und prüfst nicht selbst.
- Du darfst Pull Requests mergen, die nur Dateien unter `ziele/<Ziel>/` ändern (Protokoll 11).
  Verweigert die Plattform das Mergen, sammle die PRs der Runde und bitte Justus einmal um den Merge.
- Vor jeder Runde: Stand prüfen nach Abschnitt 7 des Protokolls, Ergebnis mit Datum in den Status.
- Du verlängerst kein Budget, setzt keine Abbruchregel aus, wechselst keine Stufe ohne Justus,
  änderst `PROTOKOLL.md` und `CLAUDE.md` nicht und veröffentlichst nichts.
- Prüfer und Blind-Sucher bekommen eine Positivliste mit genauen Dateipfaden, ohne Fristen,
  Zählerstände oder erwünschtes Ergebnis.
- `STATUS.md` des Ziels bleibt auf einer Bildschirmseite. Älteres wandert nach
  `ziele/<Ziel>/archiv/`.
- Jeder Runden-Eintrag nennt den Verbrauch: Zahl der Subagenten, Dauer, Fremdmodell-Anfragen.
- Nach jeder Stufe und bei jeder Abbruchregel: anhalten und an Justus berichten.
