#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <queue>
#include <iomanip>
#include <map>
#define DEBUG2
 
using namespace std;
 
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> tot(n,0);
    vector<int> valeurs(n);
    vector<vector<int> > liste_adjacence(n);
 
    for(int c=0;c<n;c++)
    {
        cin>>valeurs[c];
    }
    for(int c=0;c<m;c++)
    {
        int one,two;
        cin>>one>>two;
 
        one--;
        two--;
 
        liste_adjacence[one].push_back(two);
        liste_adjacence[two].push_back(one);
        tot[one]+=valeurs[two];
        tot[two]+=valeurs[one];
    }
 
    int res = 0;
    for(int c=0;c<n;c++)
    {
        int i = 0;
        for(int c2=0;c2<n;c2++)
        {
            if(valeurs[i] < valeurs[c2]) i = c2;
        }
 
        res+=tot[i];
 
        for(int c2=0;c2<n;c2++)
        {
            for(int c3=0;c3<liste_adjacence[c2].size();c3++)
            {
                if(liste_adjacence[c2][c3] == i)
                {
                    tot[c2] -= valeurs[i];
                }
            }
        }
        valeurs[i] = -1;
    }
    cout<<res<<endl;
}