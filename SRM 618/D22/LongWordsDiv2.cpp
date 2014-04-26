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

class LongWordsDiv2 {
public:
    string find(string word) {
	int N = word.size();
	set < pair<char, char> > seq[105];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			seq[i].insert(mkp(word[j], word[i]));
		}
	}
	for (int i = 1; i < N; i++) {
		if (word[i] == word[i - 1]) {
			return "Dislikes";
		} else {
			for (int j = 0; j < i; j++) {
				if (word[j] == word[i]) {
					for (int k = j + 1; k < i; k++) {
						if (seq[j].find(mkp(word[k], word[i])) != seq[j].end()) {
							return "Dislikes";
						}
					}
				}
			}
		}
	}
	return "Likes";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        LongWordsDiv2 theObject;
        eq(0, theObject.find("AAA"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(1, theObject.find("ABCBA"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(2, theObject.find("ABCBAC"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(3, theObject.find("TOPCODER"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(4, theObject.find("VAMOSGIMNASIA"),"Dislikes");
    }
    {
        LongWordsDiv2 theObject;
        eq(5, theObject.find("SINGLEROUNDMATCH"),"Likes");
    }
    {
        LongWordsDiv2 theObject;
        eq(6, theObject.find("DALELOBO"),"Likes");
    }
	return 0;
}
// END CUT HERE
