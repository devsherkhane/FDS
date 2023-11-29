#include<iostream>
using namespace std;
class D
{
    public:
    float a,b,c;
    D ip()
    {
        cout<<"ENTER THE FIRST FLOAT NO :"<<endl;
        cin>>a;
        cout<<"ENTER THE SECOND FLOAT NO :"<<endl;
        cin>>b;
    }
    D op()
    {
        c=a*b;
        cout<<"THE MULTIPLICATION OF TWO NO IS :"<<c<<endl;
        
    }
};
int main()
{
    D d;
    d.ip();
    d.op();
    return 0;
} 