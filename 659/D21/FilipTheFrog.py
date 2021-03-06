import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class FilipTheFrog:
    def countReachableIslands(self, positions, L):
        cur = positions[0]
        positions = sorted(positions)
        cur = positions.index(cur)
        res = 1
        for i in range(cur - 1, -1, -1):
            if positions[i + 1] - positions[i] <= L:
                res += 1
            else:
                break

        for i in range(cur + 1, len(positions)):
            if positions[i] - positions[i-1] <= L:
                res += 1
            else:
                break

        return res

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, p1, hasAnswer, p2):
	obj = FilipTheFrog()
	startTime = time.clock()
	answer = obj.countReachableIslands(p0, p1)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		res = answer == p2
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		print(str("\t") + str(p2))
		sys.stdout.write(str("received: "))
		print(str("\t") + str(answer))
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
p0 = (4,7,1,3,5)
p1 = 1
p2 = 3
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = (100,101,103,105,107)
p1 = 2
p2 = 5
all_right = (disabled or KawigiEdit_RunTest(1, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = (17,10,22,14,6,1,2,3)
p1 = 4
p2 = 7
all_right = (disabled or KawigiEdit_RunTest(2, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = (0,)
p1 = 1000
p2 = 1
all_right = (disabled or KawigiEdit_RunTest(3, p0, p1, True, p2) ) and all_right
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
