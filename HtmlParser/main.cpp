#include "HtmlParser.h"
#include <iostream>
using namespace std;
int main()
{
	HtmlParser parser;
	cout << parser.getValueOf("fr.openclassrooms.com") << endl;
}
