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
const int MAX = 1000000000;
class EllysNumberGuessing {
public:
    int getNumber(vector <int> guesses, vector <int> answers) {
        int res = 0;
	set <int> st;
	set <int> st2;

	int N = guesses.size();
	int t1 = guesses[0] - answers[0];
	int t2 = guesses[0] + answers[0];
	if (t1 > 0) {
		st.insert(t1);
	}
	if (t2 <= MAX) {
		st.insert(t2);
	}
	if (st.size() == 0) {
		return -2;
	}
	set <int>::iterator it;
	for (int i = 1; i < N; i++) {
		int t1 = guesses[i] - answers[i];
		int t2 = guesses[i] + answers[i];
		bool notLie = false;
		if (t1 > 0) {
			it = st.find(t1);
			if (it != st.end()) {
				st2.insert(t1);
				notLie = true;
			}
		}
		if (t2 <= MAX) {
			it = st.find(t2);
			if (it != st.end()) {
				st2.insert(t2);
				notLie = true;
			}
		}
		st = st2;
		st2.clear();
		if (!notLie) {
			return -2;
		}
	}
	if (st.size() > 1) {
		return -1;
	}
	res = ( *st.begin() );
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int guessesARRAY[] = {5, 5, 4};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {2, 2, 1};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(0, theObject.getNumber(guesses, answers), 3);
    }
    {
        int guessesARRAY[] = {100, 50, 34, 40};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {58, 8, 8, 2};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(1, theObject.getNumber(guesses, answers),42);
    }
    {
        int guessesARRAY[] = {500000, 600000, 700000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {120013, 220013, 79987};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(2, theObject.getNumber(guesses, answers),-2);
    }
    {
        int guessesARRAY[] = {500000000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {133742666};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(3, theObject.getNumber(guesses, answers),-1);
    }
    {
        int guessesARRAY[] = {76938260, 523164588, 14196746, 296286419, 535893832,
            41243148, 364561227, 270003278, 472017422, 367932361,
            395758413, 301278456, 186276934, 316343129, 336557549,
            52536121, 98343562, 356769915, 89249181, 335191879};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {466274085, 20047757, 529015599, 246925926, 7318513,
            501969197, 178651118, 273209067, 71194923, 175279984,
            147453932, 241933889, 356935411, 226869216, 206654796,
            490676224, 444868783, 186442430, 453963164, 208020466};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(4, theObject.getNumber(guesses, answers),543212345);
    }
    {
        int guessesARRAY[] = {42};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {42};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(5, theObject.getNumber(guesses, answers),84);
    }
    {
        int guessesARRAY[] = {999900000};
        vector <int> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
        int answersARRAY[] = {100001};
        vector <int> answers( answersARRAY, answersARRAY+ARRSIZE(answersARRAY) );
        EllysNumberGuessing theObject;
        eq(6, theObject.getNumber(guesses, answers),999799999);
    }
}
// END CUT HERE
