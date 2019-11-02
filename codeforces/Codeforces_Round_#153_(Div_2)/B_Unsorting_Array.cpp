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
#include <iomanip>
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
 
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n;
    cin>>n;
    if(n<=2)
    {
        cout<<-1;
    }
    else
    {
         vector<int> v(n);
         set<int> s;
        for(int c=0;c<n;c++)
        {
            cin>>v[c];
            s.insert(v[c]);
        }
        if(s.size()>=3)
        {
            set<int>::iterator it=s.begin();
            it++;
            int prec=(*it);
            int choix=0;
            while(choix<v.size()&&v[choix]!=prec)
                choix++;
            if(choix==0)
                cout<<n<<" "<<1;
            else
                cout<<1<<" "<<choix+1;
            return 0;
        }
        else if(s.size()==2)
        {
            if(v.size()==3&&v[0]==v[2])
            {
                cout<<-1;
                return 0;
            }
            else
            {
                map<int,int> m;
                for(int c=0;c<v.size();c++)
                    m[v[c]]++;
                int solo=-1;
                for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
                {
                    if(it->second==1)
                        solo=it->first;
                }
                if(solo!=-1)
                {
                    for(int c=0;c<v.size();c++)
                    {
                        if(v[c]==solo)
                        {
                            if(c==(v.size()-1)/2)
                            {
                                cout<<c+1<<" "<<c+2<<endl;
                                return 0;
                            }
                            else
                            {
                                cout<<c+1<<" "<<(v.size()-1)/2+1<<endl;
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    if(v[0]!=v.back())
                    {
                        int c;
                        for(c=1;v[c]!=v[0];c++);
                        cout<<c+1<<" "<<v.size()<<endl;
                        return 0;
                    }
                    else
                    {
                        int c;
                        for(c=1;v[c]==v[0]&&v[v.size()-1-c]==v[0];c++);
                        if(v[c]!=v[0])
                            cout<<1<<" "<<c+1;
                        else
                            cout<<1<<" "<<v.size()-c;
                        return 0;
                    }
                }
            }
        }
        else
        {
            cout<<-1;
            return 0;
         }
 
    }
 
}