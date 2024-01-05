#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

string infix_to_postfix(const string &infix)
{
    stringstream postfix;
    stack<char> s;

    for (char c : infix)
    {
        if (isdigit(c))
        {
            postfix << c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (is_operator(c))
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix << s.top();
        s.pop();
    }

    return postfix.str();
}

string evaluate_postfix(const string &postfix)
{
    stack<float> s;

    try
    {
        for (char c : postfix)
        {
            if (isdigit(c))
            {
                s.push(static_cast<float>(c - '0'));
            }
            else if (is_operator(c))
            {
                if (s.size() < 2)
                {
                    throw runtime_error("Invalid expression: Too few operands");
                }

                float operand2 = s.top();
                s.pop();
                float operand1 = s.top();
                s.pop();

                float result;
                switch (c)
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        throw runtime_error("Error: Division by zero!");
                    }
                    result = operand1 / operand2;
                    break;
                }
                s.push(result);
            }
        }
    }
    catch (const exception &e)
    {
        throw;
    }

    if (s.size() != 1)
    {
        throw runtime_error("Invalid expression: Too many operands");
    }

    return to_string(s.top());
}

void *handle_client(void *arg)
{
    int client_sockfd = *((int *)arg);
    char message[1000];

    while (true)
    {
        read(client_sockfd, message, 1000);

        if (strcmp(message, "q") == 0)
        {
            break;
        }

        string postfix = infix_to_postfix(message);
        char result[1000];

        try
        {
            string result_str = evaluate_postfix(postfix);
            strcpy(result, result_str.c_str());
        }
        catch (const exception &e)
        {
            strcpy(result, e.what());
        }

        write(client_sockfd, result, strlen(result) + 1);
    }

    close(client_sockfd);
    free(arg);
    return NULL;
}

int main()
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    int server_len, client_len;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);

    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    listen(server_sockfd, 5);

    cout << "Server is waiting..." << endl;

    while (true)
    {
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);

        pthread_t thread;
        int *arg = (int *)malloc(sizeof(*arg));
        *arg = client_sockfd;
        pthread_create(&thread, NULL, handle_client, arg);
        pthread_detach(thread);
    }

    close(server_sockfd);
    return 0;
}