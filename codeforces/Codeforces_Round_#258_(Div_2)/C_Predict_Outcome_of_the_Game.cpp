#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
 
 
 
int main()
{
   long long int t;
   cin>>t;
   while(t--)
   {
        long long int n,k,d1,d2;
        cin>>n>>k>>d1>>d2;
        if(n%3!=0)
        {
            cout<<"no"<<endl;
            continue;
        }
        vector<long long int> choice(4);
        choice[0]=k-d1-d2;
        choice[1]=k+d1-d2;
        choice[2]=k-d1+d2;
        choice[3]=k+d1+d2;
        for(int c=0;c<4;c++)
        {
            if(choice[c]%3!=0) continue;
            long long int mid = choice[c]/3;
            long long int gauche,droite;
            if(c < 2)
            {
                droite = mid + d2;
            }
            else
            {
                droite = mid - d2;
            }
            if(c%2==0)
            {
                gauche = mid + d1;
            }
            else gauche = mid - d1;
            if(min(gauche,min(mid,droite)) >=0LL && max(gauche,max(mid,droite)) <= n/3 && gauche+droite+mid == k)
            {
                cout<<"yes"<<endl;
                goto EvilGoto;
            }
        }
        cout<<"no"<<endl;
        EvilGoto:;
   }
}