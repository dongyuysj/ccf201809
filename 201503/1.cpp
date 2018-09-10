#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int a[N][N];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = m; j >= 1; j --){
        for(int i = 1; i <= n; i ++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
