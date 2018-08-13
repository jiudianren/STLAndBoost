FROM jiudianren/boostdocker:latest

RUN apt-get update &&  apt-get -y install  gdb  cmake && apt-get clean && mkdir -p  /home/git/src
COPY .  /home/git/src
RUN  mkdir  /home/git/src/build

WORKDIR  /home/git/src/build
RUN     cmake -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_COMPILER=`which g++` ..  && make install
ENV     LD_LIBRARY_PATH  /home/git/src/build/lib:$LD_LIBRARY_PATH

CMD ["/home/git/src/build/bin/myboost"]

ENTRYPOINT /bin/bash