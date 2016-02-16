#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stdlib.h>
#include<Windows.h>
#include<urlmon.h>
#include<fstream>
#include<regex>


int main()
{


	string url = "http://web.cs.wpi.edu/~matt/courses/cs563/talks/powwie/p2/decimate.htm";
	string n1 = url.substr(0, url.find_first_of("//")+2);
	string n2 = url.substr(url.find_first_of("//") + 2);
	string n3 = n2.substr(0, n2.find_first_of("/"));
	string domain = n1 + n3;

	cout << domain << endl;
	

	return 0;
}
