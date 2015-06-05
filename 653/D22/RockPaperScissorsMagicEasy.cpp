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

const int MOD = 1000000007;
long long C[2001][2001];
class RockPaperScissorsMagicEasy {
public:
    int count(vector <int> card, int score) {
		memset(C, 0, sizeof(C));
		int N = card.size();
		C[0][0] = 0;
		C[1][0] = 1;
		C[1][1] = 1;
		for (int i = 2; i <= N; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				C[i][j] %= MOD;
			}
		}

		long long res = C[N][score];
		int tmp = N - score;
		while (tmp-- > 0) {
			res *= 2;
			res %= MOD;
		}


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
        int cardARRAY[] = {0,1,2};
        vector <int> card( cardARRAY, cardARRAY+ARRSIZE(cardARRAY) );
        RockPaperScissorsMagicEasy theObject;
        eq(0, theObject.count(card, 2),6);
    }
    {
        int cardARRAY[] = {1,2};
        vector <int> card( cardARRAY, cardARRAY+ARRSIZE(cardARRAY) );
        RockPaperScissorsMagicEasy theObject;
        eq(1, theObject.count(card, 0),4);
    }
    {
        int cardARRAY[] = {2,2,1,0,0};
        vector <int> card( cardARRAY, cardARRAY+ARRSIZE(cardARRAY) );
        RockPaperScissorsMagicEasy theObject;
        eq(2, theObject.count(card, 10),0);
    }
    {
        int cardARRAY[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
        vector <int> card( cardARRAY, cardARRAY+ARRSIZE(cardARRAY) );
        RockPaperScissorsMagicEasy theObject;
        eq(3, theObject.count(card, 7),286226628);
    }
    {
        int cardARRAY[] = {0,1,2,0,1,2,2,1,0};
        vector <int> card( cardARRAY, cardARRAY+ARRSIZE(cardARRAY) );
        RockPaperScissorsMagicEasy theObject;
        eq(4, theObject.count(card, 8),18);
    }
	return 0;
}
// END CUT HERE
