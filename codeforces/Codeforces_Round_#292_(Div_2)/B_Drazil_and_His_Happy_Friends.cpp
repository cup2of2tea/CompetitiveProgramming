#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <fstream>
using namespace std;
 
int pgcd(int a,int b)
{
    return a==0?b:pgcd(b%a,a);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int N,M;
    cin>>N>>M;
    int h1,h2;
 
    if(true)
    {
        cin>>h1;
        vector<bool> happy1(N,false);
        vector<bool> happy2(M,false);
        vector<pair<int,int> > parcours;
        for(int c=0;c<h1;c++)
        {
            int z;
            cin>>z;
            parcours.push_back(make_pair(z,0));
            happy1[z]=true;
        }
        cin>>h2;
        for(int c=0;c<h2;c++)
        {
            int z;
            cin>>z;
            parcours.push_back(make_pair(z,1));
            happy2[z]=true;
        }
        while(parcours.size())
        {
 
            int bla = parcours.back().second;
            int truc = parcours.back().first;
            parcours.pop_back();
            int act = truc;
            if(bla==0)
            {
                if(!happy2[act%M])
                {
                    happy2[act%M]=true;
                    parcours.push_back(make_pair(act%M,1));
                }
                act+=N;
                while(act%M!=truc%M)
                {
                    if(!happy2[act%M])
                    {
                        happy2[act%M]=true;
                        parcours.push_back(make_pair(act%M,1));
                    }
                    act+=N;
                }
            }
            else
            {
                if(!happy1[act%N])
                {
                    happy1[act%N]=true;
                    parcours.push_back(make_pair(act%N,0));
                }
                act+=M;
                while(act%N!=truc%N)
                {
                    if(!happy1[act%N])
                    {
                        happy1[act%N]=true;
                        parcours.push_back(make_pair(act%N,1));
                    }
                    act+=M;
                }
            }
        }
        for(int c=0;c<N;c++)
        {
            if(!happy1[c])
            {
                cout<<"No";
                return 0;
            }
        }
        for(int c=0;c<M;c++)
        {
            if(!happy2[c])
            {
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }
}