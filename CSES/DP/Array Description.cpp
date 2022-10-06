//region Folding
/*
  Tue Oct  4 21:23:42 CEST 2022
  @author: Night Fury
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MOD 1000000007;
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
#define EACH(x, a) for (auto& x: a)
#define x first
#define y second
#define MIN_LL -1000000000000000000ll
#define INF 999999999
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

bool sortByCond(const pair<int, int> &a,
                const pair<int, int> &b) {
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second < b.second);
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

void print(vvi &h) {
    EACH(r, h) {
        if (sz(r) == 0) cout << '_';
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

void display(const vvll &d) {
    EACH(row, d) {
        EACH(k, row) {
            if (k == MIN_LL) {
                cout << "--" << ' ';
            } else {
                cout << k << ' ';
                if (k >= 0 && k < 10) cout << ' ';
            }
        }
        print();
    }
    print("---------------------");
}

class Numeric {
public:
    vll max_div;

    void init(ll MAX_N = 20) {
        max_div.resize(MAX_N + 1);
        for (ll i = 2; i <= MAX_N; i++) {
            if (max_div[i] == 0) {
                for (ll j = i; j <= MAX_N; j += i) {
                    max_div[j] = i;
                }
            }
        }
    }

    int no_memory_number_divisors(ll n) {
        int div_num = 0;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                div_num += i * i == n ? 1 : 2;
//                print(i);
            }
        }
        return div_num;
    }

    int number_divisors(ll n) {
        int ans = 1;
        while (n != 1) {
            /* 12 = 2^2 * 3^ 1
             * => ans = (2 + 1) * (1 + 1)
             */
            ll time = 0;
            ll k = max_div[n];
            while (n % k == 0) {
//                print(n, k);
                n /= k;
                time++;
            }
            ans *= time + 1;
        }
        return ans;
    }

    void solve() {
        ll N;
        read(N);
        N += 4;
//        init(N + 4);
//        ll ans = number_divisors(N);
//        ll ans = countDivisors(N);
//        print(N);
        int ans = no_memory_number_divisors(N);
        print(ans);
        ans -= 2;
        if (N % 2 == 0) ans -= 2;
//        if ((ll)sqrt(N) * (ll) sqrt(N) == N ) ans +=2;
        print((int) ans / 2);
    }
};

class Graph {
public :
    struct edge {
        int from;
        int to;
        int cost;
    };
    vector<bool> visited;
    vector<edge> edges;
    vector<vector<int>> g;
    vector<int> values;
    vector<vector<int>> paths;
    int nv; // number of vertexes
    Graph(int num_vertex) : nv(num_vertex) {
        g.resize(nv);
        visited.resize(nv);
    }

    void add_edge(int from, int to, int cost = 1, int directed = false) {
        edge new_edge{from, to, cost};
        edges.push_back(new_edge);
        g[from].push_back(to);
        if (!directed) {
            add_edge(to, from, cost, true);
        }
    }

    void print_edges() {
        cout << "List of edges of " << nv << " vertexes:" << '\n';
        for (auto e: edges) {
            cout << "(" << e.from << " -> " << e.to << ") | " << e.cost << '\n';
        }
    }

    void read_edges(int M) {
        repi(M) {
            int a, b;
            read(a, b);
            add_edge(a - 1, b - 1);
        }
    }

    void add_value(int value) {
        values.push_back(value);
    }

    void bfs(int from, int to, bool tracking = false, bool debug = false) {
        queue<int> q;
        vector<int> d(nv), p(nv);

        q.push(from);
        visited[from] = true;
        p[from] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v == to) {
                print(d[v] + 1);
                // backtracking
                if (!tracking) return;
                vi path;
                path.pb(v + 1);
                while (p[v] != -1) {
                    path.pb(p[v] + 1);
                    v = p[v];
                }
                reverse(all(path));
                print(path);
                return;
            }

            for (int u: g[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
        if (debug) {
            for (int i: p) {
                cout << i << ' ';
            }
            cout << '\n';
        }
        if (tracking) print("IMPOSSIBLE");
    }

    void all_shortest_path(bool debug = false) {
        paths.resize(nv, vector<int>(nv));
        for (auto &v: paths) {
            fill(v.begin(), v.end(), INF);
        }
        for (int i = 0; i < nv; i++) paths[i][i] = 0;
        for (edge e: edges) {
            paths[e.from][e.to] = e.cost;
        }
        for (int k = 0; k < nv; ++k) {
            for (int i = 0; i < nv; ++i) {
                for (int j = 0; j < nv; ++j) {
                    if (paths[i][k] < INF && paths[k][j] < INF)
                        paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
                }
            }
        }
        if (debug) {
            cout << "  | ";
            for (int i = 0; i < nv; i++) cout << i << ' ';
            cout << '\n';
            for (int i = 0; i < nv; i++) cout << "--";
            cout << '\n';
            // ************************************
            for (int i = 0; i < nv; i++) {
                cout << i << " | ";
                for (int j = 0; j < nv; j++) {
                    cout << paths[i][j] << ' ';
                }
                cout << '\n';
            }
            // ************************************
        }
    }

    void dfs(int from) {
        fill(all(visited), false);
        stack<int> stack;
        stack.push(from);
        while (!stack.empty()) {
            int s = stack.top();
            stack.pop();
            if (visited[s]) continue;
            visited[s] = true;
            for (int &i: g[s]) {
                if (!visited[i]) {
                    stack.push(i);
                }
            }
        }
    }

    int number_connected_components(bool building_road = false) {
        stack<int> stack;
        vi roads;
        int count = 0;
        repi(nv) {
            if (!visited[i]) {
                int next = i;
                count++;
                roads.pb(i);
                stack.push(next);
                while (!stack.empty()) {
                    int s = stack.top();
                    stack.pop();
                    if (!visited[s]) {
                        visited[s] = true;
                    }
                    for (int &j: g[s])
                        if (!visited[j])
                            stack.push(j);
                }
            }
        }
        if (building_road) {
            print(count - 1);
            repi(sz(roads) - 1) {
                print(roads[i] + 1, roads[i + 1] + 1);
            }
        }

        return count;
    }
};

class Graph2D {
public :
    vvc g;
    vvb visited;
    vt<vpii> tracking;
    vvc dir;

    constexpr static const int di[] = {1, 0, -1, 0};
    constexpr static const int dj[] = {0, 1, 0, -1};
    constexpr static const int ldi[] = {1, 0};
    constexpr static const int ldj[] = {0, 1};
    string dc = "DRUL";
//    vi di, dj;
    int N, M;

    Graph2D(int n, int m) {
        // init
        N = n;
        M = m;
        g.resize(N, vc(M));
        visited.resize(N, vb(M));
//        tracking.resize(N, vpii(M));
//        dir.resize(N, vc(M, '_'));
        // read
        repi(N) {
            vc row;
            repj(M) {
                char c;
                cin >> c;
                g[i][j] = c;
            }
        }
        solve();
    }

    void solve() {

    }

    void dfs(int i, int j) {
        visited[i][j] = true;
//        g[i][j] = '_';
//        print_graph();
//        print();
//        print();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (is_valid(ni, nj)) {
                if (g[ni][nj] == '.' && !visited[ni][nj]) {
                    dfs(ni, nj);
                }
            }
        }
    }

    bool bfs(int si, int sj) {
        int i = si, j = sj;
        queue<pii> q;
        q.push({i, j});

        visited[i][j] = true;

        while (!q.empty()) {
            // Pop data
            i = q.front().first;
            j = q.front().second;

            q.pop();

            if (g[i][j] == 'B') {
                print("YES");
                string paths;
                int ni = i, nj = j;
                while (ni != si || nj != sj) {
                    paths += dir[ni][nj];
                    pii PP = tracking[ni][nj];
                    ni = PP.x, nj = PP.y;
                }
                print(sz(paths));
                reverse(all(paths));
                print(paths);
                return true;
            }

            // Loop next
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                    if ((g[ni][nj] == '.' || g[ni][nj] == 'B') && !visited[ni][nj]) {
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                        tracking[ni][nj] = {i, j};
                        dir[ni][nj] = dc[k];
                    }
                }
            }
        }
        return false;
    }

    ll S = 0, P = 0;

    void dfs_area_perimeter(int i, int j) {
        visited[i][j] = true;
        S++;
        int max_perimeter = 4;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (is_valid(ni, nj)) {
                if (g[ni][nj] == '#') {
                    max_perimeter--;
                }
                if (g[ni][nj] == '#' && !visited[ni][nj]) {
                    dfs_area_perimeter(ni, nj);
                }
            }
        }
        P += max_perimeter;
    }

    bool is_valid(int i, int j) const {
        return i >= 0 && i < N && j >= 0 && j < M;
    }

    int count_rooms() {
        int count = 0;
        repi(N) {
            repj(M) {
                if (g[i][j] == '.' && !visited[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }

    void print_graph() {
        EACH(row, g) print(row);
    }
};

class Tree {
public:
    vvi children;
    vi subtree_size, depth;
    int N;

    Tree(int n) {
        N = n;
        children.resize(n);
        depth.resize(n);
        solve();
    }

    void read_tree() {
        repi1(N) {
            int parent;
            read(parent);
            parent--;
            // this node is the parent of node i ...
            children[parent].push_back(i);
        }
    }

    void read_graph() {
        repi1(N) {
            int a, b;
            read(a, b);
            a--;
            b--;
            children[a].pb(b);
            children[b].pb(a);
        }
    }

    void dfs_size(int node) {
        if (node == 0) {
            subtree_size.resize(N);
        }
        subtree_size[node] = 1;
        for (int child: children[node]) {
            depth[child] = depth[node] + 1;
            dfs_size(child);
            subtree_size[node] += subtree_size[child];
        }
    }

    int dis = 0;
    int mx_node = 0;

    void dfs(int node, int pre) {
        EACH(child, children[node]) {
            if (child == pre) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
        int d = depth[node];
        if (d > dis) {
            dis = d;
            mx_node = node;
        }
    }

    void solve() {
        //read_tree();
        read_graph();
        dfs(0, -1);
        dis = 0;
        fill(all(depth), 0);
        dfs(mx_node, -1);
        print(dis);
    }
};
// Add syntax :
/* std::priority_queue<int> q; Example: 3 2 1
 * priority_queue<int, std::vector<int>, std::greater<int>> pq; Example :  1 2 3
 * push(), empty(), pop(), top(); sz(pq)
 *
 * Fill by 0:    fill(all(v), 0);
 *///endregion
/*
3 5
2 0 2
3 5
0 0 2
*/


void solve() {
    int N;
    read(N);
    int M;
    read(M);
    auto is_valid = [&] (int i, int j){
        return i >= 0 && i < N && j >= 0 && j < M;
    };
    vi A(N); read(A);
    vvll dp(N, vll(M));
    repi(N){
        if (i==0) {
            if (A[i] != 0) {
                dp[i][A[i] - 1] = 1;
            } else {
                fill(all(dp[i]), 1);
            }
        } else {
            if (A[i] != 0) {
                int val = A[i] - 1;
                for (int di : {-1, 0, 1} ){
                    int ni = i - 1;
                    int nj = val + di;
                    if (is_valid(ni, nj)){
                        dp[i][val] += dp[ni][nj] % MOD;
                        dp[i][val] %= MOD;
                    }
                }
            } else{
                rep(val, 0, M) {
                    for (int di : {-1, 0, 1} ){
                        int ni = i - 1;
                        int nj = val + di;
                        if (is_valid(ni, nj)){
                            dp[i][val] += dp[ni][nj] % MOD;
                            dp[i][val] %= MOD;
                        }
                    }
                }
            }
        }
    }

//    print(dp);
    int last = A[N-1];
    if (last != 0)
    print(dp[N-1][last-1]);
    else {
        ll sum = 0;
        EACH(x, dp[N-1]) {
            sum += x;
            sum %= MOD;
        }
        print(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    //freopen("bcount.out","w",stdout);
    //freopen("bcount.in","r",stdin);
    //freopen("../tasks/input.txt", "r", stdin);
    int t = 1;
    //read(t);
    repi1(t + 1) {
        // write("Case #", i, ": ");
        solve();
    }
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
