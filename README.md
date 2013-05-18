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

    
