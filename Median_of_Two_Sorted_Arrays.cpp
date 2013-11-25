#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        m--, n--;
        int mid_pos = (m + n) / 2 + 1;
        int mid_m = m, mid_n = n;
        while(mid_m + mid_n != mid_pos) {
        	if (A[mid_m] < B[mid_n]) {
        		if (mid_m + mid_n < mid_pos) {
        			mid_m = (mid_m + m) / 2 + 1;
        		} else {
        			mid_n /= 2;
        		}
        	} else {
        		if (mid_m + mid_n < mid_pos) {
        			mid_n = (mid_n + n) / 2 + 1;
        		} else {
        			mid_m /= 2;
        		}
        	}
        }
        if ((m + n) % 2 == 1) {
        	return A[mid_m] > B[mid_n] ? A[mid_m] : B[mid_n];
        } else {
        	return (A[mid_m] + B[mid_n]) / 2.0;
        }
    }
};

int main() {
	Solution sol;
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {3, 4, 5, 6, 7, 8};
	cout << sol.findMedianSortedArrays(A, 5, B, 6);
}
