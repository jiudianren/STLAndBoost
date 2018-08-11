FROM ubuntu:latest
 
#no git 
MAINTAINER  jiudiaren <lianpengfei12@foxmail.com>
 
RUN apt-get update
RUN apt-get -y install g++  gdb  cmake
RUN apt-get -y install libboost-all-dev
RUN  mkdir -p  /home/git/src
COPY .  /home/git/src
RUN  mkdir  /home/git/src/build

WORKDIR  /home/git/src/build
RUN     cmake -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_COMPILER=`which c++` ..
RUN     make install
ENV     LD_LIBRARY_PATH  /home/git/src/build/lib:$LD_LIBRARY_PATH

CMD ["/home/git/src/build/bin/myboost"]