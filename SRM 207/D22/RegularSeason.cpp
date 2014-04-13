#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class RegularSeason
{
public:
	vector <string> finalStandings(vector <string> teams, int rounds);
};

struct Team {
	int wins;
	string name;
};

/* 比较函数 */
bool cmp (const Team &a, const Team &b)
{
	if ( a.wins != b.wins ) {
		return a.wins > b.wins;	/* 按 wins */
	} else {	
		return a.name < b.name;	/* 按 name */
	}
}

//bool operator< (const Team &a, const Team &b)
//{
//	if ( a.wins != b.wins ) {
//		return a.wins > b.wins;	/* 按 wins */
//	} else {	
//		return a.name < b.name;	/* 按 name */
//	}
//};

vector <string> RegularSeason::finalStandings(vector <string> teams, int rounds)
{
	int num = teams.size();
	int prob;
	vector <Team> vt(num);
	vector <string> ans;

	for (int i = 0; i < num; i++) {
		vt[i].wins = 0;
	}

	for (int i = 0; i < num; i++) {
		istringstream iss(teams[i]);
		iss >> vt[i].name;
		for (int j = 0; j < num; j++) {
			iss >> prob;	/* 得到羸的可能值 */
			if (i != j) {		/* 更新期望值 */
				vt[j].wins += rounds * (100 - prob);
				vt[i].wins += rounds * prob;
			}	
		}
	}

	sort(vt.begin(), vt.end(), cmp);
	for (int i = 0; i < num; i++) {
		ostringstream oss;
		int iwins = vt[i].wins;
		string teamname = vt[i].name;

		/* 四舍5入约分 */
		iwins = (iwins + 50) / 100;

		oss << teamname << " " << iwins;

		ans.push_back(oss.str());
	}

	return ans;
}

int main()
{
	RegularSeason R;
	vector <string> teasm;
	vector <string> ans;
	string t[] = {"A 0 10 20 30 40 50 60 70 80 90", "AA 90 0 10 20 30 40 50 60 70 80", "AAA 80 90 0 10 20 30 40 50 60 70", "AAAA 70 80 90 0 10 20 30 40 50 60", "AAAAA 60 70 80 90 0 10 20 30 40 50", "AAAAAA 50 60 70 80 90 0 10 20 30 40", "AAAAAAA 40 50 60 70 80 90 0 10 20 30", "AAAAAAAA 30 40 50 60 70 80 90 0 10 20", "AAAAAAAAA 20 30 40 50 60 70 80 90 0 10", "AAAAAAAAAA 10 20 30 40 50 60 70 80 90 0"}
	;
	int Round = 10;


	for (int i = 0; i < 10; i++) {
		teasm.push_back(t[i]);
	}
	
	ans = R.finalStandings(teasm, Round);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}