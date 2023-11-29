#include <stack>
#include <iostream>

using namespace std;

string sanitize(string str) {
    string res = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            res = res + (char) tolower(ch);
        }
    }
    return res;
}

string reverse(string str) {
    stack<char> stack;
    for (char ch : str) {
        stack.push(ch);
    }
    string res = "";
    while (!stack.empty()) {
        res = res + stack.top();
        stack.pop();
    }
    return res;
}

bool is_palindrome(string str) {
    string sanitized = sanitize(str);
    string reversed = reverse(sanitized);
    return sanitized == reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "- Reversed: " << reverse(sanitize(str)) << endl;
    cout << "- Is palindrome? " << (is_palindrome(str) == 1 ? "Yes" : "No") << endl;
}