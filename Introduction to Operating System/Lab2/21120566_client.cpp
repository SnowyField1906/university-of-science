#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main()
{
    int sockfd;
    struct sockaddr_in address;
    int result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(9734);

    int len = sizeof(address);

    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1)
    {
        perror("Oops: client problem");
        return 1;
    }

    while (true)
    {
        char message[1000];

        cout << "Enter expression..."
             << endl
             << "\t- Only + - * / ( ) are supported"
             << endl
             << "\t- Enter \"q\" to close"
             << endl
             << "Your expression: ";

        cin.getline(message, 1000);

        if (strcmp(message, "q") == 0)
        {
            break;
        }

        write(sockfd, message, strlen(message) + 1);

        char result[1000];
        read(sockfd, result, 1000);

        cout << "Result from server: " << result << endl
             << endl;
    }

    cout << "Goodbye!" << endl;

    close(sockfd);
    return 0;
}