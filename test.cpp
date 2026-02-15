#include <iostream>
#include <vector>
using namespace std;

// ヒープ化（部分木を最大ヒープにする）
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // 根
    int left = 2 * i + 1;   // 左の子
    int right = 2 * i + 2;  // 右の子

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// ヒープソート
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 最大ヒープを構築
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 要素を1つずつ取り出す
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}


/** memo

壊れてしまった謎を誰か修復してくれ・・・！
あれがないと私のメッセージが届けられないんだ・・・！

**/
