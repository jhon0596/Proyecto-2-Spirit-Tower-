//
// Created by jrodr on 30/6/2020.
//

#include <iostream>

#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
using namespace std;



void main()
{
    // se inicializa el winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    INT wsOk = WSAStartup(ver, &wsData);
    if (wsOk != 0) {
        cerr << "no se inicio el socket" << endl;
        return;
    }

    // creacion de socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET) {
        cerr << " no se pudo crear el socket" << endl;
        return;
    }

    //direccion ip y socket

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // socket escuchando

    listen(listening, SOMAXCONN);

    //esperando conexion del cliente

    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(host, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {

        cout << host << " conectado al puerto" << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "conectado al puerto" <<
             ntohs(client.sin_port) << endl;
    }
    //dejar de escuchar
    closesocket(listening);

    //acceptar mensaje del cliente

    char buf[4096];

    while (true) {
        ZeroMemory(buf, 4096);

        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
            cerr << "error en el mensaje" << endl;
            break;

        }
        if (bytesReceived == 0) {
            cout << "cliente desconectado" << endl;
            break;
        }
        send(clientSocket, buf, bytesReceived + 1, 0);
    }
    closesocket(clientSocket);

    WSACleanup();



}
