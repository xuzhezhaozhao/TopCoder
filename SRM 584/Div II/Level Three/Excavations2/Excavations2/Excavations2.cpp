// BEGIN CUT HERE

// END CUT HERE
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

/*******************************************************/
/******************************************************/
/************** Program  Begin *********************/
#define FOR(i,j,k) for(i=j;i<=k;i++) 
#define REP(i,j) for(i=0;i<j;i++) 
long long c[100][100],f[100][100]; 
int num[100]; 
class Excavations2 {
public:
	long long count(vector <int> kind, vector <int> found, int K) 
	{ 
		int i,j,k; 
		for (int i = 0; i < 100; i++) {
			num[i] = 0;
			for (int j = 0; j < 100; j++) {
				c[i][j] = f[i][j] = 0;
			}
		}
		
		c[0][0]=1; 
		FOR(i,1,50) 
		{ 
			c[i][0]=c[i][i]=1; 
			FOR(j,1,i-1)c[i][j]=c[i-1][j]+c[i-1][j-1]; 
		} 
		for(i=0;i<kind.size();i++)num[kind[i]]++; 
		f[0][0]=1; 
		for(j=0;j<found.size();j++) 
		{ 
			for(i=0;i<=K;i++) 
			{ 
				FOR(k,1,num[found[j]]) 
					if(i-k>=0) 
					{ 
						f[j+1][i]+=c[num[found[j]]][k]*f[j][i-k]; 
					} 
					f[j+1][0]=0; 
			} 
		} 
		int m = found.size();
		return f[m][K]; 
	} 
};
/************** Program End ************************/
/******************************************************/
/******************************************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int kindARRAY[] = {1, 2, 2, 1};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {1};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(0, theObject.count(kind, found, 2), 1LL);
    }
    {
	int kindARRAY[] = {1, 2, 2, 1};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {1, 2};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(1, theObject.count(kind, found, 2), 4LL);
    }
    {
	int kindARRAY[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {4, 2};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(2, theObject.count(kind, found, 3), 6LL);
    }
    {
	int kindARRAY[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
	vector <int> kind( kindARRAY, kindARRAY+ARRSIZE(kindARRAY) );
	int foundARRAY[] = {50};
	vector <int> found( foundARRAY, foundARRAY+ARRSIZE(foundARRAY) );
	Excavations2 theObject;
	eq(3, theObject.count(kind, found, 21),5567902560LL);
    }
}
// END CUT HERE
