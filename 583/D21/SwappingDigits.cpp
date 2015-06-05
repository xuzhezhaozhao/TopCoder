#include <iostream>
#include <string>

using namespace std;

string minstr = "";

class SwappingDigits
{
public: string minNumber(string num);
};



string SwappingDigits::minNumber(string num)
{
	string temp;
	string mins = "";
	for (int i = 0; i < num.size()-1; i++) {
		for (int j = i+1; j < num.size(); j++) {
			temp = num;
			swap(temp[i], temp[j]);
			if (temp[0] != '0' && mins == "") {
				mins = temp;
			} else {
				if (temp[0] != '0' && temp < mins) {
					mins = temp;
				}
			}
		}
	}

	return mins;
}

int main()
{
	class SwappingDigits sd;
	string num = "9191386619601631";
	cout << sd.minNumber(num) << endl;

	return 0;
}