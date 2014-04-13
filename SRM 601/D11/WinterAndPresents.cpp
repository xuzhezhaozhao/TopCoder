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

class WinterAndPresents {
public:
    long long getNumber(vector <int> apple, vector <int> orange) {
        long long res = 0LL;
	int maxX = 10000000;
	int n = apple.size();
	for (int i = 0; i < n; i++) {
		maxX = min(maxX, apple[i] + orange[i]);
	}
	int maxA, maxO, sum;
	for (int i = 1; i <= maxX; i++) {
		sum = i * n;
		maxA = maxO = 0;
		for (int j = 0; j < n; j++) {
			maxA += min( i, apple[j] );
			maxO += min( i, orange[j] );
		}
		res += maxA + maxO - sum + 1;
	}
	//CHECKTIME();
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int appleARRAY[] = {1};
        vector <int> apple( appleARRAY, appleARRAY+ARRSIZE(appleARRAY) );
        int orangeARRAY[] = {1};
        vector <int> orange( orangeARRAY, orangeARRAY+ARRSIZE(orangeARRAY) );
        WinterAndPresents theObject;
        eq(0, theObject.getNumber(apple, orange),3LL);
    }
    {
        int appleARRAY[] = {1, 2, 0, 3};
        vector <int> apple( appleARRAY, appleARRAY+ARRSIZE(appleARRAY) );
        int orangeARRAY[] = {4, 5, 0, 6};
        vector <int> orange( orangeARRAY, orangeARRAY+ARRSIZE(orangeARRAY) );
        WinterAndPresents theObject;
        eq(1, theObject.getNumber(apple, orange),0LL);
    }
    {
        int appleARRAY[] = {2, 2, 2};
        vector <int> apple( appleARRAY, appleARRAY+ARRSIZE(appleARRAY) );
        int orangeARRAY[] = {2, 2, 2};
        vector <int> orange( orangeARRAY, orangeARRAY+ARRSIZE(orangeARRAY) );
        WinterAndPresents theObject;
        eq(2, theObject.getNumber(apple, orange),16LL);
    }
    {
        int appleARRAY[] = {7, 4, 5};
        vector <int> apple( appleARRAY, appleARRAY+ARRSIZE(appleARRAY) );
        int orangeARRAY[] = {1, 10, 2};
        vector <int> orange( orangeARRAY, orangeARRAY+ARRSIZE(orangeARRAY) );
        WinterAndPresents theObject;
        eq(3, theObject.getNumber(apple, orange),46LL);
    }
    {
        int appleARRAY[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
	1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
	1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
	1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
	1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
        vector <int> apple( appleARRAY, appleARRAY+ARRSIZE(appleARRAY) );
	int orangeARRAY[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
		1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
		1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
		1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 
		1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
        vector <int> orange( orangeARRAY, orangeARRAY+ARRSIZE(orangeARRAY) );
        WinterAndPresents theObject;
        eq(4, theObject.getNumber(apple, orange),1000002000000LL);
    }
}
// END CUT HERE
