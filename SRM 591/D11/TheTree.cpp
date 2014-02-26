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

class TheTree {
public:
	int maximumDiameter(vector <int> cnt)
	{
		int res = 0;
		int D = cnt.size();

		for (int cur = 0; cur < D; cur++) {
			int maxL = 0, maxR = 0;
			for (int i = cur; i < D; i++) {
				maxR = D - cur;
				if (cnt[i] == 1) {
					break;
				} else {
					++maxL;
				}
			}

			res = max(res, maxL + maxR);
		}
		return res;
	}
};
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	{
		int skillARRAY[] = {3};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		TheTree theObject;
		cout << theObject.maximumDiameter(skill) << " need: 2" << endl;
	}
	{
		int skillARRAY[] = {2, 2};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		TheTree theObject;
		cout << theObject.maximumDiameter(skill) << " need: 4" << endl;
	}
	{
		int skillARRAY[] = {4, 1, 2, 4};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		TheTree theObject;
		cout << theObject.maximumDiameter(skill) << " need: 5" << endl;
	}
	{
		int skillARRAY[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		TheTree theObject;
		cout << theObject.maximumDiameter(skill) << " need: 21" << endl;
	}
	return 0;
}
