#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
#define W 1
#define Y 0

int n;
int puzzle[16][17], press[16][17];
int searchsteps(){
    int r, c, steps=0;
    for(r = 1; r < n; r++){
        for(c = 1; c < n+1; c++){
            press[r+1][c] = (puzzle[r][c] + press[r][c] + press[r-1][c] + press[r][c-1] + press[r][c+1]) % 2;
            if(press[r+1][c] == 1)
                steps++;
        }

    }
    for(c = 1; c < n+1; c++){     //！=前面要加括号。
        if((press[n][c]+press[n][c-1]+press[n][c+1]+press[n-1][c])%2 != puzzle[n][c])
            return -1;               //无法熄灭
    }
    for(c=1; c<n+1; c++)
            if(press[1][c] == 1)
                steps++;
    return steps;
}

int searchmin(){               //简化模型: 通过局部确定整体，只枚举局部就可以了！
    int c, min=4000, steps=0;                      //把第一行看作一个二进制数递增
    for(c = 1; c < n+1; c++)
        press[1][c] = 0;
    c = 0;
    while(c <= n){                   //！！当变成1000000（n个0）时，c=n+1
        steps = searchsteps();
        if(steps < min && steps != -1)
            min = steps;
        press[1][1]++;
        c = 1;
        while(press[1][c] > 1){ //二进制数递增的算法
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }

    }
    return min;
}



int main()
{
    int i, c, r, cases, minsteps;
    char color;
    scanf("%d", &cases);
    scanf("%d", &n);
    //scanf(" %c", &color);
    //printf("%c\n", color);
    for(c = 1; c < n+1; c++)
        puzzle[0][c] = 0;
    for(r = 0; r < n+1; r++)
        puzzle[r][0] = puzzle[r][n+1] = 0;
    for(i = 1; i <= cases; i++){
        for (r = 1; r < n+1; r++){
            for(c = 1; c < n+1; c++){
            scanf(" %c", &color);             //字符输入前面要加个空格，？？
            if(color == 'Y')
                puzzle[r][c] = 0;

            if(color == 'W')
                puzzle[r][c] = 1;
            //printf("%d", puzzle[r][c]);
            //scanf("%d", &puzzle[r][c]);
            }
        }
        minsteps = searchmin();
        printf("PUZZLE#%d最少需要%d步。\n", i, minsteps);
    }
    return 0;
}
