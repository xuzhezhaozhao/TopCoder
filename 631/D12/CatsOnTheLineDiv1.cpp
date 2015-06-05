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

class CatsOnTheLineDiv1 {
public:
	int getNumber(vector <int> position, vector <int> count, int time) {
		int N = position.size();
		vector <pii> v;
		for (int i = 0; i < N; i++) {
			v.push_back(mkp(position[i], count[i]));
		}
		sort(v.begin(), v.end());
		
		int bad = 0;
		int non_conf_right = -2000000020;
		int conf_right = 0;
		for (int i = 0; i < N; i++) {
			int cnt = v[i].second;
			int pos_left = v[i].first - time;
			int pos_right = v[i].first + time;
			if ( bad != 0 && pos_left <= conf_right ) {
				continue;
			} else {
				int valid_left = max(non_conf_right + 1, pos_left);
				if (pos_right - valid_left + 1 >= cnt) {
					// ok, no conflict
					non_conf_right = valid_left + cnt - 1;
				} else {
					// new conflict
					conf_right = pos_right;
					++bad;
				}
			}
		}
		return bad;
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
		CatsOnTheLineDiv1 theObject;
		eq(0, theObject.getNumber(position, count, 3),0);
	}
	{
		int positionARRAY[] = {0};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {6};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv1 theObject;
		eq(1, theObject.getNumber(position, count, 2),1);
	}
	{
		int positionARRAY[] = {4, 7, 47};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {4, 7, 4};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv1 theObject;
		eq(2, theObject.getNumber(position, count, 1),3);
	}
	{
		int positionARRAY[] = {3, 0, 7, 10};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {3, 7, 4, 5};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv1 theObject;
		eq(3, theObject.getNumber(position, count, 2),2);
	}
	{
		int positionARRAY[] = {-5, 0, 7};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {47, 85, 10};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv1 theObject;
		eq(4, theObject.getNumber(position, count, 6),1);
	}
	{
		int positionARRAY[] = {-8, 12, -15, -20, 17, -5, 7, 10};
		vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
		int countARRAY[] = {20, 10, 7, 9, 2, 8, 11, 10};
		vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
		CatsOnTheLineDiv1 theObject;
		eq(5, theObject.getNumber(position, count, 2),5);
	}
	return 0;
}
// END CUT HERE
