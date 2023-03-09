#include<iostream>
#include<queue>
#include <cstdlib> // to use rand

using namespace std;
/**
 * Priority Queue are designed its first element always greatest (default) of the elements it contains
 * 
 *  priority_queue<data_type> queue_name 
 * 
 * min priority_queue:
 *  priority_queue<T, vector<T>, greater<T>> pq_min; // we can pass custom compare to priority queue 
 * 
 * create a priority queue:
 *  priority_queue<int> st; // empty queue
 * 
 * method:
 *  get
 *      size() // get size of priority queue
 *      top() // get top element in priority queue 
 * 
 *  add element
 *      push(e) // add an element(object) to the priority queue 
 *      emplace(e) // add an element(construct) to the priority queue  
 * 
 *  delete element:
 *      pop() // remove top element in the priority queue
 * 
 *  check empty queue:
 *      empty() // return bool whether its size is zero
 *      
*/

struct compare {
    bool operator()(int &a, int &b) {
        return a < b;
    }
};

int main() {
    // new a queue or : queue<int> queue_name;
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    // get size of queue
    cout << "size of priority queue = " <<  pq.size() << endl;
    // delete a element
    pq.pop();
    cout << "size of priority queue = " <<  pq.size() << endl;

    // check if queue is empty:
    cout << "priority queue is empty: " <<  pq.empty() << endl;

    // get and pop all element in queue
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        cout << x << " ";
    }
    cout << endl;
    // min priority queue
    priority_queue<int, vector<int>, greater<int>> min_pq;
    // priority_queue<int, vector<int>, compare> min_pq; // using custom compare
    min_pq.push(1);
    min_pq.push(2);
    min_pq.push(3);
    cout << "min priority queue" << endl;
    while(!min_pq.empty()) {
        int x = min_pq.top();
        min_pq.pop();
        cout << x << " ";
    }
    cout << endl;

    // print true
    return 0;
}
