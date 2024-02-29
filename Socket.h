
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

class Socket
{
	int sock;
	std::string text_;
public:
	Socket();
	bool Init();
	bool InitSocket(int sockType);
	bool Connect(std::string serverIpv4Address, unsigned short port);
	bool Send(float _time);

	bool Recv(bool* _isStart);
	int Recv(float* _time);
	bool Exit();
	std::string GetText() { return text_; }
};
