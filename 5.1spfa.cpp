//最短路变形，需要维护前一个买的食物的价格
//可以采用spfa算法或者最短路算法
#include<bits/stdc++.h>
using namespace std;
const int N = 25;
const int inf = 0x3f3f3f3f;
int n, m;
int price[N];
struct node
{
    int to, cost;
};
bool vis[N];
int ans;
vector<node> mp[N];
struct node1
{
    int x, cost, ans;
};
int mincost[N];
void bfs(int s, int t)
{
    node1 tmp;
    tmp.x = s, tmp.cost = price[s], tmp.ans = 0;
    queue<node1> que;
    que.push(tmp);
    mincost[s] = 0;
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        int pos = tmp.x;
        int cost = tmp.cost;
        vis[pos] = false;
//        cout << pos << ' ' << cost << endl;
//        system("pause");
        for(int i = 0; i < mp[pos].size(); i ++){
//            cout << "zi" << endl;
            int to = mp[pos][i].to;
            int dis = mp[pos][i].cost;
            int ncost = price[to];
            if(mincost[to] > mincost[pos] + dis) mincost[to] = mincost[pos] + dis;
            if(vis[to]) continue;
            node1 tt;
            tt.x = to, tt.cost = min(cost, ncost);
            tt.ans = tmp.ans + cost * dis;
            que.push(tt);
            vis[to] = true;
            if(to == t) {
                ans = tt.ans;
                return;
            }
//            cout << to << ' ' << ncost << ' ' << min(cost, ncost) << ' ' << dis << endl;
//            cout << ans << endl;
//            system("pause");
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> price[i];
    }
    for(int i = 1; i < n; i ++){
        node tmp;
        int s, t;
        cin >> s >> t >> tmp.cost;
        tmp.to = t;
        mp[s].push_back(tmp);
        tmp.to = s;
        mp[t].push_back(tmp);
    }
    while(m --){
        int s, t;
        cin >> s >> t;
        ans = 0;
        memset(mincost, inf, sizeof(mincost));
        memset(vis, false, sizeof(vis));
        bfs(s, t);
        cout << ans << endl;
    }
    return 0;
}
