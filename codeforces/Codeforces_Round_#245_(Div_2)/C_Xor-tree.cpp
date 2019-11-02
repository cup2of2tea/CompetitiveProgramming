#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
using namespace std;
 
int main()
{
 
    int n;
    cin>>n;
    vector<vector<int>  > liste_adjacence(n);
    
    for(int c=0;c<n-1;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        liste_adjacence[a].push_back(b);
        liste_adjacence[b].push_back(a);
    }
    
    vector<int> ori(n);
    vector<int> but(n);
    for(int c=0;c<n;c++) cin>>ori[c];
    for(int c=0;c<n;c++) cin>>but[c];
    
    
    vector<bool> visites(n,false);
    visites[0]=true;
    
    vector<pair<int,int> > parcours;
    parcours.push_back(make_pair(0,0));
    
    vector<int> res;
    
    while(parcours.size())
    {
        int nbSwaps = parcours.back().second;
        int noeud = parcours.back().first;
        parcours.pop_back();
        
        int swap = 0;
        
        if((ori[noeud]+(nbSwaps%2))%2 != but[noeud])
        {
            swap = 1;
            res.push_back(noeud+1);
        }
        
        for(int c=0;c<liste_adjacence[noeud].size();c++)
        {
            int n2 = liste_adjacence[noeud][c];
            if(!visites[n2])
            {
                visites[n2]=true;
 
                parcours.push_back(make_pair(n2,((((nbSwaps&1)+swap)%2)<<1)+((nbSwaps&2)>>1)));
            }
        }
    }
    
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    copy(res.begin(),res.end(),ostream_iterator<int>(cout,"\n"));
}