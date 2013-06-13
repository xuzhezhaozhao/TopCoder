##TopCoder: [RevolvingDoors](http://community.topcoder.com/stat?c=problem_statement&pm=3064&rd=5869)

###Problem Statement
You are in a maze containing revolving doors. The doors can be turned 90 
degrees by pushing against them in either direction. You are to find a route
 from the start square to the end square that involves revolving as few doors
 as possible. Given a map of the maze, determine the fewest number of door 
 revolutions necessary to get from the start to the end.

In the map:
-   ' ': empty space
-   '#': wall
-   'O': center of a revolving door (letter "oh", not zero)
-   '-': horizontal door (always adjacent to a 'O')
-   '|': vertical door (always adjacent to a 'O')
-   'S': start square
-   'E': end square

Each revolving door will always be oriented horizontally (with two horizontal 
segments) or vertically (with two vertical segments):

>    | <br />
>    O  or  -O- <br />
>    | <br />

Doors can be revolved 90 degrees by moving onto a door segment from any of the 4 
squares diagonally adjacent to the door center, i.e., the 'X' characters below:

>   X|X     X X <br />
>    O  or  -O- <br />
>   X|X     X X <br />

Here is an example map:

	"     ###"
	"    #E# "
	"   ## # "
	"####  ##" 
	"# S -O-#"
	"# ###  #" 
	"#      #" 
	"########" 

In this example, 2 door revolutions are necessary to get from 'S' to 'E'. The 
first turn is shown here:

	"    ### "    "     ###" 
	"    #E# "    "    #E# " 
	"   ## # "    "  ## #  " 
	"####  ##"    "#### |##" 
	"# S -O-#"    "# S  OX#" 
	"# ### X#"    "# ###| #" 
	"#      #"    "#      #" 
	"########"    "########" 

And the second turn is shown here:

	"    ### "   "    ### " 
	"    #E# "   "    #E# " 
	"   ## # "   "   ## # " 
	"####X|##"   "#### X##"  
	"# S  O #"   "# S -O-#" 
	"# ###| #"   "# ###  #" 
	"#      #"   "#      #" 
	"########"   "########" 

Your method should return an int, the minimum number of door revolutions necessary
 to get from the start square to the end square. If there is no way to reach the 
 end square, return -1.

 
###Definition
    
Class:	RevolvingDoors <br />
Method:	turns <br />
Parameters:	String[] <br />
Returns:	int <br />
Method signature:	int turns(String[] map) <br />
(be sure your method is public) <br />
    
 
###Notes
-	Assume that all squares off the edge of the map are walls.
 
###Constraints
-	map will contain between 3 and 50 elements, inclusive.
-	Each element of map will contain between 3 and 50 characters, inclusive.
-	Each element of map will contain the same number of characters.
-	Each character in map will be one of 'S', 'E', 'O', '-', '|', '#', and ' ' (space).
-	There will be exactly one 'S' and one 'E' in map.
-	There will be between 1 and 10 doors, inclusive, and they will be formatted in map as described in the problem statement.
-	No two doors will be close enough for any part of them to occupy the same square.
-	It is not allowed for a door to be blocked and unable to turn. There will not be any walls in any of the 4 squares immediately adjacent to the center of a door, nor will a door be on the edge of the map.
 
###Examples

0)	
    	
	"    ### ",
	"    #E# ", 
	"   ## # ", 
	"####  ##", 
	"# S -O-#", 
	"# ###  #", 
	"#      #", 
	"########"
  
Returns: 2 <br />
This is the example from the problem statement.

1)	
    	
	"#### ",  
	"#S|##", 
	"# O #", 
	"##|E#", 
	" ####"

Returns: -1 <br />
There is no way to reach the end square.

2)	
    	
	" |  |  |     |  |  |  |  |  | ", 
	" O  O EO -O- O  O  O  O  OS O ", 
	" |  |  |     |  |  |  |  |  | "

Returns: 7 <br />
The optimal path involves turning the 3rd door twice, and the 5th, 6th, 7th, 8th, and 9th doors once each (counting from the left). Note that the 'S' and 'E' do not block doors, and in fact you must turn the 3rd door twice to end up on the 'E'.

3)	
    	
	"###########", 
	"#    #    #", 
	"#  S | E  #", 
	"#    O    #", 
	"#    |    #", 
	"#         #", 
	"###########" 

Returns: 0 <br />

4)	
    	
	"        E", 
	"    |    ", 
	"    O    ", 
	"    |    ", 
	" -O-S-O- ", 
	"    |    ", 
	"    O    ", 
	"    |    ", 
	"         " 

Returns: -1 <br />
You are stuck, unable to move or turn any doors from this position.

5)	
    	
	"##E#   ", 
	"#  ##  ", 
	" -O-## ", 
	" #  ## ", 
	" ##  ##", 
	"  -O-  ", 
	"##  ## ", 
	" # ### ", 
	" #  S  " 

Returns: 5 <br />

6)	
    	
	"#############", 
	"#  #|##|#   #", 
	"#   O  O    #", 
	"# E || || S #", 
	"#    O  O   #", 
	"#   #|##|#  #", 
	"#############" 

Returns: 4 <br />

After all the doors have been turned, the map looks like this:

	"#############" 
	"#  # ## #   #" 
	"#  -O--O-   #"	
	"# E       S #"	
	"#   -O--O-  #" 
	"#   # ## #  #" 
	"#############" 

This problem statement is the exclusive and proprietary property of TopCoder, 
Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.


This problem was used for: 
       [Single Round Match 223 Round 1 - Division I, Level Three](http://community.topcoder.com/tc?module=ProblemDetail&rd=5869&pm=3064)