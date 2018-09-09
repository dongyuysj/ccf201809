# ccf201809
截至到201809的素有ccf题解
## 201303
##### 1-	出现次数最多的数
n较小，直接遍历所有的数据
##### 2-ISBN号码
模拟 <br>
对每个数据处理后加入并且更新结果
##### 3-最大的矩形
首先想到的是暴力的算法o(n2)，数据范围是1000 <br>
另一种做法：单调栈o(n) <br>
每次只需要把每个位置处的数据向两端延伸，找到以当前数据为最小值的最左端的数据和最右端的数据 <br>
单调栈维护的每个数据往左第一个小于当前数据的位置，对于每个数据来说只要top>当前数据，直接入栈，否则取出所有不满足单调性的数据更新ans <br>
对于每个不满足单调性的数据来说，栈顶的下一个元素是她往左的第一个小于她的数据，当前i是栈顶往右的时候第一个小于她的数据，因此可以求得以栈顶为最小值的 <br>
子序列的最小值
##### 4-有趣的数
数位dp <br>
和其他的数位dp不同的是，此题不要求数据的上限，只要求数据的位数，因此可以直接采用for循环 <br>
共有6中情况： <br>
1:只出现过2 <br>
2:只出现过2,0 <br>
3:只出现过2,3 <br>
4:只出现过2,0,1 <br>
5:只出现过2,0,3 <br>
6:只出现过0,1,2,3 <br>
##### 5-I’m stuck!
正向遍历与反向遍历！
最开始看到题目想到的是用两次bfs，从起点开始进行一次bfs，再从终点开始进行一次bfs，但是后来发现不可以，因为从终点可以到一个点，但是不一定在起点经过这个点时候还是可以到达终点，比如样例中的那个情况<br>
因此，用到了一个able[x1][y1][x2][y2]数组，表示从(x1,y1)->(x2,y2)可达，第一次普通的bfs找到起点可达的点且的到able数组<br>
第二次遍历的时候从终点开始，四周的点根据able数组确定下一个点去哪里
