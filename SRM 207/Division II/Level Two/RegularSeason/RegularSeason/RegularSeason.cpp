#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <utility>

using namespace std;

#define entry pair<int, string>		/* <羸的场数, 队名> */
#define MAX_TEAMS 20

class RegularSeason
{
public:
	vector <string> finalStandings(vector <string> teams, int rounds);
};

/* 比较函数 */
struct cmp {
	bool operator() (const entry &a, const entry &b)
	{
		if (a.first > b.first)	/* 按羸的场数 */
			return false;
		else if (a.first == b.first)
			return (a.second > b.second);	/* 按队名排序 */
		else
			return true;
	}
};

vector <string> RegularSeason::finalStandings(vector <string> teams, int rounds)
{
	int num = teams.size();
	int prob, pos1, pos2;
	int wins[MAX_TEAMS];	/* 期望羸的场数，为了简单，保存的是实际结果的100倍 */
	priority_queue < entry, vector <entry>, cmp > P;
	vector <string> ans;
	string name[MAX_TEAMS];		/* 队名 */

	for (int i = 0; i < num; i++) {
		wins[i] = 0;
	}

	for (int i = 0; i < num; i++) {
		pos1 = teams[i].find_first_of(' ', 0);
		name[i] = teams[i].substr(0, pos1);
		pos2 = pos1;
		for (int j = 0; j < num; j++) {
			pos1 = pos2;
			pos2 = teams[i].find_first_of(' ', pos1 + 1);

			if ( string::npos == pos2) {
				pos2 = teams[i].size();
			}
			prob = atoi(teams[i].substr(pos1+1, pos2-pos1+1).c_str());	/* 得到羸的可能值 */

			if (i != j) {		/* 更新期望值 */
				wins[j] += rounds * (100 - prob);
				wins[i] += rounds * prob;
			}	
		}
	}

	/* 用堆排序 */
	for (int i = 0; i < num; i++) {
		P.push( make_pair(wins[i], name[i]) );
	}
	for (int i = 0; i < num; i++) {
		int iwins = P.top().first;
		string teamname = P.top().second;
		P.pop();

		/* 四舍5入约分 */
		iwins = (iwins + 50) / 100;

		/* 数字转字符串 */
		stringstream sswins;
		sswins << iwins;

		string str = teamname + " " + sswins.str();
		ans.push_back(str);
	}

	return ans;
}

int main()
{
	RegularSeason R;
	vector <string> teasm;
	vector <string> ans;
	string t[] = {"NW 0 4 75 3 13 8 55 57 53 22 7 30 6 41", "MAR 13 0 25 82 51 27 99 92 12 28 71 47 29 34", "JOT 53 81 0 52 6 83 55 10 51 95 73 47 45 92", "A 55 36 89 0 66 12 51 11 28 55 79 37 86 75", "THU 46 36 44 59 0 38 63 56 48 84 18 0 11 4", "SHOKC 22 25 41 71 44 0 13 54 86 81 22 93 31 14", "CR 61 1 96 54 39 1 0 23 89 59 15 1 54 92", "R 65 22 40 97 9 40 51 0 33 33 63 25 29 53", "TXTO 90 48 33 68 46 58 41 93 0 12 67 15 24 11", "CG 10 69 83 49 45 65 42 64 10 0 83 37 88 52", "ZMFU 97 39 73 63 37 82 86 6 75 36 0 23 82 79", "JMZJ 27 56 17 12 76 41 28 17 54 24 32 0 22 66", "FQODY 70 67 64 5 33 96 32 31 16 37 27 97 0 23", "QBR 26 63 76 58 27 71 34 72 2 70 63 12 72 0"};
	int Round = 8;


	for (int i = 0; i < 14; i++) {
		teasm.push_back(t[i]);
	}
	
	ans = R.finalStandings(teasm, Round);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}