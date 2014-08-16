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

class ConundrumReloaded {
public:
	int minimumLiars(string answers) {
		int res = 0;
		int N = answers.size();
		int first_qus = -1;
		for (int i = 0; i < N; i++) {
			if ('?' == answers[i]) {
				first_qus = i;
				break;
			}
		}
		if (-1 == first_qus) {	// all are be asked
			res = 1000;
			bool now = true;
			bool first = true;
			int liar_cnt = 0;
			for (int i = 0; i < N; i++) {
				liar_cnt += (now ? 0 : 1);
				if ( (answers[i] == 'H' && now) || 
					(answers[i] == 'L' && !now)) {
						now = true;
				} else {
					now = false;
				}
			}
			if (first == now) {
				res = liar_cnt;
			}
			now = false;
			first = false;
			liar_cnt = 0;
			for (int i = 0; i < N; i++) {
				liar_cnt += (now ? 0 : 1);
				if ( (answers[i] == 'H' && now) || 
					(answers[i] == 'L' && !now)) {
						now = true;
				} else {
					now = false;
				}
			}
			if (first == now) {
				res = min(res, liar_cnt);
			}
			res = (res == 1000 ? -1 : res);
		} else {
			int start = (first_qus + 1) % N;
			int cur = start;
			int seq_cnt = 0;
			int liar_cnt = 0;
			bool now = true;

			while (((cur + 1) % N) != start) {
				if (answers[cur] == '?') {
					liar_cnt += (now ? 0 : 1);
					++seq_cnt;
					now = true;
					res += min(liar_cnt, seq_cnt - liar_cnt);
					seq_cnt = 0;
					liar_cnt = 0;
					cur = (cur + 1) % N;
				} else {
					++seq_cnt;
					liar_cnt += (now ? 0 : 1);

					if ( (answers[cur] == 'H' && now) || 
						(answers[cur] == 'L' && !now)) {
						now = true;
					} else {
						now = false;
					}
					cur = (cur + 1) % N;
				}
			}
			liar_cnt += (now ? 0 : 1);
			++seq_cnt;
			res += min(liar_cnt, seq_cnt - liar_cnt);
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		ConundrumReloaded theObject;
		eq(0, theObject.minimumLiars("LLH"),1);
	}
	{
		ConundrumReloaded theObject;
		eq(1, theObject.minimumLiars("?????"),0);
	}
	{
		ConundrumReloaded theObject;
		eq(2, theObject.minimumLiars("LHLH?"),2);
	}
	{
		ConundrumReloaded theObject;
		eq(3, theObject.minimumLiars("??LLLLLL??"),3);
	}
	{
		ConundrumReloaded theObject;
		eq(4, theObject.minimumLiars("LLL"),-1);
	}
}
// END CUT HERE
