// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
	if ( delim.find( s[i] ) != string::npos ) {
	    if ( !t.empty() ) {
		res.push_back( t );
		t = "";
	    }
	} else {
	    t += s[i];
	}
    }
    if ( !t.empty() ) {
	res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
	res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
	if ( i != 0 ) cerr << ", ";
	print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
	cerr << "Case " << n << " failed: expected ";
	print( need );
	cerr << " received ";
	print( have );
	cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
	cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
	print( have );
	print( need );
	return;
    }
    for( int i= 0; i < have.size(); i++ ) {
	if( have[i] != need[i] ) {
	    cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
	    print( have );
	    print( need );
	    return;
	}
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
	cerr << "Case " << n << " failed: expected ";
	print( need );
	cerr << " received ";
	print( have );
	cerr << "." << endl;
    }
}
// END CUT HERE

/*******************************************************/
/******************************************************/
/************** Program  Begin *********************/

class HealthFood {
private:
	vector <int> getH(vector <int> &carbs, vector <int> &indexs)
	{
		vector <int> ans;
		int maxc = -1;

		for (int i = 0; i < indexs.size(); i++) {
			if (carbs[ indexs[i] ] > maxc) {
				maxc = carbs[ indexs[i] ];
			}
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (maxc == carbs[ indexs[i] ]) {
				ans.push_back(indexs[i]);
			}
		}
		return ans;
	}
	vector <int> getL(vector <int> &carbs, vector <int> &indexs)
	{
		vector <int> ans;
		int minc = 1000;

		for (int i = 0; i < indexs.size(); i++) {
			if (carbs[ indexs[i] ] < minc) {
				minc = carbs[ indexs[i] ];
			}
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (minc == carbs[ indexs[i] ]) {
				ans.push_back(indexs[i]);
			}
		}
		return ans;
	}
	vector <int> getHT(vector <int> &protein, vector <int> &carbs, vector <int> &fat, vector <int> &indexs)
	{
		vector <int> ans;
		vector <int> total(protein.size());
		int maxt = -1;

		for (int k = 0; k < protein.size(); k++) {
			total[k] = 5 * (protein[k] + carbs[k]) + 9 * fat[k];
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (total[ indexs[i] ] > maxt) {
				maxt = total[ indexs[i] ];
			}
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (maxt == total[ indexs[i] ]) {
				ans.push_back(indexs[i]);
			}
		}

		return ans;
	}
	vector <int> getLT(vector <int> &protein, vector <int> &carbs, vector <int> &fat, vector <int> &indexs)
	{
		vector <int> ans;
		vector <int> total(protein.size());
		int mint = 1000000;

		for (int i = 0; i < protein.size(); i++) {
			total[i] = 5 * (protein[i] + carbs[i]) + 9 * fat[i];
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (total[ indexs[i] ] < mint) {
				mint = total[ indexs[i] ];
			}
		}

		for (int i = 0; i < indexs.size(); i++) {
			if (mint == total[ indexs[i] ]) {
				ans.push_back(indexs[i]);
			}
		}

		return ans;
	}

public:
vector <int> selectMeals(vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans) {
	vector <int> res;
	int plan_num = dietPlans.size();

	for (int i = 0; i < plan_num; i++) {
		if ("" == dietPlans[i]) {
			res.push_back(0);
			continue;
		}
		vector <int> indexs;
		for (int k = 0; k < protein.size(); k++) {
			indexs.push_back(k);
		}
		bool flag = false;

		for (int j = 0; j < dietPlans[i].size(); j++) {
			switch (dietPlans[i][j]) {
			case 'C':
				indexs = getH(carbs, indexs);
				break;
			case 'c':
				indexs = getL(carbs, indexs);
				break;
			case 'P':
				indexs = getH(protein, indexs);
				break;
			case 'p':
				indexs = getL(protein, indexs);
				break;
			case 'F':
				indexs = getH(fat, indexs);
				break;
			case 'f':
				indexs = getL(fat, indexs);
				break;
			case 'T':
				indexs = getHT(protein, carbs, fat, indexs);
				break;
			case 't':
				indexs = getLT(protein, carbs, fat, indexs);
				break;
			}

			if (1 == indexs.size()) {
				res.push_back(indexs[0]);
				flag = true;
			} else {
				if (j == dietPlans[i].size() - 1) {
					res.push_back(indexs[0]);
					flag = true;
				} else {
					continue;
				}
			}
			if (flag) {
				break;
			}
		}
	}

	return res;
    }

};

/************** Program End ************************/
/******************************************************/
/******************************************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int proteinARRAY[] = {54, 24, 97, 51, 91, 42, 91, 44, 8, 47, 31, 30, 40, 53, 73, 54, 96, 76, 65, 49, 93, 92, 74, 1, 51, 1, 87, 57, 25, 66, 60, 39, 49, 74, 47, 96, 11, 82, 15, 23, 28, 77, 93, 90, 24, 72, 67, 89, 51};
	vector <int> protein( proteinARRAY, proteinARRAY+ARRSIZE(proteinARRAY) );
	int carbsARRAY[] = {83, 41, 40, 50, 61, 67, 16, 63, 66, 76, 28, 2, 95, 13, 65, 0, 72, 40, 94, 20, 57, 59, 30, 89, 59, 88, 9, 22, 95, 70, 10, 88, 25, 29, 31, 74, 77, 47, 22, 1, 81, 1, 91, 44, 3, 29, 70, 39, 83};
	vector <int> carbs( carbsARRAY, carbsARRAY+ARRSIZE(carbsARRAY) );
	int fatARRAY[] =  {57, 59, 10, 71, 42, 88, 49, 18, 5, 98, 92, 64, 90, 27, 41, 78, 40, 15, 18, 50, 86, 59, 98, 78, 71, 77, 73, 90, 89, 44, 22, 19, 61, 90, 11, 70, 83, 77, 81, 59, 78, 21, 77, 84, 83, 17, 21, 70, 39};
	vector <int> fat( fatARRAY, fatARRAY+ARRSIZE(fatARRAY) );
	string dietPlansARRAY[] = {"ptpt"};
	vector <string> dietPlans( dietPlansARRAY, dietPlansARRAY+ARRSIZE(dietPlansARRAY) );
	int retrunValueARRAY[] = { 25 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	HealthFood theObject;
	eq(0, theObject.selectMeals(protein, carbs, fat, dietPlans),retrunValue);
    }
 
}
// END CUT HERE
