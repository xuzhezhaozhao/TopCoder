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

class EllysBulls {
public:
	int K, cnt;
	string res;
	vector <string> guesses;
	vector <int> bulls;
	void next(string & s)
	{
		int len = s.size();
		int k = 0;
		while (k < len && '9' == s[k]) {
			s[k] = '0';
			++k;
		}
		if (k >= len) {
			s = "";
		} else {
			++s[k];
		}
	}
	int countMatches(const string & s, const string & g)
	{
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == g[i]) {
				++res;
			}
		}
		return res;
	}
	string getNumber(vector <string> guesses, vector <int> bulls) {
		string res = "Liar";
		K = guesses[0].size();
		this->guesses = guesses;
		this->bulls = bulls;
		int n = guesses.size();
		// left half
		map <vector<int>, string> left_half;
		for (string s(K / 2, '0'); s != ""; next(s)) {
			bool good = true;
			vector <int> matches(n);
			for (int i = 0; i < n; i++) {
				int m = countMatches(s, guesses[i]);
				if (m > bulls[i]) {
					good = false;
					break;
				} else {
					matches[i] = m;
				}
			}
			if (good) {
				if (left_half[matches] != "") {
					left_half[matches] = "Ambiguity";
				} else {
					left_half[matches] = s;
				}
			}
		}
		// right half
		for (string s(K - K / 2, '0'); s != ""; next(s)) {
			bool good = true;
			vector <int> required(n);
			for (int i = 0; i < n; i++) {
				int m = bulls[i] - countMatches(s, guesses[i].substr(K / 2));
				if (m < 0) {
					good =false;
					break;
				} else {
					required[i] = m;
				}
			}
			if (good) {
				if (left_half.find(required) != left_half.end()) {
					if (left_half[required] == "Ambiguity") {
						return "Ambiguity";
					} else {
						if (res != "Liar") {
							if (res != left_half[required] + s) {
								return "Ambiguity";
							}
						} else {
							res = left_half[required] + s;
						}
					}
				}
			}
		}
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string guessesARRAY[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(0, theObject.getNumber(guesses, bulls),"1337");
	}
	{
		string guessesARRAY[] = {"0000", "1111", "2222"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {2, 2, 2};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(1, theObject.getNumber(guesses, bulls),"Liar");
	}
	{
		string guessesARRAY[] = {"666666", "666677", "777777", "999999"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {2, 3, 1, 0};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(2, theObject.getNumber(guesses, bulls),"Ambiguity");
	}
	{
		string guessesARRAY[] = {"000", "987", "654", "321", "100", "010"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {2, 1, 0, 0, 1, 1};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(3, theObject.getNumber(guesses, bulls),"007");
	}
	{
		string guessesARRAY[] = {"28", "92", "70", "30", "67", "63", "06", "65",
			"11", "06", "88", "48", "09", "65", "48", "08"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(4, theObject.getNumber(guesses, bulls),"54");
	}
	{
		string guessesARRAY[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
			"4166623", "1166638", "2767693", "8650248", "2486509",
			"6138934", "4018642", "6236742", "2961643", "8407361",
			"2097376", "6575410", "6071777", "3569948", "2606380"};
		vector <string> guesses( guessesARRAY, guessesARRAY+ARRSIZE(guessesARRAY) );
		int bullsARRAY[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
		vector <int> bulls( bullsARRAY, bullsARRAY+ARRSIZE(bullsARRAY) );
		EllysBulls theObject;
		eq(5, theObject.getNumber(guesses, bulls),"4266642");
	}
}
// END CUT HERE
