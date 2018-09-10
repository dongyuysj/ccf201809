#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
struct node
{
    int val, pos;
}a[N];
bool cmp(node x, node y)
{
    if(x.val > y.val) return true;
    if(x.val == y.val) return x.pos < y.pos;
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < N; i ++){
        a[i].val = 0;
        a[i].pos = i;
    }
    for(int i = 1; i <= n; i ++){
        int k;
        scanf("%d", &k);
        a[k].val ++;
    }
    sort(a, a + N, cmp);
    for(int i = 0; i < n && a[i].val; i ++){
        printf("%d %d\n", a[i].pos, a[i].val);
    }
    return 0;
}
