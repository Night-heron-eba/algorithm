#include <iostream>
#include<iomanip> //要用到格式控制符
#include<cmath>
#include<memory.h>
using namespace std;

int s[9][9]; //每个格子的分数
int sum[9][9]; //(1,1)到(i,j)的矩形的分数之和
int res[15][9][9][9][9]; //fun的记录表

int calsum(int x1, int y1, int x2, int y2){        ////(x1,y1)到(x2,y2)的矩形的分数之和
    return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}

int fun(int n, int x1, int y1, int x2, int y2){
    int t;
    if(res[n][x1][y1][x2][y2] != -1)
        return res[n][x1][y1][x2][y2];
    if(n == 1) {                              //!
        t = calsum(x1, y1, x2, y2);
        res[n][x1][y1][x2][y2] = t*t;
        return t*t;
    }
    int MIN = 100000000, i, c, e, s;
    for(i = x1; i <= x2-1; i++){
        c = fun(1, x1, y1, i, y2);                 //可以直接用fun函数而不是用calsum函数
        e = fun(1, i+1, y1, x2, y2);
        s = min(fun(n-1, x1, y1, i, y2)+e, fun(n-1, i+1, y1, x2, y2)+c);  //min函数
        if(MIN > s)
            MIN = s;
    }
    for(i = y1; i <= y2-1; i++){
        c = fun(1, x1, y1, x2, i);
        e = fun(1, x1, i+1, x2, y2);
        s = min(fun(n-1, x1, y1, x2, i)+e, fun(n-1, x1, i+1, x2, y2)+c);
        if(MIN > s)
            MIN = s;
    }
    res[n][x1][y1][x2][y2] = MIN;
    return MIN;
}

int main(){
    memset(res, -1, sizeof(res));//初始化数组   FF
    memset(sum, 0, sizeof(sum));// 00
    int n, i, j, rowsum;
    cin>>n;
    for(i = 1; i < 9; i++)
        for(j = 1, rowsum = 0; j < 9; j++){
            cin>>s[i][j];
            rowsum += s[i][j];             //从s[1][1]到s[i][j]的矩形上的数字之和
            sum[i][j] = sum [i-1][j] + rowsum;   //i-1当i= 1时sum[1][j]=sum[0][j]+rowsum
        }
    for(i = 1; i < 9; i++){
        for(j = 1; j < 9; j++){
            cout<<sum[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<fun(n, 1, 1, 8, 8)<<endl;
    double result = n * fun(n, 1, 1, 8, 8) - sum[8][8]*sum[8][8];//double result = n * fun(n, 1, 1, 9, 9) - sum[8][8]*sum[8][8];不是9
    cout<<result<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl;//n*n要加括号
    return 0;

}

/*
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
*/

