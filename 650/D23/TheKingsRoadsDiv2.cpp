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

const int MAX_H = 10;
bool used[1 << MAX_H];
int parent[1 << MAX_H];

class TheKingsRoadsDiv2 {
public:
    string getAnswer(int h, vector <int> a, vector <int> b) {
		string correct = "Correct";
		string incorrect = "Incorrect";

		int N = (1 << h) - 1;
		for (int lack = 0; lack < (int)a.size(); lack++) {
			vector <vector<int> > tree(N + 1);
			bool ok = true;
			for (int i = 0; i < (int)a.size(); i++) {
				if (i != lack) {
					if (a[i] == b[i]) {
						ok = false;
						break;
					}
					tree[a[i]].push_back(b[i]);
					tree[b[i]].push_back(a[i]);
				}
			}
			if (ok && check(tree, h)) {
				return correct;
			}
		}

		return incorrect;
    }

	bool check(vector <vector<int> > &tree, int h) {
		int root = 0;
		for (int i = 1; i < (int)tree.size(); i++) {
			if (tree[i].size() == 2) {
				root = i;
				break;
			}
		}
		if (!root) {
			return false;
		}
		
		memset(used, 0, sizeof(used));
		memset(parent, 0, sizeof(parent));
		used[root] = true;
		set<int> vex; 
		parent[root] = 0;
		vex.insert(root);
		
		for (int layer = 2; layer <= h; layer++) {
			set<int> tmp;
			for (auto cur : vex) {
				if (cur != root && tree[cur].size() != 3) {
					return false;
				}
				for (auto next : tree[cur]) {
					if (used[next]) {
						if (next == parent[cur]) {
							continue;
						} else {
							return false;
						}
					}

					parent[next] = cur;
					used[next] = true;
					tmp.insert(next);
				}
			}
			if ((int)tmp.size() != (1 << (layer-1))) {
				return false;
			}
			vex = tmp;
		}

		return true;
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
        int aARRAY[] = {1, 2, 3, 7, 1, 5, 4};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {6, 7, 4, 3, 3, 1, 7};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        TheKingsRoadsDiv2 theObject;
		eq(0, theObject.getAnswer(3, a, b),"Correct");
    }
    {
        int aARRAY[] = {1, 2, 3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2, 1, 3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        TheKingsRoadsDiv2 theObject;
        eq(1, theObject.getAnswer(2, a, b),"Incorrect");
    }
    {
        int aARRAY[] = {7, 1, 1, 2, 2, 3, 1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {7, 1, 7, 4, 5, 2, 6};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        TheKingsRoadsDiv2 theObject;
		eq(2, theObject.getAnswer(3, a, b),"Incorrect");
    }
    {
        int aARRAY[] = {1, 3, 3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2, 1, 2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        TheKingsRoadsDiv2 theObject;
		eq(3, theObject.getAnswer(2, a, b),"Correct");
    }
    {
        int aARRAY[] = {6, 5, 3, 3, 5, 5, 6};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1, 5, 5, 6, 4, 7, 2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        TheKingsRoadsDiv2 theObject;
        eq(4, theObject.getAnswer(3, a, b),"Correct");
    }
	return 0;
}
// END CUT HERE
