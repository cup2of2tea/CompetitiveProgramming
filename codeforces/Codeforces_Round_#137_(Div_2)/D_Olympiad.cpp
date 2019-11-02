#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
 
 
int main()
{
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        vector<int> b(n);
        for(int c=0;c<n;c++)
                cin>>a[c];
        for(int c2=0;c2<n;c2++)
                cin>>b[c2];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout<<1<<" ";
        int droite=a.size()-1,gauche=0;
        int res=0;
        while(droite>=0)
        {
                while(gauche<a.size()&&a[droite]+b[gauche]<x)
                        gauche++;
                if(gauche>=a.size())
                        break;
                droite--;
                res++;
        gauche++;
        }
        int temp=0;
        droite=a.size()-1;
        gauche=0;
        while(droite>=0)
        {
                while(gauche<a.size()&&b[droite]+a[gauche]<x)
                        gauche++;
                if(gauche>=a.size())
                        break;
                droite--;
                temp++;
        gauche++;
        }
        res=max(res,temp);
        cout<<res;
}