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

class EllysPairing {
public:
    int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add) {
        int res = 0;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int countARRAY[] = {4, 7};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        int firstARRAY[] = {5, 3};
        vector <int> first( firstARRAY, firstARRAY+ARRSIZE(firstARRAY) );
        int multARRAY[] = {2, 3};
        vector <int> mult( multARRAY, multARRAY+ARRSIZE(multARRAY) );
        int addARRAY[] = {1, 0};
        vector <int> add( addARRAY, addARRAY+ARRSIZE(addARRAY) );
        EllysPairing theObject;
        eq(0, theObject.getMax(16, count, first, mult, add),5);
    }
    {
        int countARRAY[] = {6, 4, 3};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        int firstARRAY[] = {0, 3, 2};
        vector <int> first( firstARRAY, firstARRAY+ARRSIZE(firstARRAY) );
        int multARRAY[] = {3, 7, 5};
        vector <int> mult( multARRAY, multARRAY+ARRSIZE(multARRAY) );
        int addARRAY[] = {0, 3, 2};
        vector <int> add( addARRAY, addARRAY+ARRSIZE(addARRAY) );
        EllysPairing theObject;
        eq(1, theObject.getMax(8, count, first, mult, add),5);
    }
    {
        int countARRAY[] = {42, 13, 666, 17, 1337, 42, 1};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        int firstARRAY[] = {18, 76, 3, 122, 0, 11, 11};
        vector <int> first( firstARRAY, firstARRAY+ARRSIZE(firstARRAY) );
        int multARRAY[] = {33, 17, 54, 90, 41, 122, 20};
        vector <int> mult( multARRAY, multARRAY+ARRSIZE(multARRAY) );
        int addARRAY[] = {66, 15, 10, 121, 122, 1, 30};
        vector <int> add( addARRAY, addARRAY+ARRSIZE(addARRAY) );
        EllysPairing theObject;
        eq(2, theObject.getMax(128, count, first, mult, add),1059);
    }
    {
        int countARRAY[] = {4242, 42, 9872, 13, 666, 21983, 17, 1337, 42, 1};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        int firstARRAY[] = {19, 18, 76, 42, 3, 112, 0, 11, 11, 12};
        vector <int> first( firstARRAY, firstARRAY+ARRSIZE(firstARRAY) );
        int multARRAY[] = {27, 33, 10, 8, 17, 9362, 90, 41, 122, 20};
        vector <int> mult( multARRAY, multARRAY+ARRSIZE(multARRAY) );
        int addARRAY[] = {98, 101, 66, 15, 10, 144, 3, 1, 5, 1};
        vector <int> add( addARRAY, addARRAY+ARRSIZE(addARRAY) );
        EllysPairing theObject;
        eq(3, theObject.getMax(1048576, count, first, mult, add),16232);
    }
    {
        int countARRAY[] = {894602, 946569, 887230, 856152, 962583, 949356, 904847, 829100, 842183, 958440,
            811081, 864078, 809209, 938727, 949135, 892809, 816528, 961237, 979142, 890922};
        vector <int> count( countARRAY, countARRAY+ARRSIZE(countARRAY) );
        int firstARRAY[] = {844085078, 898937259, 243490172, 887804102, 187696417, 156820442, 237600210, 618812924, 153000239, 912364033,
            254936966, 650298774, 982988140, 649258331, 566444626, 201481721, 492943390, 1061953081, 492672963, 960519711};
        vector <int> first( firstARRAY, firstARRAY+ARRSIZE(firstARRAY) );
        int multARRAY[] = {1036482037, 583219072, 819168094, 253755052, 548208982, 401830167, 638626082, 43642932, 123607749, 485521178,
            860368129, 30334704, 219771462, 733375600, 130839219, 415503960, 294132484, 1044831462, 256910484, 198852170};
        vector <int> mult( multARRAY, multARRAY+ARRSIZE(multARRAY) );
        int addARRAY[] = {889169006, 604831366, 967292994, 980686280, 844875791, 1027687492, 357734882, 295879743, 48284748, 421729100,
            1049536313, 327207332, 948053446, 271229570, 664579359, 795815285, 842856528, 876662975, 675611938, 634229925};
        vector <int> add( addARRAY, addARRAY+ARRSIZE(addARRAY) );
        EllysPairing theObject;
        eq(4, theObject.getMax(1073741824, count, first, mult, add),8971965);
    }
}
// END CUT HERE
