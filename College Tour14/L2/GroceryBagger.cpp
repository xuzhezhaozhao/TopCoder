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

class GroceryBagger {
public:
    int minimumBags(int strength, vector <string> itemType) {
        int res = 0;
	map <string, int> mp;
	for (int i = 0; i < itemType.size(); i++) {
		mp[ itemType[i] ] = mp[ itemType[i] ] + 1;
	}

	for (auto it = mp.begin(); it != mp.end(); ++it) {
		res += ( (*it).second - 1 ) / strength + 1;
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string itemTypeARRAY[] = {"DAIRY",
            "DAIRY",
            "PRODUCE",
            "PRODUCE",
            "PRODUCE",
            "MEAT"};
        vector <string> itemType( itemTypeARRAY, itemTypeARRAY+ARRSIZE(itemTypeARRAY) );
        GroceryBagger theObject;
        eq(0, theObject.minimumBags(2, itemType),4);
    }
    {
        string itemTypeARRAY[] = {"DAIRY",
            "DAIRY",
            "PRODUCE",
            "PRODUCE",
            "PRODUCE",
            "MEAT"};
        vector <string> itemType( itemTypeARRAY, itemTypeARRAY+ARRSIZE(itemTypeARRAY) );
        GroceryBagger theObject;
        eq(1, theObject.minimumBags(3, itemType),3);
    }
    {
        GroceryBagger theObject;
        eq(2, theObject.minimumBags(10, vector <string>()),0);
    }
    {
        string itemTypeARRAY[] = {"CANNED",   "CANNED",  "PRODUCE",
            "DAIRY",    "MEAT",    "BREAD",
            "HOUSEHOLD","PRODUCE", "FROZEN",
            "PRODUCE", "DAIRY"};
        vector <string> itemType( itemTypeARRAY, itemTypeARRAY+ARRSIZE(itemTypeARRAY) );
        GroceryBagger theObject;
        eq(3, theObject.minimumBags(5, itemType),7);
    }
    {
        string itemTypeARRAY[] = {"CANNED",   "CANNED",  "PRODUCE",
            "DAIRY",    "MEAT",    "BREAD",
            "HOUSEHOLD","PRODUCE", "FROZEN",
            "PRODUCE", "DAIRY"};
        vector <string> itemType( itemTypeARRAY, itemTypeARRAY+ARRSIZE(itemTypeARRAY) );
        GroceryBagger theObject;
        eq(4, theObject.minimumBags(2, itemType),8);
    }
}
// END CUT HERE
