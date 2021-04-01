#include <iostream>
#include <stack>
using namespace std;

struct Problem {
  int n;
  char src,mid,dest;
  Problem( int nn, char s,char m,char d) :n(nn),src(s),mid(m),dest(d) { }
}; //一个Problem变量代表一个子问题，将src上的n个盘子，
 // 以mid为中介，移动到dest

stack<Problem> stk; //用来模拟信封堆的栈，一个元素代表一个信封
                                                                 //若有n个盘子，则栈的高度不超过 n * 3 

int main() {
  int n; cin >> n;
  stk.push(Problem(n,‘A’,‘B’,‘C’)); //初始化了第一个信封
  while( ! stk.empty()) { //只要还有信封，就继续处理
    Problem curPrb = stk.top(); //取最上面的信封，即当前问题
    stk.pop(); // 丢弃最上面的信封
    if( curPrb.n == 1 ) 
      cout << curPrb.src << "->" << curPrb.dest << endl ;
    else { //分解子问题
                                                                         //先把分解得到的第3个子问题放入栈中
      stk.push(Problem(curPrb.n -1,curPrb.mid,curPrb.src,curPrb.dest));
                                                                         //再把第2个子问题放入栈中
      stk.push(Problem(1,curPrb.src,curPrb.mid,curPrb.dest));
                                                                         //最后放第1个子问题，后放入栈的子问题先被处理
      stk.push(Problem(curPrb.n -1,curPrb.src,curPrb.dest,curPrb.mid));
    }
  }
  return 0;
}
