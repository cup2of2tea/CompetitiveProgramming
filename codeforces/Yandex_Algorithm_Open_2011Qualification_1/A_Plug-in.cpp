        #include <iostream>
 
        using namespace std;
 
        int main()
        {
            string s;
            getline(cin,s);
                string s2;
                s2.resize(1000000);
                int truc=0;
                for(int c=0;c<s.size();c++)
                {
                    if(truc==0||s2.at(truc-1)!=s.at(c))
                        s2.at(truc++)=s.at(c);
                    else
                        truc--;
                }
                for(int c=0;c<truc;c++)
                {
                cout<<s2.at(c);
                   }
 
        }