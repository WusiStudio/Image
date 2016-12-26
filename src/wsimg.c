#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_DEFINE
#include "stb.h"

#include "wsimg.h"


struct wsimg_info wsimg_read_info(const char * img_path)
{
    struct wsimg_info result;
    if(img_path)
    {
        stbi_info(img_path, &result.width, &result.height, &result.channels);
    }
    return result;
}

const unsigned char * wsimg_read_data(const char * img_path, struct wsimg_info * img_info)
{
    unsigned char * result = NULL;

    if(img_path && img_info)
    {
        result = stbi_load(img_path, &img_info->width, &img_info->height, &img_info->channels, 4);
    }
    return result;
}

void wsimg_free(const unsigned char * data)
{
    free((void *)data);
}