
enum  Notes {
    DO = 1,
    RE = 2,
    ME = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SE = 64
};

std::string printNote(int note) {
    switch (note) {
        case DO:
            return "Do ";
        case RE:
            return "Re ";
        case ME:
            return "Me ";
        case FA:
            return "Fa ";
        case SOL:
            return "Sol ";
        case LA:
            return "La ";
        case SE:
            return "Se ";
        default:
            std::cout << "There is not such note" << std::endl;
            break;
    }
}

std::string getNotes(std::string s) {
    std::string notes = "";
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - '0' - 1;
        notes += printNote(1 << index);
    }
    return notes;
}

bool isValid(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '7')
            return false;
    }
    return true;
}

void task4() {
    std::stringstream melody;
    std::string combination;

    for (int i = 0; i < 12; i++) {
        std::cout << "Enter " << i + 1 << " combination:";
        std::getline(std::cin, combination);

        while (!isValid(combination)) {
            std::cout << "Incorrect notes. Try again";
            std::getline(std::cin, combination);
        }

        melody << getNotes(combination);
    }

    std::cout << melody.str();
}
