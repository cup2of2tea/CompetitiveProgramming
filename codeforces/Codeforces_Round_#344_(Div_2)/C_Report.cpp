#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    deque<long long> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
 
    vector<pair<int,int> > ops(m);
    for(int c=0;c<m;c++) cin>>ops[c].first>>ops[c].second;
 
    vector<int> maxis(m,-1);
    for(int c=m-1;c>=0;c--){
        maxis[c] = ops[c].second;
        if(c!=m-1) maxis[c] = max(maxis[c],maxis[c+1]);
    }
    int lastOp = -1;
    int prec = -1;
 
    vector<int> res;
 
    for(int c=0;c<m;c++) {
        if(maxis[c] > ops[c].second) continue;
        if(lastOp == -1){
            for(int c2=v.size()-1;c2>=ops[c].second;c2--) res.push_back(v[c2]);
            sort(v.begin(),v.begin()+ops[c].second);
            prec = ops[c].second-1;
            lastOp = ops[c].first;
        } else if(lastOp != ops[c].first) {
            if(prec == ops[c].second-1){
                lastOp = ops[c].first;
                continue;
            }
            int limGauche = ops[c].second;
            int limDroite = prec;
            if(lastOp == 2) {
                for(int c2=0;c2<prec-ops[c].second+1;c2++){ res.push_back(v[0]);v.pop_front();}
            } else {
                for(int c2=limDroite;c2>=limGauche;c2--){ res.push_back(v[c2]); }
            }
            lastOp = ops[c].first;
            prec = ops[c].second-1;
        }
    }
    int limGauche = 0;
    int limDroite = prec;
    if(lastOp == 1) {
        for(int c2=limDroite;c2>=limGauche;c2--){ res.push_back(v[c2]); }
    } else {
        for(int c2=0;c2<=limDroite;c2++){ res.push_back(v[0]);v.pop_front();}
    }
    reverse(res.begin(),res.end());
    for(int c=0;c<res.size();c++) cout<<res[c]<<" ";
 
}
 
 
 