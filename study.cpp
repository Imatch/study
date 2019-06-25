1.mkdir src bin lib
2.把opencv_world400d.lib拷贝到lib目录;把opencv_world400d.dll和opencv_ffmpeg400_64.dll拷贝到bin目录;把include文件夹拷贝到src目录下.
3.设置属性,常规输出目录和调试工作目录了设置为../../bin;c/c++常规附加包含目录设置为../include;链接器，常规:附加包含目录设置为../../lib,输入附加依赖库把opencv_world400d.lib加上.


视频类需要下载openh264链接库。地址 https://github.com/cisco/openh264/releases

FFMPEG 
1.下载解压ffmpeg
2.把bin目录加入到path变量中
3.ffmpeg -i /home/1.mp3 -vn 1.mp3  //抽取音频，抽取视频-an
