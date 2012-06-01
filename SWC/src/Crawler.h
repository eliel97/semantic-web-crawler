/*
 * Crawler.h
 *
 *  Created on: May 5, 2012
 *      Author: michael
 */

#ifndef CRAWLER_H_
#define CRAWLER_H_
#include <iostream>
#include <cstdlib>

namespace std {

class Crawler {
public:
	Crawler();
	virtual ~Crawler();
	const char *path;
	string url;
	string urlhash;
	void downloadUrl (Crawler *Url);
};

} /* namespace std */
#endif /* CRAWLER_H_ */
