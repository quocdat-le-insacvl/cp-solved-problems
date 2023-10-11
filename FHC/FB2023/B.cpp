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
#define repi1(n) for (int i=1; i < (int)(n); ++i)
#define repj1(n) for (int j=1; j < (int)(n); ++j)
#define repk1(n) for (int k=1; k < (int)(n); ++k)
#define rep1(i, n) for (int i=1; i < (int)(n); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vt vector
#define pb push_back
#define rsz resize
#define EACH(x, a) for (auto& x: a)
#define f first
#define s second
#define MIN_LL -1000000000000000000ll
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> pii;
typedef vt<int> vi;
typedef vt<ll> vll;
typedef vt<vll> vvll;
typedef vt<bool> vb;
typedef vt<vi> vvi;
typedef vt<vt<bool>> vvb;
typedef vt<char> vc;
typedef vt<vt<char>> vvc;
typedef vt<pii> vpii;
const std::string MIN_A_TO_Z = "abcdefghijklmnopqrstuvwxyz";
const std::string MAJ_A_TO_Z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ZERO_NINE = "0123456789";
const std::string SPECIAL_CHARACTERS = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const vt<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


int max(int a, int b, int c) {
    return max(max(a, b), c);
}

ll max(ll a, ll b, ll c) {
    return max(max(a, b), c);
}

void read(int &k) {
    cin >> k;
}

void read(ll &k) {
    cin >> k;
}

void read(double &k) {
    cin >> k;
}

void read(string &k) {
    cin >> k;
}

void read(deque<int> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vt<int> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vll &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vt<string> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vt<char> &k) {
    EACH(x, k) {
        cin >> x;
    }
}

void read(vpii &k) {
    EACH(x, k) {
        cin >> x.first >> x.second;
    }
}

void read(vvi &k) {
    EACH(x, k) {
        EACH(a, x) {
            cin >> a;
        }
    }
}

vi read_line() {
    stringstream SS;
    string s;
    getline(cin, s);
    SS << s;
    vi A;
    int k;
    while (SS >> k) A.push_back(k);
    return A;
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

void print(vvc &h) {
    EACH(r, h) {
        EACH(x, r) {
            cout << x;
        }
        cout << '\n';
    }
}

void print(vvb &h) {
    EACH(r, h) {
        repi(sz(r)) {
            cout << r[i];
        }
        cout << '\n';
    }
    cout << '\n';
}

void print(vvi &h) {
    EACH(r, h) {
        if (sz(r) == 0) cout << '_' << '\n';
        else
            EACH(x, r) {
                if (x == INF)
                    cout << "_ ";
                else {
                    if (x < 10) {
                        cout << ' ';
                    }
                    cout << x << ' ';
                }
            }
        cout << '\n';
    }
}

void print(vvll &h) {
    EACH(r, h) {
        if (sz(r) == 0) cout << '_' << '\n';
        else
            EACH(x, r) {
                cout << x << ' ';
            }
        cout << '\n';
    }
}

template<class H, class... T>
void print(const H &h, const T &... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}


#define MOD 1000000007

void solve() {
    ll P; read(P);
    int S = 41;
    //if (P > 10e7) {
        //print(-1);
        //return;
    //}
    //vll dist(10e5, 1);
    //set<ll> dist;
    vi divide;
    rep(i, 1, 42) {
        if(P % i == 0) {
            divide.push_back(i);
        }
    }

    set<tuple<ll, int, multiset<int>>> A;
    // Product, Sum
    dbg(divide);
    rep(j_, 0, sz(divide)){
        dbg(sz(A));
        int j = divide[j_];
        multiset v= {j};
        A.insert({P/j, j, v});
    }
    //vi done;
    rep(i_, 0, sz(divide)){
        int i = divide[i_];
        rep(j_, 0, sz(divide)){
            int j = divide[j_];
            //dbg(j, done);
            multiset v= {j};
            auto B = A;
            int init_size = sz(A);
            EACH(x, B) {
                auto [p, s, v] = x;
                s += j;
                if (s <= S && p % j == 0) {
                    //v.push_back(j);
                    v.insert(j);
                    //int init_size = sz(A);
                    A.insert({p/j, s, v});
                    //if (init_size == sz(A)){
                        //dbg(init_size, sz(A));
                    //}
                }
            }
            print(init_size == sz(A));
        }
        
    }
    multiset<int> ans ;
    bool not_set = true;
     EACH(x, A){
        auto [p, s, v] = x;
        if ((p == 1) && (s == S) ) {
            dbg(p, s, v);
            if (not_set){
                not_set = false;
                ans = v;
            } else {
                if (sz(v) < sz(ans)) {
                    ans = v;
                }
            }
        }
    }
     if (sz(ans) == 0) {
         print(-1);
         return;
     }
    vi ANS;
    EACH(x, ans){
        ANS.push_back(x);
    }
    print(sz(ans), ANS);
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    read(t);
    repi1(t+1){
         write("Case #", i, ": ");
        solve();
    }
    return 0;
}


