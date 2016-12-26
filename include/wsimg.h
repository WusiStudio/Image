#pragma once
#ifndef __WS_IMG_H__
#define __WS_IMG_H__

#ifdef __cplusplus
   #define WS_EXTERN   extern "C"
#else
   #define WS_EXTERN   extern
#endif

typedef struct wsimg_info
{
    int width;
    int height;
    int channels;
} wsimg_info;

WS_EXTERN struct wsimg_info wsimg_read_info(const char * img_path);
WS_EXTERN const unsigned char * wsimg_read_data(const char * img_path, struct wsimg_info * img_info);
WS_EXTERN void wsimg_free(const unsigned char * data);


#endif //__WS_IMG_H__