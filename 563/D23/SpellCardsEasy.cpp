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
int dp[55][55];
class SpellCardsEasy {
public:
	int n;
	vector <int> level, damage;
	int rec(int cur, int owned)
	{
		if (n - cur == owned) {
			return 0;
		}
		int & res = dp[cur][owned];
		if (res != -1) {
			return res;
		}
		// not choose
		res = rec(cur + 1, max(0, owned - 1) );
		// choose
		if ( owned + level[cur] - 1 <= n - cur - 1) {
			res = max(res, damage[cur] + rec(cur + 1, owned + level[cur] - 1) );
		}
	
		return res;
	}
	int maxDamage(vector <int> level, vector <int> damage) {
		int res = 0;
		n = level.size();
		this->level = level;
		this->damage = damage;
		memset(dp, -1, sizeof(dp));
		res = rec(0, 0);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int levelARRAY[] = {5, 31, 5, 9, 31, 20, 3, 20};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {145, 356, 142, 514, 284, 639, 117, 377};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(0, theObject.maxDamage(level, damage),145);
	}
	{
		int levelARRAY[] = {2,2};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {10,20};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(1, theObject.maxDamage(level, damage),10);
	}
	{
		int levelARRAY[] = {4,4,4};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {10,20,30};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(2, theObject.maxDamage(level, damage),0);
	}
	{
		int levelARRAY[] = {50,1,50,1,50};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {10,20,30,40,50};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(3, theObject.maxDamage(level, damage),60);
	}
	{
		int levelARRAY[] = {2,1,1};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {40,40,10};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(4, theObject.maxDamage(level, damage),80);
	}
	{
		int levelARRAY[] = {1,2,1,1,3,2,1};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {10,40,10,10,90,40,10};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(5, theObject.maxDamage(level, damage),150);
	}
	{
		int levelARRAY[] = {1,2,2,3,1,4,2};
		vector <int> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
		int damageARRAY[] = {113,253,523,941,250,534,454};
		vector <int> damage( damageARRAY, damageARRAY+ARRSIZE(damageARRAY) );
		SpellCardsEasy theObject;
		eq(6, theObject.maxDamage(level, damage),1577);
	}
}
// END CUT HERE
