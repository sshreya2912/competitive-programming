#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

class LightedPanels {
public:

    int dp[8][1 << 8][1 << 8], n, arr[9], m;

    int call(int row, int parent, int current)
    {
        if(row == n)
            return parent == (1 << m) - 1? 0 : infinity;
        int &ret = dp[row][parent][current];
        if(ret != -1) return ret;
        ret = infinity;
        int new_parent, new_current, i, j, next_current;
        for(i = 0; i < (1 << m); i++)
        {
            new_current = current;
            new_parent = parent;
            next_current = arr[row + 1];
            for(j = 0; j < m; j++)
            {
                if(!(i & (1 << j))) continue;
                new_current ^= (1 << j);
                new_parent ^= (1 << j);
                next_current ^= (1 << j);
                if(j > 0)
                {
                    new_current ^= (1 << (j - 1));
                    new_parent ^= (1 << (j - 1));
                    next_current ^= (1 << (j - 1));
                }
                if(j < m - 1)
                {
                    new_current ^= (1 << (j + 1));
                    new_parent ^= (1 << (j + 1));
                    next_current ^= (1 << (j + 1));
                }
            }
            if(row == 0 || new_parent == (1 << m) - 1)
                ret = min(ret, call(row + 1, new_current, next_current) + no_of_ones(i));
        }
        return ret;
    }

	int minTouch(vector <string> board) {
        clr(dp, -1);
        int i, j;
        for(i = 0; i < SZ(board); i++)
        {
            arr[i] = 0;
            for(j = 0; j < SZ(board[i]); j++)
                if(board[i][j] == '*')
                    arr[i] |= (1 << j);
        }
        n = SZ(board);
        m = SZ(board[0]);
        return call(0, (1 << m) - 1, arr[0]) >= infinity ? -1 : call(0, (1 << m) - 1, arr[0]);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	LightedPanels *obj;
	int answer;
	obj = new LightedPanels();
	clock_t startTime = clock();
	answer = obj->minTouch(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;

	vector <string> p0;
	int p1;

	// ----- test 0 -----
	disabled = false;
	p0 = {"*****","*...*","*...*","*...*","*****"};
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 1 -----
	disabled = false;
	p0 = {".*"};
	p1 = -1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 2 -----
	disabled = false;
	p0 = {"*.*.*","*.*.*","....."};
	p1 = 5;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	// ----- test 3 -----
	disabled = false;
	p0 = {"*...","**..","..**","...*"};
	p1 = 10;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
//
// You are given a rectangular board consisting of several light panels.  Character j of element i of board represents the panel in row i, column j. '*' means the panel is on, and '.' means it's off.  When you touch a panel, its state will be toggled.  In other words, if you touch a panel that's on, it will turn off, and if you touch a panel that's off, it will turn on.  Because the panels are so sensitive, when you touch a panel, all of its horizontally, vertically, and diagonally adjacent panels will also toggle their states.
//
//
// Your goal is to have all the light panels in the board be on at the same time.  Return the minimum number of touches required to achieve this goal, or return -1 if it is impossible.
//
//
// DEFINITION
// Class:LightedPanels
// Method:minTouch
// Parameters:vector <string>
// Returns:int
// Method signature:int minTouch(vector <string> board)
//
//
// CONSTRAINTS
// -board will contain between 1 and 8 elements, inclusive.
// -Each element of board will contain between 1 and 8 characters, inclusive.
// -Each element of board will contain the same number of characters.
// -board will contain only the characters '*' and '.'.
//
//
// EXAMPLES
//
// 0)
// {"*****",
//  "*...*",
//  "*...*",
//  "*...*",
//  "*****"}
//
// Returns: 1
//
// Just touch the panel in the center of the board.
//
// 1)
// {".*"}
//
// Returns: -1
//
// Here touching any panel makes both panels toggle its state. So it's impossible to light both panels at the same time.
//
// 2)
// {"**.",
//  "**.",
//  "..."}
//
// Returns: 2
//
// First touch the panel in row 0, column 0 to turn all the panels off, and then touch the panel in row 1, column 1.
//
// 3)
// {"*...",
//  "**..",
//  "..**",
//  "...*"}
//
// Returns: 10
//
//
//
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
