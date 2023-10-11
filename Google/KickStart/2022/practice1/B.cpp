//region Folding
/*
  Fri Feb 18 17:12:51 RST 2022
  @author: Night Fury
*/
 
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

template<class T>
string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
        res += to_string(x) + '\n';
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
//endregion

void solve() {
    string S; cin >> S;
    char last_char = S[sz(S) - 1];
    string ans ;
    if (last_char == 'y' || last_char == 'Y') {
        ans = "nobody.";
    } else if (count( all(vowels), last_char ) ) {
        ans = "Alice.";
    } else ans = "Bob.";
    print(S, "is ruled by", ans);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    read(t);
    repi1(t){
        write("Case #", i, ": ");
        solve();
    }
    return 0;
}

