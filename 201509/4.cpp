//求解强连同分量，取反后后序求出来
#include<bits/stdc++.h>
using namespace std;
const int N = 10005, M = 100005;
int n, m;
vector<int> mp[N], mp1[N];
stack<int> sta;
bool vis[N];
void dfs(int s)
{
    for(int i = 0; i < mp1[s].size(); i ++){
        int to = mp1[s][i];
        if(!vis[to]){
            vis[to] = true;
            dfs(to);
        }
    }
    sta.push(s);
}
int dfs1(int x)//注意此计算个数的方法函数的求解
{
    int res = 0;
    for(int i = 0; i < mp[x].size(); i ++){
        int to = mp[x][i];
        if(!vis[to]){
            vis[to] = 1;
            res ++;
            res += dfs1(to);
        }
    }
    return res;
}
int cal(int x)
{
    return x * (x - 1) / 2;
}
int main()
{
    cin >> n >> m;
    while(m --){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp1[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    memset(vis, false, sizeof(vis));
    int ans = 0;
    while(!sta.empty()){
        int tmp = sta.top();
        sta.pop();
        vis[tmp] = true;
        int res = dfs1(tmp);
        ans += cal(res + 1);
    }
    cout << ans << endl;
    return 0;
}
