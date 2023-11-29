#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
    string str;

public:
    MyString(string s)
    {
        str = s;
    }

    void frequencyOfCharacter(char c)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == c)
            {
                count++;
            }
        }
        cout << "Frequency of character " << c << " is: " << count << endl;
    }

    void extractSubstring(int start, int length)
    {
        string newStr = str.substr(start, length);
        cout << "Extracted substring: " << newStr << endl;
    }

    void removeCharacter(char c)
    {
        string newStr = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != c)
            {
                newStr += str[i];
            }
        }
        cout << "String after removing character " << c << ": " << newStr << endl;
    }

    void replaceSubstring(string w, string x)
    {
        string result;
        int pos = 0;
        while (pos < str.length())
        {
            bool match = true;
            for (int i = 0; i < w.length(); i++)
            {
                if (str[pos + i] != w[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                result += x;
                pos += w.length();
            }
            else
            {
                result += str[pos++];
            }
        }
        str = result;
        cout << "String after replacement: " << str << endl;
    }

    bool isPalindrome()
    {
        int left = 0;
        int right = str.length() - 1;

        while (left < right)
        {
            if (str[left] != str[right])
            {
                cout << "The string is not a palindrome." << endl;
                return false;
            }
            left++;
            right--;
        }

        cout << "The string is a palindrome." << endl;
        return true;
    }
};

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    MyString myStr(input);

    int choice;
    char character;
    int start, length;
    string w, x;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Frequency of character\n";
        cout << "2. Extract substring\n";
        cout << "3. Remove character\n";
        cout << "4. Replace substring\n";
        cout << "5. Check palindrome\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter character to find frequency: ";
            cin >> character;
            myStr.frequencyOfCharacter(character);
            break;
        case 2:
            cout << "Enter starting position: ";
            cin >> start;
            cout << "Enter length: ";
            cin >> length;
            myStr.extractSubstring(start, length);
            break;
        case 3:
            cout << "Enter character to remove: ";
            cin >> character;
            myStr.removeCharacter(character);
            break;
        case 4:
            cout << "Enter substring to replace: ";
            cin >> w;
            cout << "Enter replacement string: ";
            cin >> x;
            myStr.replaceSubstring(w, x);
            break;
        case 5:
            myStr.isPalindrome();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}