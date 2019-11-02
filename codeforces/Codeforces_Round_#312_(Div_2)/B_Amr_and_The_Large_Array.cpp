#include <bits/stdc++.h>
using namespace std;
 
typedef struct triplet
{
    triplet(){}
    int mini;
    int maxi;
    int compte;
};
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,triplet> m;
    for(int c=0;c<n;c++)
    {
        cin>>a[c];
        if(m.find(a[c])==m.end())
        {
            m[a[c]].mini = c;
            m[a[c]].maxi = c;
            m[a[c]].compte = 1;
        }
        else
        {
            m[a[c]].compte ++;
            m[a[c]].maxi = c;
        }
    }
    int bestCompte = 0;
    int lRes = 1, rRes =n;
    for(map<int,triplet>::iterator it = m.begin(); it != m.end(); it++)
    {
        triplet act = it->second;
        if(bestCompte < act.compte)
        {
            bestCompte = act.compte;
            lRes = act.mini;
            rRes = act.maxi;
        }
        else if(bestCompte == act.compte && act.maxi - act.mini < rRes - lRes)
        {
            lRes = act.mini;
            rRes = act.maxi;
        }
    }
    cout<<lRes+1<<" "<<rRes+1;
 
}