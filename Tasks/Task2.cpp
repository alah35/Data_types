
void task2() {
    std::string integer = "";
    std::string fraction = "";
    std::cout << "Enter integer part: ";
    std::cin >> integer;
    std::cout << "Enter fraction part:";
    std::cin >> fraction;
    double number = std::stod(integer + '.' + fraction);
    std::cout << number;
}
