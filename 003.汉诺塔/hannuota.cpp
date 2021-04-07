#include <iostream>
//#include <stack>
using namespace std;

void Hanoi(int n, char a, char b, char c){
    if(n==1){
        cout<<a<<"->"<<c<<endl;
        return;
    }
    Hanoi(n-1, a, c, b);
    cout<<a<<"->"<<c<<endl;
    Hanoi(n-1, b, a, c);
    return;

}

int main(){
    int n;
    cin>>n;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
//不会做不可怕，想不出不是我的错，愚蠢也不是我的错，
//不努力思考，害怕困难，害怕挫折，害怕失败才是错误！
