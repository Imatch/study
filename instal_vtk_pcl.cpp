
1.qt bao cannot find -lGL
sudo apt-get install libgl1-mesa-dev

2.cmake 配置vtk时Qt5_DIR-NOTFOUND
在VTK源代码文件夹下，打开CMakeLists.txt，在第二行添加
set (Qt5_DIR "/opt/Qt5.12.2/5.12.2/gcc_64/lib/cmake/Qt5")


依赖库版本一:	
	sudo apt-get install libboost-all-dev
	sudo apt-get install libeigen3-dev
	sudo apt-get install libflann-dev
依赖库版本二:
	sudo apt-get update 
	sudo apt-get install git build-essential linux-libc-dev 
	sudo apt-get 	install cmake cmake-gui 
	sudo apt-get install libusb-1.0-0-dev libusb-dev libudev-dev 
	sudo apt-get install mpi-default-dev openmpi-bin openmpi-common 
	sudo apt-get install libflann1.8 libflann-dev 
	sudo apt-get install libeigen3-dev 
	sudo apt-get install libboost-all-dev 
	sudo apt-get install libvtk5.10-qt4 libvtk5.10 libvtk5-dev
	sudo apt-get install libqhull* libgtest-dev 
	sudo apt-get install freeglut3-dev pkg-config 
	sudo apt-get install libxmu-dev libxi-dev 
	sudo apt-get install mono-complete sudo apt-get install qt-sdk openjdk-8-jdk openjdk-8-jre


一:
1.下载VTK-8.2.0.tar.gz
2.解压sudo tar -zxvf VTK-8.2.0.tar.gz
3.sudo mkdir build
用cmake-gui配置文件
	1.选VTK_Group_Qt选项
	2.将CMAKE_BUILD_TYPE改为Release
	3.VTK_QT_VERSION改为5
	按一下Configure按钮后，上面有关QT的路径应该都是上面QT5.5的安装路径。

4.sudo make
5.sudo make insatll
6.把libQVTKWidgetPlugin.so拷贝到qt安装目录/opt/Qt5.12.2/Tools/QtCreator/lib/Qt/plugins/designer/
	libQVTKWidgetPlugin.so，qtcretor才会有QVTKwidget控件。(可以用sudo find / -name 
	'libQVTKWidgetPlugin.so'查找所在的路径)

7.sudo ldconfig(不执行装pcl会报 VTK ImportError cannot open shared object file）

二:
1.下载pcl-pcl-1.9.1.tar.gz/pcl-pcl-1.8.0.tar.gz
2.解压sudo tar -xzvf pcl-pcl-1.9.1.tar.gz/pcl-pcl-1.8.0.tar.gz
3.用cmake-gui配置文件
	安装类似vtk安装
4.sudo make(途中报.hpp，.cpp文件错，用pcl1.9中的文件替换，继续sudo make）
5.sudo make install



三:qtcretor使用过程中，报头文件路径不对，跳到终端使用sudo find / -name 'filename',然后把路径加入到.pro配置文件中


	
