#include<iostream>
#include<string>
#include<algorithm> // to use reverse, sort
#include <cstdlib> // to use rand
using namespace std;

/**
 * string name_string
 * create a string:
 *  string str = "val";
 *  string str = (const string& str);
 *  string str = (const string& str, size_t pos, size_t len = npos);
 *  string str = (size_t n, char c);
 * 
 * method:
 *  get
 *      str[index] or srt.at(index) // get the element at the index
 *      size() // get size of vector
 *      front() // access first character
 *      back() // access last character
 * 
 *  modify element
 *      operator+= (const string& str)
 *      operator+= (const char* s)
 *      operator+= (char c)
 * 
 *      insert(size_t pos, const string& str)
 *      insert(size_t pos, const string& str, size_t subpos, size_t sublen)
 *      insert(size_t pos, const char* s)
 *      insert(size_t pos, const char* s, size_t n)
 *      insert(size_t pos, size_t n, char c)
 *      insert(iterator p, char c)
 * 
 *      append(const string& str)
 *      append(const string& str, size_t subpos, size_t sublen)
 *      append(const char* s)
 *      append(const char* s, size_t n)
 *      append(size_t n, char c)
 * 
 *      replace(size_t pos, size_t len, const string& str)
 *      replace(size_t pos, size_t n, char c)
 * 
 *      push_back(c) // add an element to the back of string
 *      str[i] = new_val
 * 
 *  delete element:
 *      str.pop_back() // erase the last character 
 *      erase(size_t pos = 0, size_t len = npos)
 *      erase(iterator p)
 *      erase(iterator first, iterator last)
 *  
 *  resize: resize the vector to n elements
 *      str.resize(n);
 *      str.resize(size_t n, char c)
 *      str.clear(); remove all element in string
 *
 *  string operations:
 *      str.find(val) // return first index (string::npos) if it appear, else -1
 *      str.find(const string&s, size_t pos) // return first index from pos if it appear, else -1
 *          
 *      str.substr(size_t pos  = 0, size_t len = npos)
 *      str.copy(char* s, size_t len, size_t pos = 0)
 * 
 *      str.compare(str2) // return 0 if equals
 *      str.compare(size_t pos, size_t len, const string& str)
 *      
 * 
 *  iterator:
 *      using index: for(int i = 0; i < n ; i++) cout << str[i];
 *      using for each: for(char e : str) cout << e
 *      
 *  reverse elements in a string 
 *      revert(v.begin(), v.end()) // revert fuction from algorithm
 * 
 *  sort elements in a vector
 *      sort asc
 *          sort(v.begin(), v.end);
 *          sort(v.begin(), v.end, less<data_type> ());
 *      sort desc
 *          sort(v.begin(), v.end, greater<data_type> ());
 *  transform string
 *      upper case string:
 *          transform(str.begin(), str.end(), str.begin(), ::toupper)
 * 
*/

int main() {
    // Create a string
    string s0 ("Initial string");
    // constructors used in the same order as described above:
    string s1;
    string s2 (s0);
    string s3 (s0, 8, 3);
    string s4 ("A character sequence");
    string s5 ("Another character sequence", 12);
    string s6a (10, 'x');
    string s6b (10, 42);      // 42 is the ASCII code for '*'
    string s7 (s0.begin(), s0.begin()+7);

    cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
    cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';

    // get in string
    string s_get = "abcdef";

    // get at index
    cout << "get at index 2 " << s_get[1] << endl;
    cout << "get at index 2 " << s_get.at(1) << endl;

    // get size;
    cout << "s_get size = " <<  s_get.size() << endl;

    // get front;
    cout << "s_get front = " <<  s_get.front() << endl;

    // get back;
    cout << "s_get back = " <<  s_get.back() << endl;

    // add in string

    string str_find = "geeksforgeeks a computer science";
    char c = 'g';
  
    // Find first occurrence of 'g'
    size_t found = str_find.find(c);
    if (found != string::npos)
        cout << "First occurrence is " << found << endl;
  
    // Find next occurrence of 'g'
    found = str_find.find(c, found+1);
    if (found != string::npos) cout << "Next occurrence is " << found << endl;

    // sort string
    string str_sort = "axbef";
    cout << "before sort = " << str_sort << endl;
    sort(str_sort.begin(), str_sort.end());
    cout << "after sort asc = " << str_sort << endl;
    sort(str_sort.begin(), str_sort.end(), greater<char>());
    cout << "after sort desc = " << str_sort << endl;

    // reverse string
    string str_rev = "abcdef";
    cout << "before rev: " << str_rev << endl;
    reverse(str_rev.begin(), str_rev.end());
    cout << "after rev: " << str_rev << endl;

    // transform string
    string str_trans = "abXcd";
    transform(str_trans.begin(), str_trans.end(), str_trans.begin(), ::toupper);
    cout << str_trans << endl;

    return 0;
}
