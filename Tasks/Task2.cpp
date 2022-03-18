
void task2() {
    std::string integer = "";
    std::string fraction = "";
    std::cout << "Enter integer part: ";
    std::cin.sync();
    std::cin >> integer;
    std::cout << "Enter fraction part:";
    std::cin >> fraction;
    double number = std::stod(integer + '.' + fraction);
    std::cout << (double) number << std::endl;
}
