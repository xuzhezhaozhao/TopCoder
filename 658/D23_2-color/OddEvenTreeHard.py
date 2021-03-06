import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class OddEvenTreeHard:

    def dfs(self, v, color):
        if self.vetexColor[v] == -1:
            self.vetexColor[v] = color
            for x in self.gdif[v]:
                self.dfs(x, color ^ 1)
            for x in self.geq[v]:
                self.dfs(x, color)
        elif self.vetexColor[v] != color:
            self.wrongGraph = True
            

    def getTree(self, x):
        N = len(x)
        self.gdif = [ [] for i in range(N) ]
        self.geq = [ [] for i in range(N) ]
        self.vetexColor = [-1 for i in range(N)]

        for i in range(N):
            for j in range(N):
                if x[i][j] == 'O':
                    self.gdif[i].append(j)
                    self.gdif[j].append(i)
                elif x[i][j] == 'E':
                    self.geq[i].append(j)
                    self.geq[j].append(i)

        self.wrongGraph = False
        for i in range(N):
            if self.vetexColor[i] == -1:
                self.dfs(i, (0 if i == 0 else 1))

        if self.wrongGraph:
            return (-1,)

        colored = [ [] for i in range(2) ]
        for i in range(N):
            colored[ self.vetexColor[i] ].append(i)

        if len(colored[0]) == 0 or len(colored[1]) == 0:
            return (-1,)

        root = colored[0][0]
        odd = colored[1][0]

        res = (root, odd)
        for i in range(1, len(colored[1])):
            res += (root, colored[1][i])

        for i in range(1, len(colored[0])):
            res += (odd, colored[0][i])
            

        return res

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, hasAnswer, p1):
	obj = OddEvenTreeHard()
	startTime = time.clock()
	answer = obj.getTree(p0)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		if (len(answer) != len(p1)):
			res = False
		else:
			for i in range(len(answer)):
				if (answer[i] != p1[i]):
					res = False
				
			
		
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		sys.stdout.write(str("\t") + str("{"))
		for i in range(len(p1)):
			if (i > 0):
				sys.stdout.write(str(","))
			
			sys.stdout.write(str(p1[i]))
		
		print(str("}"))
		sys.stdout.write(str("received: "))
		sys.stdout.write(str("\t") + str("{"))
		for i in range(len(answer)):
			if (i > 0):
				sys.stdout.write(str(","))
			
			sys.stdout.write(str(answer[i]))
		
		print(str("}"))
		print(str(""))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		sys.stdout.write(str("passed.      "))
		sys.stdout.write(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
		print(str(""))
	else:
		print(str("OK, but is it right?"))
	
	return res

all_right = True
tests_disabled = False


# ----- test 0 -----
disabled = False
p0 = ("EOE","OEO","EOE")
p1 = (0,1,2,1)
all_right = (disabled or KawigiEdit_RunTest(0, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = ("????","????","????","????")
p1 = (0,1,0,3,2,1)
all_right = (disabled or KawigiEdit_RunTest(1, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = ("????","????","??O?","????")
p1 = (-1,)
all_right = (disabled or KawigiEdit_RunTest(2, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = ("??O?","????","E???","????")
p1 = (-1,)
all_right = (disabled or KawigiEdit_RunTest(3, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = ("?O??","??O?","???O","????")
p1 = (0,1,0,3,2,1)
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 5 -----
disabled = False
p0 = ("?E??","??E?","???E","????")
p1 = (-1,)
all_right = (disabled or KawigiEdit_RunTest(5, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 6 -----
disabled = False
p0 = ("?????????????","??????????OE?","?????????????","?????????????","?????????????","?????????????","?????????????","???????E?????","???????E?????","?????????????","???????????O?","???????????E?","????????????E")
p1 = (0,1,0,3,0,5,0,7,0,8,0,11,0,12,2,1,4,1,6,1,9,1,10,1)
all_right = (disabled or KawigiEdit_RunTest(6, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	print(str(""))
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!
