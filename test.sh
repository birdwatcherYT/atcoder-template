#!/bin/sh
# テストする

if [ $# -ne 3 ]; then
  echo "Usage: ./test.sh EXE START END"
  echo "Example: ./test.sh ./template.exe 1 32"
  exit 1
fi

EXE=$1
START=$2
END=$3

# 並列数
PROCESS=4

# テスト
mkdir -p test judge
seq $START $END | xargs -L 1 -P $PROCESS -I{} sh -c "echo {}; $EXE < ./in/{} > ./test/{}; diff -b ./out/{} ./test/{} > ./judge/{}"

echo ----------
cat ./judge/*
