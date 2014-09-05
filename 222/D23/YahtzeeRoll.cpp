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

class YahtzeeRoll {
public:
	vector <int> dice;
	int N;

	double score(vector <int> d)
	{
		sort(d.begin(), d.end());
		if (d[0] == d[4]) {
			return 50;
		}
		if (d[4] == d[3] + 1 && d[4] == d[2] + 2 && d[4] == d[1] + 3 && d[4] == d[0] + 4) {
			return 40;
		}
		vector <int> temp = d;
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		if (temp.size() >= 4) {
			if (temp[3] == temp[2] + 1 && temp[3] == temp[1] + 2 && temp[3] == temp[0] + 3) {
				return 30;
			}
			int n = temp.size();
			if (temp[n - 1] == temp[n - 2] + 1 && temp[n - 1] == temp[n - 3] + 2 && temp[n - 1] == temp[n - 4] + 3) {
				return 30;
			}
		}
		if (2 == temp.size()) {
			if (d[0] == d[1] && d[3] == d[4]) {
				return 25;
			}
		}
		return 0;
	}

	double backtrack(int p, vector <int> d, vector <int> & selected)
	{
		double ans = 0;
		if (p == N) {
			ans = score(d);
		} else {
			if (selected[p]) {
				for (int i = 1; i <= 6; i++) {
					d[p] = i;
					ans += backtrack(p + 1, d, selected) / 6;
				}
			} else {
				d[p] = dice[p];
				ans = backtrack(p + 1, d, selected);
			}
		}
		return ans;
	}

	double bestChoice(vector <int> dice) {
		double res = 0.0;
		this->dice = dice;
		this->N = dice.size();

		for (int choice = 0; choice < (1 << N); choice++) {
			vector <int> selected;
			for (int j = 0; j < 5; j++) {
				selected.push_back(1 & (choice >> j));
			}
			res = max(res, backtrack(0, dice, selected));
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

void main( int argc, char* argv[] ) {
	{
		int diceARRAY[] = { 1, 1, 1, 1, 2 };
		vector <int> dice( diceARRAY, diceARRAY+ARRSIZE(diceARRAY) );
		YahtzeeRoll theObject;
		eq(0, theObject.bestChoice(dice),8.333333333333334);
	}
	{
		int diceARRAY[] = { 1, 1, 1, 2, 2 };
		vector <int> dice( diceARRAY, diceARRAY+ARRSIZE(diceARRAY) );
		YahtzeeRoll theObject;
		eq(1, theObject.bestChoice(dice),25.0);
	}
	{
		int diceARRAY[] = { 2, 3, 4, 5, 5 };
		vector <int> dice( diceARRAY, diceARRAY+ARRSIZE(diceARRAY) );
		YahtzeeRoll theObject;
		eq(2, theObject.bestChoice(dice),33.333333333333336);
	}
	{
		int diceARRAY[] = { 2, 2, 3, 4, 4 };
		vector <int> dice( diceARRAY, diceARRAY+ARRSIZE(diceARRAY) );
		YahtzeeRoll theObject;
		eq(3, theObject.bestChoice(dice),17.77777777777778);
	}
	{
		int diceARRAY[] = { 6, 1, 3, 5, 5 };
		vector <int> dice( diceARRAY, diceARRAY+ARRSIZE(diceARRAY) );
		YahtzeeRoll theObject;
		eq(4, theObject.bestChoice(dice),9.722222222222221);
	}
}
// END CUT HERE
