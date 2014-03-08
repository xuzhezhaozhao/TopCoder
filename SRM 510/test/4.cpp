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
// 求 C[N][k]
const int MAX_N = 1005;
long long C[MAX_N][MAX_N];

// 计算二项式系数
void calc()
{
	memset(C, 0, sizeof(C));
	for (int i = 1; i < MAX_N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= MOD;
		}
	}
}
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	calc();
	long long res = 0;
	for (int i = 2; i <= n - 2; i++) {		// 0, 1的个数i
		long long t01 = i - 1;				// 0,1 排列种数
		long long t23 = (n - i - 1);		// 2,3排列种数
		res += ( ( C[n - 1][i] * t01 * t23 ) % MOD );	// 首位一定是2
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}