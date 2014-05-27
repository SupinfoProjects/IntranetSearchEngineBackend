#include "UserInfos.h"
#include <fstream>

using namespace std;

UserInfos::UserInfos(string _xmlFilePath)
{
    ipAddress = 
        countryName =
        regionName  = "Null";
    if (_xmlFilePath != "")
    {
        parseXmlFile(_xmlFilePath);
    }
}

bool UserInfos::parseXmlFile(string _xmlFilePath)
{
    ifstream file(_xmlFilePath.c_str());
    if (!file)
    {
        return false;
    }
    string line;
    while (getline(file, line)) // Tant qu'on n'est pas à la fin, on lit
    {
        size_t pos;
        size_t len;
        if (ipAddress == "Null")
        {
            string openIpAngleBracket = string("<Ip>");
            string closedIpAngleBracket = string("</Ip>");
            pos = line.find(openIpAngleBracket);
            len = line.find(closedIpAngleBracket);
            if (pos != string::npos && len != string::npos)
            {
                ipAddress = line.substr(pos + openIpAngleBracket.length(), len - closedIpAngleBracket.length());
            }
        }
        if (countryName == "Null")
        {
            string openCountryNameAngleBracket = string("<CountryName>");
            string closedCountryNameAngleBracket = string("</CountryName>");
            pos = line.find(openCountryNameAngleBracket);
            len = line.find(closedCountryNameAngleBracket);
            if (pos != string::npos && len != string::npos)
            {
                countryName = line.substr(pos + openCountryNameAngleBracket.length(), len - closedCountryNameAngleBracket.length());
            }
        }
        if (regionName == "Null")
        {
            string openRegionNameAngleBracket = string("<RegionName>");
            string closedRegionNameAngleBracket = string("</RegionName>");
            pos = line.find(openRegionNameAngleBracket);
            len = line.find(closedRegionNameAngleBracket);
            if (pos != string::npos && len != string::npos)
            {
                regionName = line.substr(pos + openRegionNameAngleBracket.length(), len - closedRegionNameAngleBracket.length());
            }
        }
    }
    return true;
}

bool UserInfos::isUserAuthorized()
{
    bool locatedInGoodCountry = false,
         locatedInGoodRegion  = false;
    for (auto country : authorizedCountries)
    {
        if (countryName == country)
        {
            locatedInGoodCountry = true;
        }
    }
    for (auto region : authorizedRegions)
    {
        if (regionName == region)
        {
            locatedInGoodRegion = true;
        }
    }
    return (locatedInGoodCountry && locatedInGoodRegion);
}

string UserInfos::getIpAddress() const
{
    return ipAddress;
}

string UserInfos::getCountryName() const
{
    return countryName;
}

string UserInfos::getRegionName() const
{
    return regionName;
}
