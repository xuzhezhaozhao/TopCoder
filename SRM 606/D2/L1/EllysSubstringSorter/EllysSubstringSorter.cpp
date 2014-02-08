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

class EllysSubstringSorter {
public:
    string getMin(string S, int L) {
        string res;
	set <string> st;
	int len = S.size();
	string t;
	for (int i = 0; i <= len - L; i++) {
		t = S;
		sort(t.begin() + i, t.begin() + i + L);
		st.insert(t);
	}
	res = ( *st.begin() );
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        EllysSubstringSorter theObject;
        eq(0, theObject.getMin("TOPCODER", 4),"COPTODER");
    }
    {
        EllysSubstringSorter theObject;
        eq(1, theObject.getMin("ESPRIT", 3),"EPRSIT");
    }
    {
        EllysSubstringSorter theObject;
        eq(2, theObject.getMin("AAAAAAAAA", 2),"AAAAAAAAA");
    }
    {
        EllysSubstringSorter theObject;
        eq(3, theObject.getMin("ABRACADABRA", 5),"AAABCRDABRA");
    }
    {
        EllysSubstringSorter theObject;
        eq(4, theObject.getMin("BAZINGA", 6),"ABGINZA");
    }
    {
        EllysSubstringSorter theObject;
        eq(5, theObject.getMin("AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD", 21),"AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD");
    }
}
// END CUT HERE
