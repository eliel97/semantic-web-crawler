/*
 * IO.cpp
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#include "IO.h"

namespace std {

IO::IO() {
	// TODO Auto-generated constructor stub
}

IO::~IO() {
	// TODO Auto-generated destructor stub
}

void IO::processArguments(std::string inputs, Storage cache){
	if(inputs.find("SWC") != string::npos){
		//Check for application argument ./SWC
	} else if(inputs.find("http://") != string::npos || inputs.find("https://") != string::npos){
		cout << inputs << endl;
		cache.generateUrlHash(inputs,cache);
	} else {
		cout << inputs << endl;
		//parseArgument(inputs);
	}
}

} /* namespace std */
