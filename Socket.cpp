#include "Socket.h"

Socket::Socket()
{
}

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

bool Socket::Send(NetWorkValue _elem)
{
	NetWorkValue sendVal;
	//TransByteOrder(&sendVal, _elem);
	sendVal = _elem;// 送信データ
	int ret;		// 成否の判定用
	// 送信
	ret = SendElem(sendVal);

	// 失敗
	if (ret != sizeof(sendVal))
	{
		return false;
	}

	return WSAGetLastError();
}

bool Socket::SendElem(NetWorkValue _elem)
{
	bool ret;
	ret = send(sock, (char*)&_elem.playerPos.position_.x, sizeof(_elem.playerPos.position_.x), 0);
	ret = send(sock, (char*)&_elem.playerPos.position_.y, sizeof(_elem.playerPos.position_.y), 0);
	ret = send(sock, (char*)&_elem.playerPos.position_.z, sizeof(_elem.playerPos.position_.z), 0);

	int bulletNum = _elem.bulletPos.size();
	ret = send(sock, (char*)&bulletNum, sizeof(bulletNum), 0);
	for (int i = 0; i < bulletNum; i++)
	{
		ret = send(sock, (char*)&_elem.bulletPos[i].position_.x, sizeof(_elem.bulletPos[i].position_.x), 0);
		ret = send(sock, (char*)&_elem.bulletPos[i].position_.y, sizeof(_elem.bulletPos[i].position_.y), 0);
		ret = send(sock, (char*)&_elem.bulletPos[i].position_.z, sizeof(_elem.bulletPos[i].position_.z), 0);
	}
	return ret;
}

bool Socket::Recv(NetWorkValue* _elem)
{
	NetWorkValue recvValue;
	int ret;
	ret = RecvElem(_elem);

	if (ret != sizeof(recvValue))
		return 0;

	// 成功時は受信データをバイトオーダーに変換
	*_elem = recvValue;

	return WSAGetLastError();
}

bool Socket::RecvElem(NetWorkValue* _elem)
{
	bool ret;
	NetWorkValue recvVal;
	ret = recv(sock, (char*)&recvVal.playerPos.position_.x, sizeof(recvVal.playerPos.position_.x), 0);
	ret = recv(sock, (char*)&recvVal.playerPos.position_.y, sizeof(recvVal.playerPos.position_.y), 0);
	ret = recv(sock, (char*)&recvVal.playerPos.position_.z, sizeof(recvVal.playerPos.position_.z), 0);

	int bulletNum;
	ret = recv(sock, (char*)&bulletNum, sizeof(bulletNum), 0);
	if (bulletNum > 0)
		recvVal.bulletPos.resize(bulletNum);
	for (int i = 0; i < bulletNum; i++)
	{
		ret = recv(sock, (char*)&recvVal.bulletPos[i].position_.x, sizeof(recvVal.bulletPos[i].position_.x), 0);
		ret = recv(sock, (char*)&recvVal.bulletPos[i].position_.y, sizeof(recvVal.bulletPos[i].position_.y), 0);
		ret = recv(sock, (char*)&recvVal.bulletPos[i].position_.z, sizeof(recvVal.bulletPos[i].position_.z), 0);
	}
	if (recvVal.playerPos.position_.x != 0)   *_elem = recvVal;
	return false;
}

void Socket::TransByteOrder(NetWorkValue* _aftElem, NetWorkValue _BfoElem)
{
	_aftElem->playerPos.position_.x = htonl(_BfoElem.playerPos.position_.x);
	_aftElem->playerPos.position_.y = htonl(_BfoElem.playerPos.position_.y);
	_aftElem->playerPos.position_.z = htonl(_BfoElem.playerPos.position_.z);

	_aftElem->playerPos.rotate_.x = htonl(_BfoElem.playerPos.rotate_.x);
	_aftElem->playerPos.rotate_.y = htonl(_BfoElem.playerPos.rotate_.y);
	_aftElem->playerPos.rotate_.z = htonl(_BfoElem.playerPos.rotate_.z);

	_aftElem->playerPos.scale_.x = htonl(_BfoElem.playerPos.scale_.x);
	_aftElem->playerPos.scale_.y = htonl(_BfoElem.playerPos.scale_.y);
	_aftElem->playerPos.scale_.z = htonl(_BfoElem.playerPos.scale_.z);
	for (int i = 0; i < _aftElem->bulletPos.size(); i++)
	{
		_aftElem->bulletPos.at(i).position_.x = htonl(_BfoElem.bulletPos.at(i).position_.x);
		_aftElem->bulletPos.at(i).position_.y = htonl(_BfoElem.bulletPos.at(i).position_.y);
		_aftElem->bulletPos.at(i).position_.z = htonl(_BfoElem.bulletPos.at(i).position_.z);

		_aftElem->bulletPos.at(i).rotate_.x = htonl(_BfoElem.bulletPos.at(i).rotate_.x);
		_aftElem->bulletPos.at(i).rotate_.y = htonl(_BfoElem.bulletPos.at(i).rotate_.y);
		_aftElem->bulletPos.at(i).rotate_.z = htonl(_BfoElem.bulletPos.at(i).rotate_.z);

		_aftElem->bulletPos.at(i).scale_.x = htonl(_BfoElem.bulletPos.at(i).scale_.x);
		_aftElem->bulletPos.at(i).scale_.y = htonl(_BfoElem.bulletPos.at(i).scale_.y);
		_aftElem->bulletPos.at(i).scale_.z = htonl(_BfoElem.bulletPos.at(i).scale_.z);
	}
}

bool Socket::Exit()
{
	return WSAGetLastError();
}
