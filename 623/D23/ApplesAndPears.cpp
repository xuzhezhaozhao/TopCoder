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
int xdots[51][51], xapps[51][51], xpears[51][51];
int g[51][51];
const int DOT = 0, APPLE = 1, PEAR = 2;
class ApplesAndPears {
public:
    int getArea(vector <string> board, int K) {
        int res = 0;
	int N = board.size();
	int cnt_dot = 0, cnt_app = 0, cnt_pear = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ('.' == board[i][j]) {
				g[i][j] = DOT;
				++cnt_dot;
			} else if ('A' == board[i][j]) {
				g[i][j] = APPLE;
				++cnt_app;
			} else {
				g[i][j] = PEAR;
				++cnt_pear;
			}
		}
	}
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		memset(xdots, 0, sizeof(xdots));
		memset(xapps, 0, sizeof(xapps));
		memset(xpears, 0, sizeof(xpears));

		// pre-calculate xdots[], xapps[], xpears[]
		for (int p = i; p < N; p++) {
		for (int q = j; q < N; q++) {
			int t1, t2, t3;
			t1 = (p - 1 >= 0 ? xdots[p-1][q] : 0);
			t2 = (q - 1 >= 0 ? xdots[p][q-1] : 0);
			t3 = ((p - 1 >= 0 && q - 1 >= 0) ? xdots[p-1][q-1] : 0);
			xdots[p][q] = t1 + t2 - t3;
			if (DOT == g[p][q]) {
				++xdots[p][q];
			}
			t1 = (p - 1 >= 0 ? xapps[p-1][q] : 0);
			t2 = (q - 1 >= 0 ? xapps[p][q-1] : 0);
			t3 = ((p - 1 >= 0 && q - 1 >= 0) ? xapps[p-1][q-1] : 0);
			xapps[p][q] = t1 + t2 - t3;
			if (APPLE == g[p][q]) {
				++xapps[p][q];
			}
			xpears[p][q] = (p - i + 1) * (q - j + 1) - xapps[p][q] - xdots[p][q];
		}	
		}

		for (int p = i; p < N; p++) {
		for (int q = j; q < N; q++) {
			int all = (p - i + 1) * (q - j + 1);
			// dots
			if (all <= cnt_dot && K >= all - xdots[p][q]) {
				res = max(res, all);
			}
			// apples
			if (all <= cnt_app) {
				if (0 == xpears[p][q] && K >= xdots[p][q]) {
					res = max(res, all);
				}
				if (0 != xpears[p][q] && cnt_dot > 0 && K >= xpears[p][q] + all - xapps[p][q]) {
					res = max(res, all);
				}
			}
			// pears
			if (all <= cnt_pear) {
				if (0 == xapps[p][q] && K >= xdots[p][q]) {
					res = max(res, all);
				}
				if (0 != xapps[p][q] && cnt_dot > 0 && K >= xapps[p][q] + all - xpears[p][q]) {
					res = max(res, all);
				}
			}
		}
		}
	}
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {".A",
            "P."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(0, theObject.getArea(board, 0),1);
    }
    {
        string boardARRAY[] = {".A",
            "P."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(1, theObject.getArea(board, 1),2);
    }
    {
        string boardARRAY[] = {".PP", 
            "PPA", 
            "PAP"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(2, theObject.getArea(board, 3),6);
    }
    {
        string boardARRAY[] = {"A.P.PAAPPA",
            "PPP..P.PPP",
            "AAP.A.PAPA",
            "P.PA.AAA.A",
            "...PA.P.PA",
            "P..A.A.P..",
            "PAAP..A.A.",
            "PAAPPA.APA",
            ".P.AP.P.AA",
            "..APAPAA.."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        ApplesAndPears theObject;
        eq(3, theObject.getArea(board, 10),21);
    }
    {
	    string boardARRAY[] = {
		    "A.P.PAAPPAA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "PPP..P.PPPA.P.PAAA.P.PAAPPAPPAA.P.PAAPPAA.P.PAAPPA",
		    "AAP.A.PAPAAA.P.PAA.P.PAAPPAAPPAA.P.PAAPPA.P.PAAPPA",
		    "P.PA.AAA.AA.P.PA.P.PAAPPAAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "...PA.P.A.P.PAA.P.PAAPPAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    "P..A.A.PA.P.PA.P.PAAPPAAAPPAA.P.PAAPPA..A.P.PAAPPA",
		    "PAAP..A.A.PA.P.PAAPPA.PAAPPAA.P.PAAPPAA.A.P.PAAPPA",
		    "PAAPPA.AA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    ".P.AP.P.AA.P.PAAPPA.P.PAAPPAA.P.PAAPPAAAA.P.PAAPPA",
		    "..APAPAAA.P.PAAPPA.P.PAAPPAA.P.PAAPPAA..A.P.PAAPPA",
		    "A.P.PAAPPAA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "PPP..P.PPPA.P.PAAA.P.PAAPPAPPAA.P.PAAPPAA.P.PAAPPA",
		    "AAP.A.PAPAAA.P.PAA.P.PAAPPAAPPAA.P.PAAPPA.P.PAAPPA",
		    "P.PA.AAA.AA.P.PA.P.PAAPPAAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "...PA.P.A.P.PAA.P.PAAPPAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    "P..A.A.PA.P.PA.P.PAAPPAAAPPAA.P.PAAPPA..A.P.PAAPPA",
		    "PAAP..A.A.PA.P.PAAPPA.PAAPPAA.P.PAAPPAA.A.P.PAAPPA",
		    "PAAPPA.AA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    ".P.AP.P.AA.P.PAAPPA.P.PAAPPAA.P.PAAPPAAAA.P.PAAPPA",
		    "..APAPAAA.P.PAAPPA.P.PAAPPAA.P.PAAPPAA..A.P.PAAPPA",
		    "A.P.PAAPPAA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "PPP..P.PPPA.P.PAAA.P.PAAPPAPPAA.P.PAAPPAA.P.PAAPPA",
		    "AAP.A.PAPAAA.P.PAA.P.PAAPPAAPPAA.P.PAAPPA.P.PAAPPA",
		    "P.PA.AAA.AA.P.PA.P.PAAPPAAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "...PA.P.A.P.PAA.P.PAAPPAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    "P..A.A.PA.P.PA.P.PAAPPAAAPPAA.P.PAAPPA..A.P.PAAPPA",
		    "PAAP..A.A.PA.P.PAAPPA.PAAPPAA.P.PAAPPAA.A.P.PAAPPA",
		    "PAAPPA.AA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    ".P.AP.P.AA.P.PAAPPA.P.PAAPPAA.P.PAAPPAAAA.P.PAAPPA",
		    "..APAPAAA.P.PAAPPA.P.PAAPPAA.P.PAAPPAA..A.P.PAAPPA",
		    "A.P.PAAPPAA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "PPP..P.PPPA.P.PAAA.P.PAAPPAPPAA.P.PAAPPAA.P.PAAPPA",
		    "AAP.A.PAPAAA.P.PAA.P.PAAPPAAPPAA.P.PAAPPA.P.PAAPPA",
		    "P.PA.AAA.AA.P.PA.P.PAAPPAAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "...PA.P.A.P.PAA.P.PAAPPAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    "P..A.A.PA.P.PA.P.PAAPPAAAPPAA.P.PAAPPA..A.P.PAAPPA",
		    "PAAP..A.A.PA.P.PAAPPA.PAAPPAA.P.PAAPPAA.A.P.PAAPPA",
		    "PAAPPA.AA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    ".P.AP.P.AA.P.PAAPPA.P.PAAPPAA.P.PAAPPAAAA.P.PAAPPA",
		    "..APAPAAA.P.PAAPPA.P.PAAPPAA.P.PAAPPAA..A.P.PAAPPA",
		    "A.P.PAAPPAA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "PPP..P.PPPA.P.PAAA.P.PAAPPAPPAA.P.PAAPPAA.P.PAAPPA",
		    "AAP.A.PAPAAA.P.PAA.P.PAAPPAAPPAA.P.PAAPPA.P.PAAPPA",
		    "P.PA.AAA.AA.P.PA.P.PAAPPAAAPPAA.P.PAAPPAA.P.PAAPPA",
		    "...PA.P.A.P.PAA.P.PAAPPAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    "P..A.A.PA.P.PA.P.PAAPPAAAPPAA.P.PAAPPA..A.P.PAAPPA",
		    "PAAP..A.A.PA.P.PAAPPA.PAAPPAA.P.PAAPPAA.A.P.PAAPPA",
		    "PAAPPA.AA.A.P.PAAPPAP.PAAPPAA.P.PAAPPAPAA.P.PAAPPA",
		    ".P.AP.P.AA.P.PAAPPA.P.PAAPPAA.P.PAAPPAAAA.P.PAAPPA",
		    "..APAPAAA.P.PAAPPA.P.PAAPPAA.P.PAAPPAA..A.P.PAAPPA"
	    };
	    vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
	    ApplesAndPears theObject;
	    eq(4, theObject.getArea(board, 10),21);
    }
}
// END CUT HERE
