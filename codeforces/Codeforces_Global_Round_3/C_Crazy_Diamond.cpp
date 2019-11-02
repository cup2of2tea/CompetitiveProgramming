#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <chrono>
 
using namespace std;
 
bool DEBUG = false;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
 
    map<int,int> m;
    vector<pair<int,int> > res;
 
    vector<int> v(n);
 
    for(int c=0;c<n;c++) {
        int z;
        cin>>z;
        z--;
        m[z] = c;
        v[c]=z;
    }
 
    int mid = n/2;
 
    for(int c=0;c<n;c++) {
        if(m[c] == c) {
            continue;
        }
        int s1 = m[c]/mid;
        int s2 = c/mid;
 
        if(DEBUG)cout<<c<<endl;
        int target = v[c];
 
        if(s1 == s2) {
            if(s2 == 0){
                    if(DEBUG)cout<<"first"<<endl;
                int last = v.back();
 
                res.push_back(make_pair(v.size()-1,m[c]));
                swap(v[res.back().first],v[res.back().second]);
                if(DEBUG)cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(v.size()-1,c));
                swap(v[res.back().first],v[res.back().second]);
 
                if(DEBUG)cout<<res.back().first<<" "<<res.back().second<<endl;
 
                int t1 = m[last];
                int t2 = m[c];
                int t3 = m[target];
 
                m[last] = t2;
                m[c] = c;
                m[target] = v.size()-1;
 
            } else {
                if(DEBUG)cout<<"second"<<endl;
                int first = v[0];
                res.push_back(make_pair(0,m[c]));
                swap(v[res.back().first],v[res.back().second]);
 
                if(DEBUG)cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(0,c));
 
                swap(v[res.back().first],v[res.back().second]);
 
               if(DEBUG) cout<<res.back().first<<" "<<res.back().second<<endl;
 
 
                int t1 = m[first];
                int t2 = m[c];
                int t3 = m[target];
 
                m[first] = t2;
                m[c] = c;
                m[target] = 0;
 
            }
        }else if(abs(m[c]-c)>=mid) {
           if(DEBUG) cout<<"third"<<endl;
            res.push_back(make_pair(c,m[c]));
                swap(v[res.back().first],v[res.back().second]);
                if(DEBUG)cout<<res.back().first<<" "<<res.back().second<<endl;
            m[target] = m[c];
            m[c]=c;
        } else {
             if(DEBUG)   cout<<"fourth"<<endl;
                int last = v.back();
                int first = v[0];
 
                res.push_back(make_pair(v.size()-1,min(m[c],c)));
                swap(v[res.back().first],v[res.back().second]);
 
              if(DEBUG)  cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(0,max(m[c],c)));
                swap(v[res.back().first],v[res.back().second]);
              if(DEBUG)  cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(0,v.size()-1));
                swap(v[res.back().first],v[res.back().second]);
 
              if(DEBUG)  cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(v.size()-1,min(m[c],c)));
                swap(v[res.back().first],v[res.back().second]);
 
            if(DEBUG)    cout<<res.back().first<<" "<<res.back().second<<endl;
 
                res.push_back(make_pair(0,max(m[c],c)));
                swap(v[res.back().first],v[res.back().second]);
 
               if(DEBUG) cout<<res.back().first<<" "<<res.back().second<<endl;
 
                int t1 = m[last];
                int t2 = m[first];
 
                m[last] = t2;
                m[first] = t1;
 
                m[target] = m[c];
                m[c]=c;
 
        }
    }
 
 
 
    if(v[0] != 0) {
        res.push_back(make_pair(0,v.size()-1));
        swap(v[res.back().first],v[res.back().second]);
    }
    cout<<res.size()<<endl;
 
    //for(int c=0;c<v.size();c++) cout<<v[c]<<" ";
    //cout<<endl;
 
    for(int c=0;c<res.size();c++) {
        cout<<res[c].first+1<<" "<<res[c].second+1<<endl;
    }
}