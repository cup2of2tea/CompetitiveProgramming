#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> res(n,0);
    vector<int> res2(n,0);
    for(int c=0;c<n;c++)
        for(int c2=0;c2<n;c2++)
        {
            int z;
            cin>>z;
            res[c]+=z;
            res2[c2]+=z;
        }
   int tot=0;
   for(int c=0;c<n;c++)
       for(int c2=0;c2<n;c2++)
           if(res2[c2]>res[c])
               tot++;
   cout<<tot;
}