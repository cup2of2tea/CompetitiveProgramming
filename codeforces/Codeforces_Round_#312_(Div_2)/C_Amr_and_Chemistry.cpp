#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
#ifndef ONLINE_JUDGE
    //#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++)
    {
        cin>>v[c];
    }
    vector<bool> seen(1e5+1,false);
    int lim = (*max_element(v.begin(),v.end()));
    vector<int> parcours(1,(*min_element(v.begin(),v.end())));
    long long res = 1e15;
 
    vector<int> thePowers(N,0);
    for(int c=0;c<v.size();c++)
    {
        int copie = v[c];
        while(copie)
        {
            copie/=2;
            thePowers[c]++;
        }
        thePowers[c]--;
    }
 
    while(parcours.size())
    {
        int act = parcours.back();
        int myPower = 0;
        int copie = act;
        while(copie)
        {
            copie/=2;
            myPower++;
        }
        myPower--;
        parcours.pop_back();
        if(act==0) continue;
        long long int cost = 0;
        for(int c=0;c<N;c++)
        {
            int bla = v[c];
            int otherPower = thePowers[c];
            while(bla != act)
            {
                if(bla > act)
                {
                    bla/=2;
                    otherPower --;
                    cost++;
                }
                else if(act & ((bla*(1<<(myPower-otherPower)) ^ act)))
                {
                    goto nop;
                }
                else if(bla*(1<<(myPower-otherPower)) != act)
                {
                    bla/=2;
                    otherPower --;
                    cost++;
                }
                else
                {
                    cost += myPower-otherPower;
                    break;
                }
            }
        }
        res = min(res,cost);
        nop:
 
        if(!seen[act/2])
        {
            parcours.push_back(act/2);
            seen[act/2]=true;
        }
        if(act*2 <= lim && !seen[act*2])
        {
            parcours.push_back(act*2);
            seen[act*2]=true;
        }
    }
    cout<<res;
}