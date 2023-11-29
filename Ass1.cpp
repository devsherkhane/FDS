#include <iostream>
using namespace std;
class student
{
public:
    string C[5];
    string P[5];
    string M[5];
    string ur[15];
    string PA[15];
    void unionofarrays(string C[], string P[], string M[])
    {
        int count = 0;
        for (int i = 0; i < 5; ++i)
        {
            ur[count++] = C[i];
        }
        for (int i = 0; i < 5; ++i)
        {
            bool isDuplicate = false;
            for (int j = 0; j < 5; ++j)
            {
                if (P[i] == ur[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                ur[count++] = P[i];
            }int count = 0;
        }
        for (int i = 0; i < 5; ++i)
        {
            bool isDuplicate = false;
            for (int j = 0; j < 5; ++j)
            {
                if (M[i] == ur[j])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                ur[count++] = M[i];
            }
        }
        for (int i = 0; i < 15; ++i)
        {
            cout << ur[i] << " ";
        }
        cout<<endl<<endl;
    }
    void inter(string C[], string P[])
    {
        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            bool b = false;
            for (int j = 0; j < 5; j++)
            {
                if (P[i] == C[j])
                {
                    ur[count] = P[i];
                    count++;
                }
            }
            if (!b)
            {
                b = true;
            }
        }
        for (int i = 0; i < 15; ++i)
        {
            std::cout << ur[i] << " ";
        }
        cout<<endl<<endl;
    }
    void difference(string C[], string M[])
    {
        for (int i = 0; i < 5; ++i)
        {
            bool found = false;
            for (int j = 0; j < 5; ++j)
            {
                if (C[i] == M[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << C[i] << " ";
            }
        }
        cout<<endl<<endl;
    }
    void inter(string C[], string P[], string M[])
    {

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (C[i] == P[j] && P[j] == M[k])
                    {
                        cout << C[i] << " ";
                    }
                }
            }
        }

        cout << endl;
    }
};
int main()
{
    student s;
    string C[5] = {"DEV", "DJ", "SHREYASH", "AATHU", "TOHID"};
    string P[5] = {"DEV", "DJ", "ANJAS", "SHREYASH", "TANMAY"};
    string M[5] = {"SHREYASH", "AATHU", "TOHID", "DEV", "PRATIK"};
    string PA[20] = {"RUSHI", "SHUBHAM", "SHIVAM", "PRANAV", "BHAVESH", "DEV", "DJ", "SHREYASH", "AATHU", "TOHID", "TANMAY"};
    while (true)
    {
        cout << "SELECT AN OPERATION FROM BELOW :" << endl;
        cout << "a.FIND OUT PARTICIPANTS WHO HAVE PARTICIPATED IN CODING AND PROJECT BOTH " << endl;
        cout << "b.FIND OUT PARTICIPANTS WHO HAVE PARTICIPATED IN CODING OR PROJECT COMPETITION OR MASTERMIND " << endl;
        cout << "c.FIND OUT PARTICIPANTS WHO HAVE PARTICIPATED IN CODING BUT NOT IN  MASTERMIND " << endl;
        cout << "d.FIND OUT PARTICIPANTS WHO HAVE PARTICIPATED IN ALL EVENTS " << endl;
        cout << "e.LIST OF ALL STUDENTS " << endl;
        cout << "ENTER YOUR CHOICE :" << endl;
        char n;
        cin >> n;
        switch (n)
        {
        case 'a':
            cout << "THE STUDENTS ARE :" << endl;
            s.inter(C, P);
            break;
        case 'b':
            cout << "THE STUDENTS ARE :" << endl;
            s.unionofarrays(C, P, M);
            break;
        case 'c':
            cout << "THE STUDENTS ARE :" << endl;
            s.difference(C, M);
            break;
        case 'd':
            cout << "THE STUDENTS ARE :" << endl;
            s.inter(C, P, M);
            break;
        case 'e':
            cout << "THE STUDENTS ARE :" << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << PA[i] << " ";
            }
            cout<<endl;
            break;

        default:
            cout << "PLEASE SELECT A VALID CHOICE !!!!!!!" << endl;
        }
    }
    return 0;
}