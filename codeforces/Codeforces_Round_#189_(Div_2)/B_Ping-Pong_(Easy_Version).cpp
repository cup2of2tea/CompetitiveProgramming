#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#include <bitset>
 
 
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
 
#define COUT1(s) cout<<"----- "<<s<<" -----"<<endl;
#define COUT2(s,c) cout<<(string(7,c))<<" "<<s<<" "<<(string(7,c))<<endl;
 
#endif
 
using namespace std;
 
 
 
bool between(int a,pair<int,int> &p)
{
    return a>p.first&&a<p.second;
}
 
bool intersect(pair<int,int> &p1,pair<int,int> &p2)
{
    return between(p1.first,p2)||between(p1.second,p2);
}
 
int main(int argc,char **argv)
{
 
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int nb_queries;
    cin>>nb_queries;
    vector<pair<int,int> > intervalles;
    vector<vector<bool> > matrice_adjacence;
    for(int c=0;c<nb_queries;c++)
    {
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1)
        {
            intervalles.push_back(make_pair(a,b));
            matrice_adjacence.push_back(vector<bool>(matrice_adjacence.size()+1,false));
            for(int c2=0;c2<(int)matrice_adjacence.size()-1;c2++)
            {
                matrice_adjacence[c2].push_back(false);
            }
            for(int c2=0;c2<(int)intervalles.size()-1;c2++)
            {
                if(intersect(intervalles[c2],intervalles.back()))
                {
                    matrice_adjacence[c2][(int)intervalles.size()-1]=true;
                }
                if(intersect(intervalles.back(),intervalles[c2]))
                {
                    matrice_adjacence[(int)intervalles.size()-1][c2]=true;
                }
            }
        }
        else
        {
            a--;
            b--;
            vector<int> to_do;
            vector<bool> visites(intervalles.size(),false);
            visites[a]=true;
            to_do.push_back(a);
            while(to_do.size()!=0)
            {
                int act=to_do.back();
                to_do.pop_back();
                if(act==b)
                {
                    cout<<"YES"<<endl;
                    goto end;
                }
                for(int c2=0;c2<matrice_adjacence.size();c2++)
                {
                    if(matrice_adjacence[act][c2]&&!visites[c2])
                    {
                            visites[c2]=true;
                            to_do.push_back(c2);
                    }
                }
            }
            cout<<"NO"<<endl;
        }
        end:;
    }
}