#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;
class IDNumberVerification
{
public:
	string verify(string id, vector <string> regionCodes);
};

string IDNumberVerification::verify(string id, vector<string> regionCodes)
{
	string region;
	string year;
	string monday;
	string month, day;
	string seq;
	string checksum;
	string gender;
	int nyear, nmonth, nday, nchecksum, nseq;
	int sum;
	int days_notleap[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days_leap[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int *days;

	region = id.substr(0, 6);
	year = id.substr(6, 4);
	monday = id.substr(10, 4);
	month = id.substr(10, 2);
	day = id.substr(12, 2);
	seq = id.substr(14, 3);
	checksum = id.substr(17, 1);
	gender = id.substr(14, 3);
	bool flag = false;
	/* seq */
	if (seq == "000") {
		return "Invalid";
	}
	/* region */
	for (int i = 0; i < regionCodes.size(); i++) {
		if (region == regionCodes[i]) {
			flag = true;
		}
	}
	if (!flag) {
		return "Invalid";
	}
	/* data */
	bool leap = false;
	nyear = atoi(year.c_str());

	if (nyear < 1900 || nyear > 2011) {
		return "Invalid";
	}

	if ( (nyear % 4 == 0 && nyear % 100 != 0) ||
		(nyear % 400 == 0) ) {
		leap = true;
	}
	if ("0229" == monday && !leap) {
		return "Invalid";
	}
	days = days_notleap;
	if (leap) {
		days = days_leap;
	}
	
	nmonth = atoi(month.c_str());
	nday = atoi(day.c_str());
	if (nmonth > 12 || nmonth < 1) {
		return "Invalid";
	}

	if (nday > days[nmonth] || nday < 1) {
		return "Invalid";		
	}

	/* checksum */
	sum = 0;
	for (int i = 0; i < 17; i++) {
		sum = (sum * 2) + id[i] - '0';
	}
	sum = 2 * sum;

	nchecksum = checksum[0] - '0';
	if (checksum[0] == 'X') {
		nchecksum = 10;
	}
	int rchecksum = 12 - sum % 11;
	if (rchecksum == 11) {
		rchecksum = 0;
	}
	if ( nchecksum != rchecksum ) {
		return "Invalid";
	}
	
	/* gender */
	nseq = atoi(seq.c_str());
	if (nseq % 2 != 0) {
		return "Male";		
	} else {
		return "Female";
	}
}

int main()
{
	IDNumberVerification ver;
	string id = "230231198306100162";
	vector <string> regionCodes;
	regionCodes.push_back("230231");
	regionCodes.push_back("520381");

	cout << ver.verify(id, regionCodes) << endl;;

	return 0;
}