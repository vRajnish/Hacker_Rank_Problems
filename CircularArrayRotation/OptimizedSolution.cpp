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

    for(int i = 1; i <= opTimes; i++) {
        std::rotate(array.begin(), array.end()-1, array.end());
    }
    
    for(int i = 1; i <= query; i++){
        cin >> num;
        cout << array[num] << endl;
    }
    
    return 0;
}
