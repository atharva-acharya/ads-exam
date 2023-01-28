// CPP program to find pairs of
// positive and negative values present in
// an array.
#include <bits/stdc++.h>
using namespace std;

// Print pair with negative and positive value
void printPairs(int arr[], int n)
{
	vector<int> v;
	unordered_map<int, bool> cnt;

	// For each element of array.
	for (int i = 0; i < n; i++) {

		// If element has not encounter early,
		// mark it on cnt array.
		if (cnt[abs(arr[i])] == 0)
			cnt[abs(arr[i])] = 1;

		// If seen before, push it in vector (
		// given that elements are distinct)
		else {
			v.push_back(abs(arr[i]));
			cnt[abs(arr[i])] = 0;
		}
	}

	if (v.size() == 0)
		return;

	for (int i = 0; i < v.size(); i++)
		cout << "-" << v[i] << " " << v[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printPairs(arr, n);

	return 0;
}
