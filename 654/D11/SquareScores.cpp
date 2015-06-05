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

class SquareScores {
public:
    double calcexpectation(vector <int> p, string s) {
        double res = 0;
		int N = s.size();
		for (int i = (int)p.size(); i < 26; i++) {
			p.push_back(0);
		}

		res += N;
		for (int len = 2; len <= N; len++) {
			for (int i = 0; i <= N - len; i++) {
				string substr = s.substr(i, len);
				res += calc(p, substr);
			}
		}

        return res;
    }

	double calc(vector <int> &p, string &s) {
		int sz = s.size();
		char pre = ' ';
		bool ok = true;
		int cnt = 0;
		for (auto c : s) {
			if (c != '?') {
				if (pre != ' ' && c != pre) {
					ok = false;
					break;
				}
				pre = c;
			} else {
				++cnt;
			}
		}
		if (!ok) {
			return 0;
		}
		double res = 0;
		if (pre == ' ') {
			for (int i = 0; i < 26; i++) {
				res += pow(p[i] / 100.0, cnt);
			}
		} else {
			res += pow(p[pre - 'a'] / 100.0, cnt);
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
        int pARRAY[] = {1, 99};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(0, theObject.calcexpectation(p, "aaaba"),8.0);
    }
    {
        int pARRAY[] = {10, 20, 70};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(1, theObject.calcexpectation(p, "aa?bbbb"),15.0);
    }
    {
        int pARRAY[] = {10, 20, 30, 40};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(2, theObject.calcexpectation(p, "a??c?dc?b"),11.117);
    }
    {
        int pARRAY[] = {25, 25, 21, 2, 2, 25};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(3, theObject.calcexpectation(p, "a??b???????ff??e"),21.68512690712425);
    }
    {
        int pARRAY[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(4, theObject.calcexpectation(p, "??????????????????????????????"),31.16931963781721);
    }
    {
        int pARRAY[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        SquareScores theObject;
        eq(5, theObject.calcexpectation(p, "makigotapresentfromniko"),23.0);
    }
	return 0;
}
// END CUT HERE
