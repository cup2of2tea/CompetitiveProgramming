#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
 
 
 
int main()
{
    int tab[5]={0};
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        tab[z]++;
    }
    int nb_cars=tab[4];
    while(tab[3])
    {
        tab[3]--;
        if(tab[1])
            tab[1]--;
        nb_cars++;
    }
    while(tab[2])
    {
        tab[2]--;
        if(tab[2])
            tab[2]--;
        else if(tab[1])
        {
            tab[1]=max(0,tab[1]-2);
        }
        nb_cars++;
    }
    nb_cars+=(tab[1]+3)/4;
    cout<<nb_cars;
}