#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int partition(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) std::swap(arr[low], arr[mid]);
    if (arr[high] < arr[low]) std::swap(arr[low], arr[high]);
    if (arr[high] < arr[mid]) std::swap(arr[mid], arr[high]);
    std::swap(arr[mid], arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> data = {9, 3, 7, 5, 6, 4, 8, 2};
    quickSort(data, 0, data.size() - 1);
    assert(std::is_sorted(data.begin(), data.end()));
    std::cout << "Quicksort median-of-three verified." << std::endl;
    return 0;
}

// Updated: 2017-09-22 - feat(sorting): implement quicksort with median-of-three pivot
