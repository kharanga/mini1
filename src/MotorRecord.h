#ifndef MOTORRECORD_H
#define MOTORRECORD_H

#include <iostream>

struct MotorRecord {
	std::string crashDate;			
	std::string crashTime;
	std::string borough;
	int zipCode;
	double latitude;
	double longitude;
	std::string location;	
	std::string onStreeName;
	std::string crossStreetName;
	std::string offStreetName;
	int numberOfPersonInjured;
	int numberOfPersonKilled;
	int numberOfPedestrianInjured;
	int numberOfPedestrianKilled;
	int numberOfCyclistInjured;
	int numberOfCyclistKilled;
	int numberOfMotoristInjured;
	int numberOfMotoristKilled;
	std::string contributingFactorVehicle1;
	std::string contributingFactorVehicle2;
	std::string contributingFactorVehicle3;
	std::string contributingFactorVehicle4;
	std::string contributingFactorVehicle5;
	int collisonId;
	std::string vehicleTypeCode1;
	std::string vehicleTypeCode2;
	std::string vehicleTypeCode3;
	std::string vehicleTypeCode4;
	std::string vehicleTypeCode5;
};



#endif
