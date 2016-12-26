#include "wsimg.h"
#include "stdio.h"


int main(int argc, char ** argv)
{
    int i = 0, j = 0;
    for(i = 1; i < argc; ++i)
    {
        struct wsimg_info img_info = wsimg_read_info(argv[i]);
        if(!img_info.width || !img_info.height || !img_info.channels)
        {
            printf("read %s info failed!\r\n", argv[i]);
            continue;
        }
        printf("%s  width: %d, height: %d, channels: %d\r\n", argv[i], img_info.width, img_info.height, img_info.channels);

        const unsigned char * data = wsimg_read_data(argv[i], &img_info);
        if(!data)
        {
            printf("read %s data failed!\r\n", argv[i]);
            continue;
        }

        printf("%s data: ", argv[i]);
        for(j = 0; j < img_info.width * img_info.height; j++)
        {
            printf("%d, %d, %d, %d\t", *(data + j * 4 + 0), *(data + j * 4 + 1), *(data + j * 4 + 2), *(data + j * 4 + 3));
        }
        printf("\r\n");

        wsimg_free(data);

        printf("%s data: ", argv[i]);
        for(j = 0; j < img_info.width * img_info.height; j++)
        {
            printf("%d, %d, %d, %d\t", *(data + j * 4 + 0), *(data + j * 4 + 1), *(data + j * 4 + 2), *(data + j * 4 + 3));
        }
        printf("\r\n");

    }
    return 0;
}