/*
日期在计算的时候78月均为31天
*/

#include<bits/stdc++.h>
using namespace std;
int month[] = {31,0,31,30,31,30,31,31,30,31,30,31};
int isrun(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 1;
    return 0;
}
int main()
{
    int y, d;
    while(scanf("%d%d", &y, &d) != EOF){
        int f = isrun(y);
        month[1] = f ? 29 : 28;
        int i;
        for(i = 0; i < 12; i ++){
            if(d > month[i]) d -= month[i];
            else break;
        }
//        if(i < 12)
            printf("%d\n%d\n", i + 1, d);
//        else printf("1\n%d\n", d);
    }
    return 0;
}
