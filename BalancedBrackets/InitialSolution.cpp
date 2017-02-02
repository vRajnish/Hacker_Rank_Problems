#include <stack>
#include <iostream>

bool is_balanced(string expression) {
    if(expression.length() % 2 != 0) return false;
    
    stack<char> characters;
    
    for(int i = 0; i < expression.length(); ++i) {
        if(expression[i] == '{' || 
           expression[i] == '(' ||
           expression[i] == '[') {
           characters.push(expression[i]);
        }
        else if (!characters.empty()) {
            switch(expression[i]) {
                case('}'):
                    if(characters.top() == '{') {
                        characters.pop();
                        break;
                    } else
                        return false;
                case(']'):
                    if(characters.top() == '[') {
                        characters.pop();
                        break;
                    } else
                        return false;
                case(')'):
                    if(characters.top() == '(') {
                        characters.pop();         
                    } else
                        return false;
            }
        }
        else
            return false;
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

