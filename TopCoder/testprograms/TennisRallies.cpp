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

class TennisRallies {
public:
	int howMany(int numLength, vector <string> forbidden, int allowed) {
		
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	TennisRallies *obj;
	int answer;
	obj = new TennisRallies();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	int p0;
	vector <string> p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 3;
	p1 = {"cc","dd"};
	p2 = 1;
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = {"c"};
	p2 = 1;
	p3 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 10;
	p1 = {"c"};
	p2 = 2;
	p3 = 11;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 18;
	p1 = {"c","d"};
	p2 = 1;
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 18;
	p1 = {};
	p2 = 1;
	p3 = 262144;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 18;
	p1 = {"c","cc","ccc","cccc","ccccc","cccccc","ccccccc","cccccccc","ccccccccc","cccccccccc"};
	p2 = 100;
	p3 = 262122;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
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
// You are practicing your tennis game with a hitting partner.  Each time the ball comes over the net a player can either hit it 
// cross-court, or down-the-line.  In this problem, a sequence of shots will be denoted by a string 
// composed of (quotes for clarity) the letters 'c' and 'd', representing cross-court and down-the-line shots respectively.  For 
// example, "cccddc" would be such a sequence consisting of 3 cross-courts, 2 down-the-lines, and a final cross-court.
// 
// Since you are going to practice a particular play strategy there are certain shot sequences you will avoid.  You are given a 
// vector <string> forbidden containing precisely which sequences must be avoided.  For example, if (quotes for 
// clarity) "ccd" is an element of forbidden then you should never allow 2 cross-court shots followed by a down-the-line 
// shot to occur consecutively at any point in the rally.  If you were a professional, a single forbidden sequence might cause you 
// to stop hitting.  Since you are an amateur, you are willing to let allowed distinct forbidden sequences to occur 
// before you stop.  For example, if allowed was 2, the second forbidden sequence would terminate the hitting sequence.
// 
// You will return the number of distinct hitting sequences of length numLength which contain fewer than 
// allowed forbidden sequences.  Two hitting sequences are distinct if they differ at some stroke in the sequence.  Two 
// forbidden sequences are distinct if they differ in length, or position in the hitting sequence they begin at.  For 
// example, if forbidden = {"cc","cd","ccd"} then the sequence "ccccdd" has 5 distinct forbidden sequences (3 distinct 
// "cc" sequences, a "cd" sequence, and a "ccd" sequence).
// 
// DEFINITION
// Class:TennisRallies
// Method:howMany
// Parameters:int, vector <string>, int
// Returns:int
// Method signature:int howMany(int numLength, vector <string> forbidden, int allowed)
// 
// 
// CONSTRAINTS
// -numLength will be between 1 and 18 inclusive
// -forbidden will contain between 0 and 10 elements inclusive
// -allowed will be between 1 and 100 inclusive
// -forbidden will contain no repeated elements
// -Each element of forbidden will contain between 1 and 18 'c's and 'd's inclusive (quotes for clarity; both are lowercase)
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {"cc","dd"}
// 1
// 
// Returns: 2
// 
// Since allowed is 1, neither "cc" nor "dd" can occur anywhere in a valid sequence.  The only possible sequences are thus "cdc" and "dcd".
// 
// 1)
// 10
// {"c"}
// 1
// 
// Returns: 1
// 
// There is exactly 1 sequence with 10 shots that contains no cross-court shots.
// 
// 2)
// 10
// {"c"}
// 2
// 
// Returns: 11
// 
// There are 11 sequences that contain at most 1 cross-court shot.
// 
// 3)
// 18
// {"c","d"}
// 1
// 
// Returns: 0
// 
// 4)
// 18
// {}
// 1
// 
// Returns: 262144
// 
// 5)
// 18
// {"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
//  "cccccccc","ccccccccc","cccccccccc"}
// 100
// 
// Returns: 262122
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
