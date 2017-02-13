#ifndef __netutils_h__
#define __netutils_h__
#include <winsock2.h>
#include <ping.h>
int GetHttpURL(char *URL,char *OutFileName);
int GetFtpURL(char *host,char *remotepath,char *localpath);
typedef struct tagSession {
	char *Host;
	int port;
	int Socket;
	int BytesReceived;
	int BytesSent;
	int ErrorCode;
	int Flags;
	WSABUF wsabuffer;
}
Session;

#define NEEDS_WSA_CLEANUP 	1
#define NEEDS_FREE			2
#define NET_IS_CLIENT		4
#define NET_IS_SERVER		8

#define DEFAULT_BUFFER_SIZE	512
int ServerConnect(Session *session);
int ClientConnect(Session * session);
int Send(Session *session,int len,char *data);
int Receive(Session *session, int len, char *data);
void CloseSession(Session *session);
void TranslateError(int error,int buflen, int buf);
unsigned int crc32(unsigned char *buf,unsigned int len,unsigned long crc);
int FileEncrypt(char *inputfile,char *password,char *outputfile,int encryptflag);
int Sha1FromFile(char *filename , char *digest);
int Sha1FromBuffer(char *buffer,int len,char *digest);
#endif
