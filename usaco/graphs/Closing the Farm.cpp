//region Folding
/*
  Mon Sep 26 11:35:23 CEST 2022
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
typedef long long ll;
typedef pair<int, int> pii;
typedef vt<int> vi;
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

template<class H, class... T>
void print(const H &h, const T &... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

#define INF 999999999

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

    int nodes = 0;
    vb closed;

    void solve(vi ord) {
        closed.resize(nv);
        stack<int> stack;
        dfs(0);
        vb ans;
        if (nodes == nv) ans.pb(1);
        else ans.pb(0);
        repi(nv) {
            closed[ord[i]] = true;
            dfs(ord[nv - 1]);
            if (nodes == nv - i - 1) ans.pb(1);
            else ans.pb(0);
//            print(nodes);
//            print(nv-i-1);
        }
        repi(sz(ans)-1) {
            if (ans[i]) print("YES");
            else print("NO");
        }
    }

    void dfs(int from) {
        fill(all(visited), false);
        nodes = 0;
        stack<int> stack;
        stack.push(from);
//        vector<int> path; path.push_back(from);
        while (!stack.empty()) {
            int s = stack.top();
            stack.pop();
            if (closed[s] || visited[s]) continue;
            nodes++;
            visited[s] = true;
            for (int &i: g[s]) {
                if (!visited[i] && !closed[i]) {
                    stack.push(i);
//                    print(i);
                }
            }
        }
    }

    bool is_fully_connected(bool building_road = false) {
        stack<int> stack;
        vi roads;
        int count = 0;
        repi(nv) {
            if (!visited[i]) {
                int next = i;
                count++;
                if (count >= 2) {
                    return false;
                }
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

        return true;
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
    string dc = "DRUL";
//    vi di, dj;
    int N, M;

    Graph2D(int n, int m) {
        // init
        N = n;
        M = m;
        g.resize(N, vc(M));
        visited.resize(N, vb(M));
        tracking.resize(N, vpii(M));
        dir.resize(N, vc(M, '_'));
        // read
        repi(N) {
            vc row;
            repj(M) {
                char c;
                cin >> c;
                g[i][j] = c;
            }
        }
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
            if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
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
                    pii P = tracking[ni][nj];
                    ni = P.x, nj = P.y;
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
// Add syntax :
/* std::priority_queue<int> q; Example: 3 2 1
 * priority_queue<int, std::vector<int>, std::greater<int>> pq; Example :  1 2 3
 * push(), empty(), pop(), top(); sz(pq)
 */
//endregion

void solve() {
    int N, M;
    read(N, M);
    Graph g(N);
    g.read_edges(M);
    vi ord(N);
    repi(N) {
        cin >> ord[i];
        ord[i]--;
    }
    g.solve(ord);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    freopen("closing.out","w",stdout);
    freopen("closing.in","r",stdin);
    // freopen("tasks/input.txt", "r", stdin);
    int t = 1;
//    read(t);
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
