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
const int MAX = 27;
int cnt[MAX];
int mat[MAX];
class FoxAndHandle {
public:
	bool remainMatch(string & S, int pos)
	{
		memcpy(mat, cnt, sizeof(cnt));
		for (int i = pos; i < S.size(); i++) {
			--mat[ S[i] - 'a' ];
		}
		for (int i = 0; i < MAX; i++) {
			if (mat[i] > 0) {
				return false;
			}
		}
		return true;
	}
	string lexSmallestName(string S) {
		string res;
		int n = S.size();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			++cnt[ S[i] - 'a' ];
		}
		for (int i = 0; i < MAX; i++) {
			cnt[i] /= 2;
		}

		while (accumulate(cnt, cnt + MAX, 0) != 0) {
			int k = 0;
			for (; cnt[k] == 0; k++) {}
			--cnt[k];
			int pos = S.find_first_of(k + 'a');
			while ( !remainMatch(S, pos + 1) ) {
				// 如果剩余字符串不匹配
				++cnt[k];	// 恢复
				++k;		// 选择下一个字符作起始字符
				for (; cnt[k] == 0; k++) {}
				--cnt[k];
				pos = S.find_first_of(k + 'a');

			}
			// 可以匹配
			S = S.substr(pos + 1);
			res += (char)(k + 'a');
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		FoxAndHandle theObject;
		eq(0, theObject.lexSmallestName("foxfox"),"fox");
	}
	{
		FoxAndHandle theObject;
		eq(1, theObject.lexSmallestName("ccieliel"),"ceil");
	}
	{
		FoxAndHandle theObject;
		eq(2, theObject.lexSmallestName("abaabbab"),"aabb");
	}
	{
		FoxAndHandle theObject;
		eq(3, theObject.lexSmallestName("bbbbaaaa"),"bbaa");
	}
	{
		FoxAndHandle theObject;
		eq(4, theObject.lexSmallestName("fedcbafedcba"),"afedcb");
	}
	{
		FoxAndHandle theObject;
		eq(5, theObject.lexSmallestName("nodevillivedon"),"deilvon");
	}
}
// END CUT HERE
