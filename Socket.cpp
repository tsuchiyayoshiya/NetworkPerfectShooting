#include "Socket.h"

bool Socket::Init()
{
	WSADATA wsaData;
	// WinSock限定なので、SOCKET_ERRORだって使っちゃう
	return (WSAStartup(MAKEWORD(2, 2), &wsaData) != SOCKET_ERROR);
}

bool Socket::InitSocket(int sockType)
{
	int tempSock = socket(AF_INET, sockType, 0);
	if (tempSock < 0)
	{
		return false;
	}

	unsigned long cmdArg = 0x01;
	if (ioctlsocket(tempSock, FIONBIO, &cmdArg) == 0)
	{
		sock = tempSock;
		return true;
	}
	return false;
}

bool Socket::Connect(std::string serverIpv4Address, unsigned short port)
{
	// 接続先サーバのソケットアドレス情報格納
	struct sockaddr_in toAddr;
	const int tolen = sizeof(toAddr);
	memset(&toAddr, 0, sizeof(toAddr));
	toAddr.sin_family = AF_INET;
	toAddr.sin_port = htons(port);
	inet_pton(AF_INET, serverIpv4Address.c_str(), &toAddr.sin_addr.s_addr);

	return (connect(sock, (struct sockaddr*)&toAddr, sizeof(toAddr)) == 0);
}

bool Socket::Send(SendElement _elem)
{
	
	return WSAGetLastError();
}

bool Socket::Recv(SendElement* _elem)
{
	SendElement recvElem;
	int ret;

	// 受信
	ret = recv(sock, (char*)&recvElem, sizeof(recvElem), 0);
	// 失敗
	if (ret != sizeof(recvElem))
	{
		return false;
	}

	// 成功時は受信データをバイトオーダーに変換
	TransByteOrder(_elem, recvElem);
	return WSAGetLastError();
}

void Socket::TransByteOrder(SendElement* _aftElem, SendElement _BfoElem)
{
	_aftElem->playerPos.position_.x = ntohl(_BfoElem.playerPos.position_.x);
	_aftElem->playerPos.position_.y = ntohl(_BfoElem.playerPos.position_.y);
	_aftElem->playerPos.position_.z = ntohl(_BfoElem.playerPos.position_.z);

	_aftElem->playerPos.rotate_.x = ntohl(_BfoElem.playerPos.rotate_.x);
	_aftElem->playerPos.rotate_.y = ntohl(_BfoElem.playerPos.rotate_.y);
	_aftElem->playerPos.rotate_.z = ntohl(_BfoElem.playerPos.rotate_.z);

	_aftElem->playerPos.scale_.x = ntohl(_BfoElem.playerPos.scale_.x);
	_aftElem->playerPos.scale_.y = ntohl(_BfoElem.playerPos.scale_.y);
	_aftElem->playerPos.scale_.z = ntohl(_BfoElem.playerPos.scale_.z);
	for (int i = 0; i < _aftElem->bulletPos.size(); i++)
	{
		_aftElem->bulletPos.at(i).position_.x = ntohl(_BfoElem.bulletPos.at(i).position_.x);
		_aftElem->bulletPos.at(i).position_.y = ntohl(_BfoElem.bulletPos.at(i).position_.y);
		_aftElem->bulletPos.at(i).position_.z = ntohl(_BfoElem.bulletPos.at(i).position_.z);

		_aftElem->bulletPos.at(i).rotate_.x = ntohl(_BfoElem.bulletPos.at(i).rotate_.x);
		_aftElem->bulletPos.at(i).rotate_.y = ntohl(_BfoElem.bulletPos.at(i).rotate_.y);
		_aftElem->bulletPos.at(i).rotate_.z = ntohl(_BfoElem.bulletPos.at(i).rotate_.z);

		_aftElem->bulletPos.at(i).scale_.x = ntohl(_BfoElem.bulletPos.at(i).scale_.x);
		_aftElem->bulletPos.at(i).scale_.y = ntohl(_BfoElem.bulletPos.at(i).scale_.y);
		_aftElem->bulletPos.at(i).scale_.z = ntohl(_BfoElem.bulletPos.at(i).scale_.z);
	}
}

bool Socket::Exit()
{
	return WSAGetLastError();
}
