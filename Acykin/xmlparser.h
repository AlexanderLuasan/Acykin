#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;


class xmltag
{
public:
	xmltag();
	xmltag(vector<string> data);
	string getname();
	string getleftover();
	xmltag get(string name);
	string head(string name);
	void options();
	int getendindex();

private:
	vector<string> keys;
	vector<xmltag> values;
	map<string, string> content;
	vector<string> ckeys;
	string leadingline;
	string tagtype;
	string raw;
	int endindex;
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
