    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <fstream>
    #include <sstream>
    #include <cmath>
    #include <algorithm>
 
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
        int n;
        double vb,vs;
        cin>>n>>vb>>vs;
        vector<double> arret(n);
        for(int c=0;c<n;c++)
            cin>>arret[c];
        double x,y;
        cin>>x>>y;
        sort(arret.begin(),arret.end());
 
        double mini=arret[1]/vb+(sqrt((x-arret[1])*(x-arret[1])+y*y))/vs;
        int indice_min=2;
        for(int c=2;c<arret.size();c++){double z=arret[c]/vb+sqrt((x-arret[c])*(x-arret[c])+y*y)/vs;if(z<=mini){mini=z;indice_min=c+1;}}
        cout<<indice_min;
    }