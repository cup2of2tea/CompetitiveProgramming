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
    vector<tuple<int,int,int> > case1(n);
    vector<tuple<int,int,int> > case2(n);
 
    int case1Length = 0;
    int case2Length = 0;
 
    for(int c=0;c<n;c++) {
        tuple<int,int,int> t;
        int a,b;
        cin>>a>>b;
            t = make_tuple(b,a,c);
        if(a > b) {
            case1[case1Length++] = t;
        } else {
            case2[case2Length++] = t;
        }
    }
 
    sort(case1.begin(),case1.begin()+case1Length);
    sort(case2.begin(),case2.begin()+case2Length);
    reverse(case2.begin(),case2.begin()+case2Length);
 
 
    int res = 0;
    int skip = 0;
    int act = 0;
 
    vector<int> path,path2;
 
    for(int c=0;c<case1Length;c++) {
        int v2 = get<0>(case1[c]);
 
        if(c+1<case1Length && v2 >= get<1>(case1[c+1]) ) skip++;
        else {path.push_back(get<2>(case1[c]));act++;}
    }
    res = max(res, act);
    act = 0;
    for(int c=0;c<case2Length;c++) {
        int v2 = get<0>(case2[c]);
        if(c+1<case2Length && v2 <= get<1>(case2[c+1]) ) skip++;
        else {path2.push_back(get<2>(case2[c]));act++;}
    }
 
    if(act > res) {
        cout<<act<<endl;
        for(int c=0;c<path2.size();c++) cout<<path2[c]+1<<" ";
    } else {
        cout<<res<<endl;
        for(int c=0;c<path.size();c++) cout<<path[c]+1<<" ";
    }
 
}