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

class Egalitarianism2 {
public:
    double minStdev(vector <int> x, vector <int> y) {
        double res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {0,0,1,1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1,0,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(0, theObject.minStdev(x, y),0.0);
    }
    {
        int xARRAY[] = {0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,9,10};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(1, theObject.minStdev(x, y),0.5);
    }
    {
        int xARRAY[] = {12,46,81,56};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,45,2,67};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(2, theObject.minStdev(x, y),6.102799971320872);
    }
    {
        int xARRAY[] = {0,0,0,0,0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,2,3,9,10,15,16};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(3, theObject.minStdev(x, y),0.9428090415820617);
    }
    {
        int xARRAY[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(4, theObject.minStdev(x, y),40056.95946451678);
    }
    {
        int xARRAY[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Egalitarianism2 theObject;
        eq(5, theObject.minStdev(x, y),36879.1512763429);
    }
}
// END CUT HERE
