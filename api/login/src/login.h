#ifndef LOGIN_H
#define LOGIN_H 

#include <ngrest/common/Service.h>

struct User {
    std::string username;
    std::string password;
};

struct LoginResponse {
    bool success;
    std::string message;
    std::string token;
};

// *location: login
class login: public ngrest::Service
{
public:
    
    // *location: /
    // *method: POST
    LoginResponse loginRoute(User user);

    // *location: /update
    // *method: POST
    LoginResponse updateRoute(std::string token, User user);
};


#endif // LOGIN_H



