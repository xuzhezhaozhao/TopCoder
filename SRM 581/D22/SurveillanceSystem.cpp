#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

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
#include <climits>
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

/************** Program  Begin *********************/
const int MAX = 50;
int flag[MAX];
class SurveillanceSystem {
public:
    string getContainerInfo(string containers, vector <int> reports, int L) {
	string res(containers.size(), '-');
	vector < vector<int> > pos( containers.size()+1 );	
				// pos[c]表示能够监视到c个'X'的所有的位置的起始处
	vector <int> rep_count( L+1 );	// rep_count[c]表示，reports中c出现的次数

	for (int i = 0; i <= containers.size()-L; i++) {
		int c = count(&containers[i], &containers[i]+L, 'X');	
				// 计算各个位置能监视到的'X'
		pos[c].push_back(i);
	}
	for (int i = 0; i < reports.size(); i++) {
		++rep_count[ reports[i] ];
	}

	for (int i = 0; i <= L; i++) {
		int rc = rep_count[i];
		if (rc == 0) {
			continue;
		}

		// 表示i在reports中出现rc次，而满足可以监视到i个'X'的段保存在pos[i]中，
		// 一共有pos[i].size个这样的段，也就是要从中选出rc个段，使用每个位置的
		// 重叠度来判断该位置是否一定会被监视到。位置的重叠度表示该位置在
		// pos[i].size个段中出现的次数。如果其出现次数大于pos[i].size-rc，则
		// 这个位置一定会被监视到。因为如果这个位置没有被监视的话，那么找不符合
		// 条件的rc个段。
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < pos[i].size(); j++) {
			for (int k = 0; k < L; k++) {
				if ('-' == res[ pos[i][j] + k ]) {
					// 在段中出现的位置置为'?'
					res[ pos[i][j] + k ] = '?';
				}
				++flag[ pos[i][j]+k ];	// 该位置重叠度加1
			}
		}
		for (int j = 0; j < containers.size(); j++) {
			if (flag[j] > pos[i].size() - rc) {	
					//判断重叠度，判断该位置是否必定被监视
				res[j] = '+';
			}
		}
	}

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int reportsARRAY[] = {1};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(0, theObject.getContainerInfo("X", reports, 1),"+");
    }
    {
	int reportsARRAY[] = {2};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(1, theObject.getContainerInfo("-XXXXX-", reports, 3),"???-???");
    }
    {
	int reportsARRAY[] = {3, 0, 2, 0};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(2, theObject.getContainerInfo("------X-XX-", reports, 5),"++++++++++?");
    }
    {
	int reportsARRAY[] = {2, 1, 0, 1};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(3, theObject.getContainerInfo("-XXXXX---X--", reports, 3),"???-??++++??");
    }
    {
	int reportsARRAY[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector <int> reports( reportsARRAY, reportsARRAY+ARRSIZE(reportsARRAY) );
	SurveillanceSystem theObject;
	eq(4, theObject.getContainerInfo("-XX--X-XX-X-X--X---XX-X---XXXX-----X", reports, 7),"???++++?++++++++++++++++++++??????--");
    }
}
// END CUT HERE
