#include "connection.h"


Connection::Connection(const char* server_ip, int port) {

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        cerr << "Error creating socket" << endl;
        return;
    }

    server_address.sin_port = htons(port); // преобразование порта в сетевой порядок байт
    server_address.sin_family = AF_INET; // семейство адресов (IPv 4)

    // Получаем структуру hostent по имени хоста
    struct hostent* server = gethostbyname(server_ip);
    if (server == nullptr) {
        cerr << "Error host" << endl;
        return;
    }

    // Копируем адрес в структуру sockaddr_in
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(client_socket, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address)) < 0) {
        cerr << "Error connecting to server" << endl;
        return;
    }

    cout << "Connected to server " << inet_ntoa(server_address.sin_addr) << " with port number: " << port << endl;
}

Connection::~Connection() {
    close(client_socket);
}

string Connection::sendMessage(int number, const QString& id) {
    string query ="";
    query = to_string(number) + '$' + id.toStdString()+'\0';
    send(client_socket, query.c_str(), query.length(), 0);
    //sleep(1);
    char buffer[MAX_SIZE_BUF];
    recv(client_socket, buffer, MAX_SIZE_BUF, 0);
    return buffer;
}
