#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1005, mod = 1000000007;
ll a[N];
ll dp[N][10];
ll n;
int main()
{
    while(scanf("%lld", &n) != EOF){
        memset(dp, 0, sizeof(dp));
        for(ll i = 1; i <= n; i ++){
                dp[i][1] = 1;
                dp[i][2] = (dp[i - 1][1] + dp[i - 1][2]*2) % mod;
                dp[i][3] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
                dp[i][4] = (dp[i - 1][2] + dp[i - 1][4] * 2) % mod;
                dp[i][5] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] * 2) % mod;
                dp[i][6] = (dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][6] * 2) % mod;
        }
        printf("%lld\n", dp[n][6]);
    }
    return 0;
}

