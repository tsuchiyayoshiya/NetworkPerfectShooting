#include "Socket.h"
/*
bool Socket::Init()
{
	return WSAGetLastError();
}

bool Socket::InitSocket(int sockType)
{
	return WSAGetLastError();
}

bool Socket::Connect(std::string serverIpv4Address, unsigned short port)
{
	return WSAGetLastError();
}

bool Socket::Send(SendElement _elem)
{
	
	return WSAGetLastError();
}

bool Socket::Recv(SendElement* _elem)
{
/*
	SendElement recvElem;
	int ret;

	// ��M
	ret = recv(sock, (char*)&recvElem, sizeof(recvElem), 0);
	// ���s
	if (ret != sizeof(recvElem))
	{
		return false;
	}

	// �������͎�M�f�[�^���o�C�g�I�[�_�[�ɕϊ�
	*_elem = ntohl((u_long)recvElem.playerPos.position_.x);
	return WSAGetLastError();
	
}

void Socket::TransByteOrder()
{
}

bool Socket::Exit()
{
	return WSAGetLastError();
}
*/