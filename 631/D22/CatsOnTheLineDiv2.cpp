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

class CatsOnTheLineDiv2 {
public:
	string getAnswer(vector <int> position, vector <int> count, int time) {
		int N = position.size();
		
		vector <pii> v;
		for (int i = 0; i < N; i++) {
			v.push_back(mkp(position[i], count[i]));
		}
		sort(v.begin(), v.end());

		int st = -123456789;
		for (int i = 0; i < N; i++) {
			int pos = v[i].first;
			int cnt = v[i].second;
			int left = max(st, pos - time);
			
			if (pos + time < left) {
				return "Impossible";
			}

			int next_st = left + cnt;

			if (pos + time < next_st - 1) {
				return "Impossible";
			}
			st = next_st;
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

int main( int argc, char* argv[] ) {
	{
		int positionARRAY[] = {0};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {7};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv2 theObject;
		eq(0, theObject.getAnswer(position, count, 3),"Possible");
	}
	{
		int positionARRAY[] = {0};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {8};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv2 theObject;
		eq(1, theObject.getAnswer(position, count, 2),"Impossible");
	}
	{
		int positionARRAY[] = {0, 1};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {3, 1};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv2 theObject;
		eq(2, theObject.getAnswer(position, count, 0),"Impossible");
	}
	{
		int positionARRAY[] = {5, 0, 2};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {2, 3, 5};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv2 theObject;
		eq(3, theObject.getAnswer(position, count, 2),"Impossible");
	}
	{
		int positionARRAY[] = {5, 1, -10, 7, 12, 2, 10, 20};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {3, 4, 2, 7, 1, 4, 3, 4};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv2 theObject;
		eq(4, theObject.getAnswer(position, count, 6),"Possible");
	}
	return 0;
}
// END CUT HERE
