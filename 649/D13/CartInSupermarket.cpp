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

class CartInSupermarket {
public:
    int calcmin(vector <int> a, int b) {
		int low = 0;
		int high = 1000000000;
		while (low < high) {
			int mid = (high - low) / 2 + low;
			if (possible(a, mid, b)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}

        return high;
    }

	bool possible(vector <int> &a, int timeLimit, int numSplit) {
		long long need = 0;			// attention, must use long long
		for (auto x : a) {
			need += getNumSplit(x, timeLimit);
		}

		return need <= numSplit;
	}

	int getNumSplit(int x, int timeLimit) {
		int low = 0;
		int high = 1000000000;
		while (low < high) {
			int mid = (high - low) / 2 + low;
			if (calc(x, mid) > timeLimit) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return high;
	}


	// get minimum time of one single sequence with K split, problem D22
	int calc(int N, int K) {
        int res = 0;

		int p = getExpo(N);
		if (K >= N - 1) {
			return p + 1;
		}

		if (K == 0) {
			return N;
		}

		p = getExpo(K + 1);

		int r = (1 << (p-1)) - (K - ((1 << (p-1)) - 1));
		N -= r;

		res = N / (K + 1) + p;
		if (N % (K + 1) != 0) {
			++res;
		}

        return res;
    }

	int getExpo(int n) {
		for (int i = 0; i < 31; i++) {
			if ( (1 << i) >= n ) {
				return i;
			}
		}
		return 0;
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
        int aARRAY[] = {8};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CartInSupermarket theObject;
        eq(0, theObject.calcmin(a, 3),4);
    }
    {
        int aARRAY[] = {6,6,5};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CartInSupermarket theObject;
        eq(1, theObject.calcmin(a, 3),4);
    }
    {
        int aARRAY[] = {12,5,6,2,6,8};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CartInSupermarket theObject;
        eq(2, theObject.calcmin(a, 4),6);
    }
    {
        int aARRAY[] = {15,20,11,13,18,24,25,21,22,10,15,14,19};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CartInSupermarket theObject;
        eq(3, theObject.calcmin(a, 0),25);
    }
    {
        int aARRAY[] = {671122748,846444748,84701624,608579554,672060899,967957440,31438849,734849843,376589643,904285209
           ,80693344,211737743,85405464,444633541,293184188,935462519,146753109,972886045,496631016,601669536
           ,257574086,958464570,6294570,546189534,668105964,601197313,784337929,921840143,70408284,722040626
           ,253400894,56411549,811940644,152086353,122638884,776352066,118932182,177589709,538122558,127914469
           ,523761221,290027568,734517444,819458123,699130727,784698122,810265337,283326309,593596316,368671876};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CartInSupermarket theObject;
        eq(4, theObject.calcmin(a, 6478),3805054);
    }
	return 0;
}
// END CUT HERE
