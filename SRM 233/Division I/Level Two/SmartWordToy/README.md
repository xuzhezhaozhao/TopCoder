##TopCoder: [SmartWordToy](http://community.topcoder.com/stat?c=problem_statement&pm=3935&rd=6532)

###Problem Statement
The toy company "I Can't Believe It Works!" has hired you to help 
develop educational toys. The current project is a word toy that 
displays four letters at all times. Below each letter are two buttons
that cause the letter above to change to the previous or next letter 
in alphabetical order. So, with one click of a button the letter 'c' 
can be changed to a 'b' or a 'd'. The alphabet is circular, so for 
example an 'a' can become a 'z' or a 'b' with one click. 



In order to test the toy, you would like to know if a word can be reached from 
some starting word, given one or more constraints. A constraint defines a set 
of forbidden words that can never be displayed by the toy. Each constraint is 
formatted like "X X X X", where each X is a string of lowercase letters. A word 
is defined by a constraint if the ith letter of the word is contained in the ith 
X of the contraint. For example, the constraint "lf a tc e" defines the words 
"late", "fate", "lace" and "face". 



You will be given a String start, a String finish, and a String[] forbid. 
Calculate and return the minimum number of button presses required for the toy 
to show the word finish if the toy was originally showing the word start. 
Remember, the toy must never show a forbidden word. If it is impossible for 
the toy to ever show the desired word, return -1.
 
###Definition
    	
Class:	SmartWordToy<br />
Method:	minPresses<br />
Parameters:	String, String, String[]<br />
Returns:	int<br />
Method signature:	int minPresses(String start, String finish, String[] forbid)<br />
(be sure your method is public)<br />
    
 
###Constraints
-	start and finish will contain exactly four characters.
-	start and finish will contain only lowercase letters.
-	forbid will contain between 0 and 50 elements, inclusive.
-	Each element of forbid will contain between 1 and 50 characters.
-	Each element of forbid will contain lowercase letters and exactly three spaces.
-	Each element of forbid will not contain leading, trailing or double spaces.
-	Each letter within a group of letters in each element of forbid will be distinct. Thus "aa a a a" is not allowed.
-	start will not be a forbidden word.
 
###Examples
0)	
    	
> "aaaa" <br />
> "zzzz"<br />
> {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}<br />

Returns: 8


1)	
    	
> "aaaa" <br />
> "bbbb" <br />
> {} <br />

Returns: 4 <br />
Simply change each letter one by one to the following letter in the alphabet.


2)	
    	
> "aaaa" <br />
> "mmnn" <br />
> {} <br />

Returns: 50 <br />
Just as in the previous example, we have no forbidden words. Simply apply the correct number of button presses for each letter and you're there.


3)	
    	
> "aaaa" <br />
> "zzzz" <br />
> {"bz a a a", "a bz a a", "a a bz a", "a a a bz"} <br />

Returns: -1 <br />
Here is an example where it is impossible to go to any word from "aaaa".


4)	
    	
> "aaaa" <br />
> "zzzz" <br />
> {"cdefghijklmnopqrstuvwxyz a a a",  <br />
> "a cdefghijklmnopqrstuvwxyz a a",  <br />
> "a a cdefghijklmnopqrstuvwxyz a", <br />
> "a a a cdefghijklmnopqrstuvwxyz"}<br />

Returns: 6


5)	
    	
> "aaaa" <br />
> "bbbb"<br />
> {"b b b b"}<br />

Returns: -1


6)	
    	
> "zzzz" <br />
> "aaaa" <br />
> {"abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", <br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", <br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", <br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", <br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk", <br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk",<br />
>  "abcdefghijkl abcdefghijkl abcdefghijkl abcdefghijk"}<br />

Returns: -1


This problem statement is the exclusive and proprietary property of TopCoder, 
Inc. Any unauthorized use or reproduction of this information without the prior
 written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, 
 Inc. All rights reserved.


This problem was used for: 
       [Single Round Match 233 Round 1 - Division I, Level Two](http://community.topcoder.com/tc?module=ProblemDetail&rd=6532&pm=3935)