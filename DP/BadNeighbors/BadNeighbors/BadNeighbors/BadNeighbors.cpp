#include <algorithm>
#include <iostream>
#include <sstream>

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

/*************** Program Begin **********************/
int dp[50];
bool circle[50];
class BadNeighbors {
public:
	int work(vector <int> sequence) {
		int res = 0;
		int N = sequence.size();
		memset(dp, 0, sizeof(dp));
		memset(circle, 0, sizeof(circle));
		dp[0] = sequence[0];
		res = dp[0];
		for (int i = 1; i < N; i++) {
			dp[i] = sequence[i];
			for (int j = 0; j < i-1; j++) {
				if (dp[i] < dp[j] + sequence[i]) {
					dp[i] = dp[j] + sequence[i];
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
	int maxDonations(vector <int> sequence) {
		int res1 = 0, res2 = 0;
		vector <int> s1(sequence.begin(), --sequence.end());
		vector <int> s2(++sequence.begin(), sequence.end());
		res1 = work(s1);
		res2 = work(s2);

		return max(res1, res2);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int sequenceARRAY[] = { 659, 384, 265, 947, 121, 568, 795, 596, 361, 906, 517, 902, 233, 906, 989, 777, 511, 694, 21, 422, 232, 956, 48, 810, 80, 328, 387, 694, 77, 748, 828, 422, 546, 764, 15, 810, 961, 423, 608, 879 };
		vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
		BadNeighbors theObject;
		eq(0, theObject.maxDonations(sequence),13936);
	}
	{
		int sequenceARRAY[] = {  399, 470, 76, 788, 170, 349, 895, 682, 49, 873, 943, 798, 111, 981, 678, 600, 459, 265, 939, 555, 406 };
		vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
		BadNeighbors theObject;
		eq(1, theObject.maxDonations(sequence),6886);
	}
	{
		int sequenceARRAY[] = { 7, 7, 7, 7, 7, 7, 7 };
		vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
		BadNeighbors theObject;
		eq(2, theObject.maxDonations(sequence),21);
	}
	{
		int sequenceARRAY[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
		vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
		BadNeighbors theObject;
		eq(3, theObject.maxDonations(sequence),16);
	}
	{
		int sequenceARRAY[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
			6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
			52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
		vector <int> sequence( sequenceARRAY, sequenceARRAY+ARRSIZE(sequenceARRAY) );
		BadNeighbors theObject;
		eq(4, theObject.maxDonations(sequence),2926);
	}
}
// END CUT HERE
