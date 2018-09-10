//最短路变形，需要维护前一个买的食物的价格
//可以采用spfa算法或者最短路算法
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 205;
const ll inf = 0x3f3f3f3f;
ll n, m;
ll price[N];
struct node
{
    ll to, cost;
};
bool vis[N];
ll ans;
vector<node> mp[N];
struct node1
{
    ll x, cost, ans;
};
void bfs(ll s, ll t)
{
    node1 tmp;
    tmp.x = s, tmp.cost = price[s], tmp.ans = 0;
    queue<node1> que;
    vis[s] = true;
    que.push(tmp);
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        ll pos = tmp.x;
        ll cost = tmp.cost;
        if(pos == t) {
            ans = tmp.ans;
            return;
        }
        for(ll i = 0; i < mp[pos].size(); i ++){
            ll to = mp[pos][i].to;
            ll dis = mp[pos][i].cost;
            ll ncost = price[to];
            if(vis[to]) continue;
            node1 tt;
            tt.x = to, tt.cost = min(cost, ncost);
            tt.ans = tmp.ans + cost * dis;
            que.push(tt);
            vis[to] = true;
        }
    }
}
int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++){
        cin >> price[i];
    }
    for(ll i = 1; i < n; i ++){
        node tmp;
        ll s, t;
        cin >> s >> t >> tmp.cost;
        tmp.to = t;
        mp[s].push_back(tmp);
        tmp.to = s;
        mp[t].push_back(tmp);
    }
    while(m --){
        ll s, t;
        cin >> s >> t;
        memset(vis, false, sizeof(vis));
        bfs(s, t);
        cout << ans << endl;
    }
    return 0;
}
