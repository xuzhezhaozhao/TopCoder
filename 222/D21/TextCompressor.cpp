#include <iostream>
#include <string>

using namespace std;

class TextCompressor {
public:
	string longestRepeat(string sourceText);
};

string TextCompressor::longestRepeat(string sourceText)
{
	int len = sourceText.length();
	string longestSub, substr;
	int maxLen = 0;

	for (int pos = 0; pos < len; pos++) {
		for (int sublen = 1; sublen <= (len - pos) / 2; sublen++) {
			substr = sourceText.substr(pos, sublen);
			if (string::npos != sourceText.find(substr, pos + sublen)) {
				if (maxLen < sublen) {
					maxLen = sublen;
					longestSub = substr;
				}
			}
		}
	}
	return longestSub;
}

int main()
{
	TextCompressor T;
	string so = "EbYLxNpxCd.vchJWh4j.ZN83sEbYLxNpxCd.vchJWh4j.ZN83";

	cout << T.longestRepeat(so) << "***" << endl;
}