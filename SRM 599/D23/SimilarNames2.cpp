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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)

/*************** Program Begin **********************/
const int MOD = 1000000007;
int dp[55][55];

class SimilarNames2 {
public:
	int L, n;
	vector <string> names;

	bool isPrefix(string s, string mathch)
	{
		if (s.size() < mathch.size()) {
			return false;
		} else {
			return ( mathch == s.substr(0, mathch.size()) );
		}
	}
	int rec(int cur, int s)
	{
		if (cur == L) {
			return 1;
		}
		int & res = dp[cur][s];
		if (res != -1) {
			return res;
		}
		res = 0;
		for (int i = 0; i < n; i++) {
			if (i != s && isPrefix(names[i], names[s])) {
				res += rec(cur + 1, i);
				res %= MOD;
			}
		}
		return res;
	}

	int count(vector <string> names, int L) {
		this->L = L;
		this->names = names;
		this->n = names.size();
		memset(dp, -1, sizeof(dp));
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += rec(1, i);
			res %= MOD;
		}
		for (int i = 1; i <= n - L; i++) {
			res *= i;
			res %= MOD;
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string namesARRAY[] = {"kenta", "kentaro", "ken"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		//eq(0, theObject.count(names, 2),3);
	}
	{
		string namesARRAY[] = {"hideo", "hideto", "hideki", "hide"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		eq(1, theObject.count(names, 2),6);
	}
	{
		string namesARRAY[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		eq(2, theObject.count(names, 3),24);
	}
	{
		string namesARRAY[] = {"taro", "jiro", "hanako"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		eq(3, theObject.count(names, 2),0);
	}
	{
		string namesARRAY[] = {"alice", "bob", "charlie"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		eq(4, theObject.count(names, 1),6);
	}
	{
		string namesARRAY[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
			"ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
		vector <string> names( namesARRAY, namesARRAY+ARRSIZE(namesARRAY) );
		SimilarNames2 theObject;
		eq(5, theObject.count(names, 3),276818566);
	}
}
// END CUT HERE
