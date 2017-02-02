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

    // Moves last item to beginning of vector and shifts all other items to the right
    // by 1 index. Called a right circular rotation.
    for(int i = 1; i <= opTimes; i++) {
        std::rotate(array.begin(), array.end()-1, array.end());
    }
    
    for(int i = 1; i <= query; i++){
        cin >> num;
        cout << array[num] << endl;
    }
    
    return 0;
}
