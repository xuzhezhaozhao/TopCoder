$BEGINCUT$
$PROBLEMDESC$
$ENDCUT$
#line $NEXTLINENUMBER$ "$FILENAME$"
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

class $CLASSNAME$
{
public:
        $RC$ $METHODNAME$($METHODPARMS$)
        {
		$RC$ res;

		return res;
        }
	
/************** Program End ************************/

        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        $CLASSNAME$ ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
