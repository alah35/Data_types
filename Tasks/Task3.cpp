
bool isValid(char ch) {
    return ch == '+'|| ch == '-' || ch == '*' || ch == '/';
}

double calculate(double x, char operation, double y) {
    switch (operation) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
    }
    return 0;
}

int task3(){
    std::string expression;
    std::stringstream output;

    std::cout << "Enter your expression:" << std::endl;
    std::getline(std::cin, expression);
    output << expression << " ";

    double a, b;
    char operation;
    output >> a >> operation >> b;
    if (!isValid(operation)) {
        std::cout << "Wrong operation. Restart program";
        return -1;
    }

    output << "= " << calculate(a, operation, b);
    std::cout << output.str() << std::endl;
    return 0;
}