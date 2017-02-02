#include <iostream>

int main() {
    int size{0}, opTimes{0}, query{0}, temp1{0}, temp2{0};
    std::cin >> size >> opTimes >> query;
    
    int* array = new int[size];
    
    for(int i = 0; i < size; i++)
        std::cin >> array[i];
    
    // Performs right circular rotation
    for(int i = 1; i <= opTimes; i++) {
        for(int j = 0; j < size; j++) {
            if(j == 0) {
                temp1 = array[j];
                temp2 = array[j + 1];
            }
            if(j > 0 && j < size - 1) {
                array[j] = temp1;
                temp1 = temp2;
                temp2 = array[j+1];
            }
            if(j == size - 1) {
                array[j] = temp1;
                array[0] = temp2;
            }
        }
    }
    
    for(int i = 1; i <= query; i++){
        std::cin >> temp1;
        std::cout << array[temp1] << std::endl;
    }
    
    delete [] array;
    return 0;
}
