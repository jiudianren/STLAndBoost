FROM ubuntu:latest

MAINTAINER Anastasios Zouzias <my_last_name@gmail.com>

ENV DEBIAN_FRONTEND noninteractive



# We pass the boost version argument as argument
ARG BOOST_VERSION
ARG BOOST_VERSION_
ENV BOOST_VERSION=${BOOST_VERSION}
ENV BOOST_VERSION_=${BOOST_VERSION_}

RUN mkdir -p /home/boost
WORKDIR /home/boost/
ENV BOOST_ROOT=/home/boost/

RUN apt-get -qq update && apt-get install -q -y software-properties-common python-software-properties
RUN add-apt-repository ppa:ubuntu-toolchain-r/test -y
RUN apt-get -qq update && apt-get install -qy g++-6 gcc git wget

RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90

RUN wget --no-check-certificate --max-redirect 3 https://sourceforge.net/projects/boost/files/boost/${BOOST_VERSION}/boost_${BOOST_VERSION_}.tar.gz
RUN tar zxf boost_${BOOST_VERSION_}.tar.gz -C /home/boost/ --strip-components=1
 
RUN bash ./bootstrap.sh --prefix=/usr --exec-prefix=/usr
RUN bash ./b2
RUN echo ${BOOST_ROOT}
#��װ

ENTRYPOINT /bin/bash