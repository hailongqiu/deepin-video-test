#include "video.h"


void buffer_request(Video *video, const int strem_flag)
{
    memset(&video->buffer.req, 0, sizeof(video->buffer.req));
    video->buffer.req.type = strem_flag;
    video->buffer.req.memory = V4L2_MEMORY_MMAP;
    video->buffer.req.count = BUFFER_NUM;
    // 设置视频缓冲规则.
    if (-1 == ioctl(video->fd, VIDIOC_REQBUFS, &video->buffer.req))
    {
        perror("设置规则错误");
        exit (EXIT_FAILURE);
    }

    video->buffer.buf = calloc(video->buffer.req.count, 
                            sizeof(video->buffer.buf));
    assert(video->buffer.buf != NULL);

}

void buffer_init(Video *video, const int stream_flag)
{
    int n_buffer;
    buffer_request(video, stream_flag);
    for (n_buffer; n_buffer < video->buffer.req.count; n_buffer++)
    {
        //buffer_mmap
        //buffer_enqueue
        //
    }
}

int video_open(char *dev, Video *video)
{
    if (!dev)
    {
        dev = VIDEO_DEVICE_0;
    }
    video->fd = open(dev, O_RDWR | O_NONBLOCK);
    return video->fd;
}

void video_get_fromat(Video *video)
{
    memset(&video->format, 0, sizeof(video->format));
    video->format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    video->format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (-1 == ioctl(video->fd, VIDIOC_G_FMT, &video->format))
        perror("获取信息出错");
}

void video_set_format(
            Video *video, 
            const Opt opt, 
            const int stream_flag
            )
{
    memset(&video->format, 0, sizeof(video->format));
    video->format.type = stream_flag;
    video->format.fmt.pix.width = opt.width;
    video->format.fmt.pix.height = opt.height;
    video->format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    //
    if (-1 == ioctl(video->fd, VIDIOC_S_FMT, &video->format))
    {
        perror("设置视频格式错误...");
        exit (EXIT_FAILURE);
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
    /*
     * video_init
     */
    // video_init();
    //
    option_init(&opt);
    // 开发设备. video_open();
    if (-1 == video_open(NULL, &video))
    {
        perror("/dev/videXX 打开错误!!... ...\n");
        exit (EXIT_FAILURE);
    }
    // 设置设备信息.
    video_set_format(&video, opt, stream_flag);
    // 获取设备信息.
    //video_get_fromat(&video);
    buffer_init(&video, stream_flag);
    // 关闭连接.
    video_close(&video);
    exit (EXIT_SUCCESS);
}


