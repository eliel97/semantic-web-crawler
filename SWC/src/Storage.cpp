/*
 * Storage.cpp
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#include "Storage.h"

namespace std {

Storage::Storage() {
	// TODO Auto-generated constructor stub

}

Storage::~Storage() {
	// TODO Auto-generated destructor stub
}

void Storage::checkForCacheFolder(){
	if(mkdir("cache",0777)==-1)//creating a directory
		{
		        //cerr<<"Caching..." <<endl;
		}
}

} /* namespace std */
