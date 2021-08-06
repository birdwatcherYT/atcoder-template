#pragma GCC optimize("O3")

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
#define CTOI(c) (c - '0')
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

// int -> str: to_string
// str -> int: stoi
int main() {
	int n,y;
	IN(n)IN(y)

	REP(i, n+1)
		REP(j, n+1-i){
			int k=n-i-j;
			if (i*10000+j*5000+k*1000==y){
				assert(i+j+k==n);
				cout<<i<<" "<<j<<" "<<k<<endl;
				return 0;
			}
		}
	OUT("-1 -1 -1")
	return 0;
}
