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

bool Socket::Send(float _time)
{
    int ret;		// 成否の判定用
    // 送信
    ret = send(sock, (char*)&_time, sizeof(_time), 0);

    // 失敗
    if (ret != sizeof(_time))
    {
        return false;
    }

    return ret;
}

bool Socket::Recv(bool* _isStart)
{
    bool recvValue;
    int ret;
    ret = recv(sock, (char*)&recvValue, sizeof(recvValue), 0);

    if (ret != sizeof(recvValue))
        return 0;

    // 成功時は受信データをバイトオーダーに変換
    *_isStart = recvValue;

    return WSAGetLastError();
}

int Socket::Recv(float* _time)
{
    float recvValue;
    int ret;
    ret = recv(sock, (char*)&recvValue, sizeof(recvValue), 0);

    if (ret != sizeof(recvValue))
        return 0;

    // 成功時は受信データをバイトオーダーに変換
    *_time = recvValue;

    return WSAGetLastError();
}


bool Socket::Exit()
{
	return WSAGetLastError();
}
