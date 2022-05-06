#pragma once
// server program for udp connection
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#define PORT 5000
#define MAXLINE 10

class Server
{
public:
	Server();
	~Server();
	
	
	char send[2];
	char get[2];
	int listenfd; 
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;

	void connect_to_client();
	void send_to_client(char* event);	
	void get_from_client(char* event);
};

Server::Server()
{
	bzero(&servaddr, sizeof(servaddr));	
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	
	listenfd = socket(AF_INET, SOCK_DGRAM, 0);
}

Server::~Server()
{}

void Server::connect_to_client()
{
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
}

void Server::get_from_client(char* event)
{
	len = sizeof(cliaddr);
	get[0] = get[1] = '0';
	recvfrom(listenfd, get, sizeof(get), 0, (struct sockaddr*)&cliaddr,&len);
	event[0] = get[0];
	event[1] = get[1];
}

void Server::send_to_client(char* event)
{
	send[0] = event[0];
	send[1] = event[1];
	sendto(listenfd, send, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
}







