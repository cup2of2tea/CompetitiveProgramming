#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
int main()
{
    int taille;
    cin>>taille;
    vector<int> v(taille);
    vector<int> v2(taille);
    for(int c=0;c<taille;c++)
        cin>>v[c];
    copy(v.begin(),v.end(),v2.begin());
    sort(v2.begin(),v2.end());
    bool already_swapped=false;
    for(int c=0;c<v.size();c++)
    {
        if(v[c]!=v2[c])
        {
            if(already_swapped)
            {
                cout<<"NO";
                return 0;
            }
            for(int c2=c+1;c2<v.size();c2++)
            {
                if(v[c2]!=v2[c2]&&v[c2]==v2[c])
                    swap(v[c],v[c2]);
                already_swapped=true;
            }
        }
    }
    cout<<"YES";
}