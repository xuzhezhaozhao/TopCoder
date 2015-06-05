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

int result1[32];
int result2[32];

class XorSequenceEasy {
public:
    int getmax(vector <int> A, int N) {
        int res = 0;
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
        int AARRAY[] = {3,2,1,0,3,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        XorSequenceEasy theObject;
        eq(0, theObject.getmax(A, 4),8);
    }
    {
        int AARRAY[] = {3,0,4,6,1,5,7,6};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        XorSequenceEasy theObject;
        eq(1, theObject.getmax(A, 8),21);
    }
    {
        int AARRAY[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        XorSequenceEasy theObject;
        eq(2, theObject.getmax(A, 16),76);
    }
    {
        int AARRAY[] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        XorSequenceEasy theObject;
        eq(3, theObject.getmax(A, 8),0);
    }
    {
        int AARRAY[] = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
           ,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
           ,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
           ,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
           ,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        XorSequenceEasy theObject;
        eq(4, theObject.getmax(A, 1073741824),720);
    }
	return 0;
}
// END CUT HERE
