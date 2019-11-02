#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
long long accumulate(vector<int>::iterator deb, vector<int>::iterator fin, long long res){
    while(deb!=fin)
    {
        res += (*deb);
        deb++;
    }
    return res;
}
 
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> beauty(n);
    for(int c=0;c<n;c++) cin>>beauty[c];
    vector<bool> capitales(n);
 
    long long int sum = accumulate(beauty.begin(),beauty.end(),0);
 
 
 
    for(int c=0;c<k;c++){
        int z;
        cin>>z;
        capitales[z-1] = true;
    }
 
    long long int res = 0;
 
    for(int c=0;c<n;c++) {
        if(!capitales[(c+1)%n] && !capitales[c]){
            res += beauty[c]*beauty[(c+1)%n];
        }
        if(capitales[c]) {
            sum -= beauty[c];
            res += sum * beauty[c];
        }
    }
    cout<<res;
}