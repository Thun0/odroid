#include <stdio.h>
#include <unistd.h>
#include <lirc/lirc_client.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct lirc_config* config;
    char* code;
    system("mocp -S");
    if(lirc_init("irexec", 1) == -1)
    {
        printf("Error! init failed!\n");
        return -1;
    }
    if(lirc_readconfig(NULL, &config, NULL) != 0)
    {
        printf("Error! read config failed!\n");
        return -1;
    }
    while(lirc_nextcode(&code) == 0)
    {
        if(!code) continue;
        //printf("%s\n", code);
        if(strstr(code, "KEY_RIGHT") != NULL)
        {
            system("mocp -f");
        }
        if(strstr(code, "KEY_LEFT") != NULL)
        {
            system("mocp -r");
        }
        if(strstr(code, "KEY_ENTER") != NULL)
        {
            system("mocp -G");
        }
        if(strstr(code, "KEY_VOLUMEUP") != NULL)
        {
            system("mocp -v +10");
        }
        if(strstr(code, "KEY_VOLUMEDOWN") != NULL)
        {
            system("mocp -v -10");
        }
        if(strstr(code, "KEY_UP") != NULL)
        {
            system("mocp -p");
        }
        if(strstr(code, "KEY_DOWN") != NULL)
        {
            system("mocp -s");
        }
        if(strstr(code, "KEY_POWER") != NULL)
        {
            break;
        }

    }
    system("mocp -x");
    lirc_deinit();
    return 0;
}
