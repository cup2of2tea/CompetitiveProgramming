#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
 
int main() {
    int N;
    cin>>N;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
    sort(v.rbegin(),v.rend());
    int gauche = 1, droite = N;
    while(gauche!=droite)
    {
        int mid = (gauche+droite)/2;
        vector<vector<int> > piles(mid);
        for(int c=0;c<mid;c++)
        {
            int i = 0;
            for(int c2=c;c2<N;c2+=mid)
            {
                piles[c].push_back(v[c2]);
            }
        }
        bool valide = true;
        for(int c=0;c<mid;c++)
        {
            for(int c2=0;c2<piles[c].size();c2++)
            {
                if(piles[c][c2] < piles[c].size()-c2-1)
                {
                    valide = false;
                }
            }
        }
        if(valide)
        {
            droite = mid;
        }
        else gauche = mid+1;
    }
    cout<<gauche<<endl;
}