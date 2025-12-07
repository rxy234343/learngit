#include <iostream>
using namespace std;
template <class T>
class Pair
{
    public:
        T first,second;
        Pair(T first,T second);
        void show();
};
template <class T>
Pair<T>::Pair(T pfirst, T psecond)
{
    first  = pfirst;
    second = psecond;    
}
template <class T>
void Pair<T>::show()
{
   cout<<max(first,second)<<" "<< min(first,second)<<" "<< (first +second) \
   <<" "<<(first - second) << " "<<(first * second) <<" "<<(first/second)<<endl;
}
int main()
{
   int a,b;
   cin>>a>>b;
   Pair<int> p1(a,b);
   p1.show();
   float c,d;
   cin>>c>>d;
   Pair<float> p2(c,d);
   p2.show();
}