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
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
 
    for(int c=0;c<n;c++)
    {
        cin>>a[c];
    }
 
    if((*max_element(a.begin(),a.end()))<0)
    {
        cout<<(*min_element(a.begin(),a.end()))<<endl;
        return 0;
    }
    int res = 0;
    for(int c=0;c<a.size();c++)
    {
        for(int c2=c;c2<a.size();c2++)
        {
            vector<int> choix;
            vector<int> to_delete;
            int act = 0;
            for(int c3=0;c3<a.size();c3++)
                if(c3>=c&&c3<=c2)
                {
                    act+=a[c3];
                    to_delete.push_back(a[c3]);
                }
                else choix.push_back(a[c3]);
            sort(choix.rbegin(),choix.rend());
            sort(to_delete.begin(),to_delete.end());
            int op = 0;
            res=max(res,act);
            while(op<k&&op<choix.size()&&op<to_delete.size())
            {
                act+=choix[op];
                act-=to_delete[op];
                op++;
                res=max(res,act);
            }
        }
    }
    cout<<res;
}