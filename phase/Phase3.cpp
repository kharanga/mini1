#include "../src/Reader.h" 
#include "../src/Records.h"
#include "../src/RecordVector.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <sstream>
#include <omp.h>

int intAttribute(const std::string& attribute) {
    int missingInt = -1;
    try {
        if (attribute.empty() || attribute.find_first_not_of(" \t\r\n") == std::string::npos) {
            return missingInt;
        }
        return std::stoi(attribute);
    } catch (const std::invalid_argument&) {
        return missingInt;
    }
}

double dblAttribute(const std::string& attribute) {
    double missingDbl = -1.0;
    try {
        if (attribute.empty() || attribute.find_first_not_of(" \t\r\n") == std::string::npos) {
            return missingDbl;
        }
        return std::stod(attribute);
    } catch(const std::invalid_argument&) {
        return missingDbl;
    }
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    Reader reader("./phase/csv/Motor_Vehicle_Collisions_-_Crashes_20250210.csv");
    std::vector<std::string> lines;
    std::string currentLine;
    while ((currentLine = reader.readLine()) != "") {
        lines.push_back(currentLine);
    }
    Records records;
    RecordVector recordsVector;
    recordsVector.crashDate.resize(lines.size());
    recordsVector.crashTime.resize(lines.size());
    recordsVector.borough.resize(lines.size());
    recordsVector.zipCode.resize(lines.size());
    recordsVector.latitude.resize(lines.size());
    recordsVector.longitude.resize(lines.size());
    recordsVector.location.resize(lines.size());
    recordsVector.onStreeName.resize(lines.size());
    recordsVector.crossStreetName.resize(lines.size());
    recordsVector.offStreetName.resize(lines.size());
    recordsVector.numberOfPersonInjured.resize(lines.size());
    recordsVector.numberOfPersonKilled.resize(lines.size());
    recordsVector.numberOfPedestrianInjured.resize(lines.size());
    recordsVector.numberOfPedestrianKilled.resize(lines.size());
    recordsVector.numberOfCyclistInjured.resize(lines.size());
    recordsVector.numberOfCyclistKilled.resize(lines.size());
    recordsVector.numberOfMotoristInjured.resize(lines.size());
    recordsVector.numberOfMotoristKilled.resize(lines.size());
    recordsVector.contributingFactorVehicle1.resize(lines.size());
    recordsVector.contributingFactorVehicle2.resize(lines.size());
    recordsVector.contributingFactorVehicle3.resize(lines.size());
    recordsVector.contributingFactorVehicle4.resize(lines.size());
    recordsVector.contributingFactorVehicle5.resize(lines.size());
    recordsVector.collisonId.resize(lines.size());
    recordsVector.vehicleTypeCode1.resize(lines.size());
    recordsVector.vehicleTypeCode2.resize(lines.size());
    recordsVector.vehicleTypeCode3.resize(lines.size());
    recordsVector.vehicleTypeCode4.resize(lines.size());
    recordsVector.vehicleTypeCode5.resize(lines.size());

    #pragma omp parallel for      
    for (size_t i = 0; i < lines.size(); i++) {
        auto parsedRecord = records.parseRecord(lines[i]);
        #pragma omp critical
        recordsVector.crashDate[i] = parsedRecord[0];
        recordsVector.crashTime[i] = parsedRecord[1];
        recordsVector.borough[i] = parsedRecord[2];
        recordsVector.zipCode[i] = intAttribute(parsedRecord[3]);
        recordsVector.latitude[i] = dblAttribute(parsedRecord[4]);
        recordsVector.longitude[i] = dblAttribute(parsedRecord[5]);
        recordsVector.location[i] = parsedRecord[6];
        recordsVector.onStreeName[i] = parsedRecord[7];
        recordsVector.crossStreetName[i] = parsedRecord[8];
        recordsVector.offStreetName[i] = parsedRecord[9];
        recordsVector.numberOfPersonInjured[i] = intAttribute(parsedRecord[10]);
        recordsVector.numberOfPersonKilled[i] = intAttribute(parsedRecord[11]);
        recordsVector.numberOfPedestrianInjured[i] = intAttribute(parsedRecord[12]);
        recordsVector.numberOfPedestrianKilled[i] = intAttribute(parsedRecord[13]);
        recordsVector.numberOfCyclistInjured[i] = intAttribute(parsedRecord[14]);
        recordsVector.numberOfCyclistKilled[i] = intAttribute(parsedRecord[15]);
        recordsVector.numberOfMotoristInjured[i] = intAttribute(parsedRecord[16]);
        recordsVector.numberOfMotoristKilled[i] = intAttribute(parsedRecord[17]);
        recordsVector.contributingFactorVehicle1[i] = parsedRecord[18];
        recordsVector.contributingFactorVehicle2[i] = parsedRecord[19];
        recordsVector.contributingFactorVehicle3[i] = parsedRecord[20];
        recordsVector.contributingFactorVehicle4[i] = parsedRecord[21];
        recordsVector.contributingFactorVehicle5[i] = parsedRecord[22];
        recordsVector.collisonId[i] = intAttribute(parsedRecord[23]);
        recordsVector.vehicleTypeCode1[i] = parsedRecord[24];
        recordsVector.vehicleTypeCode2[i] = parsedRecord[25];
        recordsVector.vehicleTypeCode3[i] = parsedRecord[26];
        recordsVector.vehicleTypeCode4[i] = parsedRecord[27];
        recordsVector.vehicleTypeCode5[i] = parsedRecord[28];
    }
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(endTime - startTime);
    
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
}