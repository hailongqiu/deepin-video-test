深度摄像头测试.

// sudo apt-get install libv4l-dev 

ioctl 命令部分:
    http://www.dzsc.com/data/html/2009-9-15/78721.html
    VIDIOCGCAP : 获取设备性能属性, 对应struct video_capability;
    VIDIOCSFBUF : 获取 frame buffer 参数, 对应 struct video_buffer;
    VIDIOCGFBUF : 获取当前 frame buffer 参数, 对应 struct video_buffer;
    VIDIOCCAPTURE : 开始或停止捉图, 对应struct video_capture;
    VIDIOCGCHAN : 获取信道的信息, 对应 struct video_channel;
    VIDIOCGPICT : 获取图像的属性, 对应 struct video_picture;
    VIDIOCSPICT : 设置图形的属性，对应 struct video_picture;
    VIDIOCMCAPTURE : 在mmap模式下, 进行捉图, 对应 struct video_mmap;
    VIDIOCSYNC : 等待直到完成一帧捉图，对应 struct video_mbuf;
    VIDIOCGMBCF : 查看 mmap buffer 的总大小和每帧偏移地址，对应struct video mbuf;
    
    


在进行V4L2开发中，一般会用到以下的命令标志符：
1.    VIDIOC_REQBUFS：分配内存
2.    VIDIOC_QUERYBUF：把VIDIOC_REQBUFS中分配的数据缓存转换成物理地址
3.    VIDIOC_QUERYCAP：查询驱动功能
4.    VIDIOC_ENUM_FMT：获取当前驱动支持的视频格式
5.    VIDIOC_S_FMT：设置当前驱动的频捕获格式
6.    VIDIOC_G_FMT：读取当前驱动的频捕获格式
7.    VIDIOC_TRY_FMT：验证当前驱动的显示格式
8.    VIDIOC_CROPCAP：查询驱动的修剪能力
9.    VIDIOC_S_CROP：设置视频信号的边框
10. VIDIOC_G_CROP：读取视频信号的边框
11. VIDIOC_QBUF：把数据从缓存中读取出来
12. VIDIOC_DQBUF：把数据放回缓存队列
13. VIDIOC_STREAMON：开始视频显示函数
14. VIDIOC_STREAMOFF：结束视频显示函数
15. VIDIOC_QUERYSTD：检查当前视频设备支持的标准，例如PAL或NTSC。



Video4linux2一般操作流程（视频设备）：
1. 打开设备文件。 int fd=open(”/dev/video0″,O_RDWR);
2. 取得设备的capability，看看设备具有什么功能，比如是否具有视频输入等。VIDIOC_QUERYCAP,struct v4l2_capability
3. 选择视频输入，一个视频设备可以有多个视频输入。VIDIOC_S_INPUT,struct v4l2_input
4. 设置视频的制式和帧格式，制式包括PAL，NTSC，帧的格式个包括宽度和高度等。
VIDIOC_S_STD,VIDIOC_S_FMT,struct v4l2_std_id,struct v4l2_format
5. 向驱动申请帧缓冲，一般不超过5个。struct v4l2_requestbuffers
6. 将申请到的帧缓冲映射到用户空间，这样就可以直接操作采集到的帧了，而不必去复制。
7. 将申请到的帧缓冲全部入队列，以便存放采集到的数据.VIDIOC_QBUF,struct v4l2_buffer
8. 开始视频的采集。VIDIOC_STREAMON
9. 出队列以取得已采集数据的帧缓冲，取得原始采集数据。VIDIOC_DQBUF
10. 将缓冲重新入队列尾,这样可以循环采集。VIDIOC_QBUF
11. 停止视频的采集。VIDIOC_STREAMOFF
12. 关闭视频设备。close(fd);
    
