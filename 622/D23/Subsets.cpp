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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class Subsets {
public:
	vector <int> numbers;
	int ones_cnt;
	int res;
	int nextdiff[1005];
	void backtrack(int sum, int prod, int pos)
	{
		// add
		int cur = numbers[pos];
		int next_sum = sum + cur;
		int next_prod = prod * cur;
		if (next_sum + ones_cnt > next_prod) {
			res += next_sum + ones_cnt - next_prod;
			if (pos + 1 < numbers.size()) {
				backtrack(next_sum, next_prod, pos + 1);
			}
		}

		// not add
		if (nextdiff[pos] < numbers.size()) {
			backtrack(sum, prod, nextdiff[pos]);
		}
	}

	int findSubset(vector <int> numbers) {
		sort(numbers.begin(), numbers.end());
		this->numbers = numbers;
		int n = numbers.size();

		for (int i = 0; i < n; i++) {
			nextdiff[i] = n;
			for (int j = i + 1; j < n; j++) {
				if (numbers[i] != numbers[j]) {
					nextdiff[i] = j;
					break;
				}
			}
		}
		
		ones_cnt = count(numbers.begin(), numbers.end(), 1);
		res = max(ones_cnt - 1, 0);
		if (ones_cnt < n) {
			backtrack(0, 1, ones_cnt);
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		int numbersARRAY[] = {1,1,1};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(0, theObject.findSubset(numbers),2);
	}
	{
		int numbersARRAY[] = {1,1,1,1,2,2,2,2};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(1, theObject.findSubset(numbers),13);
	}
	{
		int numbersARRAY[] = {1,2,3,4};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(2, theObject.findSubset(numbers),3);
	}
	{
		int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(3, theObject.findSubset(numbers),77);
	}
	{
		int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(4, theObject.findSubset(numbers),100);
	}
	{
		int numbersARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
			1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(5, theObject.findSubset(numbers),8050);
	}
	{
		int numbersARRAY[] = {5,3};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		Subsets theObject;
		eq(6, theObject.findSubset(numbers),0);
	}
	return 0;
}
// END CUT HERE
