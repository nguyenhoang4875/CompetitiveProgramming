#include<iostream>
#include<stack>
#include <cstdlib> // to use rand

using namespace std;
/**
 * Stack are designed in a LIFO context (last-in first out)
 * 
 * stack<data_type> stack_name //
 * create a stack:
 *  stack<int> st; // empty stack
 * 
 * method:
 *  get
 *      size() // get size of stack
 *      top() // get element in top of stack
 * 
 *  add element
 *      push(e) // add an element(object) to the stack 
 *      emplace(e) // add an element(construct) to the stack  
 * 
 *  delete element:
 *      pop() // remove element in the top of stack
 * 
 *  check empty stack:
 *      empty() // return bool whether its size is zero
 *      
*/

int main() {
    // new a stack or : stack<int> stack_name;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // get size of stack
    cout << "size of stack = " <<  st.size() << endl;
    // delete a element
    st.pop();
    cout << "size of stack = " <<  st.size() << endl;

    // check if stack is empty:
    cout << "stack is empty: " <<  st.empty() << endl;

    // get and pop all element in stack
    while(!st.empty()) {
        int x = st.top();
        st.pop();
        cout << x << " ";
    }
    cout << endl;

    // print true
    return 0;
}
