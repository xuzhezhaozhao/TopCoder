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
#define mkp make_pair

/*************** Program Begin **********************/
bool cubes[11][11][11];

class ShadowSculpture {
       public:
	string possible(vector<string> XY, vector<string> YZ,
		vector<string> ZX) {
		string impos = "Impossible";
		string pos = "Possible";

		int n = XY.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					cubes[i][j][k] = true;
				}
			}
		}

		// hack XY
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('N' == XY[i][j]) {
					for (int k = 0; k < n; k++) {
						cubes[i][j][k] = false;
					}
				}
			}
		}

		// hack YZ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('N' == YZ[i][j]) {
					for (int k = 0; k < n; k++) {
						cubes[k][i][j] = false;
					}
				}
			}
		}

		// hack ZX
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('N' == ZX[i][j]) {
					for (int k = 0; k < n; k++) {
						cubes[j][k][i] = false;
					}
				}
			}
		}
		bool ok = false;
		// check XY
		ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('Y' == XY[i][j]) {
					ok = false;
					for (int k = 0; k < n; k++) {
						if (cubes[i][j][k]) {
							ok = true;
						}
					}
					if (!ok) {
						return impos;
					}
				}
			}
		}

		// check YZ
		ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('Y' == YZ[i][j]) {
					ok = false;
					for (int k = 0; k < n; k++) {
						if (cubes[k][i][j]) {
							ok = true;
						}
					}
					if (!ok) {
						return impos;
					}
				}
			}
		}

		// check ZX
		ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ('Y' == ZX[i][j]) {
					ok = false;
					for (int k = 0; k < n; k++) {
						if (cubes[j][k][i]) {
							ok = true;
						}
					}
					if (!ok) {
						return impos;
					}
				}
			}
		}

		// check 6-connected
		// find first cube
		int f_i = -1, f_j = -1, f_k = -1;
		bool find = false;
		for (int i = 0; i < n; i++) {
			if (find) {
				break;
			}
			for (int j = 0; j < n; j++) {
				if (find) {
					break;
				}
				for (int k = 0; k < n; k++) {
					if (cubes[i][j][k]) {
						f_i = i;
						f_j = j;
						f_k = k;
						find = true;
						break;
					}
				}
			}
		}
		if (!find) {
			return pos;
		}
		int dx[] = {0, 0, -1};
		int dy[] = {0, -1, 0};
		int dz[] = {-1, 0, 0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (!cubes[i][j][k]) {
						continue;
					}
					if (i == f_i && j == f_j && k == f_k) {
						continue;
					}
					ok = false;
					// three faces
					for (int p = 0; p < 3; p++) {
						int nx = i + dx[p],
						    ny = j + dy[p],
						    nz = k + dz[p];
						if (nx < 0 || ny < 0 ||
						    nz < 0) {
							continue;
						}
						if (nx >= n || ny >= n ||
						    nz >= n) {
							continue;
						}
						if (cubes[nx][ny][nz]) {
							ok = true;
						}
					}
					if (!ok) {
						return impos;
					}
				}
			}
		}

		return pos;
	}
};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x) / sizeof(x[0]))
template <typename T>
void print(T a) {
	cerr << a;
}
static void print(long long a) { cerr << a << "L"; }
static void print(string a) { cerr << '"' << a << '"'; }
template <typename T>
void print(vector<T> a) {
	cerr << "{";
	for (int i = 0; i != a.size(); i++) {
		if (i != 0) cerr << ", ";
		print(a[i]);
	}
	cerr << "}" << endl;
}
template <typename T>
void eq(int n, T have, T need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}
template <typename T>
void eq(int n, vector<T> have, vector<T> need) {
	if (have.size() != need.size()) {
		cerr << "Case " << n << " failed: returned " << have.size()
		     << " elements; expected " << need.size() << " elements.";
		print(have);
		print(need);
		return;
	}
	for (int i = 0; i < have.size(); i++) {
		if (have[i] != need[i]) {
			cerr << "Case " << n << " failed. Expected and "
						"returned array differ in "
						"position " << i << ".";
			print(have);
			print(need);
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq(int n, string have, string need) {
	if (have == need) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print(need);
		cerr << " received ";
		print(have);
		cerr << "." << endl;
	}
}

int main(int argc, char* argv[]) {
	{
		string XYARRAY[] = {"YN", "NN"};
		vector<string> XY(XYARRAY, XYARRAY + ARRSIZE(XYARRAY));
		string YZARRAY[] = {"YN", "NN"};
		vector<string> YZ(YZARRAY, YZARRAY + ARRSIZE(YZARRAY));
		string ZXARRAY[] = {"YN", "NN"};
		vector<string> ZX(ZXARRAY, ZXARRAY + ARRSIZE(ZXARRAY));
		ShadowSculpture theObject;
		eq(0, theObject.possible(XY, YZ, ZX), "Possible");
	}
	{
		string XYARRAY[] = {"YN", "NY"};
		vector<string> XY(XYARRAY, XYARRAY + ARRSIZE(XYARRAY));
		string YZARRAY[] = {"YN", "NY"};
		vector<string> YZ(YZARRAY, YZARRAY + ARRSIZE(YZARRAY));
		string ZXARRAY[] = {"YN", "NY"};
		vector<string> ZX(ZXARRAY, ZXARRAY + ARRSIZE(ZXARRAY));
		ShadowSculpture theObject;
		eq(1, theObject.possible(XY, YZ, ZX), "Impossible");
	}
	{
		string XYARRAY[] = {"YYY", "YNY", "YYY"};
		vector<string> XY(XYARRAY, XYARRAY + ARRSIZE(XYARRAY));
		string YZARRAY[] = {"YYY", "YNY", "YYY"};
		vector<string> YZ(YZARRAY, YZARRAY + ARRSIZE(YZARRAY));
		string ZXARRAY[] = {"YYY", "YNY", "YYY"};
		vector<string> ZX(ZXARRAY, ZXARRAY + ARRSIZE(ZXARRAY));
		ShadowSculpture theObject;
		eq(2, theObject.possible(XY, YZ, ZX), "Possible");
	}
	{
		string XYARRAY[] = {"YYY", "YNY", "YYY"};
		vector<string> XY(XYARRAY, XYARRAY + ARRSIZE(XYARRAY));
		string YZARRAY[] = {"NYY", "YNY", "YYY"};
		vector<string> YZ(YZARRAY, YZARRAY + ARRSIZE(YZARRAY));
		string ZXARRAY[] = {"YYY", "YNY", "YYN"};
		vector<string> ZX(ZXARRAY, ZXARRAY + ARRSIZE(ZXARRAY));
		ShadowSculpture theObject;
		eq(3, theObject.possible(XY, YZ, ZX), "Impossible");
	}
	{
		string XYARRAY[] = {"N"};
		vector<string> XY(XYARRAY, XYARRAY + ARRSIZE(XYARRAY));
		string YZARRAY[] = {"N"};
		vector<string> YZ(YZARRAY, YZARRAY + ARRSIZE(YZARRAY));
		string ZXARRAY[] = {"N"};
		vector<string> ZX(ZXARRAY, ZXARRAY + ARRSIZE(ZXARRAY));
		ShadowSculpture theObject;
		eq(4, theObject.possible(XY, YZ, ZX), "Possible");
	}
	return 0;
}
// END CUT HERE
