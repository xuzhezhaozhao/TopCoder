##Caution ！！！

Div II Level Three 的Dynamic Programming解法没有看懂，Editorial提供的[解法](http://www.baidu.com)看懂了。
没有看懂的代码如下：

	#include <algorithm>
	#include <iostream>
	#include <sstream>
	#include <string>
	#include <vector>

	using namespace std;


	/************** Program  Begin *********************/
	typedef long long LL;

	int mn[350];
	int dp[350];

	class WolfInZooDivTwo {
	public:
	    int count(int N, vector <string> L, vector <string> R) {
		for (int i = 0; i < 350; i++) {
			mn[i] = N;
			dp[i] = 0;
		}
		string sleft, sright;
		for (int i = 0; i < L.size(); i++) {
			sleft += L[i];
		}
		for (int i = 0; i < R.size(); i++) {
			sright += R[i];
		}
	
		int a, b;
		istringstream lss(sleft), rss(sright);
		while (lss >> a && rss >> b) {
			mn[a] = min(mn[a], b);
		}
	
		for (int i = N - 2; i >= 0; i--) {
			mn[i] = min(mn[i], mn[i+1]);
		}
	
		dp[0] = 1;
		for (int i = 0; i <= N; i++) {
			for (int j = i + 1; j <= mn[i] + 1; j++) {
				dp[j] = (dp[j] + dp[i]) % 1000000007;
			}
		}
	
		return dp[N+1];
	    }
	};

	/************** Program End ************************/


题目如下：

	Problem Statement
	
	    	Mr. Pasuterukun is walking along a straight road. He is cautious, because he has heard that there may be some wolves on the road. 
	
	
	
	The road consists of N sections. The sections are numbered 0 through N-1, in order. Each section of the road contains at most one wolf. 
	
	
	
	You have M additional pieces of information about the positions of the wolves. Each piece of information is an interval of the road that contains at least one wolf. More precisely, for each i between 0 and M-1, inclusive, you are given two integers left[i] and right[i] such that the sections with numbers in the range from left[i] to right[i], inclusive, contain at least one wolf in total. 
	
	
	
	You are given two vector <string>s L and R. The concatenation of all elements of L will be a single space separated list containing the integers left[0] through left[M-1]. R contains all the integers right[i] in the same format. 
	
	
	
	Return the number of ways in which wolves can be distributed in the sections of the road, modulo 1,000,000,007.
	Definition
	
	    	
	Class:	WolfInZooDivTwo
	Method:	count
	Parameters:	int, vector <string>, vector <string>
	Returns:	int
	Method signature:	int count(int N, vector <string> L, vector <string> R)
	(be sure your method is public)
	    
	Constraints
	
	-	N will be between 1 and 300, inclusive.
	-	L and R will contain between 1 and 50 elements, inclusive.
	-	Each element of L and R will contain between 1 and 50 characters, inclusive.
	-	Each character in L and R will be a digit ('0'-'9') or a space (' ').
	-	M will be between 1 and 300, inclusive.
	-	The concatenation of all elements of L will be a single space separated list of M integers. The integers will be between 0 and N-1, inclusive, and they will be given without unnecessary leading zeroes.
	-	The concatenation of all elements of R will be a single space separated list of M integers. The integers will be between 0 and N-1, inclusive, and they will be given without unnecessary leading zeroes.
	-	For each i, the i-th integer in L will be smaller than or equal to the i-th integer in R.
	Examples
	
	0)	
	    	
	5
	{"0 1"}
	{"2 4"}
	Returns: 27
	There is at least one wolf on the sections 0 through 2, and at least one wolf on the sections 1 through 4.
	1)	
	    	
	10
	{"0 4 2 7"}
	{"3 9 5 9"}
	Returns: 798
	2)	
	    	
	100
	{"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"}
	{"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"}
	Returns: 250671525
	You must first concatenate the elements of L and only then split it into integers. The same holds for R.
	3)	
	    	
	3
	{"1"}
	{"2"}
	Returns: 6
	The following picture shows all possible patterns. 
	
	
	
	
	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.