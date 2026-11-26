# Protokoll: offene Einträge aus Formal Conjectures

Fassung 0.2 vom 26.11.2026. Änderungen nur durch Justus.

Vorgabe von Justus (26.11.2026): Das Budget ist gut, keine schnellen Abbrüche. Die Rundenzahlen
und die Abbruchregeln in den Abschnitten 3 und 6 sind deshalb großzügig gefasst.

## 1. Ziel

Einzelne offene Einträge aus `google-deepmind/formal-conjectures` entscheiden: durch einen
Lean-4-Beweis der dort stehenden Aussage oder durch ein exakt geprüftes Gegenbeispiel.
Dahinter steht ein Test, was KI-Modelle in mathematischer Forschung leisten, wenn ein
Nicht-Mathematiker sie steuert.

### Nicht-Ziele

- Rechenrekorde ohne Beweis oder Gegenbeispiel.
- Fremde Beweise nachbauen oder portieren.
- Arbeit an Fragen, an denen die Urheber oder andere sichtbar mit demselben Ansatz arbeiten.

## 2. Ziele

| Ordner | Eintrag | Besonderheit |
|---|---|---|
| `ziele/catch-up` | `Paper/CatchUpConjecture.lean` | beide Spuren möglich |
| `ziele/kourovka-20-51` | `Kourovka/20_51.lean` | praktisch nur Beweisspur |
| `ziele/677-255` | `Other/EquationalTheories_677_255.lean` | Fernschuss, erste Runde nur Lesen |

Herkunft der Auswahl: `scouting/2026-11-26/`. Ein neues Ziel kommt nur durch Justus dazu.

## 3. Stufen je Ziel

Jedes Ziel durchläuft dieselben Stufen. Nach jeder Stufe hält der Koordinator an und berichtet;
die nächste Stufe beginnt nur nach Entscheidung von Justus.

### Stufe 0: Vortest (1 Runde)

- Stand prüfen (Abschnitt 7).
- Lean-Projekt unter `ziele/<Ziel>/lean/` anlegen, das baut und die Aussage wörtlich aus
  formal-conjectures enthält (Commit nennen).
- Aussage und Definitionen gegen die Quelle lesen. Abweichungen sind ein Befund, kein Grund zum
  Weiterarbeiten.
- Eine Positivkontrolle, die zum Ziel passt (steht in `AUFTRAG-R1.md`).
- Fertig mit einer Empfehlung: weiter, oder Ziel ungeeignet, mit Grund.

### Stufe 1: Erkundung (höchstens 3 Runden)

- Daten, Literatur, Landkarte der Ansätze. Kein Beweisangriff.
- Fertig mit einer Einschätzung: welche Spur, welches Zwischenziel, was dagegen spricht.

### Stufe 2: Angriff (höchstens 10 Runden, bei `677-255` höchstens 8)

- Zwei Spuren, wo beide möglich sind: Spur A Beweis, Spur B Gegenbeispiel.
- Fertig mit einem Ergebnis im Status geprüft, erschöpftem Budget oder einer Abbruchregel.

Eine Runde hat höchstens 6 Subagenten.

## 4. Rollen

| Rolle | Aufgabe | Liest |
|---|---|---|
| Koordinator | vergibt, führt Status, merged im eigenen Ordner | alles im eigenen Ziel |
| Beweissucher | schreibt Beweise, erst als Prosa, dann Lean | Ziel, Versuche |
| Sucher | sucht Gegenbeispiele oder Konstruktionen | Ziel, Versuche |
| Prüfer | prüft eine Behauptung an ihrem Artefakt | nur die Positivliste |
| Blind-Sucher | geht die Frage ohne Vorwissen an | nur die Problemstellung |
| Stand-Wache | prüft den fremden Stand vor jeder Runde | Ziel, Quellenliste |

Niemand prüft die eigene Arbeit. Der Koordinator beweist und prüft nicht. Ein Blind-Sucher ist nur
blind, wenn ihm kein Projektgedächtnis eingeblendet wird; sonst heißt er nicht so.

Justus lässt Berichte des Koordinators zusätzlich in einem getrennten Chat gegenprüfen.

## 5. Prüfpflicht

### 5.1 Beweise

Status geprüft nur, wenn alle Punkte erfüllt sind:

1. Lean-4-Beweis baut ohne `sorry`, in GitHub Actions, aus frischem Checkout.
2. `#print axioms` zeigt nur `propext`, `Classical.choice`, `Quot.sound`. Kein `native_decide`.
3. Die bewiesene Aussage ist die aus formal-conjectures, wörtlich, samt Definitionen (Commit nennen).
   Ein Prüfer vergleicht sie Zeile für Zeile.
4. Ein Prüfer, der den Beweis nicht geschrieben hat, bestätigt 1 bis 3.

### 5.2 Endliche Objekte und Zahlen

Ein Gegenbeispiel, eine Konstruktion oder ein berechneter Wert hat Status geprüft nur, wenn zwei
unabhängig geschriebene Programme (verschiedene Sitzungen, möglichst verschiedene Sprachen) exakt
dasselbe ergeben und ein Prüfer beide Läufe wiederholt hat. Für die Meldung zählt am Ende trotzdem
nur der Lean-Beweis nach 5.1.

### 5.3 Statuswörter

vermutet, behauptet, geprüft, widerlegt, aufgegeben. Bedeutung wie im README.

### 5.4 Belegart bei Negativbefunden

Jeder Negativbefund trägt eine Belegart:

- **voll**: vollständig durchgerechnet oder bewiesen
- **Gegenbeispiel**: je Fall ein nachgerechnetes Gegenbeispiel
- **Suche**: Suche erfolglos, schließt nichts aus
- **Herleitung**: Argument, nicht formal geprüft

### 5.5 Korrekturen

Jede `STATUS.md` eines Ziels hat eine Tabelle „früher / später gilt“. Korrigiertes wird dort
eingetragen, nicht stillschweigend überschrieben.

### 5.6 Fremdmodelle

Modelle anderer Familien nur für unabhängige Gegenprüfungen, höchstens zwei Anfragen je Runde, nie
ohne vorherige Bestätigung durch einen Prüfer. Jede Anfrage kostet Justus eigenes Geld.

## 6. Budget und Abbruch

Ein Ziel **ruht**, wenn eine dieser Regeln greift:

1. Das Rundenbudget der Stufe ist verbraucht.
2. Vier Runden in Folge ohne neuen Baustein, den ein Prüfer bestätigt hat. Nach der zweiten solchen
   Runde ist die nächste eine **Ideenrunde**: Literatursuche, Blind-Sucher und Übertragung von
   Methoden aus anderen Gebieten, mit dem Ziel neuer Ansätze. Sie zählt als Runde, aber ein neuer,
   begründeter Ansatz aus ihr setzt den Zähler auf null.
3. Die Stand-Wache findet, dass jemand anderes mit demselben Ansatz gleich weit oder weiter ist.
   Ein anderer Ansatz für dasselbe Ziel bleibt erlaubt.
4. Eine Suche besteht ihre Positivkontrolle nicht: Diese Spur ruht, bis das Werkzeug geeicht ist.
   Das Eichen selbst ist ein zulässiger Auftrag der nächsten Runde.

Ruhen heißt anhalten und berichten, nicht aufgeben. Justus kann ein ruhendes Ziel mit neuem Budget
fortsetzen.

Ein Ziel **endet**, wenn die Stand-Wache eine fremde Lösung findet oder wenn sich die Aussage als
falsch formalisiert herausstellt (dann Befund nach `befunde/`).

Der Koordinator verlängert nichts und legt keine Regel aus. Im Zweifel hält er an und fragt Justus.
Neue Ansätze für ein ruhendes Ziel darf jeder Bericht vorschlagen.

## 7. Stand prüfen vor jeder Runde

Vor der Vergabe einer Runde prüft die Stand-Wache und trägt Datum und Ergebnis in den Status ein:

1. formal-conjectures: `git fetch`, Verlauf der Datei des Ziels, Status-Markierung, `formal_proof`.
2. Palomar-Register, soweit erreichbar.
3. arXiv und Websuche der letzten 90 Tage zu den Stichworten aus `ZIEL.md`.
4. Zielspezifische Quellen aus `ZIEL.md` (z. B. Kourovka-Heft, Zulip-Archiv).

Was nicht erreichbar war, steht ausdrücklich im Eintrag. Issues und Pull Requests auf GitHub sieht
die Umgebung nicht; Justus prüft sie im Browser vor dem Start einer Stufe.

## 8. Aufbau des Repos

```
README.md, STATUS.md, PROTOKOLL.md, CLAUDE.md, LICENSE
ziele/<Ziel>/
  ZIEL.md            Steckbrief, Quellen, Bekanntes, Risiken
  STATUS.md          eine Bildschirmseite
  AUFTRAG-R1.md      Auftrag der ersten Runde
  auftraege/         weitere Aufträge, eine Datei je Auftrag
  behauptungen/      eine Datei je Behauptung, ohne Status
  pruefvermerke/     Prüfurteile und Status
  versuche/          gescheiterte und laufende Ansätze, mit Grund
  rechnung/          Programme und Daten
  lean/              eigenes Lean-Projekt des Ziels
  archiv/            alte Statusfassungen
befunde/             Nebenbefunde aus Scouting und Arbeit
scouting/            Herkunft der Zielauswahl
vorlagen/            Vorlagen für Aufträge und Projektanweisungen
```

Ordner entstehen erst, wenn sie gebraucht werden.

## 9. Nach außen und Redlichkeit

- Nichts geht nach außen ohne Entscheidung von Justus. Das gilt für Issues, Pull Requests,
  Kommentare, Palomar, Zenodo, arXiv, Zulip, Discord und Mails.
- Meldeweg für ein geprüftes Ergebnis: Palomar-Eintrag, danach ein kleiner Pull Request in
  formal-conjectures, der den Eintrag als gelöst markiert und verlinkt.
- Texte für Issues, Pull Requests und Kommentare in formal-conjectures schreibt Justus selbst. Dort
  gelten die Mathlib-Regeln: KI-Nutzung offenlegen, keine vom Sprachmodell verfassten Kommentare.
  Sitzungen liefern ihm dafür Fakten in Stichpunkten, keinen fertigen Text.
- Palomar verlangt Menschen als Autoren und Verantwortliche. KI-Anteile stehen dort unter
  `automation.methods`.
- Wortwahl: „nach unserem Stand vom <Datum>“ statt Neuheitsbehauptungen. Eine Aussage der Art „als
  Erste“ nur mit dokumentierter Literatursuche.
- Ergebnisse gehören den Urhebern der Fragen und der benutzten Methoden; Quellen stehen in `ZIEL.md`.
- Jede Ergebnisnotiz enthält eine vollständige Offenlegung der KI-Nutzung und den Satz, dass kein
  Mathematiker das Ergebnis geprüft hat, solange das zutrifft.

## 10. Lean und Palomar

Stand der Angaben: 26.11.2026, aus `PalomarRegistry/PalomarPolicy` (`CONTRIBUTING.md`) und aus
formal-conjectures (Commit `9097e2f`). Vor einer Einreichung neu lesen.

- formal-conjectures steht auf `leanprover/lean4:v4.33.1`.
- Palomar nimmt nur Lean-Versionen von seiner Liste (`toolchains.json` im Repo `PalomarSubmission`)
  und verlangt das Modulsystem. Laut dem Text eines gemergten Pull Requests (#7992) braucht Palomar
  mindestens Lean 4.35 und importiert formal-conjectures nicht; die Aussage wird deshalb wörtlich in
  eine eigene Datei `Challenge.lean` kopiert. Im Vortest prüfen.
- Die Aussage-Datei (Challenge) darf nur Lean-Kern und Mathlib importieren (dazu Tau Ceti, CSLib),
  höchstens 1.000 Zeilen und 100 KiB. Der Beweis (Solution) darf weitere öffentliche GitHub-Repos
  nutzen.
- Jede `.lean`-Datei im ganzen Repo zählt mit: Modulsystem, höchstens 10.000 Zeilen. Deshalb liegen
  Lean-Dateien nur unter `ziele/<Ziel>/lean/` und sind sauber.
- Palomar kann ein Projekt in einem Unterordner auswählen; die eine Lizenzdatei liegt ganz oben.
- Erlaubte Axiome: `propext`, `Quot.sound`, `Classical.choice`.
- Relevanzschwelle: Das Ergebnis muss plausibel eine Forschungsnotiz tragen. Die Prüfung macht ein
  Sprachmodell, es gibt keinen Einspruch. Bei `catch-up` ist das ein benanntes Risiko.

## 11. Git-Regeln und Rechte

1. Jeder Thread: eigener Zweig, Pull Request, nur Dateien des eigenen Auftrags.
2. Der Koordinator eines Ziels darf Pull Requests mergen, die ausschließlich Dateien unter
   `ziele/<Ziel>/` ändern. Alles andere merged Justus. Justus kann diese Regel jederzeit auf „nur
   Justus merged“ umstellen.
3. Dateien auf oberster Ebene ändert nur Justus, mit Ausnahme der eigenen Zeile in `STATUS.md`
   (Koordinator, bei Stufenwechsel).
4. Rechen-Workflows starten nur von Hand (`workflow_dispatch`).
5. Der Koordinator ändert weder dieses Protokoll noch `CLAUDE.md`. Fehlt eine Regel, hält er an.
