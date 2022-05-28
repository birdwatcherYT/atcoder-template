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
#include <thread>
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
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
using VL = vector<LL>; using VVL = vector<VL>; using VVVL = vector<VVL>;
using VB = vector<bool>; using VVB = vector<VB>; using VVVB = vector<VVB>;
using VC = vector<char>; using VS = vector<string>;
using PII = pair<int,int>; using PLL = pair<LL,LL>;
using MII = map<int,int>; using MLL = map<LL,LL>;
using SI = set<int>; using SL = set<LL>;
template<class T> using MAXPQ = priority_queue<T>;
template<class T> using MINPQ = priority_queue< T, vector<T>, greater<T> >;
// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
// 1が立っている数: __builtin_popcount(i), __builtin_popcountll(i)

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
// 画面クリア
void clear_screen(){
	cout << "\x1b[0;0H";
}
// スリープ
void sleep(int msec){
	this_thread::sleep_for(chrono::milliseconds(msec));
}
// 数字ゼロ埋め文字列
string to_string_zerofill(int num, int digit){
	std::ostringstream sout;
	sout << std::setfill('0') << std::setw(digit) << num;
	return sout.str();
}

// CPU時間
class ClockTimer{
private:
	clock_t _start, _end;
public:
	ClockTimer(){}
	inline void start() { _start = clock(); }
	inline void end() { _end = clock(); }
	inline double time() { return (double)(_end-_start) / CLOCKS_PER_SEC; }
};

// chronoは処理系によってCPU時間か実時間か変わるため注意
class ChronoTimer{
private:
	chrono::high_resolution_clock::time_point _start, _end;
public:
	ChronoTimer(){}
	inline void start() { _start = chrono::high_resolution_clock::now(); }
	inline void end() { _end = chrono::high_resolution_clock::now(); }
	inline int64_t time() { return chrono::duration_cast<chrono::milliseconds>(_end - _start).count(); }
};


// データ
const bool DEBUG = true;
// const bool DEBUG = false;
int N;
VI init_vec;
void data_load(istream &is){
	// データ読み込み ----------
	is >> N;
	init_vec.resize(N);
	is >> init_vec;
	// ------------------------
}
void data_generate(){
	// データ生成 --------------
	N = get_rand(10, 16);
	init_vec.resize(N);
	ARANGE(init_vec);
	shuffle(ALL(init_vec), rand_engine);
	// ------------------------
}

// 状態
struct State {
	VI vec;
	double score;

	State(){}
	void initialize(){
		if(DEBUG) OUT("initialize");
		// 初期解 ----------
		vec = init_vec;
		// ----------------
	}
	tuple<double, double> calc_score() {
		double annealing_score = 0;
		score = 0;
		// スコア ----------
		REP(i, N-1)
			score += (vec[i]<vec[i+1]);
		annealing_score = -score;
		// -----------------
		return {annealing_score, score};
	}
	void print_answer(){
		// 答え表示 ---------
		OUT(vec);
		// -----------------
	}
	// ターンがあるような場合
	vector<State> next_states() const {
		// 未実装
		vector<State> next;
		return next;
	}
	bool operator<(const State& s) const {
		return score < s.score;
	}
	bool operator>(const State& s) const {
		return score > s.score;
	}
};

double annealing(int loop_max, int verbose){
	if(DEBUG) OUT("annealing");
	double start_temp = 0.1;
	double end_temp	= 0.001;
	
	State state;
	state.initialize();
	
	auto [annealing_score, score] = state.calc_score();
	if(DEBUG) OUT("initial score:", annealing_score, "\t", score);

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
		auto [current_annealing_score, current_score] = state.calc_score();
		
		if (DEBUG && loop % verbose == 0)
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
	if(DEBUG){
		OUT("final score:", annealing_score, "\t", score);
		state.print_answer();
	}
	return score;
}

double chokudai_search(int loop_max, int verbose, int max_turn, int chokudai_width){
	if(DEBUG) OUT("chokudai_search");
	State init;
	init.initialize();
	
	auto [_, score] = init.calc_score();
	if(DEBUG) OUT("initial score:", score);

	// スコアが大きいほど良い
	vector< MAXPQ<State> > pq(max_turn+1);
	pq[0].push(init);
	REP(loop, loop_max){
		REP(turn, max_turn){ // 各ターン
			REP(_, chokudai_width){
				if(pq[turn].empty()) break;
				// 先頭参照
				const State &state = pq[turn].top();
				for(State& next : state.next_states()){
					next.calc_score();
					pq[turn+1].push(next);
				}
				// 先頭削除
				pq[turn].pop();
			}
		}
		if (DEBUG && loop % verbose == 0)
			OUT(loop, "\t:", pq[max_turn].top().score);
	}
	return pq[max_turn].top().score;
}

double beam_search(int max_turn, int beam_width){
	if(DEBUG) OUT("beam_search");
	State init;
	init.initialize();
	
	auto [_, score] = init.calc_score();
	if(DEBUG) OUT("initial score:", score);

	vector<State> top_states;
	top_states.push_back(init);
	REP(turn, max_turn){ // 各ターン
		vector<State> next_states;
		for(const State &state : top_states) {
			for(State& next : state.next_states()){
				next.calc_score();
				next_states.push_back(next);
			}
			// スコアが大きいほど良い
			RSORT(next_states);
			// 上位beam_width個まで絞る
			while(SZ(next_states)>beam_width)
				next_states.pop_back();
		}
		top_states = next_states;
		if (DEBUG)
			OUT(turn, "\t:", top_states.front().score);
	}
	return top_states.front().score;
}

const string DATA_DIR = "./data/";
int main() {
	ClockTimer timer;
	int case_num = DEBUG ? 5 : 1;
	double sum_score = 0.0;
	REP(i, case_num){
		timer.start();
		if (DEBUG){
			OUT("data_load");
			string filename = to_string_zerofill(i, 4) + ".txt";
			string file_path = DATA_DIR + filename;
			ifstream ifs(file_path);
			assert(!ifs.fail());
			data_load(ifs);
			// data_generate();
		}else{
			data_load(cin);
		}
		double score = annealing(1000000, 100000);
		timer.end();
		if(DEBUG) {
			sum_score += score;
			OUT("--------------------");
			OUT("case_num: ", i);
			OUT("score: ", score);
			OUT("time: ", timer.time());
			OUT("mean_score: ", sum_score/(i+1));
			OUT("sum_score: ", sum_score);
			OUT("--------------------");
		}
	}
	return 0;
}
