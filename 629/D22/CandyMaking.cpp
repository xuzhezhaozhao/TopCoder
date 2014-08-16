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

class CandyMaking {
public:
    double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
        double res = 100000000000.0;
	for (int i = 0; i < containerVolume.size(); i++) {
		double d = 1.0 * desiredWeight[i] / containerVolume[i];
		double sum = 0;
		for (int j = 0; j < containerVolume.size(); j++) {
			double t = containerVolume[j] * d - desiredWeight[j];
			if (t < 0) {
				t = -t;
			}
			sum += t;
		}
		res = min(res, sum);
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int containerVolumeARRAY[] = {5};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(0, theObject.findSuitableDensity(containerVolume, desiredWeight),0.0);
    }
    {
        int containerVolumeARRAY[] = {10,10};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1000,2000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(1, theObject.findSuitableDensity(containerVolume, desiredWeight),1000.0);
    }
    {
        int containerVolumeARRAY[] = {10,20,40};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {4000,2000,1000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(2, theObject.findSuitableDensity(containerVolume, desiredWeight),5250.0);
    }
    {
        int containerVolumeARRAY[] = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(3, theObject.findSuitableDensity(containerVolume, desiredWeight),983673.2727272725);
    }
    {
        int containerVolumeARRAY[] = {30621,30620,2};
        vector <int> containerVolume( containerVolumeARRAY, containerVolumeARRAY+ARRSIZE(containerVolumeARRAY) );
        int desiredWeightARRAY[] = {1,1,1000000};
        vector <int> desiredWeight( desiredWeightARRAY, desiredWeightARRAY+ARRSIZE(desiredWeightARRAY) );
        CandyMaking theObject;
        eq(4, theObject.findSuitableDensity(containerVolume, desiredWeight),999999.9999673415);
    }
}
// END CUT HERE
