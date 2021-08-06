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

bool can_go(const VI &current, const VI &dist){
    int t=dist[0]-current[0];
    int x=dist[1]-current[1];
    int y=dist[2]-current[2];
 
    t -= abs(x)+abs(y);
    if (t<0)
        return false;
    // tステップで(0,0)へ移動できるか
    if (t%2==1)
        return false;
    return true;
}

// int -> str: to_string
// str -> int: stoi
int main() {
	int n;
	IN(n)
	VVI points(n, VI(3));
	EACH(txy, points){
		IN(txy)
	}
	VI current{0,0,0};
	bool flag=true;
	EACH(p, points){
		if (!can_go(current, p)){
			flag=false;
			break;
		}
		current=p;
	}
	OUT(flag ? "Yes" : "No")
	return 0;
}
