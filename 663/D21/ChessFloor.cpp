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

class ChessFloor {
public:
    int minimumChanges(vector <string> floor) {
        int res = 100000000;
		int N = floor.size();
		int h1[26] = {0};
		int h2[26] = {0};

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i+j)%2 == 0) {
					++h1[ floor[i][j] - 'a' ];
				} else {
					++h2[ floor[i][j] - 'a' ];
				}
			}
		}
		
		int sum1 = accumulate(h1, h1 + 26, 0);
		int sum2 = accumulate(h2, h2 + 26, 0);
		for (int a = 0; a < 26; a++) {
			for (int b = 0; b < 26; b++) {
				if (a == b) {
					continue;
				}
				res = min(res, sum1 - h1[a] + sum2 - h2[b]);
			}
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
        string floorARRAY[] = {"aba",
            "bbb",
            "aba"}
           ;
        vector <string> floor( floorARRAY, floorARRAY+ARRSIZE(floorARRAY) );
        ChessFloor theObject;
        eq(0, theObject.minimumChanges(floor),1);
    }
    {
        string floorARRAY[] = {"wbwbwbwb",
            "bwbwbwbw",
            "wbwbwbwb",
            "bwbwbwbw",
            "wbwbwbwb",
            "bwbwbwbw",
            "wbwbwbwb",
            "bwbwbwbw"}
            ;
        vector <string> floor( floorARRAY, floorARRAY+ARRSIZE(floorARRAY) );
        ChessFloor theObject;
        eq(1, theObject.minimumChanges(floor),0);
    }
    {
        string floorARRAY[] = {"zz",
            "zz"};
        vector <string> floor( floorARRAY, floorARRAY+ARRSIZE(floorARRAY) );
        ChessFloor theObject;
        eq(2, theObject.minimumChanges(floor),2);
    }
    {
        string floorARRAY[] = {"helloand",
            "welcomet",
            "osingler",
            "oundmatc",
            "hsixhund",
            "redandsi",
            "xtythree",
            "goodluck"};
        vector <string> floor( floorARRAY, floorARRAY+ARRSIZE(floorARRAY) );
        ChessFloor theObject;
        eq(3, theObject.minimumChanges(floor),56);
    }
    {
        string floorARRAY[] = {"jecjxsengslsmeijrmcx",
            "tcfyhumjcvgkafhhffed",
            "icmgxrlalmhnwwdhqerc",
            "xzrhzbgjgabanfxgabed",
            "fpcooilmwqixfagfojjq",
            "xzrzztidmchxrvrsszii",
            "swnwnrchxujxsknuqdkg",
            "rnvzvcxrukeidojlakcy",
            "kbagitjdrxawtnykrivw",
            "towgkjctgelhpomvywyb",
            "ucgqrhqntqvncargnhhv",
            "mhvwsgvfqgfxktzobetn",
            "fabxcmzbbyblxxmjcaib",
            "wpiwnrdqdixharhjeqwt",
            "xfgulejzvfgvkkuyngdn",
            "kedsalkounuaudmyqggb",
            "gvleogefcsxfkyiraabn",
            "tssjsmhzozbcsqqbebqw",
            "ksbfjoirwlmnoyyqpbvm",
            "phzsdodppzfjjmzocnge"};
        vector <string> floor( floorARRAY, floorARRAY+ARRSIZE(floorARRAY) );
        ChessFloor theObject;
        eq(4, theObject.minimumChanges(floor),376);
    }
	return 0;
}
// END CUT HERE
