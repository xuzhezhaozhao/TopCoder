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

class TPS {
public:
    int minimalBeacons(vector <string> linked) {
        int res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string linkedARRAY[] = {"NYNN",
            "YNYN",
            "NYNY",
            "NNYN"};
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(0, theObject.minimalBeacons(linked),1);
    }
    {
        string linkedARRAY[] = {"NYYY",
            "YNNN",
            "YNNN",
            "YNNN"};
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(1, theObject.minimalBeacons(linked),2);
    }
    {
        string linkedARRAY[] = {"NNYNNNNNNN",
            "NNNNNYNNNN",
            "YNNYNNYNNN",
            "NNYNYNNYNN",
            "NNNYNYNNYN",
            "NYNNYNNNNY",
            "NNYNNNNNNN",
            "NNNYNNNNNN",
            "NNNNYNNNNN",
            "NNNNNYNNNN"}
           ;
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(2, theObject.minimalBeacons(linked),2);
    }
    {
        string linkedARRAY[] = {"NYNYNNYNN",
            "YNYNYNNYN",
            "NYNNNYNNY",
            "YNNNNNNNN",
            "NYNNNNNNN",
            "NNYNNNNNN",
            "YNNNNNNNN",
            "NYNNNNNNN",
            "NNYNNNNNN"};
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(3, theObject.minimalBeacons(linked),3);
    }
    {
        string linkedARRAY[] = {"NYYYYYYYYY",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN",
            "YNNNNNNNNN"}
           ;
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(4, theObject.minimalBeacons(linked),8);
    }
    {
        string linkedARRAY[] = {"N"};
        vector <string> linked( linkedARRAY, linkedARRAY+ARRSIZE(linkedARRAY) );
        TPS theObject;
        eq(5, theObject.minimalBeacons(linked),0);
    }
}
// END CUT HERE
