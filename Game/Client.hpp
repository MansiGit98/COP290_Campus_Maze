# pragma once
// udp client driver program
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#define PORT 5000
#define MAXLINE 10
class Client
{
public:
	Client(char* IPaddr);
	~Client();
	
	char send[2];
	char get[2];
	int sockfd;
	struct sockaddr_in servaddr;

	bool connect_to_server();
	void send_to_server(char* event);	
	void get_from_server(char* event);
	void Close_Client();
};

Client::Client(char* IPaddr)
{
	// clear servaddr
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_addr.s_addr = inet_addr(IPaddr);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	
	// create datagram socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
}

Client::~Client()
{}

bool Client::connect_to_server()
{
	// connect to server
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("\n Error : Connect Failed \n");
		return false;
	}
	return true;
}	

void Client::send_to_server(char* event)
{
	send[0] = event[0];
	send[1] = event[1];
	sendto(sockfd, send, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr));
}

void Client::get_from_server(char* event)
{
	get[0] = get[1] = '0';
	recvfrom(sockfd, get, sizeof(get), 0, (struct sockaddr*)NULL, NULL);
	event[0] = get[0];
	event[1] = get[1];
}

void Client::Close_Client()
{
	close(sockfd);
}













