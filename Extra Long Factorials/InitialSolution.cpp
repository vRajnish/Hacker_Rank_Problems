#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int askInput();
void addFactors(int, vector<int> &totalProduct);
void factorial(int, vector<int> &totalProduct);
void multiply (int, vector<int> &totalProduct);
void removeZeros(vector<int> &currentProduct);


int main() {
    int number = askInput(),
        digits(0); // Stores initial number to calculate factorial of
    vector<int> totalProduct;
    vector<int> currentProduct;

    addFactors(number, totalProduct); // Adds initial value to totalProduct vector
    factorial(number, totalProduct); // Calculates factorial

    
    for(int i = totalProduct.size()-1; i >= 0; i--) {
        cout << totalProduct[i]; 
    }
}

// Asks user for number to calculate factorial of
int askInput() {
    int number;
    cin >> number;
    return number;
}

// Adds initial value to product vector in reverse order
void addFactors(int number, vector<int> &totalProduct) {
    while (number > 0) {
        totalProduct.push_back(number % 10);
        number /= 10;
    }
}

// Calculates factorial of the value entered by user
void factorial(int number, vector<int> &totalProduct) {
    int factor = number - 1; // First factor to multiply is the user enter value minus 1

    while (factor > 1) {
        multiply(factor, totalProduct);
        factor--;
    }
}

// Removes leading zeros left over from the resizing of currentProduct
void removeZeros(vector<int> &currentProduct) {
    for (int i = currentProduct.size()-1; i >= 0; i--) {
        if(currentProduct[i] == 0)
            currentProduct.erase(currentProduct.end()-1);
        else
            break;
    }
}

// Multiplies the digits of the factor by the digits of the product vector. Uses the basic
// idea of grade school multiplication, doing it digit by digit. No indiviual product is
// larger than 81 (or 9*9).
void multiply (int factor, vector<int> &totalProduct) {
    vector<int> currentProduct(totalProduct.size(), 0);
    int sum (0), // Used to hold the sum of the products when multiplying digits
        remainder(0), // Used to hold the remainder when adding numbers that equal a value larger than 9
        product(0), // Used for the product of a digit in the vector multiplied by a digit of the factor
        addZero(0); // Adjusts the index to account for the added zero for each iteration of summation


    while(factor > 0) {
        currentProduct.resize(currentProduct.size()+1, 0);
        for (int i = 0; i < totalProduct.size(); i++) {
            product = (factor % 10) * totalProduct[i];

            sum = currentProduct[i + addZero] + product % 10 + remainder;
            remainder = product / 10;

            if (sum <= 9) {
                currentProduct.at(i + addZero) = sum;
            } else {
                currentProduct.at(i + addZero) = sum % 10;
                remainder += (sum/10);
            }

            if (i == totalProduct.size() - 1) // if at last index, add last remainder to front of currentProduct
                currentProduct.at(i + addZero + 1) = remainder;
        }
        factor /= 10;
        addZero++;
        remainder = 0;
    }

    removeZeros(currentProduct);
    totalProduct.swap(currentProduct);
}
