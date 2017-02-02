#include <vector>
#include <iostream>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

bool swapPossible(std::vector<int>, int&, int&);
bool reversePossible(std::vector<int>, int&, int&);

int main() {

    int size(0), num(0), start(0), end(0);
    std::vector<int> intVector;

    cin >> size;

    for(int i = 0; i < size; i++) {
        cin >> num;
        intVector.push_back(num);
    }


    if(swapPossible(intVector, start, end))
        cout << "yes" << "\nswap " << start+1 << ' ' << end+1;
    else if(reversePossible(intVector, start, end))
        cout << "yes" << "\nreverse " << start+1 << ' ' << end;
    else
        cout << "no";
}


/*
 * Checks to see if the vector can be sorted into ascending order by swapping one single pair of values.
 * It iterates through the values, if they are already in ascending order, it skips them. The first set of values
 * it finds that aren't in ascending order it saves the index. It then reverses the descending pair and
 * then returns whether the vector is now sorted.
 */
bool swapPossible(std::vector<int> intVector, int& start, int& end) {
    bool firstSeen(false);

    for(int i = 0; i < intVector.size() - 1; i++) {
        if(intVector.at(i) <= intVector.at(i+1))
            continue;
        else if(intVector.at(i) > intVector.at(i+1) && !firstSeen) {
            start = i;
            end = i + 1;
            firstSeen = true;
        } else if (intVector.at(i) > intVector.at(i+1)) {
            end = i + 1;
            break;
        }
    }

    if (start < end)
        std::swap(intVector.at(start), intVector.at(end));

    return std::is_sorted(intVector.begin(), intVector.end());
}

/*
 * Checks to see if the vector can be sorted into ascending order by swapping one solid chunk of values.
 * It iterates through the values, if they are already in ascending order, it skips them. The first set of values
 * it finds that aren't in ascending order it saves the index. It then continues until the vector values are in
 * ascending order again and saves the index of the end of the descending chunk. It then reverses the descending
 * chunk and then returns whether the vector is now sorted.
 */
bool reversePossible(std::vector<int> intVector, int &start, int &end) {
    bool firstSeen(false);

    for(int i = 0; i < intVector.size() - 1; i++) {
        if(intVector.at(i) <= intVector.at(i + 1))
            continue;
        else if(intVector.at(i) > intVector.at(i + 1) && !firstSeen) {
            start = i;
            end = i + 2; // plus two because end iterators are exclusive
            firstSeen = true;
        } else if (intVector.at(i) > intVector.at(i + 1)) {
            end++;
        }
    }

    if (start < end)
        std::reverse(intVector.begin()+start, intVector.begin()+end);

    return std::is_sorted(intVector.begin(), intVector.end());
}
