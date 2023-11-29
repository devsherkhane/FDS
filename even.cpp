#include<iostream>
using namespace std;
class S
{
    public:
    int n;
  S input()
   {
            cout<<"ENTER THE NO :"<<endl;
            cin>>n;
   }
   S op()
   {
    if(n%2==0)
    {
        cout<<"THE GIVEN NO IS EVEN "<<endl;
    }
    else
    {
        cout<<"THE GIVEN NO IS ODD "<<endl;
    } 
   }
};
int main()
{
    S s;
    s.input();
    s.op();
    return 0;

}