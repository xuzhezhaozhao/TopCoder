#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountExpressions
{
public:
	int calcExpressions(int x, int y, int val);
};

int CountExpressions::calcExpressions(int x, int y, int val)
{
	int i, j, k;
	int sum, count;
	vector <int> vnum;
	if (x > y) {
		swap(x, y);
	}
	/* 保证 x < y */
	vnum.push_back(x);
	vnum.push_back(x);
	vnum.push_back(y);
	vnum.push_back(y);
	
	sum = 0;
	count = 0;
	do {
		for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
		for (k = 0; k < 3; k++) {
			switch (i) {
			case 0:
				sum = vnum[0] + vnum[1];
				break;
			case 1:
				sum = vnum[0] - vnum[1];
				break;
			case 2:
				sum = vnum[0] * vnum[1];
				break;
			}

			switch (j) {
			case 0:
				sum = sum + vnum[2];
				break;
			case 1:
				sum = sum - vnum[2];
				break;
			case 2:
				sum = sum * vnum[2];
				break;
			}

			switch (k) {
			case 0:
				sum = sum + vnum[3];
				break;
			case 1:
				sum = sum - vnum[3];
				break;
			case 2:
				sum = sum * vnum[3];
				break;
			}

			if (sum == val) {
				++count;
			}
		}
		}
		}
	} while (next_permutation(vnum.begin(), vnum.end()));	/* 4个数字不同的排列组合 */

	return count;
}

int main()
{

	return 0;
}