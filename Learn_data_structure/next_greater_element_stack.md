#Next Greater Element (NGE) for every element in given Array
(source [NGE GeeksForGeeks](https://www.geeksforgeeks.org/next-greater-element/))


## Find next greater element using Stack:

```txt
The idea is to store the elements for which we have to find the next greater element in a stack 
and while traversing the array, if we find a greater element, 
we will pair it with the elements from the stack till the top element of the stack is less than the current element.  
```

### Follow the steps mentioned below to implement the idea:

- Push the first element to stack.
- Pick the rest of the elements one by one and follow the following steps in the loop. 
    - Mark the current element as next.
    - If the stack is not empty, compare top most element of stack with next.
    - If next is greater than the top element, Pop element from the stack. next is the next greater element for the popped element.
    - Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
- Finally, push the next in the stack.
- After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.

```C++
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all elements of arr[] of size n */
void printNGE(int arr[], int n) {
	stack<int> s;
	/* push the first element to stack */
	s.push(arr[0]);

	// iterate for rest of the elements
	for (int i = 1; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}
		/* if stack is not empty, then pop an element from stack.
		If the popped element is smaller than next, then
		a) print the pair
		b) keep popping while elements are smaller and stack is not empty */
		while (s.empty() == false && s.top() < arr[i]) {
			cout << s.top() << " --> " << arr[i] << endl;
			s.pop();
		}

		/* push next to stack so that we can find next greater for it */
		s.push(arr[i]);
	}

	/* After iterating over the loop,
     the remaining elements in stack do not have the next greater element,
     so print -1 for them */
	while (s.empty() == false) {
		cout << s.top() << " --> " << -1 << endl;
		s.pop();
	}
}

int main()
{
	int arr[] = { 11, 13, 21, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}
```

```txt
Output:
    11 --> 13
    13 --> 21
    3 --> -1
    21 --> -1
```