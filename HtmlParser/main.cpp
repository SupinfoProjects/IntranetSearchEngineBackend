#include "HtmlParser.h"
#include <iostream>
using namespace std;
int main()
{
	HtmlParser parser;
	vector<string> v;
	v.push_back("prout");
	v.push_back("cours");
	cout << parser.getValueOf("fr.openclassrooms.com", v) << endl;
}
