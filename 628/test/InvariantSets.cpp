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

class InvariantSets{ 
public: 
	int D[52]; 
	LL dp[52]; 
	queue<int> Q; 
	long long countSets(vector <int> f){ 
		int N=f.size(); 
		memset(D,0,sizeof(D)); 
		long long ret=1; 
		for(int i=0;i<N;++i) ++D[f[i]],dp[i]=1; 
		for(int i=0;i<N;++i) if(D[i]==0) Q.push(i); 
		while(!Q.empty()){ 
			int x=Q.front(); 
			Q.pop(); 
			dp[f[x]]*=(1+dp[x]); 
			if(--D[f[x]]==0) Q.push(f[x]); 
		} 
		for(int i=0;i<N;++i) if(D[i]){ 
			int j=i; 
			LL ans=1; 
			do{ 
				ans*=dp[j]; 
				D[j]=0; 
				j=f[j]; 
			}while(j!=i); 
			ret*=ans+1; 
		} 
		return ret; 
	} 


}; 


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int fARRAY[] = {1,0,0,0};
		vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
		InvariantSets theObject;
		eq(0, theObject.countSets(f),5LL);
	}
	{
		int fARRAY[] = {1,2,0};
		vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
		InvariantSets theObject;
		eq(1, theObject.countSets(f),2LL);
	}
	{
		int fARRAY[] = {0,0,1,2};
		vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
		InvariantSets theObject;
		eq(2, theObject.countSets(f),5LL);
	}
	{
		int fARRAY[] = {0,1,2,3,4,5};
		vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
		InvariantSets theObject;
		eq(3, theObject.countSets(f),64LL);
	}
	{
		int fARRAY[] = {12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5};
		vector <int> f( fARRAY, fARRAY+ARRSIZE(fARRAY) );
		InvariantSets theObject;
		eq(4, theObject.countSets(f),90LL);
	}
}
// END CUT HERE
