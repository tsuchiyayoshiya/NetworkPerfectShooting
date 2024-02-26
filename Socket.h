
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <cstdlib>
#include "Engine/Transform.h"

#pragma comment( lib, "ws2_32.lib")

const unsigned short SERVERPORT = 8888;

const unsigned int MESSAGELENGTH = 1024;

struct NetWorkValue
{
	Transform playerPos;
	std::vector<Transform> bulletPos;
};

class Socket
{
	int sock;
	std::string text_;
public:
	Socket();
	bool Init();
	bool InitSocket(int sockType);
	bool Connect(std::string serverIpv4Address, unsigned short port);
	bool Send(NetWorkValue _elem);
	bool SendElem(NetWorkValue _elem);
	bool Recv(NetWorkValue* _elem);
	bool RecvElem(NetWorkValue* _elem);
	void TransByteOrder(NetWorkValue* _aftElem, NetWorkValue _BfoElem);
	bool Exit();
	std::string GetText() { return text_; }
};
