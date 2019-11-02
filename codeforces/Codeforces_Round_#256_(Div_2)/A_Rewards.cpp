#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
 
 
 
int main()
{
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int b1,b2,b3;
    cin>>b1>>b2>>b3;
    int n;
    cin>>n;
    cout<<((a1+a2+a3+4)/5+(b1+b2+b3+9)/10 <= n? "YES":"NO");
}