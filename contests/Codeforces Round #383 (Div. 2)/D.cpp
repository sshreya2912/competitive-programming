#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("control.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1LL << 58)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dp[MAX][MAX], par[MAX], n, B[MAX], W[MAX], nex[MAX], totB[MAX], totW[MAX];
vector <pair<int,int>> arr;

int root(int v)
{
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}
void merge(int x,int y) 	//	x and y are some tools (vertices)
{
    x = root(x), y = root(y);
    if(par[y] < par[x])	// balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

LL call(int indx, int baki)
{
	if(baki < 0) return -infinity;
	if(indx == n) return 0;
	LL &ret = dp[indx][baki];
	if(ret != -1) return ret;
	ret = call(nex[indx], baki-totW[arr[indx].first])+totB[arr[indx].first];
	ret = max(ret, call(nex[indx], baki-W[arr[indx].second])+B[arr[indx].second]);
	ret = max(ret, call(indx+1, baki));
	return ret;
}

int main()
{
	clr(par, -1);
	int m, i, w, x, y;
	cin >> n >> m >> w;
	for(i = 1; i <= n; i++)
		cin >> W[i];
	for(i = 1; i <= n; i++)
		cin >> B[i];
	while(m--)
	{
		cin >> x >> y;
		if(root(x) != root(y))
			merge(x, y);
	}
	for(i = 1; i <= n; i++)
		arr.pb(mp(root(i), i));
	sort(all(arr));
	nex[n-1] = n;
	for(i = n-2; i >= 0; i--)
	{
		if(arr[i].first == arr[i+1].first)
			nex[i] = nex[i+1];
		else
			nex[i] = i+1;
	}
	for(i = 1; i <= n; i++)
	{
		totB[root(i)] += B[i];
		totW[root(i)] += W[i];
	}
	clr(dp, -1);
	cout << call(0, w);
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 
















