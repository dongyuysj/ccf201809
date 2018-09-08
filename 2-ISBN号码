#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    string s1 = s.substr(0, len - 1);
    char shibie = s[len - 1];
    int sum = 0, k = 1;
    for(int i = 0; i < len - 2; i ++){
        if(s[i] != '-'){
            sum += (s[i] - '0') * k ++;
        }
    }
    cout << sum << endl;
    sum %= 11;
    char ans = (sum == 10) ? 'X' : (sum + '0');
    cout << ((shibie == ans) ? "Right" : s1 + ans) << endl;
    return 0;
}
