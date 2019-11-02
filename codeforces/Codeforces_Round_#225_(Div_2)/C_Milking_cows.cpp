#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
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
    int nb_zero = 0;
    int nb_one = 0;
    int n;
    cin>>n;
    int gauche = -1,droite = -1; // gauche 1 droite 0
    vector<int> v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        if(v[c]==1)
        {
            nb_one++;
            if(gauche == -1) gauche = c;
        }
        else
        {
            nb_zero++;
            droite = c;
        }
    }
    long long res = 0;
    int nb_one_gauche = 0;
    int nb_zero_droite = 0;
    for(int c=0;c<n;c++)
    {
        if(c>gauche&&v[c]==0) nb_zero_droite++;
        else if(c<droite&&v[c]==1) nb_one_gauche++;
    }
    vector<bool> visites(n,false);
    while((nb_zero || nb_one) &&(gauche < droite))
    {
        if(nb_one &&(!nb_zero || nb_zero_droite < nb_one_gauche))
        {
            visites[gauche]=true;
            res+= nb_zero_droite;
            gauche++;
            while(gauche <n && v[gauche] != 1) {nb_zero_droite--;gauche++;}
            nb_one--;
        }
        else
        {
            visites[droite]=true;
            res+= nb_one_gauche;
            droite--;
            while(droite >=0  && v[droite] != 0) {nb_one_gauche--;droite--;}
            nb_zero--;
        }
    }
    cout<<res;
}