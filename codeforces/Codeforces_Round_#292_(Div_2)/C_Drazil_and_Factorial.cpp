#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <fstream>
using namespace std;
 
string decompo(string act,vector<int> &fac,int i,int n)
{
    if(n==1)
    {
        return act;
    }
    string res = "";
    for(int c=i;c<fac.size();c++)
    {
        if(n%fac[c]==0)
        {
            string tmp = decompo(act+(char)('0'+c),fac,c,n/fac[c]);
            if(tmp.size() > res.size() || (tmp.size() == res.size() && tmp > res))
                res = tmp;
        }
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res="";
    vector<string> corres(10,"");
    int act = 1;
    vector<int> fac(10,1);
    for(int c=2;c<=9;c++)
    {
        fac[c]=fac[c-1]*c;
    }
    for(int c=2;c<=9;c++)
        corres[c]=decompo("",fac,2,fac[c]);
    for(int c=0;c<s.size();c++)
    {
 
        res+=corres[s[c]-'0'];
    }
    sort(res.rbegin(),res.rend());
    cout<<res;
}