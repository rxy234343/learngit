#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    /*int a[10][10];
    for(int i = 0; i < m ; i ++)
    {
        for(int j =0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }*/
    struct Singer
    {
        int num;
        int score;
    }
    Singer singers[10];
    int slen = 0;
     for(int i = 0; i < m ; i ++)
    {
        (singers[i]).num = i+1；
        int max = 0;
        int min = 10;
        int sum = 0;
        for(int j =0; j<n; j++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            if(temp > max)
                max = temp;
            if(temp < min)
                min = temp;
        }
        singers[i].score= sum - min -max;
    }

    /*for(int i =0; i<m; i++)
    {
        cout <<singers[i].no << ":" << singers[i].score <<endl;
    }*/

    //冒泡排序
    while(true)
    {
        bool ifBubble = false;
        for(int i = 0; i<m-1; i++)
        {
            if(singers[i].score < singers[i+1].score)
            {
                Singer ss;
                ss = singers[i];
                singers[i] = singers[i+1];
                singers[i+1] = ss;
                ifBubble = true;
            }
        }
        if(!ifBUbble)
            break;
    }
    for(int i =0; i<m; i++)
        cout << setw(3) << singers[i].num;
}