#include "userinfos.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string command = "wget https://freegeoip.net/xml";
	if (argc > 1)
		command += argv[1];
	command += " --no-check-certificate --output-document=data.xml";
	system(command.c_str());
	UserInfos infos("data.xml");
	cout << endl << endl;
	cout << "================================" << endl;
	cout << "IP : " <<  infos.getIpAddress() << endl;
	cout << "Country : " <<  infos.getCountryName() << endl;
	cout << "Region : " <<  infos.getRegionName() << endl;
	if (infos.isUserAuthorized())
		cout << "Utilisateur autorisé" << endl;
	cout << "================================" << endl;
	return 0;
}
