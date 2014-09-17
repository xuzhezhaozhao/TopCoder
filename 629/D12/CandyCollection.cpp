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
int dp[2][2][2001];
vector <int> loop;
bool used[2001];

class CandyCollection {
public:
	int N;
	vector <int> Number1;
	vector <int> Number2;
	vector <int> Type1;
	vector <int> Type2;
	int rec(int first, int pre, int pos) {
		if (loop.empty()) {
			return 0;
		}
		// base case
		int & res = dp[first][pre][pos];
		if (res != -1) {
			return res;
		}
		int x = loop[pos];
		int n1 = Number1[x];
		int n2 = Number2[x];
		if (pos == (int)loop.size() - 1) {
			if (pre == 0) {
				if (first == 0) {
					res = max(n1, n2) + 1;		
				} else {
					res = n2 + 1;
				}
			} else {
				// pre == 1
				if (first == 0) {
					res = n1 + 1;
				} else {
					res = 0;
				}
			}
			return res;
		}

		res = 200000000;
		if (pos == 0) {
			// don't choose the first sharp
			res = min(res, rec(0, 0, pos + 1));

			if (n1 > n2) {
				res = min(res, n2 + 1 + rec(1, 0, pos + 1));
				res = min(res, n1 + 1 + rec(1, 1, pos + 1));
			} else if (n1 < n2) {
				res = min(res, n1 + 1 + rec(0, 1, pos + 1));
				res = min(res, n2 + 1 + rec(1, 1, pos + 1));
			} else {
				// n1 == n2
				res = min(res, n1 + 1 + rec(1, 1, pos + 1));
			}
		} else {
			if (pre == 0) {
				// must choose this sharp
				if (n1 > n2) {
					res = min(res, n2 + 1 + rec(first, 0, pos + 1));
					res = min(res, n1 + 1 + rec(first, 1, pos + 1));
				} else {
					// n1 <= n2
					res = min(res, n2 + 1 + rec(first, 1, pos + 1));
				}
			} else {
				// pre == 1
				// not choose
				res = min(res, rec(first, 0, pos + 1));
				
				// choose
				res = min(res, n1 + 1 + rec(first, 1, pos + 1));
			}
		}
		return res;
	}

	void dfs(int v) {
		int t = Type2[v];
		for (int i = 0; i < N; i++) {
			if (used[i]) {
				continue;
			}

			if (Type1[i] == t) {
				// no swap
				loop.push_back(i);
				used[i] = true;
				dfs(i);
				break;
			}
			if (Type2[i] == t) {
				// swap
				swap(Number1[i], Number2[i]);
				swap(Type1[i], Type2[i]);
				loop.push_back(i);
				used[i] = true;
				dfs(i);
				break;
			}
		}
	}

	int solve(vector <int> _Type1, vector <int> _Number1, vector <int> _Type2, vector <int> _Number2) {
		int res = 0;
		N = _Type1.size();
		this->Number1 = _Number1;
		this->Number2 = _Number2;
		this->Type1 = _Type1;
		this->Type2 = _Type2;

		memset(used, 0, sizeof(used));
		loop.clear();

		for (int i = 0; i < N; i++) {
			if (!used[i]) {
				// begin a loop
				memset(dp, -1, sizeof(dp));
				res += rec(0, 0, 0);
				loop.clear();
				loop.push_back(i);
				used[i] = true;
				dfs(i);
			}
		}
		memset(dp, -1, sizeof(dp));
		res += rec(0, 0, 0);
		return res;
	}

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
	{
		int Type1ARRAY[] = {1, 5, 2, 3, 4, 6, 0, 8, 7};
		vector <int> Type1( Type1ARRAY, Type1ARRAY+ARRSIZE(Type1ARRAY) );
		int Number1ARRAY[] = {598, 255, 109, 494, 367, 439, 820, 291, 340};
		vector <int> Number1( Number1ARRAY, Number1ARRAY+ARRSIZE(Number1ARRAY) );
		int Type2ARRAY[] = {6, 0, 8, 2, 5, 1, 3, 7, 4};
		vector <int> Type2( Type2ARRAY, Type2ARRAY+ARRSIZE(Type2ARRAY) );
		int Number2ARRAY[] = {425, 377, 670, 928, 69, 103, 601, 319, 985};
		vector <int> Number2( Number2ARRAY, Number2ARRAY+ARRSIZE(Number2ARRAY) );
		CandyCollection theObject;
		eq(0, theObject.solve(Type1, Number1, Type2, Number2),2137);
	}
	{
		int Type1ARRAY[] = {78, 3, 88, 86, 13, 36, 13, 61, 77, 46, 71, 47, 81, 41, 65, 7, 79, 4, 23, 27, 8, 34, 60, 56, 54, 45, 32, 16, 43, 38, 64, 29, 21, 8, 51, 5, 75, 0, 70, 18, 52, 80, 77, 55, 84, 6, 26, 25, 16, 38, 60, 5, 66, 12, 11, 76, 79, 40, 15, 87, 59, 28, 85, 78, 86, 20, 39, 20, 14, 27, 2, 83, 42, 4, 21, 68, 30, 72, 30, 48, 39, 68, 22, 2, 37, 63, 11, 37, 42, 65};
		vector <int> Type1( Type1ARRAY, Type1ARRAY+ARRSIZE(Type1ARRAY) );
		int Number1ARRAY[] = {473, 571, 143, 378, 313, 384, 625, 46, 363, 960, 261, 177, 109, 182, 226, 641, 245, 181, 113, 818, 217, 473, 633, 658, 465, 963, 341, 13, 151, 426, 593, 817, 302, 13, 473, 58, 488, 234, 938, 7, 230, 498, 862, 844, 268, 906, 684, 918, 386, 756, 941, 266, 253, 596, 201, 831, 828, 852, 392, 167, 859, 536, 930, 553, 859, 138, 935, 194, 416, 759, 552, 216, 202, 120, 428, 829, 869, 498, 619, 58, 785, 87, 263, 18, 730, 587, 278, 370, 377, 367};
		vector <int> Number1( Number1ARRAY, Number1ARRAY+ARRSIZE(Number1ARRAY) );
		int Type2ARRAY[] = {71, 35, 15, 12, 58, 61, 19, 49, 49, 82, 3, 48, 32, 22, 41, 18, 9, 46, 33, 67, 45, 89, 57, 0, 75, 62, 74, 67, 40, 14, 34, 55, 10, 64, 44, 17, 72, 52, 25, 31, 69, 89, 19, 74, 7, 10, 17, 26, 85, 1, 84, 35, 57, 47, 69, 9, 66, 6, 53, 82, 88, 44, 54, 29, 1, 33, 83, 73, 70, 73, 53, 24, 87, 50, 76, 51, 31, 62, 36, 56, 23, 81, 24, 28, 58, 59, 80, 43, 63, 50};
		vector <int> Type2( Type2ARRAY, Type2ARRAY+ARRSIZE(Type2ARRAY) );
		int Number2ARRAY[] = {885, 263, 745, 944, 624, 273, 27, 414, 518, 343, 284, 360, 373, 292, 699, 5, 577, 783, 581, 486, 399, 412, 714, 752, 92, 36, 665, 645, 236, 121, 248, 827, 571, 122, 940, 284, 143, 405, 703, 140, 948, 272, 277, 590, 735, 775, 270, 976, 220, 705, 880, 602, 544, 362, 402, 243, 71, 275, 841, 220, 879, 782, 454, 954, 211, 18, 14, 152, 929, 461, 10, 171, 156, 565, 333, 933, 83, 966, 744, 251, 408, 383, 449, 95, 35, 941, 983, 254, 468, 262};
		vector <int> Number2( Number2ARRAY, Number2ARRAY+ARRSIZE(Number2ARRAY) );
		CandyCollection theObject;
		eq(1, theObject.solve(Type1, Number1, Type2, Number2),20744);
	}
	{
		int Type1ARRAY[] = {0,0,2,3};
		vector <int> Type1( Type1ARRAY, Type1ARRAY+ARRSIZE(Type1ARRAY) );
		int Number1ARRAY[] = {1,1,2,2};
		vector <int> Number1( Number1ARRAY, Number1ARRAY+ARRSIZE(Number1ARRAY) );
		int Type2ARRAY[] = {1,1,3,2};
		vector <int> Type2( Type2ARRAY, Type2ARRAY+ARRSIZE(Type2ARRAY) );
		int Number2ARRAY[] = {1,1,2,2};
		vector <int> Number2( Number2ARRAY, Number2ARRAY+ARRSIZE(Number2ARRAY) );
		CandyCollection theObject;
		eq(2, theObject.solve(Type1, Number1, Type2, Number2),5);
	}
	{
		int Type1ARRAY[] = {0,1,2,3};
		vector <int> Type1( Type1ARRAY, Type1ARRAY+ARRSIZE(Type1ARRAY) );
		int Number1ARRAY[] = {5,5,10,13};
		vector <int> Number1( Number1ARRAY, Number1ARRAY+ARRSIZE(Number1ARRAY) );
		int Type2ARRAY[] = {1,2,3,0};
		vector <int> Type2( Type2ARRAY, Type2ARRAY+ARRSIZE(Type2ARRAY) );
		int Number2ARRAY[] = {8,8,10,15};
		vector <int> Number2( Number2ARRAY, Number2ARRAY+ARRSIZE(Number2ARRAY) );
		CandyCollection theObject;
		eq(3, theObject.solve(Type1, Number1, Type2, Number2),20);
	}
	{
		int Type1ARRAY[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
		vector <int> Type1( Type1ARRAY, Type1ARRAY+ARRSIZE(Type1ARRAY) );
		int Number1ARRAY[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
		vector <int> Number1( Number1ARRAY, Number1ARRAY+ARRSIZE(Number1ARRAY) );
		int Type2ARRAY[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
		vector <int> Type2( Type2ARRAY, Type2ARRAY+ARRSIZE(Type2ARRAY) );
		int Number2ARRAY[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
		vector <int> Number2( Number2ARRAY, Number2ARRAY+ARRSIZE(Number2ARRAY) );
		CandyCollection theObject;
		eq(4, theObject.solve(Type1, Number1, Type2, Number2),5101);
	}
	return 0;
}
// END CUT HERE
