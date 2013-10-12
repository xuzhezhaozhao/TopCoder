#include <algorithm>
#include <iostream>
#include <sstream>

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

/*************** Program Begin **********************/
int dp[2][50];
class ZigZag {
public:
    int longestZigZag(vector <int> sequence) {
        int res = 1;
	int N = sequence.size();
	dp[0][0] = dp[1][0] = 1;
	for (int i = 1; i < N; i++) {
		dp[0][i] = dp[1][i] = 1;
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				if (dp[1][i] < dp[0][j] + 1) {
					dp[1][i] = dp[0][j] + 1;
				}
			} else if (sequence[i] < sequence[j]) {
				if (dp[0][i] < dp[1][j] + 1) {
					dp[0][i] = dp[1][j] + 1;
				}
			}
		}
		res = max(res, dp[0][i]);
		res = max(res, dp[1][i]);
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int sequenceARRAY[] = { 1, 7, 4, 9, 2, 5 };
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(0, theObject.longestZigZag(sequence),6);
    }
    {
        int sequenceARRAY[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(1, theObject.longestZigZag(sequence),7);
    }
    {
        int sequenceARRAY[] = { 44 };
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(2, theObject.longestZigZag(sequence),1);
    }
    {
        int sequenceARRAY[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(3, theObject.longestZigZag(sequence),2);
    }
    {
        int sequenceARRAY[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(4, theObject.longestZigZag(sequence),8);
    }
    {
        int sequenceARRAY[] = { 
		374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
		600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
		67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
		477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
		249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
           ;
        vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
        ZigZag theObject;
        eq(5, theObject.longestZigZag(sequence),36);
    }
}
// END CUT HERE
