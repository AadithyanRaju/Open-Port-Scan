#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Usage: bash $0 <target_ip> <start_port> <end_port>"
    exit 1
fi
target_ip="$1"
start_port="$2"
end_port="$3"

for ((port = start_port; port <= end_port; port++)); do
    (echo >/dev/tcp/"$target_ip"/"$port") >/dev/null 2>&1 && echo "Port $port is open" && $(echo "$port" >> open_ports.txt)
done
