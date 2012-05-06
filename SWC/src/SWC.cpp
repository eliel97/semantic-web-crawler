//============================================================================
// Name        : SWC.cpp
// Author      : Michael Bastos
// Version     :
// Copyright   : This is open source software
// Description : C++ Crawler
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <locale>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
using namespace std;
void downloadUrl (const char *path, string url, string urlhash);
void loadPage(const char *p, string url, string urlhash);
void parsePage(vector<string> page);
void parseLine(string line);

int main(int argc, char *argv[])
{

	locale loc;
	const collate<char>& coll = use_facet<collate<char> >(loc);
	//cout << "There are " << argc << " arguments:" << endl;
	if(mkdir("cache",0777)==-1)//creating a directory
	{
	        //cerr<<"Caching..." <<endl;
	}

    // Loop through each argument and print its number and value
    for (int i=0; i < argc; i++){
        std::string inputs = argv[i];
        long inputhash = coll.hash(inputs.data(),inputs.data()+inputs.length());
        std::string hash;
        std::stringstream strstream;
        strstream << inputhash;
        strstream >> hash;
        string path = "cache/" + hash;
        const char *p;
        p=path.c_str();
        cout << p << endl;
        if(inputs.find("http://") != string::npos){
        	cout << i << " " << inputs << " " << inputhash << endl;
        	loadPage(p,inputs,hash);
        }
    }

    return 0;
}

void downloadUrl (const char *path, string url, string urlhash){
	std::string command = "cd cache && wget " + url + " --output-document=" + urlhash + " --continue --force-html";
	system(command.c_str());
	//cout << command << endl;
	loadPage(path,url,urlhash);
}

void loadPage(const char *path, string url, string urlhash){
	vector<string> page;
	string line;
	ifstream read (path);//reading a file
	if (read.is_open()) {
		while (! read.eof() ) {
			getline (read,line);
			page.push_back (line);
			//cout<<line<<endl;
	    }
	    read.close();
	    parsePage(page);
	} else {
		downloadUrl(path,url,urlhash);
	}
}

void parsePage(vector<string> page){
	for (vector<string>::iterator line = page.begin();line != page.end();++line)
	{
		parseLine(*line);
	}

}

void parseLine(string line){
	cout << line << endl;

}
