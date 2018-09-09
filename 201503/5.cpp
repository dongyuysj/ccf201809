#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
char mp[N][N];
int vis[N][N];
bool able[N][N][N][N];
struct node
{
    int x, y;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool hefa(int x, int y, int i, int f, int px, int py)
{
    if(!f){
        if(x >= 1 && x <= n && y >= 1 && y <= m){
            if(mp[x][y] == '#') return false;
            if(mp[px][py] == '+' || mp[px][py] == 'T' || mp[px][py] == 'S') return true;
            if(mp[px][py] == '|' && (i == 2 || i == 3)) return true;
            if(mp[px][py] == '-' && (i == 0 || i == 1)) return true;
            if(mp[px][py] == '.' && i == 2) return true;
            return false;
        }
        return false;
    }
    else{
        if(x >= 1 && x <= n && y >= 1 && y <= n){
            return true;
        }
        return false;
    }
}
void bfs(int x, int y, int f)
{
    if(!f){
        vis[x][y] = 1;
        queue<node> que;
        node tmp;
        tmp.x = x;
        tmp.y = y;
        que.push(tmp);
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            for(int i = 0; i < 4; i ++){
                int xx = tmp.x + dx[i];
                int yy = tmp.y + dy[i];
                if(hefa(xx, yy, i, f, tmp.x, tmp.y)){
                    if(!vis[xx][yy]){
                        vis[xx][yy] = 1;
                        able[tmp.x][tmp.y][xx][yy] = true;
                        node tmp1;//注意必须新定义一个变量才可改变其值后加入到队列中去
                        tmp1.x = xx;
                        tmp1.y = yy;
                        que.push(tmp1);
                    }
                    else{

                        able[tmp.x][tmp.y][xx][yy] = true;
                    }
                }
            }
        }
    }
    else{
        vis[x][y] = 2;
        queue<node> que;
        node tmp;
        tmp.x = x;
        tmp.y = y;
        que.push(tmp);
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            for(int i = 0; i < 4; i ++){
                int xx = tmp.x + dx[i];
                int yy = tmp.y + dy[i];
                if(hefa(xx, yy, i, f, tmp.x, tmp.y) && vis[xx][yy] != 2 && able[xx][yy][tmp.x][tmp.y]){
                    vis[xx][yy] = 2;
                    node tmp1;
                    tmp1.x = xx;
                    tmp1.y = yy;
                    que.push(tmp1);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int sx, sy, tx, ty;
    for(int i = 1; i <= n; i ++){
        scanf("%s", mp[i] + 1);
        for(int j = 1; j <= m; j ++){
            if(mp[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(mp[i][j] == 'T'){
                tx = i;
                ty = j;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    memset(able, false, sizeof(able));
    bfs(sx, sy, 0);
    if(!vis[tx][ty]){
        printf("I'm stuck!\n");
        return 0;
    }
    bfs(tx, ty, 1);
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(vis[i][j] == 1) ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
