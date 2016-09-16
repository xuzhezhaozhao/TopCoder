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

const int MOD = 1000000007;

long long PowerMod(long long a, long long b, long long c)
{
	long long ans = 1;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans % c;
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open jam.in!\n");
		exit(-1);
	}
	FILE * f = NULL;
	f = freopen("jam.out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	for (int casei = 0; casei < T; ++casei) {
		long long N, L1, R1, A, B, C1, C2, M;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
		vector<long long> x, y;
		vector<pii> intervals;
		x.push_back(L1);
		y.push_back(R1);
		long long L = min(x.back(), y.back());
		long long R = max(x.back(), y.back());
		intervals.push_back(mkp(L, R));

		for (int i = 2; i <= N; i++) {
			int a = x.back();
			int b = y.back();
			x.push_back((A * a + B * b + C1) % M);
			y.push_back((A * b + B * a + C2) % M);
			long long L = min(x.back(), y.back());
			long long R = max(x.back(), y.back());
			intervals.push_back(mkp(L, R));
		}

		sort(intervals.begin(), intervals.end());
		auto g_L = intervals[0].first;
		auto g_R = intervals[0].second;
		long long mxd = 0;
		long long curd = g_R - g_L + 1;
		long long total = curd;

		long long pre_L = -1LL, pre_R = -1LL;
		for (int i = 1; i < N; i++) {
			auto L = intervals[i].first;
			auto R = intervals[i].second;
			L = max(L, g_L);

			auto len = R - L + 1;
			if (len <= 0) {
				continue;
			}

			if (R <= g_R) {
				// case 1: 包含关系
				if (pre_L == -1) {
					pre_L = L;
					pre_R = R;
					curd -= len;
					continue;
				}
				// 判断 (L, R) 与 (pre_L, pre_R) 关系
				if (R <= pre_R) {
					// 包含
					// do nothing
				} else if (L <= pre_R) {
					// 交叉
					curd -= R - pre_R;
					pre_R = R;
				} else {
					// 分离
					curd -= len;
					pre_L = L;
					pre_R = R;
				}
			} 
			else if (L <= g_R) {
				// case 2: 交叉关系
				total += R - g_R;
				// 判断 (L, R) 与 (pre_L, pre_R) 关系
				if (R <= pre_R) {
					// 包含
					// never happen
				} else if (L <= pre_R) {
					// 交叉
					curd -= g_R - pre_R;
				} else {
					// 分离
					curd -= g_R - L + 1;
				}
				// R > g_R
				// 开始新的 g_L, g_R
				g_L = g_R + 1;
				g_R = R;
				pre_L = -1;
				pre_R = -1;
				mxd = max(mxd, curd);
				curd = g_R - g_L + 1;
			}
			else {
				// case 3: 不相交
				total += len;
				// 开始新的 g_L, g_R
				g_L = L;
				g_R = R;
				pre_L = -1;
				pre_R = -1;
				mxd = max(mxd, curd);
				curd = g_R - g_L + 1;
			}
		}
		mxd = max(mxd, curd);

		long long res = total - mxd;
		printf("Case #%d: %lld\n", casei + 1, res);
	}
	
	return 0;
}