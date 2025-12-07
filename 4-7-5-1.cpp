#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

string dealSpace(string s)
{
    int begin = s.find_first_not_of(" ");
    int end = s.find_last_not_of(" ");
    if(begin == -1) return ""; // 处理全空格的情况
    s = s.substr(begin,end-begin+1);
    
    string s1 = ""; 
    for(int i = 0; i< s.size(); i++)
    {
       if(s[i] == ' ')
       {
           if(s1.back() != ' '&& i<s.size()-1 && !ispunct(s[i+1]) && s[i+1] !=' ')         
           {
               s1 =s1 + s[i];
              
           }
       }
        else
        {
            s1 = s1 + s[i];
            
        }
     }
    
    return s1;
}
string dealCap(string s)
{
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] != 'I' && s[i] <= 'Z' && s[i]>='A')
            s[i] = s[i] + ('a'-'A');
    }
    return s;
}
/*
string dealReplace(string s,string originstr,string replacestr)
{
    int pos = 0;

    while(true)
    {
        pos = s.find(originstr,pos);
        if(pos < 0)
            break;
        else
        {
            int end = pos + originstr.size() -1;
            if((pos == 0 ||(pos > 0 && (ispunct(s[pos-1])||s[pos-1]==' ')))&&(end == s.size()-1||(end<s.size()-1 && (ispunct(s[end+1])||s[end+1] ==' '))))
               s.replace(pos,originstr.size(),replacestr);
            
            pos =pos+1;
        }

    }
    return s;
}
string dealReplace1(string s,string originstr,string replacestr)
{
    int pos = 0;

    while(true)
    {
        
        pos = s.find(originstr,pos);
        if(pos < 0)
            break;
        else
        {
            s.replace(pos,originstr.size(),replacestr);
            pos =pos+1;
        }

    }
    return s;
}
*/
bool isWordBoundary(char c) {
    return c == ' ' || ispunct(c) || c == '\0';
}

// 主要的替换函数，在一次遍历中完成所有替换
string replaceAllInOnePass(string s) {
    string result = "";
    int i = 0;
    int n = s.length();
    
    while (i < n) {
        // 检查 can you
        if (s.substr(i, 7) == "can you" && 
            (i == 0 || isWordBoundary(s[i-1])) && 
            (i + 7 == n || isWordBoundary(s[i+7]))) {
            result += "I can";
            i += 7;
        }
        // 检查 could you
        else if (s.substr(i, 9) == "could you" && 
                 (i == 0 || isWordBoundary(s[i-1])) && 
                 (i + 9 == n || isWordBoundary(s[i+9]))) {
            result += "I could";
            i += 9;
        }
        // 检查独立的 I
        else if ((i == 0 || isWordBoundary(s[i-1])) && 
                 s[i] == 'I' && 
                 (i + 1 == n || isWordBoundary(s[i+1]))) {
            result += "you";
            i += 1;
        }
        // 检查独立的 me
        else if (s.substr(i, 2) == "me" && 
                 (i == 0 || isWordBoundary(s[i-1])) && 
                 (i + 2 == n || isWordBoundary(s[i+2]))) {
            result += "you";
            i += 2;
        }
        // 检查问号
        else if (s[i] == '?') {
            result += '!';
            i += 1;
        }
        // 其他字符直接复制
        else {
            result += s[i];
            i += 1;
        }
    }
    
    return result;
}

int main()
{
    
    int N;
    cin >> N;
    string s;
    getline(cin,s);
    for(int i = 0; i<N; i++)
    {
        getline(cin,s);
        cout << s << endl;
        /*
        s = dealCap(s);
        s = dealSpace(s);
        
        
        s = dealReplace(s,"can you","I can");
        s = dealReplace(s,"could you","I could");
    
        s = dealReplace(s,"me","you");
         s = dealReplace(s,"I","you");
        s = dealReplace1(s,"?","!");
        cout << "AI: "<< s << endl;
        */
       // 处理流程
        s = dealCap(s);      // 大小写转换
        s = dealSpace(s);    // 处理空格
        s = replaceAllInOnePass(s); // 一次性完成所有替换
        
        cout << "AI: " << s << endl;
    }
}