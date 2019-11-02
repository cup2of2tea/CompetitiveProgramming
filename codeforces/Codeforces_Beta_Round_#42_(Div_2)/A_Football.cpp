#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int nb;
    cin>>nb;
    vector <string> v;
    v.resize(nb);
    for(int c=0;c<nb;c++)
        cin>>v[c];
    sort(v.begin(),v.end());
    int max=-1;
    string maxi;
    int current=0;
    for(int c=0;c<v.size();c++)
    {    
        if(c>0&&v[c-1]==v[c])
            current++;
        else
        {
            if(c>0)
            {
                if(max<current)
                {
                    max=current;
                    maxi=v[c-1];
                }
            }
            current=1;
        }
    }
    if(max<current)
        maxi=v[v.size()-1];
    cout<<maxi;
}