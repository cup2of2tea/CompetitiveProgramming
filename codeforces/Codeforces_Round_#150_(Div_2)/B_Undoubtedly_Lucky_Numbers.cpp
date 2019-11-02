#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
bool comparaison(string a,string b)
{
    if(a.size()!=b.size())
        return a.size()>b.size();
    else return a>=b;
}
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    string n;
    cin>>n;
    int puissances_dix[10];
    puissances_dix[0]=0;
    for(int c=1;c<10;c++)
    {
        puissances_dix[c]=puissances_dix[c-1]+(9*8)*(1<<(c-1))/4-9;
    }
    if(n=="0")
    {
        cout<<0;
        return 0;
    }
    int res=puissances_dix[n.size()-1];
    set<string> se;
    for(int c=0;c<=9;c++)
    {
        for(int c2=c+1;c2<=9;c2++)
        {
            for(int c4=1;c4<=n.size();c4++){
            string s;
            s.resize(c4);
            for(int c3=0;c3<=s.size();c3++)
            {
                for(int c4=0;c4<c3;c4++)
                    s[c4]=c+'0';
                for(int c4=c3;c4<s.size();c4++)
                    s[c4]=c2+'0';
                sort(s.begin(),s.end());
                do
                {
                    if(s[0]=='0')
                        continue;
                    if(comparaison(n,s))
                    {
                       se.insert(s);
                    }
                }while(next_permutation(s.begin(),s.end()));
            }
            }
        }
    }
    cout<<se.size();
}