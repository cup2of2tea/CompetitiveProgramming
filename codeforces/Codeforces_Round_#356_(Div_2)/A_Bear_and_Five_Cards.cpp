#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
   map<int,int> m;
   int res = 0;
   for(int c=0;c<5;c++) {
        int z;
        cin>>z;
        m[z]++;
        res+=z;
   }
   int resounet = res;
   for(map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
    if(it->second >= 2) {
        resounet = min(resounet,res - min(3,it->second)*(it->first));
    }
   }
   cout<<resounet;
}