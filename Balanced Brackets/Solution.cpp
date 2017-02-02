#include <stack>
#include <iostream>

bool is_balanced(std::string expression) {
    std::stack<char> characters;

    for (char& c : expression) {
        if      (c == '{') characters.push('}');
        else if (c == '[') characters.push(']');
        else if (c == '(') characters.push(')');
        else {
            if (characters.empty() || c != characters.top())
                return false;
            characters.pop();
        }
    }
    return characters.empty();
}

int main(){
    int test_cases{0};
    std::cin >> test_cases;
    for(int i = 0; i < test_cases; i++){
        std::string expression;
        std::cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    return 0;
}

