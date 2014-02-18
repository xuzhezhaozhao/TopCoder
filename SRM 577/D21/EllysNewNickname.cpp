#include <iostream>
#include <string>
using namespace std;

class EllysNewNickname {
public:
	int getLength(string nickname);
};

int EllysNewNickname::getLength(string nickname)
{
	bool flag1, flag2;
	int len;

	flag1 = flag2 = false;
	len = 0;
	for (int i = 0; i < nickname.length(); i++) {
		if (true == flag1 && ( 'a' == nickname[i] || 'e' == nickname[i] || 'i' == nickname[i]
		    || 'o' == nickname[i] || 'u' == nickname[i] || 'y' == nickname[i] ) ) {
			flag2 = true;
		} else {
			flag2 = false;
		}
		if ('a' == nickname[i] || 'e' == nickname[i] || 'i' == nickname[i]
		    || 'o' == nickname[i] || 'u' == nickname[i] || 'y' == nickname[i]) {
			flag1 = true;
		} else {
			flag1 = false;
		}
		if (!flag2) {
			++len;
			flag2 = false;
		}
	}
	return len;
}

int main()
{
	EllysNewNickname E;
	string nick = "ayayayayayaya"

	;
	cout << E.getLength(nick) << endl;
	
	return 0;
}