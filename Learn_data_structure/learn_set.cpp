#include<iostream>
#include<set>
#include <cstdlib> // to use rand

using namespace std;
/**
 * set<data_type> set_name //
 * set is a tree set that the elements will be sorted.
 * unordered_set: a set that element will be not sorted. (faster then set) 
 * create a set:
 *  set<int> v; // empty set
 *  set<int> v = {val, val, val, ...}; // init and set value for set
 * 
 * method:
 *  get
 *      size() // get size of set
 * 
 *  add element
 *      insert(e) // add an element(object) to the set 
 *      emplace(e) // add an element(construct) to the set  
 * 
 *  delete element:
 *      v.erase(e) // e the value of element need to erase
 *      v.erase(iterator) // delete element at index
 *      v.erase(iterator_left, iterator_right) // delete element for index left to right 
 *  
 *    contains:
 *      using count function // set.count(val) return number element appear 
 *      using find function // return set.find(val) iterator of element
 * 
 *  iterator:
 *      using index: for(int i = 0; i < n ; i++) cout << v[i];
 *      using for each: for(int e : v) cout << e
 *      using interator: for(set<int>:: interator it = v.begin(); it < v.end(); it++) cout << *it
 *      using interator auto: for(auto it = v.begin(); it < v.end(); it++) cout << *it
 *      
*/

void printSet(set<int> si) {
    // for each in set
    for (int e: si) {
        cout << e << " " ;
    }
    cout << endl;
}

int main() {
    // new a set or : set<int> set_name;
    set<int> si = {1, 2, 3, 4};
    si.insert(5);
    si.insert(8);
    si.insert(7);
    printSet(si);

    // get size of set
    cout << "size of set = " <<  si.size() << endl;
    // delete a element
    si.erase(5);
    cout << "size of set = " <<  si.size() << endl;

    set<int> si2 = {1, 1, 1, 1, 2, 2, 3};
    cout << "size of si2 = " << si2.size() << endl; // size = 3
    printSet(si2);
    // find element in set
    if (si2.find(-2) != si2.end()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // print: false

    // find count element in set
    if (si2.count(1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // print true
    return 0;
}
