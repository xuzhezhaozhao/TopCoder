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

class FlowerGarden {
public:
	vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
		int N = height.size();
		vector <int> res(N), b(N), w(N);
		for (int i = N-1; i >= 0; i--) {
			int index = 0;
			for (int j = 1; j <= i; j++) {
				if (height[j] < height[index]) {
					index = j;
				}
			}
			swap(height[i], height[index]);
			swap(bloom[i], bloom[index]);
			swap(wilt[i], wilt[index]);
		}

		res[0] = height[0];
		b[0] = bloom[0];
		w[0] = wilt[0];
		for (int i = 1; i < N; i++) {
			int index = i;
			for (int j = 0; j < i; j++) {
				if ( ( b[j]     >= bloom[i] && b[j]     <= wilt[i] ) || 
				     ( w[j]     >= bloom[i] && w[j]     <= wilt[i] ) || 
				     ( bloom[i] >= b[j]     && bloom[i] <= w[j] )    ||
				     ( wilt[i]  >= b[j]     && wilt[i]  <= w[j] )
				     ) {
						index = j;
						break;
				}
			}
			for (int k = i; k > index; k--) {
				res[k] = res[k-1];
				b[k] = b[k-1];
				w[k] = w[k-1];

			}
			res[index] = height[i];
			b[index] = bloom[i];
			w[index] = wilt[i];
		}

		return res;
	}

};
//{689, 929, 976, 79,  630, 835, 721, 386, 492, 767, 787, 387, 193, 547, 906, 642, 3,   920, 306, 735, 889, 663, 295, 892, 575, 349, 683, 699, 584, 149, 410, 710, 459, 277, 965, 112, 146, 352, 408, 432}, 
//{4,   123, 356, 50,  57,  307, 148, 213, 269, 164, 324, 211, 249, 355, 110, 280, 211, 106, 277, 303, 63,  326, 285, 285, 269, 144, 331, 15,  296, 319, 89,  243, 254, 159, 185, 158, 81,  270, 219, 26},
//{312, 158, 360, 314, 323, 343, 267, 220, 347, 197, 327, 334, 250, 360, 350, 323, 291, 323, 315, 320, 355, 334, 286, 293, 362, 181, 360, 328, 322, 344, 173, 248, 284, 301, 215, 230, 226, 331, 355, 81}
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int heightARRAY[] = {689, 929, 976, 79,  630, 835, 721, 386, 492, 767, 787, 387, 193, 547, 906, 642, 3,   920, 306, 735, 889, 663, 295, 892, 575, 349, 683, 699, 584, 149, 410, 710, 459, 277, 965, 112, 146, 352, 408, 432};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {4,   123, 356, 50,  57,  307, 148, 213, 269, 164, 324, 211, 249, 355, 110, 280, 211, 106, 277, 303, 63,  326, 285, 285, 269, 144, 331, 15,  296, 319, 89,  243, 254, 159, 185, 158, 81,  270, 219, 26};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {312, 158, 360, 314, 323, 343, 267, 220, 347, 197, 327, 334, 250, 360, 350, 323, 291, 323, 315, 320, 355, 334, 286, 293, 362, 181, 360, 328, 322, 344, 173, 248, 284, 301, 215, 230, 226, 331, 355, 81};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 1,  2,  3,  4,  5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(0, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
    {
        int heightARRAY[] = {5,4,3,2,1};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {1,5,10,15,20};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {4,9,14,19,24};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 5,  4,  3,  2,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(1, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
    {
        int heightARRAY[] = {5,4,3,2,1};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {1,5,10,15,20};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {5,10,15,20,25};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 1,  2,  3,  4,  5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(2, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
    {
        int heightARRAY[] = {5,4,3,2,1};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {1,5,10,15,20};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {5,10,14,20,25};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 3,  4,  5,  1,  2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(3, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
    {
        int heightARRAY[] = {1,2,3,4,5,6};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {1,3,1,3,1,3};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {2,4,2,4,2,4};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 2,  4,  6,  1,  3,  5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(4, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
    {
        int heightARRAY[] = {3,2,5,4};
        vector <int> height( heightARRAY, heightARRAY+ARRSIZE(heightARRAY) );
        int bloomARRAY[] = {1,2,11,10};
        vector <int> bloom( bloomARRAY, bloomARRAY+ARRSIZE(bloomARRAY) );
        int wiltARRAY[] = {4,3,12,13};
        vector <int> wilt( wiltARRAY, wiltARRAY+ARRSIZE(wiltARRAY) );
        int retrunValueARRAY[] = { 4,  5,  2,  3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FlowerGarden theObject;
        eq(5, theObject.getOrdering(height, bloom, wilt),retrunValue);
    }
}
// END CUT HERE
