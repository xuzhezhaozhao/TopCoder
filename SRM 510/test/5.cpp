#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)

const int MOD = 1e9 + 7;
char Map[55][55];
bool v[55][55];
int R, C;
set < pair<int, int> > startGo;
set < pair<int, int> > SP, TP;
 
void up(int x, int y)
{
	if (x - 1 >= 0 && Map[x-1][y] != '#') {
		int nx = x - 1;
		int ny = y;
		if (!v[nx][ny]) {
			startGo.insert(mkp(nx, ny));
			SP.insert(mkp(nx, ny));
			v[nx][ny] = true;
		}
	}
}
void down(int x, int y)
{
	if (x + 1 < R && Map[x+1][y] != '#') {
		int nx = x + 1;
		int ny = y;
		if (!v[nx][ny]) {
			startGo.insert(mkp(nx, ny));
			SP.insert(mkp(nx, ny));

			v[nx][ny] = true;
		}
	}
}
void left(int x, int y)
{
	if (y - 1 >= 0 && Map[x][y-1] != '#') {
		int nx = x;
		int ny = y - 1;
		if (!v[nx][ny]) {
			startGo.insert(mkp(nx, ny));
			SP.insert(mkp(nx, ny));

			v[nx][ny] = true;
		}
	}
}
void right(int x, int y)
{
	if (y + 1 < C && Map[x][y+1] != '#') {
		int nx = x;
		int ny = y + 1;
		if (!v[nx][ny]) {
			startGo.insert(mkp(nx, ny));
			SP.insert(mkp(nx, ny));

			v[nx][ny] = true;
		}
	}
}

void up2(int x, int y)
{
	if (x - 1 >= 0) {
		int nx = x - 1, ny = y;
		char c = Map[nx][ny];
		if (c == '+' || c == '|' || c == '.') {
			if (!v[nx][ny]) {
				startGo.insert(mkp(nx, ny));
				TP.insert(mkp(nx, ny));

				v[nx][ny] = true;
			}
		}
	}
}
void down2(int x, int y)
{
	if (x + 1 < R) {
		int nx = x + 1, ny = y;
		char c = Map[nx][ny];
		if (c == '+' || c == '|') {
			if (!v[nx][y]) {
				startGo.insert(mkp(nx, ny));
				TP.insert(mkp(nx, ny));
				v[nx][ny] = true;
			}
		}
	}
}
void left2(int x, int y)
{
	if (y - 1 >= 0) {
		int nx = x, ny = y - 1;
		char c = Map[nx][ny];
		if (c == '+' || c == '-') {
			if (!v[nx][ny]) {
				startGo.insert(mkp(nx, ny));
				TP.insert(mkp(nx, ny));
				v[nx][ny] = true;
			}
		}
	}
}
void right2(int x, int y)
{
	if (y + 1 < C) {
		int nx = x, ny = y + 1;
		char c = Map[nx][ny];
		if (c == '+' || c == '-') {
			if (!v[nx][ny]) {
				startGo.insert(mkp(nx, ny));
				TP.insert(mkp(nx, ny));

				v[nx][ny] = true;
			}
		}
	}
}

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	cin >> R >> C;
	getchar();
	for (int i = 0; i < R; i++) {
			scanf("%s\n", Map[i]);
	}
	memset(v, 0, sizeof(v));
	 
	pair<int, int> startP, endP;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == 'S') {
				v[i][j] = true;
				startP.first = i;
				startP.second = j;
				Map[i][j] = '+';
			} else if (Map[i][j] == 'T') {
				endP.first = i;
				endP.second = j;
			}
		}
	}
	// bfs
	startGo.insert(startP);
	SP.insert(startP);

	pair <int, int> cur;
	char c;
	while (!startGo.empty()) {
		cur = *startGo.begin();
		startGo.erase(startGo.begin());
		int x = cur.first, y = cur.second;
		v[x][y] = true;
		c = Map[x][y];
		switch (c) {
			case '#':
				break;
			case '+':
				up(x, y); down(x, y); left(x, y); right(x, y);
				break;
			case '-':
				left(x, y); right(x, y);
				break;
			case '|':
				up(x, y); down(x, y);
				break;
			case '.':
				down(x, y);
				break;
			case 'T':
				up(x, y); down(x, y); left(x, y); right(x, y);
				break;
		}
	}

	if (!v[endP.first][endP.second]) {
		printf("I'm stuck!");
		return 0;
	}

	// bfs
	memset(v, 0, sizeof(v));
	startGo.clear();
	startGo.insert(endP);
	TP.insert(endP);
	while (!startGo.empty()) {
		cur = *startGo.begin();
		startGo.erase(startGo.begin());
		int x = cur.first, y = cur.second;
		up2(x, y); down2(x, y); left2(x, y); right2(x, y);
	}

	int res = 0;
	for (set < pair<int, int> >::iterator it = SP.begin(); it != SP.end(); it++) {
		if ( TP.find( (*it) ) == TP.end() ) {
			++res;
		}
	}
	cout << res;

	return 0;
}
