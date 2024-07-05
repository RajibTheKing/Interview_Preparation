

class IUser
{
    virtual User getUserById(string id) = 0;
    virtual bool authenticate(string username, string password) = 0;
}

class ILogger
{
    virtual void debugLog(string msg) = 0;
}

class IEmail
{
    virtual bool sendEmail(User to, string msg) = 0;
}