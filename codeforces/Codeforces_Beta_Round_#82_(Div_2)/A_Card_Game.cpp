#include <iostream>
 
    using namespace std;
    int conversion(char c)
    {
        if(c<='9'&&c>='0')
            return c-'6';
        else if(c=='T')
            return 4;
        if(c=='J')
            return 5;
       if(c=='Q')
           return 6;
       if(c=='K')
           return 7;
       return 8;
    }
    int main()
    {
        string trump;
        cin>>trump;
        string c1,c2;
        cin>>c1>>c2;
        if((c1[1]==trump[0]&&c2[1]!=trump[0])||(c1[1]==c2[1]&&conversion(c1[0])>conversion(c2[0])))
        {
            cout<<"YES";return 0;
         }
         cout<<"NO";
         return 0;
    }