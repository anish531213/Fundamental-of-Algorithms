#include <iostream>
#include <map>

using namespace std;


void find2IntegerSumNaiveApproach(int arr[], int size, int sum) {
	cout << "\n***** Uisng navive approach *****" << endl;
	for (int i=0; i<size-1; i++) {
		for (int j=i+1; j<size; j++) {
			if (arr[i]+arr[j] == sum) {
				cout << arr[i] << " " << arr[j] << endl;
			}
		}
	}
}

void find2IntegerSumUsingHashmap(int arr[], int size, int sum) {
	cout << "\n***** Uisng Hashmap *****" << endl;
	map<int, int> m;
	int temp;
	for (int i=0; i<size; i++) {
		temp = arr[i];
		m[temp] = 1; 
	}

	for (int i=0; i<size; i++) {
		temp = arr[i];
		if (m[sum-temp] == 1) {
			cout << temp << " " << sum-temp << endl; 
			m.erase(temp);
			m.erase(sum-temp);
		}
	}
}


int main() {
	int n = 5;
	int arr[] = {2, 11, 7, 5, 4};
	int sum = 9;

	cout << "***** Given Array ******" << endl;
	for (int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	find2IntegerSumNaiveApproach(arr, n, sum);
	find2IntegerSumUsingHashmap(arr, n, sum);

	return 0;
}