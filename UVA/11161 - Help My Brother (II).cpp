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
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct data
{
    string s, med;
};

data arr[1502];
int indx = 1;

void creat_series(string a, string b);
void calculate_median(void);

int main()
{
    // out;
    arr[0] = "0", arr[1] = "1";
    creat_series(arr[0], arr[1]);
    indx = 1;
    calculate_median();
    int n;
    while(scanf("%d", &n) == 1)
        printf("The Fibonacci number for %d is %s\n", n, arr[n].c_str());
    return 0;
}

void creat_series(string a, string b)
{
    indx++;
    int carry = 0, ac, bc, t;
    string tem;
    for(ac = a.size() - 1, bc = b.size() - 1; bc >= 0; ac--, bc--)
        {
            if(ac < 0)
                t = (b[bc] - '0') + carry;
            else
                t = (a[ac] - '0') + (b[bc] - '0') + carry;
            carry = 0;
            if(t < 10)
                tem += (t + '0');
            else
                {
                    carry = 1;
                    tem += ((t % 10) + '0');
                }
        }
    if(carry)
        tem += '1';
    for(ac = tem.size() - 1; ac >= 0; ac--)
        arr[indx].s += tem[ac];
    if(indx < 5000)
        creat_series(b, arr[indx].s);
    return;
}

void calculate_median(void)
{
    string a = arr[indx].s, b;
    md = (indx - 1) >> 1 + !((indx - 1) & 1);
}
