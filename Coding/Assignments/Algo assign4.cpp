#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long CountInvMerge(vector<long long>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary vectors for left and right halves
    vector<long long> L(a.begin() + left, a.begin() + mid + 1);
    vector<long long> R(a.begin() + mid + 1, a.begin() + right + 1);
    
    // Merging two halves and counting inversions
    long long inversions = 0;
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
            inversions += (n1 - i);  // All remaining elements in L[i..n1-1] are greater than R[j]
        }
    }
    
    // Copy any remaining elements of L
    while (i < n1) {
        a[k++] = L[i++];
    }
    
    // Copy any remaining elements of R
    while (j < n2) {
        a[k++] = R[j++];
    }
    
    return inversions;
}

long long CountInv(vector<long long>& a, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    long long inversions = 0;
    
    // Divide and conquer
    inversions += CountInv(a, left, mid);
    inversions += CountInv(a, mid + 1, right);
    
    // Merge and count cross inversions
    inversions += CountInvMerge(a, left, mid, right);
    
    return inversions;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long inversions = CountInv(a, 0, n - 1);
        cout << inversions << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
