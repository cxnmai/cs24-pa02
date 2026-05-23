#!/bin/sh

set -e

make >/dev/null

for input_file in \
  input_20_random.csv \
  input_100_random.csv \
  input_1000_random.csv \
  input_76920_random.csv
do
  start_time=$(date +%s%N)
  ./runMovies "$input_file" prefix_large.txt >/dev/null
  end_time=$(date +%s%N)
  elapsed_ms=$(( (end_time - start_time) / 1000000 ))
  printf "%s: %s ms\n" "$input_file" "$elapsed_ms"
done
