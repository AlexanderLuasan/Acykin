#include "xmlparser.h"
#include <string>
#include <fstream>
#include <allegro5/allegro.h>
#include <iostream>
#include <vector>
using namespace std;


xmlfile::xmlfile()
{
}

void xmlfile::setfile(const char * name)
{
	ifstream infile;
	char path[100];
	const char * here = al_get_current_directory();
	const char * filename = name;
	strcpy_s(path, 70, here);
	strcat_s(path, 70, filename);
	cout << path << endl;

	infile.open(path);
	if (!infile) {
		cout << "unable to open" << endl;
		exit(1);
	}
	string file;
	string line;
while (getline(infile, line)) {
	file = file + line + "\n";
}
//remove first line
file = file.substr(file.find(">") + 2, file.size());
content = xmltag(file);





}

void xmlfile::tagprint()
{

}

xmltag xmlfile::nav()
{
	return content;
}

xmltag::xmltag()
{
}

xmltag::xmltag(string data)
{
	//setfirst line to my name
	int blade = data.find(">");
	string tagline = data.substr(0, blade + 1);
	name = tagline;
	blade = tagline.find(" ");
	string tagtype = "</" + tagline.substr(0 + 1, blade - 1) + ">";
	//remove open and close of my tag



	string cutdata = data.substr(data.find(">") + 2, data.find(tagtype) - (data.find(">") + 2));





	//find next tag create xml object is no more tags save base data and end
	int index = 0;
	while (true) {
		blade = cutdata.find(">");
		if (blade != string::npos) {
			tagline = cutdata.substr(0, blade + 1);
			while (true) {
				if ((tagline[0] == ' ') | (tagline[0] == '\n')) {
					tagline = tagline.substr(1, tagline.size() - 1);
				}
				else {
					break;
				}
			}
			blade = tagline.find(" ");
			tagtype = "</" + tagline.substr(0 + 1, blade - 1) + ">";

			blade = cutdata.find(tagtype);


			if (blade != string::npos) {
				xmltag newtag(cutdata.substr(0, cutdata.find(tagtype) + tagtype.size()));
				values.push_back(newtag);
				keys.push_back(newtag.getname());
				cutdata = cutdata.substr(cutdata.find(tagtype) + tagtype.size(), cutdata.size() - cutdata.find(tagtype) - tagtype.size());
			}
			else {
				leftover = cutdata;
				break;
			}
			//makenewtag

			//get it to tell me its name
			//setup key value relation
		}
		else {
			leftover = cutdata;
			break;
		}
	}



	//repeat to end of file




}

string xmltag::getname()
{

	int blade;
	string end;
	blade = name.find("name=");
	if (blade != string::npos) {
		end = name.substr(blade + 6, 15);
		blade = end.find('"');
		if (blade != string::npos){
			end = end.substr(0, blade);

			return end;
		}
		
	}
	else {
		blade = name.find("<")+1;
		end = name.substr(blade, name.size() - blade);
		blade = end.find(" ");
		end = end.substr(0, blade);
		return end;
	}

	return name;
}

string xmltag::getleftover()
{
	return leftover;
}

xmltag xmltag::get(string name)
{
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == name) {
			return values[i];
		}
	}
}
