#include <iostream>
using namespace std;
class matrix
{
public:
    int A[3][3];
    int B[3][3];
    int T[3][3];
    void in()
    {
        cout << "ENTER THE ELEMENTS OF FIRST MATRIX" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> A[i][j];
            }
        }
        cout << "ENTER THE ELEMENTS OF SECOND MATRIX" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> B[i][j];
            }
        }
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] == 0)
                {
                    count++;
                }
            }
        }
        cout << "FREQUENCY OF ZERO IN A MATRIX IS " << count << endl;
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (B[i][j] == 0)
                {
                    count++;
                }
            }
        }
        cout << "FREQUENCY OF ZERO IN B MATRIX IS " << count << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] != 0)
                {
                    count2++;
                }
            }
        }
        cout << "FREQUENCY OF NON-ZERO ELEMENTS IN A MATRIX IS: " << count2 << endl;
        count2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (B[i][j] != 0)
                {
                    count2++;
                }
            }
        }
        cout << "FREQUENCY OF NON-ZERO ELEMENTS IN B MATRIX IS: " << count2 << endl;
        if (count > count2)
        {
            cout << "THE GIVEN BOTH 'A'&'B' MATRIX ARE  SPARSE MATRIX " << endl;
            cout << "---------------------------------------------------------------------------------------------------------";
        }
        else
        {
            cout << "THE GIVEN BOTH MATRIX ARE NOT A SPARSE MATRIX " << endl;
            exit(1);
            cout << "----------------------------------------------------------------------------------------------------------";
        }
    }
    void disp()
    {
        cout << "THE SPARSE MATRIX IS :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << A[i][j];
            }
            cout << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
    }
    void Addition()
    {
        int i, j;
        int S[3][3];
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                S[i][j] = A[i][j] + B[i][j];
            }
        }
        cout << "THE ADDITION OF TWO  SPARSE MATRIX WILL BE :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << S[i][j];
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    }
    void trans()
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                T[j][i] = A[i][j];
            }
        }
        cout << "TRANSPOSE OF MATRIX WILL BE :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << T[i][j];
            }
            cout << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    }
    void ftrans()
    {
        int Temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] != 0)
                {
                    Temp[j][i] = A[i][j];
                }
            }
        }
        cout << "TRANSPOSE OF MATRIX USING FAST ALGORITHM WILL BE :" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << Temp[i][j];
            }
            cout << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    }
};
int main()
{
    matrix m;
    char n;
    cout << "TAKE THE INPUT THE INPUT IN SPARSE MATRIX 'A' AND 'B' " << endl;
    m.in();
    while (true)
    {
        cout << "LIST OF OPERATION :" << endl;
        cout << "a.DISPLAY A SPARSE MATRIX" << endl;
        cout << "b.DISPLAY THE ADDITION OF TWO MATRIX" << endl;
        cout << "c.DISPLAY THE TRANSPOSE OF THE MATRIX " << endl;
        cout << "d.DISPLAY THE TRANSPOSE OF THE MATRIX USING FAST ALGORITHM" << endl;
        cout << "e.exit" << endl;
        cout << "SELECT AN OPERATION FROM ABOVE :" << endl;
        cin >> n;
        switch (n)
        {
        case 'a':
            m.disp();
            break;

        case 'b':
            m.Addition();
            break;

        case 'c':
            m.trans();
            break;

        case 'd':
            m.ftrans();
            break;

        case 'e':
            cout<<"THANKYOU FOR USING ME :) "<<endl;
            cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            exit(1);
            break;

        default:
            cout << "SELECT A VALID OPEARTION !!!!!!!!" << endl;
        }
    }

    return 0;
}