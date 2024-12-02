#include"torolize.h"


Req* request(const char* destip,const int destport){
    Req* req;

    req = malloc(sizeof(Req));
    
    req->vn = 4;
    req->cd = 1;
    req->desport = htons(destport);
    req->destip = inet_addr(destip);
    strncpy(req->userid,USERNAME,8);

    return req; 

}


int main(int argc , char* argv[]){
    char* host;
    int port;
    Req* req;
    Res* res;
    char buff[ressize]; 
    int success;

    if(argc < 3){
        printf("Usage : %s <host> <port>\n",argv[0]);
        return -1;
    }
    host = (argv[1]);
    port = atoi(argv[2]);

    int sid = socket(AF_INET,SOCK_STREAM,0);
    if(sid<1){
        printf("Failed to create a Socket  :) \n");
        return -1;
    }

    struct sockaddr_in sock;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);  
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if(connect(sid,(struct sockaddr*)&sock,sizeof(sock)) !=0 ){
        perror("Not Connected :) \n");
        return -1;
    }
    printf("Connected to proxy Server \n");
    
    
    req = request(host,port);
    write(sid,req,reqsize);
    
    memset(buff,0,ressize);
    if (read(sid,buff,ressize)<1){
        perror("read");
        free(req);
        close(sid);

        return -1;
    }

    res=(Res*)buff;
    success=(res->cd==90);

    if (!success){
        fprintf(stderr,"Unable to treverse the proxy\n");
        close(sid);
        free(req);
        return -1;
    }    
    
    printf("Succesfully connected through the proxy to ip:%s port:%d",host,port);
    close(sid);
    free(req);


    return 0;

      

}