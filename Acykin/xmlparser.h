#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;


class xmltag
{
public:
	xmltag();
	xmltag(string data);
	string getname();
	string getleftover();
	xmltag get(string name);

private:
	vector<string> keys;
	vector<xmltag> values;
	map<string, string> content;
	string leftover;
	string name;
};


class xmlfile
{
public:
	xmlfile();
	void setfile(const char * name);
	void tagprint();
	xmltag nav();

private:
	const char * name;
	xmltag content;
};
