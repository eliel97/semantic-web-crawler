/*
 * Storage.h
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#ifndef STORAGE_H_
#define STORAGE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <locale>
#include <sstream>
#include "Crawler.h"
namespace std {

class Storage {
public:
	Storage();
	virtual ~Storage();
	vector<string> page;
	void checkForCacheFolder();
	void generateUrlHash(std::string url, Storage cache);
	void loadPage(Crawler Url);
};

} /* namespace std */
#endif /* STORAGE_H_ */
