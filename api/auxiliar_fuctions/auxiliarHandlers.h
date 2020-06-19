#include "../api/src/api.h"
#include "Base64Handle.h"
#include "json.hpp"
#include <string>
#include <iomanip>

using json = nlohmann::json;

std::string encodeText(std::string text) {
  std::string encodedData = base64_encode(reinterpret_cast<const unsigned char*>(text.c_str()), text.length());

  return encodedData;
}

std::string decodeText(std::string base64) {
  std::string text;
  std::vector<unsigned char> decodedData = base64_decode(base64);

  for (char c: decodedData)
		text.push_back(c);

  return text;
}

Config setDefaultIcons (Config config) {
    config.messagesGeneral.IOError.icon     = "default_icons/sad.svg";
    config.messagesGeneral.serverError.icon = "default_icons/sad.svg";
    config.messagesGeneral.tryConnect.icon  = "default_icons/waitTicket.svg";
    config.messagesGeneral.testIO.icon      = "default_icons/info.svg";


    config.messagesEntry.clearedToGo.icon    = "default_icons/thumbsUp.svg";
    config.messagesEntry.empty.icon          = "default_icons/info.svg";
    config.messagesEntry.invalid.icon        = "default_icons/sad.svg";
    config.messagesEntry.pressButton.icon    = "default_icons/thumbsUp.svg";
    config.messagesEntry.removeTicket.icon   = "default_icons/info.svg";
    config.messagesEntry.validateTicket.icon = "default_icons/waitTicket.svg";
    config.messagesEntry.welcome.icon        = "default_icons/happy.svg";
    config.messagesEntry.parkingFull.icon    = "default_icons/info.svg";

    config.messagesExit.clearedToGo.icon        = "default_icons/thumbsUp.svg";
    config.messagesExit.empty.icon              = "default_icons/info.svg";
    config.messagesExit.errorReadingCard.icon   = "default_icons/info.svg";
    config.messagesExit.goToAdministration.icon = "default_icons/sad.svg";
    config.messagesExit.insertCard.icon         = "default_icons/happy.svg";
    config.messagesExit.nonAuthorized.icon      = "default_icons/thumbsDown.svg";
    config.messagesExit.validateTicket.icon     = "default_icons/sad.svg";
    config.messagesExit.vehicleDoesntMatch.icon = "default_icons/info.svg";

    return config;
}

Config savePersonalizedIcons(Config config) {
    config.messagesGeneral.IOError.icon     = saveImage(config.messagesGeneral.IOError.icon,     "personalized_icons/general/", "IOError");
    config.messagesGeneral.serverError.icon = saveImage(config.messagesGeneral.serverError.icon, "personalized_icons/general/", "serverError");
    config.messagesGeneral.tryConnect.icon  = saveImage(config.messagesGeneral.tryConnect.icon,  "personalized_icons/general/", "tryConnect");
    config.messagesGeneral.testIO.icon      = saveImage(config.messagesGeneral.testIO.icon,      "personalized_icons/general/", "testIO");

    config.messagesEntry.clearedToGo.icon    = saveImage(config.messagesEntry.clearedToGo.icon,    "personalized_icons/entry/", "clearedToGo");
    config.messagesEntry.empty.icon          = saveImage(config.messagesEntry.empty.icon,          "personalized_icons/entry/", "empty");
    config.messagesEntry.invalid.icon        = saveImage(config.messagesEntry.invalid.icon,        "personalized_icons/entry/", "invalid");
    config.messagesEntry.pressButton.icon    = saveImage(config.messagesEntry.pressButton.icon,    "personalized_icons/entry/", "pressButton");
    config.messagesEntry.removeTicket.icon   = saveImage(config.messagesEntry.removeTicket.icon,   "personalized_icons/entry/", "removeTicket");
    config.messagesEntry.validateTicket.icon = saveImage(config.messagesEntry.validateTicket.icon, "personalized_icons/entry/", "validateTicket");
    config.messagesEntry.welcome.icon        = saveImage(config.messagesEntry.welcome.icon,        "personalized_icons/entry/", "welcome");
    config.messagesEntry.parkingFull.icon    = saveImage(config.messagesEntry.parkingFull.icon,    "personalized_icons/entry/", "parkingFull");

    config.messagesExit.clearedToGo.icon        = saveImage(config.messagesExit.clearedToGo.icon,        "personalized_icons/exit/", "clearedToGo");
    config.messagesExit.empty.icon              = saveImage(config.messagesExit.empty.icon,              "personalized_icons/exit/", "empty");
    config.messagesExit.errorReadingCard.icon   = saveImage(config.messagesExit.errorReadingCard.icon,   "personalized_icons/exit/", "errorReadingCard");
    config.messagesExit.goToAdministration.icon = saveImage(config.messagesExit.goToAdministration.icon, "personalized_icons/exit/", "goToAdministration");
    config.messagesExit.insertCard.icon         = saveImage(config.messagesExit.insertCard.icon,         "personalized_icons/exit/", "insertCard");
    config.messagesExit.nonAuthorized.icon      = saveImage(config.messagesExit.nonAuthorized.icon,      "personalized_icons/exit/", "nonAuthorized");
    config.messagesExit.validateTicket.icon     = saveImage(config.messagesExit.validateTicket.icon,     "personalized_icons/exit/", "validateTicket");
    config.messagesExit.vehicleDoesntMatch.icon = saveImage(config.messagesExit.vehicleDoesntMatch.icon, "personalized_icons/exit/", "vehicleDoesntMatch");

    return config;
}

Config saveAds(Config config) {

    if(!config.adOne.empty()) {
        config.adOne = saveImage(config.adOne, "ad_images/", "1");
    }

    if(!config.adTwo.empty()) {
        config.adTwo = saveImage(config.adTwo, "ad_images/", "2");
    }

    if(!config.adThree.empty()) {
        config.adThree = saveImage(config.adThree, "ad_images/", "3");
    }

    if(!config.adFour.empty()) {
        config.adFour = saveImage(config.adFour, "ad_images/", "4");
    }

    if(!config.adFive.empty()) {
        config.adFive = saveImage(config.adFive, "ad_images/", "5");
    }

    if(!config.adSix.empty()) {
        config.adSix = saveImage(config.adSix, "ad_images/", "6");
    }

    if(!config.adSeven.empty()) {
        config.adSeven = saveImage(config.adSeven, "ad_images/", "7");
    }

    if(!config.adEight.empty()) {
        config.adEight = saveImage(config.adEight, "ad_images/", "8");
    }

    if(!config.adNine.empty()) {
        config.adNine = saveImage(config.adNine, "ad_images/", "9");
    }

    if(!config.adTen.empty()) {
        config.adTen = saveImage(config.adTen, "ad_images/", "10");
    }
   
    return config;
}

Config saveTexts(Config config) {
    config.messagesGeneral.IOError.text     = decodeText(config.messagesGeneral.IOError.text);
    config.messagesGeneral.serverError.text = decodeText(config.messagesGeneral.serverError.text);
    config.messagesGeneral.tryConnect.text  = decodeText(config.messagesGeneral.tryConnect.text);
    config.messagesGeneral.testIO.text      = decodeText(config.messagesGeneral.testIO.text);

    config.messagesEntry.clearedToGo.text    = decodeText(config.messagesEntry.clearedToGo.text);
    config.messagesEntry.empty.text          = decodeText(config.messagesEntry.empty.text);     
    config.messagesEntry.invalid.text        = decodeText(config.messagesEntry.invalid.text);
    config.messagesEntry.pressButton.text    = decodeText(config.messagesEntry.pressButton.text);
    config.messagesEntry.removeTicket.text   = decodeText(config.messagesEntry.removeTicket.text);
    config.messagesEntry.validateTicket.text = decodeText(config.messagesEntry.validateTicket.text);
    config.messagesEntry.welcome.text        = decodeText(config.messagesEntry.welcome.text);
    config.messagesEntry.parkingFull.text    = decodeText(config.messagesEntry.parkingFull.text);

    config.messagesExit.clearedToGo.text        = decodeText(config.messagesExit.clearedToGo.text);
    config.messagesExit.empty.text              = decodeText(config.messagesExit.empty.text);
    config.messagesExit.errorReadingCard.text   = decodeText(config.messagesExit.errorReadingCard.text);
    config.messagesExit.goToAdministration.text = decodeText(config.messagesExit.goToAdministration.text);
    config.messagesExit.insertCard.text         = decodeText(config.messagesExit.insertCard.text);
    config.messagesExit.nonAuthorized.text      = decodeText(config.messagesExit.nonAuthorized.text);
    config.messagesExit.validateTicket.text     = decodeText(config.messagesExit.validateTicket.text);
    config.messagesExit.vehicleDoesntMatch.text = decodeText(config.messagesExit.vehicleDoesntMatch.text);

    return config;
}

bool compare_strings(std::string s1, std::string s2) {
    if((s1.compare(s2)) == 0) {
        return true;
    }

    return false;
}

void save_config(Config newConfig) {
    json j = {
        {"type",                          newConfig.type},
		{"clientCode",                    newConfig.clientCode},
		{"address",                       newConfig.address},
		{"interphoneIP",                  newConfig.interphoneIP},
		{"mensalistType",                 newConfig.mensalistType},
		{"personalizedMensalistCardCode", newConfig.personalizedMensalistCardCode},
		{"codeCardFormat",                newConfig.codeCardFormat},
		{"paperSensor",                   newConfig.paperSensor},
		{"openedGateSensor",              newConfig.openedGateSensor},
		{"closedGateSensor",              newConfig.closedGateSensor},
		{"automaticCarCharging",          newConfig.automaticCarCharging},
		{"automaticMotoCharging",         newConfig.automaticMotoCharging},
		{"activateEquipment",             newConfig.activateEquipment},
		{"fullCourtyard",                 newConfig.fullCourtyard},
		{"accessControl",                 newConfig.accessControl},
		{"expansionPort",                 newConfig.expansionPort},
		{"rfidPort",                      newConfig.rfidPort},
		{"barcodePort",                   newConfig.barcodePort},
		{"printerPort",                   newConfig.printerPort},
		{"useDefaultIcons",               newConfig.useDefaultIcons},
		
		{"adCount", newConfig.adCount},
		{"adOne",   newConfig.adOne},
		{"adTwo",   newConfig.adTwo},
		{"adThree", newConfig.adThree},
		{"adFour",  newConfig.adFour},
		{"adFive",  newConfig.adFive},
		{"adSix",   newConfig.adSix},
		{"adSeven", newConfig.adSeven},
		{"adEight", newConfig.adEight},
		{"adNine",  newConfig.adNine},
		{"adTen",   newConfig.adTen},
        
        {"messagesGeneral", 
            {
                {"IOError", 
                    {
                        {"icon", newConfig.messagesGeneral.IOError.icon},
                        {"text", newConfig.messagesGeneral.IOError.text},
                    }
                },
                {"serverError", 
                    {
                        {"icon", newConfig.messagesGeneral.serverError.icon},
                        {"text", newConfig.messagesGeneral.serverError.text},
                    }
                },
                {"tryConnect", 
                    {
                        {"icon", newConfig.messagesGeneral.tryConnect.icon},
                        {"text", newConfig.messagesGeneral.tryConnect.text},
                    }
                },
                {"testIO", 
                    {
                        {"icon", newConfig.messagesGeneral.testIO.icon},
                        {"text", newConfig.messagesGeneral.testIO.text},
                    }
                },
            }
        },

        {"messagesEntry", 
            {
                {"clearedToGo", 
                    {
                        {"icon", newConfig.messagesEntry.clearedToGo.icon},
                        {"text", newConfig.messagesEntry.clearedToGo.text},
                    }
                },
                {"empty", 
                    {
                        {"icon", newConfig.messagesEntry.empty.icon},
                        {"text", newConfig.messagesEntry.empty.text},
                    }
                },
                {"invalid", 
                    {
                        {"icon", newConfig.messagesEntry.invalid.icon},
                        {"text", newConfig.messagesEntry.invalid.text},
                    }
                },
                {"pressButton", 
                    {
                        {"icon", newConfig.messagesEntry.pressButton.icon},
                        {"text", newConfig.messagesEntry.pressButton.text},
                    }
                },
                {"removeTicket", 
                    {
                        {"icon", newConfig.messagesEntry.removeTicket.icon},
                        {"text", newConfig.messagesEntry.removeTicket.text},
                    }
                },
                {"validateTicket", 
                    {
                        {"icon", newConfig.messagesEntry.validateTicket.icon},
                        {"text", newConfig.messagesEntry.validateTicket.text},
                    }
                },
                {"welcome", 
                    {
                        {"icon", newConfig.messagesEntry.welcome.icon},
                        {"text", newConfig.messagesEntry.welcome.text},
                    }
                },
                {"parkingFull", 
                    {
                        {"icon", newConfig.messagesEntry.parkingFull.icon},
                        {"text", newConfig.messagesEntry.parkingFull.text},
                    }
                },
            }
        },

        {"messagesExit", 
            {
                {"clearedToGo", 
                    {
                        {"icon", newConfig.messagesExit.clearedToGo.icon},
                        {"text", newConfig.messagesExit.clearedToGo.text},
                    }
                },
                {"empty", 
                    {
                        {"icon", newConfig.messagesExit.empty.icon},
                        {"text", newConfig.messagesExit.empty.text},
                    }
                },
                {"errorReadingCard", 
                    {
                        {"icon", newConfig.messagesExit.errorReadingCard.icon},
                        {"text", newConfig.messagesExit.errorReadingCard.text},
                    }
                },
                {"goToAdministration", 
                    {
                        {"icon", newConfig.messagesExit.goToAdministration.icon},
                        {"text", newConfig.messagesExit.goToAdministration.text},
                    }
                },
                {"insertCard", 
                    {
                        {"icon", newConfig.messagesExit.insertCard.icon},
                        {"text", newConfig.messagesExit.insertCard.text},
                    }
                },
                {"nonAuthorized", 
                    {
                        {"icon", newConfig.messagesExit.nonAuthorized.icon},
                        {"text", newConfig.messagesExit.nonAuthorized.text},
                    }
                },
                {"validateTicket", 
                    {
                        {"icon", newConfig.messagesExit.validateTicket.icon},
                        {"text", newConfig.messagesExit.validateTicket.text},
                    }
                },
                {"vehicleDoesntMatch", 
                    {
                        {"icon", newConfig.messagesExit.vehicleDoesntMatch.icon},
                        {"text", newConfig.messagesExit.vehicleDoesntMatch.text},
                    }
                },
            }
        },
    };

    std::ofstream configFile("../configuration.json");
    configFile << std::setw(4) << j << std::endl;
}

void save_token(std::string token) {
    json j = {
        {"token", token}
    };

    std::ofstream tokenFile("login/src/token.json");
    tokenFile << std::setw(4) << j << std::endl;
}

std::string get_token() {
    std::ifstream tokenFile ("login/src/token.json");
    json tokenJson;
    tokenFile >> tokenJson;

    return tokenJson["token"];
}

std::string generate_token(const int len) {
    std::string token;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        token.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
    }

    save_token(token);
    return token;
}

bool verify_token(std::string token) {
    std::ifstream tokenFile ("login/src/token.json");
    json tokenJson;
    tokenFile >> tokenJson;

    bool isValid = compare_strings(tokenJson["token"], token);
    return isValid;
}

std::string image_to_base64(std::string path) {
    std::string image_str = image_to_string(path);

    std::size_t image_type_initial = path.find('.');
    std::string image_type = path.substr(image_type_initial + 1, path.length());

    if (compare_strings("svg", image_type)) {
        image_type = "svg+xml";
    }
    
    std::string base64_img = encodeText(image_str);
    std::string base64_data = "data:image/" + image_type + ";base64," + base64_img; 

    if (compare_strings("", base64_img)) {
        base64_data = ""; 
    }

    return base64_data;
}

Config configJson_to_base64() {
    std::ifstream configFile ("../configuration.json");
    json j;
    configFile >> j;

    Config config = {
        j["type"],
        j["clientCode"],
        j["address"],
        j["interphoneIP"],
        j["mensalistType"],
        j["personalizedMensalistCardCode"],
        j["codeCardFormat"],
        j["paperSensor"],
		j["openedGateSensor"],
		j["closedGateSensor"],
		j["automaticCarCharging"],
		j["automaticMotoCharging"],
		j["activateEquipment"],
		j["fullCourtyard"],
		j["accessControl"],
		j["expansionPort"],
		j["rfidPort"],
		j["barcodePort"],
		j["printerPort"],
		j["useDefaultIcons"],

        j["adCount"],
        image_to_base64(j["adOne"]),
        image_to_base64(j["adTwo"]),
        image_to_base64(j["adThree"]),
        image_to_base64(j["adFour"]),
        image_to_base64(j["adFive"]),
        image_to_base64(j["adSix"]),
        image_to_base64(j["adSeven"]),
        image_to_base64(j["adEight"]),
        image_to_base64(j["adNine"]),
        image_to_base64(j["adTen"]),
    };

    if(j["useDefaultIcons"] == false) {
        config.messagesGeneral.IOError.icon         =  image_to_base64(j["messagesGeneral"]["IOError"]["icon"]);
        config.messagesGeneral.serverError.icon     =  image_to_base64(j["messagesGeneral"]["serverError"]["icon"]);
        config.messagesGeneral.tryConnect.icon      =  image_to_base64(j["messagesGeneral"]["tryConnect"]["icon"]);
        config.messagesGeneral.testIO.icon          =  image_to_base64(j["messagesGeneral"]["testIO"]["icon"]);

        config.messagesEntry.clearedToGo.icon       =  image_to_base64(j["messagesEntry"]["clearedToGo"]["icon"]);
        config.messagesEntry.empty.icon             =  image_to_base64(j["messagesEntry"]["empty"]["icon"]);
        config.messagesEntry.invalid.icon           =  image_to_base64(j["messagesEntry"]["invalid"]["icon"]);
        config.messagesEntry.pressButton.icon       =  image_to_base64(j["messagesEntry"]["pressButton"]["icon"]);
        config.messagesEntry.removeTicket.icon      =  image_to_base64(j["messagesEntry"]["removeTicket"]["icon"]);
        config.messagesEntry.validateTicket.icon    =  image_to_base64(j["messagesEntry"]["validateTicket"]["icon"]);
        config.messagesEntry.welcome.icon           =  image_to_base64(j["messagesEntry"]["welcome"]["icon"]);
        config.messagesEntry.parkingFull.icon       =  image_to_base64(j["messagesEntry"]["parkingFull"]["icon"]);

        config.messagesExit.clearedToGo.icon        =  image_to_base64(j["messagesExit"]["clearedToGo"]["icon"]);
        config.messagesExit.empty.icon              =  image_to_base64(j["messagesExit"]["empty"]["icon"]);
        config.messagesExit.errorReadingCard.icon   =  image_to_base64(j["messagesExit"]["errorReadingCard"]["icon"]);
        config.messagesExit.goToAdministration.icon =  image_to_base64(j["messagesExit"]["goToAdministration"]["icon"]);
        config.messagesExit.insertCard.icon         =  image_to_base64(j["messagesExit"]["insertCard"]["icon"]);
        config.messagesExit.nonAuthorized.icon      =  image_to_base64(j["messagesExit"]["nonAuthorized"]["icon"]);
        config.messagesExit.validateTicket.icon     =  image_to_base64(j["messagesExit"]["validateTicket"]["icon"]);
        config.messagesExit.vehicleDoesntMatch.icon =  image_to_base64(j["messagesExit"]["vehicleDoesntMatch"]["icon"]);
    }

    config.messagesGeneral.IOError.text         = encodeText(j["messagesGeneral"]["IOError"]["text"]);
    config.messagesGeneral.serverError.text     = encodeText(j["messagesGeneral"]["serverError"]["text"]);
    config.messagesGeneral.tryConnect.text      = encodeText(j["messagesGeneral"]["tryConnect"]["text"]);
    config.messagesGeneral.testIO.text          = encodeText(j["messagesGeneral"]["testIO"]["text"]);

    config.messagesEntry.clearedToGo.text       = encodeText(j["messagesEntry"]["clearedToGo"]["text"]);
    config.messagesEntry.empty.text             = encodeText(j["messagesEntry"]["empty"]["text"]);     
    config.messagesEntry.invalid.text           = encodeText(j["messagesEntry"]["invalid"]["text"]);
    config.messagesEntry.pressButton.text       = encodeText(j["messagesEntry"]["pressButton"]["text"]);
    config.messagesEntry.removeTicket.text      = encodeText(j["messagesEntry"]["removeTicket"]["text"]);
    config.messagesEntry.validateTicket.text    = encodeText(j["messagesEntry"]["validateTicket"]["text"]);
    config.messagesEntry.welcome.text           = encodeText(j["messagesEntry"]["welcome"]["text"]);
    config.messagesEntry.parkingFull.text       = encodeText(j["messagesEntry"]["parkingFull"]["text"]);

    config.messagesExit.clearedToGo.text        = encodeText(j["messagesExit"]["clearedToGo"]["text"]);
    config.messagesExit.empty.text              = encodeText(j["messagesExit"]["empty"]["text"]);
    config.messagesExit.errorReadingCard.text   = encodeText(j["messagesExit"]["errorReadingCard"]["text"]);
    config.messagesExit.goToAdministration.text = encodeText(j["messagesExit"]["goToAdministration"]["text"]);
    config.messagesExit.insertCard.text         = encodeText(j["messagesExit"]["insertCard"]["text"]);
    config.messagesExit.nonAuthorized.text      = encodeText(j["messagesExit"]["nonAuthorized"]["text"]);
    config.messagesExit.validateTicket.text     = encodeText(j["messagesExit"]["validateTicket"]["text"]);
    config.messagesExit.vehicleDoesntMatch.text = encodeText(j["messagesExit"]["vehicleDoesntMatch"]["text"]);

    return config;
}