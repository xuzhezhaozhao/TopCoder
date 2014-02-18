#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
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

/************** Program  Begin *********************/
typedef pair <int, int> durTime;
class EelAndRabbit {
public:
    int getmax(vector <int> l, vector <int> t) {
	vector <durTime> dur;
	vector <int> time;
	dur.reserve(100);
	int size = l.size();
	for (int i = 0; i < size; i++) {
		time.push_back(t[i]);
		time.push_back(t[i]+l[i]);
		dur.push_back( durTime(t[i], t[i]+l[i]) );
	}
	sort(time.begin(), time.end());
	time.erase( unique(time.begin(), time.end()), time.end() );
	size = time.size();
	bool v[50] = {false};
	int maxc = 0;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < size-1; i++) {
		// first
		memset(v, 0, sizeof(v));
		count1 = 0;
		for (int j = 0; j < dur.size(); j++) {
			if ( dur[j].first <= time[i] && dur[j].second >= time[i] ) {
				v[j] = true;
				++count1;
			}
		}
		
		// twice
		for (int j = i+1; j < size; j++) {
			count2 = 0;
			for (int k = 0; k < dur.size(); k++) {
				if ( !v[k] && dur[k].first <= time[j] && dur[k].second >= time[j] ) {
					++count2;
				}
			}
			if (count1 + count2 > maxc) {
				maxc = count1 + count2;
			}
		}
		
	}

	return maxc;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int lARRAY[] = {2, 4, 3, 2, 2, 1, 10};
	vector <int> l( lARRAY, lARRAY+ARRSIZE(lARRAY) );
	int tARRAY[] = {2, 6, 3, 7, 0, 2, 0};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	EelAndRabbit theObject;
	eq(0, theObject.getmax(l, t),6);
    }
    {
	int lARRAY[] = {1, 1, 1};
	vector <int> l( lARRAY, lARRAY+ARRSIZE(lARRAY) );
	int tARRAY[] = {2, 0, 4};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	EelAndRabbit theObject;
	eq(1, theObject.getmax(l, t),2);
    }
    {
	int lARRAY[] = {1};
	vector <int> l( lARRAY, lARRAY+ARRSIZE(lARRAY) );
	int tARRAY[] = {1};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	EelAndRabbit theObject;
	eq(2, theObject.getmax(l, t),1);
    }
    {
	int lARRAY[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
	vector <int> l( lARRAY, lARRAY+ARRSIZE(lARRAY) );
	int tARRAY[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
	vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
	EelAndRabbit theObject;
	eq(3, theObject.getmax(l, t),7);
    }
}
// END CUT HERE
