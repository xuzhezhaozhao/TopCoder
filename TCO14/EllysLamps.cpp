// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysLamps.cpp"
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
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class EllysLamps
{
public:
	string lamps;
        int getMin(string lamps)
        {
		int res = 0;
		long long a = LLONG_MAX;
		for (int i = 0; i < lamps.size(); i++) {
			++res;
		}

		return res;
        }
	
/************** Program End ************************/

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNNYN"; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "NNN"; int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "YY"; int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "YNYYYNNNY"; int Arg1 = 3; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"; int Arg1 = 13; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysLamps ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
