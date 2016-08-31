#include <cassert>
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

typedef pair<int, int> pii;
#define mkp make_pair

bool is_number(char c) {
	return ( c >= '0' && c <= '9' );
}
bool is_alpha(char c) {
	return ( c >= 'A' && c <= 'Z' );
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int T;
	scanf("%d", &T);
	char buf[128];
	for (int case_i = 0; case_i < T; ++case_i) {
		scanf("%s", buf);
		stack<char> symbol;
		stack<int> res;
		int N = strlen(buf);

		for (int i = 0; i < N; /* update in the loop body */) {
			if (is_alpha(buf[i])) {
				// get lenth
				int len = 1;
				int j = i+1;
				while (j < N && is_alpha(buf[j])) {
					++len;
					++j;
				}
				int num = 1;
				if (j < N && is_number(buf[j])) {
					num = buf[j] - '0';
					++j;
					while (j < N && is_number(buf[j])) {
						 num *= 10;
						 num += buf[j] -'0';
						 ++j;
					}
				}
				len += num-1;

				i = j;
				if (!symbol.empty()) {
					char s = symbol.top();
					if (s == '+') {
						len += res.top();
						res.pop();
						symbol.pop();
					}
				}
				res.push(len);
				symbol.push('+');
			} else if (buf[i] == '(') {
				symbol.push('(');
				++i;
			} else if (buf[i] == ')') {
				int num = 1;
				int j = i+1;
				if (j < N && is_number(buf[j])) {
					num = buf[j] - '0';
					++j;
					while (j < N && is_number(buf[j])) {
						 num *= 10;
						 num += buf[j] -'0';
						 ++j;
					}
				}
				i = j;
				assert(!res.empty());
				int n = res.top();
				res.pop();
				n *= num;
				assert(symbol.top() == '+');
				symbol.pop();
				assert(symbol.top() == '(');
				symbol.pop();
				if (!symbol.empty()) {
					if (symbol.top() == '+') {
						symbol.pop();
						n += res.top();
						res.pop();
					}
				}
				res.push(n);
				symbol.push('+');
			}
		}
		
		int len = res.top();
		res.pop();
		assert(res.empty());
		printf("%d\n", len);
	}

	return 0;
}

