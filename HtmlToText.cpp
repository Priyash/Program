#include<iostream>
#include<string>
#include<algorithm>
#include<regex>
#include<fstream>

using namespace std;

vector<string>v;
void findText(string s)
{
	smatch sm;
	string exp = ">([^<]*.?)<";
	regex e(exp);
	int index = 1;
	while (regex_search(s, sm, e))
	{
		
		for (auto x : sm)
		{
			if (index % 2 == 0 && x.length()!=0)
			{
				cout << x << endl;
				v.push_back(x);
			}
			index++;
		}
		s = sm.suffix().str();
	}
}

void dumpData()
{
	ofstream writer;
	string _path = "\\HTML\\";
	string file = "out.txt";
	string path = _path + file;
	writer.open(path.c_str(), ios::out);
	for (auto i : v)
	{
		writer << i << endl;
	}
}

void loadFile()
{
	ifstream reader;
	string _path = "\\HTML\\";
	string file = "page.html";
	string path = _path + file;
	reader.open(path.c_str(), ios::in);
	string line = "";
	while (getline(reader, line))
	{
		findText(line);
	}

	line.clear();
	reader.clear();
	reader.close();
}

int main()
{
	loadFile();
	dumpData();

	return 0;
}
