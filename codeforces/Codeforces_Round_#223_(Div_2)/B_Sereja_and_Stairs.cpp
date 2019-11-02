#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int m;
    cin>>m;
    vector<int> visites(50000,0);
    vector<int> one,two;
    for(int c=0;c<m;c++)
    {
       int z;
       cin>>z;
       if(visites[z]==2) continue;
       if(visites[z]==1) two.push_back(z);
       else one.push_back(z);
       visites[z]++;
   }
   sort(one.begin(),one.end());
   sort(two.rbegin(),two.rend());
   int t = one.size()+two.size();
   if(two.size()>0&&two[0]==one.back()) t--;
   cout<<t<<endl; 
   for(int c=0;c<one.size();c++) cout<<one[c]<<" ";
   for(int c=0;c<two.size();c++) if(c==0&&two[0]==one.back()) continue; else cout<<two[c]<<" ";
}