#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main()
{
        map<int,vector<int> > m;
        int n,k,x;
        cin>>n;
        for(int c=0;c<n;c++) for(int c2=0;c2<c;c2++)
        {
                cin>>k;
                for(int c3=0;c3<k;c3++)
                {
                        cin>>x;
                        m[x].push_back(c*n+c2);
                }
        }
        map<vector<int>,vector<int> > m2;
        for(map<int,vector<int> >::iterator it=m.begin();it!=m.end();it++)
                m2[it->second].push_back(it->first);
        vector<int> a[210];
        int suivant=0;
        for(map<vector<int> , vector<int> >::iterator it=m2.begin();it!=m2.end();it++)
                a[suivant++]=it->second;
        if(!a[1].size())
        {       
                a[1].push_back(a[0].back());
                a[0].pop_back();
        }
        for(int c=0;c<n;c++)
        {
                cout<<a[c].size();
                for(int c2=0;c2<a[c].size();c2++)
                        cout<<" "<<a[c][c2];
                cout<<endl;
        }
}