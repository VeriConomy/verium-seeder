FROM alpine:3.15.4 as builder

RUN apk update && apk add \
    g++ \
    gcc \
    libc-dev \
    make \
    git \
    openssl-dev \
    curl-dev \
    libconfig-dev \
    boost-dev && \
    mkdir /app

WORKDIR /app

COPY . .

RUN make

# Now that we have a build, let's create our docker
FROM alpine:3.15.4

ENV NS_HOSTNAME="" \
    HOST_HOSTNAME="" \
    SOA_MAIL=""

EXPOSE 53/tcp 53/udp

COPY --from=builder /app/dnsseed /usr/local/bin/

RUN apk --no-cache add \
    libgcc \
    libstdc++ \
    libconfig-dev \
    curl-dev

RUN mkdir -p /data
WORKDIR /data
VOLUME ["/data"]

COPY entrypoint.sh /opt/entrypoint.sh

ENTRYPOINT ["/opt/entrypoint.sh"]
