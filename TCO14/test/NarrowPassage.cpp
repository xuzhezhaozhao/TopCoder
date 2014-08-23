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
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
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
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
// END CUT HERE

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/
int CL[55], CR[55];
int CB[55][55];
class NarrowPassage {
public:
	int minDist(int L, vector <int> a, vector <int> b) {
		int res = 0;
		int N = a.size();
		vector <pii> v;
		for (int i = 0; i < N; i++) {
			v.push_back(mkp(a[i], b[i]));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < N; i++) {
			a[i] = v[i].first;
			b[i] = v[i].second;
		}

		memset(CL, 0, sizeof(CL));
		memset(CR, 0, sizeof(CR));
		memset(CB, 0, sizeof(CB));
		for (int i = 0; i < N; i++) {
			// CL[i]
			for (int j = 0; j <= i; j++) {
				CL[i] += a[j] + b[j];	
			}
			// CR[i]
			for (int j = i; j < N; j++) {
				CR[i] += (L - a[j]) + (L - b[j]);
			}
			// CB[i][j]
			for (int j = i; j < N; j++) {
				for (int k = i; k <= j; k++) {
					CB[i][j] += abs(b[k] - a[k]);
				}
			}
		}

		v.clear();
		for (int k = 0; k < N;) {
			for (int i = N - 1; i > k; i--) {
				if (b[k] > b[i]) {
					v.push_back(mkp(k, i));
					k = i;
					break;
				}
			}
			++k;
		}

		if (v.empty()) {	// 无需到端点重新排序
			res = CB[0][N-1];
		} else {
			int t = v.size();
			int left = v[0].first, right = v[t-1].second;
			res = CR[left];			// 全部到右端
			if (left > 0) {
				res += CB[0][left - 1];
			}
			res = min(res, CL[right] + CB[right + 1][N - 1]);	// 全部到左端
			// 部分左，部分右
			for (int i = 0; i < t - 1; i++) {
				left = v[i].second;
				right = v[i + 1].first;
				res = min(res, CL[left] + CB[left + 1][right - 1] + CR[right]);
			}
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int aARRAY[] = {1, 2};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {3, 4};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		NarrowPassage theObject;
		//eq(0, theObject.minDist(5, a, b),4);
	}
	{
		int aARRAY[] = {3, 9};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {8, 6};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		NarrowPassage theObject;
		//eq(1, theObject.minDist(10, a, b),14);
	}
	{
		int aARRAY[] = {133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
			38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
			25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
			156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
			81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
			40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
			33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
			245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
			119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		NarrowPassage theObject;
		//eq(2, theObject.minDist(265467, a, b),7148670);
	}
	{
		int aARRAY[] = {706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
			938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
			670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
			476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
			79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
			441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
			409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
			418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
			285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		NarrowPassage theObject;
		eq(3, theObject.minDist(1000000, a, b),45670501);
	}
}
// END CUT HERE
