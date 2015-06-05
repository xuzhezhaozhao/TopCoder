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

class GUMIAndSongsDiv2 {
public:
    int maxSongs(vector <int> duration, vector <int> tone, int T) {
	int res = 0;
	int N = duration.size();

	vector <int> songs;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int maxTone = max(tone[i], tone[j]);
			int minTone = min(tone[i], tone[j]);
			songs.clear();
			for (int k = 0; k < N; k++) {
				if (tone[k] <= maxTone && tone[k] >= minTone) {
					songs.push_back(duration[k]);
				}
			}
			sort(songs.begin(), songs.end());
			int sum = 0;
			int c = 0;
			for (int k = 0; k < songs.size(); k++) {
				sum += songs[k];
				if (sum <= T - maxTone + minTone) {
					++c;
				}
			}
			res = max(res, c);
		}
	}

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int durationARRAY[] = {3, 5, 4, 11};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {2, 1, 3, 1};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(0, theObject.maxSongs(duration, tone, 17),3);
    }
    {
	int durationARRAY[] = {100, 200, 300};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {1, 2, 3};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(1, theObject.maxSongs(duration, tone, 10),0);
    }
    {
	int durationARRAY[] = {1, 2, 3, 4};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {1, 1, 1, 1};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(2, theObject.maxSongs(duration, tone, 100),4);
    }
    {
	int durationARRAY[] = {10, 10, 10};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {58, 58, 58};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(3, theObject.maxSongs(duration, tone, 30),3);
    }
    {
	int durationARRAY[] = {8, 11, 7, 15, 9, 16, 7, 9};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {3, 8, 5, 4, 2, 7, 4, 1};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(4, theObject.maxSongs(duration, tone, 14),1);
    }
    {
	int durationARRAY[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
	vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
	int toneARRAY[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
	vector <int> tone( toneARRAY, toneARRAY+ARRSIZE(toneARRAY) );
	GUMIAndSongsDiv2 theObject;
	eq(5, theObject.maxSongs(duration, tone, 302606),8);
    }
}
// END CUT HERE
