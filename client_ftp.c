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
#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>


#define IPSERVER	"127.0.0.1"



int main(int argc, char* argv[])
{

    char *ip_server = NULL, *file_name = NULL;

    //BEGIN: 
    printf("argc:%d\n",argc);

    for(int i=0; i< argc; i++)
        printf("argv[%d]= %s\n",i, argv[i]);

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
        ip_server = (char *)malloc(sizeof(IPSERVER));
        printf("sizeof(IP)=%d, len(IP):%d\n", sizeof(IPSERVER), strlen(IPSERVER));
        sprintf(ip_server,"%s",IPSERVER);


        file_name = (char *)malloc(sizeof(argv[1]));
        printf("sizeof(file_name)=%d, len(file_name):%d\n", sizeof(argv[1]), strlen(argv[1]));
        sprintf(file_name,"%s",argv[1]);

    }
    else
    {
        ip_server = (char *)malloc(sizeof(argv[1]));
        printf("sizeof(IP)=%d, len(IP):%d\n", sizeof(argv[1]), strlen(argv[1]));
        sprintf(ip_server,"%s",argv[1]);

        file_name = (char *)malloc(sizeof(argv[2]));
        printf("sizeof(file_name)=%d, len(file_name):%d\n", sizeof(argv[2]), strlen(argv[2]));
        sprintf(file_name,"%s",argv[2]);


    }

    // init
    struct sockadd_in sin_client;
    int sfd_client, x;
    size_t size_sockaddr = sizeof(struct sockaddr);
    short int connection_id;
    



    printf("ipserver:%s\n", ip_server);
    printf("filename:%s\n", file_name);
    
    if(ip_server != NULL)
        free(ip_server);

    if(file_name != NULL)
        free(file_name);


    return 0;
}