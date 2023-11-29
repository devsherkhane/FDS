#include <cstring>
#include <iostream>
using namespace std;

struct Stack {
  int size;
  int top;
  char *arr;
};

int isfull(Stack *ptr) {
  if (ptr->top == ptr->size - 1) {
    return 1;
  } else {
    return 0;
  }
}
int isempty(Stack *ptr) {
  if (ptr->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void display(Stack *ptr) {

  for (int i = ptr->top; i >= 0; i--) {
    cout << ptr->arr[i] << " " << endl;
  }
}

void push(Stack *ptr, char x) {
  ptr->top++;
  ptr->arr[ptr->top] = x;
}

char pop(Stack *ptr) {
  char x = ptr->arr[ptr->top];
  ptr->top--;
  return x;
}

void palindrome(Stack *ptr, char a[], int length) {
  char temp;
  for (int i = 0; a[i] != '\0'; i++) {
    if (a[i] != ' ') {
      push(ptr, a[i]);
    }
  }

  char str[40];

  for (int i = 0; isempty(ptr)!=1; i++) {
    str[i] = pop(ptr);
  }
  cout << "Given String :" << a << endl;
  cout << "Reversed String :" << str << endl;

  int count = 0;
  char b[30];
  for (int i = 0; a[i] != '\0'; i++) {
    if (a[i] != ' ') {
      b[count] = a[i];
      count++;
    }
  }
  int p = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == b[i]) {
      p++;
    }
  }

  if (p == length) {
    cout << "The given String '" << a << "' is a Palindrome " << endl;
  } else {
    cout << "The given String '" << a << "' is not a Palindrome " << endl;
  }
}

int main() {
  struct Stack s;
  s.size = 30;
  s.top = -1;
  s.arr = new char[s.size]; // char[30]

  char str[] = "poor dan is in a droop";

  int len = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] != ' ') {
      len++;
    }
  }
  palindrome(&s, str, len);

  delete[] s.arr;
  return 0;
}
