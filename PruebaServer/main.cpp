#include <iostream>
#include <vector>
#include<list>
#include <string>
#include <thread>
#include <WinSock2.h>
#include <ws2ipdef.h>
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

using namespace std;

#define MAXPENDING 5
#define RCVBUFSIZE 1024

typedef  struct playerinfo {
    SOCKET client;
    int id;
}
        PlayerInfo;
typedef  struct sessioninfo {
    int id;
    string name;
    string serverip;
    int serverport;
}
        SessionInfo;
list<PlayerInfo> players;
list<SessionInfo> sessions;
int playercount = 0;
int sessioncount = 0;

void InterpretClientMessage(char* buffer, PlayerInfo player)
{
    string temp = "";
    vector<string> params;
    char cmd = 0;
    for (int i = 0; buffer[i] != '#'; i++) {
        if ((buffer[i] == '|') && (cmd == 0)) {
            cmd = temp[0];
            temp = "";
        }
        else if ((buffer[i] == '|') && (cmd != 0)) {
            params.push_back(temp);
            temp = "";
        }
        else {
            temp = temp + buffer[i];
        }
    }

    if (cmd == 'g') {
        string message = "s|";
        if (sessions.size() > 0) {
            for (list<SessionInfo>::iterator it = sessions.begin();
                 it != sessions.end(); it++) {
                message = message + to_string(it->id) + "|" + it->name +
                          "|" + it
                                  ->serverip + "|" +
                          to_string(it
                                            ->serverport) + "|";
                if (send(player.client, message.c_str(), message.length(), 0)
                    == SOCKET_ERROR) {
                    cout << "send() failed" << endl;
                }
            }
        }
        else {
            message = message + "null|";
            if (send(player.client, message.c_str(), message.length(), 0)
                == SOCKET_ERROR) {
                cout << "send() failed" << endl;
            }
        }
    }

    else if (cmd == 'h'){
        SessionInfo session;
        session.id = sessioncount++;
        session.name = params.at(0);
        session.serverip = params.at(1);
        session.serverport = stoi(params.at(2));
        sessions.push_back(session);
        string message = "o|" + params.at(2) + "|";
        if (send(player.client, message.c_str(), message.length(), 0)
            == SOCKET_ERROR) {
            cout << "send() failed" << endl;
        }
    }
    else {
        char* endline = strchr(buffer, '#');
        buffer[(int)(endline-buffer) + 1] = 0;
        cout << "Unknown message: " << buffer << endl;
    }
}

void HandleClientThread(PlayerInfo player)
{
    char buffer[RCVBUFSIZE];
    while (recv(player.client, buffer, sizeof(buffer), 0) > 0)
    {
        InterpretClientMessage(buffer, player);
        memset(buffer, 0, sizeof(buffer));
    }
    if (closesocket(player.client) == SOCKET_ERROR)
    {
        cout << "closesocket() failed" << endl;
    }
}

int main() {
    SOCKET server;
    SOCKADDR_IN server_addr, client_addr;
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != NO_ERROR) {
        cout << "WSAStartup() failed" << endl;
        exit(EXIT_FAILURE);
    }
    if ((server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))
        == INVALID_SOCKET) {
        cout << "socket() failed" << endl;
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8856);

    if (::bind(server, (struct sockaddr*) & server_addr,
               sizeof(server_addr)) == SOCKET_ERROR) {
        cout << "bind() failed" << endl;
        exit(EXIT_FAILURE);
    }
    if (listen(server, MAXPENDING) == SOCKET_ERROR) {
        cout << "listen() failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Server Started!" << endl;
    while (true) {
        SOCKET client;
        int clientlen = sizeof(client_addr);
        if ((client = accept(server, (struct sockaddr*) & client_addr,
                             &clientlen)) == INVALID_SOCKET) {
            cout << "accept() failed" << endl;
        }

        char addrstr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), addrstr,
                  INET_ADDRSTRLEN);
        cout << "Connection from " << addrstr << endl;
        PlayerInfo cinfo;
        cinfo.client = client;
        cinfo.id = playercount++;
        players.push_back(cinfo);
        thread* clientthread = new std::thread(HandleClientThread,
                                               cinfo);
    }

}
