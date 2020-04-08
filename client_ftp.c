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

#define IPSERVER	"127.0.0.1"

int main(int argc, char* argv[])
{
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

    if(argc ==2)
    {

    }
    else
    {
        /* code */
    }
    




    return 0;
}