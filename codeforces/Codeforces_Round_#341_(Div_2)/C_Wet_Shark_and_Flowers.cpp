#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    long long int n,p;
    cin>>n>>p;
    vector<pair<long long int,long long int> > intervalles(n);
 
    for(int c=0;c<intervalles.size();c++) {
        cin>>intervalles[c].first>>intervalles[c].second;
    }
 
     double res = 0;
 
    for(int c=0;c<n;c++) {
        long long int aOri = intervalles[c].first, bOri = intervalles[c].second;
        long long int cOri = intervalles[(c+1)%n].first, dOri = intervalles[(c+1)%n].second;
 
        long long int aCorrect = (long long)((aOri+p-1)/p)*p;
        long long int bCorrect = ((long long)((bOri)/p))*p;
        long long int cCorrect = (long long)((cOri+p-1)/p)*p;
        long long int dCorrect = ((long long)((dOri)/p))*p;
 
 
        long long lol1 = (bCorrect-aCorrect)/p+1,lol2 = (dCorrect-cCorrect)/p+1;
 
        long long poss = lol1*(dOri-cOri+1-lol2) + lol2*(bOri-aOri+1-lol1) + lol1*lol2;
 
        res += (double)(poss*1000.*2.)/(double)((bOri-aOri+1.)*(dOri-cOri+1.));
 
    }
    cout<<fixed<<setprecision(15)<<res;
 
}