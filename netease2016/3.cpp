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

char buf[1000005];


inline bool is_op(char c) {
	return (c == '+' || c == '-' || c == '*');
}
inline bool is_num(char c) {
	return (c >= '0' && c <= '9');
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int T;
	scanf("%d\n", &T);
	for (int casei = 0; casei < T; ++casei) {
		fgets(buf, sizeof(buf), stdin);
		int N = strlen(buf);
		int pos = 0;
		stack<char> op;
		stack<pair<int, long long>> num; 

		bool error = false;
		while (pos < N) {
			if (buf[pos] == '(') {
				op.push('(');
				++pos;
			} else if (is_op(buf[pos])) {
				if (op.empty() || op.top() != '(') {
					error = true;
					break;
				}
				op.push(buf[pos]);
				num.push({-1, -1});
				++pos;
			} else if (buf[pos] == ')') {
				// 计算表达式的值
				if (op.empty()) {
					error = true;
					break;
				}
				char opt = op.top();
				op.pop();	// pop 'opt'
				if (!is_op(opt)) {
					error = true;
					break;
				}
				if (op.empty() || op.top() != '(') {
					error = true;
					break;
				}
				op.pop();	// pop '('

				long long r = 0;
				if (opt == '+') {
					while (num.top().first != -1) {
						r += num.top().second;
						num.pop();
					}
				} else if (opt == '-') {
					long long n1 = 0, n2 = 0;
					bool f1 = false, f2 = false;
					bool ok = true;
					while (num.top().first != -1) {
						if (!f1) {
							f1 = true;
							n1 = num.top().second;
						} else if (!f2) {
							f2 = true;
							n2 = num.top().second;
						} else {
							// 操作数过多
							ok = false;
							break;
						}
						num.pop();
					}
					if (!ok) {
						error = true;
						break;
					}
					if (!f2) {
						r = -n1;
					} else {
						r = n2 - n1;
					}
				} else if (opt == '*') {
					// '*'
					r = 1;
					while (num.top().first != -1) {
						r *= num.top().second;
						num.pop();
					}
				}
				num.pop();		// pop -1
				num.push({0, r});	// push result
				++pos;
			} else if (buf[pos] == ' ' || buf[pos] == '\n') {
				// 空格
				++pos;
			} else {
				// number
				long long number = buf[pos] - '0';
				int pos2 = pos+1;
				while (pos2 < N && is_num(buf[pos2])) {
					number *= 10;
					number += buf[pos2] - '0';
					++pos2;
				}
				pos = pos2;
				num.push({0, number});
			}
		}
		
		if (!op.empty()) {
			error = true;
		}
		if (num.size() != 1) {
			error = true;
		}

		if (error) {
			printf("Invalid expression.\n");
		} else {
			printf("%lld\n", num.top().second);
			num.pop();
		}
	}

	return 0;
}
