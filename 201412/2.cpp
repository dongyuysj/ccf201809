#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int mp[N][N];
int n;
//1Íù×óÏÂ£¬2ÍùÓÒÉÏ
void zsaomiao(int x, int y, int f)
{
    printf("%d ", mp[x][y]);
    if(x == n && y == n) return;
    if(x == 1 && y < n && f == 2){
        zsaomiao(x, y + 1, 1); return;
    }
    if(x == 1 && f == 1){
        zsaomiao(x + 1, y - 1, 1); return;
    }
    if(y == 1 && x < n && f == 1){
        zsaomiao(x + 1, y, 2);return;
    }
    if(y == 1 && f == 2){
        zsaomiao(x - 1, y + 1, 2); return;
    }
    if(x == n && f == 1){
        zsaomiao(x, y + 1, 2); return;
    }
    if(x == n && f == 2){
        zsaomiao(x - 1, y + 1, 2); return;
    }
    if(y == n && f == 1){
        zsaomiao(x + 1, y - 1, 1); return;
    }
    if(y == n && f == 2){
        zsaomiao(x + 1, y, 1); return;
    }
    if(f == 1){
        zsaomiao(x + 1, y - 1, 1);return;
    }
    if(f == 2){
        zsaomiao(x - 1, y + 1, 2);return;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            scanf("%d", &mp[i][j]);
        }
    }
    zsaomiao(1, 1, 2);
    return 0;
}
