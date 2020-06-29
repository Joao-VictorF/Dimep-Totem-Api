#ifndef LOGIN_H
#define LOGIN_H 

#include <ngrest/common/Service.h>

struct User {
    std::string username;
    std::string password;
};

struct LoginResponse {
    bool success;
    bool firstAccess;
    std::string message;
    std::string token;
};

// *location: loginRoute
class login: public ngrest::Service
{
public:
    
    // *location: /login
    // *method: POST
    LoginResponse loginRoute(User user);

    // *location: /update
    // *method: POST
    LoginResponse updateRoute(std::string token, User user);
};


#endif // LOGIN_H



