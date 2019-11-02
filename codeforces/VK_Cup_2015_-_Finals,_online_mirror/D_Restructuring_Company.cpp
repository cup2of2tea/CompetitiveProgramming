#include <bits/stdc++.h>
using namespace std;
 
int getRoot(int n,vector<int> &parent)
{
    if(n!=parent[n])
    {
        parent[n] = getRoot(parent[n],parent);
    }
    return parent[n];
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> root(n);
    vector<int> skip(n);
    vector<int> inverseSkip(n);
    for(int c=0;c<n;c++) root[c]=skip[c]=inverseSkip[c]=c;
    for(int c=0;c<m;c++)
    {
        int type,a,b;
        scanf("%d %d %d",&type,&a,&b);
        a--;
        b--;
        if(type == 1)
        {
 
            if(a>b) swap(a,b);
            int r1 = getRoot(a,root);
            int r2 = getRoot(b,root);
            root[max(r2,r1)] = min(r1,r2);
 
            if(b+1<n)
            {
                if(getRoot(b+1,root) == r2){inverseSkip[b+1] = inverseSkip[b];skip[b] = skip[b+1];}
            }
            if(b-1>0)
            {
                if(getRoot(b-1,root) == r2){inverseSkip[b] = inverseSkip[b-1]; skip[b-1] = skip[b];}
            }
            if(a+1<n)
            {
                if(getRoot(a+1,root) == r2){inverseSkip[a+1]=inverseSkip[a];skip[a] = skip[a+1];}
            }
            if(a-1 > 0)
            {
                if(getRoot(a-1,root) == r2){inverseSkip[a]=inverseSkip[a-1];skip[a-1] = skip[a];}
            }
        }
        else if(type == 2)
        {
            if(a>b) swap(a,b);
            int s1 = getRoot(a,skip);
            int s2 = getRoot(b,inverseSkip);
            skip[s1]=max(skip[b],skip[s1]);
            inverseSkip[s1]=min(inverseSkip[a],inverseSkip[s1]);
            for(int c=s1+1;c<=s2;c++)
            {
                skip[c]=max(skip[c],skip[b]);
                inverseSkip[c]=min(inverseSkip[c],inverseSkip[a]);
                int r1 = getRoot(c-1,root);
                int r2 = getRoot(c,root);
                root[max(r1,r2)] = min(r1,r2);
            }
        }
        else if(type == 3)
        {
            if(getRoot(a,root) == getRoot(b,root))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}