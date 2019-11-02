#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
 
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("input.txt");
#endif
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<string> > templa(n);
    for(int c=0;c<n;c++)
    {
        string s;
        getline(cin,s);
        for(int c2=0;c2<s.size();c2++)
            if((s[c2]>='a'&&s[c2]<='z')||(s[c2]>='A'&&s[c2]<='Z')||(s[c2]>='0'&&s[c2]<='9'))
                continue;
            else
                s[c2]=' ';
        stringstream ss(s);
        bool first=true;
        while(!ss.eof())
        {
            string z;
            ss>>z;
            if(z.size()>0&&!first){
            templa[c].push_back(z);}
            first=false;
        }
    }
    int m;
    cin>>m;
    vector<pair<string,string> > var(m);
    for(int c=0;c<m;c++)
        cin>>var[c].first>>var[c].second;
    int k;
    cin>>k;
    cin.ignore();
    vector<vector<string> > appel(k);
    for(int c=0;c<k;c++)
    {
        string s;
        getline(cin,s);
        for(int c2=0;c2<s.size();c2++)
            if((s[c2]>='a'&&s[c2]<='z')||(s[c2]>='A'&&s[c2]<='Z')||(s[c2]>='0'&&s[c2]<='9'))
                continue;
            else
                s[c2]=' ';
        stringstream ss(s);
        while(!ss.eof())
        {
            string z;
            ss>>z;
            if(z.size()>0){
            appel[c].push_back(z);}
        }
        int res=0;
        for(int c2=0;c2<templa.size();c2++)
        {
            if(templa[c2][0]!=appel[c][0]||templa[c2].size()!=appel[c].size())
                continue;
            for(int c3=1;c3<templa[c2].size();c3++)
            {
                if(templa[c2][c3]=="T")
                    continue;
                for(int c4=0;c4<var.size();c4++)
                {
                    if(appel[c][c3]==var[c4].second)
                    {
                        if(templa[c2][c3]!=var[c4].first)
                            goto end;
                    }
 
                }
            }
            res++;
            end:;
        }
        cout<<res<<endl;
    }
}