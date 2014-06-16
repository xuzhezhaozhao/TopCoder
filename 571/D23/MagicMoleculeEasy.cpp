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
int sortedPower[55];
vector <int> magicPower;
vector <string> magicBond;
vector <pii> edges;
int k, n;
int res;

bool cmp(int i, int j)
{
	return (magicPower[i] > magicPower[j]);
}
class MagicMoleculeEasy {
public:
	inline bool isAdded(int x, long long used) { return ( used & (1LL << x) ); }
	inline long long add(int x, long long used) { return (used | (1LL << x) ); }
	void backtrack(int p, int cnt, long long used)
	{
		if (p == edges.size()) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (!isAdded( sortedPower[i], used )) {
					if (cnt < k) {
						++cnt;
						sum += magicPower[ sortedPower[i] ];
					}
				} else {
					sum += magicPower[ sortedPower[i] ];
				}
			}
			if (cnt != k) {
				sum = -1;
			}
			res = max(res, sum);
			return;
		}
		int x = edges[p].first, y = edges[p].second;
		if (!isAdded(x, used) && !isAdded(y, used)) {
			if (cnt + 1 <= k) {
				// add x
				backtrack(p + 1, cnt + 1, add(x, used));
				// add y
				backtrack(p + 1, cnt + 1, add(y, used));
			}
		} else {
			// not add
			backtrack(p + 1, cnt, used);
		}
	}
	int maxMagicPower(vector <int> _magicPower, vector <string> _magicBond, int _k) {
		magicPower = _magicPower;
		magicBond = _magicBond;
		k = _k;
		n = magicPower.size();
		for (int i = 0; i < n; i++) {
			sortedPower[i] = i;
		}
		sort(sortedPower, sortedPower + n, cmp);
		edges.clear();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (magicBond[i][j] == 'Y') {
					edges.push_back(mkp(i, j));
				}
			}
		}
		res = -1;
		backtrack(0, 0, 0);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int magicPowerARRAY[] = {1, 2};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NY",
			"YN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(0, theObject.maxMagicPower(magicPower, magicBond, 1),2);
	}
	{
		int magicPowerARRAY[] = {100, 1, 100};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYN",
			"YNY",
			"NYN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(1, theObject.maxMagicPower(magicPower, magicBond, 1),1);
	}
	{
		int magicPowerARRAY[] = {100, 1, 100};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYN",
			"YNY",
			"NYN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(2, theObject.maxMagicPower(magicPower, magicBond, 2),200);
	}
	{
		int magicPowerARRAY[] = {4, 7, 5, 8};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYNY",
			"YNYN",
			"NYNY",
			"YNYN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(3, theObject.maxMagicPower(magicPower, magicBond, 2),15);
	}
	{
		int magicPowerARRAY[] = {46474, 60848, 98282, 58073, 42670, 50373};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(4, theObject.maxMagicPower(magicPower, magicBond, 3),209503);
	}
	{
		int magicPowerARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
			"YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
			"NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(5, theObject.maxMagicPower(magicPower, magicBond, 9),-1);
	}
	{
		int magicPowerARRAY[] = {1, 1};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NN", "NN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(6, theObject.maxMagicPower(magicPower, magicBond, 1),1);
	}
	{
		int magicPowerARRAY[] = {1,1,2,5,2,4,2};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMoleculeEasy theObject;
		eq(7, theObject.maxMagicPower(magicPower, magicBond, 3),11);
	}
}
// END CUT HERE
