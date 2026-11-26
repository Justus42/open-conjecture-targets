# R2-01: Landkarte von catch-up-research (nur gelesen)

Stand: 26.11.2026. Rolle: Sucher, nur Lesen. Kein Beweisversuch, kein Lean-Bau, nichts nach außen.

## Ergebnis zuerst

Die Vermutung ist dort **offen** (Übergabedokument vom 27.10.2026, Zeile 3). Das Projekt ist ruhig,
aber nicht erkennbar eingestellt: Der öffentliche `main` steht am 26.11.2026 weiter auf `b0853b4`,
also seit einem Monat ohne neuen Commit. Die im Übergabedokument empfohlene Aufgabe zu **CU-L039 ist
offen** und ist der kleinste sinnvolle Beitrag: ein rein arithmetisches Lemma in Lean, ohne
Spielregeln. Ein Beitrag muss auf **Lean v4.27.0 mit Mathlib `a3a10db`** gebaut werden (nicht auf
unserer fc-Version v4.33.1) und die dortigen Prüfskripte bestehen.

## Quelle und Positivkontrolle

- Klon `/home/user/cur`, `main` = `b0853b4e71d240ed539855cbaf91da7855a4685f` (aus `.git/refs/heads/main`
  gelesen; git-Befehle im Klon verweigert die Umgebung). `git ls-remote` am 26.11.2026: öffentlicher
  `HEAD` ebenfalls `b0853b4`. Es gibt 9 Pull-Request-Referenzen (`refs/pull/1` bis `9`), alle aus den
  `codex/*`-Zweigen des Betreibers; keine fremde PR zu CU-L039. Issues sieht die Umgebung nicht.
- Vollständig gelesen: `docs/research-handoff.md`, `results/open-questions.md`,
  `results/failed-ideas.md`, `results/research-routes.md`, `CONTRIBUTING.md`, `CREDITS.md`.
  Zusätzlich gezielt: `README.md`, `results/fifth-endpoint.md`, `results/lower-ray-endpoints.md`,
  `results/legacy-findings.md` (CU-L039), Notizbuch
  `archive/campaigns/notebooks/uniform-descent-20260929/INDEPENDENT_IDEA--4569e7ba.md`,
  `verification/README.md`, `scripts/check_axioms.py`, `scripts/check_collection.py`,
  `.github/workflows/verify.yml`, `lakefile.toml`, `lake-manifest.json`, `CITATION.cff`.
- **Positivkontrolle bestanden:** Der „fifth-from-top lower-ray theorem“ steht als
  `CatchUp.pair_deletion_position_fifth_from_top_value_ne_loss (N : ℕ) (hN : 23 ≤ N) :
  (pairDeletionPosition N 1 (N - 4)).value ≠ .loss` in `CatchUp/LowerRayFifthEndpoint.lean`,
  Zeile 585 (README Zeile 63, `results/fifth-endpoint.md`). Auf Deutsch: Für jedes N ≥ 23 verliert
  der Spieler am Zug nicht, wenn aus {1, …, N} die Zahlen 1 und N−4 entfernt sind und er N−5 Punkte
  zurückliegt.

## Begriffe (kurz)

- **Position (S, d):** noch liegende Zahlen S, der Spieler am Zug liegt d Punkte zurück (d = Rückstand,
  dort „deficit“).
- **nonloss / nicht verlierend:** der Spieler am Zug kann eine Niederlage sicher vermeiden, egal wie der Gegner spielt.
  **Remis** heißt: beide Seiten haben eine solche Garantie.
- **Q_N(b):** die Lage nach Eröffnung b und Antwort 1, formal `(I_N \ {1, b}, b − 1)`, mit
  I_N = {1, …, N}. Die Familie aller Q_N(b) heißt dort „lower ray“ (untere Reihe).
- **First-pair draw:** Remis von Q_N(2) = ({3, …, N}, 1).
- **Exact-sum block:** eine Teilmenge der liegenden Zahlen, deren Summe genau den Rückstand ergibt.
- **Port:** ein älterer, archivierter Beweis, der an die aktuelle Bibliothek angepasst und neu
  gebaut wurde. Dort ausdrücklich keine Neuentdeckung.

## 1. Landkarte: was bewiesen ist

Drei Sicherheitsstufen, wie das Projekt sie selbst trennt (`docs/research-handoff.md` Z. 42–44).

### 1a. In Lean geprüft (im öffentlichen Bau, Axiomprüfung durch `scripts/check_axioms.py`)

Ungeprüft von uns: Wir haben nichts gebaut. „In Lean geprüft“ heißt hier „laut Repo im CI-Bau
enthalten“.

| Aussage | Lean-Fundstelle |
|---|---|
| Hauptreduktion: Wenn alle Q_N(b) nicht verlierend sind **und** Q_N(2) Remis ist, dann ist {1, …, N} Remis | `CatchUp/PairDeletion.lean`, `value_Icc_eq_draw_of_lower_pair_deletion_nonloss` (Z. 165) |
| Q_N(N) nicht verlierend, N ≥ 3 | `CatchUp/Earlier/DeficitWinningBound.lean` (laut `results/lower-ray-endpoints.md` Z. 13) |
| Q_N(N−1) nicht verlierend, N ≥ 7 | `CatchUp/LowerRayEndpoints.lean`, `pair_deletion_position_penultimate_value_ne_loss` (Z. 118) |
| Q_N(N−2) nicht verlierend, **unter der Annahme**, dass eine kleinere Lage (Eröffnung 1 auf I_(N−4)) Remis ist | `CatchUp/LowerRayAntepenultimateDescent.lean`, Z. 47 |
| Q_N(N−3) nicht verlierend, N ≥ 15 (und gerade Dreieckszahl N ≥ 11) | `CatchUp/LowerRayFourthEndpoint.lean`, Z. 266 und 286 |
| Q_N(N−4) nicht verlierend, N ≥ 23 (Positivkontrolle) | `CatchUp/LowerRayFifthEndpoint.lean`, Z. 585 |
| Alle Eröffnungen remis ⇔ alle Zweierfortsetzungen „neutral“ | `CatchUp/Earlier/ReplyDigraphReduction.lean`, `every_opening_draw_Icc_iff_every_pair_neutral` (Z. 331) |
| Bedingte Kriterien für den Kern {4,7} ∪ [9,N] bzw. {3,4} ∪ [9,N] | `CatchUp/RootUpperEightCriterion.lean` (`interval_reserve_nonwin_iff_core_nonloss`, Z. 90, setzt V(C_N, 8) = Verlust voraus); `CatchUp/ConsecutiveGuardBoundary.lean` (`winning_pick_bound`, Z. 24) |
| Bedingter Begleitsatz CU-R001 (Maximum-Antwort) | `CatchUp/ReplyMaximumCompanion.lean`, nur unter Nichtleer-/Einholbarkeitsannahmen (`results/reply-maximum-companion.md`) |
| Auswerter stimmt mit den Referenzregeln überein; Zertifikatsprüfer korrekt | README „Proofs and intermediate results“; `CatchUp/Earlier/CertificateSoundness.lean` |
| Wurzel-Remis nur als kleine Prüffälle N = 3, 4, 7 in Lean; N27/N28-Zertifikate liegen nur als große native Dateien vor und gehören **nicht** zum öffentlichen Bau | `computation/README.md` Z. 45; `verification/pr1-review.md` Z. 75 |
| Kryptid: eine Turingmaschine mit 388.819.712 Zuständen hält genau dann, wenn die Vermutung falsch ist | `cryptid/` (eigenes Paket, Lean 4.35.0-rc4) |

Umfang laut Übergabe: 117 katalogisierte Module (`docs/research-handoff.md` Z. 12).
Die Spielregeln (`CatchUp/Reference.lean`) sind laut `verification/pins.json` unverändert aus
formal-conjectures übernommen, ohne die offene Vermutung selbst.

### 1b. Informell (Argument im Notizbuch, nicht in Lean)

- **CU-L039** Packungsschranke (siehe Abschnitt 3); `results/legacy-findings.md` Z. 403–411.
- Viele Einträge des Fund-Registers CU-L001 bis CU-L043 tragen nur „historical“ oder „informal“ als
  Belegart; z. B. die Vier-Pflichten-Normalform CU-L007/CU-L008 ist ein „reported scratch result“
  ohne wiedergefundene Beweisdatei (`results/research-routes.md` Z. 5).

### 1c. Nur behauptet / berichtet

- Remis bis N = 34 (von Stengel 2019, LSE-Vortrag), private Rechnungen bis N = 38; nicht öffentlich
  zertifiziert (`CREDITS.md` Z. 20, `docs/research-handoff.md` Z. 127–130).
- Historische Läufe bis N = 32 mit großen, verlorenen Tabellen (CU-L041).
- 25 fehlende Artefakte (Quellen, Tabellen, Prüfprogramme) im Register
  `archive/campaigns/README.md#missing-artifacts-and-deferred-verification`.

## 2. Offene Beweispflichten

Alle mit Fundstelle; „offen“ heißt: das Projekt sagt selbst, es fehlt.

1. **Ganze untere Reihe:** Q_N(b) nicht verlierend für **alle** b, nicht nur die fünf oberen Enden.
   Endlich viele Enden decken das Innere nicht ab (`docs/research-handoff.md` Z. 48–53).
2. **First-pair draw:** Q_N(2) = ({3, …, N}, 1) ist Remis, für zulässige N ≥ 7 mit eigenen kleinen
   Basisfällen (bei N = 3 ist diese Lage gewonnen, eine Formulierung ohne Ausnahme wäre falsch);
   `results/research-routes.md` Abschnitt „Pair deletion…“.
3. **Kern {4,7} ∪ [9,N] bei Rückstand 1**, unter der Annahme V({2,3,4,7} ∪ [9,N], 8) = Verlust; dazu
   der Zweig {3,4} ∪ [9,N]. Gesucht ist eine Bedingung, die jede gegnerische Antwort übersteht
   (`results/open-questions.md`, „Current structural proof frontier“; `results/research-routes.md`
   „Dense states…“). Die Abschätzung „q + 6 ≤ N“ allein ist kein unendlicher Abstieg, weil sich die
   Menge beim Schritt ändert.
4. **Allgemein:** eine einheitliche, gegen alle Antworten geschlossene Strategie oder Induktion, die
   die Intervallgestalt und die Annahmen erhält (`docs/research-handoff.md` Z. 59–64). Das ist der
   eigentliche Engpass.
5. **Nebenspuren:** kleinere Kryptid-Maschine (211.100.482 Zustände) braucht noch drei Beweisteile;
   Wiederbeschaffung fehlender Tabellen/Prüfprogramme; unabhängige Prüfung der Läufe von
   `catchup-exact` und `c5-k4` (README „Computational evidence“). Das Projekt sagt ausdrücklich, dass
   neue Ergebnistabellen den Engpass nicht lösen (`results/research-routes.md`, letzter Absatz).

## 3. Nachweislich gescheiterte Ansätze

Wichtig: Keiner dieser Befunde widerlegt die Vermutung selbst; widerlegt ist jeweils eine Abkürzung
(`results/failed-ideas.md` Z. 3). Belegart nach unserem Protokoll 5.4 in Klammern.

| Abkürzung, die nicht funktioniert | Belegart | Lean-Fundstelle (laut `results/failed-ideas.md`) |
|---|---|---|
| Gemeinsame Zahlen im Nachbarlücken-Tausch kopieren | Gegenbeispiel | `AdjacentHoleExchangeObstruction.lean` |
| Nur Minimum 3 und Parität beim First-pair-Transfer nutzen | Gegenbeispiel | `FirstPairDescentObstruction.lean` |
| Verschobene Antwortzyklen ausschließen | Gegenbeispiel | `ShiftedReplyCycle.lean` |
| Vorausbezahlte Reserve für große N anlegen (geht nur bei N = 7, Eröffnung 3) | voll (für die angegebene Hülle) | `TurnReserveInitialization.lean` |
| Wenige Kennzahlen (Anzahl, Summe, Extreme, Parität) bestimmen den Wert | Gegenbeispiel | `AdviceFeatureCollision.lean` |
| Kleine Paarverteidigung um zwei Paare verlängern | Gegenbeispiel | `SevenPairTest.lean`, `FourOrphan.lean` |
| Ein einziger ausgleichender Zug als Universalverteidigung (für N ≥ 7 unmöglich) | voll | `WholeTurn.lean` |
| In einen exakten Summenblock mit dessen eigener Zahl einsteigen | Gegenbeispiel | `DenseBlockEntryObstruction.lean` |
| Lückennachfolger-Zug, Dichteannahmen weglassen | Gegenbeispiel | `GapSuccessorObstruction.lean`, `FullGapDensity*.lean` |
| Reserve schon im ersten Reparaturzug verwenden | voll (unter den Annahmen) | `EqualityReserveObstruction.lean` |
| „Zahl knapp unter dem Rückstand“ oder „Minimum 2“ sichert Nichtverlust | Gegenbeispiel | `NearDeficitGuardObstruction.lean`, `UnitGuardObstruction.lean` |
| Immer mit der nächsthöheren freien Zahl antworten (scheitert ab N = 15) | Gegenbeispiel | `IntervalSuccessorReplyObstruction.lean` |
| Abwechselnde Paritäten im Schwanz sichern Nichtverlust | Gegenbeispiel | `AlternatingTailObstruction.lean` |
| Nur obere Zahlen im Summenblock (CU-L038) | voll (für diese Beweissprache) | `CatchUp/Earlier/UniformExactSumDescentObstruction.lean` |
| Mehrzug-Antwort ohne Prüfung der Zwischenstände planen | Herleitung | `docs/research-handoff.md` Z. 75 |
| Aus der Größe vollständiger Zertifikate eine allgemeine Beweislängen-Schranke folgern | Herleitung | ebenda Z. 76 |

## 4. Mögliche Beiträge, vom kleinsten zum größten

### Prüfung der Aufgabe CU-L039

- **Was verlangt ist** (`docs/research-handoff.md` Z. 85–88): Formalisiere in Lean: Für jede ganze
  Zahl q ≥ 3 gibt es höchstens ⌊(q−1)/2⌋ paarweise disjunkte Mengen aus verschiedenen ganzen Zahlen
  ≥ 2, die jeweils die Summe q haben; und diese Zahl wird erreicht. Ausdrücklich: Das begrenzt nur
  eine bestimmte „Erzwingungs-Grammatik“, nicht alle Beweise.
- **Noch offen?** Ja, nach unserem Stand vom 26.11.2026: kein Lean-Modul enthält das Lemma (Suche nach
  „packing/complement“ in `CatchUp/` leer); `results/endpoint-trap-atlas.md` Z. 75 nennt es „remains
  informal“; `verification/pr1-review.md` Z. 65: „without a new formalization“; der öffentliche
  `main` ist seit `b0853b4` unverändert, und es gibt keine fremde PR. Offene Issues konnten wir nicht
  sehen; Justus sollte das vor einer Einreichung im Browser prüfen.
- **Mathematischer Inhalt** (Notizbuch `INDEPENDENT_IDEA--4569e7ba.md`, Abschnitt 2): Jede benutzte
  Zahl ist ≤ q, und q−1 kann nicht vorkommen (der Rest wäre 1). Also liegen alle Mengen in
  {2, …, q−2, q}, deren Gesamtsumme q(q−1)/2 ist. Bei r disjunkten Mengen folgt r·q ≤ q(q−1)/2.
  Erreicht wird die Schranke durch {q} und die Paare {a, q−a} mit 2 ≤ a < q/2. Ich habe das Argument
  nachgelesen und halte es für richtig (Belegart: Herleitung, nicht formal geprüft).
- **Was man bräuchte:** eine Lean-Datei mit etwa zwei Sätzen über `Finset (Finset ℕ)`
  (Schranke und Erreichbarkeit). Nur Mathlib-Finset-Arithmetik, keine Spielregeln. Dazu die
  Pflichtpflege im Repo (siehe Abschnitt 5).
- **Der zweite Teil von CU-L039** (die Folgerung für das „consecutive-lower-pivot“-Schema auf
  F(m,k) = [2,m] ∪ [m+3, m+k+2]: es bräuchte k disjunkte Ergänzungen der Summe k+2, es gibt aber nur
  ⌊(k+1)/2⌋ < k) ist **nicht** Teil der Empfehlung und setzt eine Lean-Definition dieses Schemas
  voraus, die es dort nicht gibt.

### Beitrag 1 (klein): CU-L039-Packungslemma in Lean

- **Inhalt:** neues Modul, z. B. `CatchUp/ComplementPacking.lean`, mit Schranke und Erreichbarkeit.
- **Aufwand:** klein; geschätzt ein bis zwei Runden einschließlich Pflichtpflege und unserer eigenen
  Prüfung nach Protokoll 5.1 (Schätzung, unbelegt).
- **Risiko:** gering mathematisch. Formales Risiko: Die Formulierung muss genau die Aussage treffen
  (disjunkt, Elemente ≥ 2, Summe = q, q ≥ 3); eine zu schwache Fassung wäre wertlos. Inhaltlicher
  Wert klein: Der Satz schließt nur eine Beweissprache aus, er bringt die Vermutung nicht näher.
- **Fertig hieße:** `lake --wfail build CatchUp` grün mit dem neuen Modul; `scripts/check_axioms.py`
  grün (nur `propext`, `Classical.choice`, `Quot.sound`); `scripts/check_collection.py` grün; Eintrag
  in `results/catalog.json` und `results/modules.md`; Hinweis in CU-L039 (`results/legacy-findings.md`
  und `.json`), dass die Packungsschranke jetzt in Lean vorliegt; ein Prüfer bei uns hat 1 bis 3 nach
  Protokoll 5.1 bestätigt.

### Beitrag 2 (mittel): CU-L039 vollständig, mit dem Schema-Korollar

- **Inhalt:** Beitrag 1 plus eine präzise Lean-Fassung des zweiten Teils: Für k ≥ 2 gibt es keine k
  paarweise disjunkten Teilmengen von {2, 3, …} mit Summe k+2. Optional die Verbindung zur
  vorhandenen Summenblock-Schnittstelle `CatchUp/ExactSumResiduals.lean` und zum Träger F(m,k).
- **Aufwand:** mittel. Das reine Korollar ist einfach; die Verbindung zum Spiel verlangt, die im
  Notizbuch nur in Worten beschriebene Erzwingungs-Grammatik eng zu definieren.
- **Risiko:** Überdehnung. Das Projekt warnt ausdrücklich, dass eine Obstruktion „den Mechanismus
  nennen muss, den sie widerlegt, und die Vermutung, die sie nicht widerlegt“
  (`docs/research-handoff.md` Z. 163–164). Eine selbst erfundene Definition des Schemas könnte als
  Umdeutung gelesen werden; nach CONTRIBUTING sollten Änderungen an Definitionen vorher per Issue
  abgestimmt werden.
- **Fertig hieße:** wie Beitrag 1, dazu ein Satz, der nur das enge Schema ausschließt, mit Text in
  `results/failed-ideas.md`, der den Geltungsbereich nennt.

### Beitrag 3 (groß): sechstes oberes Ende, Q_N(N−5) nicht verlierend

- **Inhalt:** eigener neuer Beweis in der Reihe der Enden (bisher bis N−4). Nicht im Backlog des
  Projekts; dies ist mein Vorschlag.
- **Aufwand:** groß, mehrere Runden; das fünfte Ende hat rund 590 Zeilen Lean und eine
  Fallaufzählung aller zulässigen Zeugen.
- **Risiko:** hoch. Gerade CU-L038 und CU-L039 zeigen, dass die naheliegende Verallgemeinerung der
  bisherigen Methode auf längere obere Schwänze scheitert; es bräuchte eine neue Idee. Und der Nutzen
  ist begrenzt: Endlich viele Enden decken das Innere der Reihe nicht ab (Übergabe Z. 50–52).
- **Fertig hieße:** Satz `(pairDeletionPosition N 1 (N - 5)).value ≠ .loss` für alle N ab einer
  Schranke, im Bau und in der Axiomprüfung grün, mit Beweisführer-Text nach dem Vorbild von
  `results/fifth-endpoint.md`.

Den eigentlichen Engpass (Pflichten 2.2 bis 2.4) schlage ich nicht als Beitrag vor: Das ist offene
Forschung, an der das Projekt selbst seit Monaten mit großem Aufwand arbeitet.

## 5. Lean-Version und Regeln für einen Beitrag

### Technik

| Punkt | Wert | Fundstelle |
|---|---|---|
| Lean (Mathematik-Paket) | `leanprover/lean4:v4.27.0` | `lean-toolchain` |
| Mathlib | Tag `v4.27.0`, Commit `a3a10db0e9d66acbebf76c5e6a135066525ac900` | `lakefile.toml`, `lake-manifest.json`, `verification/README.md` |
| Lean (Kryptid-Paket, getrennt) | `v4.35.0-rc4`, Mathlib `1f41440…` | `cryptid/lean-toolchain`, `verification/README.md` |
| Optionen | `autoImplicit = false`; Bau mit `lake --wfail build` (Warnungen sind Fehler) | `lakefile.toml`, Übergabe Z. 148–149 |
| Modulsystem | **nicht** verwendet (klassisches `import`) | z. B. `CatchUp/LowerRayFifthEndpoint.lean` Z. 17 |
| Erlaubte Axiome | nur `propext`, `Classical.choice`, `Quot.sound`; geprüft für alle öffentlichen Sätze über `AxiomAudit.lean` und `AuditAll.lean`, mit Negativkontrolle gegen `sorryAx` | `scripts/check_axioms.py` Z. 5, 18–20 |
| Verboten | `sorry`, eigene Ergebnis-Axiome, nur-native Abkürzungen, Abhängigkeit von der offenen Vermutung | `CONTRIBUTING.md` Z. 7 |
| `decide +kernel` | in kleinen Fällen benutzt und zulässig (Kernauswertung, kein natives Kompilieren) | `results/lower-ray-endpoints.md` Z. 57–60 |
| CI | `.github/workflows/verify.yml` läuft bei push und pull_request: `check_collection.py`, kleine Rechenexperimente, Bau und Axiomprüfung beider Pakete | Workflow |
| Pflicht-Skripte vor Einreichung | `lake --wfail build CatchUp`, `scripts/check_axioms.py`, `scripts/check_collection.py` (dazu die Port-Skripte, falls berührt) | Übergabe Z. 147–157 |
| Katalogpflicht | jedes Modul unter `CatchUp/` braucht einen Eintrag in `results/catalog.json` mit `summary`, `evidence`, `group` und der genauen Liste `public_theorem_names` in Datei-Reihenfolge (nur `theorem`-Zeilen), und einen Link in `results/modules.md`; sonst schlägt `check_collection.py` fehl | `scripts/check_collection.py` Z. 24–33 |
| Kopfzeile | neue eigene Dateien: `Copyright 2026 The Catch-Up Research Authors.` plus Apache-2.0-Hinweis | z. B. `CatchUp/WholeTurn.lean` Z. 1–4 |

### Inhaltliche und redaktionelle Regeln (`CONTRIBUTING.md`, `CREDITS.md`, README)

- Aussage genau angeben: verbleibende Zahlen, Rückstand oder Anfangsintervall, aus wessen Sicht, alle
  Annahmen. Strategien müssen alle gegnerischen Antworten abdecken. Strategie, Einzelpartie und
  Spielwert unterscheiden.
- Bewiesenes, Experimente und Vermutungen getrennt halten. Rechnungen mit Befehlen, Ressourcen und
  erledigten Fällen; ein Zeitlimit ist kein Remis.
- Quellen und Mitwirkende nennen, **KI-Hilfe offenlegen** und sagen, was unabhängig geprüft wurde.
- Vor Neuheitsbehauptungen nach früheren Berichten suchen; das Projekt selbst macht keine
  Prioritätsansprüche.
- Größere Änderungen an Definitionen oder am Compiler erst per Issue abstimmen.
- Neue Module in Katalog und Themenführer eintragen, `check_collection.py` laufen lassen.
- Künftige Ports: Verträge erhalten, Importhülle prüfen, streng bauen, Platzhalter, Zusatzannahmen,
  native Vertrauensannahmen und Zirkelschlüsse auf die Vermutung prüfen (Übergabe Z. 159–164).
- Nennung: README und `CITATION.cff` bitten Beitragende, **ihren Namen** in die Zitation
  aufzunehmen. Das wäre Justus als Mensch; KI-Anteile gehören in die Offenlegung.
- Lizenz Apache 2.0; bestehende Hinweise bleiben erhalten.

### Reibung mit unserem eigenen Protokoll (Entscheidung bei Justus)

1. **Version:** Unser Lean-Projekt unter `ziele/catch-up/lean/` folgt formal-conjectures (v4.33.1).
   Ein Beitrag dort muss auf v4.27.0 / Mathlib `a3a10db` gebaut werden; das ist ein eigenes, zweites
   Lake-Projekt.
2. **Modulsystem:** Protokoll 10 verlangt für jede `.lean`-Datei in unserem Repo das Modulsystem
   (wegen Palomar). Der Beitrag dort darf es nicht nutzen, sonst passt er nicht zu den übrigen
   117 Modulen. Eine solche Datei in unserem Repo verstieße gegen Protokoll 10 und CLAUDE.md
   Punkt 15. Möglicher Ausweg: Arbeit in einem getrennten Fork, nicht in diesem Repo. Das entscheidet
   Justus.
3. **Nach außen:** Ein Beitrag ist ein Pull Request in ein fremdes Repo; das ist nach Protokoll 9
   und CLAUDE.md Punkt 9 erst nach Entscheidung von Justus zulässig. Ob der PR-Text, wie bei
   formal-conjectures, von Justus selbst stammen muss, regelt das Protokoll für dieses Repo nicht.
4. **Abbruchregel 3** ist für dieses Ziel laut Justus ausgesetzt; Palomar spielt für einen Beitrag
   dort keine Rolle.

## Abschluss

**Ergebnis:** Landkarte erstellt, Positivkontrolle bestanden. Die Vermutung ist bei catch-up-research
nach unserem Stand vom 26.11.2026 offen; die Aufgabe CU-L039 (Packungsschranke) ist offen, klein und
ohne Spielregeln formalisierbar und damit der naheliegende erste Beitrag. Ein Beitrag muss auf
Lean v4.27.0 mit Mathlib `a3a10db` ohne Modulsystem gebaut werden und drei Prüfskripte bestehen.

**Belege:** Klon `/home/user/cur` auf `b0853b4e71d240ed539855cbaf91da7855a4685f`; `git ls-remote` am
26.11.2026 bestätigt denselben `HEAD`; alle Fundstellen oben mit Datei und Zeile. Keine Rechenläufe.

**Abweichungen und eigene Fehler:** `git log` im Klon verweigert die Umgebung; Commit aus
`.git/refs/heads/main` gelesen, Datum (27.10.2026) aus dem Auftrag übernommen. Nichts gebaut; „in Lean
geprüft“ beruht auf den Angaben des Repos und seinem CI, nicht auf eigener Prüfung. Der
Mathematik-Teil von CU-L039 ist von mir nur nachgelesen (Herleitung). Aufwandsschätzungen unbelegt.

**Offene Punkte:** GitHub-Issues und offene PRs dort (Justus im Browser; `refs/pull/5/merge` deutet
auf eine noch offene PR #5 des Betreibers hin, ohne Bezug zu CU-L039). Konflikt mit Protokoll 10
(Modulsystem, Lean-Ort) vor jedem Lean-Beitrag klären.

**Empfehlung:** weiter, mit Beitrag 1 (CU-L039-Packungslemma), sofern Justus die Protokollfragen in
Abschnitt 5 entscheidet.
