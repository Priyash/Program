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


#pragma comment(lib,"urlmon.lib")
using namespace std;


class Node
{
	vector<Node*>children;
	Node* parent;
public :
	Node()
	{

	}

	vector<Node*>getChildren(){ return children; }
	void add(Node*);
	void extractURL(string path);
};


void Node::extractURL(string path)
{
	ifstream reader;
	reader.open(path, ios::in);
	string line;
	while (getline(reader, line))
	{
		
	}
}





int main()
{

	//Node* node = new Node();
	////node->extractURL("C:\\Users\\PRIYASH_11\\Desktop\\Test_Download\\index.html");
	////string url = "href=\"www.google.com\" content=\"image.png\" href=\"https://www.facebook.com/\""";
	////string url = "<link rel=\"canonical\" href=\"https://www.facebook.com/\"/>";
	//string url = "<link rel=\"alternate\" hreflang=\"fr\" href=\"https://fr-fr.facebook.com/\" />";
	//vector<string>urls;
	//for (int i = 0; i < url.size(); i++)
	//{
	//	if (url[i] == '='&&(url[i+2]=='h'||url[i+2]=='w'))
	//	{
 //    		int k = 2;
	//		string word = "";
	//		int index = i + k;
	//		while (url[index] != '\"')
	//		{
	//			word += url[index];
	//			index++;
	//		}
	//		urls.push_back(word);

	//	}
	//}


	//for (auto i : urls)
	//{
	//	cout << i << endl;
	//}
    
	string url = "http://web.cs.wpi.edu/~matt/courses/cs563/talks/powwie/p2/decimate.htm";

	/*size_t n1 = url.find_last_of(".")+1;
	int i = n1;
	while (url[i] != '/')
	{
		i++;
	}
	
	string domain = url.substr(0, i);

	cout << domain << endl;*/

	string n1 = url.substr(0, url.find_first_of("//")+2);
	string n2 = url.substr(url.find_first_of("//") + 2);
	string n3 = n2.substr(0, n2.find_first_of("/"));
	string domain = n1 + n3;

	cout << domain << endl;
	

	return 0;
}
