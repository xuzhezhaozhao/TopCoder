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


/*************** Program Begin **********************/

int l[27];
class GooseTattarrattatDiv2 {
public:
    int getmin(string S) {
	int res = 0;
	int N = S.size();
	memset(l, 0, sizeof(l));

	for (int i = 0; i < N; i++) {
		++l[S[i] - 'a'];
	}
	int m = *max_element(l, l + 27);
	res = N - m;

	return res;
    }

};

/************** Program End ************************/

int main()
{

	return 0;
}

// Powered by FileEdit
// Powered by CodeProcessor
