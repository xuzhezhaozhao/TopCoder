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
const int MAX = 50 * 60000 / 2 + 60000;
long long dp[MAX];
class YetAnotherTwoTeamsProblem {
public:
	int n, sum;
	vector <int> skill;
	//long long rec(int cur, int first)
	//{
	//	递归法，使用内存过大，不可用，dp[51][50 * 60000 / 2 + 60000]
	//	if (cur == n) {
	//		if (2 * first > sum) {
	//			return 1;
	//		} else {
	//			return 0;
	//		}
	//	}
	//	long long & res = dp[cur][first];
	//	if (res != -1) {
	//		return res;
	//	}
	//	res = 0;
	//	// not add skill[cur]
	//	res += rec(cur + 1, first);
	//	if (2 * first < sum) {
	//		// add skill[cur]
	//		res += rec(cur + 1, first + skill[cur]);
	//	}
	//	return res;
	//}

	long long count(vector <int> skill) {
		long long res = 0;
		n = skill.size();
		sum = accumulate(skill.begin(), skill.end(), 0);
		sort(skill.begin(), skill.end(), greater <int>());
		this->skill = skill;

		memset(dp, 0, sizeof(dp));
		for (int cur = n; cur >= 0; cur--) {
			for (int s = 0; s < MAX; s++) {
				if (n == cur) {
					dp[s] = (2 * s > sum ? 1 : 0);
					continue;
				}
				if (2 * s < sum) {
					dp[s] += dp[ s + skill[cur] ];
				}
			}
		}
		res = dp[0];

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int skillARRAY[] = {56709, 32581, 23159, 40328, 14924, 22231, 14457, 53622, 14346, 55254, 58820, 57260, 14223, 12245, 28234, 56764, 32034, 34198, 54543, 
			27911, 37030, 33276, 48299, 54512, 53249, 8496, 23860, 35884, 33915, 599, 24252, 54549, 20933, 35243, 25862, 31680, 39485, 37801, 43943, 4239, 58292, 36666, 15207, 33481, 51105, 24892, 3437};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		YetAnotherTwoTeamsProblem theObject;
		eq(0, theObject.count(skill),2LL);
	}
	{
		int skillARRAY[] = {1, 1, 1, 1, 1};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		YetAnotherTwoTeamsProblem theObject;
		////eq(1, theObject.count(skill),10LL);
	}
	{
		int skillARRAY[] = {1, 2, 3, 5, 10};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		YetAnotherTwoTeamsProblem theObject;
		//eq(2, theObject.count(skill),5LL);
	}
	{
		int skillARRAY[] = {1, 2, 3, 4, 10};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		YetAnotherTwoTeamsProblem theObject;
		//eq(3, theObject.count(skill),0LL);
	}
	{
		int skillARRAY[] = {999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
			1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000};
		vector <int> skill( skillARRAY, skillARRAY+ARRSIZE(skillARRAY) );
		YetAnotherTwoTeamsProblem theObject;
		eq(4, theObject.count(skill),17672631900LL);
	}
}
// END CUT HERE
