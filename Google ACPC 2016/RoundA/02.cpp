#include <cassert>
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
#define mkp make_pair

int H[51][51];
int W[51][51];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open A-small-practice.in!\n");
		exit(-1);
	}
	if (!freopen("jam.out", "w", stdout)) {
		printf("Can't open out.txt\n");
		exit(-1);
	}
#endif

	int T;
	scanf("%d\n", &T);
	for (int casei = 0; casei < T; ++casei) {
		int R, C;
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				scanf("%d", &H[i][j]);
				W[i][j] = H[i][j];
			}
		}

		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				// do bfs from (r, c)
				int barrier = 1000000;
				bool visited[51][51] = { false };
				queue<pii> Q;
				Q.push(mkp(r, c));
				visited[r][c] = true;
				bool notzero = true;
				while (notzero && !Q.empty()) {
					auto pos = Q.front();
					Q.pop();
					int x = pos.first;
					int y = pos.second;
					for (int i = 0; i < 4; ++i) {
						for (int j = 0; j < 4; ++j) {
							int nx = x + dx[i], ny = y + dy[i];
							if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
								notzero = false;
								break;
							}
							if (visited[nx][ny]) {
								continue;
							}
							if (H[nx][ny] > H[r][c]) {
								barrier = min(barrier, H[nx][ny]);
							} else {
								visited[nx][ny] = true;
								Q.push(mkp(nx, ny));
							}
						}
						if (!notzero) {
							break;
						}
					}
				}
				if (!notzero) continue;
				for (int i = 0; i < R; ++i) {
					for (int j = 0; j < C; ++j) {
						if (!visited[i][j]) continue;
						W[i][j] = max(barrier, W[i][j]);
					}
				}
			}
		}

		int res = 0;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				res += W[i][j] - H[i][j];
			}
		}
		printf("Case #%d: %d\n", casei + 1, res);
	}
	
	return 0;
}