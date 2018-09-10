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
vector<node> sum;
double three_devide(double l, double r)
{
    double m1,m2;
    while(r - l >= eps){
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)){
            l = m1;
        }
        else r = m2;
    }
    return (m1 + m2) /2;
}
int main()
{
    string s;
    double p;
    int num;
    vector<node>::iterator it;
    while(cin >> s && s != "1"){
        if(s[0] != 'c'){
            cin >> p >> num;
            node tmp;
            tmp.p = p, tmp.num = num, tmp.name = s;
            sum.push_back(tmp);
        }
        else{
            cin >> num;
            for(it = sum.begin(); it != sum.end(); it ++){
                if(num > 1) num --;
                else break;
            }
            sum.erase(it);
        }
    }
    double Min = 10005, Max = -1;
    for(it = sum.begin(); it != sum.end(); it ++){
        string name = it -> name;
        double p = it -> p;
        int num = it -> num;
        if(name == "buy") buy.insert(pair<double, int>(p, num));
        else if(name == "sell")  sell.insert(pair<double, int>(p, num));
        Min = min(Min, p);
        Max = max(Max, p);
    }
    double ans = three_devide(Min, Max);
    int res1 = 0, res2 = 0;
    map<double, int>::iterator ite;
    for(ite = buy.begin(); ite != buy.end(); ite ++){
        if((ite -> first) >= ans) res1 += (ite -> second);
    }
    for(ite = sell.begin(); ite != sell.end(); ite ++){
        if((ite -> first) <= ans) res2 += (ite -> second);
    }
    cout << ans << ' ' << min(res1, res2);
    return 0;
}
