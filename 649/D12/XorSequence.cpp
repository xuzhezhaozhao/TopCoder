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

long long result1[32];
long long result2[32];

class XorSequence {
public:
    long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
        long long res = 0;
		vector<int> A(sz);
		A[0] = A0;
		A[1] = A1;
		for (int i = 2; i < sz; i++) {
			A[i] = (A[i - 2] * (long long)P + A[i - 1] * (long long)Q + (long long)R) % N;
		}
		int p = -1;
		while (N > 0) {
			N /= 2;
			++p;
		}

		memset(result1, 0, sizeof(result1));
		memset(result2, 0, sizeof(result2));

		solve(A, p - 1);

		for (int i = 0; i < p; i++) {
			res += max(result1[i], result2[i]);
		}
		
        return res;
    }

	void solve(vector <int> &A, int p) {
		int n = A.size();
		// base case
		if (0 == n || p < 0) {
			return;
		}

		vector <int> A1, A2;
		for (int i = 0; i < n; i++) {
			if (extract(A[i], p) == 1) {
				A1.push_back(A[i]);
			} else {
				A2.push_back(A[i]);
			}
		}

		getResults(A, p); 
		solve(A1, p - 1);
		solve(A2, p - 1);
	}

	// p means pth bit, index from 0
	void getResults(vector <int> &A, int p) {
		long long ans1 = 0;
		long long ans2 = 0;
		int n = A.size();
		int sone = 0;
		int szero = 0;
		for (int i = 0; i < n; i++) {
			if ( extract(A[i], p) == 1 ) {
				++sone;
			} else {
				++szero;
			}
		}

		for (int i = 0; i < n; i++) {
			if ( extract(A[i], p) == 1 ) {
				--sone;
				ans2 += szero;
			} else {
				--szero;
				ans1 += sone;
			}
		}
		result1[p] += ans1;
		result2[p] += ans2;
	}

	int extract(int a, int p) {
		return ( (a >> p) & 0x1 );
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
        XorSequence theObject;
		eq(0, theObject.getmax(4, 6, 3, 2, 0, 1, 3),8LL);
    }
    {
        XorSequence theObject;
		eq(1, theObject.getmax(8, 8, 2, 5, 3, 1, 4),13LL);
    }
    {
        XorSequence theObject;
        eq(2, theObject.getmax(8, 7, 3, 0, 1, 2, 4),12LL);
    }
    {
        XorSequence theObject;
        eq(3, theObject.getmax(32, 15, 7, 9, 11, 2, 1),60LL);
    }
    {
        XorSequence theObject;
        eq(4, theObject.getmax(131072, 131072, 7, 7, 1, 0, 0),0LL);
    }
    {
        XorSequence theObject;
        eq(5, theObject.getmax(131072, 131070, 411, 415, 398, 463, 9191),4302679760LL);
    }
	return 0;
}
// END CUT HERE
