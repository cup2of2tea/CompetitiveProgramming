#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int racine(vector<int> &peres,int n)
{
    if(n!=peres[n]) peres[n] = racine(peres,peres[n]);
    return peres[n];
}
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
//#define cin in
//    ifstream in("input.txt");
    int n,m;
    cin>>n>>m;
    vector<int> pere(n);
    for(int c=0;c<n;c++) pere[c]=c;
    for(int c=0;c<m;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        int r1 = racine(pere,a);
        int r2 = racine(pere,b);
        if(r1!=r2)
        {
            pere[r1]=r2;
        }
    }
    long long sol = pow(2,n);
    for(int c=0;c<n;c++) if(pere[c]==c) sol/=2;
    cout<<sol;
}