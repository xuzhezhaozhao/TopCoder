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

/*************** Program Begin **********************/
//long long bestK[1000];
class SparseFactorialDiv2 {
public:
	// 计算 [0, uppderbound] 区间内，模divisor值为 d 的数的个数。
	long long getC(long long upperbound, long long divisor, long long d)
	{
		if (upperbound % divisor >= d) {
			return upperbound / divisor + 1;
		} else {
			return upperbound / divisor;
		}
	}

	// 计算 区间 [0, upperbound] 内，F(n) % divisor == 0 的数的个数。
	long long calc(long long uppperbound, long long divisor)
	{
		long long res = 0;
		vector <long long> bestK(divisor, -1);
		for (long long k = 0; k * k < uppperbound; k++) {
			// 找的最小的k, 使 k * k % divisor == d
			if (bestK[ (k * k) % divisor ] == -1) {
				bestK[ (k * k) % divisor ] = k;
			}
		}
		for (int d = 0; d < divisor; d++) {
			if (bestK[d] == -1) {
				continue;
			}
			res += ( getC(uppperbound, divisor, d) - getC(bestK[d] * bestK[d], divisor, d) );
		}
		return res;
	}

	long long getCount(long long lo, long long hi, long long divisor) {


		return calc(hi, divisor) - calc(lo - 1, divisor);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		SparseFactorialDiv2 theObject;
		eq(0, theObject.getCount(4L, 8L, 3L),3LL);
	}
	{
		SparseFactorialDiv2 theObject;
		eq(1, theObject.getCount(9L, 11L, 7L),1LL);
	}
	{
		SparseFactorialDiv2 theObject;
		eq(2, theObject.getCount(1L, 1000000000000L, 2L),999999999999LL);
	}
	{
		SparseFactorialDiv2 theObject;
		eq(3, theObject.getCount(16L, 26L, 11L),4LL);
	}
	{
		SparseFactorialDiv2 theObject;
		eq(4, theObject.getCount(10000L, 20000L, 997L),1211LL);
	}
	{
		SparseFactorialDiv2 theObject;
		eq(5, theObject.getCount(123456789L, 987654321L, 71L),438184668LL);
	}
}
// END CUT HERE
