/*********************************************************************************
 *(C) @@.        [] All Rights Reserved.
 *FileName:      client_ftp.c
 *Author:        fly
 *Telephtone:    
 *Version:       1.0.0
 *Data:          2020.04.08
 *Description:   
 *Others:        
 *History:       
**********************************************************************************/

#include "client_ftp.h"
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


// #define IPSERVER	"127.0.0.1"
// #define PORTSERVER   8487

#define IPSERVER	"47.105.217.224"
#define PORTSERVER   21
/**
 ****************************************************************************************
 * @brief       fill host addr
 ****************************************************************************************
 */
static int fill_host_addr(struct sockaddr_in *host, const char *ip, int port);
static int xconnect(struct sockaddr_in *host, int type);

int main(int argc, char* argv[])
{

    char *ip_server = NULL, *file_name = NULL;
    int port_server = PORTSERVER;

    //BEGIN: 

    if(argc <2 | argc >3)
    {
        printf("./client_ftp.out [xx] ---->argc must more than 1,\n\t \
                if=1 the argc[2] is file name downloade from localhost \n\t \
                if=2 argc[2] is ftp ip, argc[3] is filename for downloade...\n");

        return -1;
    }

    // 有点怪啊　sizeof strlen
    if(argc ==2)
    {
        ip_server = (char *)malloc(  (strlen(IPSERVER) +1) *sizeof(char));
        sprintf(ip_server,"%s",IPSERVER);

        file_name = (char *)malloc( strlen(argv[1] +1) *sizeof(char));
        sprintf(file_name,"%s",argv[1]);
    }
    else
    {
        ip_server = (char *)malloc( (strlen(argv[1]) +1) *sizeof(char) );
        sprintf(ip_server,"%s",argv[1]);

        file_name = (char *)malloc( (strlen(argv[2]) +1) *sizeof(char) );
        sprintf(file_name,"%s",argv[2]);
    }
    

    printf("ipserver:%s\n", ip_server);
    printf("filename:%s\n", file_name);

    // init
    struct sockaddr_in sin_server;
    int ret_fill_host = fill_host_addr(&sin_server, ip_server, port_server);
    if(ret_fill_host != 1 )
    {
        printf("fill host addr err:[%d]\n", ret_fill_host);
        return -1;
    }
    else
    {
        printf("fill host addr ok...\n");
    }

    int fd = xconnect(&sin_server, 1);
    if(fd == -1)
    {
        return -1;//TODO(Zhangx) 
    }
    else
    {
        printf("FTP Client started up. Attempting communication with server @ %s:%d...\n\n", ip_server, port_server);
    }
    


    
    

    int sfd_client, x;
    // size_t size_sockaddr = sizeof(struct sockaddr);
    // short int connection_id;
    

    
    if(ip_server != NULL)
        free(ip_server);

    if(file_name != NULL)
        free(file_name);


    return 0;
}


static int fill_host_addr(struct sockaddr_in *host, const char *ip, int port)
{
    if (port <=0 || port > 65535)
        return 254;//TODO(Zhangx) 
    memset(host, 0, sizeof(struct sockaddr_in));
    host->sin_family = AF_INET;
    if (inet_addr(ip) != -1)
        host->sin_addr.s_addr = inet_addr(ip);
    else
    {
        struct hostent *server_hostent = gethostbyname(ip);
        if(server_hostent != 0 )
            memcpy(&host->sin_addr, server_hostent->h_addr, sizeof(host->sin_addr));
        else
        {
            return 253;//TODO(Zhangx) 
        }
        
    }
    
    host->sin_port = htons(port);
    

    return 1;//TODO(Zhangx) 
}

static int xconnect(struct sockaddr_in *host, int type)
{
    printf("[TODO] type unused \n");
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if( fd <0 )
    {
        printf("creat socket err...\n");
        return -1;
    }

    if( connect(fd, (struct sockaddr *)host, sizeof(struct sockaddr_in)) <0 )
    {
        printf("Can't connect to server %s, port %d \n", \
                inet_ntoa(host->sin_addr), ntohs(host->sin_port));
        return -1;
    }

    return fd;
}
    




/**xconnect
 ****************************************************************************************
     struct timeval out_time;
    int set;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        printf("...creat socket errr!");
        return -1;
    }

    if (type == 1)
    {
        out_time.tv_sec = 0;
        out_time.tv_usec = 300 * 1000;
    }
    else
    {
        out_time.tv_sec = 5;
        out_time.tv_usec = 0;
    }

    set = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &out_time, sizeof(out_time));
    if (set != 0)
    {
        printf("...set socket %s errno:%d\n", strerror(errno), errno);
        return -1;
    }
    //connect to the server
    if (connect(s, (struct sockaddr *)s_addr, sizeof(struct sockaddr_in)) < 0)
    {
        printf("Can't connect to server %s, port %d\n",
               inet_ntoa(s_addr->sin_addr), ntohs(s_addr->sin_port));
        return -1;
    }
    return s;  
 ****************************************************************************************
 */



/*********************************************************************************
字符串的长度是不包括'\0'的
常见需要计算'\0'的情况是，以字符数组初始化一个字符串的时候，分配内存空间的情况。
char str[]="123456";
这时候数组str的大小需要计算'\0',也就是str有7个元素      
**********************************************************************************/
