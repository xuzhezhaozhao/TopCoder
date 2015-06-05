#include <iostream>
#include <string>
#include <set>

using namespace std;

class TopFox {
public:
	int possibleHandles(string familyName, string givenName)
	{
		set <string> name;
		string str;
		for (int i = 0; i < familyName.length(); i++) {
			for (int j = 0; j < givenName.length(); j++) {
				str = familyName.substr(0, i+1) + givenName.substr(0, j+1);
				name.insert(str);
			}
		}
		return name.size();
	}
};

int main()
{

	return 0;
}