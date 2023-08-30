#include <iostream>

class Spacecraft {
private:
    int x;
    int y;
    int z;
    char direction;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection)
        : x(initialX), y(initialY), z(initialZ), direction(initialDirection) {}

    void move_forward() {
        switch (direction) {
            case 'N':
                y += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'E':
                x += 1;
                break;
            case 'W':
                x -= 1;
                break;
        }
    }

    void move_backward() {
        switch (direction) {
            case 'N':
                y -= 1;
                break;
            case 'S':
                y += 1;
                break;
            case 'E':
                x -= 1;
                break;
            case 'W':
                x += 1;
                break;
        }
    }

    void turn_left() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
        }
    }

    void turn_right() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
        }
    }

    void turn_up() {
        if (direction == 'N' || direction == 'S') {
            direction = 'U';
        } else if (direction == 'U') {
            direction = 'S';
        } else if (direction == 'D') {
            direction = 'N';
        }
    }

    void turn_down() {
        if (direction == 'N' || direction == 'S') {
            direction = 'D';
        } else if (direction == 'U') {
            direction = 'N';
        } else if (direction == 'D') {
            direction = 'S';
        }
    }

    void execute_commands(const std::string& commands) {
        for (char cmd : commands) {
            switch (cmd) {
                case 'f':
                    move_forward();
                    break;
                case 'b':
                    move_backward();
                    break;
                case 'l':
                    turn_left();
                    break;
                case 'r':
                    turn_right();
                    break;
                case 'u':
                    turn_up();
                    break;
                case 'd':
                    turn_down();
                    break;
            }
        }
    }

    void print_final_state() {
        std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
        std::cout << "Final Direction: " << direction << "\n";
    }
};

int main() {
    Spacecraft spacecraft(0, 0, 0, 'N');

    std::string commands = "ffrblud";  // Example commands
    spacecraft.execute_commands(commands);

    spacecraft.print_final_state();

    return 0;
}
