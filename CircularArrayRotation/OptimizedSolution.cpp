#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int size(0), opTimes(0), query(0), num(0);
    std::cin >> size >> opTimes >> query;
    
    std::vector<int> array;
    array.reserve(size);
    
    for(int i = 0; i < size; i++) {
        std::cin >> num;
        array.push_back(num);
    }

    // Rotates array until item pointed to by middle iterator is the 
    // new first element. In this case, the last element array.end()-1
    // will be moved to the beginning of the array and all other elements
    // shifted to the right by 1 index.
    for(int i = 1; i <= opTimes; i++) {
        std::rotate(array.begin(), array.end()-1, array.end());
    }
    
    for(int i = 1; i <= query; i++){
        cin >> num;
        cout << array[num] << endl;
    }
    
    return 0;
}
