#include <bits/stdc++.h>
using namespace std;
 
bool ok(int n,int k, int a, vector<int> &ori, int test)
{
    vector<int> v;
    for(int c=0;c<test;c++) v.push_back(ori[c]);
    v.push_back(0);
    v.push_back(n+1);
    sort(v.begin(),v.end());
    int poss = 0;
    for(int c=1;c<v.size();c++)
    {
        poss +=(((v[c]-1)-(v[c-1]+1))+2)/(a+1);
    }
    return poss >= k;
}
 
 
int main()
{
    int n,k,a;
    cin>>n>>k>>a;
    int m;
    cin>>m;
    vector<int> v(m);
    for(int c=0;c<m;c++)
    {
        cin>>v[c];
    }
    int gauche = 0, droite = m;
    if(ok(n,k,a,v,droite)){
        cout<<-1;
        return 0;
    }
    while(gauche != droite){
        int mid = (gauche+droite)/2;
        if(ok(n,k,a,v,mid)) {
            gauche = mid+1;
        } else {
            droite = mid;
        }
    }
    cout<<gauche;
}