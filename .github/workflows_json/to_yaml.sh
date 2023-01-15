set -uC
cd ${0%/*}

yq -P -I 4 ./${1}.json | head -c -1 | tee ../workflows/${1}.yaml &> /dev/null