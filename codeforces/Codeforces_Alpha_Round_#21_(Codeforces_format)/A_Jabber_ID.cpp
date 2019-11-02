#include <iostream> 
#include <string> 
#include <cctype>
#include <vector>
using namespace std;
 
bool checkUserName(string strcheck)
{
  bool ok=true;
  if((strcheck.length()<1)||(strcheck.length()>16)) //check the length
    {
      ok=false;
    }
  for(int i=0;i<strcheck.length();i++)  //check each character
    {
      bool thisok=false;
      if(isalpha(strcheck[i]))
    thisok=true;
      else if('_'==strcheck[i])
    thisok=true;
      else if(isdigit(strcheck[i]))
    thisok=true;
      if(!thisok) ok=false;
    }
  return ok;
}
 
bool checkHostName(string hostname)
{
  vector<string> words; //to store words seperated by .
  bool ok=true;
  if((hostname.length()<1)||(hostname.length()>32)) //check hostname length
    ok=false;
  else if(hostname[hostname.length()-1]=='.') //check that it doesn't end with a dot
    ok=false;
  else
    {
      while(hostname.length()>0) //add words
    {
      int index=hostname.find(".");
      if(index<0)
        {
          cerr<<"added to words:"<<hostname<<endl;
          words.push_back(hostname);
          break;
        }
      else
        {
      words.push_back(hostname.substr(0,index));
      cerr<<"added to words:"<<words[words.size()-1]<<endl; //report
      hostname=hostname.substr(index+1,hostname.length());
        }//end of else
    }//end of while
    }//end of else
 
  for(int i=0;i<words.size();i++) //check each word with username checker
    {
      if(checkUserName(words[i])==false)
    ok=false;
    }
 
  return ok; //return answer
}
 
bool checkResource(string res)
{
  return checkUserName(res); //resource rules are just those for username
}
 
int main()
{
  bool ok=true;
  string input;
  getline(cin,input); //get the jabber id
  string usr,host,res; //for username,hostname and resource name
  int index=input.find("@"); 
  if(index<0) //there is no @
    ok=false;
  else
    {
      usr=input.substr(0,index);
      input=input.substr(index+1,input.length());
      index=input.find("/"); //check if resource exists
      if(index<0)
    {
      host=input;
      res="ok";
    }//end of if
      else
    {
      host=input.substr(0,index);
      res=input.substr(index+1,input.length());
    }//end of inner else
    }//end of else
  ok=(ok)&&(checkUserName(usr)&&checkHostName(host)&&checkResource(res)); //check ok with all checkers
 
  //write output
  if(ok)
      cout<<"YES"<<endl;
  else 
      cout<<"NO"<<endl;
  return 0;//declare successful termination
}