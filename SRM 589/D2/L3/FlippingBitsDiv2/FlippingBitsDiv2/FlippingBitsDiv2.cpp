#include <algorithm>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <bitset>
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


class FlippingBitsDiv2 {
public:
    int getmin(vector <string> S, int M) {
	int res = 0;
	string s;
	for (int i = 0; i < S.size(); i++) {
		s += S[i];
	}
	int N = s.size();
	int K = N / M;
	string one(N, '1');
	bitset <2500> B(s);
	bitset <2500> O(one);
	queue < pair <bitset<2500>, int> > Q;
	Q.push(make_pair(O, 0));
	map < bitset<2500>, int > Map;
	Map[O] = 0;
	while ( !Q.empty() ) {
		 pair <bitset<2500>, int> temp = Q.front();
		 Q.pop();
		 if (temp.first == B) {
		 	return temp.second;
		 }
		 for (int i = 0; i < N; i++) {
		 	temp.first.flip(i);
			++temp.second;
			if (Map.insert(temp).second) {
				Q.push(temp);
			}
			temp.first.flip(i);
			--temp.second;
		 }
	}

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string SARRAY[] = {"00111000"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(0, theObject.getmin(S, 1),2);
    }
    {
	string SARRAY[] = {"00111000"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(1, theObject.getmin(S, 2),3);
    }
    {
	string SARRAY[] = {"111111"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(2, theObject.getmin(S, 3),0);
    }
    {
	string SARRAY[] = {"00100"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(3, theObject.getmin(S, 5),2);
    }
    {
	string SARRAY[] = {"00010","11010110","1010111","110001010","0110001100"
	   ,"000110110","011010101","00","111","100"}
	   ;
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(4, theObject.getmin(S, 13),31);
    }
}
// END CUT HERE
