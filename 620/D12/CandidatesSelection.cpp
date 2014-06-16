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

class CandidatesSelection {
public:
    string possible(vector <string> score, vector <int> result) {
	vector < pii > cond;
	int n = result.size();
	int m = score[0].size();

	for (int i = 0; i < n - 1; i++) {
		cond.push_back( mkp(result[i], result[i + 1]) );
	}

	bool used[55];
	memset(used, 0, sizeof(used));
	while (!cond.empty()) {
		bool isIndex = true;
		int r = cond.size();
		for (int i = 0; i < r; i++) {
			isIndex &= (cond[i].first < cond[i].second);
		}
		if (isIndex) {
			break;
		}
		bool removed = false;
		for (int i = 0; i < m; i++) {
			if (used[i]) {
				continue;
			}
			bool ok = true;
			for (int j = 0; j < r; j++) {
				ok &= ( score[ cond[j].first ][i] <= score[ cond[j].second ][i] );
			}
			if (!ok) {
				continue;	
			}
			used[i] = true;
			vector < pii > newcond;
			for (int j = 0; j < r; j++) {
				if (score[ cond[j].first ][i] == score[ cond[j].second ][i]) {
					newcond.push_back(cond[j]);
				}
			}
			if (newcond.size() == cond.size()) {
				continue;
			}
			removed = true;
			cond = newcond;
			break;
		}
		if (!removed) {
			return "Impossible";
		}
	}

	return "Possible";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string scoreARRAY[] = {"CC", "AA", "BB"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {1,2,0};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(0, theObject.possible(score, result),"Possible");
    }
    {
        string scoreARRAY[] = {"BAB", "ABB", "AAB", "ABA"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {2,0,1,3};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(1, theObject.possible(score, result),"Possible");
    }
    {
        string scoreARRAY[] = {"BAB", "ABB", "AAB", "ABA"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {0, 1, 3, 2};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(2, theObject.possible(score, result),"Impossible");
    }
    {
        string scoreARRAY[] = {"AAA", "ZZZ"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {1, 0};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(3, theObject.possible(score, result),"Impossible");
    }
    {
        string scoreARRAY[] = {"ZZZ", "AAA"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {0, 1};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(4, theObject.possible(score, result),"Possible");
    }
    {
        string scoreARRAY[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"};
        vector <string> score( scoreARRAY, scoreARRAY+ARRSIZE(scoreARRAY) );
        int resultARRAY[] = {3,7,1,0,2,5,6,4};
        vector <int> result( resultARRAY, resultARRAY+ARRSIZE(resultARRAY) );
        CandidatesSelection theObject;
        eq(5, theObject.possible(score, result),"Possible");
    }
	return 0;
}
// END CUT HERE
