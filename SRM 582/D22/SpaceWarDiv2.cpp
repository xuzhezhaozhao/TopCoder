#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int F[50];

class SpaceWarDiv2
{
public:
	int minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector <int> enemyCount);
};

int SpaceWarDiv2::minimalFatigue(vector<int> magicalGirlStrength, vector<int> enemyStrength, vector<int> enemyCount)
{
	int maxMS, maxES;
	int i, j;
	maxMS = *max_element(magicalGirlStrength.begin(), magicalGirlStrength.end());
	maxES = *max_element(enemyStrength.begin(), enemyStrength.end());
	if (maxMS < maxES) {
		return -1;
	}

	for (i = 0; i < 50; i++) {
		F[i] = 0;
	}

	sort(magicalGirlStrength.begin(), magicalGirlStrength.end());

	for (i = 0; i < enemyStrength.size()-1; i++) {
		for (j = i+1; j < enemyStrength.size(); j++) {
			if (enemyStrength[i] > enemyStrength[j]) {
				swap(enemyStrength[i], enemyStrength[j]);
				swap(enemyCount[i], enemyCount[j]);
			}
		}
	}
	while (!enemyCount.empty()) {
		for (i = 0; i < magicalGirlStrength.size(); i++) {
			j = enemyStrength.size() - 1;
			while (j >= 0 && magicalGirlStrength[i] < enemyStrength[j]) {
				--j;
			}

			if (j >= 0) {
				++F[i];
				--enemyCount[j];
				if (0 == enemyCount[j]) {
					enemyCount.erase(enemyCount.begin() + j);
					enemyStrength.erase(enemyStrength.begin() + j);
				}
			}
		}
	}


	return *max_element(F, F + magicalGirlStrength.size());
}

int main()
{
	SpaceWarDiv2 sq;
	vector <int> magicalGirlStrength;
	vector <int> enemyStrength;
	vector <int> enemyCount;

	int magical[] = {17, 10, 29, 48, 92, 60, 80, 15, 69, 36, 43, 70, 14, 88, 12, 14, 29, 9, 40, 100};
	int enemy[] = {93, 59, 27, 68, 48, 82, 15, 95, 61, 49, 68, 15, 16, 26, 64, 82, 7, 8, 92, 15};
	int count[] = {56, 26, 12, 52, 5, 19, 93, 36, 69, 61, 68, 66, 55, 28, 49, 55, 63, 57, 33, 45};

	for (int i = 0; i < 20; i++) {
		magicalGirlStrength.push_back(magical[i]);
		enemyStrength.push_back(enemy[i]);
		enemyCount.push_back(count[i]);
	}

	cout << sq.minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount) << endl;

	return 0;
}