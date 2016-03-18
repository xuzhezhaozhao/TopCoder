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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class BearSortsDiv2 {
public:
	vector <int> seq;
	int N;
	double solve(int left, int right) {
		// base case
		if (left+1 >= right) {
			return 1.0;
		}
		
		int mid = (left +right) / 2;
		// right-left elements
		// part1: left,left+1,...,mid-1
		// part2: mid,mid+1,...,right-1
		double p = solve(left, mid) * solve(mid, right);

		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < N; i++) {
			if (seq[i] >= left && seq[i] < mid) {
				++cnt1;
				if (cnt2 != right-mid) {
					p *= 0.5;
				}
			} else if (seq[i] >= mid && seq[i] < right) {
				++cnt2;
				if (cnt1 != mid-left) {
					p *= 0.5;
				}
			}
		}
		return p;
	}
    double getProbability(vector <int> seq) {
        double res = 0.0;
		for (auto x : seq) {
			this->seq.push_back(x-1);
		}
		this->N = seq.size();

		res = log( solve(0, N) );

        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int seqARRAY[] = {1,2};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        BearSortsDiv2 theObject;
        eq(0, theObject.getProbability(seq),-0.6931471805599453);
    }
    {
        int seqARRAY[] = {1,3,2};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        BearSortsDiv2 theObject;
        eq(1, theObject.getProbability(seq),-1.3862943611198906);
    }
    {
        int seqARRAY[] = {10,13,18,2,4,6,24,22,19,5,7,20,23,14,21,17,25,3,1,11,12,8,15,16,9};
        vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
        BearSortsDiv2 theObject;
        eq(2, theObject.getProbability(seq),-57.53121598647546);
    }
	return 0;
}
// END CUT HERE
