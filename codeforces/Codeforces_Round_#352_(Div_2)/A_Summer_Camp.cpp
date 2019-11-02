#include <iostream>
 
using namespace std;
 
string toString(int a) {
    string res = "";
    while(a != 0) {
        res = string(1,(char)(a%10+'0'))+res;
        a/=10;
        
    }
    return res;
}
 
int main() {
    int n;
    cin>>n;
    n--;
    int a = 1;
    string all = "";
    while(all.size() <= n) {
        all += toString(a);
        a++;
    }
    cout<<all[n];
}