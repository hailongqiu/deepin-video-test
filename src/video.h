#ifndef __VIDEO_H__
#define __VIDEO_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <linux/videodev2.h>


#define VIDEO_DEVICE_0  "/dev/video0"
#define BUFFER_NUM      10

typedef struct _opt    Opt;
typedef struct _buffer Buffer;
typedef struct _video  Video;

struct _opt
{
    int verbose;
    int width;
    int height;
};

struct _buffer
{
    struct v4l2_requestbuffers req; // 请求.
    struct v4l2_buffer query; // 获取.
    struct {
        void *start;
        size_t length;
    }*buf;
};

struct _video
{
    int fd;
    struct v4l2_format format;
    struct v4l2_capability capability;
    Buffer buffer;
};

void buffer_request(Video *video, const int strem_flag);
void buffer_init(Video *video, const int stream_flag);
void option_init(Opt *opt); // 初始化 opt.
int  video_open(char *dev, Video *video);
void video_close(Video *video);
void video_set_format(Video *video, const Opt opt, const int stream_flag);

#endif

