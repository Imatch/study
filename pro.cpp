
t密码
   sudo passwd root
2.mysql链接问题，/usr/inclue目录下没有mysql.h头文件
   sudo apt-get install libmysqlclient-dev -y 
   sudo apt-get install mysql-client

3.设置允许mysql远程连接
 1.sudo vi /etc/mysql/mysql.conf.d/mysqld.cnf
    注释掉bind-address = 127.0.0.1
 2.终端进入mysql
   grant all privileges on *.* to 'root'@'%' identified by '123456';　　#root为远程登录用户，123456为远程登录用户的密码
   GRANT ALL PRIVILEGES ON *.* TO root@'指定的IP地址' IDENTIFIED BY 'root用户密码' WITH GRANT OPTION;
 3.flush privileges;
 4.sudo service mysql restart

#服务管理
#启动
sudo service mysql start
#停止
sudo service mysql stop
#服务状态
sudo service mysql status


mysql初始密码问题：
1.先stop你的myslq服务，service mysql stop或者  /etc/init.d/mysqld stop
2.mysqld_safe --skip-grant-tables &   （设置成安全模式）
3.mysql -uroot -p enter
4.use mysql;
5.UPDATE user SET password=password("test123") WHERE user='root'; 
6.flush privileges;


g++ main.c db.c cJSON.c  -o server -I /usr/include/mysql -L /usr/lib/mysql -lmysqlclient -lpthread -lstdc++ 


4.报错：/usr/bin/ld: cJSON.o: undefined reference to symbol 'floor@@GLIBC_2.2.5'
编译参数加 -lm

5.报错
In file included from /usr/include/c++/5/deque:63:0,
                 from /usr/include/c++/5/queue:60,
                 from tcpServer.h:4,
                 from define.h:25,
                 from main.cpp:1:
/usr/include/c++/5/bits/stl_uninitialized.h:59:1: error: expected initializer before ‘namespace’
 namespace std _GLIBCXX_VISIBILITY(default)
 ^
makefile:41: recipe for target 'main.o' failed

原因：文件中少了分号。


6.报错
ubuntu@VM-0-8-ubuntu:~/leishen$ g++ lsTcpServer.cpp -c
In file included from functionLib.h:8:0,
                 from lsTcpServer.h:5,
                 from lsTcpServer.cpp:1:
define.h:36:8: error: ‘LsTcpServer’ does not name a type
 extern LsTcpServer *g_oTcp;
原因：头文件相互包含，在lsTcpServer.cpp文件中，define.h和lsTcpServer.h头文件包含顺序调换







1进入配置文件vi /etc/mysql/mysql.conf.d/mysqld.cnf
2.在mysqld下添加skip-grant-tables   //skip-external-locking
3.重启mysql服务sudo service mysql start，sudo service mysql status
4.进入mysql，use mysql， 执行update mysql.user set authentication_string=password('654321') where user = 'root'
	//UPDATE user SET password=password("test123") WHERE user='root'; 如果用这句会报错Unknown column 'password' in 'field list
5.退出，进入配置文件，把添加的那行删除，保存退出
6.重启mysql


解决乱码问题:
show variables like 'character_set%';  //查看数据库编码格式
sudo vi /etc/mysql/mysql.conf.d/mysqld.cnf
打开文件增加相应字段
[client]
default-character-set=utf8
[mysql]
default-character-set=utf8
[mysqld]
#
# * Basic Settings
#
user            = mysql
pid-file        = /var/run/mysqld/mysqld.pid
socket          = /var/run/mysqld/mysqld.sock
port            = 3306
basedir         = /usr
datadir         = /var/lib/mysql
tmpdir          = /tmp
lc-messages-dir = /usr/share/mysql
character-set-server=utf8
init_connect='SET collation_connection=utf8_unicode_ci'
init_connect='SET NAMES utf8'
collation-server=utf8_unicode_ci
skip-character-set-client-handshake




linux安装lua
curl -R -O http://www.lua.org/ftp/lua-5.3.5.tar.gz
tar zxf lua-5.3.5.tar.gz  	//-x | --extract | --get 从存档展开文件
				//-z | --gzip | --ungzip 用gzip对存档压缩或解压
				//-f | --file [HOSTNAME:]F 指定存档或设备（缺省为 /dev/rmt0）
				//-v | --verbose 详细显示处理的文件
cd lua-5.3.5
make linux test
make test  //会输出两行字符串
make install


alter table sitelist add column com_pro_coding varchar(64) NOT NULL COMMENT '工单号';

sudo find / -name libpthread.*


recv函数返回值为size的问题，客户端send中，发送长度不能用sizeof，应该为包头长度+strlen(包体长度) + 1;




