# atcoder-template
atcoderのABC用C++テンプレ

## 使い方
- `template.cpp`を問題 (A,B,C, ...)ごとにコピーして使う
    - ファイル名にスペースを含まないようにする
- `make`でディレクトリ内のすべてのcppファイルをそれぞれコンパイル

## 機能
### `vector<T>`の`ostream`/`istream`に対して演算子`<<`/`>>`を定義
```c++
vector<int> vec(3);
cin >> vec;
cout << vec;
```
>10 20 30 (入力)<br>
>[ 10 20 30 ]

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
