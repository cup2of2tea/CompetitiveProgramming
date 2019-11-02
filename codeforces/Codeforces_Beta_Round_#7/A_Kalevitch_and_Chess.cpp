#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<string> v(8);
    for(int c=0;c<8;c++)
        cin>>v[c];
    int nb_lignes=0,nb_colonnes=0;
    for(int c=0;c<8;c++)
    {
        for(int c2=0;c2<8;c2++)
        {
            if(v[c][c2]!='B')
              {
                  goto end_1;
              }
        }
        nb_lignes++;
        end_1:
        for(int c2=0;c2<8;c2++)
        {
            if(v[c2][c]!='B')
            {
                goto end_2;
            }
        }
        nb_colonnes++;
        end_2:;
    }
    if(nb_lignes==8)
        cout<<8;
    else cout<<nb_lignes+nb_colonnes;
}