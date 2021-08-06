#pragma GCC optimize("O3")

// #include <atcoder/all>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <cassert>
// #include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define RREP(i, n)  for(int i = (n) - 1; i >= 0; --i)
#define EACH(e, v) for(auto &e : v)
#define CASE(x) break; case x:
#define ALL(v)  (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) int((v).size())
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define SUM(v, type) accumulate((v).begin(), (v).end(), (type) 0)
#define CTOI(c) (c - '0')
#define HEADSTR(str, n) str.substr(0, (n))
#define TAILSTR(str, n) str.substr((str).length() - (n))
#define INSPOS(v, a) (lower_bound((vec).begin(), (vec).end(), a) - (vec).begin())

// io系
#define OUT(x) cout << (x) << endl;
#define IN(x) cin >> x;
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
	is >> p.first >> p.second;
	return is;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
	os << "[ ";
	for ( const T& item : vec )
		os << item << ' ';
	os << "]";
	return os;
}

template<class T>
istream& operator>>(istream& is, vector<T>& vec) {
	for ( T& item : vec )
		is >> item;
	return is;
}

template <class Head>
void print(Head&& head) {
	cout << head << endl;
}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	// in
	int n;
	IN(n)
	VI nums(n);
	IN(nums)

	// out
	OUT(n)
	OUT(nums)

	print(1,2,3,4,5);
	return 0;
}
