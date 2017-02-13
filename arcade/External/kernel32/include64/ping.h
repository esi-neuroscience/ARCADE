#ifndef __ping_h__
#define __ping_h__
#define MAXIPNAME	30
// For optional values, zero means use the default.
typedef struct __Ping {
        char *HostName;    // IN: Host name/Ip address of destination. Required
	int TotalPackets;  // OPTIONAL: Number of packets to send before exiting. 
                           //           Default is 5
	int DataSize;      // OPTIONAL: Data size in the sent packets. Default is 32
	int SleepTime;     // OPTIONAL: Time (in ms) to wait after each packet.
                           //           Default is 1000 ms.
	int MaxTimeouts;   // OPTIONAL: Maximum number of timeouts allowed.
	                   //           Default is 5.
	int (*Callback)(struct __Ping *); // OPTIONAL: Callback function at each
                          // packet received and at each timeout.
	int ttl;          // OPTIONAL: Time to live. Default 128
	int verbose;       // Optional: Whether to print messages to stdout or not.
	int TotalReceived; // OUT: Total packets received
	int TotalSent;	   // OUT: Total packets sent
	int MaxTime;       // OUT: Maximum time (ms)
	int MinTime;       // OUT: Minimum time (ms)
	int TotalTime;     // OUT: Total time used
	int Timeouts;      // OUT: Number of timeouts
	int Errorcode;     // WSAGetLastError() report when an error occurs, or
                           // a negative number, specific to the ping function.
	int ShortPackets;  // OUT: Packets that weren't sent completely due to errors
	char ip[MAXIPNAME];// OUT: IP of destination (Can be the same as HostName)
	// Per packet specific data
	int Bytes;         // OUT: Bytes received
	int Seq;           // OUT: Sequence number
	int Time;          // OUT: Time for this packet
} PingInterface;

#define PINGERROR_BADADDR	-1
#define PINGERROR_SETSOCKOPT	-2
#define PINGERROR_NONETWORK	-3
#define PINGERROR_NOSOCKET	-4
#define PINGERROR_INTERNAL	-5

int ping(PingInterface *);
#endif

