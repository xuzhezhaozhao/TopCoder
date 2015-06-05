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
int g[150][5005];		// class 与 requirement 的匹配关系
int req_match[5005];		// req_match[req] = class
int req_n;			// req 的节点数
bool v[5005];			// DFS 访问数组
class Graduation {
public:
	bool DFS(int where)	// 使用DFS进行二分匹配
	{
		if (-1 == where) {
			return true;
		}
		for (int i = 0; i < req_n; i++) {
			if (v[i] || !g[where][i]) {
				continue;
			}
			v[i] = true;
			if (DFS(req_match[i])) {
				req_match[i] = where;
				return true;
			}
		}
		return false;
	}

	string moreClasses(string classesTaken, vector <string> requirements) {
		string res;
		memset(g, 0, sizeof(g));
		memset(req_match, -1, sizeof(req_match));
		req_n = 0;
		for (int i = 0; i < requirements.size(); i++) {
			int s = 0;

			int j = 0;
			while (isdigit(requirements[i][j])) {
				s = s * 10 + (requirements[i][j] - '0');
				++j;
			}

			for (; j < requirements[i].size(); j++) {
				for (int k = 0; k < s; k++) {
					g[ (int)requirements[i][j] ][req_n + k] = 1;
				}
			}
			req_n += s;
		}
		bool token[200];
		memset(token, 0, sizeof(token));
		for (int i = 0; i < classesTaken.size(); i++) {
			memset(v, 0, sizeof(v));
			DFS(classesTaken[i]);
			token[ (int)classesTaken[i]] = true; 
		}
		for (int i = 33; i <= 126; i++) {
			if (token[i]) {
				continue;
			}
			memset(v, 0, sizeof(v));
			if (DFS(i)) {
				res.push_back(i);
			}
		}

		for (int i = 0; i < req_n; i++) {
			if (-1 == req_match[i]) {
				res = "0";
				break;
			}
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string requirementsARRAY[] = {"2ABC","2CDE"};
		vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
		Graduation theObject;
		eq(0, theObject.moreClasses("A", requirements),"BCD");
	}
	{
		string requirementsARRAY[] = {"3NAMT","2+/","1M"};
		vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
		Graduation theObject;
		eq(1, theObject.moreClasses("+/NAMT", requirements),"");
	}
	{
		string requirementsARRAY[] = {"100%*Klju"};
		vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
		Graduation theObject;
		eq(2, theObject.moreClasses("A", requirements),"0");
	}
	{
		string requirementsARRAY[] = {"5ABCDE","1BCDE,"};
		vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
		Graduation theObject;
		eq(3, theObject.moreClasses("", requirements),",ABCDE");
	}
	{
		string requirementsARRAY[] = {"2AP", "3CDEF", "1CDEFH"};
		vector <string> requirements( requirementsARRAY, requirementsARRAY+ARRSIZE(requirementsARRAY) );
		Graduation theObject;
		eq(4, theObject.moreClasses("CDH", requirements),"AEP");
	}
}
// END CUT HERE
