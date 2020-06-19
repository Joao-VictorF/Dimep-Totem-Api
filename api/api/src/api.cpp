#include "api.h"
#include "../../auxiliar_fuctions/auxiliarHandlers.h"

Response api::updateConfig(std::string token, Config newConfig) {
    if (verify_token(token)) {
        newConfig = saveAds(newConfig);

        if(newConfig.useDefaultIcons == true) {
            newConfig = setDefaultIcons(newConfig);
        } else {
            newConfig = savePersonalizedIcons(newConfig);
        }
        
        newConfig = saveTexts(newConfig);

        save_config(newConfig);
        
        Response res = {
            true,
            encodeText("Configurações atualizadas com sucesso!")
        };

        return res;
    } else {
        Response res = {
            false,
            encodeText("Token inválido, faça login novamente!")
        };

        return res;
    }
}

Config api::getConfig(std::string token) {
    Config config = configJson_to_base64();

    return config;
}
