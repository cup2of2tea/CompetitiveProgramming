#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
 
    long long int N,M;
    cin>>N>>M;
    vector<long long int> v(N), v2(M);
    for(int c=0;c<N;c++) cin>>v[c];
    for(int c=0;c<M;c++) cin>>v2[c];
 
 
    sort(v.begin(),v.end());
    sort(v2.rbegin(),v2.rend());
 
    long long int maxiBoy = (*max_element(v.begin(),v.end()));
    long long int maxiGirl = (*max_element(v2.begin(),v2.end()));
 
    long long int miniBoy = (*min_element(v.begin(),v.end()));
    long long int miniGirl = (*min_element(v2.begin(),v2.end()));
 
    if(maxiBoy > miniGirl) {
        cout<<-1;
        return 0;
    }
 
    map<long long int,bool> isOk;
    map<long long int,long long int> canDo;
 
 
 
    for(int c=0;c<N;c++) {
        canDo[v[c]]+=M-1;
        isOk[v[c]]=true;
    }
 
    long long delta = 0;
 
 
 
    long long res = accumulate(v.begin(),v.end(),0LL)*M;
    map<long long int,long long int>::iterator it = canDo.end();
    it--;
    for(int c=0;c<v2.size();c++) {
 
        if(isOk[v2[c]]) continue;
        if(it->second == 0 && it==canDo.begin()) {
            cout<<-1;
            return 0;
        }
        if(it->second == 0) it--;
        it->second--;
        delta += v2[c]-it->first;
 
    }
    cout<<delta+res;
}