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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/

class PalindromePermutations {
public:
    double palindromeProbability(string word) {
        double res = 1.0;
	int N = word.size();
	int cnt[27];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < N; i++) {
		++cnt[word[i] - 'a'];
	}
	if (N % 2 != 0) {	// ÆæÊý
		int c = 0, m;
		for (int i = 0; i < 27; i++) {
			if (cnt[i] % 2 != 0) {
				++c;
				m = i;
			}
		}
		if (c != 1) {
			return 0.0;
		}
		res = cnt[m] * 1.0 / N;
		--cnt[m];
		--N;
	}
	if (0 == N) {
		return 1.0;
	}
	for (int i = 0; i < 27; i++) {
		if (cnt[i] % 2 != 0) {
			return 0.0;
		}
	}
	
	double a = 1.0, b = 1.0;
	for (int i = 0; i < 27; i++) {
		if (cnt[i]) {
			for (int j = (cnt[i] / 2 + 1); j <= cnt[i]; j++) {
				a *= j;
			}
		}
	}
	for (int i = N / 2 + 1; i <= N; i++) {
		b *= i;
	}
	res *= a / b;
        return res;
    }

};

/************** Program End ************************/

