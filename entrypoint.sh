#!/bin/sh -e

if [ -z "$NS_HOSTNAME" ]
then
    echo "Missing envirnoment variable NS_HOSTNAME"
    exit 1
fi

if [ -z "$HOST_HOSTNAME" ]
then
    echo "Missing envirnoment variable HOST_HOSTNAME"
    exit 1
fi

if [ -z "$SOA_MAIL" ]
then
    echo "Missing envirnoment variable SOA_MAIL"
    exit 1
fi

CMD="/usr/local/bin/dnsseed -n $NS_HOSTNAME -h $HOST_HOSTNAME -m $SOA_MAIL"

exec $CMD
