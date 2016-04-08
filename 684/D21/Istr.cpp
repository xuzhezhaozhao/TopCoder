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

class Istr {
public:
    int count(string s, int k) {
        int res = 0;
		int cnt[26] = {0};
		for (auto c : s) {
			++cnt[c - 'a'];
		}
		vector <int> v;
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				v.push_back(cnt[i]);
			}
		}
		sort(v.begin(), v.end(), greater<int>());
		int limit;
		bool have = false;
		int rem = 0;
		for (limit = v[0]; limit >= 0; limit--) {
			int deleted = 0;
			for (auto x : v) {
				if (x <= limit) {
					break;
				}
				// x > limit
				deleted += x - limit;
			}
			if (deleted > k) {
				rem = deleted - k;
				have = true;
				break;
			}
		}
		if (!have) {
			return 0;
		}

		for (int i = 0; i < v.size(); i++) {
			if (i < rem) {
				res += (limit+1)*(limit+1);
			} else {
				res += min(limit, v[i])*min(limit, v[i]);
			}
		}

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
        Istr theObject;
        eq(0, theObject.count("aba", 1),2);
    }
    {
        Istr theObject;
        eq(1, theObject.count("abacaba", 0),21);
    }
    {
        Istr theObject;
        eq(2, theObject.count("abacaba", 1),14);
    }
    {
        Istr theObject;
        eq(3, theObject.count("abacaba", 3),6);
    }
    {
        Istr theObject;
        eq(4, theObject.count("abc", 3),0);
    }
    {
        Istr theObject;
        eq(5, theObject.count("wersrsresesrsesrawsdsw", 11),23);
    }
	return 0;
}
// END CUT HERE
