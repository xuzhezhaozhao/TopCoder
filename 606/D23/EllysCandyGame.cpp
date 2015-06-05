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

class EllysCandyGame {
public:
	int N;
	vector <int> sweets;
	int isFirstWin(int w1, int w2)
	{
		bool ok = false;
		int res = 1;
		for (int j = 0; j < N; j++) {
			if (sweets[j] != 0) {
				ok = true;
				if (j - 1 >= 0) {
					sweets[j-1] = 2 * sweets[j-1];
				}
				if (j + 1 < N) {
					sweets[j+1] = 2 * sweets[j+1];
				}
				int take = sweets[j];
				sweets[j] = 0;
				int nres = isFirstWin(w2 + take, w1);
				if (1 == nres) {
					if (j - 1 >= 0) {
						sweets[j-1] = sweets[j-1] / 2;
					}
					if (j + 1 < N) {
						sweets[j+1] = sweets[j+1] / 2;
					}
					sweets[j] = take;
					return -1;
				}
				if (0 == nres) {
					res = 0;
				}
				if (j - 1 >= 0) {
					sweets[j-1] = sweets[j-1] / 2;
				}
				if (j + 1 < N) {
					sweets[j+1] = sweets[j+1] / 2;
				}
				sweets[j] = take;
			}
		}
		if (!ok) {	// 结束
			if (w1 == w2) {
				return 0;
			}
			if (w1 > w2) {
				return 1;
			}
			if (w1 < w2) {
				return -1;
			}
		}
		return res;
	}

    string getWinner(vector <int> sw) {
        string res;
	this->N = sw.size();
	this->sweets = sw;
	
	int r = -1;
	bool noChoice = true;
	for (int i = 0; i < N; i++) {
		if (sweets[i] != 0) {	// 起始选择
			noChoice = false;
			if (i - 1 >= 0) {
				sweets[i-1] = 2 * sweets[i-1];
			}
			if (i + 1 < N) {
				sweets[i+1] = 2 * sweets[i+1];
			}
			int take = sweets[i];
			sweets[i] = 0;
			int rt = isFirstWin(take, 0);
			if (rt == 1) {
				r = 1;
				break;
			} else if (rt == 0) {
				r = 0;
			}
			if (i - 1 >= 0) {
				sweets[i-1] = sweets[i-1] / 2;
			}
			if (i + 1 < N) {
				sweets[i+1] = sweets[i+1] / 2 ;
			}
			sweets[i] = take;
		}
	}

	if (noChoice) {
		return "Draw";
	}

	if (r == 0) {
		return "Draw";
	}
	if (r == 1) {
		return "Elly";
	}
	if (r == -1) {
		return "Kris";
	}
	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int sweetsARRAY[] = {20, 50, 70, 0, 30};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(0, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {42, 13, 7};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(1, theObject.getWinner(sweets),"Elly");
    }
    {
        int sweetsARRAY[] = {10, 20};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
	eq(2, theObject.getWinner(sweets),"Draw");
    }
    {
        int sweetsARRAY[] = {3, 1, 7, 11, 1, 1};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(3, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(4, theObject.getWinner(sweets),"Kris");
    }
    {
        int sweetsARRAY[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298};
        vector <int> sweets( sweetsARRAY, sweetsARRAY+ARRSIZE(sweetsARRAY) );
        EllysCandyGame theObject;
        eq(5, theObject.getWinner(sweets),"Elly");
    }
}
// END CUT HERE
