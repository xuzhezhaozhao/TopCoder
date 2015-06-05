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

/*************** Program Begin **********************/

class SuffixArrayDiv2 {
public:
	// 求后缀数组
	vector <int> getSuffiexArray(string s)
	{
		vector <string> suf;
		for (int i = 0; i < s.size(); i++) {
			suf.push_back(s.substr(i));
		}

		vector <int> sufarr(s.size());
		vector < pair<string, int> > v;

		for (int i = 0; i < s.size(); i++) {
			v.push_back(mkp(suf[i], i));
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < s.size(); i++) {
			sufarr[i] = v[i].second;
		}
		return sufarr;
	}

	string smallerOne(string s) {
		int N = s.size();
		vector <int> sufarr = getSuffiexArray(s);
		vector <int> rank(N);
		for (int i = 0; i < N; i++) {
			rank[ sufarr[i] ] = i;
		}

		string minS(N, ' ');	// 后缀数组为sufarr的最小字符串
		// 构造minS
		char c = 'a';
		minS[ sufarr[0] ] = 'a';
		for (int i = 1; i < N; i++) {
			int pos1 = sufarr[i - 1] + 1;
			int pos2 = sufarr[i] + 1;
			if (pos2 >= N) {
				++c;
			} else {
				if (pos1 < N && rank[pos1] > rank[pos2]) {
					++c;
				}
			}

			minS[ sufarr[i] ] = c;
		}

		return (minS == s ? "Does not exist" : "Exists");
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		SuffixArrayDiv2 theObject;
		eq(0, theObject.smallerOne("abca"),"Exists");
	}
	{
		SuffixArrayDiv2 theObject;
		eq(1, theObject.smallerOne("bbbb"),"Exists");
	}
	{
		SuffixArrayDiv2 theObject;
		eq(2, theObject.smallerOne("aaaa"),"Does not exist");
	}
	{
		SuffixArrayDiv2 theObject;
		eq(3, theObject.smallerOne("examplesareveryweakthinktwicebeforesubmit"),"Exists");
	}
}
// END CUT HERE
