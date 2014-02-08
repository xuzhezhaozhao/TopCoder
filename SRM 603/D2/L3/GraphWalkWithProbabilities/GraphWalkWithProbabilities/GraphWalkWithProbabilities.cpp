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
const int MAX_TURNS = 3000;
const int MAX_V = 50;
double p[MAX_V][MAX_TURNS + 1];


class GraphWalkWithProbabilities {
public:
    double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) {
	    for (int i = 0; i < MAX_V; i++) {
		p[i][0] = 0.0;
	    }
	    int N = graph.size();
	    for (int k = 1; k <= MAX_TURNS; k++) {
		for (int i = 0; i < N; i++) {
			p[i][k] = 0.0;
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == '1') {
					p[i][k] = max( p[i][k], 
						winprob[j] / 100.0 + (100 - winprob[j] - looseprob[j]) / 100.0 * p[j][k-1]);
				}
			}
		}
	    }
	    return p[Start][MAX_TURNS];
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string graphARRAY[] = {"1"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {1};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {1};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(0, theObject.findprob(graph, winprob, looseprob, 0),0.5);
    }
    {
        string graphARRAY[] = {"11","11"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {60,40};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {40,60};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(1, theObject.findprob(graph, winprob, looseprob, 0),0.6);
    }
    {
        string graphARRAY[] = {"11","11"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {2,3};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {3,4};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(2, theObject.findprob(graph, winprob, looseprob, 0),0.4285714285714286);
    }
    {
        string graphARRAY[] = {"110","011","001"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {2,1,10};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {20,20,10};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(3, theObject.findprob(graph, winprob, looseprob, 0),0.405);
    }
    {
        string graphARRAY[] = {"111","111","011"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        int winprobARRAY[] = {100,1,1};
        vector <int> winprob( winprobARRAY, winprobARRAY+ARRSIZE(winprobARRAY) );
        int looseprobARRAY[] = {0,50,50};
        vector <int> looseprob( looseprobARRAY, looseprobARRAY+ARRSIZE(looseprobARRAY) );
        GraphWalkWithProbabilities theObject;
        eq(4, theObject.findprob(graph, winprob, looseprob, 2),0.5);
    }
}
// END CUT HERE
