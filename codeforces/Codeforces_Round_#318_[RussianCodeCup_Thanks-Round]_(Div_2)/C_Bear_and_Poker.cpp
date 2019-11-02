#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    int dep ;
    cin>>dep;
    while(dep%2==0) dep/=2;
    while(dep%3==0) dep/=3;
    for(int c=1;c<N;c++) {
        int z;
        cin>>z;
        while(z%2==0) z/=2;
        while(z%3==0) z/=3;
        if(z!=dep) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}