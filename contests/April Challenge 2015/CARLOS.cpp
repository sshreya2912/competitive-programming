#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1LL << 40)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 205
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL dist[MAX][MAX], arr[200005];
LL test, n, m;

LL curbest[MAX], prebest[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL i, j, k, x, y;
    cin >> test;
    while(test--)
    {
        cin >> m >> k >> n;
        clr(dist, 31);
        while(k--)
        {
            cin >> x >> y;
            dist[x][y] = dist[y][x] = 1;
        }
        for(i = 1; i <= m; i++)
            dist[i][i] = 0;
        for(k = 1; k <= m; k++)
            for(i = 1; i <= m; i++)
                for(j = 1; j <= m; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        clr(curbest, 31);
        clr(prebest, 31);
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        for(i = 1; i <= m; i++)
            if(dist[arr[1]][i] < dist[203][203])
                prebest[i] = (i != arr[1]);
        for(i = 2; i <= n; i++)
        {
            LL curmin = curbest[203];
            for(j = 1; j <= m; j++)
            {
                curmin = min(curmin, prebest[j]);
                if(dist[arr[i]][j] < dist[203][203])
                    curbest[j] = curmin + (j != arr[i]);
                else
                    curbest[j] = curbest[203];
            }
            memcpy(prebest, curbest, sizeof curbest);
        }
        LL res = *min_element(prebest + 1, prebest + m + 1);
        if(res >= prebest[203])
            res = -1;
        cout << res << "\n";
    }
    return 0;
}

