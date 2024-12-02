/*Torolize.h*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h> // to convert string to int
#include<sys/socket.h>// creating socks connection
#include<netinet/in.h> // INANY_ADDRESS kind of this function 

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
    
#define PROXY       "127.0.0.1"
#define PROXYPORT   7777
#define USERNAME    "toroliz"
#define reqsize sizeof(struct proxy_request)
#define ressize sizeof(struct proxy_response)


    /*  +----+----+----+----+----+----+----+----+----+----+....+----+
		| VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
		+----+----+----+----+----+----+----+----+----+----+....+----+
           1    1      2              4           variable       1

    */
struct proxy_request{
    int8 vn;
    int8 cd;
    int16 desport;
    int32 destip;
    unsigned char userid[8];
};
typedef struct proxy_request Req;


    /*
        +----+----+----+----+----+----+----+----+
		| VN | CD | DSTPORT |      DSTIP        |
		+----+----+----+----+----+----+----+----+
     	   1    1      2              4
    */

struct proxy_response{
    int8 vn;
    int8 cd;
    int16 _destport;
    int32 __destip;

};   
typedef struct proxy_response Res; 

Req* request(const char*,const int);
int main(int,char**);
