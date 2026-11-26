#!/usr/bin/env bash
# Reproduce R1-03: build, table N=1..20, positive control against the paper,
# negative control (deliberately wrong rule must be caught by compare.py).
# Usage: bash run.sh [BUILD_DIR]   (default: ./build, ignored by git via .gitignore)
set -euo pipefail
HERE="$(cd "$(dirname "$0")" && pwd)"
OUT="${1:-$HERE/build}"
mkdir -p "$OUT"
g++ -O2 -std=c++17 -Wall -o "$OUT/catchup" "$HERE/catchup.cpp"
g++ -O2 -std=c++17 -Wall -DMIN_LAST -o "$OUT/catchup_minlast" "$HERE/catchup.cpp"

echo "== table N=1..20 =="
start=$(date +%s.%N)
"$OUT/catchup" 1 20 | tee "$HERE/table.tsv"
end=$(date +%s.%N)
echo "wall seconds: $(python3 -c "print(round($end - $start, 2))")"

echo "== positive control (compare with paper) =="
python3 "$HERE/compare.py" "$OUT/catchup" 10 | tee "$HERE/compare.txt"

echo "== negative control (MIN_LAST build must FAIL) =="
if python3 "$HERE/compare.py" "$OUT/catchup_minlast" 10 > "$HERE/negative_control.txt"; then
  echo "NEGATIVE CONTROL DID NOT FIRE"; exit 1
else
  grep -c '^FAIL' "$HERE/negative_control.txt" | sed 's/^/negative control: FAIL lines = /'
fi
