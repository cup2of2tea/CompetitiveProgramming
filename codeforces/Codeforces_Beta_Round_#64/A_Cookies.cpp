#include <iostream>
    #include <cmath>
    using namespace std;
 
 int power(int truc,int n,int resultat)
 {
     if(resultat>1000003)
         resultat%=1000003;
     if(n==0)
     {
         return resultat;
     }
     
     return power(truc,n-1,resultat*truc);
}
 
   int main()
   {
        int n;     
        cin>>n;
        if(n==0)
        {
            cout<<1;
            return 0;
        }
         cout<<power(3,n-1,1);
  }