#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int num[N];
int ans[N];
int main()
{
    int n;
    scanf("%d", &n);
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        num[a[i]] ++;
        ans[i] = num[a[i]];
        printf("%d ", ans[i]);
    }
    return 0;
}
