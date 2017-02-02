#include <iostream>
#include <vector>
using std::cin; using std::cout;

int binary_search(const std::vector<long long> &, long long);
void quick_sort(std::vector<long long> &, int, int);
int partition(std::vector<long long> &, int, int);

int main() {
    int size(0), count(0);
    long long difference(0), number(0);
    std::vector<long long> numbers;

    cin >> size >> difference;

    numbers.reserve(size);
    for(int i = 0; i < size; ++i) {
        cin >> number;
        numbers.push_back(number);
    }

    quick_sort(numbers, 0, size-1);

    // Binary searches for compliment required to create specified difference
    for(int i = 0; i < size; ++i) {
        if(numbers[i] < difference)
            break;
        if(binary_search(numbers, numbers[i] - difference))
            ++count;
    }

    cout << count;
    return 0;
}

int binary_search(const std::vector<long long> &numbers, long long search_value) {
    int left(0), right(numbers.size() - 1);

    while(left <= right) {
        int middle = left + (right - left) / 2;
        if(numbers[middle] == search_value)
            return 1;

        else if(numbers[middle] > search_value)
            left = middle + 1;

        else
            right = middle - 1;
    }
    return 0;
}

void quick_sort(std::vector<long long> &numbers, int left, int right) {

    if(left >= right)
        return;

    int middle = partition(numbers, left, right);
    quick_sort(numbers, left, middle - 1);
    quick_sort(numbers, middle, right);
}

int partition(std::vector<long long> &numbers, int left, int right) {
    int middle = left + (right - left) / 2;
    long long pivot = numbers[middle];

    while(left <= right) {
        while(left <= right && numbers[left] > pivot)
            ++left;
        while(left <= right && numbers[right] < pivot)
            --right;
        if(left <= right) {
            std::swap(numbers[right], numbers[left]);
            ++left, --right;
        }
    }
    return left;
}
