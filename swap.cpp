#include<iostream>
using namespace std;
class SY
{
    public:
    int a,b,temp;
    int input()
    {
        cout<<"enter the first  no :"<<endl;
        cin>>a;
        cout<<"ENTER THE SECOND NO :"<<endl;
        cin>>b;
    }
    int swap()
    {
        a=temp;
        a=b;
        b=temp;
        return 0;
    }
    int display()
    {
        cout<<"a :"<<a<<endl;
        cout<<"b :"<<b<<endl;
    }
};
int main()
{
    SY s;
    s.input();
    s.swap();
    s.display();
    return 0;
}