#include "userinfos.h"
#include <fstream>

using namespace std;

UserInfos::UserInfos(string _xmlFilePath)
{
    this->ipAddress = 
        this->countryName =
        this->regionName  = "Null";
    if (_xmlFilePath != "")
        this->parseXmlFile(_xmlFilePath);
}

bool UserInfos::parseXmlFile(string _xmlFilePath)
{
    ifstream file(_xmlFilePath.c_str());
    if (!file) return false;
    string line;
    while (getline(file, line)) // Tant qu'on n'est pas à la fin, on lit
    {
        size_t pos;
        size_t len;
        if (this->ipAddress == "Null")
        {
            string openIpAngleBracket = string("<Ip>");
            string closedIpAngleBracket = string("</Ip>");
            pos = line.find(openIpAngleBracket);
            len = line.find(closedIpAngleBracket);
            if (pos != string::npos && len != string::npos)
                this->ipAddress = line.substr(pos + openIpAngleBracket.length(), len - closedIpAngleBracket.length());
        }
        if (this->countryName == "Null")
        {
            string openCountryNameAngleBracket = string("<CountryName>");
            string closedCountryNameAngleBracket = string("</CountryName>");
            pos = line.find(openCountryAngleBracket);
            len = line.find(closedCountryAngleBracket);
            if (pos != string::npos && len != string::npos)
                this->countryName = line.substr(pos + openCountryNameAngleBracket.length(), len - closedCountryNameAngleBracket.length());
        }
        if (this->regionName == "Null")
        {
            string openRegionNameAngleBracket = string("<RegionName>");
            string closedRegionNameAngleBracket = string("</RegionName>");
            pos = line.find(openRegionNameAngleBracket);
            len = line.find(closedRegionNameAngleBracket);
            if (pos != string::npos && len != string::npos)
                this->regionName = line.substr(pos + openRegionNameAngleBracket.length(), len - closedRegionNameAngleBracket.length());
        }
    }
    return true;
}

bool UserInfos::isUserAuthorized()
{
    bool locatedInGoodCountry = false,
        locatedInGoodRegion   = false;
    for (int i = 0; i < authorizedCountriesArrayLen; i++)
        if (this->countryName == authorizedCountries[i])
            locatedInGoodCountry = true;
    for (int i = 0; i < authorizedRegionsArrayLen; i++)
        if (this->regionName == authorizedRegions[i])
            locatedInGoodRegion = true;
    return (locatedInGoodCountry && locatedInGoodRegion);
}

string UserInfos::getIpAddress() const
{
    return this->ipAddress;
}

string UserInfos::getCountryName() const
{
    return this->countryName;
}

string UserInfos::getRegionName() const
{
    return this->regionName;
}
