#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
        int taille;
        cin>>taille;
        vector<int> v(taille+1);
        for(int c=0;c<taille;c++)
        {
                int z;
                cin>>z;
                v[z]=c;
        }
        long long int res1=0,res2=0;
        int nb_requetes;
        cin>>nb_requetes;
        for(int c=0;c<nb_requetes;c++)
        {
                int z;
                cin>>z;
                res1+=v[z]+1;
                res2+=taille-v[z];
        }
        cout<<res1<<" "<<res2;
} 
 