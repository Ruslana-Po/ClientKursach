#ifndef CONNECTION_H
#define CONNECTION_H
#include "header.h"
#include <QString>

class Connection
{
public:
    Connection(const char* server_ip, int port);
    ~Connection();
    string sendMessage(int number, const QString& id);
private:
    int  client_socket;
    struct sockaddr_in server_address;

};

#endif // CONNECTION_H
