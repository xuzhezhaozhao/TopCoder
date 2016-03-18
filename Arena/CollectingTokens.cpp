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

class CollectingTokens {
public:
    int maxTokens(vector <int> A, vector <int> B, vector <int> tokens, int L) {
        int res = 0;



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
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int tokensARRAY[] = {7,1};
        vector <int> tokens( tokensARRAY, tokensARRAY+ARRSIZE(tokensARRAY) );
        CollectingTokens theObject;
        eq(0, theObject.maxTokens(A, B, tokens, 6),8);
    }
    {
        int AARRAY[] = {3,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int tokensARRAY[] = {2,3,9};
        vector <int> tokens( tokensARRAY, tokensARRAY+ARRSIZE(tokensARRAY) );
        CollectingTokens theObject;
        eq(1, theObject.maxTokens(A, B, tokens, 5),14);
    }
    {
        int AARRAY[] = {1,2,5,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {4,4,1,4};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int tokensARRAY[] = {6,1,6,4,4};
        vector <int> tokens( tokensARRAY, tokensARRAY+ARRSIZE(tokensARRAY) );
        CollectingTokens theObject;
        eq(2, theObject.maxTokens(A, B, tokens, 3),16);
    }
    {
        int AARRAY[] = {9,1,7,10,5,8,3,4,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {6,6,9,6,6,1,1,6,6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int tokensARRAY[] = {4,2,1,6,3,7,8,5,2,9};
        vector <int> tokens( tokensARRAY, tokensARRAY+ARRSIZE(tokensARRAY) );
        CollectingTokens theObject;
        eq(3, theObject.maxTokens(A, B, tokens, 4),26);
    }
    {
        int AARRAY[] = {25,22,35,42,40,9,32,12,37,44,23,1,24,28,20,4,26,33,11,48,34,6,16,50,46,17,8,43,18,30,31,36,39,13,
           10,45,3,47,15,2,29,19,7,14,41,49,38,27,21};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {5,5,25,25,25,42,25,40,5,35,25,32,42,9,32,23,40,25,20,33,26,37,12,1,48,24,22,25,11,24,48,34,18,9,50,42,16,40,1,
           10,47,22,48,44,48,1,4,46,47};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int tokensARRAY[] = {6,9,4,9,5,8,6,4,4,1,4,8,3,4,5,8,5,6,4,9,7,9,7,9,5,2,7,2,7,7,5,9,5,8,5,7,1,9,3,9,3,6,4,5,5,4,7,9,2,2};
        vector <int> tokens( tokensARRAY, tokensARRAY+ARRSIZE(tokensARRAY) );
        CollectingTokens theObject;
        eq(4, theObject.maxTokens(A, B, tokens, 48),194);
    }
	return 0;
}
// END CUT HERE
