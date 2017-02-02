#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using std::cin; using std::cout;

int add_to_country(std::map<int,std::set<int>> &, int,int);
void merge_countries(std::map<int,std::set<int>> &);
bool compare_countries(std::set<int> &, std::set<int> &);
long calculate_combinations(std::map<int,std::set<int>> &, long);

int main() {

    std::map<int,std::set<int>> countries;
    int astro_total(0), pairs(0), ast1(0), ast2(0), curr_key(0), total_unique(0);
    long extra(0);

    cin >> astro_total >> pairs;

    // Read in all pairs of astronauts and add them to countries
    for(int i = 0; i < pairs; ++i) {
        cin >> ast1 >> ast2;
        curr_key = add_to_country(countries, ast1, ast2);
    }

    // Checks for duplicates across countries and merge
    merge_countries(countries);

    // Check total unique astronauts
    for(auto it = countries.begin(); it != countries.end(); ++it) {
        total_unique += it->second.size();
    }

    extra = astro_total - total_unique;

    cout << calculate_combinations(countries, extra);
}

int add_to_country(std::map<int,std::set<int>> &countries, int ast1, int ast2) {
    static int key = 0;

    // If no countries have been generated yet, create first one
    if(key == 0) {
        countries[key].insert(ast1);
        countries[key].insert(ast2);
        ++key;
        return key;
    }

    // Iterate through list of countries, each denoted by a unique integer key
    for(auto itCnty = countries.begin(); itCnty != countries.end(); ++itCnty) {

        // If astronaut found in either country, add additional astronaut to country
        if(std::binary_search(itCnty->second.begin(), itCnty->second.end(), ast1)) {
            itCnty->second.insert(ast2);
            return key;
        }
        else if(std::binary_search(itCnty->second.begin(), itCnty->second.end(), ast2)) {
            itCnty->second.insert(ast1);
            return key;
        }
    }
    
    // If astronaut not found in any country, create new country and add astronauts to it
    countries[key].insert(ast1);
    countries[key].insert(ast2);
    ++key;
    return key;
}


long calculate_combinations(std::map<int,std::set<int>> &countries, long extra) {
    long combinations(0);

    for(auto it1 = countries.begin(), it2 = countries.end(); it1 != it2; ++it1) {
        auto it3 = it1;
        for(auto it4 = ++it3; it4 != countries.end(); ++it4) {
            combinations += (it1->second.size()*it4->second.size());
        }
        combinations += it1->second.size()*extra;
    }
    combinations += ((extra-1)*(extra))/2;

    return combinations;
}

void merge_countries(std::map<int,std::set<int>> &countries) {
    bool merging(false);
    do {
        merging = false;
        for (int i = 0; i < countries.size() - 1; ++i) {
            if(countries[i].empty())
                continue;
            for (int j = i + 1; j < countries.size(); ++j) {
                if(countries[j].empty())
                    continue;
                if (compare_countries(countries[i], countries[j])) {
                    countries.erase(j);
                    merging = true;
                }
            }
        }
    } while(merging);
}

bool compare_countries(std::set<int> &countryA, std::set<int> &countryB) {

    for (auto it = countryA.begin(); it != countryA.end(); ++it) {
        int minimumB = *(countryB.begin()),
            maximumB = *(countryB.rbegin());
        if(*it < minimumB) {
            continue;
        }
        if(*it > maximumB) {
            return false;
        }
        if (std::binary_search(countryB.begin(), countryB.end(), *it)) {
            countryA.insert(countryB.begin(), countryB.end());
            return true;
        }
    }
    return false;
}
