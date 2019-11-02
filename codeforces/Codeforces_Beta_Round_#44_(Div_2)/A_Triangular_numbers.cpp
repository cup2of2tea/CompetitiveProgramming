    #include <iostream>
   
    using namespace std;
   
 
    int main()
    {
        int nb;
        cin>>nb;
        int total=0;
      for(int c=0;total<=nb;c++)
       {
             if(total==nb)
              {
                  cout<<"YES";
                  return 0;
              }
              total+=c;
       }
       cout<<"NO";
   }