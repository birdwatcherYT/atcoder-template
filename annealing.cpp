// #pragma GCC optimize("O3")
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
#include <list>
#include <numeric>
#include <cassert> // assert();
#include <iomanip> // cout << setprecision(15); cout << setfill('0') << std::right << setw(3);
#include <fstream>
#include <random>
#include <chrono>
#define _PI	 3.14159265358979323846
#define _E	  2.7182818284590452354
#define INF	 (INT_MAX / 2)
#define LINF	(LLONG_MAX / 2)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define RREP(i, n)  for(int i = (n) - 1; i >= 0; --i)
#define EACH(e, v) for(auto &e : v)
#define ITR(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
#define RITR(it, v) for(auto it = (v).rbegin(); it != (v).rend(); ++it)
#define CASE break; case
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
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class... T> ostream& operator<<(ostream& os, const tuple<T...>& t) {
	os << "("; apply([&os](auto&&... args) {((os << args << ", "), ...);}, t);
	os << ")"; return os;
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
template <class Head> void OUT(Head&& head) {cout << head << endl;}
template <class Head, class... Tail> void OUT(Head&& head, Tail&&... tail) {cout << head << " ";OUT(forward<Tail>(tail)...);}
// 入力系
template<class T1, class T2> istream& operator>>(istream& is, pair<T1, T2>& p) {
	is >> p.first >> p.second;
	return is;
}
template<class... T> istream& operator>>(istream& is, tuple<T...>& t) {
	apply([&is](auto&&... args) {((is >> args), ...);}, t);
	return is;
}
template<class T> istream& operator>>(istream& is, vector<T>& vec) {
	for ( T& item : vec ) is >> item;
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

using LL = long long; using ULL = unsigned long long;
using VI = vector<int>; using VVI = vector<VI>;
using VL = vector<LL>; using VVL = vector<VL>;
using VB = vector<bool>; using VVB = vector<VB>;
using VC = vector<char>; using VS = vector<string>;
using PII = pair<int,int>; using PLL = pair<LL,LL>;
using MII = map<int,int>; using MLL = map<LL,LL>;
using SI = set<int>; using SL = set<LL>;
template<class T> using MAXPQ = priority_queue<T>;
template<class T> using MINPQ = priority_queue< T, vector<T>, greater<T> >;

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

// 乱数
// const int SEED = random_device()();
const int SEED = 1;
mt19937 rand_engine(SEED);
// [0,1]
double get_rand(){
	uniform_real_distribution<double> rand01(0.0, 1.0);
	return rand01(rand_engine);
}
// [0, n)
int get_rand(int n){
	uniform_int_distribution<int> rand_n(0, n-1);
	return rand_n(rand_engine);
}
// [l, u)
int get_rand(int l, int u){
	uniform_int_distribution<int> rand_lu(l, u-1);
	return rand_lu(rand_engine);
}

// データ
const string DATA_DIR = "./";
const int N = 15;
vector<string> raw_data(N);
void data_load(){
	OUT("data_load");
	const string file_path = DATA_DIR + "annealing.cpp";
	ifstream ifs(file_path);
	assert(!ifs.fail());
	// データ読み込み ----------
	ifs >> raw_data;
	// ------------------------
}

// 状態
struct State {
	VI vec;

	State(){}
	void initialize(){
		OUT("initialize");
		// 初期解 ----------
		vec.resize(N);
		ARANGE(vec);
		shuffle(ALL(vec), rand_engine);
		// ----------------
	}
	tuple<double, double> get_score() {
		double annealing_score = 0;
		double score = 0;
		// スコア ----------
		REP(i, N-1)
			score += (vec[i]<vec[i+1]);
		annealing_score = -score;
		// -----------------
		return {annealing_score, score};
	}
};

void optimize(int loop_max, int verbose){
	OUT("optimize");
	double start_temp = 0.1;
	double end_temp	= 0.001;
	
	State state;
	state.initialize();
	
	auto [annealing_score, score] = state.get_score();
	OUT("initial score:", annealing_score, "\t", score);

	REP(loop, loop_max){
		double temp = start_temp + (end_temp - start_temp) * loop / loop_max;
		// State backup = state;
		// 操作
		int op = get_rand(2);
		int i=get_rand(N), j=get_rand(N), k=get_rand(N);
		switch(op){
			case 0:
			{
				swap(state.vec[i], state.vec[j]);
			}
			CASE 1:
			{
				swap(state.vec[i], state.vec[j]);
				swap(state.vec[j], state.vec[k]);
			}
		}
		auto [current_annealing_score, current_score] = state.get_score();
		
		if (loop % verbose == 0)
			OUT(loop, "\t:", annealing_score, "\t", score);

		double probability = exp((annealing_score-current_annealing_score) / temp); 
		if (current_annealing_score < annealing_score){
			// 改善
			score = current_score;
			annealing_score = current_annealing_score;
			continue;
		} else if (probability > get_rand()){
			score = current_score;
			annealing_score = current_annealing_score;
			continue;
		}

		// もとに戻す
		// state = backup;
		switch(op){
			case 0:
			{
				swap(state.vec[i], state.vec[j]);
			}
			CASE 1:
			{
				swap(state.vec[j], state.vec[k]);
				swap(state.vec[i], state.vec[j]);
			}
		}
	}
	OUT("final score:", annealing_score, "\t", score);
	dump(state.vec)
}

// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
int main() {
	data_load();
	auto start = chrono::system_clock::now();
	optimize(1000000, 10000);
	auto end = chrono::system_clock::now();
	auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	OUT("msec: ", msec);
	return 0;
}
