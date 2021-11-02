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
// デバッグ用
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

template<class T> vector<size_t> argsort(const vector<T> &vec, bool asc=true){
	vector<size_t> index(vec.size()); iota(index.begin(), index.end(), 0);
	sort(index.begin(), index.end(), [&vec, &asc](size_t i, size_t j){return asc ? (vec[i] < vec[j]):(vec[i] > vec[j]);});
	return index;
}
// 表示系
template <class Head> void OUT(Head&& head) {cout << head << endl;}
template <class Head, class... Tail> void OUT(Head&& head, Tail&&... tail) {cout << head << " ";OUT(forward<Tail>(tail)...);}
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
	os << "[ "; for ( const T& item : vec ) os << item << ", ";
	os << "]"; return os;
}
template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
	os << "{ "; for ( const T& item : s ) os << item << ", ";
	os << "}"; return os;
}
template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1, T2>& m) {
	os << "{ "; for ( const auto &[key, value] : m ) os << key << ":"<< value << ", ";
	os << "}"; return os;
}
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
	os << "("; apply([&os](auto&&... args) {((os << args << ", "), ...);}, t);
	os << ")"; return os;
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
template<class... T> istream& operator>>(istream& is, tuple<T...>& t) {
	apply([&is](auto&&... args) {((is >> args), ...);}, t);
	return is;
}
// 集合演算
template<class T> set<T> operator&(const set<T>& a, const set<T>& b) {// 共通集合
	set<T> ans; set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator|(const set<T>& a, const set<T>& b) {// 和集合
	set<T> ans; set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}
template<class T> set<T> operator-(const set<T>& a, const set<T>& b) {// 差集合
	set<T> ans; set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(ans, ans.end()));
	return ans;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

// --------------------ここから--------------------

// a^n % mod
template<class T>
T pow_mod(T a, T n, T mod){
	T ans = 1;
	while (n > 0) {
		if ((n & 1))
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

// nCr
template<class T>
T combi(T n, T r){
	r = (r > n / 2) ? n - r : r;
	T ans = 1;
	for (int i = 1; i <= r; i++, n--) {
		ans *= n;
		ans /= i;
	}
	return ans;
}

// nCr % mod ただし modは素数
template<class T>
T combi_mod(T n, T r, T mod){
	T ans=1, div=1;
	for (T i = n; i > n-r; --i)
		ans = (ans*(i%mod))%mod;
	for (T i = 1; i < r+1; ++i)
		div = (div*(i%mod))%mod;
	T inv_div = pow_mod(div, mod-2, mod); // 整数の逆元
	return (ans * inv_div) % mod;
}

// 素因数分解
template<class T>
vector<T> pfact(T x){
	vector<T> ans;
	for (T i=2; i*i<=x; ++i){
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
template<class T>
vector<T> dijkstra(const vector< vector< pair<int, T> > > &adj, int n, int s){ // (隣接, ノード数, 始点)
	vector<T> dist(n, numeric_limits<T>::max());
	priority_queue< pair<T, int>, vector< pair<T, int> >, greater< pair<T, int> > > pq;
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

// 有向グラフの順序で見て, 頂点に順序をつける
VI topological_sort(const VVI &adj, int n){
	// 入次数
	VI indeg(n, 0);
	REP(i, n)EACH(j, adj[i])
		indeg[j]++;
	
	priority_queue< int, VI, greater<int> > heap;
	REP(i, n){
		if (indeg[i] == 0) 
			heap.push(i);
	}
	VI ans;
	while (!heap.empty()) {
		// 入次数がゼロで番号が若い順に訪問する
		int i = heap.top();
		heap.pop();
		ans.push_back(i);
		// iをグラフから削除
		EACH(j, adj[i]) {
			indeg[j]--;
			if (indeg[j] == 0)
				heap.push(j);
		}
	}
	return ans;
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
		os << uf.all_group_members();
		return os;
	}
};

// 最小全域木
// edges: {cost, v1, v2}
template<class T>
T kruskal(vector< tuple<T,int,int> > edges, int n) {
	// コストが小さい順にソート
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	T min_cost = 0;
	for(auto [cost, v1, v2] : edges) {
		if (!uf.same(v1, v2)) {
			// 辺を追加しても閉路ができないなら、その辺を採用する
			min_cost += cost;
			uf.merge(v1, v2);
		}
	}
	return min_cost;
}

// 最大値に関するセグメント木
template <class T>
class SegmentTree {
private:
	T init_val; // 初期値
	int num_leaves; // 2のべき
	vector<T> data, lazy;
	vector<bool> upd;

	T op(T a, T b){
		return max(a, b); // ここを書き換えれば最小値, 合計値に対する木も作れる
	}
	void __update(int a, int b, T val, int i, int l, int r) {
		eval(i);
		if (a <= l && r <= b) { // 範囲内のとき
			lazy[i] = val;
			upd[i] = true;
			eval(i);
		} else if (a < r && l < b) {
			__update(a, b, val, i * 2 + 1, l, (l + r) / 2);
			__update(a, b, val, i * 2 + 2, (l + r) / 2, r);
			data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}
	T __query(int a, int b, int i, int l, int r) {
		eval(i);
		if (r <= a || b <= l) // 範囲外のとき
			return init_val;
		if (a <= l && r <= b)// 範囲内のとき
			return data[i];
		T vl = __query(a, b, i * 2 + 1, l, (l + r) / 2);
		T vr = __query(a, b, i * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
	void eval(int i) {
		if (!upd[i]) return; // 更新が無ければスルー
		if (i < num_leaves - 1) { // 葉でなければ子に伝搬
			lazy[i * 2 + 1] = lazy[i];
			lazy[i * 2 + 2] = lazy[i];
			upd[i * 2 + 1] = true;
			upd[i * 2 + 2] = true;
		}
		// 自身を更新
		data[i] = lazy[i];
		lazy[i] = init_val;
		upd[i] = false;
	}
public:
	SegmentTree(int n, T init) {// [0,n)の範囲を持つセグメント木
		int x = 1;
		while(n > x)
			x *= 2;
		num_leaves = x;
		init_val = init;
		data.resize(num_leaves*2-1, init_val);
		lazy.resize(num_leaves*2-1, init_val);
		upd.resize(num_leaves*2-1, false);
	}
	void update(int a, int b, T val) {// [a,b)区間の値をvalに更新
		__update(a, b, val, 0, 0, num_leaves);
	}
	void update(int i, T val) {// 値を更新
		__update(i, i+1, val, 0, 0, num_leaves);
	}
	T query(int a, int b) {// [a,b)の最大値を取得
		return __query(a, b, 0, 0, num_leaves);
	}
	T query(int i) {// iの最大値を取得
		return __query(i, i+1, 0, 0, num_leaves);
	}
	// 表示用
	friend ostream& operator<<(ostream& os, SegmentTree& st){
		st.query(0, st.num_leaves);
		int br=1;
		for (int i = 0; i < 2*st.num_leaves-1; ++i) {
			os << st.data[i] << ", ";
			if (br==i+1){
				os << endl;
				br = 2*br+1;
			}
		}
		return os;
	}
};

// Binary Indexed Tree
template <class T>
class BIT {
	int n;
	vector<T> bit;
public:
	BIT(int _n) : n(_n + 1), bit(n, 0) {}
	// a[i] += val ただし i in [0, n)
	void add(int i, T val) {
		for (int idx = i+1; idx <= n; idx += (idx & -idx))
			bit[idx] += val;
	}
	// a[0] + ... + a[i] ただし i in [0, n)
	T sum(int i) {
		T s(0);
		for (int idx = i+1; idx > 0; idx -= (idx & -idx)) 
			s += bit[idx];
		return s;
	}
};

// 座標圧縮
template<class T>
T compress(vector<T> &vec){
	map<T, T> mem;
	for(auto v: vec) mem[v] = 0;
	T sz = 0;
	for(auto &p: mem) p.second = sz++;
	for(auto &p: vec) p = mem[p];
	return sz;
}

// 最長増加部分列の長さ
template<class T>
size_t LIS(const vector<T> &ary){
	vector<T> dp;// 長さkである増加部分列のうち, 最後の要素の最小値
	dp.reserve(ary.size());
	for(T a : ary){
		size_t i=INSPOS(dp, a);
		if (i<dp.size())
			dp[i]=a;
		else
			dp.push_back(a);
	}
	return dp.size();
}

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
	//
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
	dump(sccd(adj2, n2))
	// UnionFind
	UnionFind uf(5);
	uf.merge(1,2);
	uf.merge(0,4);
	dump(uf)
	//
	dump(LIS(VI{3, 1, 4, 1, 5, 9, 2, 6}))
	return 0;
}
