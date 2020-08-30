FROM ubuntu:16.04
MAINTAINER Arslan Ali

RUN apt-get update && \
	apt-get install -y build-essential git cmake gcc make autoconf libtool pkg-config

WORKDIR /src

COPY CMakeLists.txt main.cpp ./

RUN cmake . && make

FROM ubuntu:16.04

WORKDIR /opt/hello-world

COPY --from=build /src/helloworld ./

CMD ["./helloworld"]


