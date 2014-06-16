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
#include <ctime>
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
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
class AlienAndHamburgers {
public:

    int getNumber(vector <int> type, vector <int> taste) {
	int A = 0;
	int n = type.size();
	vector < pair<int, int> > tt;

	for (int i = 0; i < n; i++) {
		tt.push_back( make_pair(type[i], taste[i]) );
	}
	sort(tt.begin(), tt.end(), cmp);

	set <int> kinds;
	bool v[60];
	for (int i = 0; i < 60; i++) {
		v[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (tt[i].second >= 0) {
			kinds.insert(tt[i].first);
			A += tt[i].second;
			v[i] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			set <int>::iterator it;
			it = kinds.find(tt[i].first);
			if (it != kinds.end()) {
				v[i] = true;
			}
		}
	}
	int Y = kinds.size();
	int ans = Y * A;
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			int m = tt[i].second;	
			kinds.insert(tt[i].first);
			++Y;
			if (Y == kinds.size()) {
				A += m;
				ans = max(ans, Y * A);
				v[i] = true;
			} else {
				--Y;
			}
		}
	}
	return ans;
    }
};
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int typeARRAY[] = {18, 4, 29, 38, 98, 46, 22, 31, 36, 77, 2, 91, 32, 62, 85, 5, 41, 77, 87, 86, 22, 38, 19, 47, 73, 78, 22, 49, 59, 73, 42, 71, 6, 22, 77, 20, 40, 5, 43};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        int tasteARRAY[] = {-95929, -20247, -16930, -23102, -3631, 9730, 79498, 89280, 61680, 28355, -32337, -89897, 69331, -34638, -1407, -89899, 93620, 97350, 72452, 35505, -41564, -10552, -52729, -89549, -8728, 29689, 41012, -73449, -71143, -67902, 44435, -83504, -74404, -86814, 38628, -68284, -81822, -81364, -38733};
        vector <int> taste( tasteARRAY, tasteARRAY+ARRSIZE(tasteARRAY) );
        AlienAndHamburgers theObject;
        eq(0, theObject.getNumber(type, taste),12579805);
    }
    {
        int typeARRAY[] = {1, 1};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        int tasteARRAY[] = {-1, -1};
        vector <int> taste( tasteARRAY, tasteARRAY+ARRSIZE(tasteARRAY) );
        AlienAndHamburgers theObject;
        eq(1, theObject.getNumber(type, taste),0);
    }
    {
        int typeARRAY[] = {1, 2, 3};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        int tasteARRAY[] = {7, 4, -1};
        vector <int> taste( tasteARRAY, tasteARRAY+ARRSIZE(tasteARRAY) );
        AlienAndHamburgers theObject;
        eq(2, theObject.getNumber(type, taste),30);
    }
    {
        int typeARRAY[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        int tasteARRAY[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
        vector <int> taste( tasteARRAY, tasteARRAY+ARRSIZE(tasteARRAY) );
        AlienAndHamburgers theObject;
        eq(3, theObject.getNumber(type, taste),54);
    }
    {
        int typeARRAY[] = {30, 20, 10};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        int tasteARRAY[] = {100000, -100000, 100000};
        vector <int> taste( tasteARRAY, tasteARRAY+ARRSIZE(tasteARRAY) );
        AlienAndHamburgers theObject;
        eq(4, theObject.getNumber(type, taste),400000);
    }
}
// END CUT HERE
