#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
map<vector<int>,bool> deja_vus;
 
int racine(int indice,vector<int> v)
{
    if(v[indice]==indice)
        return indice;
    return racine(v[indice],v);
}
 
int main()
{
        int n;
        cin>>n;
    vector<int> pere(n);
        vector<int> perm(n);
        vector<int> pref(n);
        for(int c=0;c<n;c++)
                cin>>perm[c];
        for(int c=0;c<n;c++)
                cin>>pref[c];
    for(int c=0;c<n;c++)
        pere[c]=c;
    for(int c=0;c<n;c++)
    {
        if(c+pref[c]<n)
        {
            int a=racine(c,pere),b=racine(pref[c]+c,pere);
            if(a!=b)
                pere[a]=b;
        }
        if(c-pref[c]>=0)
        {
            int a=racine(c,pere),b=racine(c-pref[c],pere);
            if(a!=b)
                pere[a]=b;
        }
  
    }
        
        for(int c=0;c<n;c++)
        if(racine(c,pere)!=racine(perm[c]-1,pere))
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
} 
 