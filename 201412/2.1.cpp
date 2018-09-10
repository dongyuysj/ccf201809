#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int mp[N][N];
int n;
//1Íù×óÏÂ£¬2ÍùÓÒÉÏ
void zsaomiao(int x, int y, int f)
{
    while(x < n || y < n){
        printf("%d ", mp[x][y]);
        if(x == 1 && y < n && f == 2){
            y ++; f = 1;continue;
        }
        if(x == 1 && f == 1){
            x ++, y --, f = 1; continue;
        }
        if(y == 1 && x < n && f == 1){
            x ++, f = 2; continue;
        }
        if(y == 1 && f == 2){
            x --, y ++, f = 2; continue;
        }
        if(x == n && f == 1){
            y ++, f = 2; continue;
        }
        if(x == n && f == 2){
            x --, y ++, f = 2; continue;
        }
        if(y == n && f == 1){
            x ++, y --, f = 1; continue;
        }
        if(y == n && f == 2){
            x ++, f = 1; continue;
        }
        if(f == 1){
            x ++, y --, f = 1;continue;
        }
        if(f == 2){
            x --, y ++, f = 2;continue;
        }
    }
    printf("%d\n", mp[n][n]);
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
