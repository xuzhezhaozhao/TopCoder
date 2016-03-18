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

const int MAX_N = 16;
long long dp[1<<MAX_N][MAX_N];

class CheeseRolling {
public:
	int OnesCount(int n) {
		int cnt = 0;
		while (n != 0) {
			cnt += (n & 1);
			n >>= 1;
		}
		return cnt;
	}

    vector<long long> waysToWin(vector <string> wins) {
        vector<long long> res;
		memset(dp, 0, sizeof(dp));

		int N = wins.size();
		vector< vector<int> > kind(N+1);


		for (int i = 1; i < (1<<N); i++) {
			int cnt = OnesCount(i);
			kind[cnt].push_back(i);
		}
		
		for (int i = 0; i < N; i++) {
			dp[1<<i][i] = 1;
		}

		for (int i = 2; i <= N; i *= 2) {
			// i 个人比赛
			for (auto x : kind[i]) {
				// 分成2个 i/2 个人的比赛
				for (auto y : kind[i/2]) {
					int z = 0;
					if ((x | y) != x) {
						continue;
					}
					z = x^y;

					// 分成 y, z 两队
					for (int win1 = 0; win1 < N; win1++) {
						for (int win2 = 0; win2 < N; win2++) {
							if (win1 == win2) {
								continue;
							}
							long long t = dp[y][win1] * dp[z][win2];
							if (wins[win1][win2] == 'Y') {
								dp[x][win1] += t;
							} else {
								dp[x][win2] += t;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			res.push_back( dp[ (1<<N)-1 ][i] );
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
        string winsARRAY[] = {"NN",
            "YN"};
        vector <string> wins( winsARRAY, winsARRAY+ARRSIZE(winsARRAY) );
        long retrunValueARRAY[] = {0L, 2L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheeseRolling theObject;
        eq(0, theObject.waysToWin(wins),retrunValue);
    }
    {
        string winsARRAY[] = {"NYNY",
            "NNYN",
            "YNNY",
            "NYNN"};
        vector <string> wins( winsARRAY, winsARRAY+ARRSIZE(winsARRAY) );
        long retrunValueARRAY[] = {8L, 0L, 16L, 0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheeseRolling theObject;
        eq(1, theObject.waysToWin(wins),retrunValue);
    }
    {
        string winsARRAY[] = {"NYNYNYNY",
            "NNYNYNYY",
            "YNNNNNNN",
            "NYYNNYNY",
            "YNYYNYYY",
            "NYYNNNNN",
            "YNYYNYNN",
            "NNYNNYYN"};
        vector <string> wins( winsARRAY, winsARRAY+ARRSIZE(winsARRAY) );
        long retrunValueARRAY[] = {4096L, 8960L, 0L, 2048L, 23808L, 0L, 1408L, 0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheeseRolling theObject;
        eq(2, theObject.waysToWin(wins),retrunValue);
    }
    {
        string winsARRAY[] = {"NYNNNNYYNYYNNYNN",
            "NNNNNNNNNYYNYYNY",
            "YYNYYNNNNYYYYYYN",
            "YYNNYYYNYNNYYYNY",
            "YYNNNYYNYYNNNNYY",
            "YYYNNNNYYNNYYNYN",
            "NYYNNYNYNYNYYYYN",
            "NYYYYNNNYYNYNYYY",
            "YYYNNNYNNYYYYNNN",
            "NNNYNYNNNNNNYYNY",
            "NNNYYYYYNYNYYYNN",
            "YYNNYNNNNYNNYNNY",
            "YNNNYNNYNNNNNYNN",
            "NNNNYYNNYNNYNNYY",
            "YYNYNNNNYYYYYNNN",
            "YNYNNYYNYNYNYNYN"};
        vector <string> wins( winsARRAY, winsARRAY+ARRSIZE(winsARRAY) );
        long retrunValueARRAY[] = {331616878592L, 37267079168L, 2426798866432L, 2606831599616L, 994941665280L, 1162501849088L, 1888166674432L, 4632734203904L, 832881524736L, 84707409920L, 3007127748608L, 55490052096L, 17818550272L, 254672666624L, 629921447936L, 1959311671296L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheeseRolling theObject;
        eq(3, theObject.waysToWin(wins),retrunValue);
    }
    {
        string winsARRAY[] = {"NYYYYYYYYYYYYYYY",
            "NNYYYYYYYYYYYYYY",
            "NNNYYYYYYYYYYYYY",
            "NNNNYYYYYYYYYYYY",
            "NNNNNYYYYYYYYYYY",
            "NNNNNNYYYYYYYYYY",
            "NNNNNNNYYYYYYYYY",
            "NNNNNNNNYYYYYYYY",
            "NNNNNNNNNYYYYYYY",
            "NNNNNNNNNNYYYYYY",
            "NNNNNNNNNNNYYYYY",
            "NNNNNNNNNNNNYYYY",
            "NNNNNNNNNNNNNYYY",
            "NNNNNNNNNNNNNNYY",
            "NNNNNNNNNNNNNNNY",
            "NNNNNNNNNNNNNNNN"};
        vector <string> wins( winsARRAY, winsARRAY+ARRSIZE(winsARRAY) );
        long retrunValueARRAY[] = {20922789888000L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CheeseRolling theObject;
        eq(4, theObject.waysToWin(wins),retrunValue);
    }
	return 0;
}
// END CUT HERE
