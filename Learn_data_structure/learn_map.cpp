#include<iostream>
#include<map>
#include<unordered_map>
#include <cstdlib> // to use rand

using namespace std;
/**
 * map<key_type, value_type> map_name //
 * map is a tree map that the key elements will be sorted.
 * unordered_map: a map that element will be not sorted. (faster then set) 
 * create a map:
 *  map<int, int> mii; // empty map
 * 
 * method:
 *  get
 *      size() // get size of map
 *      empty() // checks whether the container is empty
 * 
 *  add element
 *      insert(key, value) // add an element(object) to the map 
 *      emplace(key, value) // add an element(construct) to the map  
 *      map_name[key] = val
 * 
 *  delete element:
 *      v.erase(key) // e the value of element need to erase
 *      v.erase(iterator) // delete element at index
 *      v.erase(iterator_left, iterator_right) // delete element for index left to right 
 *  
 *    contains:
 *      using count function // map.count(val) return number element appear 
 *      using find function // return map.find(val) iterator of element
 * 
 *  iterator:
 *      using index: for(int i = 0; i < n ; i++) cout << map[i];
 *      using for each: for(int e : v) cout << e
 *      using interator: for(map<int, int>:: interator it = v.begin(); it < v.end(); it++) cout << *it
 *      using interator auto: for(auto it = v.begin(); it < v.end(); it++) cout << *it
 *      
*/

struct person {
    int id;
    string name;
    person(int _id, string _name) {
        id = _id;
        name = _name;
    }

    // override operator < to compare in map
    bool operator < (const person &p) const {
        return id < p.id;
    }

    // override operator == to compare in unordered_map
    bool operator == (const person &p) const {
        return id == p.id && name == p.name;
    }

    // override << to print person
    friend ostream& operator<< (ostream &os, const person &p) {
        return os << p.id  << " " << p.name;
    }

};

// hash function to using for hashtable
struct hash_person {
    size_t operator() (const person& p) const {
        return (hash<int>() (p.id) ^ hash<string>()(p.name));
    }
};

void print_map(map<int, int> mii) {
    // for each in map
    for (auto e: mii) {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;
}

int main() {
    // new a map or : set<int> set_name;
    map<int, int> mii;
    mii[1] = 1;
    mii[2] = 2;
    mii[3] = 3;
    mii[4] = 4;
    mii[5] = 5;

    print_map(mii);

    // get size of map
    cout << "size of map = " <<  mii.size() << endl;
    // delete a element
    mii.erase(5);
    cout << "size of map = " <<  mii.size() << endl;

    // find element in map
    if (mii.find(0) != mii.end()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // print: false

    // find count element in map
    if (mii.count(1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    // print true

    // check whether is map empty
    cout << "map is empty: " << mii.empty() << endl;

    cout << "custom struc using in map" << endl;
    map<person, int> map_person;
    map_person[person(1, "a")] = 1;
    map_person[person(2, "b")] = 2;
    map_person[person(3, "c")] = 3;

    person p = person(4, "d");
    cout << p << endl;

    for (auto e: map_person) {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;

    // unordered_map: map using hash table
    unordered_map<int, int> umii;
    umii[1] = 1;
    umii[5] = 5;
    umii[2] = 2;
    umii[4] = 4;
    umii[3] = 3;

    cout << "unordered map: " << endl;
    for (pair<int, int> e: umii) {
        cout << e.first << " " << e.second << endl;
    }

    // custom stuct using unordered_map
    unordered_map<person, int, hash_person> umap_person;
    cout << "unordered map with custom struc key: " << endl;

    umap_person[person(1, "a")] = 1;
    umap_person[person(2, "b")] = 2;
    umap_person[person(3, "c")] = 3;

    for (auto e: umap_person) {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;


    return 0;
}
