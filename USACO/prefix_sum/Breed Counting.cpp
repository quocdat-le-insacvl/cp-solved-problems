//region Folding
/*
  Thu Sep 22 18:10:59 CEST 2022
  @author: Night Fury
*/
 
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define for_map(Map) for ( const auto &[k, v] : Map)
#define rep(i, a, b) for (int i=a; i < (b); ++i)
#define repd(i, a, b) for (int i=a; i >= (b); --i)
#define rep0(i, n) for (int i=0; i < (int)(n); ++i)
#define repi(n) for (int i=0; i < (int)(n); ++i)
#define repj(n) for (int j=0; j < (int)(n); ++j)
#define repk(n) for (int k=0; k < (int)(n); ++k)
#define repi1(n) for (int i=1; i <= (int)(n); ++i)
#define repj1(n) for (int j=1; j <= (int)(n); ++j)
#define repk1(n) for (int k=1; k <= (int)(n); ++k)
#define rep1(i, n) for (int i=1; i < (int)(n); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vt vector
#define EACH(x, a) for (auto& x: a)
typedef long long ll;
typedef pair<int, int> pii;
typedef vt<int> vi;
typedef vt<pii> vpii;
const std::string MIN_A_TO_Z = "abcdefghijklmnopqrstuvwxyz";
const std::string MAJ_A_TO_Z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ZERO_NINE = "0123456789";
const std::string SPECIAL_CHARACTERS = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const vt<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

void DBG() {
    cerr << "]" << endl;
}

template<class H, class... T>
void DBG(H h, T... t) {
    cerr << to_string(h);
    if (sizeof...(t))
        cerr << ", ";
    DBG(t...);
}

#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

void read(int &k) {
    cin >> k;
}

void read(double &k) {
    cin >> k;
}

void read(string &k) {
    cin >> k;
}

void read(vt<int> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vt<string> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vpii &k) {
    EACH(x, k) {
        cin >> x.first >> x.second;
    }
}

template<class H, class... T>
void read(H &h, T &... t) {
    read(h);
    read(t...);
}

string to_string(char c) {
    return string(1, c);
}

string to_string(bool b) {
    return b ? "true" : "false";
}

string to_string(const char *s) {
    return string(s);
}

string to_string(string s) {
    return s;
}

string to_string(vt<bool> v) {
    string res;
    repi(sz(v))res += char('0' + v[i]);
    return res;
}

template<size_t S>
string to_string(bitset<S> b) {
    string res;
    repi(S) res += char('0' + b[i]);
    return res;
}

string to_string(pii v) {
    string res = to_string(v.first) + ' ' + to_string(v.second);
    return res;
}

string to_string(std::priority_queue<int, vi, greater<int>> v) {
    string res = "Priority Queue : [";
    while (!v.empty()) {
        int tmp = v.top();
        v.pop();
        res += to_string(tmp) + ", ";
    }
    res += "]";
    return res;
}

template<class T>
string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
        res += to_string(x) + ' ';
    }
    return res;
}

template<class A>
void write(A x) {
    cout << to_string(x);
}

template<class H, class... T>
void write(const H &h, const T &... t) {
    write(h);
    write(t...);
}

void print() {
    write("\n");
}

template<class H, class... T>
void print(const H &h, const T &... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}
// Add syntax :
/* std::priority_queue<int> q; Example: 3 2 1
 * priority_queue<int, std::vector<int>, std::greater<int>> pq; Example :  1 2 3
 * push(), empty(), pop(), top(); sz(pq)
 */
//endregion

void solve() {
    int N, Q; read(N, Q);
    vi ID(N); read(ID);
    vt<vi> prefix_sum(3, vi(N+1));
    repi(3) {
        repj(N) {
            prefix_sum[i][j+1] = prefix_sum[i][j];
            if (ID[j] -1 == i) {
                prefix_sum[i][j+1]++;
            }
        }
    }
    repi(Q) {
        int a, b; read(a, b);
        repj(3) {
            cout << prefix_sum[j][b] - prefix_sum[j][a-1];
            if (j != 2) cout << ' ';
        }
        print();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("bcount.out","w",stdout);
    freopen("bcount.in","r",stdin);
    // freopen("tasks/input.txt", "r", stdin);
//    int t = 1;
//    read(t);
//    repi1(t){
        // write("Case #", i, ": ");
//        solve();
//    }
    solve();
    return 0;
}


//#include "exercise.hpp"
//
//ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
//
//void ContestExerciseImpl::main() {
//solve();
//
//}
