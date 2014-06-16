#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define Rate(win, i) ( (double)(win) / (double)(i) * 100)
#define PRECISE 0.000001

class WinningRecord
{
public:
	vector <int> getBestAndWorst(string games);
};

vector <int> WinningRecord::getBestAndWorst(string games)
{
	int i;
	int best, worst, win;
	double bestRate, worstRate, rate;
	int length;
	vector <int> ans;

	best = worst = win = 0;
	length = games.size();
	bestRate =  0;
	worstRate = 100;

	for (i = 0; i < 2; i++) {
		if ('W' == games[i]) {
			++win;
		}
	}

	for (i = 2; i < length; i++) {
		if ('W' == games[i]) {
			++win;
		}

		rate = Rate(win, i+1);
		if ( rate - bestRate > PRECISE || abs(bestRate - rate) < PRECISE ) {
			bestRate = rate;
			best = i + 1;
		}

		if ( worstRate - rate > PRECISE || abs(worstRate - rate) < PRECISE ) {
			worstRate = rate;
			worst = i + 1;
		}
	}

	ans.push_back(best);
	ans.push_back(worst);
	return ans;
}

int main()
{
	WinningRecord W;
	vector <int> ans;

	string str = "LLLLLLLLL"
	;
	ans=  W.getBestAndWorst(str);
	cout << ans[0] << ", " << ans[1] << endl;
}