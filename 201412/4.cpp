//最小生成树问题
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1005, M = 100005;
int n, m;
int head[N];
int mp[N][N];
int mincost[N];
int vis[M];
int ans = 0;
void prim()
{
    mincost[1] = 0;
    while(1){
        int v = -1;
        for(int i = 1; i <= n; i ++){
            if(!vis[i] && (v == -1 || mincost[v] > mincost[i]))  v = i;
        }
        if(v == -1) break;
        ans += mincost[v];
        vis[v] = 1;
        for(int i = 1; i <= n; i ++){
            if(mincost[i] > mp[i][v] && !vis[i]) mincost[i] = mp[i][v];
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        memset(vis, 0, sizeof(vis));
        memset(mp, inf, sizeof(mp));
        memset(mincost, inf, sizeof(mincost));
        for(int i = 1; i <= m; i ++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mp[a][b] = c, mp[b][a] = c;
        }
        prim();
        printf("%d\n", ans);
    }
}
