#include<iostream>
#include<stack>
using namespace std;

class MinStack {
  stack < long long > st;
  long long mini;
  public:

    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 *val*1LL - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};

int main() {
    MinStack ms;

    ms.push(5);
    cout << "Pushed 5, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(3);
    cout << "Pushed 3, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(7);
    cout << "Pushed 7, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    return 0;
}