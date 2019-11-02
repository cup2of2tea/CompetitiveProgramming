#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
    if(v.size()==1)
    {
        cout<<-1;
        return 0;
    }
    set<int> s;
    int diff;
    for(int c=0;c<2;c++)
    {
        diff = v[1]-v[0];
        bool miss = false;
        bool doble = false;
        int res = 0;
        for(int c=1;c<v.size();c++)
        {
            if(v[c]-v[c-1]!=diff)
            {
                if(miss)
                {
                    doble = true;
                    break;
                }
                miss=true;
                res=v[c-1]+diff;
                if(res+diff!=v[c])
                {
                    doble = true;
                    break;
                }
            }
        }
        if(!doble)
        {
           if(miss)
            {
                s.insert(res);
            }
            else
            {
                s.insert(v[0]-diff);
                s.insert(v.back()+diff);
            }
        }
        reverse(v.begin(),v.end());
    }
    if(v.size()==2)
    {
        if((v[0]+v[1])%2==0) s.insert((v[0]+v[1])/2);
    }
    cout<<s.size()<<endl;
    for(auto z : s)
    {
        cout<<z<<" ";
    }
}