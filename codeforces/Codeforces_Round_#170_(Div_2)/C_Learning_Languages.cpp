#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
 
void unir(int a,int b,vector<int> &racines)
{
    if(racines[a]==racines[b])
        return;
    int temp=racines[a];
    for(int c=0;c<racines.size();c++)
        if(racines[c]==temp)
            racines[c]=racines[b];
}
 
int main()
{
    int N,M;
    cin>>N>>M;
    int res=0;
    vector<int> racines(N);
    vector<vector<string> > langages(N);
    for(int c=0;c<N;c++)
    {
        int nb;
        cin>>nb;
        langages[c].resize(nb);
        racines[c]=c;
        if(nb==0) res++;
        for(int c2=0;c2<nb;c2++)
        {
            cin>>langages[c][c2];
        }
    }
    for(int c=0;c<N;c++)
    {
        for(int c2=c+1;c2<N;c2++)
        {
            for(int c3=0;c3<langages[c].size();c3++)
                for(int c4=0;c4<langages[c2].size();c4++)
                {
                    if(langages[c][c3]==langages[c2][c4])
                    {
                        unir(c,c2,racines);
                        goto end;
                    }
                }
            end:;
        }
    }
    set<int> s;
    for(int c=0;c<racines.size();c++)
    {
        if(langages[c].size()!=0)
            s.insert(racines[c]);
    }
    cout<<max(0,(int)s.size()-1)+res;
}