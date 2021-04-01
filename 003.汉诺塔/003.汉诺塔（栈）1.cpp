#include <iostream>
#include <stack>               //用到这个库！<stack> 但是我还有好多不懂。
using namespace std;

struct Problem{
    int n;
    char src, mid, dest;
    //Problem(int nn, char srcn, char midn, char destn):nn(n), srcn(src), midn(mid), destn(dest) 
    //Problem(int nn, char srcn, char midn, char destn):n(nn), src(srcn), mid(midn), dest(destn) 
    Problem(int nn, char srcn, char midn, char destn):n(nn), src(srcn), mid(midn), dest(destn) {} //构造函数的用法我已经忘得差不多了！
};

stack<Problem> ta;               //定义在全局？

int main(){
    int n;
    cin>>n;
    ta.emplace(n, 'A', 'B', 'C');     //emplace和push的区别      //x=Problem(n, 'A', 'B', 'C');       //ta.emplace(Problem(n, 'A', 'B', 'C')); 可以     //ta.emplace(n, 'A', 'B', 'C'); 可以
    Problem curPro = ta.top();                                  //ta.emplace(x);   可以               //ta.push(Problem(n, 'A', 'B', 'C'));   可以      //ta.push(n, 'A', 'B', 'C');  ！！！！！不可以
    while( !ta.empty() ){                                       //ta.push(x);      可以
        curPro = ta.top();     //ta.top()最上面的元素
        ta.pop();
        if(curPro.n == 1)
            cout<<curPro.src<<"->"<<curPro.dest<<endl;
        else{
            ta.emplace(curPro.n-1, curPro.mid, curPro.src, curPro.dest);
            ta.emplace(1, curPro.src, curPro.mid, curPro.dest);
            ta.emplace(curPro.n-1, curPro.src, curPro.dest, curPro.mid);
        }
    }
    return 0;
}
