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

class LittleElephantAndRGB {
public:
    long long getNumber(vector <string> list, int minGreen) {
        long long res = 0;
	string s;
	for (int i = 0; i < list.size(); i++) {
		s += list[i];
	}
	int n = s.size();



        return res;
    }

};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string listARRAY[] = {"GRG"};
        vector <string> list( listARRAY, listARRAY+ARRSIZE(listARRAY) );
        LittleElephantAndRGB theObject;
        eq(0, theObject.getNumber(list, 2),1L);
    }
    {
        string listARRAY[] = {"GG", "GG"};
        vector <string> list( listARRAY, listARRAY+ARRSIZE(listARRAY) );
        LittleElephantAndRGB theObject;
        eq(1, theObject.getNumber(list, 3),9L);
    }
    {
        string listARRAY[] = {"GRBGRBBRG"};
        vector <string> list( listARRAY, listARRAY+ARRSIZE(listARRAY) );
        LittleElephantAndRGB theObject;
        eq(2, theObject.getNumber(list, 2),11L);
    }
    {
        string listARRAY[] = {"RRBRBBRRR", "R", "B"};
        vector <string> list( listARRAY, listARRAY+ARRSIZE(listARRAY) );
        LittleElephantAndRGB theObject;
        eq(3, theObject.getNumber(list, 1),0L);
    }
    {
        string listARRAY[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"};
        vector <string> list( listARRAY, listARRAY+ARRSIZE(listARRAY) );
        LittleElephantAndRGB theObject;
        eq(4, theObject.getNumber(list, 4),12430L);
    }
}
// END CUT HERE
