#include <iostream>
#include <cmath>
using namespace std;
class search
{
public:
    int rn[10];
    int t;
    void ip()
    {
        cout << "Enter the roll no of students in Array :" << endl;
        for (int i = 0; i < 10; i++)
        {
            cin >> rn[i];
        }
        cout << endl;
        cout << "Before sorting the Array will be :" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << rn[i] << " ";
        }
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter the student roll which you want to check whether he attend the lecture or not :" << endl;
        cin >> t;
        cout << "Target acquired succesfully!!!" << endl;
    }
    void disp()
    {
        bool swapped;

        do
        {
            swapped = false;
            for (int i = 0; i < 9; i++)
            {
                if (rn[i] > rn[i + 1])
                {
                    int temp = rn[i];
                    rn[i] = rn[i + 1];
                    rn[i + 1] = temp;
                    swapped = true;
                }
            }
        } while (swapped);
        cout << "After sorting of the Array the Array will be :" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << rn[i] << " ";
        }
        cout << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
    void ls()
    {
        for (int i = 0; i < 10; i++)
        {
            if (rn[i] == t)
            {
                cout << "The roll no you entered was present in the lecture at index using linear search " << i << endl;
            }
        }
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
    void bs()
    {
        int start = 0;
        int end = 9;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (rn[mid] == t)
            {
                cout << "The roll no you enterd was present in the lecture at the index using binary search " << mid << endl;
            }

            bool isasc = rn[start] < rn[end];

            if (isasc)
            {
                if (t < rn[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (t > rn[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
    void js()
    {
        int start = 0;
        int end = sqrt(10);

        while (rn[end] <= t && end < 10)
        {
            start = end;
            end += sqrt(10);
            if (end > 9)
                end = 10;
        }

        for (int i = start; i < end; i++)
        {
            if (rn[i] == t)
                cout << "The roll no you enterd was present in the lecture at the index using jump search " << i << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    }
};
int main()
{
    search s;
    cout << "Pls input the roll nos :" << endl;
    s.ip();
    s.disp();
    while (true)
    {
        cout << "List of searches :" << endl;
        cout << "a.Search the roll no using Linear Search" << endl;
        cout << "b.Search the roll no using Binary Search" << endl;
        cout << "c.Search the roll no using Jump Search" << endl;
        cout << "d.Exit" << endl;
        char c;
        cout << "Select an Searching operation from above list" << endl;
        cin >> c;
        switch (c)
        {
        case 'a':
            s.ls();
            break;

        case 'b':
            s.bs();
            break;

        case 'c':
            s.js();
            break;

        case 'd':
            cout << "Thankyou for using me :)" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
            return 0;
            break;

        default:
            cout << "PLSS SELECT AN VALID OPEARTION FROM THE LIST !!!!!!!!!!!!!!" << endl;
        }
    }
    return 0;
}
