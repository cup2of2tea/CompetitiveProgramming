#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> li(m);
    vector<int> ri(m);
    vector<int> ti(m);
    vector<int> ci(m);
    for(int c=0;c<m;c++)
        cin>>li[c]>>ri[c]>>ti[c]>>ci[c];
    int total=0;
    for(int c=1;c<=n;c++)
    {
        int maxi=0;
        int vitesse_maxi=100000000;
        for(int c2=0;c2<m;c2++)
        {
            if(li[c2]>c||ri[c2]<c)
                continue;
            if(ti[c2]<vitesse_maxi)
            {
                  vitesse_maxi=ti[c2];
                  maxi=ci[c2];
            }
        }
        total+=maxi;
    }
    cout<<total;
}