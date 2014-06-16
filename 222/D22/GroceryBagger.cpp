#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
	if ( delim.find( s[i] ) != string::npos ) {
	    if ( !t.empty() ) {
		res.push_back( t );
		t = "";
	    }
	} else {
	    t += s[i];
	}
    }
    if ( !t.empty() ) {
	res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
	res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

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

/************** Program  Begin *********************/

class GroceryBagger {
public:
    int minimumBags(int strength, vector <string> itemType) {
	    int res = 0;
	    map <string, int> msi;
	    for (int i = 0; i < itemType.size(); i++) {
	    	msi[ itemType[i] ] = 0;
	    }

	    for (int i = 0; i < itemType.size(); i++) {
	    	++msi[ itemType[i] ];
	    }

	    for ( map<string, int>::iterator it = msi.begin(); 
		    it != msi.end(); it++) {
	    	res += (it->second + strength - 1) / strength;
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
