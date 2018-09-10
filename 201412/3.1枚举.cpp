//三分(此类问题的一般求解方法，但是此题可以不使用三分，因为题目中要求的是输出最大的开盘价，则只需要枚举所有的报价计科)
#include<bits/stdc++.h>
using namespace std;
const double eps = 0.01;
map<double, int> buy, sell;
typedef struct node
{
    string name;
    double p;
    int num;
};
vector<node> sum;
int cancle[1005], cnum = 0;
int f(double x)
{
    int res1 = 0, res2 = 0;
    map<double, int>::iterator ite;
    for(ite = buy.begin(); ite != buy.end(); ite ++){
        if((ite -> first) >= x) res1 += (ite -> second);
    }
    for(ite = sell.begin(); ite != sell.end(); ite ++){
        if((ite -> first) <= x) res2 += (ite -> second);
    }
    return min(res1, res2);
}
bool cmp(int x, int y)
{
    return x < y;
}
int main()
{
    string s;
    double p;
    int num;
    vector<node>::iterator it;
    while(cin >> s){
        if(s[0] != 'c'){
            cin >> p >> num;
            node tmp;
            tmp.p = p, tmp.num = num, tmp.name = s;
            sum.push_back(tmp);
        }
        else if(s[0] == 'c'){
            cin >> num;
            cancle[++cnum] = num;
        }
        else break;
    }
    sort(cancle + 1, cancle + 1 + cnum, cmp);
    for(int i = 1; i <= cnum; i ++){
        num = cancle[i];
        for(it = sum.begin(); it != sum.end(); it ++){
            if(num > 1) num --;
            else break;
        }
        sum.erase(it);
        for(int j = i + 1; j <= cnum; j ++){
            cancle[j] --;
        }
    }
    for(it = sum.begin(); it != sum.end(); it ++){
        string name = it -> name;
        double p = it -> p;
        int num = it -> num;
        if(name == "buy") buy.insert(pair<double, int>(p, num));
        else if(name == "sell")  sell.insert(pair<double, int>(p, num));
    }
    int ans = -1, res, tp = 0;
    double prep = -1;
    for(it = sum.begin(); it != sum.end(); it ++){
        double p = it -> p;
        int tmp = f(p);
        if(tmp > ans) ans = tmp, res = tp, prep = p;
        if(tmp == ans && p > prep) res = tp, prep = p;
        tp ++;
    }
    printf("%.2lf %d\n", sum[res].p, ans);
    return 0;
}

