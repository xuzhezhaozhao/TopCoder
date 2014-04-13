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

const int INF = 1000;
int disA[9][9], disB[9][9];	// 两点间的距 离
int P[9];
class TreeUnionDiv2 {
public:
    int maximumCycles(vector <string> tree1, vector <string> tree2, int K) {
	int res = 0;
	int vexs = tree1.size();
	for (int i = 0; i < vexs; i++) {
		P[i] = i;
	}
	for (int i = 0; i < vexs; i++) {
		for (int j = 0; j < vexs; j++) {
			if ('X' == tree1[i][j]) {
				disA[i][j] = 1;
			} else {
				disA[i][j] = INF;
			}
			if ('X' == tree2[i][j]) {
				disB[i][j] = 1;
			} else {
				disB[i][j] = INF;
			}
		}
	}

	// Floyd 算法任意求两点间的距离
	for (int k = 0; k < vexs; k++) {
		for (int i = 0; i < vexs; i++) {
			for (int j = 0; j < vexs; j++){  
				if ( disA[i][j] > disA[i][k] + disA[k][j] ) {
					disA[i][j] = disA[i][k] + disA[k][j];
				}
				if ( disB[i][j] > disB[i][k] + disB[k][j] ) {
					disB[i][j] = disB[i][k] + disB[k][j];
				}
			}
		}
	}

	do {
		int c = 0;
		for (int i = 0; i < vexs; i++) {
			for (int j = i+1; j < vexs; j++) {
				if (disA[i][j] + disB[ P[i] ][ P[j] ] + 2 == K) {
					++c;
				}
			}
		}
		res = max(res, c);
	} while (next_permutation(P, P + vexs));

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string tree1ARRAY[] = {"-X",
	    "X-"}
	   ;
	vector <string> tree1( tree1ARRAY, tree1ARRAY+ARRSIZE(tree1ARRAY) );
	string tree2ARRAY[] = {"-X",
	    "X-"}
	   ;
	vector <string> tree2( tree2ARRAY, tree2ARRAY+ARRSIZE(tree2ARRAY) );
	TreeUnionDiv2 theObject;
	eq(0, theObject.maximumCycles(tree1, tree2, 4),1);
    }
    {
	string tree1ARRAY[] = {"-X-",
	    "X-X",
	    "-X-"}
	   ;
	vector <string> tree1( tree1ARRAY, tree1ARRAY+ARRSIZE(tree1ARRAY) );
	string tree2ARRAY[] = {"-X-",
	    "X-X",
	    "-X-"}
	   ;
	vector <string> tree2( tree2ARRAY, tree2ARRAY+ARRSIZE(tree2ARRAY) );
	TreeUnionDiv2 theObject;
	eq(1, theObject.maximumCycles(tree1, tree2, 5),2);
    }
    {
	string tree1ARRAY[] = {"-X-",
	    "X-X",
	    "-X-"};
	vector <string> tree1( tree1ARRAY, tree1ARRAY+ARRSIZE(tree1ARRAY) );
	string tree2ARRAY[] = {"-X-",
	    "X-X",
	    "-X-"};
	vector <string> tree2( tree2ARRAY, tree2ARRAY+ARRSIZE(tree2ARRAY) );
	TreeUnionDiv2 theObject;
	eq(2, theObject.maximumCycles(tree1, tree2, 3),0);
    }
    {
	string tree1ARRAY[] = {"-X---",
	    "X-XXX",
	    "-X---",
	    "-X---",
	    "-X---"}
	   ;
	vector <string> tree1( tree1ARRAY, tree1ARRAY+ARRSIZE(tree1ARRAY) );
	string tree2ARRAY[] = {"-X-X-",
	    "X-X-X",
	    "-X---",
	    "X----",
	    "-X---"}
	   ;
	vector <string> tree2( tree2ARRAY, tree2ARRAY+ARRSIZE(tree2ARRAY) );
	TreeUnionDiv2 theObject;
	eq(3, theObject.maximumCycles(tree1, tree2, 6),5);
    }
    {
	string tree1ARRAY[] = {"-XX------",
	    "X------X-",
	    "X--XX-X--",
	    "--X--X---",
	    "--X------",
	    "---X----X",
	    "--X------",
	    "-X-------",
	    "-----X---"}
	   
	   ;
	vector <string> tree1( tree1ARRAY, tree1ARRAY+ARRSIZE(tree1ARRAY) );
	string tree2ARRAY[] = {"-X-------",
	    "X-X------",
	    "-X-XX----",
	    "--X---X--",
	    "--X--X---",
	    "----X--XX",
	    "---X-----",
	    "-----X---",
	    "-----X---"}
	   ;
	vector <string> tree2( tree2ARRAY, tree2ARRAY+ARRSIZE(tree2ARRAY) );
	TreeUnionDiv2 theObject;
	eq(4, theObject.maximumCycles(tree1, tree2, 7),17);
    }
}
// END CUT HERE
