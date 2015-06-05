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

/*************** Program Begin **********************/

class PackingBallsDiv2 {
public:
    int minPacks(int R, int G, int B) {
        int res = 0;
	res = min(R, G);
	res = min(res, B);
	R -= res;
	G -= res;
	B -= res;
	res += R / 3 + G / 3 + B / 3;
	R %= 3;
	G %= 3;
	B %= 3;
	int s = R + G + B;
	if (s == 1 || s == 2) {
		res += 1;
	} else if (s == 3 || s == 4) {
		res += 2;
	}

        return res;
    }

};

/************** Program End ************************/

