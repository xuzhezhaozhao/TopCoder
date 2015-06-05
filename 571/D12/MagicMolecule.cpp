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

class MagicMolecule {
public:
	vector <int> magicPower;
	vector <string> magicBond;
	vector <pii> edges;
	int n, res;
	bool used[55];
	void backtrack(int p, int cnt)
	{
		if (p == edges.size()) {	// base case
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					sum += magicPower[i];
				}
			}
			res = max(res, sum);
			return;	
		}
		int x = edges[p].first, y = edges[p].second;
		if (used[x] || used[y]) {
			// ignore, process next edge
			backtrack(p + 1, cnt);
		} else {
			if ( (cnt + 1) * 3 <= n )  {
				// add x
				used[x] = true;
				backtrack(p + 1, cnt + 1);
				used[x] = false;
				// add y
				used[y] = true;
				backtrack(p + 1, cnt + 1);
				used[y] = false;
			}
		}
	}
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
		n = magicPower.size();
		this->magicPower = magicPower;
		this->magicBond = magicBond;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && magicBond[i][j] == 'N') {
					edges.push_back(mkp(i, j));
				}
			}
		}
		res = 0;
		memset(used, 0, sizeof(used));
		backtrack(0, 0);
		res = (res == 0 ? -1 : res);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int magicPowerARRAY[] = {1,2,3};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYY","YNN","YNN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMolecule theObject;
		eq(0, theObject.maxMagicPower(magicPower, magicBond),4);
	}
	{
		int magicPowerARRAY[] = {1,1,1,1};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NNYY","NNYY","YYNN","YYNN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMolecule theObject;
		eq(1, theObject.maxMagicPower(magicPower, magicBond),-1);
	}
	{
		int magicPowerARRAY[] = {86,15,100,93,53,50};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMolecule theObject;
		eq(2, theObject.maxMagicPower(magicPower, magicBond),332);
	}
	{
		int magicPowerARRAY[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691};
		vector <int> magicPower( magicPowerARRAY, magicPowerARRAY+ARRSIZE(magicPowerARRAY) );
		string magicBondARRAY[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"};
		vector <string> magicBond( magicBondARRAY, magicBondARRAY+ARRSIZE(magicBondARRAY) );
		MagicMolecule theObject;
		eq(3, theObject.maxMagicPower(magicPower, magicBond),57179);
	}
}
// END CUT HERE
