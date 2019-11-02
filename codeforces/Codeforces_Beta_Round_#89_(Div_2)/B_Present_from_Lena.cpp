#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
 
#ifdef LOCAL
#define cin in
#define cout out
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
template < class T,class T2 >
T2 fac(T n)
{
    return n<2?1:fac<T,T2>(n-1)*n;
}
 
template <class T>
T nb_combinaisons(T k,T n)
{
    if(n<k)
        return nb_combinaisons<T>(n,k);
    return fac<T,long long int>(n)/(fac<T,long long int>(n-k)*fac<T,long long int>(k));
}
 
string itoa_2(long long int n)
{
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    while(s.size()!=9)
        s='0'+s;
    return s;
}
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n;
    cin>>n;
 
    for(int c=0;c<=n;c++)
    {
        int a=0;
        for(int c2=0;c2<=n;c2++)
        {
            if(n-c<=c2)
            {
                cout<<a;if(c!=0) cout<<" "; a++;
            }
            else
                cout<<"  ";
        }
        a-=2;
        for(int c2=n-1;c2>=0&&a>=0;c2--)
        {
            if(n-c<=c2){
                cout<<a;if(a!=0&&c!=0) cout<<" ";a--;}
            else   cout<<"  ";
        }
        cout<<endl;
    }
    for(int c=n-1;c>=0;c--)
    {
        int a=0;
        for(int c2=0;c2<=n;c2++)
        {
            if(n-c<=c2)
            {
                cout<<a;if(c!=0) cout<<" "; a++;
            }
            else
                cout<<"  ";
        }
        a-=2;
        for(int c2=n-1;c2>=0&&a>=0;c2--)
        {
            if(n-c<=c2){
                cout<<a;if(a!=0&&c!=0) cout<<" ";a--;}
            else   cout<<"  ";
        }
        if(c!=0)
        cout<<endl;
    }
}
 
 
 