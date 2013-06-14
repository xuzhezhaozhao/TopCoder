#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class SemiPerfectSquare
{
public:
	string check(int N);
};



string SemiPerfectSquare::check(int N)
{
	int sq = (int)sqrt((double)N);

	for (int i = 0; i <= sq; i++) {
		for (int j = 0; j < i; j++) {
			if (j * i * i == N) {
				return "Yes";
			}
		}
	}

	return "No";
}



int main()
{
	SemiPerfectSquare se;
	cout << se.check(48) << endl;

	return 0;
}