#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int number, count(0);
    cout << "Enter a number to calculate factorial: ";
    cin >> number;

    vector<int> product;
    product.push_back(1);

    // Multiplies digit by digit first, and then takes care of remainders second.
    for(int i = 2; i <= number; i++) {
        for(auto digit = product.begin(); digit != product.end(); ++digit) {
            *digit *= i;
        }

        for(size_t j = 0; j < product.size(); ++j) {
            if(product.at(j) < 10)
                continue;

            if(j == product.size()-1)
                product.push_back(0);

            product[j+1] += product[j]/10;
            product[j] %= 10;
        }
    }

    cout << "The factorial of " << number << " is: " << endl;
    for (auto it = product.rbegin(); it != product.rend(); ++it) {
        count++;
        cout << *it;
        if(count % 100 == 0)
            cout << endl;
    }

    return 0;
}
