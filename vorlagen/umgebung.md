# Vorlage: Cloud-Umgebung „Mathe-Lean“

Eine gemeinsame Umgebung für alle drei Ziele. Stand 26.11.2026. Das Skript ist **ungetestet**; der
erste Auftrag R1-02 meldet, was davon funktioniert hat und welche Domains wirklich fehlten.

## Warum eine eigene Umgebung

In den Cloud-Sitzungen von `matmul-rank-n2m` waren zwei Adressen gesperrt, die Lean braucht
(`lean/NACHBAU.md` dort, Punkte 1 und 2): die Lean-Versionen (`releases.lean-lang.org`) und der
fertige Mathlib-Bau (`lakecache.blob.core.windows.net`). Mathlib musste deshalb aus den Quellen
gebaut werden. Mit den Freigaben unten entfällt das.

## Freizugebende Domains

| Domain | Wofür | Beleg |
|---|---|---|
| `releases.lean-lang.org` | Lean-Versionen für `elan` | in matmul gesperrt (Proxy 403) |
| `lakecache.blob.core.windows.net` | fertiger Mathlib-Bau (`lake exe cache get`) | in matmul gesperrt (Proxy 403) |
| `raw.githubusercontent.com` | Installationsskript von `elan` | Annahme, evtl. schon frei |
| `objects.githubusercontent.com`, `release-assets.githubusercontent.com` | Dateien aus GitHub-Releases (Ersatzweg für Lean, GAP) | in bb6 war „github.com per Web (Releases)“ gesperrt |
| `arxiv.org`, `export.arxiv.org` | Literatur | in der Umgebung „Mathe“ schon frei |
| `leanprover-community.github.io` | Zulip-Archiv (677 → 255), Mathlib-Dokumentation | gebraucht für `ziele/677-255` |
| `teorth.github.io` | Blueprint des Gleichungsprojekts | gebraucht für `ziele/677-255` |
| `palomar-registry.org`, `data.palomar-registry.org` | Register lesen (Stand-Wache) | im Scouting per Shell gesperrt (403) |
| `mpra.ub.uni-muenchen.de` | Quelle zu Catch-Up | gebraucht für `ziele/catch-up` |
| `archive.ubuntu.com`, `security.ubuntu.com` | `apt` für GAP und SAT-Löser | Annahme, evtl. schon frei |

Neuere Mathlib-Fassungen können ihren fertigen Bau von einer anderen Adresse laden. R1-02 nennt den
Hostnamen, falls `lake exe cache get` scheitert.

Nicht freigeben: `submit.palomar-registry.org`. Einreichungen macht keine Sitzung von sich aus.

## Setup-Skript

```bash
#!/bin/bash
# Umgebung "Mathe-Lean": läuft einmal beim Bau der Umgebung. Fehler brechen nicht ab, sie werden gemeldet.
set -u
export DEBIAN_FRONTEND=noninteractive

# 1. Lean: elan ohne Standard-Version. Die Version legt jedes Projekt über seine lean-toolchain fest.
curl -sSfL https://raw.githubusercontent.com/leanprover/elan/master/elan-init.sh \
  | sh -s -- -y --default-toolchain none || echo "SETUP: elan fehlgeschlagen"
grep -q '.elan/bin' "$HOME/.bashrc" 2>/dev/null || echo 'export PATH="$HOME/.elan/bin:$PATH"' >> "$HOME/.bashrc"

# 2. Rechenwerkzeuge in Python (SAT, SMT, ganzzahlige Programme)
pip install --quiet python-sat z3-solver ortools sympy networkx \
  || pip install --quiet --break-system-packages python-sat z3-solver ortools sympy networkx \
  || echo "SETUP: pip fehlgeschlagen"

# 3. GAP (Gruppentheorie, für kourovka-20-51) und SAT-Löser
(apt-get update -qq && apt-get install -y -qq gap cadical kissat) || echo "SETUP: apt fehlgeschlagen"

echo "SETUP: fertig"
```

Die Paketnamen bei `apt` sind nicht nachgeprüft. Fehlt in GAP die Bibliothek der kleinen Gruppen,
meldet das der Auftrag R1-04 von `kourovka-20-51`.
