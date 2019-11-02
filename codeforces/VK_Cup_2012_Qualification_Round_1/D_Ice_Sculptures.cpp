#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++)
        cin>>v[c];
    int maxi=-100000000;
    for(int c=1;c<=n;c++)
    {
        if(n%c!=0)
            continue;
        for(int c2=0;c2<c;c2++)
        {
            int res=0;
            int nb_sommet=0;
            for(int c3=c2;c3<n;c3+=c){nb_sommet++;
                res+=v[c3];}
            if(nb_sommet<3)
                break;
            maxi=max(maxi,res);
        }
    }
    cout<<maxi;
}