# Vorlage: Auftrag an einen Thread oder Subagenten

Ablage: `ziele/<Ziel>/auftraege/<Nummer>.md`. Eine Datei je Auftrag.

```
# <Ziel> <Runde>-<Nr>: <Titel in einer Zeile>

Rolle: Beweissucher | Sucher | Prüfer | Blind-Sucher | Stand-Wache
Zweig: <ziel>/<Runde>-<Nr>
Zieldatei: ziele/<Ziel>/<Pfad>

## Aufgabe
<Was genau zu liefern ist, in zwei bis fünf Sätzen.>

## Darfst du lesen
<Für Prüfer und Blind-Sucher: Positivliste mit genauen Pfaden. Sonst: „alles im Ziel-Ordner“.>

## Positivkontrolle
<Bei Suchen und Rechnungen: welcher bekannte Fall zuerst wiedergefunden werden muss.>

## Fertig, wenn
<Prüfbares Kriterium.>

## Abbruch
<Wann der Auftrag ohne Ergebnis endet und was dann zu berichten ist.>

## Grenzen
Rechenblöcke höchstens 30 Minuten, dazwischen committen. Keine eigenen Subagenten.
Nichts nach außen. Nur die Zieldatei und zugehörigen Code ändern.
```

Nicht in einen Auftrag gehören: Fristen, Zählerstände, das erwünschte Ergebnis, Urteile anderer
Prüfer.
