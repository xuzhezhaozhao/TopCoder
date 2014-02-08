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
#include <ctime>

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

class MysticAndCandiesEasy {
public:
    int minBoxes(int C, int X, vector <int> high) {
        int res = 0;
	int N = high.size();

	sort(high.begin(), high.end());
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += high[i];
	}
	int dif = sum - C;
	reverse(high.begin(), high.end());
	int eat = 0;
	for (int i = 0; i < N; i++) {
		eat += high[i];
		if (eat - dif >= X) {
			res = i + 1;
			break;
		}
	}

        return res;
    }

};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int highARRAY[] = {1, 2, 3, 4, 5};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandiesEasy theObject;
        eq(0, theObject.minBoxes(10, 7, high),1);
    }
    {
        int highARRAY[] = {3, 3, 3, 3, 3};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandiesEasy theObject;
        eq(1, theObject.minBoxes(10, 7, high),4);
    }
    {
        int highARRAY[] = {12, 34, 23, 45, 34};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandiesEasy theObject;
        eq(2, theObject.minBoxes(100, 63, high),3);
    }
    {
        int highARRAY[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandiesEasy theObject;
        eq(3, theObject.minBoxes(19, 12, high),22);
    }
    {
        int highARRAY[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandiesEasy theObject;
        eq(4, theObject.minBoxes(326, 109, high),15);
    }
}
// END CUT HERE
