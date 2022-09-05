#!/bin/sh
# AOJからテストケースをDLする

if [ $# -ne 3 ]; then
  echo "Usage: ./download.sh CASE START END"
  echo "Example: ./download.sh GRL_5_C 1 32"
  exit 1
fi

CASE=$1
START=$2
END=$3

mkdir -p in out
# ダウンロード
curl -o "./in/#1" https://judgedat.u-aizu.ac.jp/testcases/$CASE/[$START-$END]/in \
     -o "./out/#1" https://judgedat.u-aizu.ac.jp/testcases/$CASE/[$START-$END]/out
