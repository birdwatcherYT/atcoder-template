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

class UnionFind {
private:
	int n;
	VI parent; //親のノード情報、自身が親の場合はその集合のサイズを負で持つ
	
public:
	UnionFind(int n) : n(n), parent(n, -1){} // -1で初期化
	// データxが属する木の根
	int root(int x) const{
		if (parent[x] < 0) return x;
		return root(parent[x]);
	}
	// xとyの木を併合
	void merge(int x, int y) {
		if (same(x,y)) return;
		if (parent[x] > parent[y])
			swap(x, y);
		parent[x] += parent[y]; // 個数更新
		parent[y] = x; // 根の付け変え
	}
	// 同じ木に属するかどうか
	bool same(int x, int y) const{
		return root(x) == root(y);
	}
	// xの集合のサイズ
	int size(int x) const{
		return -parent[root(x)];
	}
	// xの属するメンバー
	VI members(int x) const{
		int r = root(x);
		VI mem;
		REP(i, n)
			if (root(i) == r)
				mem.push_back(i);
		return mem;
	}
	// 根たち
	VI root_members() const{
		VI mem;
		REP(i, n)
			if (parent[i] < 0)
				mem.push_back(i);
		return mem;
	}
	// 木の数
	int group_count() const{
		return SZ(root_members());
	}
	// 根に対するすべてのメンバー
	map<int, VI> all_group_members() const{
		map<int, VI> group_members;
		REP(member, n)
			group_members[root(member)].push_back(member);
		return group_members;
	}
	// 表示用
	friend ostream& operator<<(ostream& os, const UnionFind& uf){
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
	// グラフ
	istringstream iss(
		"4 5 0\n" // 頂点数 辺の数 開始ノード
		"0 1 1\n" // s t c
		"0 2 4\n"
		"1 2 2\n"
		"2 3 1\n"
		"1 3 5\n"
	);
	int n, edges, start;
	iss >> n >> edges >> start;
	vector< vector<PII> > adj(n);
	REP(_, edges){
		int s, t, cost;
		iss >> s >> t >> cost;
		adj[s].push_back({t, cost});
	}
	dump(adj)
	dump(dijkstra(adj, n, start))
	dump(bfs(adj, n, start))
	dump(dfs(adj, n, start))
	dump(dfs_recursive(adj, n, start))
	// UnionFind
	UnionFind uf(5);
	uf.merge(1,2);
	uf.merge(0,4);
	OUT("UnionFind")
	OUT(uf)
	return 0;
}
