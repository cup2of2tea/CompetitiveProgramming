#include <iostream>
 
using namespace std;
 
int main() {
    int N;
    cin>>N;
    int one = 0, two = 0;
    for(int c=0;c<N;c++) {
        int a,b;
        cin>>a>>b;
        one += (a>b);
        two += (b>a);
    }
    cout<<(one == two?"Friendship is magic!^^": (one > two?"Mishka": "Chris") );
}