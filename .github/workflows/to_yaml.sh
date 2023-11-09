#!/bin/sh
set -eu

cd ${0%/*}

for _v in $(find ./ -maxdepth 1 -type f -name '*.json'); do
    yq -I 4 -o y ${_v} | head -c -1 > ${_v%.*}.yaml
done; unset _v