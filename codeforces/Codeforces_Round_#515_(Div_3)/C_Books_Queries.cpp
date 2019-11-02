#include <iostream>
#include <map>
using namespace std;
 
int main() {
   int q;
   cin>>q;
 
    map<int,int> m;
 
    int l = 0, r = 0;
 
   while(q--) {
       char op;
       cin>>op;
       int id;
       cin>>id;
    
       if(op == 'L') {
           if(r==l) r++;
           m[id] = l;
           l--;
       } else if(op == 'R'){
           if(r==l) l--;
           m[id] = r;
           r++;
       } else {
           cout<<min(m[id]-l-1, r-m[id]-1)<<endl;
       }
 
   }
}