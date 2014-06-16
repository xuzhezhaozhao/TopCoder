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
bool v[6][6];
int g[6][6];
class ElephantDrinkingEasy {
public:
    int maxElephants(vector <string> map) {
        int res = 0;
	int n = map.size();
	memset(g, 0, sizeof(g));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'Y') {
				g[i][j] = 1;
			} else {
				g[i][j] = 0;
			}
		}
	}
	vector <int> p;
	for (int i = 1; i <= 4; i++) {
		p.push_back(i);
	}
	do {
		memset(v, 0, sizeof(v));
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			switch (p[i]) {
			case 1:	// Up
				for (int j = 0; j < n; j++) {	// 列
					int k = 0;					
					while (k < n && !v[k][j] && !g[k][j]) {
						k++;
					}
					if (k < n && g[k][j] == 1 && !v[k][j]) {
						++cnt;
						for (int q = 0; q <= k; q++) {
							v[q][j] = true;
						}
					}
				}
				break;
			case 2:	// left
				for (int j = 0; j < n; j++) {	// 行
					int k = 0;					
					while (k < n && !v[j][k] && !g[j][k]) {
						k++;
					}
					if (k < n && g[j][k] == 1 && !v[j][k]) {
						++cnt;
						for (int q = 0; q <= k; q++) {
							v[j][q] = true;
						}
					}
				}
				break;
			case 3: // down
				for (int j = 0; j < n; j++) {	// 列
					int k = n - 1;					
					while (k >= 0 && !v[k][j] && !g[k][j]) {
						--k;
					}
					if (k >= 0 && g[k][j] == 1 && !v[k][j]) {
						++cnt;
						for (int q = n - 1; q >= k; q--) {
							v[q][j] = true;
						}
					}
				}
				break;
			case 4: // right
				for (int j = 0; j < n; j++) {	// 行
					int k = n - 1;					
					while (k >= 0 && !v[j][k] && !g[j][k]) {
						--k;
					}
					if (k >= 0 && g[j][k] == 1 && !v[j][k]) {
						++cnt;
						for (int q = n - 1; q >= k; q--) {
							v[j][q] = true;
						}
					}
				}
				break;
			}
		}
		res = max(res, cnt);
	} while (next_permutation(p.begin(), p.end()));

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string mapARRAY[] = {"NNNNN",
            "NNYYN",
            "NYNNN",
            "NNYNN",
            "NNNNN"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(0, theObject.maxElephants(map),4);
    }
    {
        string mapARRAY[] = {"YYY",
            "YYY",
            "YYY"}
           ;
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(1, theObject.maxElephants(map),8);
    }
    {
        string mapARRAY[] =  {"YNYN",
             "NNYY",
             "YYNN",
             "YYYY"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(2, theObject.maxElephants(map),10);
    }
    {
        string mapARRAY[] =  {"YNYN",
             "YNYY",
             "YYNN",
             "YYYY"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(3, theObject.maxElephants(map),10);
    }
    {
        string mapARRAY[] = {"YYNYN",
            "NYNNY",
            "YNYNN",
            "YYNYY",
            "YYNNN"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(4, theObject.maxElephants(map),12);
    }
    {
        string mapARRAY[] = {"YYNYN",
            "NYNYY",
            "YNYYN",
            "YYNYY",
            "YYNNN"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(5, theObject.maxElephants(map),13);
    }
    {
        string mapARRAY[] = {"NN",
            "NN"};
        vector <string> map( mapARRAY, mapARRAY+ARRSIZE(mapARRAY) );
        ElephantDrinkingEasy theObject;
        eq(6, theObject.maxElephants(map),0);
    }
}
// END CUT HERE
