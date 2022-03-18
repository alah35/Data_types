
enum switches {
    POWER = 1,
    SOCKETS = 2,
    LIGHT_INSIDE = 4,
    LIGHT_OUTSIDE = 8,
    HEATING_HOUSE = 16,
    HEATING_PLUMBING = 32,
    CONDITIONER = 64
};

bool stob(std::string s) {
    return s == "Yes" || s == "yes" || s == "On" || s == "on" || s == "y" || s =="Y";
}

void control_heating_plumbing(float tempOut, int &state) {
    if (tempOut < 0 && !(state & HEATING_PLUMBING)) {
        state |= HEATING_PLUMBING;
        std::cout << "Plumbing Heating is ON" << std::endl;
    } else
        if (tempOut > 5 && (state & HEATING_PLUMBING)) {
        state ^= HEATING_PLUMBING;
        std::cout << "Plumbing Heating os OFF" << std::endl;
    }
}

void control_light_outside(bool moveOut, int &state, bool night) {
    if (night && moveOut && !(state & LIGHT_OUTSIDE)) {
        state |= LIGHT_OUTSIDE;
        std::cout << "Light in the garden is ON" << std::endl;
    } else
        if ((state & LIGHT_OUTSIDE) && !night) {
        state ^= LIGHT_OUTSIDE;
        std::cout << "Light in the garden is OFF" << std::endl;
    }
}

void control_heating_house(float tempInside, int &state) {
    if (tempInside < 22 && !(state & HEATING_HOUSE)) {
        state |= HEATING_HOUSE;
        std::cout << "House Heating is ON" << std::endl;
    }
    else
        if ((state & HEATING_HOUSE) && tempInside >= 25) {
        state ^= HEATING_HOUSE;
        std::cout << "House Heating is OFF" << std::endl;
    }
}

void control_conditioner(float tempInside, int &state) {
    if (!(state & CONDITIONER) && tempInside >= 30) {
        state |= CONDITIONER;
        std::cout << "Conditioner is ON" << std::endl;
    } else
        if ((state & CONDITIONER) && tempInside <= 25) {
            state ^= CONDITIONER;
            std::cout << "Conditioner is OFF" << std::endl;
        }
}


void control_light_inside(bool lightIns, int state, int time, int bright) {
    if (time == 0)
        bright = 5000;
    if (!(state & LIGHT_OUTSIDE) && lightIns) {
        state |= LIGHT_INSIDE;
        std::cout << "House Light is ON" << std::endl;
    } else
        if ((state & LIGHT_INSIDE) && !lightIns) {
            std::cout << "House Light is OFF" << std::endl;
        }
    if (time >= 16 && time <= 20 && (state & LIGHT_INSIDE))
        std::cout << "Color temperature: " << bright << "K" << std::endl;
}

void task5() {
    std::string s;
    std::stringstream sensors;
    int state = 0 | POWER | SOCKETS; // turn on the sockets and the power in the house
    int brightness = 5000;
    for (int i = 0; i < 48; i++) {
        int time = i % 24;
        bool night = i % 24 > 16 || i < 5;
        std::cout << "It is " << i % 24 << " o'clock. Enter the data from sensors:" << std::endl;
        std::getline(std::cin, s);
        sensors.str(s);

        float temperatureInside, temperatureOutside;
        std::string movementOutside, lightInside;

        sensors >> temperatureInside >> temperatureOutside >> movementOutside >> lightInside;

        control_heating_plumbing(temperatureOutside, state);
        control_heating_house(temperatureInside, state);
        control_light_outside(stob(movementOutside), state, night);
        control_conditioner(temperatureInside, state);
        control_light_inside(stob(lightInside), state, time, brightness);
        sensors.clear();
    }
}
