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

    for(int i = 0; i < columns; ++i) {
        for(int j = 0; j < rows; ++j) {
            if(i + j * columns < length)
                cout << sentence[i + j * columns];
        }
        cout << ' ';
    }

    return 0;
}
