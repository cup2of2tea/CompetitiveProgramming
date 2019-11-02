#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    int nb_lignes,nb_colonnes;
    cin>>nb_lignes>>nb_colonnes;
    vector<string> v(nb_lignes);
    for(int c=0;c<nb_lignes;c++)
    {
        cin>>v[c];
    }
    for(int c=0;c<nb_lignes;c++)
    {
        for(int c2=0;c2<nb_colonnes;c2++)
        {
            if(v[c][c2]=='S')
                goto nop;
        }
        for(int c2=0;c2<nb_colonnes;c2++) v[c][c2]='L';
        nop:;
    }
    for(int c2=0;c2<nb_colonnes;c2++)
    {
        for(int c=0;c<nb_lignes;c++)
        {
            if(v[c][c2]=='S')
                goto nop2;
        }
        for(int c=0;c<nb_lignes;c++) v[c][c2]='L';
        nop2:;
    }
    int res=0;
    for(int c=0;c<v.size();c++) for(int c2=0;c2<v[c].size();c2++) res+=(v[c][c2]=='L'?1:0);
    cout<<res;
}