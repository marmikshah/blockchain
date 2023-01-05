FROM ubuntu:22.04

RUN apt update && \
    apt install -y cmake git vim g++ \
    libcrypto++-dev libcrypto++-doc libcrypto++-utils

WORKDIR /app/
COPY . .
RUN make -j4

CMD ["./main.o"]