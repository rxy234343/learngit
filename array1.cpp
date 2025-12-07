#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int N,M;
    cin >> N >> M;
    string sym[100];
    int slen = 0;//记忆数组长度；
    string s;
    getline(cin,s);//把2后面的换行跳过去；
    for(int i = 0;i<N; i++)
    {
        getline(cin,sym[slen++]);//getline一直读字符串，遇到空格不断，碰到换行结束；
        //cin >> sym[slen++];
    }
    /*for (int i = 0; i<N; i++)
    cout << sym[i] << endl;*/
    int a[10][10];
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
            a[i][j]=-1;//初始化数组；
    }
    int line[10];
    for(int i = 0; i<M; i++)
    {
        cin >> line[i];
    }
    for(int i = 0; i<M; i++)
    {
        for(int j = 0; j<10; j++)
        {
            cin >> a[line[i]][j];//a[line[i]]查到目前这个第i行，被叫做第几行；
        }
    }
    /*for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }*/
    int k;
    cin >> k;
    for(int i = 0; i<k; i++)
    {
        int t;
        cin >> t;
        int t1 =a[t/10][t%10];
        cout << (t1==-1 ? "?" :sym[t1-1]) << endl;
    }
}