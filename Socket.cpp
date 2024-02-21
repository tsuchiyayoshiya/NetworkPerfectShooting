#include "Socket.h"

Socket::Socket()
{
	// 初期化
	if (!Init())
	{
		text_ = "Error: Init()";
	}
	text_ = "Success: Init()";


	// ノンブロッキングソケットの作成
	if (!InitSocket(SOCK_STREAM))
	{
		text_ = "Error:Socket()";
	}
	text_ = "Success: Socket()";


	// 接続要求
	if (!Connect("127.0.0.1", SERVERPORT))
	{
		text_ = "Error:Connect()";
	}
	text_ = "Success: Connect()";
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

bool Socket::Send(SendElement _elem)
{
	SendElement sendValue;	
	TransByteOrder(&sendValue, _elem);// 送信データ ... ネットワークバイトオーダーに変換後の値を格納
	int ret;		// 成否の判定用
	// 送信
	ret = send(sock, (char*)&sendValue, sizeof(sendValue), 0);
	// 失敗
	if (ret != sizeof(sendValue))
	{
		return false;
	}

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
	_aftElem->playerPos.position_.x = htonl(_BfoElem.playerPos.position_.x);
	_aftElem->playerPos.position_.y = htonl(_BfoElem.playerPos.position_.y);
	_aftElem->playerPos.position_.z = htonl(_BfoElem.playerPos.position_.z);

	_aftElem->playerPos.rotate_.x = htonl(_BfoElem.playerPos.rotate_.x);
	_aftElem->playerPos.rotate_.y = htonl(_BfoElem.playerPos.rotate_.y);
	_aftElem->playerPos.rotate_.z = htonl(_BfoElem.playerPos.rotate_.z);

	_aftElem->playerPos.scale_.x = htonl(_BfoElem.playerPos.scale_.x);
	_aftElem->playerPos.scale_.y = htonl(_BfoElem.playerPos.scale_.y);
	_aftElem->playerPos.scale_.z = htonl(_BfoElem.playerPos.scale_.z);
	/*for (int i = 0; i < _aftElem->bulletPos.size(); i++)
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
