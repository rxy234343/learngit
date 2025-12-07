#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
string dealSpace(string s)
{
    int i = 0;
    while(s[i]==' ')
        i++;
    int begin = i;
    i = s.length()-1;
    while(s[i] == ' ')
        i--;
    int end = i;
    if(begin == -1) return "";
    s  = s.substr(begin, end-begin+1);
    string s1;
    int n = s.size();
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            if(s[i+1] == ' ' || ispunct(s[i+1]))
            {
            
            }
            else
            {
                  s1 += s[i];
            }
            
        }
        else
        {
            s1 += s[i];
        }
     
    }
    return s1;
}
string dealCap(string s)
{
    string s1;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z' && s[i] != 'I')
            s1 +=s[i] + 'a' -'A';
        else
            s1 += s[i];
    }
    return s1;
}
string dealPunct(string s)
{
    while(true)
    {
        int pos = s.find("?");
        if(pos == -1)
        {
            break;
            
        }
        else
        {
            s.replace(pos,1,"!");
        }
    }
    return s;
}
string dealOthers(string s)
{
    int i = 0;
    int n = s.size();
    string s1;
    while(i < n)
    {
        bool ifFind = false;
        if(s.substr(i,7) == "can you"  && (i==0 || s[i-1] == ' ') && (i+7 >=n || s[i+7] == ' '|| ispunct(s[i+7])))
        {
            ifFind = true;
            s1 += "I can";
            i += 7;
        }
        
        
        if(s.substr(i,9) == "could you"  && (i==0 || s[i-1] == ' ') && (i+9 ==n || s[i+9] == ' '|| ispunct(s[i+9])))
        {
            ifFind = true;
            s1 += "I could";
            i += 9;
        }

         if(s.substr(i,1) == "I"  && (i==0 || s[i-1] == ' ') && (i+1 ==n || s[i+1] == ' '|| ispunct(s[i+1])))
        {
            ifFind = true;
            s1 += "you";
            i += 1;
        }
        if(s.substr(i,2) == "me"  && (i==0 || s[i-1] == ' ') && (i+2 ==n || s[i+2] == ' '|| ispunct(s[i+2])))
        {
            ifFind = true;
            s1 += "you";
            i += 2;
        }
        if(ifFind == false)
        {
            s1 += s[i];
            i++;
        }
    }
   
    return s1;
}
int main()
{
    int N;
    cin >> N;
    string s;
    getline(cin,s);
    
    for(int i = 0; i<N; i++)
    {
        getline(cin, s);
        cout << s << endl;
        s = dealSpace(s);
        s = dealCap(s);
        s = dealOthers(s);
        s = dealPunct(s);
        cout <<"AI: " <<s << endl;
    }
    
}