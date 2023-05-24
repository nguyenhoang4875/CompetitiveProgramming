#Monotonic Stack – Data Structure
(source: [Monotonic Stack GeeksForGeeks](https://www.geeksforgeeks.org/introduction-to-monotonic-stack-data-structure-and-algorithm-tutorials/))

## Define
A stack is called a monotonic stack if all the elements starting from the bottom of the stack is either in increasing or in decreasing order

## Types of Monotonic Stack:
- Monotonic Increasing Stack
- Monotonic Decreasing Stack

### Monotonic Increasing Stack:
```txt
It is a stack in which the elements are in increasing order from the bottom to the top of the stack. 
```

- As we need monotonically increasing stack, we should not have a smaller element at top of a bigger element.
- Steps to implement:
    - Iterate the given list of elements one by one :
        - Before pushing into the stack, POP all the elements till either of one condition fails:
            - Stack is not empty
            - Stack’s top is bigger than the element to be inserted.
        - Then push the element into the stack.

```C++
#include <bits/stdc++.h>
using namespace std;

void increasingStack(int arr[], int N) {
	stack<int> stk;
	for (int i = 0; i < N; i++) {
		// Either stack is empty or
		// all bigger numbers are popped off
		while (stk.size() > 0 && stk.top() > arr[i]) {
			stk.pop();
		}
		stk.push(arr[i]);
	}

	int N2 = stk.size();
	int ans[N2] = { 0 };
	int j = N2 - 1;

	// Empty Stack
	while (!stk.empty()) {
		ans[j] = stk.top();
		stk.pop();
		j--;
	}

	cout << "The Array: ";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "The Stack: ";
	for (int i = 0; i < N2; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 1, 4, 5, 3, 12, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);

	increasingStack(arr, N);
	return 0;
}
```
```txt
Output:
    The Array: 1 4 5 3 12 10 
    The Stack: 1 3 10 
```

### Monotonic Decreasing Stack:
```txt
A stack is monotonically decreasing if It’s elements are in decreasing order from the bottom to the top of the stack. 
```

- As we need monotonically decreasing stack, we should not have a bigger element at top of a smaller element.
- Steps to implement:
    - Iterate the elements of the list one by one:
        - Before pushing into the stack, POP all the elements till either of one condition fails:
            - Stack is not empty
            - Stack’s top is smaller than the element to be Inserted.
        - Then push the element into the stack.



```C++
#include <bits/stdc++.h>
using namespace std;

void decreasingStack(int arr[], int N)
{
	stack<int> stk;
	for (int i = 0; i < N; i++) {
		// Either stack empty or
		// all smaller numbers are popped off
		while (stk.size() > 0 && stk.top() < arr[i]) {
			stk.pop();
		}
		stk.push(arr[i]);
	}

	int N2 = stk.size();
	int ans[N2] = { 0 };
	int j = N2 - 1;

	// Empty stack
	while (!stk.empty()) {
		ans[j] = stk.top();
		stk.pop();
		j--;
	}

	cout << "The Array: ";
	for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    } 
	cout << endl;

	cout << "The Stack: ";
	for (int i = 0; i < N2; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 15, 17, 12, 13, 14, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);

	decreasingStack(arr, N);
	return 0;
}
```
```txt
Output:
    The Array: 15 17 12 13 14 10 
    The Stack: 17 14 10 
```