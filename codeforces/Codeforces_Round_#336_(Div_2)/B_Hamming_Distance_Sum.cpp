#include <bits/stdc++.h>
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    string a,b;
    cin>>a>>b;
    if(a.size() > b.size()) {
        cout<<0;
        return 0;
    }
    vector<long long int> nbOnes(a.size(),0),nbZeros(a.size(),0);
    for(int c=0;c<a.size();c++){
        if(a[c] == '1') nbOnes[c]++; else nbZeros[c]++;
        if(c>0)
        {
            nbOnes[c]+=nbOnes[c-1];
            nbZeros[c]+=nbZeros[c-1];
        }
    }
    long long int res = 0;
    for(int c=0;c<b.size();c++) {
        int gauche = 0, droite = a.size()-1;
        if(c+1 < a.size()){
            droite = c;
        }
        if(b.size()-c < a.size()){
            gauche = a.size()-(b.size()-c);
        }
        if(b[c] == '1'){
            res += nbZeros[droite];
            if(gauche > 0) res -= nbZeros[gauche-1  ];
        } else {
            res += nbOnes[droite];
            if(gauche > 0) res -= nbOnes[gauche-1];
        }
    }
    cout<<res;
}
/*
1010
100010101
 
 1010
100010101
 
  1010
100010101
 
   1010
100010101
 
    1010
100010101
 
     1010
100010101
*/