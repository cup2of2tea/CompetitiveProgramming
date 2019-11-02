#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
 
struct node
{
    node(){t.resize(3);}
    node(int a,int b,int c){t.resize(3);t[0]=a;t[1]=b;t[2]=c;}
    vector<int> t;
};
 
void actualiser(node &n)
{
    sort(n.t.begin(),n.t.end());
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
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    c--;
    vector<string> mat(n);
    for(int c=0;c<n;c++) cin>>mat[c];
    vector<vector<vector<pair<int,int> > > > previous(n,vector<vector<pair<int,int> > >(n,vector<pair<int,int> >(n,make_pair(-1,-1))));
    if(b==min(a,min(b,c))) swap(a,b);
    if(c==min(a,min(b,c))) swap(a,c);
    if(b==max(a,max(b,c))) swap(b,c);
    previous[a][b][c]=make_pair(1992,1992);
    queue<node> q;
    q.push(node(a,b,c));
    node act;
    while(q.size())
    {
        act = q.front();
        q.pop();
        if(*max_element(act.t.begin(),act.t.end())==2)
        {
            break;
        }
        for(int c=0;c<3;c++)
        {
            for(int c2=0;c2<n;c2++)
            {
                if(c2==act.t[0]||c2==act.t[1]||c2==act.t[2]) continue;
                if(mat[act.t[c]][c2]==mat[act.t[(c+1)%3]][act.t[(c+2)%3]])
                {
                    pair<int,int> change = make_pair(act.t[c],c2);
                    vector<int> new_node(3);
                    new_node[c]=c2;
                    new_node[(c+1)%3]=act.t[(c+1)%3];
                    new_node[(c+2)%3]=act.t[(c+2)%3];
                    sort(new_node.begin(),new_node.end());
                    if(previous[new_node[0]][new_node[1]][new_node[2]].first==-1)
                    {
                        previous[new_node[0]][new_node[1]][new_node[2]]=change;
                        q.push(node(new_node[0],new_node[1],new_node[2]));
                    }
                }
            }
        }
    }
    if(*max_element(act.t.begin(),act.t.end())!=2)
    {
            cout<<-1;
            return 0;
    }
    vector<pair<int,int> > res;
    while(previous[act.t[0]][act.t[1]][act.t[2]].first!=1992)
    {
        pair<int,int> change = previous[act.t[0]][act.t[1]][act.t[2]];
        res.push_back(change);
        if(act.t[0]==change.second) act.t[0]=change.first;
        else if(act.t[1]==change.second) act.t[1]=change.first;
        else if(act.t[2]==change.second) act.t[2]=change.first;
        actualiser(act);
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++)
    {
        cout<<res[c].first+1<<" "<<res[c].second+1<<endl;
    }
}