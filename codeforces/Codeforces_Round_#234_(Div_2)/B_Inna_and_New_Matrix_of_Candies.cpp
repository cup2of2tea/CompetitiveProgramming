#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int nb_lignes,nb_colonnes;
    cin>>nb_lignes>>nb_colonnes;
    vector<string> v(nb_lignes);
    for(int c=0;c<nb_lignes;c++)
    {
        cin>>v[c];
    }
    vector<int> dwarfs(nb_lignes),candys(nb_lignes);
    for(int c=0;c<nb_lignes;c++)
    {
        for(int c2=0;c2<nb_colonnes;c2++)
        {
            if(v[c][c2]=='G') dwarfs[c]=c2;
            else if(v[c][c2]=='S') candys[c]=c2;
        }
    }
    for(int c=0;c<nb_lignes;c++)
    {
        if(dwarfs[c]>candys[c]) {cout<<-1;return 0;}
    }
    set<int> ecarts;
    for(int c=0;c<nb_lignes;c++) ecarts.insert(candys[c]-dwarfs[c]);
    cout<<ecarts.size()<<endl;
}