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
    
