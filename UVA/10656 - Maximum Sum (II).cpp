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
#define SZ 1010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    int i, n, m;
    while(scanf("%d", &n) == 1 && n)
    {
        bool flag = 1;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &m);
            if(m)
            {
                if(flag)
                    printf("%d", m), flag = 0;
                else
                    printf(" %d", m);
            }
        }
//        if(flag)
//            printf("0");
        printf("\n");
    }
    return 0;
}

