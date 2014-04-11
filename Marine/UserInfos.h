#include <string>

static const int authorizedCountriesArrayLen = 1;
static const int authorizedRegionsArrayLen   = 2;

namespace {
// Si l'IP de l'utilisateur ne mène pas dans l'un de ces pays; alors rejet de la requête
std::string authorizedCountries[] = {
    std::string("France")
};

// Si l'IP de l'utilisateur ne mène pas dans l'une de ces régions; alors rejet de la requête
std::string authorizedRegions[] = { 
    std::string("Rhône-Alpes");
    std::string("Île-de-France")
};
}

namespace authentification {

void initializeDatabase();

class UserInfos
{
public:
    // Parse un xml pour récupérer infos
    UserInfos(std::string _xmlFilePath = "");
    bool parseXmlFile(std::string _xmlFilePath);
	
    // Renvoie si l'utilisateur est autorisé ou non (si IP non valide; alors non autorisé)
    bool isUserAuthorized();
	
    // Accesseurs
    std::string getIpAddress() const;
    std::string getCountryName() const;
    std::string getRegionName() const;
	
private:
    std::string ipAddress;
    std::string countryName;
    std::string regionName;
};

}
