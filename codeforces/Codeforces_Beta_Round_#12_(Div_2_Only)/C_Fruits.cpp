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
    #endif
    int n,m;
    map<string,int> ma;
    vector<int> products;
    cin>>n>>m;
    vector<int> prices(n);
    for(int c=0;c<n;c++)
        cin>>prices[c];
    sort(prices.begin(),prices.end());
    for(int c=0;c<m;c++)
    {
        string s;
        cin>>s;
        ma[s]++;
    }
    for(map<string,int>::iterator it=ma.begin();it!=ma.end();it++)
        products.push_back((*it).second);
    sort(products.begin(),products.end());
    int mini=0,maxi=0;
    for(int c=0;c<products.size();c++)
    {
        mini+=products[products.size()-c-1]*prices[c];
        maxi+=products[products.size()-c-1]*prices[prices.size()-c-1];
    }
    cout<<mini<<" "<<maxi;
}
 
 
 