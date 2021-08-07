# atcoder-template
atcoderのABC用C++テンプレ

## 使い方
- `template.cpp`を問題 (A,B,C, ...)ごとにコピーして使う
    - ファイル名にスペースを含まないようにする
- `make`でディレクトリ内のすべてのcppファイルをそれぞれコンパイル
- `tools.cpp`必要に応じてコピペして使える関数を実装
    - a^n mod m
    - nCr
    - nCr mod m
    - ダイクストラ（by 優先度付きキュー）
    - 幅優先（by キュー）
    - 深さ優先（by スタック）
    - 深さ優先（by 再帰）
    - UnionFind
- コンパイル後に自動的に実行するようにするにはMakefileの`# ./$@`のコメントアウトを外す

`./AtCoderBeginnersSelection/`に[AtCoder Beginners Selection](https://atcoder.jp/contests/abs/tasks)を解く例を掲載


## 機能
### `vector<T>`の`ostream`/`istream`に対して演算子`<<`/`>>`を定義
```c++
vector<int> vec(3);
cin >> vec;
cout << vec;
```
>10 20 30 (入力)<br>
>[ 10, 20, 30, ]

### `pair<T1, T2>`の`ostream`/`istream`に対して演算子`<<`/`>>`を定義
```c++
pair<int, int> p;
cin >> p;
cout << p;
```
>1 2 (入力)<br>
>(1, 2)

### `set<T>`/`map<T1, T2>`の`ostream`に対して演算子`<<`を定義
```c++
set<int> s{1,2,3};
cout << s;
```
>{ 1, 2, 3, }
```c++
map<int, int> m{{1,2},{3,4}};
cout << m;
```
>{ 1:2, 3:4, }

### スペースで区切って与えられた引数を表示する関数を定義
```c++
print(1,2,3,4,5);
```
>1 2 3 4 5

### その他表記が簡単になるマクロを定義
```c++
REP(i, 3)
    OUT(i)
```
>0<br>
>1<br>
>2<br>

詳しくは[template.cpp](./template.cpp)を参照。

### 最適化オプションで`-O3`に相当するものを使用
```c++
#pragma GCC optimize("O3")
```
使えないコンパイラでは無視される

## デバッグ用に標準入力を簡単に文字列ストリームに切り替えれるコードを用意
```c++
istringstream debug_iss(R"(
デバッグ時はここに入力を貼り付けて下記マクロのコメントアウトを外す
)");
// #define cin debug_iss
```

## [ac-library](https://atcoder.github.io/ac-library/document_ja/index.html)を使う場合
1. [ac-library](https://github.com/atcoder/ac-library/releases)をダウンロードしてくる
2. zipを展開して`ac-library`をcppと同じ階層に置く
3. `Makefile`の以下のコメントアウトを外す
```makefile
# INCLUDE  = -I ac-library
```
4. includeして使う
```c++
#include <atcoder/all>
```
