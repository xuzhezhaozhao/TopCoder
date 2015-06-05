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

/*************** Program Begin **********************/

class PackingBallsDiv1 {
public:
    int minPacks(int K, int A, int B, int C, int D) {
        long long res = 0;
	vector <long long> X;
	X.resize(K);
	X[0] = A;
	for (int i = 1; i <= K - 1; i++) {
		X[i] = (X[i-1] * B + C) % D + 1;
	}
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += X[i] / K;
		X[i] %= K;
	}
	res = sum + K;
	sort(X.begin(), X.end());
	for (int i = 0; i < K; i++) {
		res = min(res, sum + X[i] + K - (i+1));
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        PackingBallsDiv1 theObject;
        eq(0, theObject.minPacks(3, 4, 2, 5, 6),4);
    }
    {
        PackingBallsDiv1 theObject;
        eq(1, theObject.minPacks(1, 58, 23, 39, 93),58);
    }
    {
        PackingBallsDiv1 theObject;
        eq(2, theObject.minPacks(23, 10988, 5573, 4384, 100007),47743);
    }
    {
        PackingBallsDiv1 theObject;
        eq(3, theObject.minPacks(100000, 123456789, 234567890, 345678901, 1000000000),331988732);
    }
}
// END CUT HERE
