# Open-Port-Scan
This is a simple tool to find ports that are open in a given IP Address.
## Installation
```bash
git clone https://github.com/AadithyanRaju/Open-Port-Scan.git
```
## How To Use
First open a terminal and go to the path, where the script is located. Then,
```bash
bash PortScan.sh <ip address> <Start port> <End Port>
```
Example, Running with 10 threads.
```bash
bash PortScan.sh 192.168.1.1 1 10000
```

## C++ Code
It is still in development, but you can see the [code](./PortScan.cpp).

### Compiling
```bash
g++ PortScan.cpp -o PortScan
```

### Running
```bash
./PortScan <IP Address> <start port>-<end port>
```

#### Example
```bash
./PortScan 192.168.1.1 1-10000
```

