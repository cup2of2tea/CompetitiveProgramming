#include <iostream>
    #include <vector>
    using namespace std;
 
    int main()
    {
        string s;
        int people=0;
        int total=0;
        while(!cin.eof())
        {
            getline(cin,s);
            if(s[0]=='+')
                people++;
            else if(s[0]=='-')
                people--;
            else
            {
                int c;
                for(c=0;c<s.size()&&s[c]!=':';c++);if(c!=s.size())
                total+=people*(s.size()-c-1);
            }
 
        }
        cout<<total;
    }