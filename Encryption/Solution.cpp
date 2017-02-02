#include <iostream>
#include <cmath>
using std::cin; using std::cout;

int main() {
    std::string sentence;
    getline(cin, sentence);

    int length = sentence.length(),
        columns = ceil(sqrt(length)),
        rows = floor(sqrt(length));
        
    if(rows*columns < length)
        rows = columns;

    // Sifts through the sentence as if it were a linear 2D array where
    // the columns are stored consecutively. In this case the columns
    // are the answers to the encryption being requested.
    for(int i = 0; i < columns; ++i) {
        for(int j = 0; j < rows; ++j) {
            if(i + j * columns < length)
                cout << sentence[i + j * columns];
        }
        cout << ' ';
    }

    return 0;
}
