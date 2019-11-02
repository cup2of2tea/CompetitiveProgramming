#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef struct score
{
    score(){}
    int penalties;
    int nb;
}score;
 
bool comp(const score &s1,const score &s2)
{
    return s1.nb>s2.nb||(s1.nb==s2.nb&&s1.penalties<s2.penalties);
}
 
int main()
{
    int n,k;
    cin>>n>>k;
    vector<score> v(n);
    for(int c=0;c<n;c++){
        cin>>v[c].nb>>v[c].penalties; }
    sort(v.begin(),v.end(),comp);
    int res=0;
    for(int c=0;c<v.size();c++)
        if(v[c].nb==v[k-1].nb&&v[c].penalties==v[k-1].penalties) res++;
    cout<<res<<endl;
}