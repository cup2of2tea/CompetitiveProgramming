#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <queue>
#include <iomanip>
#include <map>
#define DEBUG2
 
using namespace std;
 
bool visites[100001]={false};
 
int dfs(int act,vector<int> &res,int adding,int &needs,int lim)
{
    if(needs == 0) return 0;
    if(lim < act) return 0;
    int bla = 0;
    if(!visites[act])
    {
        visites[act]=true;
        res.push_back(act);
        needs--;
        bla++;
    }
    if(adding <= lim)
    {
        bla+=dfs(act+adding,res,adding*2,needs,lim);
        bla+=dfs(act,res,adding*2,needs,lim);
    }
    return bla;
 
}
 
int main()
{
    int sum,limit;
    cin>>sum>>limit;
    int dep = 1;
    int possibilites = 1;
    while(dep <= limit)
    {
        dep *= 2;
    }
    dep /= 2;
    vector<int> res;
    while(dep && sum)
    {
      //  cout<<dep<<" "<<sum<<" "<<possibilites<<endl;
        if(sum >= dep)
        {
            int needs = sum / dep;
            int truc = dfs(dep,res,dep*2,needs,limit);
            sum -= dep*truc;
 
        }
        possibilites*=2;
        dep/=2;
    }
    if(sum != 0)
    {
        cout<<-1;
        return 0;
    }
    cout<<res.size()<<endl;
    for(int c=0;c<res.size();c++) cout<<res[c]<<" ";
}