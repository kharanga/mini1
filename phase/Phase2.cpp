#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    Reader reader("./phase/csv/Motor_Vehicle_Collisions_-_Crashes_20250210.csv");
    Records records;
    std::vector<std::string> lines;
    std::string currentLine;

    while ((currentLine = reader.readLine()) != "") {
        lines.push_back(currentLine);
    }

    int numThreads = 4;

    #pragma omp parallel for
    for (size_t i = 0; i < lines.size(); i++) {
        auto record = records.parseRecord(lines[i]);
        #pragma omp critical
        records.addRecord(record);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(endTime - startTime);
    
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
}

