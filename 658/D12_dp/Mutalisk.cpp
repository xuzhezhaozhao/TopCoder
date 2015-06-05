#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int dp[21][94][94];
class Mutalisk {
public:
	bool canBe(const vector<int> &x, int t) {
		const int INF = 2 * t;
		memset(dp, 0, sizeof(dp));
		for (size_t n = 1; n <= x.size(); n++) {
			for (int d9 = 0; d9 <= t; d9++) {
				for (int d3 = 0; d3 <= t; d3++) {
					dp[n][d9][d3] = INF;
					for (int u9 = 0; u9 <= d9 && 9*u9 <= x[n-1]+9; u9++) {
						for (int u3 = 0; u3 <= d3 && 9*u9 + 3*u3 <= x[n-1]+9; u3++) {
							int u1 = max(0, x[n-1] - 9*u9 - 3*u3);
							if (u1 + u9 + u3 <= t) {
								int x = dp[n-1][d9-u9][d3-u3] + u1;
								dp[n][d9][d3] = min(dp[n][d9][d3], x);
							}
						}
					}
				}
			}
		}

		return (dp[x.size()][t][t] <= t);
	}

	int minimalAttacks(vector <int> x) {
		int lo = 0;
		int hi = 93;
		while (lo + 1 < hi) {
			int ha = lo + (hi - lo) / 2;
			if (canBe(x, ha)) {
				hi = ha;
			} else {
				lo = ha;
			}
		}

		return hi;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	Mutalisk *obj;
	int answer;
	obj = new Mutalisk();
	clock_t startTime = clock();
	answer = obj->minimalAttacks(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	if (hasAnswer) {
		res = answer == p1;
	}
	cout << "Test " << testNum << " ";
	if (!res) {
		cout << "failed." << endl;
		cout << "expected: ";
		cout << "\t" << p1 << endl;
		cout << "received: ";
		cout << "\t" << answer << endl;
		cout << "" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "passed.      ";
		cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds";
		cout << "" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <int> p0;
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {12,10,4};
	p1 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {54,18,6};
	p1 = 6;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,1,1,1,1,1,1,1,1,1};
	p1 = 4;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {55,60,53};
	p1 = 13;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {60};
	p1 = 7;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
	p1 = 93;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		cout << "" << endl;
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
