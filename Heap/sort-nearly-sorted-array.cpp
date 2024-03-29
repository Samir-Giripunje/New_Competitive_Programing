// Sort a k-sorted array
// Given a k–sorted array that is almost sorted such that each of the n elements may be misplaced by no more than k positions from the correct sorted order. Find a space-and-time efficient algorithm to sort the array.

// For example,

// Input:

// arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9]
// k = 2

// Output:[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Practice this problem

// A simple solution would be to use an efficient sorting algorithm to sort the whole array again. The worst-case time complexity of this approach will be O(n.log(n)), where n is the size of the input. This method also does not use the fact that the array is k–sorted. We can also use the insertion sort algorithm to correct the order in just O(n.k) time. Insertion sort performs really well for small values of k, but it’s not recommended for a large value of k (we can use it for k < 12).

// We can solve this problem in O(n.log(k)) using a min-heap. The idea is to construct a min-heap of size k+1 and insert the first k+1 elements into the heap. Then remove minimum from the heap and insert the next element from the array into the heap and continue the process till both array and heap are exhausted. Each pop operation from the heap should insert the corresponding top element in its correct position into the array.

// The algorithm can be implemented as follows in C++;

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to sort a k–sorted array
void sortKSortedArray(vector<int> &nums, int k)
{
    // create an empty min-heap using `std::priority_queue`
    // use `std::greater` as a comparison function for min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // insert the first `k+1` elements into a heap
    for (int i = 0; i <= k; i++)
    {
        pq.push(nums[i]);
    }

    int index = 0;

    // do for remaining elements in the array
    for (int i = k + 1; i < nums.size(); i++)
    {
        // pop the top element from the min-heap and assign them to the
        // next available array index
        nums[index++] = pq.top();
        pq.pop();

        // push the next array element into min-heap
        pq.push(nums[i]);
    }

    // pop all remaining elements from the min-heap and assign them to the
    // next available array index
    while (!pq.empty())
    {
        nums[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    vector<int> nums = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;

    sortKSortedArray(nums, k);

    // print the sorted array
    for (int i : nums)
    {
        cout << i << " ";
    }

    return 0;
}