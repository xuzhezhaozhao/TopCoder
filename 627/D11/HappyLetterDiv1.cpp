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
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class HappyLetterDiv1 {
public:
	bool check(int x, string & letters) {
		vector <int> cnt;
		for (int c = 'a'; c <= 'z'; c++) {
			if (x == c) {
				continue;
			}
			int t = count(letters.begin(), letters.end(), c);
			if (t != 0) {
				cnt.push_back(t);
			}
		}
		sort(cnt.begin(), cnt.end());
		while (cnt.size() > 1) {
			int n = cnt.size();
			--cnt[n-1];
			--cnt[n-2];
			cnt.erase(remove(cnt.begin(), cnt.end(), 0), cnt.end());
			sort(cnt.begin(), cnt.end());
		}
		int xcnt = count(letters.begin(), letters.end(), x);
		if (xcnt > accumulate(cnt.begin(), cnt.end(), 0)) {
			return true;
		}
		return false;
			
	}
	string getHappyLetters(string letters) {
		string res;
		for (int c = 'a'; c <= 'z'; c++) {
			if (check(c, letters)) {
				res.push_back(c);
			}
		}
		sort(res.begin(), res.end());
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		HappyLetterDiv1 theObject;
		eq(0, theObject.getHappyLetters("aabbacccc"),"abc");
	}
	{
		HappyLetterDiv1 theObject;
		eq(1, theObject.getHappyLetters("aaaaaaa"),"a");
	}
	{
		HappyLetterDiv1 theObject;
		eq(2, theObject.getHappyLetters("ddabccadb"),"abcd");
	}
	{
		HappyLetterDiv1 theObject;
		eq(3, theObject.getHappyLetters("aaabbb"),"");
	}
	{
		HappyLetterDiv1 theObject;
		eq(4, theObject.getHappyLetters("rdokcogscosn"),"cos");
	}
	{
		HappyLetterDiv1 theObject;
		eq(4, theObject.getHappyLetters("ocoooccscloolllll"),"clos");
	}
	return 0;
}
// END CUT HERE
