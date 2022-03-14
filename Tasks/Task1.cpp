
bool is_valid_speed(float val, float min, float max, float epsilon) {
    return val > min - epsilon && val <= max + epsilon;
}

void task1() {

    float speed = 0.f;

    do {
        char display[17];
        float delta = 0.f;
        std::cout << "Enter delta speed:";
        std::cin >> delta;
        speed += delta;
        std::sprintf(display, "Speed: %.1f km/h", speed);
        std::cout << display << std::endl;
    } while (is_valid_speed(speed, 0, 150, 0.01));
}
