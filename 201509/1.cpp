#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];
int main()
{
    while(cin >> n){
        int ans = 0;
        a[0] = -1;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            if(a[i] != a[i - 1]) ans ++;
        }
        cout << ans << endl;
    }
}
