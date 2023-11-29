#include <iostream>
using namespace std;
class Poly
{
public:
    int A[4];
    int B[4];
    int sum[4] = {0, 0, 0, 0};
    void ip()
    {
        cout << "ENTER THE COEFFICIENTS OF FIRST POLYNOMIAL:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cin >> A[i];
        }
        cout << "ENTER THE COEFFICIENTS OF SECOND POLYNOMIAL:" << endl;
        for (int i = 0; i < 4; i++)
        {
            cin >> B[i];
        }
    }
    void disp()
    {
        cout << "THEfor (int i = 0; i < 4; i++)
        {
            sum[i] = A[i] + B[i];
        } FIRST POLYNOMIAL IS :" << endl;
        for (int i = 3; i >= 0; i--)
        {
            if (A[i] != 0)
            {
                if (i == 0)
                {
                    cout << A[i];
                }
                else
                {
                    if (i == 1)
                    {
                        cout << A[i] << "x";
                    }
                    else
                    {
                        cout << A[i] << "x^" << i;
                    }
                }

                if (i > 0 && A[i - 1] != 0)
                {
                    cout << " + ";
                }
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "THE SECOND POLYNOMIAL IS :" << endl;
        for (int i = 3; i >= 0; i--)
        {
            if (B[i] != 0)
            {
                if (i == 0)
                {
                    cout << B[i];
                }
                else
                {
                    if (i == 1)
                    {
                        cout << B[i] << "x";
                    }
                    else
                    {
                        cout << B[i] << "x^" << i;
                    }
                }

                if (i > 0 && B[i - 1] != 0)
                {
                    cout << " + ";
                }
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }

    void Addition()
    {
        for (int i = 0; i < 4; i++)
        {
            sum[i] = A[i] + B[i];
        }
        cout << "THE ADDDITION OF POLYNOMIALS WILL BE :" << endl;
        for (int i = 3; i >= 0; i--)
        {
            if (sum[i] != 0)
            {
                if (i == 0)
                {
                    cout << sum[i];
                }
                else
                {
                    if (i == 1)
                    {
                        cout << sum[i] << "x";
                    }
                    else
                        cout << sum[i] << "x^" << i;
                }

                if (i > 0 && sum[i - 1] != 0)
                {
                    cout << " + ";
                }
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }
};

int main()
{
    Poly p;
    while (true)
    {
        cout << "LIST OF OPERATIONS ON POLYNOMIALS :" << endl;
        cout << "a.READ POLYNOMIALS" << endl;
        cout << "b.DISPLAY BOTH THE POLYNOMIALS " << endl;
        cout << "c.DISPLAY THE ADDITION OF BOTH THE POLYNOMIALS" << endl;
        cout << "d.EXIT" << endl;
        char c;
        cout << "SELECT AN OPERATION FROM ABOVE :" << endl;
        cin >> c;

        switch (c)
        {
        case 'a':
            p.ip();
            break;

        case 'b':
            p.disp();
            break;

        case 'c':
            p.Addition();
            break;

        case 'd':
        cout<<"THANKYOU FOR HAVING ME :)"<<endl;
            return 0;

        default:
            cout << "PLEASE SELECT A VALID OPERATION FROM THE LIST !!!!!!!" << endl;
        }
    }

    return 0;
}