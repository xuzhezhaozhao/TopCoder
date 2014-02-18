#include <iostream>
#include <vector>

using namespace std;

class YahtzeeScore
{
public:
	int maxPoints(vector <int> toss);
};

int YahtzeeScore::maxPoints(vector<int> toss)
{
	int i, j;
	int size = toss.size();
	int maxP = 0;
	int sum;

	for (i = 0; i < size; i++) {
		sum = 0;
		for (j = 0; j < size; j++) {
			if (toss[i] == toss[j]) {
				sum += toss[i];
			}
		}
		if (sum > maxP) {
			maxP = sum;
		}
	}
	return maxP;
}

int main()
{
	int i;
	int t[] = {2, 3, 2, 2, 5}
	;
	vector <int> toss;
	YahtzeeScore Y;
	for (i = 0; i < 5; i++) {
		toss.push_back(t[i]);
	}

	cout << Y.maxPoints(toss) << endl;
}