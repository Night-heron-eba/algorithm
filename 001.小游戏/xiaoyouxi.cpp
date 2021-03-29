#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory.h>
using namespace std;
#define MAXIN 75

char board[MAXIN+2][MAXIN+2];//定义矩形板，算他最大!!!!时char ‘ ’或‘X’
int minstep, w, h, to[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};//定义方向 东 南西北
bool mark[MAXIN+2][MAXIN+2];//定义标记数组

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f){
    if(step > minstep) return;
    if(now_x == end_x && now_y == end_y){
        if(minstep > step)
            minstep = step;
        return;
    }
    for(int i = 0; i < 4; i++){
        int x = now_x + to[i][0];
        int y = now_y + to[i][1];
        if((x > -1) && (x < w+2) && (y > -1) && (y < h+1) && (((board[y][x] == ' ') && (mark[y][x] == false)) || ((x == end_x) && (y == end_y) && (board[y][x] == 'X')))){
            mark[y][x] == true;         //未到终点或未超过最小线段前都是true
            if(f == i) Search(x, y, end_x, end_y, step, i);
            else Search(x, y, end_x, end_y, step+1, i);
            mark[y][x] == false;       //一次子搜索结束会回溯回false
        }
    }
}

int main(){
    int Boardnum = 0;
    while(scanf("%d %d", &w, &h)){      //读入矩形板的数据
        if(w ==0 && h == 0) break;      //如果 0 0结束
        Boardnum ++;
        printf("Board#%d", Boardnum);
        
        int i, j;
        //for(i = 0; i < w+2; i++) board[0][i] = board[h+1][i] = ' ';
        for(i = 0; i < MAXIN+2; i++) board[0][i] = board[i][0] = ' ';
        for(i = 1; i < h+1; i++){
            getchar();
            for(j = 1; j < w+1; j++)
                //getchar();          //getchar空格和换行符都读，输入完一行要打空格，上面还有scanf！
                board[i][j] = getchar();
        }
        //for(i = 1; i < h+1; i++) board[i][0] = board[i][w+1] = ' ';
        for(i = 1; i <= w+1; i++)
            board[h+1][i] = ' ';
        for(i = 1; i <= h+1; i++)
            board[w+1][i] = ' ';

        int begin_x, begin_y, end_x, end_y, count = 0;
        while(scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y) && begin_x > 0){
            count++;
            minstep = 100000;                         //
            memset(mark, false, sizeof(mark));
            Search(begin_x, begin_y, end_x, end_y, 0, -1); //?
            if(minstep < 100000) printf("Pair %d: %d segements.\n", count, minstep);
            else printf("Pair %d: Impossible.\n", count);
        }
        printf("\n");
    }
    return 0;
}
