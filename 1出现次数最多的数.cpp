#include<bits/stdc++.h>
#define inf 10001
using namespace std;
int num[10005];
int a[1005];
int main()
{
    int n;
    scanf("%d", &n);
    int ans = -1;
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        num[a[i]] ++;
    }

    for(int i = 1; i <= n; i ++){
        int k = a[i];
        if( ans == -1 || num[k] > num[ans] || (num[k] == num[ans] && k < ans)) ans = k;
    }
    printf("%d\n", ans);
}
