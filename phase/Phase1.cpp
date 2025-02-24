#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	Reader reader = Reader("./phase/csv/Motor_Vehicle_Collisions_-_Crashes_20250210.csv");	
	Records records;
	std::string currentLine;
	while((currentLine = reader.readLine()) != "") {
		records.addRecord(records.parseRecord(currentLine));
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken: " << duration.count() << " seconds" <<std::endl;
}
