#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <target_ip> <start_port>-<end_port>" << std::endl;
        return 1;
    }

    const char* target_ip = argv[1];
    const char* port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2 || start_port < 1 || end_port > 65535 || start_port > end_port) {
        std::cerr << "Invalid port range. Please provide a valid range, e.g., 1-65535." << std::endl;
        return 1;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    for (int port = start_port; port <= end_port; ++port) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            return 1;
        }

        target_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0) {
            std::cout << "Port " << port << " is open." << std::endl;
        }

        close(sockfd);
    }

    return 0;
}
