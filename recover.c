#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc!=2){
        printf("argc hatası...");
        return 1;
    }
    int bayt = 512;

    FILE *file = fopen(argv[1],"r");

    if (file == NULL){
        printf("dosya null hatası...");
        return 2;
    }

    int jpeg = -1;
    uint8_t bayt_buffer[512];
    uint8_t buffer;
    int r;
    FILE *m = NULL;
    m = fopen("001.jpg","w");
    char str[10] = {"\0"};
    while (1){
        r = fread(bayt_buffer,512,1,file);
        if (r==0) break;
        if (bayt_buffer[0]==0xff && bayt_buffer[1]==0xd8 && bayt_buffer[2]==0xff){
            jpeg++;
            fclose(m);
            sprintf(str,"%03d.jpg",jpeg);
            printf("%03d.jpg",jpeg);
            m = fopen(str,"w");

        }
        fwrite(bayt_buffer,512,1,m);

    }
    printf("%d\n",jpeg);


    fclose(file);
    return 0;

}
