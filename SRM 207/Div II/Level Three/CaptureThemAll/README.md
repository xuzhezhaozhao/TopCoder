##TopCoder: [CaptureThemAll](http://community.topcoder.com/stat?c=problem_statement&pm=2915&rd=5853)

###Problem Statement
Harry is playing magical chess. In this version of the game, all 
pieces move the same way as in regular chess, but players can cast 
some magical spells. Unfortunately, Harry's opponent, Joe, has captured
all of Harry's pieces except one knight; Joe, on the other hand, still 
has a queen and a rook. The only chance Harry has to win this game is 
to cast a spell, "Haste", that will allow Harry's knight to make 
several moves in a row. You should determine the minimal number of moves
the knight needs to capture both the rook and the queen, assuming neither
of them moves. You may capture them in either order - rook first or queen
first. 

You will be given a String, knight, containing information about the knight. 
You will also be given a String, queen, and a String, rook, giving you 
information about Joe's pieces. knight, rook and queen will be formatted as 
"cr", where c is a character between 'a' and 'h', inclusive, determining the 
column on the board ('a' is the first column, 'h' is the last), and r is a 
digit between '1' and '8', inclusive, determining the row (1 is the lowest, 
8 is the highest).
 
###Definition
    	
*Class:*	CaptureThemAll <br />
*Method:*	fastKnight<br />
*Parameters:*	String, String, String<br />
*Returns:*	int<br />
*Method signature:*	int fastKnight(String knight, String rook, String queen)<br />
(be sure your method is public)<br />
    
 
###Notes
-	A knight's jump moves him 2 cells along one of the axes, and 1 cell along the other one. In other words, if knight is in the (0,0) now, it can be in (-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (1, -2), (-1, 2) or (1, 2) after his move.
-	The knight will capture one of Joe's pieces if it ends its move in the cell that the piece occupies.
-	The knight cannot jump out of the board.
-	A chessboard has 8 rows and 8 columns.
 
###Constraints
-	knight, rook and queen will all be distinct.
-	knight, rook and queen will be formatted as "cr", where c is a lowercase character between 'a' and 'h', inclusive, and r is a digit between '1' and '8', inclusive.
 
###Examples
0)	
    	
> "a1" <br />
> "b3" <br />
> "c5" <br />

Returns: 2 <br />
From "a1", the knight can move directly to "b3" and capture the rook. From there, the knight can move directly to "c5" and capture the queen.

1)	
     	
> "b1" <br />
> "c3" <br />
> "a3" <br />

Returns: 3 <br />
The rook and the queen are both 1 move away from the knight. Once the knight captures one of them (it doesn't matter which one), it can return to its starting location, and capture the other piece in one more move.

2)	
    	
> "a1" <br />
> "a2" <br />
> "b2" <br />

Returns: 6 <br />
The rook and the queen are close, but it takes 6 moves to capture them.

3)	
    	
> "a5" <br />
> "b7" <br />
> "e4" <br />

Returns: 3

4)	
    	
> "h8"<br />
> "e2"<br />
> "d2"<br />

Returns: 6


This problem statement is the exclusive and proprietary property of TopCoder, 
Inc. Any unauthorized use or reproduction of this information without the prior
 written consent of TopCoder, Inc. is strictly prohibited.
 (c)2010, TopCoder, Inc. All rights reserved.

This problem was used for: 
[Single Round Match 207 Round 1 - Division II, Level Three](http://community.topcoder.com/tc?module=ProblemDetail&rd=5853&pm=2915)