#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin; using std::cout; using std::endl; using std::vector;

int operations(vector<int> &);

int main() {

    vector<int> interns;
    int cases(0), intern_total(0), intern(0);

    cin >> cases;

    // Reads in all test cases
    for(int i = 1; i <= cases; ++i) {

        cin >> intern_total;
        interns.reserve(intern_total);

        // Reads in all interns for each test case
        for(int j = 0; j < intern_total; ++j) {
            cin >> intern;
            interns.push_back(intern);
        }
        
        cout << operations(interns) << endl;
        interns.clear();
    }
    return 0;
}

/*
  Finds the minimum number of operations needed to ensure that all interns have equal numbers of chocolate.
  It does this by checking one of two possible ways: 
      1. Finding the minimum element and then checking how many operations (of +5, +2, and +1) it would 
         take to get all other elements to equal the minimum element. 
      2. Finding an element other than the minimum and checking how many operations it would take to get
         all elements to equal that element.
         
  It then checks to see which option takes the least amount of operations and then returns that number.
*/
int operations(vector<int> &interns) {
    int best_op_count(0), op_count1(0), op_count2(0), number(0),
        min(*std::min_element(interns.begin(), interns.end()));

    for(int j = 0; j <= 5; j++) {
        if(j == 3 || j == 4)
            continue;
        for (int i = 0; i < interns.size(); ++i) {
            number = interns[i] - min - j;
            op_count1 += abs(number / 5 + (number % 5) / 2 + (number % 5) % 2);

            if(j == 0) {
                number = interns[i] - std::min({abs(min), abs(min - 1), abs(min - 2), abs(min - 5)});
                op_count2 += abs(number / 5 + (number % 5) / 2 + (number % 5) % 2);
            }
        }
        if(j == 0)
            best_op_count = op_count1;
        else
            best_op_count = std::min(op_count1, best_op_count);
    }
    return std::min(best_op_count,op_count2);
}

