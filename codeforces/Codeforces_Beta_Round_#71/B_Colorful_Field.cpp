#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
string tableau[3]={"Carrots","Kiwis","Grapes"};
 
int main()
{
    int nb_lignes,nb_colonnes;
    cin>>nb_lignes>>nb_colonnes;
    int nb_waste;
    cin>>nb_waste;
    vector <int> waste;
    int nb_demandes;
    cin>>nb_demandes;
    for(int c=0;c<nb_waste;c++)
    {
        int i,j;
        cin>>i>>j;
        i--;
        j--;
        waste.push_back(i*nb_colonnes+j);
    }sort(waste.begin(),waste.end());
    for(int c=0;c<nb_demandes;c++)
    {
        int i,j;
        cin>>i>>j;
        i--;
        j--;
        int nb=0;
        for(int c2=0;c2<waste.size();c2++)
        {
            if(waste[c2]==i*nb_colonnes+j)
            {
                cout<<"Waste"<<endl;
                goto end;
            }
            if(waste[c2]>i*nb_colonnes+j)
                break;
            nb++;
        }
        cout<<tableau[(i*nb_colonnes+j-nb)%3]<<endl;;
        end:;
    }
}