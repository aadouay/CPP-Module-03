#include <iostream>
#include <cstring>


class Car {
private:
    char* brand;
    int year;

public:
    // 🔹 Default constructor
    Car(const char* b = "Unknown", int y = 0) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        year = y;
        std::cout << "Constructor called for " << brand << std::endl;
    }

    // 🔹 Copy constructor (Deep copy)
    Car(const Car& other) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
        year = other.year;
        std::cout << "Copy constructor called for " << brand << std::endl;
    }

    // 🔹 Destructor
    ~Car() {
        std::cout << "Destructor called for " << brand << std::endl;
        delete[] brand;
    }

    // 🔹 Display info
    void show() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

int main() {
    Car car1("Toyota", 2022);   // Constructor called
    Car car2 = car1;            // Copy constructor called (!!!)
    // Car car3(car1);             // Copy constructor called again

    car1.show();
    car2.show();
    // car3.show();

    return 0;
}

