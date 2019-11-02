   #include <iostream>
    #include <string>
   
 
    using namespace std;
   
 
    int main()
    {
        string truc;
        cin>>truc;
        int petit=0,grand=0;
       for(int c=0;c<truc.size();c++)
           if(truc.at(c)<='z'&&truc.at(c)>='a')
                  petit++;
           else if(truc.at(c)<='Z'&&truc.at(c)>='A')
                   grand++;
       for(int c=0;c<truc.size();c++)
       {
           if(truc.at(c)<='z'&&truc.at(c)>='a'&&grand>petit)
              cout<<(char)(truc.at(c)-'a'+'A');
           else if (truc.at(c)<='Z'&&truc.at(c)>='A'&&petit>=grand)
               cout<<(char)(truc.at(c)-'A'+'a');
           else
               cout<<truc.at(c);
      }
   }