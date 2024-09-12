#include <iostream>

class Building {
protected:
    int numFloors;
    int numRooms;
    double totalSquareFootage;

public:
    Building(int floors, int rooms, double sqFootage)
        : numFloors(floors), numRooms(rooms), totalSquareFootage(sqFootage) {}

    void inputData() {
        std::cout << "Enter number of floors: ";
        std::cin >> numFloors;
        std::cout << "Enter number of rooms: ";
        std::cin >> numRooms;
        std::cout << "Enter total square footage: ";
        std::cin >> totalSquareFootage;
    }

    void displayData() {
        std::cout << "Number of floors: " << numFloors << std::endl;
        std::cout << "Number of rooms: " << numRooms << std::endl;
        std::cout << "Total square footage: " << totalSquareFootage << " sq. ft" << std::endl;
    }
};

class House : public Building {
private:
    int numBedrooms;
    int numBathrooms;

public:
    House(int floors, int rooms, double sqFootage, int bedrooms, int bathrooms)
        : Building(floors, rooms, sqFootage), numBedrooms(bedrooms), numBathrooms(bathrooms) {}

    void inputData() {
        Building::inputData();
        std::cout << "Enter number of bedrooms: ";
        std::cin >> numBedrooms;
        std::cout << "Enter number of bathrooms: ";
        std::cin >> numBathrooms;
    }

    void displayData() {
        Building::displayData();
        std::cout << "Number of bedrooms: " << numBedrooms << std::endl;
        std::cout << "Number of bathrooms: " << numBathrooms << std::endl;
    }
};

class Office : public Building {
private:
    int numFireExtinguishers;
    int numTelephones;

public:
    Office(int floors, int rooms, double sqFootage, int fireExtinguishers, int telephones)
        : Building(floors, rooms, sqFootage), numFireExtinguishers(fireExtinguishers), numTelephones(telephones) {}

    void inputData() {
        Building::inputData();
        std::cout << "Enter number of fire extinguishers: ";
        std::cin >> numFireExtinguishers;
        std::cout << "Enter number of telephones: ";
        std::cin >> numTelephones;
    }

    void displayData() {
        Building::displayData();
        std::cout << "Number of fire extinguishers: " << numFireExtinguishers << std::endl;
        std::cout << "Number of telephones: " << numTelephones << std::endl;
    }
};

int main() {
    House myHouse(2, 5, 2000, 3, 2);
    Office myOffice(1, 10, 3000, 5, 20);

    std::cout << "House Data:" << std::endl;
    myHouse.inputData();
    myHouse.displayData();

    std::cout << "\nOffice Data:" << std::endl;
    myOffice.inputData();
    myOffice.displayData();

    return 0;
}