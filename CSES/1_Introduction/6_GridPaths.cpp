#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/nightfury/mycp/debug.h"
#else
#define dbg(...) 42
#endif

int ans = 0;
string s;

string dir = "URLD";
map<char,int> mdir = {
	{'U', 0},
	{'R', 1},
	{'L', 2},
	{'D', 3},
};

int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

int N = 7;
//2 - 3 : N*N - 1
//3 ->8


bool valid(int x, int y){
	return (x>=0 && x<N && y>=0 && y<N);
}

bool ok(int x, int y, vector<vector<bool>>& visited){
	return valid(x, y) && !visited[x][y];
}

bool dead(int x, int y, vector<vector<bool>>& visited){
	return !valid(x, y) || (valid(x,y) && visited[x][y]);
}

pair<int,int> next_x_y(int x, int y, char next_dir) {
	int idx = mdir[next_dir];
	return { x + dx[idx], y + dy[idx]};
}

int count_nei(int x, int y, vector<vector<bool>>& visited) {
	int cnt = 0;
	for (int i=0; i<4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx,ny) && visited[nx][ ny]) {
			cnt++;
		}
	}
	return cnt;

}

void res(string cur, vector<vector<bool>> visited, int x, int y){
	// arg: visited, current idx, 
	// cont stop:
	// - end not bottom left
	// - meet end before hand
	// - go to a cell visited
	//cout << x << ' ' << y << '\n';
	if (!valid(x, y)) return;
	if (x == 0 && y == N-1 && cur.size() == N*N-1){
		ans++;
		//cout << cur << '\n';
		return;
	}
	visited[x][y]=true;
	if (cur.size() > 0){
		for (string gg: { "UDRL"s, "RLDU"s,}){
			char u, d, r, l;
			u = gg[0], d=gg[1], r=gg[2], l=gg[3];
			auto [down_x, down_y] = next_x_y(x, y, d);
			auto [up_x, up_y] = next_x_y(x, y, u);
			if (dead(down_x, down_y, visited) && dead(up_x, up_y, visited)){
				auto [rx,ry] = next_x_y (x, y, r);
				auto [lx,ly] = next_x_y (x, y, l);
				if (ok(rx, ry, visited) && ok(lx, ly, visited)) {
					//dbg("HEY!", cur, cd);
					return;
				}
			}
		}
	}

	// if 1 of the 3 has 3 visited => must choose
	for(int j=0; j<4; j++) {
		char nd = dir[j];
		int nx = x + dx[j], ny = y + dy[j];
		if (valid(nx, ny) && !visited[nx][ny]) {
			if (nx == 0 && ny == N-1 && cur.size() != N*N-2)  continue;
			int i = cur.size();

			if (3 == count_nei(nx, ny, visited)) {
				if (s[i] == '?' || s[i] == nd) {
					res(cur + nd, visited, nx, ny);
					return;
				}
			}

		}
	}


	for(int j=0; j<4; j++) {
		char nd = dir[j];
		int nx = x + dx[j], ny = y + dy[j];
		if (valid(nx, ny) && !visited[nx][ny]) {
			if (nx == 0 && ny == N-1 && cur.size() != N*N-2)  continue;
			int i = cur.size();
			if (s[i] == '?' || s[i] == nd) {
				res(cur + nd, visited, nx, ny);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	//s = "????????"
	vector<vector<bool>> vis(N, vector<bool>(N));
	res("", vis, 0, 0);
	cout << ans << '\n';
	return 0;
}
