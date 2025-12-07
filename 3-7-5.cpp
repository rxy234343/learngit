#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   int signNum;
   int lineNum;
    cin >> signNum >> lineNum;
    string sign[101];
    int signLen = 1;
    
    cin.ignore();  //notice!!!!
    
    for(int i = 0; i < signNum; i++)
    {
        string ts;
        getline(cin,ts);
        sign[signLen]  = ts;
        signLen++;
    }
    /*
    for(int i = 0; i < signLen; i++)
    {
        cout << sign[i] << "\n";
    }
    */
    int code[10][10];
    for(int i = 0; i<10; i++)
        for(int j = 0; j<10; j++)
            code[i][j] = -1;
   
    int line[10];
    int lineLen = 0;
    for(int i = 0; i<lineNum; i++)
    {
        int temp;
        cin >> temp;
        line[lineLen] = temp;
        lineLen++;
    }
    
    for(int i = 0; i<lineNum; i++)
    {
        for(int j = 0; j<10; j++)
        {
            int temp;
            cin >> temp;
            code[line[i]][j] = temp;
        }
    }
    /*
    for(int i = 0; i<10; i++)
    {
     for(int j = 0; j<10; j++)
            cout <<code[i][j] << " ";
      cout << endl;
    }
    */
    int nums;
    cin >> nums;
    for(int i = 0; i<nums; i++)
    {
        int num;
        cin >> num;
        int l = num/10;
        int c = num%10;
        int index = code[l][c];
        if(index>=0 && index < signLen)
            cout << sign[index];
        else
            cout << "?";
        cout << endl;
    }
 }