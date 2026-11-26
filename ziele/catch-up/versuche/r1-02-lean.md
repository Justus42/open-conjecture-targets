# catch-up R1-02: Lean-Projekt und Aussage (Zwischenstand, Runde angehalten)

Stand 26.11.2026. Auftrag auf Anweisung des Koordinators vorzeitig beendet (Abbruchregel 3 berührt).
**Das Projekt ist noch nicht gebaut. Positiv- und Negativkontrolle sind nicht gelaufen.**

## Ergebnis

Projekt `ziele/catch-up/lean/` angelegt (Lean v4.35.0, Mathlib-Tag v4.35.0), Aussage wörtlich aus
formal-conjectures übernommen, zwei Änderungen. Abgleich mit dem Paper: keine Regelabweichung
gefunden, eine harmlose Erweiterung (N = 0). Bau und Kontrollen offen.

## Aufbau und Bau

```
ziele/catch-up/lean/
  lean-toolchain        leanprover/lean4:v4.35.0
  lakefile.toml         Mathlib per git-URL, rev v4.35.0; Bibliothek CatchUp, globs CatchUp.+
  lake-manifest.json    Mathlib 56a005855ea17e0b0958f73ec801ae140b0a1679 (= Tag v4.35.0)
  CatchUp/Challenge.lean
  ci/                   (leer, Workflow-Vorschlag nicht geschrieben)
```

Baubefehl (ungeprüft, weil nicht zu Ende gelaufen):

```
cd ziele/catch-up/lean
lake exe cache get
lake build
```

Für R1-05: eine neue Datei `CatchUp/<Name>.lean` (mit `module`-Kopf) wird durch `globs = ["CatchUp.+"]`
automatisch mitgebaut; Import der Aussage mit `public import CatchUp.Challenge`.

## Lean-Version: v4.35.0, Begründung

- `toolchains.json` in PalomarSubmission (main = 046554302064b2c83c2b924bea6db87fc5900c68):
  `{"schema_version": 2, "minimum": "v4.35.0-rc2"}`. Laut README gibt es keine Liste mehr, jede
  Release- oder RC-Version ab dem Minimum wird angenommen.
- v4.35.0 ist stabil, steht in `checker-revisions.json` (con-ron-Zuordnung, nur 4.35.0-rc2 bis
  4.35.0) und in der Liste der Verso-Backports fürs Rendern (4.35.0-rc4, 4.35.0, 4.36.0-rc1).
  v4.36.0 existiert, fehlt aber in `checker-revisions.json`.
- Palomar verlangt, dass die Projekt-Toolchain exakt der der Mathlib-Revision entspricht
  (PalomarPolicy main = 5bd35cddcfc940532bb5f55e399d68b49b0986a5, `CONTRIBUTING.md` Abschnitt 2.1).
  Daher Mathlib-Tag v4.35.0. Ob dessen `lean-toolchain` exakt v4.35.0 ist: noch nicht nachgesehen.
- Installiertes `lean --version`: 4.35.0, Commit eb6cafb7290e8bd5f2937522d8d804f58f02bafc = Tag v4.35.0.

## Antworten zu Protokoll Abschnitt 10 (Fundstellen oben)

1. **Versionen:** alles ab v4.35.0-rc2 (`toolchains.json`, PalomarSubmission 0465543). Das bestätigt
   „mindestens 4.35“ aus PR #7992.
2. **Modulsystem:** verlangt, für jede `.lean`-Datei im Repo, je höchstens 10.000 Zeilen
   (PalomarSubmission README „Lean source requirements“; PalomarPolicy `CONTRIBUTING.md`).
3. **formal-conjectures importieren:** nein für die Challenge. Erlaubt sind in ihrer transitiven
   Importhülle nur Lean-Kern, Mathlib, Tau Ceti, CSLib (PalomarPolicy `CONTRIBUTING.md` 2.4: „No other
   project-specific source may occur … Previous registration by Palomar does not make a repository an
   approved Challenge dependency“). Die Solution darf beliebige öffentliche GitHub-Repos nutzen.

## formal-conjectures: maßgeblicher Commit

Datei `FormalConjectures/Paper/CatchUpConjecture.lean` bei HEAD
5bd8bfb9def462c19a87d2d275af3db3341dc727 (lokal `/home/user/fc`) und bei 9097e2f (von
raw.githubusercontent geladen) byte-gleich, sha256-Präfix 53b9153986d279c1 in allen drei Fassungen.
Maßgeblich: 5bd8bfb9def462c19a87d2d275af3db3341dc727. Den vollen Hash von 9097e2f konnte ich nicht
auflösen (git auf `/home/user/fc` war in meiner Sitzung gesperrt, GitHub-API ohne Zugriff).
formal-conjectures selbst steht auf v4.33.1.

## Änderungen gegenüber dem Original

1. `public import FormalConjecturesUtil` → `public import Mathlib`. Grund: Challenge darf
   formal-conjectures nicht importieren. `FormalConjecturesUtil` importiert selbst `Mathlib`,
   dazu `FormalConjecturesForMathlib` und Linter. Offen: ob `FormalConjecturesForMathlib` etwas
   enthält, das die Elaboration der Aussage ändert (nicht geprüft, halte ich für unwahrscheinlich).
2. Attribut `@[category research open, AMS 11 91]` entfernt. Grund: in formal-conjectures definiert;
   ohne Wirkung auf die Aussage.
3. Zusätzlicher Kommentarblock vor `module` mit Herkunft und Änderungen (Apache-2.0 verlangt
   Kennzeichnung von Änderungen; Lizenzkopf bleibt).
4. Lean v4.33.1 → v4.35.0, Mathlib v4.33.1 → v4.35.0. Ob die Aussage dort unverändert elaboriert,
   zeigt erst der Bau (offen).

Sonst unverändert, einschließlich `@[expose] public section`, Namensraum `CatchUp`, Docstrings.

## Abgleich mit dem Paper (Volltext, sha256 cbf8fdd7…, Regeln S. 38, Abschnitte 2.5, 2.6, 3.1)

| Paper | Lean | Urteil |
|---|---|---|
| Regel 1: P1 entfernt eine Zahl | `isFirstMove`: genau ein Zug, dann Wechsel | gleich |
| Regel 2: eine oder mehr Zahlen, bis eigener Stand ≥ Gegner | weiterziehen solange `s_me' < s_opp`, sonst Wechsel | gleich; bei Gleichstand zu Zugbeginn genau eine Zahl, wie im Paper („start their turns either tied or behind“) |
| Regel 3: geht das nicht mehr, bekommt der Ziehende den Rest; höhere Summe gewinnt | `s_me + sum < s_opp → loss`; Gleichheit bleibt spielbar | gleich (Rest nehmen lässt ihn strikt zurück) |
| Spielende bei leerer Menge, höhere Summe gewinnt, sonst Remis | Vergleich bei `remaining = ∅` | gleich |
| bestes Spiel | `Outcome.best` = Maximum win > draw > loss, Perspektivwechsel per `neg` | gleich |
| Vermutung: N = 4n+3 oder 4n+4, n ≥ 0 | alle N mit `Even (N*(N+1)/2)` | **Erweiterung um N = 0**: `value ∅ = draw` trivial wahr; keine echte Abweichung |
| Paper spielt mit Multimengen | `Finset ℕ` | für {1,…,N} ohne Belang |

Eigene Überlegung (nicht formal geprüft): Die Abschneide-Regel greift mitten im Zug nie, denn wer
mit Rückstand d und Restsumme ≥ d eine Zahl x < d nimmt, hat Rückstand d − x und Restsumme ≥ d − x.
`Outcome.best []` = loss wird nie erreicht, weil die Liste nur bei nichtleerer Menge gebildet wird.

## Abweichungen und eigene Fehler

- Gesperrte Hosts (Proxy 403): `release.lean-lang.org` (von elan 4.4.0 benutzt; `releases.lean-lang.org`
  ist frei), `reservoir.lean-lang.org` (Lake-Paketsuche), `lean-lang.org`.
- Umgehung, offen gelegt: Toolchain als offizielles Release-Zip von
  `github.com/leanprover/lean4/releases/download/v4.35.0/lean-4.35.0-linux.zip` geladen
  (sha256 c8531faaa4a93d5a4dae0c742cbc1bd42a2993594d02f93a9d629ebf299fb2c8, keine offizielle
  Prüfsumme zum Vergleich) und von Hand nach `~/.elan/toolchains/leanprover--lean4---v4.35.0` entpackt.
  Mathlib per `git = "https://github.com/leanprover-community/mathlib4"` statt `scope` (Reservoir
  gesperrt). Justus soll entscheiden, ob das zulässig war.
- Der Mathlib-Cache lädt von `cache.mathlib.org` (lief beim Anhalten noch).
- Der Scratchpad-Ordner wird mit anderen Subagenten geteilt; meine Dateien liegen in `r102/`.

## Offene Punkte

1. `lake exe cache get` und `lake build` zu Ende laufen lassen; Positivkontrolle (`Nat.add_comm`) und
   Negativkontrolle (`example : 1 = 2 := rfl` scheitert, `sorry` wird gemeldet) — nicht gemacht.
2. Prüfen, dass Mathlib v4.35.0 exakt `leanprover/lean4:v4.35.0` als Toolchain hat.
3. Workflow-Vorschlag unter `ci/` (nur `workflow_dispatch`) und Anleitung für Justus — nicht gemacht.
4. Einfluss von `FormalConjecturesForMathlib` auf die Elaboration prüfen.
5. Voller Hash von 9097e2f.

## Empfehlung

Weiter: Punkte 1 bis 3 sind ein kurzer Folgeauftrag auf diesem Zweig. Kein Befund, der zum Abbruch
des Ziels rät.
