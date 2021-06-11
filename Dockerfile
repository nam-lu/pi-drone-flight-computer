FROM alpine

# Get dev tools for compiling
RUN apk update
RUN apk upgrade
RUN apk add --no-cache alpine-sdk cmake

WORKDIR /pi-drone-flight-computer

# Copy project dependencies
COPY external external/

WORKDIR /pi-drone-flight-computer/external/pigpio

# Fix for compiling pigpio on Linux Alpine, https://github.com/joan2937/pigpio/issues/107
RUN sed -i -e 's/ldconfig/echo ldconfig disabled/g' Makefile

# Build pigpio GPIO library
RUN make
RUN make install

WORKDIR /pi-drone-flight-computer

# Copy project source
COPY CMakeLists.txt .
COPY src src/

# Build project
WORKDIR /pi-drone-flight-computer/build
RUN cmake ..
RUN make

# Start program
ENTRYPOINT ["./PiDroneFlightComputer"]
