# R1-01 Stand-Wache vor Runde 1

Rolle: Stand-Wache. Datum aller Abfragen: 26.11.2026. Grundlage: Protokoll Abschnitt 7,
Auftrag `auftraege/R1-01.md` (auf Zweig `catch-up/R1-00`, Commit `593a775`).

## Ergebnis vorab

Die Vermutung ist nach unserem Stand vom 26.11.2026 **nicht gelöst** (kein Beweis, kein
Gegenbeispiel gefunden). Aber: **Es gibt ein öffentliches, aktives Projekt, das mit genau unseren
geplanten Ansätzen deutlich weiter ist** (`bocowgill-collaborations/catch-up-research`, Stand laut
eigener Angabe 27.10.2026). Das berührt **Abbruchregel 3** (Protokoll Abschnitt 6). Nach Auftrag
sofort festgehalten; Entscheidung liegt bei Koordinator und Justus.

Außerdem ist der Abschnitt „Bekannt“ in `ZIEL.md` veraltet: öffentlich gerechnet ist Remis bis
N = 34 (von Stengel 2019), privat berichtet bis N = 38; ein freies Programm rechnet exakt bis N = 28.

## Fund, der Abbruchregel 3 berührt

**Repo `github.com/bocowgill-collaborations/catch-up-research`** (Bo Cowgill und Mitwirkende,
KI-gestützt mit Codex, Lizenz Apache 2.0). Gelesen über `raw.githubusercontent.com` (Zweig `main`,
abgerufen 26.11.2026): `README.md`, `docs/research-handoff.md`, `docs/sources.md`,
`computation/README.md`, `CREDITS.md`, `CITATION.cff`. Die Commit-Liste war nicht abrufbar (siehe
unten); Datumsangaben stammen aus den Texten selbst.

Was das Repo nach eigener Angabe hat (nicht von uns nachgeprüft, Belegart: Herleitung/Angabe Dritter):

- Status 23.10.2026 „conjecture remains open“; letzte datierte Aktualisierung 27.10.2026
  (`research-handoff.md`). Aktiv mindestens August bis Oktober 2026.
- **Ausführbare Lean-Fassung des Spielwerts mit bewiesener Übereinstimmung zur Referenz**
  (`CatchUp/Executable.lean`). Das ist genau unser Auftrag R1-05.
- **Beweisspur mit Strategien und Induktion über Restmengen**, also unsere Angriffsidee „Beweis“:
  117 katalogisierte Lean-Module, Teilsätze („lower-ray endpoints“, „fifth-from-top theorem“ für alle
  N ≥ 23, strukturelle Abstiege, Zertifikatsprüfer mit Korrektheitsbeweis), dazu eine Liste
  gescheiterter Abkürzungen und widerlegter Strategieregeln. Offener Kern laut eigener Darstellung:
  eine gleichmäßige Übertragung/Induktion, die die Intervallgestalt erhält; außerdem das Remis von
  `Position({3,…,N},1)`.
- **Rechenspur:** Sammlung und Vergleich aller öffentlichen Rechnungen; keine eigenen Rekordläufe.
- **Turingmaschine** (388.819.712 Zustände), die genau dann hält, wenn die Vermutung falsch ist
  (Google-DeepMind-Cryptids), mit vollständigem Äquivalenzbeweis.
- Bittet öffentlich um Beiträge („shared research effort“).

Einschätzung (meine, Herleitung): Bei beiden geplanten Spuren (Beweis über Strategie/Induktion,
berechenbare Lean-Fassung) ist dieses Projekt gleich weit oder weiter. Ein anderer Ansatz bliebe nach
Abschnitt 6 erlaubt; welcher, ist offen.

## Weitere Funde

| Quelle | Inhalt | Belegart |
|---|---|---|
| B. von Stengel, LSE-Seminar 22.02.2019, https://www.lse.ac.uk/Mathematics/assets/documents/Events-Archive/CGO-PhD/PhD-Seminar-on-Combinatorics-2019-update.pdf#page=5 | Remis bei gerader Summe bis **N = 34** gerechnet; ein gewinnender erster Zug ist, falls vorhanden, eindeutig. Privat bis N = 38 (Mai 2024) laut catch-up-research. | zitiert nach catch-up-research und Websuche, PDF nicht selbst geöffnet |
| `github.com/t1merickson/catchup-exact` (README gelesen) | exakte Werte N = 21–28: Remis bei 23, 24, 27, 28; ungerade Summe dort stets Sieg des Anziehenden; C- und zwei Python-Löser; Python-Referenz zeilenweise aus der Lean-Datei (fc-Commit `e751934`) übernommen | Angabe Dritter, nicht nachgerechnet |
| `github.com/Kuberwastaken/c5-k4` | Remis N = 23, 24 (Bericht vom 14.08.2026) | zitiert nach catch-up-research |
| `github.com/ndesmo/leaning`, `PROBLEMS.md`, Eintrag P8 | dieselbe Vermutung als **Kandidat** gelistet (Issue #28, laut Websuche eröffnet 25.11.2026); erstes Ziel N = 23, 24 rechnen und in Lean prüfen. Nur Plan, kein Ergebnis. | gelesen |
| formal-conjectures Issues #1324 (Aufnahme der Vermutung) und #4834 (Normalisierte API) | nur aus Suchtreffern und catch-up-research bekannt, nicht geöffnet | nicht geprüft |

## Quellen nach Protokoll Abschnitt 7

### 1. formal-conjectures

- **Datei heute:** `FormalConjectures/Paper/CatchUpConjecture.lean` auf `main`, abgerufen über
  `raw.githubusercontent.com`: Zeile 181 `@[category research open, AMS 11 91]`, Zeile 182
  `theorem value_of_even_mul_succ_self_div_two`, Zeile 185 `sorry`. Kein `formal_proof`, keine
  weitere Datei im Klon nennt Catch-Up (Volltextsuche in `/home/user/fc` ohne `.git`).
- **Vergleich der Fassungen (SHA-256):** Stand `9097e2f`, Stand `5bd8bfb9` (lokaler Klon), aktueller
  `main` und Arbeitskopie des Klons sind bytegleich
  (`53b91539…0e2790`). Der Inhalt hat sich seit `9097e2f` also nicht geändert.
- **Zweige im Klon:** 40 Remote-Zweige (`packed-refs`), keiner mit Bezug zu Catch-Up.
- **Git-Verlauf: nicht geprüft.** `git log`/`git fetch` in `/home/user/fc` verweigert der
  Arbeitsbaum-Schutz dieser Sitzung („git operations must target its own worktree“); GitHub-API
  (`gh api`, GitHub-MCP) antwortet 403 bzw. „repository not configured for this session“;
  `github.com/.../commits/....atom` ebenso 403. Nicht umgangen.
- **Positivkontrolle (a): nicht bestanden im Sinn des Auftrags.** Die Commit-Liste der Datei ließ
  sich nicht abrufen. Ersatzweise: Über `raw.githubusercontent.com/.../7a3017f2/...` ist die Datei
  im bekannten Commit `7a3017f2` abrufbar (ältere Fassung ohne Modulsystem, `import
  FormalConjectures.Util.ProblemImports`); der Commit existiert also mit der Datei unter diesem Pfad.
  Ob zwischen `9097e2f` und heute Commits die Datei berührt haben, ist damit nicht ausgeschlossen,
  wohl aber eine inhaltliche Änderung.

### 2. Palomar-Register

- `palomar-registry.org` 200, `data.palomar-registry.org/api/v1/results` erreichbar
  (1.403 Ergebnisse, 1.074 Projekte). `data.palomar-registry.org/` selbst 404 (keine Startseite).
- **Positivkontrolle bestanden:** Suche „Kuhn poker“ findet den bekannten Eintrag; Suche „Erdos“
  liefert 25 Treffer; MSC 91 liefert 50 Einträge.
- Suchen ohne Treffer: „catch-up“, „catch up“, „catchup“, „catch“, „Isaksen“, „Brams“,
  „alternating lead“, „combinatorial game“, „cryptid“, „CatchUpConjecture“,
  „value_of_even_mul_succ_self_div_two“. MSC 91 (50 Einträge) und MSC 91A (23) ohne Catch-Up.
  „Cowgill“ findet 4 Einträge zu Matching-Märkten, keinen zu Catch-Up.
  `repositories/bocowgill-collaborations/catch-up-research.json` 404.
- `recent.json` und `feed.xml` vollständig durchsucht: kein Treffer zu catch-up, Isaksen, Brams.
- Ergebnis: **kein Palomar-Eintrag zu Catch-Up.**

### 3. arXiv und Websuche (letzte 90 Tage und älter)

- arXiv-API (`export.arxiv.org`, HTTPS; HTTP liefert 301): Abfragen `all:"catch-up" AND all:game`,
  `ti:"catch-up"`, `au:Isaksen AND au:Nealen`, `au:Brams AND ti:catch`, `all:"lead alternates"`,
  `ti:"lead alternates"`, `abs:"catch up" AND cat:math.CO`, `all:"Catch-Up" AND all:draw`,
  `all:"Catch-Up" AND cat:cs.GT`, `all:"Catch-Up" AND all:Brams`, `ti:catch AND cat:math.CO`.
  **Kein Treffer zu diesem Spiel** seit 28.08.2026 (90 Tage) und auch davor nicht.
- **Positivkontrolle (b), arXiv:** Das Paper von 2015 steht nicht auf arXiv (nur MPRA und
  nealen.net). Als Ersatz findet die Suche den bekannten verwandten Brams-Artikel 1808.06922
  („Catch-Up: A Rule that Makes Service Sports More Competitive“). Werkzeug funktioniert.
- **Positivkontrolle (b), Websuche: bestanden.** Die Suche „Catch-Up game Isaksen Ismail Brams
  Nealen conjecture draw“ findet die MPRA-Fassung
  (https://mpra.ub.uni-muenchen.de/108784/1/MPRA_paper_108784.pdf) und die Fassung auf nealen.net.
- Websuche (zwei Abfragen) lieferte die Funde oben: catch-up-research, ndesmo/leaning, Issue #1324.
  Keine Meldung eines Beweises oder Gegenbeispiels.

### 4. Zielspezifische Quellen aus `ZIEL.md`

- Git-Verlauf der Datei: siehe 1 (nicht geprüft).
- Palomar: siehe 2. arXiv/Web: siehe 3.
- Honors Thesis Feng 2024 (CUNY): nicht gesucht, nicht geöffnet.

## Nicht erreicht

| Quelle | Fehlerbild |
|---|---|
| Git-Verlauf in `/home/user/fc` | Arbeitsbaum-Schutz verweigert git außerhalb des eigenen Worktrees |
| GitHub-API für formal-conjectures | `gh api` 403 „GitHub access to this repository is not enabled“; GitHub-MCP „not configured for this session“ |
| `github.com` (Commit-Feeds, Issues, Repo-Seiten fremder Repos) | Proxy 403, gleiche Meldung. Nicht über andere Wege umgangen. |
| formal-conjectures Issues/PRs | wie oben; laut Protokoll prüft Justus sie im Browser |
| Commit-Daten von catch-up-research | wie oben; nur Datumsangaben im Text |
| LSE-PDF von Stengel, Thesis Feng | nicht abgerufen |

## Bericht

**Ergebnis:** Nach unserem Stand vom 26.11.2026 ist die Catch-Up-Vermutung offen, ohne
Palomar-Eintrag, ohne arXiv-Arbeit, die Lean-Aussage seit `9097e2f` unverändert. Aber das öffentliche
Projekt `bocowgill-collaborations/catch-up-research` arbeitet mit unseren geplanten Ansätzen
(berechenbare Lean-Fassung mit Äquivalenzbeweis, Strategie-/Induktionsbeweis) und ist deutlich
weiter; das berührt Abbruchregel 3. Zudem ist „Bekannt“ in `ZIEL.md` veraltet (Remis bis N = 34
öffentlich, N = 38 privat berichtet).

**Belege:** Abrufe vom 26.11.2026 wie oben (URLs, Hashes). Commit dieser Datei auf Zweig
`catch-up/R1-01`.

**Abweichungen und eigene Fehler:** Positivkontrolle (a) nicht erfüllt, Git-Verlauf daher nicht
geprüft (nur Inhaltsvergleich und Existenz von `7a3017f2`). Arbeitsbaum-Basis war `main`
(`38f2d5f`), in dem `auftraege/R1-01.md` noch fehlt; der Auftrag wurde vom Zweig `catch-up/R1-00`
gelesen. Aussagen über catch-up-research sind Selbstangaben, nicht nachgeprüft.

**Offene Punkte:** Justus: formal-conjectures Issues #1324, #4834 und offene PRs im Browser prüfen;
Commit-Verlauf von catch-up-research und `ndesmo/leaning` Issue #28 ansehen. Koordinator/Justus:
entscheiden, ob Abbruchregel 3 greift und ob ein anderer Ansatz bleibt. `ZIEL.md` „Bekannt“
aktualisieren.

**Empfehlung:** Runde anhalten und an Justus berichten, bevor weitere Arbeit (insbesondere R1-05 und
jede Beweisspur) läuft. Ohne einen klar anderen Ansatz: abbrechen bzw. ruhen lassen.
