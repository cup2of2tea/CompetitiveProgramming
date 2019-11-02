#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;cin>>n;
    vector <int> t; t.resize(n);int pair_impair[2]; int nb_impair=0,nb_pair=0; for(int c=0;c<n;c++){ int n; cin>>n; if(n%2){nb_impair++;pair_impair[1]=c+1;}
     else {nb_pair++;pair_impair[0]=c+1;}} cout<<(nb_impair==1?pair_impair[1]:pair_impair[0]);
}