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
#include <cassert> // assert();
#include <iomanip> // cout << setprecision(15);
// #include <bits/stdc++.h>
#ifndef M_PI
	#define M_PI		3.14159265358979323846
#endif
#ifndef M_E
	#define M_E		2.7182818284590452354
#endif
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define RREP(i, n)  for(int i = (n) - 1; i >= 0; --i)
#define EACH(e, v) for(auto &e : v)
#define ITR(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
#define RITR(it, v) for(auto it = (v).rbegin(); it != (v).rend(); ++it)
#define CASE(x) break; case x:
#define ALL(v)  (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) int((v).size())
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define SUM(v, type) accumulate((v).begin(), (v).end(), (type) 0)
#define MIN(v) (*min_element((v).begin(), (v).end()))
#define MAX(v) (*max_element((v).begin(), (v).end()))
#define ARGMIN(v) (min_element((v).begin(), (v).end()) - (v).begin())
#define ARGMAX(v) (max_element((v).begin(), (v).end()) - (v).begin())
#define REVERSE(v) reverse((v).begin(), (v).end())
#define ARANGE(v) iota((v).begin(), (v).end(), 0)
#define FILTER(src, tgt, func) copy_if(begin(src), end(src), back_inserter(tgt), func); // func = [](type x){return 条件;}
#define CTOI(c) (c - '0')
#define HEADSTR(str, n) str.substr(0, (n))
#define TAILSTR(str, n) str.substr((str).length() - (n))
#define CONTAINS(str, c) ((str).find(c) != string::npos)
#define INSPOS(v, a) (lower_bound((v).begin(), (v).end(), a) - (v).begin())
// io系
#define OUT(x) cout << (x) << endl;
#define IN(x) cin >> x;
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

template<class T> vector<size_t> argsort(const vector<T> &vec, bool asc=true){
	vector<size_t> index(vec.size());
	iota(index.begin(), index.end(), 0);
	sort(index.begin(), index.end(), [&vec, &asc](size_t i, size_t j){return asc ? (vec[i] < vec[j]):(vec[i] > vec[j]);});
	return index;
}
// 表示系
template <class Head> void print(Head&& head) {
	cout << head << endl;
}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	os << "[ ";
	for ( const T& item : vec ) os << item << ", ";
	os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
	os << "{ ";
	for ( const T& item : s ) os << item << ", ";
	os << "}";
	return os;
}
template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& m) {
	os << "{ ";
	for ( const auto &[key, value] : m ) os << key << ":"<< value << ", ";
	os << "}";
	return os;
}
// 入力系
template<class T1, class T2> istream& operator>>(istream& is, pair<T1, T2>& p) {
	is >> p.first >> p.second;
	return is;
}
template<class T> istream& operator>>(istream& is, vector<T>& vec) {
	for ( T& item : vec ) is >> item;
	return is;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

// --------------------ここから--------------------

// a^n % mod
int pow_mod(int a, int n, int mod){
	int ans = 1;
	while (n > 0) {
		if ((n & 1))
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

// nCr
int combi(int n, int r){
	r = (r > n / 2) ? n - r : r;

	int ans = 1;
	for (int i = 1; i <= r; i++, n--) {
		ans *= n;
		ans /= i;
	}
	return ans;
}

// nCr % mod ただし modは素数
int combi_mod(int n, int r, int mod){
	int ans=1, div=1;
	for (int i = n; i > n-r; --i)
		ans = (ans*(i%mod))%mod;
	for (int i = 1; i < r+1; ++i)
		div = (div*(i%mod))%mod;
	int inv_div = pow_mod(div, mod-2, mod); // 整数の逆元
	return (ans * inv_div) % mod;
}

// 素因数分解
VI pfact(int x){
	VI ans;
	for (int i=2; i*i<=x; ++i){
		while(x%i==0){
			x/=i;
			ans.push_back(i);
		}
	}
	if (x!=1)
		ans.push_back(x);
	return ans;
}

// ダイクストラ：始点sからその他頂点への最短距離を返す
VI dijkstra(const vector< vector<PII> > &adj, int n, int s){ // (隣接, ノード数, 始点)
	VI dist(n, INT_MAX);
	priority_queue< PII, vector<PII>, greater<PII> > pq;
	pq.push({0, s}); // (コスト, ノード)
	dist[s] = 0;
	vector<bool> seen(n, false);
	while (!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		seen[v] = true;
		for (auto [to, cost] : adj[v]){ // ノード v に隣接しているノードに対して
			if (!seen[to] && dist[v] + cost < dist[to]){
				dist[to] = dist[v] + cost;
				pq.push({dist[to], to});
			}
		}
	}
	return dist;
}

// 幅優先で訪問したノードの順番を返す
VI bfs(const vector< vector<PII> > &adj, int n, int s){ // (隣接, ノード数, 始点)
	queue<int> que;
	que.push(s);
	vector<bool> seen(n, false);

	VI visit;
	while (!que.empty()){
		int v = que.front();
		que.pop();
		if (!seen[v])
			visit.push_back(v);
		seen[v] = true;
		for (auto [to, cost] : adj[v]){ // ノード v に隣接しているノードに対して
			if (!seen[to])
				que.push(to);
		}
	}
	return visit;
}

// 深さ優先で訪問したノードの順番を返す
VI dfs(const vector< vector<PII> > &adj, int n, int s){  // (隣接, ノード数, 始点)
	stack<int> st;
	st.push(s);
	vector<bool> seen(n, false);

	VI visit;
	while (!st.empty()) {
		int v = st.top();
		st.pop();
		if (!seen[v])
			visit.push_back(v);
		seen[v] = true;
		for (auto [to, cost] : adj[v]){ // ノード v に隣接しているノードに対して
			if (!seen[to])
				st.push(to);
		}
	}

	return visit;
}

// 深さ優先（再帰）で訪問したノードの順番を返す
void _dfs_recursive(const vector< vector<PII> > &adj, int n, int s, vector<bool> &seen, VI &visit){
	if (!seen[s])
		visit.push_back(s);
	seen[s] = true;
	for (auto [to, cost] : adj[s]){
		if (!seen[to])
			_dfs_recursive(adj, n, to, seen, visit);
	}
}
VI dfs_recursive(const vector< vector<PII> > &adj, int n, int s){
	vector<bool> seen(n, false);
	VI visit;
	_dfs_recursive(adj, n, s, seen, visit);
	return visit;
}

// 深さ優先で抜けるときにpushする
void _sccd(const VVI &adj, int s, vector<bool> &seen, VI &visit){
	seen[s] = true;
	EACH(to, adj[s])
		if (!seen[to])
			_sccd(adj, to, seen, visit);
	visit.push_back(s);
}
// Strongly Connected Component Decomposition (強連結成分分解)
VVI sccd(const VVI &adj, int n){
	// 1. DFSで順序付け
	vector<bool> seen(n, false);
	VI visit;
	REP(s, n){
		if (!seen[s])
			_sccd(adj, s, seen, visit);
	}
	// 2. DFSの順番に反転させたグラフをたどる
	VVI adj_rev(n);
	REP(i, n)EACH(j, adj[i])
		adj_rev[j].push_back(i);
	seen = vector<bool>(n, false);
	VVI connected;
	RITR(it, visit){
		if (seen[*it])
			continue;
		VI component;
		_sccd(adj_rev, *it, seen, component);
		connected.push_back(component);
	}
	return connected;
}

class UnionFind {
private:
	int n;
	VI parent; //親のノード情報、自身が親の場合はその集合のサイズを負で持つ
	
public:
	UnionFind(int n) : n(n), parent(n, -1){} // -1で初期化
	// データxが属する木の根
	int root(int x) {
		if (parent[x] < 0) return x;
		return parent[x]=root(parent[x]);
	}
	// xとyの木を併合
	void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
		if (parent[x] > parent[y])
			swap(x, y);
		parent[x] += parent[y]; // 個数更新
		parent[y] = x; // 根の付け変え
	}
	// 同じ木に属するかどうか
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	// xの集合のサイズ
	int size(int x) {
		return -parent[root(x)];
	}
	// xの属するメンバー
	VI members(int x) {
		int r = root(x);
		VI mem;
		REP(i, n)
			if (root(i) == r)
				mem.push_back(i);
		return mem;
	}
	// 根たち
	VI root_members() {
		VI mem;
		REP(i, n)
			if (parent[i] < 0)
				mem.push_back(i);
		return mem;
	}
	// 木の数
	int group_count() {
		return SZ(root_members());
	}
	// 根に対するすべてのメンバー
	map<int, VI> all_group_members() {
		map<int, VI> group_members;
		REP(member, n)
			group_members[root(member)].push_back(member);
		return group_members;
	}
	// 表示用
	friend ostream& operator<<(ostream& os, UnionFind& uf){
		EACH(p, uf.all_group_members())
			os << p.first << ": " << p.second << endl;
		return os;
	}
};

int main() {
	// 数学
	dump(combi(4, 2))
	dump(combi_mod(4, 2, 5))
	dump(pow_mod(5, 5, 100))
	dump(pfact(100))
	// グラフ
	istringstream iss1(
		"4 5 0\n" // 頂点数 辺の数 開始ノード
		"0 1 1\n" // s t c
		"0 2 4\n"
		"1 2 2\n"
		"2 3 1\n"
		"1 3 5\n"
	);
	int n1, m1, start;
	iss1 >> n1 >> m1 >> start;
	vector< vector<PII> > adj1(n1);
	REP(_, m1){
		int s, t, cost;
		iss1 >> s >> t >> cost;
		adj1[s].push_back({t, cost});
	}
	dump(adj1)
	dump(dijkstra(adj1, n1, start))
	dump(bfs(adj1, n1, start))
	dump(dfs(adj1, n1, start))
	dump(dfs_recursive(adj1, n1, start))
	istringstream iss2(
		"9 11 \n" // 頂点数 辺の数
		"0 1 \n" // s t
		"1 6 \n"
		"6 0 \n"
		"3 1 \n"
		"3 5 \n"
		"5 8 \n"
		"8 4 \n"
		"4 3 \n"
		"5 7 \n"
		"7 2 \n"
		"2 7 \n"
	);
	int n2, m2;
	iss2 >> n2 >> m2;
	VVI adj2(n2);
	REP(_, m2){
		int s, t;
		iss2 >> s >> t;
		adj2[s].push_back(t);
	}
	dump(adj2)
	dump(sccd(adj2, n2));
	// UnionFind
	UnionFind uf(5);
	uf.merge(1,2);
	uf.merge(0,4);
	OUT("UnionFind")
	OUT(uf)
	return 0;
}
