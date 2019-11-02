    #include <iostream>
    #include <vector>
     using namespace std;
     
   
 
         int main () {
           int  n, i, j, c = 0;
              vector <int> a;
           
          cin>>n;
a.resize(n+1);
         for (i = 0; i <= n; i++) a[i] = 0;
          for (i = 2; i <= n; i++) {
            switch (a[i]) {
            case 0:
             for (j = i; j <= n; j += i) a[j]++;
            break;
           case 2:
             c++;
           }
         }
         cout<<c;
      return 0;
       }