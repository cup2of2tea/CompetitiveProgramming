    #include <iostream>
   
 
    using namespace std;
   
    int main()
    {
        int nb_trucs;
        int a,b,c;
       long long int totala=0,totalb=0,totalc=0;
       cin>>nb_trucs;
      for(int c2=0;c2<nb_trucs;c2++)
     {
          cin>>a>>b>>c;
           totala+=a;
           totalb+=b;
           totalc+=c;
       }
       cout<<((totala==totalb&&totala==totalc&&totala==0)?"YES":"NO");
   }