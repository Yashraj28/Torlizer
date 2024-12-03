#include "proxy_server.h"

void handle_client(int client_socket) {
    Req* req = malloc(sizeof(Req));
    Res* res = malloc(sizeof(Res));

    if (req == NULL || res == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // Read the proxy request
    if (read(client_socket, req, reqsize) <= 0) {
        perror("Failed to read from client");
        free(req);
        free(res);
        return;
    }

    // Connect to the target server
    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (target_socket < 0) {
        perror("Failed to create target socket");
        free(req);
        free(res);
        return;
    }

    struct sockaddr_in target_address;
    target_address.sin_family = AF_INET;
    target_address.sin_port = req->desport;
    target_address.sin_addr.s_addr = req->destip;

    if (connect(target_socket, (struct sockaddr*)&target_address, sizeof(target_address)) < 0) {
        perror("Failed to connect to target");
        res->cd = 91; // Failure code
        write(client_socket, res, ressize); // Send failure response
        close(target_socket);
        free(req);
        free(res);
        return;
    }

    // Connection successful
    res->cd = 90; // Success code
    write(client_socket, res, ressize); // Send success response

    // Relay data between client and target server (not implemented here for brevity)

    close(target_socket);
    free(req);
    free(res);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the proxy logic
        handle_client(client_socket);

        close(client_socket); // Close client socket after handling
    }

    close(server_socket);
    return 0;
}



