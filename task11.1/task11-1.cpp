#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream inputFile("price.dat");
    std::ofstream outputFile("Output.dat");

    if (!inputFile) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cout << "Failed to create output file." << std::endl;
        return 1;
    }

    int numRecords;
    inputFile >> numRecords;

    double price, sum = 0, maxPrice = 0, minPrice = 0;
    bool isFirstRecord = true;

    for (int i = 0; i < numRecords; ++i) {
        int id;
        inputFile >> id >> price;

        if (isFirstRecord) {
            maxPrice = price;
            minPrice = price;
            isFirstRecord = false;
        }
        else {
            if (price > maxPrice)
                maxPrice = price;
            if (price < minPrice)
                minPrice = price;
        }

        sum += price;
    }

    double averagePrice = sum / numRecords;

    outputFile << "Number of price readings: " << numRecords << std::endl;
    outputFile << "Maximum price: " << std::fixed << std::setprecision(2) << maxPrice << std::endl;
    outputFile << "Minimum price: " << std::fixed << std::setprecision(2) << minPrice << std::endl;
    outputFile << "Average price: " << std::fixed << std::setprecision(2) << averagePrice << std::endl;

    std::cout << "Summary report saved to 'Output.dat'." << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
