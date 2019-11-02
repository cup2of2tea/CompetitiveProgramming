    #include <iostream>
    #include <cmath>
    using namespace std;
   
 
    int main()
    {
        int n,m;
        cin>>n>>m;
    if(m%2==0)
    {
        cout<<"NO";
        return 0;
    }
    for(int c=3;c<=sqrt(m);c++)
    {
        if(m%c==0)
        {
            cout<<"NO";
            return 0;
        }
    }
       for(int c=n+1;c<m;c++)
       {
           if(c%2==0)
               goto end;
           for(int c2=3;c2<=sqrt(c);c2+=2)
               if(c%c2==0)
                   goto end;
           cout<<"NO";
           return 0;
           end:;
       }
       cout<<"YES";
   }