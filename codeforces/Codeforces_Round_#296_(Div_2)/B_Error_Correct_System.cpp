#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<vector<int> > toSwap(256,vector<int>(256,-1));
    vector<int> disponible(256,-1);
    int taille;
    cin>>taille;
    
    string s1,s2;
    cin>>s1>>s2;
    
    pair<int,int> best = make_pair(-2,-2);
    
    int val = 0;
    int dist = 0;
    for(int c=0;c<s1.size();c++)
    {
        if(s1[c] != s2[c])
        {
            dist++;
            toSwap[s2[c]][s1[c]] = c;
            disponible[s1[c]] = c;
            if(val == 0 && disponible[s2[c]] != -1)
            {
                val = 1;
                best = make_pair(c,disponible[s2[c]]);
            }
            if(toSwap[s1[c]][s2[c]]!=-1)
            {
                val = 2;
                best = make_pair(c,toSwap[s1[c]][s2[c]]);
            }
        }
   }
   for(int c=0;c<s1.size()&&val!=2;c++)
    {
        if(s1[c] != s2[c])
        {
            toSwap[s2[c]][s1[c]] = c;
            disponible[s1[c]] = c;
            if(val == 0 && disponible[s2[c]] != -1)
            {
                val = 1;
                best = make_pair(c,disponible[s2[c]]);
            }
            if(toSwap[s1[c]][s2[c]]!=-1)
            {
                val = 2;
                best = make_pair(c,toSwap[s1[c]][s2[c]]);
            }
        }
   }
   cout<<dist-val<<endl<<1+best.first<<" "<<1+best.second<<endl;
}
    