#include<iostream>
#include<vector>
#include<algorithm> // to use reverse, sort
#include <cstdlib> // to use rand

using namespace std;
/**
 * vector<data_type> name
 * create a vector:
 *  vector<int> v; // empty vector
 *  vector<int> v(n); // vector with size n
 *  vector<int> v(n, value); // vector with size n and default value
 * 
 * method:
 *  get
 *      v[index] or v.at(index) // get the element at the index
 *      size() // get size of vector
 * 
 *  add element
 *      push_back(e) // add an element(object) to the back of vector  
 *      emplace_back(e) // add an element(construct) to the back of vector  
 *      empalce(*pos, val)
 *      insert(*pos, val)
 * 
 *  update element:
 *      v[i] = new value;
 * 
 *  delete element:
 *      v.erase(v.begin() + index) // delete element at index
 *      v.erase(v.begin() + a, v.begin() + b) // delete element for index a to b
 *  
 *  resize: resize the vector to n elements
 *      v.resize(n);
 *
 *    contains:
 *      using count function // in algorithm
 *      using find function // in algorithm
 *      using find_if, any_of function // in algorithm
 *      using binary_search function // in algorithm (require sorted)
 * 
 *  iterator:
 *      using index: for(int i = 0; i < n ; i++) cout << v[i];
 *      using for each: for(int e : v) cout << e
 *      using interator: for(vector<int>:: interator it = v.begin(); it < v.end(); it++) cout << *it
 *      using interator auto: for(auto it = v.begin(); it < v.end(); it++) cout << *it
 *      
 *  reverse elements in a vector
 *      revert(v.begin(), v.end()) // revert fuction from algorithm
 * 
 *  sort elements in a vector
 *      sort asc
 *          sort(v.begin(), v.end);
 *          sort(v.begin(), v.end, less<data_type> ());
 *      sort desc
 *          sort(v.begin(), v.end, greater<data_type> ());
 * 
*/

int main() {

    // declare a vector, need to create a variable and the add to vector: cin >> x; v.push_back(x);
    vector<int> v; 
    // vector<int> v(n) // declare a vector with size n, can use cin >> a[i]
    // vector<int> v(n, 0) // declare a vector with size n and set all value equal 0

    // add element in back
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // or can using emplace_back(val)

    // get front
    cout << "front : " << v.front() << endl;

    // get back 
    cout << "back: " << v.back() << endl;

    // get size
    cout << "size of vector : " << v.size() << endl;

    // empalce: add element to the position, construct them inside the vector
    // good performance than insert
    v.emplace(v.begin(), 0);

    // insert: add element to the position, copy objects in to the vector 
    v.insert(v.begin(), -1);

    // update element:
    int new_value = 1000;
    v[0] = new_value;

    // delete an element: at index
    int index = 1;
    v.erase(v.begin() + index);

    // delete the element form index a to b;
    int a = 0, b= 2;
    v.erase(v.begin() + a, v.begin() + b);

    // resize the vector
    vector<int> vector_resize (10, 1);
    cout << "resize vector to 5 elements" << endl;
    vector_resize.resize(5);
    for (int e: vector_resize) cout << e << " ";
    cout << endl;

     // check contains element
    vector<int> vector_check_contains;
    vector_check_contains.emplace_back(1);
    vector_check_contains.emplace_back(2);
    vector_check_contains.emplace_back(3);
    vector_check_contains.emplace_back(4);
    vector_check_contains.emplace_back(4);

    // using count: return total number appear, return 0 if not found
    // count in range;
    int cnt = count(vector_check_contains.begin(), vector_check_contains.end(), 4);
    cout << "Number appear of 4 is = " << cnt << endl;
    cnt = count(vector_check_contains.begin(), vector_check_contains.end(), 0);
    cout << "Number appear of 0 is = " << cnt << endl;

    // using find: return iterator to first element appear, else return last (end)
    // find in range
    auto iFind = find(vector_check_contains.begin(), vector_check_contains.end(), 9);
    cout << "First index for 4 = " << iFind - vector_check_contains.begin()<< endl;

    // binary search
    sort(vector_check_contains.begin(), vector_check_contains.end());
    bool contains = binary_search(vector_check_contains.begin(), vector_check_contains.end(), 3);
    cout << "Binary search value 3 is exist: " << contains << endl;

    // iterator using index
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // same with v.at(i)
    }
    cout << endl;

    // interator using for each
    for (int e : v) {
        cout << e << " ";
    }
    cout << endl;

    // interator using for iterator 
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // using auto
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // auto can using for interator, int

    int n = 10;
    vector<int> v2(n, 100);
    for (int e: v2) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> vector_reverse;
    vector_reverse.push_back(1);
    vector_reverse.push_back(2);
    vector_reverse.push_back(3);
    vector_reverse.push_back(4);
    
    // reverse a vector
    reverse(vector_reverse.begin(), vector_reverse.end());
    for (int e: vector_reverse) {
        cout << e << " ";
    }
    cout << endl;

    // sort a vector
    vector<int> vector_sort;
    cout << "vector_sort size = "  << vector_sort.size() << endl;
    for (int i = 1 ; i < 10; i++) {
        vector_sort.push_back(rand() % 10);
    }
    cout << "vector sort before sort: " << endl;
    for (auto e: vector_sort) cout << e << " ";
    cout << endl;

    cout << "vector sort after sort asc: " << endl;
    sort(vector_sort.begin(), vector_sort.end()); // or sort(vector_sort.begin(), vector_sort.end(), less<int>());
    for (auto e: vector_sort) cout << e << " ";
    cout << endl;

    cout << "vector sort after sort desc: " << endl;
    sort(vector_sort.begin(), vector_sort.end(), greater<int>()); // 
    for (auto e: vector_sort) cout << e << " ";
    cout << endl;
    
}
