#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
  int nb_cas;
  cin>>nb_cas;
  while(nb_cas--)
  {
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>  > edges;
    vector<pair<int,int> > degres(n);
    vector<vector<bool> > matrice_adjacence(n,vector<bool>(n,false));
    for(int c=0;c<n;c++) degres[c]=make_pair(0,c);
    sort(degres.begin(),degres.end());
    for(int c=0;c<2*n+p;c++)
    {
      int c2,c3;
      for(c2=0;c2<degres.size();c2++)
         for(c3=0;c3<c2;c3++)
             if(!matrice_adjacence[degres[c2].second][degres[c3].second])
                    goto end;
      end:         
      int from = degres[c3].second;
      int to = degres[c2].second;
      if(from>to) swap(from,to);
      matrice_adjacence[from][to]=matrice_adjacence[to][from]=true;
      edges.push_back(make_pair(from,to));
      degres[0].first++;
      degres[1].first++;
      sort(degres.begin(),degres.end());
    }
    sort(edges.begin(),edges.end());
    for(int c=0;c<edges.size();c++)
      cout<<edges[c].first+1<<" "<<edges[c].second+1<<endl;
  }
}