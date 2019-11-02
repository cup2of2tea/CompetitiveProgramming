#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
        int taille,k;
    cin>>taille>>k;
        vector<int> v(taille);
    for(int c=0;c<taille;c++) cin>>v[c];
    for(int c=k;c<taille;c++)
    {
        if(v[c]!=v[k-1])
        {
            cout<<-1;
            return 0;
        }
    }
    for(int c=k-2;c>=0;c--)
        if(v[c]!=v[k-1])
        {
            cout<<c+1;
            return 0;
        }
    cout<<0;
}