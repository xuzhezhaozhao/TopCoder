#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/
const int MAX_N = 31;
int g[MAX_N][MAX_N];
class TwoLLogo {
public:
        int M, N;
        int count(int x1, int y1, int x2, int y2)
        {
                int res = 0;
                if (x1 == x2 && y1 == y2) {     // 两点相同
                        return 0;
                }
                if (x1 > x2) {
                       swap(x1, x2);
                       swap(y1, y2);
                }
                // x1 <= x2
                if (y1 > y2) {
                        
                } else if (y1 == y2) {
                        
                } else if (y1 < y2) {
                        
                }
        }
    long long countWays(vector <string> grid) {
        long long res = 0;
        this->N = grid.size();
        this->M = grid[0].size();
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                       if ('.' == grid[i][j]) {
                                g[i][j] = 1; 
                       } else {
                                g[i][j] = 0;
                       }
                }
        }
        
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        if (!g[i][j]) {
                             continue;   
                        }
                        for (int p = 0; p < N; p++) {
                               for (int q = 0; q < M; q++) {
                                       if (!g[p][q]) {
                                               continue;
                                       }
                                       res += count(j, i, q, p);
                               } 
                        }
                }
        }
        
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string gridARRAY[] = {"....",
            "...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(0, theObject.countWays(grid),1LL);
    }
    {
        string gridARRAY[] = {".##..",
            "...#.",
            ".#.#.",
            "#...#"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(1, theObject.countWays(grid),3LL);
    }
    {
        string gridARRAY[] = {"..#.",
            "#.#.",
            "....",
            "..#."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(2, theObject.countWays(grid),4LL);
    }
    {
        string gridARRAY[] = {"..",
            ".."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(3, theObject.countWays(grid),0LL);
    }
    {
        string gridARRAY[] = {".#.#",
            "....",
            ".#.#",
            "...."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(4, theObject.countWays(grid),34LL);
    }
    {
        string gridARRAY[] = {"##############",
            "##############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.############",
            "#.#####.######",
            "#.#####.######",
            "#.#####.######",
            "#....##.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######.######",
            "#######......#",
            "##############"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(5, theObject.countWays(grid),1350LL);
    }
    {
        string gridARRAY[] = {"#......",
            ".#....#",
            ".#.#...",
            "#....#.",
            ".##..#.",
            ".#.....",
            ".....#.",
            ".#.#...",
            ".#...#.",
            "..##..."};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(6, theObject.countWays(grid),2386LL);
    }
    {
        string gridARRAY[] = {"...#..........................",
            "..............................",
            "..............................",
            "..................#...#.......",
            "..................#...........",
            "..............................",
            "...........#..................",
            "..............................",
            ".....#..#.....................",
            ".......................#......",
            "..................#.....#.....",
            "..............................",
            "..............................",
            "..............................",
            "..............................",
            "..#...........................",
            "..............................",
            "..............................",
            "..............................",
            "#............................#",
            "..............................",
            ".....#.........#............#.",
            "..............................",
            ".........................#....",
            ".#............................",
            ".............#................",
            "..............................",
            "..............................",
            ".......................#......",
            ".............#................"};
        vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
        TwoLLogo theObject;
        eq(7, theObject.countWays(grid),5020791386LL);
    }
	return 0;
}
// END CUT HERE
