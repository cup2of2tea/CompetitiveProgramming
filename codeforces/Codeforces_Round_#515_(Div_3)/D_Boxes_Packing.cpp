#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
bool fine(vector<int> &v, int dep, int boxes, int boxSize) {
 
    int res = v.size() - dep;
    
    for(int c=0;c<boxes;c++) {
        int act = boxSize;
        for(int c2=dep;c2<v.size();c2++) {
            if(v[c2] <= act) {
                act -= v[c2];
                res--;
                dep=c2+1;
            } else break;
        }
    }
    return res == 0;
}
 
 
int main() {
   int n,m,k;
   cin>>n>>m>>k;
 
   vector<int> v(n);
   for(int c=0;c<n;c++) cin>>v[c];
 
   int gauche = 0, droite = n;
   while(gauche != droite) {
       int mid = (gauche + droite) / 2;
 
        if(fine(v, mid, m, k)){
            droite = mid;
        } else {
            gauche = mid + 1;
        }
   }
   cout<<(n - gauche);
}