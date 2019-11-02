#include <iostream>
using namespace std;
 
string truc="aeiou";
 
int tab[3]={5,7,5};
int main()
{
    
    for(int c3=0;c3<3;c3++)
    {
        int nb_syllabes=0;
        string s;
        getline(cin,s);
        for(int c=0;c<s.size();c++)
        {
            for(int c2=0;c2<truc.size();c2++)
            {
                if(truc[c2]==s[c])
                {
                    nb_syllabes++;
                    break;
                 }
              }
        }
        if(nb_syllabes!=tab[c3])
        {
            cout<<"NO";
            return 0;
         }
      }
     cout<<"YES";
}