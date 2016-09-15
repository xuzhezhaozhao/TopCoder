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

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open A-small-practice.in!\n");
		exit(-1);
	}
	if (!freopen("jam.out", "w", stdout)) {
		printf("Can't open out.txt\n");
		exit(-1);
	}
#endif

	int T;
	scanf("%d", &T);
	for (int casei = 0; casei < T; ++casei) {
		int N;
		scanf("%d\n", &N);
		char buf[128];
		string leader = "";
		int mcnt = 0;
		for (int i = 0; i < N; ++i) {
			int h[26] = { 0 };
			fgets(buf, 128, stdin);
			char *p = buf;
			int cnt = 0;
			while (*p != '\0') {
				if (*p >= 'A' && *p <= 'Z') {
					cnt += 1 - h[(*p) - 'A'];
					h[(*p) - 'A'] = 1;
				}
				++p;
			}
			if (cnt > mcnt) {
				// update
				leader = buf;
				mcnt = cnt;
			}
			else if (cnt == mcnt) {
				leader = min(leader, string(buf));
			}
		}
		printf("Case #%d: %s", casei+1, leader.c_str());
	}
	
	return 0;
}