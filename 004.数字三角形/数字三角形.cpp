#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int main(){                                      //1
    int n, d[MAX][MAX];     //记忆空间是最后一行
    int* sumMax;
    cin>>n;
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++)
            cin>>d[i][j];  
    sumMax=d[n];
    for(i=n-1; i>=1; i--) 
        for(j=1; j<=i; j++)
            sumMax[j] = max(sumMax[j], sumMax[j+1])+d[i][j];        
    cout<<sumMax[1]<<endl;
    return 0;
}


int main(){                              //空间未优化的递推法                          //2
    int n, d[MAX][MAX], sumMax[MAX][MAX];     //记忆空间是重新开辟的，大小与原数组一样
    cin>>n;
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++)
            cin>>d[i][j];  
    for(j=1; j<=n; j++)
        sumMax[n][j]=d[n][j];
    for(i=n-1; i>=1; i--) 
        for(j=1; j<=i; j++)
            sumMax[i][j] = max(sumMax[i+1][j], sumMax[i+1][j+1])+d[i][j];        
    cout<<sumMax[1][1]<<endl;
    return 0;
}



int n;                            //递归记忆型                         //3
int d[MAX][MAX];
int sumMax[MAX][MAX];

int maxway(int i, int j){
    if(sumMax[i][j] != -1)               //记录过直接返回
        return sumMax[i][j];
    else if(i == n)
        sumMax[i][j]=d[i][j];
    else
        sumMax[i][j] = max(maxway(i+1, j), maxway(i+1, j+1)) + d[i][j];
    return sumMax[i][j];
}

int main(){
    cin>>n;

    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++){
            cin>>d[i][j];
            sumMax[i][j]=-1;           //初始化
        }
    cout<<maxway(1,1)<<endl;
    return 0;
}
