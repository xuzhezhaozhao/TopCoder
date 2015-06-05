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
bool isEqual(int a, int b, int c, int d)
{
	if (a*d - b*c == 0) {
		return true;
	} else {
		return false;
	}

}

int test(int a, int b, vector <int> A, int p) 
{
	int N = A.size();
	int index = 10000;
	if (p < 0) {
		return -1;
	}
	for (int i = p; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			int x = A[i];
			int y = A[j];
			if ( isEqual(a, b, x, y) ) {
				if (index > j) {
					index = j;
				}
			}
		}
	}
	if (index == 10000) {
		index = -1;
	}
	return index;
}

int dp[50][50];
int index[50][50];
class AstronomicalRecords {
public:
	int minimalPlanets(vector <int> A, vector <int> B);
};
int f[55][55];

int AstronomicalRecords::minimalPlanets(vector <int> A, vector <int> B) {
	int n = A.size(), m = B.size();
	int ans = n + m;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= m; j++) 
					f[i][j] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++) {
					bool ok = (((long long)A[i - 1] * B[y]) == ((long long)B[j - 1] * A[x]));
					if (ok) f[i][j] = f[i - 1][j - 1] + 1; 
					else if (f[i - 1][j] > f[i][j - 1]) f[i][j] = f[i - 1][j];
					else f[i][j] = f[i][j - 1];
				}
				int cur = n + m - f[n][m];
				if (cur < ans) ans = cur;
		}
		return ans;
}
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {1,2,1,2,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,1,2,1,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        AstronomicalRecords theObject;
        eq(0, theObject.minimalPlanets(A, B),6);
    }
    {
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,4,6,8};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        AstronomicalRecords theObject;
        //eq(1, theObject.minimalPlanets(A, B),4);
    }
    {
        int AARRAY[] = {2,3,2,3,2,3,2};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {600,700,600,700,600,700,600};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        AstronomicalRecords theObject;
        //eq(2, theObject.minimalPlanets(A, B),10);
    }
    {
        int AARRAY[] = {1,2,3,4,5,6,7,8,9};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {6,7,8,9,10,11,12};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        AstronomicalRecords theObject;
        //eq(3, theObject.minimalPlanets(A, B),12);
    }
    {
        int AARRAY[] = {100000000,200000000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {200000000,100000000};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        AstronomicalRecords theObject;
        //eq(4, theObject.minimalPlanets(A, B),3);
    }
}
// END CUT HERE
