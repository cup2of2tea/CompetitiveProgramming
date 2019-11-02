#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main()
{
    vector<bool> visites(1e6,false);
    int n,m;
    cin>>n>>m;
    visites[n]=true;
    queue<pair<int,int> > q;
    q.push(make_pair(n,0));
    while(1) {
        pair<int,int> act = q.front();
        q.pop();
        if(act.first == m) {
            cout<<act.second;
            return 0;
        }
        if(act.first*2 < visites.size() && !visites[act.first*2]) {
            visites[act.first*2] = true;
            q.push(make_pair(act.first*2,act.second+1));
        }
        if(act.first > 0 && !visites[act.first-1]) {
            visites[act.first-1] = true;
            q.push(make_pair(act.first-1,act.second+1));
        }
    }
    
}