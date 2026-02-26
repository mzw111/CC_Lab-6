#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while (true) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nServed by backend: ";
        response += getenv("HOSTNAME");
        response += "\n";

        send(new_socket, response.c_str(), response.length(), 0);
        close(new_socket);
    }

    return 0;
}
