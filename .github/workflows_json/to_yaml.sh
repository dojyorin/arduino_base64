#!/bin/sh
set -eu

cd ${0%/*}

yq -P -I 4 ./${1}.json | head -c -1 > ../workflows/${1}.yaml