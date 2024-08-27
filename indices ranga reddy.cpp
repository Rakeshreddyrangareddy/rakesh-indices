#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // To store the indices of the elements
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement that adds to the target
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return the indices of the two numbers
        }
        numMap[nums[i]] = i; // Store the index of the current element
    }
    return {}; // Return an empty vector if no solution is found
}

int main() {
    int n, target;
    
    // Input array size and validate
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n < 2 || n > 10000) {
        cout << "Invalid input: Array size must be between 2 and 10000." << endl;
        return 1;
    }

    vector<int> nums(n);

    // Input array elements and validate
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < -1000000000 || nums[i] > 1000000000) {
            cout << "Invalid input: Array elements must be between -10^9 and 10^9." << endl;
            return 1;
        }
    }

    // Input target value and validate
    cout << "Enter the target value: ";
    cin >> target;

    if (target < -1000000000 || target > 1000000000) {
        cout << "Invalid input: Target must be between -10^9 and 10^9." << endl;
        return 1;
    }

    // Calculate and output the result
    vector<int> result = twoSum(nums, target);
    if (result.empty()) {
        cout << "No solution exists." << endl;
    } else {
        cout << "Indices of the two numbers are: [" << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}
