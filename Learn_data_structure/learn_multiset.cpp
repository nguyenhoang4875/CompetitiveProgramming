#include<iostream>
#include<set>
#include <cstdlib> // to use rand

using namespace std;
/**
 * multiset<data_type> set_name //
 * multiset are containers that store elements following a specific order,
 *  and where multiple elements can have equivalent values
 * create a multiset:
 *  multiset<int> v; // empty set
 *  multiset<int> v = {val, val, val, ...}; // init and set value for set
 * 
 * method:
 *  get
 *      size() // get size of set
 *      empty() // check multiset is empty or not
 * 
 *  add element
 *      insert(e) // add an element(object) to the set 
 *      emplace(e) // add an element(construct) to the set  
 * 
 *  delete element:
 *      multiset.erase(e) // e the value of element need to erase
 *      multiset.clear() // clear all elements in multiset 
 *  
 *  
 *    contains:
 *      using count function // set.count(val) return number element appear 
 *      using find function // return set.find(val) iterator of element
 * 
 *  iterator:
 *      using for each: for(int e : v) cout << e
 *      using interator: for(set<int>:: interator it = v.begin(); it < v.end(); it++) cout << *it
 *      using interator auto: for(auto it = v.begin(); it < v.end(); it++) cout << *it
 *      
*/

void printSet(multiset<int> si) {
    // for each in set
    for (int e: si) {
        cout << e << " " ;
    }
    cout << endl;
}

int main() {
    // new a set or : set<int> set_name;
    multiset<int> si = {1, 2, 3, 4};
    si.insert(5);
    si.insert(8);
    si.insert(7);
    printSet(si);

    // get size of multiset
    cout << "size of multiset = " <<  si.size() << endl;
    // delete a element
    si.erase(5);
    cout << "size of multiset = " <<  si.size() << endl;

    // clear multiset
    si.clear();
    cout << "size of multiset after clear = " <<  si.size() << endl;

    multiset<int> si2 = {1, 1, 1, 1, 2, 2, 3};
    cout << "size of si2 = " << si2.size() << endl; // size = 7
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
    // count the number appear of 1
    cout << "multiset si2 size = " << si2.size() << endl;
    cout << "number times appear of 1 = " << si2.count(1) << endl;


    // erase elements 1
    si2.erase(1);
    cout << "multiset si2 size after delete 1 = " << si2.size() << endl;
    return 0;
}
