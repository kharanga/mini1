#include <stdexcept>
#include "Reader.h"

Reader::Reader(std::string filename) {
	this->filename = filename;
	this->filestream.open(this->getFilename());
	if(!this->filestream.is_open()){ 
	throw std::runtime_error("Runtime Exception: Unable to open file: " + this->getFilename());	
	}
	std::string throwAway;
	getline(this->filestream, throwAway);
}

void Reader::close() {
	this->filestream.close();
}

std::string Reader::readLine() {
	std::string line;
	if (getline(this->filestream, line)) {
		return line;	
	} 
	return "";
}

