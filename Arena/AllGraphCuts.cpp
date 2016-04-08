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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class AllGraphCuts {
public:
    vector <int> findGraph(vector <int> x) {
        vector <int> res;
        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {0,1,
            1,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(0, theObject.findGraph(x),retrunValue);
    }
    {
        int xARRAY[] = {0,1,
            1,1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {-1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(1, theObject.findGraph(x),retrunValue);
    }
    {
        int xARRAY[] = {0,2,2,
            2,0,2,
            2,2,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {10, 11, 14 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(2, theObject.findGraph(x),retrunValue);
    }
    {
        int xARRAY[] = {0,1,2,3,4,
            1,0,2,3,4,
            1,2,0,3,4,
            1,2,3,0,4,
            1,2,3,4,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {-1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(3, theObject.findGraph(x),retrunValue);
    }
    {
        int xARRAY[] = {0,0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(4, theObject.findGraph(x),retrunValue);
    }
    {
        int xARRAY[] = {
           0, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 3082,
           2545, 0, 2348, 2545, 2545, 2545, 2013, 2545, 2545, 2440, 2495, 2262, 2342, 2545, 2545, 2545, 2545, 2545, 2545, 2545,
           2348, 2348, 0, 2348, 2348, 2348, 2013, 2348, 2348, 2348, 2348, 2262, 2342, 2348, 2348, 2348, 2348, 2348, 2348, 2348,
           2993, 2545, 2348, 0, 2606, 2623, 2013, 2993, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 2993, 2993,
           2606, 2545, 2348, 2606, 0, 2606, 2013, 2606, 2606, 2440, 2495, 2262, 2342, 2606, 2606, 2606, 2606, 2606, 2606, 2606,
           2623, 2545, 2348, 2623, 2606, 0, 2013, 2623, 2623, 2440, 2495, 2262, 2342, 2617, 2623, 2623, 2623, 2623, 2623, 2623,
           2013, 2013, 2013, 2013, 2013, 2013, 0, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013,
           3001, 2545, 2348, 2993, 2606, 2623, 2013, 0, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3001, 3001,
           2626, 2545, 2348, 2626, 2606, 2623, 2013, 2626, 0, 2440, 2495, 2262, 2342, 2617, 2626, 2626, 2626, 2626, 2626, 2626,
           2440, 2440, 2348, 2440, 2440, 2440, 2013, 2440, 2440, 0, 2440, 2262, 2342, 2440, 2440, 2440, 2440, 2440, 2440, 2440,
           2495, 2495, 2348, 2495, 2495, 2495, 2013, 2495, 2495, 2440, 0, 2262, 2342, 2495, 2495, 2495, 2495, 2495, 2495, 2495,
           2262, 2262, 2262, 2262, 2262, 2262, 2013, 2262, 2262, 2262, 2262, 0, 2262, 2262, 2262, 2262, 2262, 2262, 2262, 2262,
           2342, 2342, 2342, 2342, 2342, 2342, 2013, 2342, 2342, 2342, 2342, 2262, 0, 2342, 2342, 2342, 2342, 2342, 2342, 2342,
           2617, 2545, 2348, 2617, 2606, 2617, 2013, 2617, 2617, 2440, 2495, 2262, 2342, 0, 2617, 2617, 2617, 2617, 2617, 2617,
           2773, 2545, 2348, 2773, 2606, 2623, 2013, 2773, 2626, 2440, 2495, 2262, 2342, 2617, 0, 2662, 2736, 2773, 2773, 2773,
           2662, 2545, 2348, 2662, 2606, 2623, 2013, 2662, 2626, 2440, 2495, 2262, 2342, 2617, 2662, 0, 2662, 2662, 2662, 2662,
           2736, 2545, 2348, 2736, 2606, 2623, 2013, 2736, 2626, 2440, 2495, 2262, 2342, 2617, 2736, 2662, 0, 2736, 2736, 2736,
           2827, 2545, 2348, 2827, 2606, 2623, 2013, 2827, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 0, 2827, 2827,
           3044, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 0, 3044,
           3082, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 0
           }
           ;
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {76801, 87602, 76403, 15604, 14005, 14406, 95607, 14408, 45609, 54010, 113211, 102812, 53613, 72414, 10015, 90416, 110417, 108818, 76819, 20022, 5223, 16824, 14025, 20426, 37227, 115628, 118829, 105230, 39631, 114032, 70833, 2434, 9235, 71636, 3637, 108438, 68439, 16443, 24444, 37245, 54046, 118447, 46048, 13249, 38450, 27651, 23652, 105253, 76054, 22455, 112056, 5657, 82458, 28859, 31264, 117665, 73666, 91667, 11268, 67269, 110870, 18471, 114872, 119673, 22074, 86075, 44876, 22477, 74478, 93679, 96085, 8486, 59687, 110088, 1689, 107290, 56091, 56092, 74893, 61294, 109295, 109296, 18097, 66498, 20899, 12506, 98907, 82908, 77309, 51710, 110111, 108112, 22513, 66514, 43315, 36516, 19717, 15318, 26519, 34127, 70128, 8929, 20930, 131, 81732, 80133, 29334, 68935, 53336, 81737, 36538, 57739, 35348, 96149, 25750, 19351, 15752, 4153, 80554, 107355, 96556, 70557, 66958, 48559, 33769, 81370, 55771, 15372, 61373, 72574, 11375, 2976, 66577, 108178, 57779, 590, 78991, 14992, 10593, 69794, 47395, 33796, 113397, 77398, 68999, 77811, 28212, 12613, 64614, 80215, 9816, 27017, 30618, 73819, 46632, 66633, 7834, 100635, 636, 7437, 4238, 76639, 87453, 16254, 10255, 31856, 50257, 18258, 3459, 73474, 69475, 63876, 41077, 3878, 28679, 13495, 56696, 109497, 101098, 116699, 60316, 107517, 12318, 98719, 51137, 91138, 81139, 108358, 119959, 106379 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AllGraphCuts theObject;
        eq(5, theObject.findGraph(x),retrunValue);
    }
	return 0;
}
// END CUT HERE
