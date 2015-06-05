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

class IncrementAndDoubling {
public:
    int getMin(vector <int> desiredArray) {
        int res = 0;
	int n = desiredArray.size();
	bool flag1, flag2;
	while (true) {
		flag1 = flag2 = false;
		for (int i = 0; i < n; i++) {
			if (desiredArray[i] & 1) {
				++res;
				--desiredArray[i];
				flag2 = true;
			}
		}
		for (int i = 0; i < n; i++) {
			if (desiredArray[i] != 0) {
				desiredArray[i] /= 2;
				flag1 =true;
			}
		}

		if (flag1) {
			++res;
		}
		if (!flag1 && !flag2) {
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
        int desiredArrayARRAY[] = {2, 1};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(0, theObject.getMin(desiredArray),3);
    }
    {
        int desiredArrayARRAY[] = {16, 16, 16};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(1, theObject.getMin(desiredArray),7);
    }
    {
        int desiredArrayARRAY[] = {100};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(2, theObject.getMin(desiredArray),9);
    }
    {
        int desiredArrayARRAY[] = {0, 0, 1, 0, 1};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(3, theObject.getMin(desiredArray),2);
    }
    {
        int desiredArrayARRAY[] = {123, 234, 345, 456, 567, 789};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(4, theObject.getMin(desiredArray),40);
    }
    {
        int desiredArrayARRAY[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7};
        vector <int> desiredArray( desiredArrayARRAY, desiredArrayARRAY+ARRSIZE(desiredArrayARRAY) );
        IncrementAndDoubling theObject;
        eq(5, theObject.getMin(desiredArray),84);
    }
}
// END CUT HERE
