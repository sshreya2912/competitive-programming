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

class EllysSortingTrimmer {
public:
    map <string, string> mpp;

    string call(string S, int L)
    {
        if(mpp.find(S) != mpp.end())
            return mpp[S];
        mpp[S] = S;
//	    if(SZ(S) <= L)
//            return S;
//        cout << S << endl;
		int i;
		string ret = S;
		for(i = 0; i <= SZ(S) - L; i++)
        {
//            cout << i << endl;
            string tem = S;
            tem.erase(i + L);
//            cout << tem << endl;
            sort(tem.begin() + i, tem.end());
//            cout << tem << endl;
            ret = min(ret, call(tem, L));
        }
        mpp[S] = ret;
        return ret;
    }
	string getMin(string S, int L) {
	    return call(S, L);
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
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	EllysSortingTrimmer *obj;
	string answer;
	obj = new EllysSortingTrimmer();
	clock_t startTime = clock();
	answer = obj->getMin(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	string p0;
	int p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "ABRACADABRA";
	p1 = 5;
	p2 = "AAAAA";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "ESPRIT";
	p1 = 3;
	p2 = "EIP";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "BAZINGA";
	p1 = 7;
	p2 = "AABGINZ";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	p1 = 13;
	p2 = "ABCDEFGHIJKLM";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "GOODLUCKANDHAVEFUN";
	p1 = 10;
	p2 = "AACDDEFGHK";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
	p1 = 21;
	p2 = "AAAAAAAAABBDDDDDDDEEI";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = "TOPCODER";
	p1 = 3;
	p2 = "CDT";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = "BA";
	p1 = 2;
	p2 = "AB";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 8 -----
	disabled = false;
	p0 = "BBA";
	p1 = 2;
	p2 = "AB";
	all_right = (disabled || KawigiEdit_RunTest(8, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 9 -----
	disabled = false;
	p0 = "BAA";
	p1 = 2;
	p2 = "AA";
	all_right = (disabled || KawigiEdit_RunTest(9, p0, p1, true, p2) ) && all_right;
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
// Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.
// 
// The device is used in the following way. The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then performs the following changes:
// 
// It leaves the first i characters (i.e., characters with indices 0 through i-1) untouched.
// It rearranges the next L characters (i.e., characters with indices i through i+L-1) into alphabetical order.
// It erases all the remaining characters (i.e., characters with indices i+L and more). Note that for i=length(S)-L no characters are erased.
// 
// The girl can use this "sorting trimmer" as many times as she likes. After each use she is left with the new version of the string.
// 
// In the examples below we use brackets to highlight the region that shall be sorted. For example, "ABRA[CADAB]RA" means that L=5 and Elly chose i=4. The device keeps the letters in front of the brackets, sorts the letters in the brackets, and throws away the rest.
// 
// Here is one way how Elly could have used a device with L = 5, starting with the string S = "ABRACADABRA":
// 
// "ABRAC[ADABR]A" -> "ABRACAABDR"
// "ABR[ACAAB]DR" -> "ABRAAABC"
// "A[BRAAA]BC" -> "AAAABR"
// 
// 
// You are given the string S and the int L. Return the lexicographically smallest string Elly can obtain.
// 
// DEFINITION
// Class:EllysSortingTrimmer
// Method:getMin
// Parameters:string, int
// Returns:string
// Method signature:string getMin(string S, int L)
// 
// 
// NOTES
// -A string A is lexicographically smaller than string B if A contains a smaller character in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.
// 
// 
// CONSTRAINTS
// -S will contain between 2 and 50 characters, inclusive.
// -L will be between 2 and |S|, inclusive, where |S| denotes the number of characters in S.
// -S will consist of uppercase characters of the English alphabet, only ('A'-'Z').
// 
// 
// EXAMPLES
// 
// 0)
// "ABRACADABRA"
// 5
// 
// Returns: "AAAAA"
// 
// Please note that the example in the problem statement does not obtain the lexicographically smallest string. In fact, it is optimal to start by using the device on the last five characters of the string, transforming it from ABRACA[DABRA] to ABRACAAABDR.
// 
// 1)
// "ESPRIT"
// 3
// 
// Returns: "EIP"
// 
// We can obtain the answer in the following steps:
// 
// ES[PRI]T -> ESIPR
// E[SIP]R -> EIPS
// [EIP]S -> EIP
//  
// 
// 2)
// "BAZINGA"
// 7
// 
// Returns: "AABGINZ"
// 
// We can use the sorting trimmer on the entire word.
// 
// 3)
// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// 13
// 
// Returns: "ABCDEFGHIJKLM"
// 
// Even though the string is already sorted, shorter strings are considered lexicographically smaller, so we can use the device once to make the string as short as possible.
// 
// 4)
// "GOODLUCKANDHAVEFUN"
// 10
// 
// Returns: "AACDDEFGHK"
// 
// 
// 
// 5)
// "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
// 21
// 
// Returns: "AAAAAAAAABBDDDDDDDEEI"
// 
// 
// 
// 6)
// "TOPCODER"
// 3
// 
// Returns: "CDT"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
