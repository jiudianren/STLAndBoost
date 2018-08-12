FROM zouzias/boost:1.67.0

RUN  cd /usr/include/ && rm -f boost_1_*.tar.gz 
RUN  mkdir -p /home/boost &&  cp /usr/include/boost  /home/boost
WORKDIR  /home/boost
RUN bash ./bootstrap.sh --prefix=/usr --exec-prefix=/usr
RUN bash ./b2 install

#°²×°

RUN apt-get update
RUN apt-get -y install  gdb  cmake
RUN  mkdir -p  /home/git/src
COPY .  /home/git/src
RUN  mkdir  /home/git/src/build

WORKDIR  /home/git/src/build
RUN     cmake -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_COMPILER=`which c++` ..
RUN     make install
ENV     LD_LIBRARY_PATH  /home/git/src/build/lib:$LD_LIBRARY_PATH

CMD ["/home/git/src/build/bin/myboost"]

ENTRYPOINT /bin/bash