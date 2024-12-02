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
    

#define PORT   7777
#define USERNAME "toroliz"
#define reqsize sizeof(struct proxy_request)
#define ressize sizeof(struct proxy_response)


struct proxy_request{
    int8 vn;
    int8 cd;
    int16 desport;
    int32 destip;
    unsigned char userid[8];
};
typedef struct proxy_request Req;



struct proxy_response{
    int8 vn;
    int8 cd;
    int16 _destport;
    int32 __destip;

};   
typedef struct proxy_response Res; 

void handle_client(int);
Req* request(const char*,const int);

