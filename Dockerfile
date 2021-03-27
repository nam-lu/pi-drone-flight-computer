FROM alpine

# Get dev tools for compiling
RUN apk update
RUN apk upgrade
RUN apk add --no-cache alpine-sdk cmake

# Clone GPIO library
RUN git clone -b v79 --single-branch https://github.com/joan2937/pigpio.git

WORKDIR /pigpio

# Fix for compiling on alpine, https://github.com/joan2937/pigpio/issues/107
RUN sed -i -e 's/ldconfig/echo ldconfig disabled/g' Makefile

# Build GPIO library
RUN make
RUN make install

WORKDIR /pi-drone-flight-computer

# Copy project source and dependencies
COPY external external/
COPY CMakeLists.txt .
COPY src src/

# Build project
WORKDIR /pi-drone-flight-computer/build
RUN cmake ..
RUN make

# Start program
ENTRYPOINT ["./PiDroneFlightComputer"]
