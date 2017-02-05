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

    // Sifts through the sentence as if it were a linear 2D array,
    // with the indexing return the columns of the sentence.
    for(int i = 0; i < columns; ++i) {
        for(int j = 0; j < rows; ++j) {
            if(i + j * columns < length)
                cout << sentence[i + j * columns];
        }
        cout << ' ';
    }

    return 0;
}
