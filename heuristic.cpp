#pragma GCC optimize("O3")

#define DEBUG true
// #define DEBUG false

#if !DEBUG
    #define NDEBUG // assertを無視
#endif

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
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
#include <optional> // optional<int> f = nullopt; if(f) f.value();
#include <functional> // function<int(int)> frac; frac = [&](int i){ return i <= 0 ? 1 : i*frac(i-1); };
#include <regex> // regex_replace("target", regex("old"), "new");
#define MY_PI     3.14159265358979323846
#define MY_E      2.7182818284590452354
#define INF     (INT_MAX / 2)
#define LINF    (LLONG_MAX / 2)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define EACH(e, v) for(auto &e : v)
#define ITR(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
#define RITR(it, v) for(auto it = (v).rbegin(); it != (v).rend(); ++it)
#define CASE break; case
#define DEFAULT break; default
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
#define COUNT(v, e) count((v).begin(), (v).end(), e)
#define ROTATE_L(v) rotate((v).begin(), (v).begin()+1, (v).end())
#define ROTATE_R(v) rotate((v).rbegin(), (v).rbegin()+1, (v).rend())
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
template<class T, size_t N> ostream& operator<<(ostream& os, const array<T, N>& ary) {
    os << "[ "; for ( const T& item : ary ) os << item << ", ";
    os << "]"; return os;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[ "; for ( const T& item : vec ) os << item << ", ";
    os << "]"; return os;
}
template<class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{ "; for ( const T& item : s ) os << item << ", ";
    os << "}"; return os;
}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& s) {
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
template<class T, size_t N> istream& operator>>(istream& is, array<T, N>& ary) {
    for ( T& item : ary ) is >> item;
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
using VD = vector<double>; using VVD = vector<VD>; using VVVD = vector<VVD>;
using VC = vector<char>; using VS = vector<string>;
using PII = pair<int,int>; using PLL = pair<LL,LL>; using PDD = pair<double,double>;
using MII = map<int,int>; using MLL = map<LL,LL>;
using SI = set<int>; using SL = set<LL>;
template<class T> using MAXPQ = priority_queue<T>;
template<class T> using MINPQ = priority_queue< T, vector<T>, greater<T> >;
// int -> str: to_string(i)
// str -> int: stoi(s)
// vec -> set: set<int> s(ALL(v));
// 1が立っている数: __builtin_popcount(i), __builtin_popcountll(i)
// 上位ビットの連続した0の数: __builtin_clz(i), __builtin_clzll(i) // i=0未定義
// 下位ビットの連続した0の数: __builtin_ctz(i), __builtin_ctzll(i) // i=0未定義

template <class Head> void IN(Head&& head) {cin >> head;}
template <class Head, class... Tail> void IN(Head&& head, Tail&&... tail) {cin >> head;IN(forward<Tail>(tail)...);}

// 乱数
// const int SEED = random_device()();
constexpr int SEED = 1;
mt19937 rand_engine(SEED);
// [0,1)
inline double get_rand(){
    uniform_real_distribution<double> rand01(0.0, 1.0);
    return rand01(rand_engine);
}
// [0, n)
inline int get_rand(int n){
    uniform_int_distribution<int> rand_n(0, n-1);
    return rand_n(rand_engine);
}
// [l, u)
inline int get_rand(int l, int u){
    uniform_int_distribution<int> rand_lu(l, u-1);
    return rand_lu(rand_engine);
}
// 累積和
template<class T>
inline vector<T> cumsum(const vector<T> &vec, bool zero_start){
    int n = SZ(vec) + zero_start;
    vector<T> cumsum(n);
    cumsum[0] = zero_start ? 0 : vec[0];
    FOR(i, 1, n)
        cumsum[i] = cumsum[i-1] + vec[i - zero_start];
    return cumsum;
}
template<class T>
inline int get_rand_index_with_cumsum_weight(const vector<T> &weight_cumsum){
    double p = get_rand() * weight_cumsum.back();
    return min((int)INSPOS(weight_cumsum, p), SZ(weight_cumsum)-1);
}
// 重みの割合でindex
template<class T>
inline int get_rand_index(const vector<T> &weight){
    auto weight_cumsum = cumsum(weight, false);
    return get_rand_index_with_cumsum_weight(weight_cumsum);
}
// [0,n)から重複なしでr個選ぶ
inline VI rand_choice(int n, int r){
    VI candidates(n);
    ARANGE(candidates);
    VI result;
    std::sample(candidates.begin(), candidates.end(), back_inserter(result), r, rand_engine);
    return result;
}

// 画面クリア
inline void clear_screen(){
    cout << "\x1b[0;0H";
}
// スリープ
inline void sleep(int msec){
    this_thread::sleep_for(chrono::milliseconds(msec));
}
// 数字ゼロ埋め文字列
inline string to_string_zerofill(int num, int digit){
    std::ostringstream sout;
    sout << std::setfill('0') << std::setw(digit) << num;
    return sout.str();
}

// CPU時間
class ClockTimer{
private:
    clock_t start_at, end_at;
public:
    ClockTimer(){}
    inline void start() { start_at = clock(); }
    inline void end() { end_at = clock(); }
    inline clock_t time() const { return 1000*(end_at-start_at) / CLOCKS_PER_SEC; }// ミリ秒
};

// chronoは処理系によってCPU時間か実時間か変わるため注意
class ChronoTimer{
private:
    chrono::high_resolution_clock::time_point start_at, end_at;
public:
    ChronoTimer(){}
    inline void start() { start_at = chrono::high_resolution_clock::now(); }
    inline void end() { end_at = chrono::high_resolution_clock::now(); }
    inline int64_t time() const { return chrono::duration_cast<chrono::milliseconds>(end_at - start_at).count(); }// ミリ秒
};

// テンプレートクラス TopN
// Compare: std::less<T> で最大値N個管理
// Compare: std::greater<T> で最小値N個管理
template <typename T, typename Compare = std::less<T>>
class TopN {
public:
    // コンストラクタ: 管理する要素数 capacity を指定
    explicit TopN(size_t capacity) : capacity_(capacity) {}

    // emplace による要素追加
    template <typename... Args>
    void emplace(Args&&... args) {
        T value(std::forward<Args>(args)...);
        if (data_.size() < capacity_) {
            data_.emplace(std::move(value));
        } else {
            auto it = data_.begin();
            if (comp_(*it, value)) {
                data_.erase(it);
                data_.emplace(std::move(value));
            }
        }
    }

    const T& getWorst() const {
        if (data_.empty()) throw std::runtime_error("TopN: 要素が存在しません");
        return *data_.begin();
    }

    const T& getBest() const {
        if (data_.empty()) throw std::runtime_error("TopN: 要素が存在しません");
        return *data_.rbegin();
    }

    void removeWorst() {
        if (data_.empty()) throw std::runtime_error("TopN: 削除できる要素がありません");
        data_.erase(data_.begin());
    }

    void removeBest() {
        if (data_.empty()) throw std::runtime_error("TopN: 削除できる要素がありません");
        auto it = std::prev(data_.end());
        data_.erase(it);
    }

    // Worst -> Best
    auto begin() { return data_.begin(); }
    auto end() { return data_.end(); }
    auto begin() const { return data_.begin(); }
    auto end() const { return data_.end(); }

    // Best -> Worst
    auto rbegin() { return data_.rbegin(); }
    auto rend() { return data_.rend(); }
    auto rbegin() const { return data_.rbegin(); }
    auto rend() const { return data_.rend(); }

    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }
    size_t capacity() const { return capacity_; }
    void clear() { data_.clear(); }

private:
    size_t capacity_;
    std::multiset<T, Compare> data_;
    Compare comp_{}; // 比較関数オブジェクト。たとえば std::less<T> は a < b の判定を行い、bool を返します。
};


// 時間制限
constexpr int TIME_LIMIT = 1980;
// メモ: greedy, DP

// データ
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
    // 小さいほどよい
    double custom_score;

    State(){}
    void initialize(){
        if(DEBUG) OUT("initialize");
        // 初期解 ----------
        vec = init_vec;
        // ----------------
    }
    tuple<double, double> calc_score() {
        score = 0;
        custom_score = 0;
        // スコア ----------
        REP(i, N-1)
            score += (vec[i]<vec[i+1]);
        custom_score = -score;
        // -----------------
        return {score, custom_score};
    }
    void print_answer() const {
        // 答え表示 ---------
        OUT(vec);
        // -----------------
    }
    // ターンがあるような場合
    // vector<State> next_states() const {
    //     // 未実装
    //     vector<State> nexts;
    //     return nexts;
    // }
    void next_states(TopN<State,greater<State>> &nexts) const {
        // 未実装
        State s=*this;
        // sに次のターンの変更を加える
        s.calc_score();
        nexts.emplace(s);
    }
    bool operator<(const State& s) const {
        return custom_score < s.custom_score;
    }
    bool operator>(const State& s) const {
        return custom_score > s.custom_score;
    }
};



double annealing(ChronoTimer &timer, int loop_max, int verbose){
    if(DEBUG) OUT("annealing");
    constexpr double START_TEMP = 0.1;
    constexpr double END_TEMP   = 0.001;

    State state;
    state.initialize();

    auto [score, custom_score] = state.calc_score();
    if(DEBUG) OUT("initial score:", score, "\t", custom_score);
    // ベスト解を別で持っておく場合
    State best_state=state;

    // 改善されないとき強制遷移させる間隔(山登りで破壊したいとき)
    constexpr int FORCE_UPDATE = 10000;
    int no_update_times=0;
    REP(loop, loop_max){
        timer.end();
        if(timer.time()>TIME_LIMIT)
            break;

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
        const auto [current_score, current_custom_score] = state.calc_score();
        
        if (DEBUG && loop % verbose == 0){
            // OUT(loop, "\t:", score, "\t", custom_score);
            OUT(loop, "\t:", score, "\t", custom_score, "\t", best_state.score, "\t", best_state.custom_score);
        }

        if (current_custom_score < custom_score){
            // 改善された場合
            no_update_times=0;
            score = current_score;
            custom_score = current_custom_score;
            // ベスト解
            if (current_custom_score<best_state.custom_score)
                best_state=state;
            continue;
        }
        // 改善されなかった場合
        ++no_update_times;
        if (no_update_times>=FORCE_UPDATE){
            // 強制遷移
            no_update_times=0;
            score = current_score;
            custom_score = current_custom_score;
            continue;
        }
        // 温度
        const double temp = START_TEMP + (END_TEMP - START_TEMP) * loop / loop_max; // 線形
        // const double temp = START_TEMP * pow(END_TEMP/START_TEMP, (double) loop / loop_max); // 指数
        // const double temp = START_TEMP + (END_TEMP - START_TEMP) * (double) timer.time() / TIME_LIMIT; // 線形
        // const double temp = START_TEMP * pow(END_TEMP/START_TEMP, (double) timer.time() / TIME_LIMIT); // 指数
        const double probability = exp((custom_score-current_custom_score) / temp);
        if (probability > get_rand()){
            // 温度による遷移
            score = current_score;
            custom_score = current_custom_score;
            continue;
        }

        // もとに戻す
        // 逆操作が難しい場合はまるごとコピーする
        // NOTE: 焼きなましは遷移が失敗することのほうが多いため、その場合はbackup側を変更して、成功時にstateに反映させたほうが速い
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
        // OUT("final score:", score, "\t", custom_score);
        // state.print_answer();
        OUT("final score:", best_state.score, "\t", best_state.custom_score);
        best_state.print_answer();
    }
    return best_state.score;
}

double chokudai_search(ChronoTimer &timer, int loop_max, int max_turn, int chokudai_width, int verbose){
    if(DEBUG) OUT("chokudai_search");
    State init;
    init.initialize();
    
    auto [score, custom_score] = init.calc_score();
    if(DEBUG) OUT("initial score:", score, "\t", custom_score);

    // カスタムスコアが小さいほど良い
    // vector< MINPQ<State> > pq(max_turn+1);
    constexpr int maxsave = 100;
    vector< TopN<State, greater<State>> > pq(max_turn+1, TopN<State,greater<State>>(maxsave));
    pq[0].emplace(init);
    REP(loop, loop_max){
        timer.end();
        if(timer.time()>TIME_LIMIT)
            break;
        REP(turn, max_turn){ // 各ターン
            REP(w, chokudai_width){
                if(pq[turn].empty()) break;
                // 先頭参照
                // const State &state = pq[turn].top();
                // for(State& next : state.next_states()){
                //     next.calc_score();
                //     pq[turn+1].emplace(next);
                // }
                // 先頭削除
                // pq[turn].pop();
                const State &state = pq[turn].getBest();
                state.next_states(pq[turn+1]);
                pq[turn].removeBest();
            }
        }
        if (DEBUG && loop % verbose == 0)
            // OUT(loop, "\t:", pq[max_turn].top().score, "\t", pq[max_turn].top().custom_score);
            OUT(loop, "\t:", pq[max_turn].getBest().score, "\t", pq[max_turn].getBest().custom_score);
    }
    // return pq[max_turn].top().score;
    return pq[max_turn].getBest().score;
}

double beam_search(int max_turn, int beam_width, int verbose){
    if(DEBUG) OUT("beam_search");
    State init;
    init.initialize();
    
    auto [score, custom_score] = init.calc_score();
    if(DEBUG) OUT("initial score:", score, "\t", custom_score);

    // vector<State> top_states{init};
    TopN<State,greater<State>> top_states(beam_width);
    top_states.emplace(init);
    REP(turn, max_turn){ // 各ターン
        // vector<State> next_states;
        TopN<State,greater<State>> next_states(beam_width);
        for(const State &state : top_states) {
            state.next_states(next_states);
            // for(State& next : state.next_states()){
            //     next.calc_score();
            //     next_states.emplace_back(next);
            // }
            // カスタムスコアが小さいほど良い
            // SORT(next_states);
            // partial_sort(next_states.begin(), next_states.begin() + min(beam_width, SZ(next_states)), next_states.end());
            // nth_element(next_states.begin(), next_states.begin() + min(beam_width, SZ(next_states)), next_states.end());
            // // 上位beam_width個に絞る
            // if (SZ(next_states)>beam_width)
            //     next_states.resize(beam_width);
        }
        top_states = next_states;
        if (DEBUG && turn % verbose == 0)
            // OUT(turn, "\t:", top_states.front().score, "\t", top_states.front().custom_score);
            OUT(turn, "\t:", top_states.getBest().score, "\t", top_states.getBest().custom_score);
    }
    // return top_states.front().score;
    // return MIN(top_states).score;
    return top_states.getBest().score;
}

const string INPUT_DIR = "./in/";
int main() {
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    ChronoTimer timer;
    int case_num = DEBUG ? 5 : 1;
    double sum_score = 0.0;
    double sum_log_score = 0.0;
    int64_t max_time = 0;
    int argmax_time = -1;
    REP(i, case_num){
        timer.start();
        if (DEBUG){
            rand_engine.seed(SEED);
            OUT("data_load");
            string filename = to_string_zerofill(i, 4) + ".txt";
            string file_path = INPUT_DIR + filename;
            ifstream ifs(file_path);
            assert(!ifs.fail());
            data_load(ifs);
            // data_generate();
        }else{
            data_load(cin);
        }
        double score = annealing(timer, 1000000, 100000);
        timer.end();
        if(DEBUG) {
            auto time = timer.time();
            sum_score += score;
            sum_log_score += log1p(score);
            if(max_time < time)
                max_time = time, argmax_time=i;
            OUT("--------------------");
            OUT("case_num: ", i);
            OUT("score: ", score);
            OUT("time: ", time);
            OUT("mean_score: ", sum_score/(i+1));
            OUT("mean_log_score: ", sum_log_score/(i+1));
            OUT("sum_score: ", sum_score);
            OUT("sum_log_score: ", sum_log_score);
            OUT("max_time: ", max_time);
            OUT("argmax_time: ", argmax_time);
            OUT("--------------------");
        }
    }
    return 0;
}
