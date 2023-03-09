#include<iostream>
#include<queue>
#include <cstdlib> // to use rand

using namespace std;
/**
 * Queue are designed in a FIFO context (first-in first out)
 * queue<data_type> queue_name 
 * 
 * create a queue:
 *  queue<int> st; // empty queue
 * 
 * method:
 *  get
 *      size() // get size of queue
 *      front() // get element first in queue 
 *      back() // get element last in queue 
 * 
 *  add element
 *      push(e) // add an element(object) to the queue 
 *      emplace(e) // add an element(construct) to the queue  
 * 
 *  delete element:
 *      pop() // remove element in the top of queue
 * 
 *  check empty queue:
 *      empty() // return bool whether its size is zero
 *      
*/

int main() {
    // new a queue or : queue<int> queue_name;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // get size of queue
    cout << "size of queue = " <<  q.size() << endl;
    // delete a element
    q.pop();
    cout << "size of queue = " <<  q.size() << endl;

    // check if queue is empty:
    cout << "queue is empty: " <<  q.empty() << endl;

    // get and pop all element in queue
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
    }
    cout << endl;

    // print true
    return 0;
}
