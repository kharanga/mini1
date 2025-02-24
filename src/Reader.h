#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>

class Reader {
	private:
		std::string filename;
		std::fstream filestream;
	public:
		Reader(std::string filename);
		void close();
		std::string readLine();

		void setFilename(std::string filename) { this->filename = filename; }
		std::string getFilename() { return this->filename; }
};	

#endif 
