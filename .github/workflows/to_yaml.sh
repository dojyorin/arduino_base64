#!/bin/sh
set -eu

cd ${0%/*}

for _v in $(find ./ -type f -name '*.json'); do
    yq -o y -I 4 ${_v} | head -c -1 > ${_v%.*}.yaml
done; unset _v