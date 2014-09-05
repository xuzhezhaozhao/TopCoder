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

class InverseRMQ {
public:
    string possible(int n, vector <int> A, vector <int> B, vector <int> ans) {
	int m = A.size();
	vector <int> d;
	vector <pii> intervals;
	for (int i = 0; i < m; i++) {
		d.push_back(A[i]);
		d.push_back(B[i]);
	}
	d.erase(unique(d.begin(), d.end()), d.end());
	sort(d.begin(), d.end());

	for (int i = 0; i < d.size(); i++) {
		intervals.push_back(mkp(d[i], d[i]));
		if (i + 1 < d.size()) {
			intervals.push_back(mkp(d[i], d[i + 1]));
		}
	}

	for (int i = 0; i < m; i++) {
		int H = ans[i]; 

		// 验证条件1
		// H has to lie in the intersection of all those intervals that are
		//+ supposed to have H as their maximum
		int left = 1;
		int right = n;
		for (int j = 0; j < m; j++) {
			if (ans[j] == H) {
				if (left <= B[j] && right >= A[j]) {
					// 有交集, 求交集
					if (A[j] > left) {
						left = A[j];
					}
					if (B[j] < right) {
						right = B[j];
					}
				} else {
					// 无交集，invalid
					return "Impossible";
				}
			}
		}

		// 验证条件2
		// The union of all intervals with maxima smaller than H must not contain
		//+ the entire interval I(left, right).
		bool cover[256] = {false};
		for (int k = 0; k < intervals.size(); k++) {
			int a = intervals[k].first;
			int b = intervals[k].second;
			for (int j = 0; j < m; j++) {
				if (ans[j] < H && A[j] <= a && B[j] >= b) {
					cover[k] = true;
					break;
				}
			}
		}
		bool ok = false;
		for (int k = 0; k < intervals.size(); k++) {
			if (!cover[k] && left <= intervals[k].first && right >= intervals[k].second) {
				if (intervals[k].second - intervals[k].first == 1) {
					if (cover[k-1] && cover[k+1]) {
						continue;
					}
				}

				ok = true;
				break;
			}
		}
		if (!ok) {
			return "Impossible";
		}

		// 验证条件3
		// The total length of the union of all intervals with maxima smaller 
		//+ than or equal to H must not exceed H.
		int cnt = 0;
		bool pre_ok = false;
		for (int k = 0; k < intervals.size(); k++) {
			int a = intervals[k].first, b = intervals[k].second;
			bool ok = false;
			for (int j = 0; j < m; j++) {
				if (ans[j] <= H && A[j] <= a && B[j] >= b) {
					ok = true;
					break;
				}
			}
			if (ok) {
				cnt += b - a + 1;
				if (pre_ok) {
					--cnt;
				}
			}
			pre_ok = ok;
		}

		if (cnt > H) {
			return "Impossible";
		}
	}

        return "Possible";
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

void main( int argc, char* argv[] ) {
    {
	    //{10, {4, 5, 6}, {5, 6, 7}, {6, 7, 5}}
        int AARRAY[] = {4, 5, 6};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {5, 6, 7};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {6, 7, 5};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(0, theObject.possible(10, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {3,3,3};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(1, theObject.possible(3, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,101,201,301,401,501};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {100,200,300,400,500,600};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {100,200,300,400,500,600};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(2, theObject.possible(600, A, B, ans),"Possible");
    }
    {
        int AARRAY[] = {1234,1234};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {5678,5678};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {10000,20000};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(3, theObject.possible(1000000000, A, B, ans),"Impossible");
    }
    {
        int AARRAY[] = {1,2,3,4,5,6,7,8};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1,2,3,4,5,6,7,8};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {4,8,2,5,6,3,7,1};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(4, theObject.possible(8, A, B, ans),"Possible");
    }
    {
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1000000000};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int ansARRAY[] = {19911120};
        vector <int> ans( ansARRAY, ansARRAY+ARRSIZE(ansARRAY) );
        InverseRMQ theObject;
        eq(5, theObject.possible(1000000000, A, B, ans),"Impossible");
    }
}
// END CUT HERE
