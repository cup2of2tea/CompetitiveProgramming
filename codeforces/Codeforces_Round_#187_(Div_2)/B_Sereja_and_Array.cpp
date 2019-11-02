#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
   int n,m;
   cin>>n>>m;
   vector<long long int> v(n);
   for(int c=0;c<n;c++)
     cin>>v[c];
   long long to_add=0;
   for(int c=0;c<m;c++)
   {
       int a;
       cin>>a;
        if(a==1)
        {
            int vi,x;
            cin>>vi>>x;
            vi--;
            v[vi]=x-to_add;
        }
        else if(a==2)
        {
            int vi;
            cin>>vi;
            to_add+=vi;
        }
        else{
            int vi;
            cin>>vi;
            vi--;
            cout<<v[vi]+to_add<<endl;
        }
   }
}