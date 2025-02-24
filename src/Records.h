#ifndef RECORDS_H 
#define RECORDS_H

#include <iostream>
#include <vector>
#include "MotorRecord.h"

class Records{
	private:
		std::vector<MotorRecord> records;
	public:
		std::vector<std::string> parseRecord(std::string record);
		void addRecord(std::vector<std::string> recordAttributes);
		MotorRecord getRecords(int index);

};

#endif
