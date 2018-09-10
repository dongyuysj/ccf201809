#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = (1e5 + 5);
ll n, m;
ll price[N];
struct node
{
    ll to, cost;
};
vector<node> mp[N];
bool vis[N];
ll ans;
bool endflag;
void dfs(ll s, ll t, ll pri)
{
    if(s == t){
        cout << ans << endl;
        endflag = true;
        return;
    }
    vis[s] = true;
    for(ll i = 0; i < mp[s].size() && !endflag; i ++){
        ll to = mp[s][i].to;
        ll cost = mp[s][i].cost;
        if(!vis[to]){
            ans += cost * pri;
            dfs(to, t, min(pri, price[to]));
            ans -= cost * pri;
        }
    }
    vis[s] = false;
}
int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++){
        cin >> price[i];
    }
    for(ll i = 1; i < n; i ++){
        ll s, t,c;
        cin >> s >> t >> c;
        node tmp;
        tmp.to = s, tmp.cost = c, mp[t].push_back(tmp);
        tmp.to = t, mp[s].push_back(tmp);
    }
    while(m --){
        ll s, t;
        memset(vis, false, sizeof(vis));
        cin >> s >> t;
        endflag = false;
        ans = 0;
        dfs(s, t, price[s]);
    }
    return 0;
}
