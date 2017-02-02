#include<iostream>
#include<unordered_set>
using std::cout; using std::cin;

int main() {
    std::unordered_set<int> compliments;
    int size, difference, number, pairs;
    
    cin >> size >> difference;
    
    for (int i = 0; i < size; i++) {
        cin >> number;
        compliments.insert(number);
    }
    
    // Searchs the set for the compliment needed to create the specified difference
    for (auto it = compliments.begin(); it != compliments.end(); ++it) {
        if (compliments.find(*it + difference) != compliments.end()) 
            pairs++;
    }
    cout << pairs;
    return 0;
}
