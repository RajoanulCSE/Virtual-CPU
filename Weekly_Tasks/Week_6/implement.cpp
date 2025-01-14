#include <iostream>
using namespace std;

// InputDevice class for input
class InputDevice {
public:
    int readData() {
        int inputData;
        cout << "Enter a number (InputDevice): ";
        cin >> inputData;
        return inputData;
    }
};

// OutputDevice class for output
class OutputDevice {
public:
    void printData(int outputData) {
        cout << "OutputDevice: " << outputData << endl;
    }
};

// Storage class for storing data
class Storage {
private:
    int storage[10]; // Small fixed-size storage

public:
    Storage() {
        for (int i = 0; i < 10; i++) storage[i] = 0;
    }

    void store(int location, int value) {
        if (location >= 0 && location < 10) {
            storage[location] = value;
            cout << "Storage Write: Location " << location << " = " << value << endl;
        } else {
            cout << "Error: Location out of bounds!" << endl;
        }
    }

    int fetch(int location) {
        if (location >= 0 && location < 10) {
            cout << "Storage Read: Location " << location << " = " << storage[location] << endl;
            return storage[location];
        } else {
            cout << "Error: Location out of bounds!" << endl;
            return -1;
        }
    }
};

// Processor class to control everything
class Processor {
private:
    Storage storage;
    InputDevice inputDevice;
    OutputDevice outputDevice;

public:
    void execute() {
        cout << "Processor Test Program Starting...\n";

        // Get data from InputDevice and store in Storage
        int data = inputDevice.readData();
        storage.store(0, data); // Store at location 0

        // Fetch from Storage and send to OutputDevice
        int result = storage.fetch(0);
        outputDevice.printData(result);

        cout << "Processor Test Program Completed.\n";
    }
};

int main() {
    Processor processor;
    processor.execute();
    return 0;
}
