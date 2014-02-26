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
bool v[105];
class DivideByZero {
public:
    int CountNumbers(vector <int> numbers) {
        int res = 0;
	int n = numbers.size();
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; i++) {
		v[numbers[i]] = true;
	}
	sort(numbers.begin(), numbers.end());
	while (1) {
		bool over = true;
		n = numbers.size();
		sort(numbers.begin(), numbers.end());		
		for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int t = numbers[j] / numbers[i];
			if (!v[t]) {
				numbers.push_back(t);
				over = false;
				v[t] = true;
			}
		}
		}
		if (over) {
			break;
		}
	}
	res = numbers.size();

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int numbersARRAY[] = {9, 2};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(0, theObject.CountNumbers(numbers),3);
    }
    {
        int numbersARRAY[] = {8, 2};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(1, theObject.CountNumbers(numbers),3);
    }
    {
        int numbersARRAY[] = {50};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(2, theObject.CountNumbers(numbers),1);
    }
    {
        int numbersARRAY[] = {1, 5, 8, 30, 15, 4};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(3, theObject.CountNumbers(numbers),11);
    }
    {
        int numbersARRAY[] = {1, 2, 4, 8, 16, 32, 64};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(4, theObject.CountNumbers(numbers),7);
    }
    {
        int numbersARRAY[] = {6, 2, 18};
        vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
        DivideByZero theObject;
        eq(5, theObject.CountNumbers(numbers),7);
    }
}
// END CUT HERE
