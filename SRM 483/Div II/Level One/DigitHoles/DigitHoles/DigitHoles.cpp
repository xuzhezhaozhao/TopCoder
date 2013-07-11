#include <iostream>

using namespace std;

class DigitHoles {
public:
	int numHoles(int number);
};

int DigitHoles::numHoles(int number)
{
	int holes[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
	int res;
	int ans;
	ans = 0;
	do {
		res = number % 10;
		number = number / 10;
		ans += holes[res];
	} while (number != 0);

	return ans;
}

int main()
{
	DigitHoles D;
	int n = 779;

	cout << D.numHoles(n) << endl;

	return 0;
}