#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int dp[N];
int n;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[1] = a[1];
    int ans = 0;
    for(int i = 2; i <= n; i ++){
        int Min = a[i];
        for(int j = i; j >= 1; j --){
            Min = min(Min, a[j]);
            dp[i] = max(dp[i], Min * (i - j + 1));
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
