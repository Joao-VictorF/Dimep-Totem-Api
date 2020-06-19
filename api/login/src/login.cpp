#include "login.h"
#include <iomanip>
#include <fstream>
#include "../../auxiliar_fuctions/json.hpp"
#include "../../auxiliar_fuctions/auxiliarHandlers.h"

using json = nlohmann::json;

LoginResponse login::loginRoute(User user) {  
    std::string invalidCredetialsText = encodeText("Usuário ou senha incorretos!");

    LoginResponse res = {
        false,
        invalidCredetialsText,
        ""
    };

    std::ifstream userFile ("login/src/user.json");
    json userJson;
    userFile >> userJson;

    bool correct_user = compare_strings(userJson["username"], user.username);
    bool correct_pass = compare_strings(userJson["password"], user.password);

    if (correct_user && correct_pass){
        std::string token = generate_token(20);

        res.success = true;
        res.message = encodeText("Login realizado com sucesso!");
        res.token   = token;
    }

    return res;
}

LoginResponse login::updateRoute(std::string token, User user) { 
    std::string invalidTokenText = encodeText("Token inválido, faça o login novamente!");

    LoginResponse res = {
        false,
        invalidTokenText,
        ""
    };

    if (verify_token(token)) {
        json userJson {
            {"username", user.username},
            {"password", user.password}
        };

        std::ofstream userFile("login/src/user.json");
        userFile << std::setw(4) << userJson << std::endl;
        
        res.success = true;
        res.message = encodeText("Usuário atualizado com sucesso!");
        res.token = get_token();

    } 
        
    return res;
}


