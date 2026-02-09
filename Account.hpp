#ifndef __Account.HPP__
#define __Account .HPP__
#include <iostream>
#include <uuid/uuid.h>

enum AccountStatus
{
    ACTIVE,
    INACTIVE,
    BLOCKED
};

class Account
{
private:
    std::string userId;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    AccountStatus status;
    double amount;

public:
    Account(std::string firstName,
            std::string lastName,
            std::string email,
            std::string password)
    {
        // Make ID
        uuid_t id;
        char c_id[37];
        uuid_generate_random(id);
        uuid_unparse(id, c_id);

        this->userId = std::string(c_id);
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->password = password;
        this->amount = 0.0;
        this->status = ::ACTIVE;
    }

    bool isValidName()
    {
        // Check if firstName and lastName are not empty
    }

    bool isValidEmail()
    {
        // check if email is valid using Regex
    }

    bool isValidPassword()
    {
        // make sure password is at least 8 characters
    }

    bool signIn(std::string email, std::string password)
    {
    }

    bool createAccount(
        std::string firstName,
        std::string lastName,
        std::string email,
        std::string password)
    {
    }

    bool blockAccount(std::string userId) {}
};
#endif