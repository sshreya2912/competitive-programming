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
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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

struct point{int x, y;};    // for coordinates;

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

#define MAX 55
/*************************************************HABIJABI ENDS HERE******************************************************/

int n, m;
point arr[MAX];
double ager[MAX][MAX], notun[MAX][MAX];
struct info
{
    double dist;
    int i, j;
}ans;

void init()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            ager[i][j] = infinity;
        ager[i][i] = 0;
    }
}

void get(void)
{
    int i, j, k, l;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                ager[i][j] = min(ager[i][j], ager[i][k] + ager[k][j]);
    double sum;
    for(k = 1; k <= n; k++)
        for(l = k + 1; l <= n; l++)
        {
            if(ager[k][l] <= getdist(arr[k], arr[l])) continue;
            sum = 0;
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    notun[i][j] = min(ager[i][j], getdist(arr[k], arr[l]) + ager[i][k] + ager[l][j]);
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    sum += ager[i][j] - notun[i][j];
            if(sum - 1.0 > eps)
            {
                if(sum > ans.dist)
                    ans.dist = sum, ans.i = k, ans.j = l;
                else if(abs(sum - ans.dist) < eps)
                {
                    if(k < ans.i)
                        ans.i = k, ans.j = l;
                    else if(k == ans.i && l < ans.j)
                        ans.i = k, ans.j = l;
                }
            }
        }
}

int main()
{
    int i, a, b;
    while(scanf("%d %d", &n, &m) == 2 && (n | m))
    {
        ans.dist = 0, ans.i = ans.j = infinity;
        init();
        for(i = 1; i <= n; i++)
            scanf("%d %d", &arr[i].x, &arr[i].y);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            ager[a][b] = ager[b][a] = getdist(arr[a], arr[b]);
        }
        get();
        if(abs(ans.dist - 0.0) < eps)
        {
            puts("No road required");
            continue;
        }
        printf("%d %d\n", ans.i, ans.j);
    }
    return 0;
}


