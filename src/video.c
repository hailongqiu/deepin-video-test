
#include "video.h"


int video_open(char *dev, Video *video)
{
    if (!dev)
    {
        dev = VIDEO_DEVICE_0;
    }
    video->fd = open(dev, O_RDWR);
    //
    puts("video_open...");
    struct v4l2_input input;
    struct v4l2_audio audio;
    memset(&input, 0, sizeof(input));
    memset(&audio, 0, sizeof(audio));

    int index;
    if (-1 == ioctl (video->fd, VIDIOC_G_INPUT, &index))
    {
        perror("错误...");
        exit (EXIT_FAILURE);
    }
    input.index = index;
    //
    if (-1 == ioctl (video->fd, VIDIOC_ENUMINPUT, &input))
    {
        perror("video_enum..put");
        exit (EXIT_FAILURE);
    }
    printf("input.index:%d\n", input.index);
    printf("input.name:%s\n", input.name);

    return video->fd;
}

void video_set_format(
            Video *video, 
            const Opt opt, 
            const int stream_flag
            )
{
    video->format.type = stream_flag;
    video->format.fmt.pix.width = opt.width;
    video->format.fmt.pix.height = opt.height;
    video->format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    //
    if (ioctl(video->fd, VIDIOC_S_FMT, video->format) == -1)
    {
        perror("获取视频格式错误...");
    }
}

void video_close(Video *video)
{
    close(video->fd);
}


void option_init(Opt *opt)
{
    opt->verbose = 0;
    opt->width   = 640;
    opt->height  = 480;
}

int main(int argc, char *argv[])
{
    Opt   opt;
    Video video;
    int stream_flag = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    // video_init();
    //
    option_init(&opt);
    // 开发设备. video_open();
    if (-1 == video_open(NULL, &video))
    {
        perror("/dev/videXX 打开错误!!... ...\n");
        exit (-1);
    }
    // 获取设备信息.
    memset(&video.format, 0, sizeof(video.format)); // 清除.
    video.format.type = stream_flag;
    video.format.fmt.pix.width = opt.width;
    video.format.fmt.pix.height = opt.height;
    video.format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    //
    if (ioctl(video.fd, VIDIOC_S_FMT, video.format) == -1)
    {
        perror("获取视频格式错误...");
    }
    //video_set_format(&video, opt, stream_flag);
    // 测试.
    printf("width:%d\n", video.format.fmt.pix.width);
    // buffer_init();
    // 关闭连接.
    video_close(&video);
    return 0;
}


