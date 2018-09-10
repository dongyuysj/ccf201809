#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> mp[N];
int vis[N], maxcost[N], maxdis, pos;
void bfs(int x)
{
    vis[x] = 1;
    queue<int> que;
    que.push(x);
    while(que.size()){
        int tmp = que.front();
        que.pop();
        for(int i = 0; i < mp[tmp].size(); i ++){
            int to = mp[tmp][i];
            if(!vis[to]){
                vis[to] = 1;
                maxcost[to] = maxcost[tmp] + 1;
                if(maxcost[to] > maxdis) maxdis = maxcost[to], pos = to;
                que.push(to);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n + m; i ++){
        int x;
        cin >> x;
        mp[x].push_back(i);
        mp[i].push_back(x);
    }
    memset(vis, 0, sizeof(vis));
    memset(maxcost, 0, sizeof(maxcost));
    maxdis = 0;
    bfs(1);
    memset(vis, 0, sizeof(vis));
    memset(maxcost, 0, sizeof(maxcost));
    maxdis = 0;
    bfs(pos);
    printf("%d\n", maxcost[pos]);
    return 0;
}
