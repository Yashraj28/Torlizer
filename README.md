
# Torolizer

Torolize is a C-based project that establishes a connection to a proxy server and routes traffic to a specified host and port. It uses a SOCKS-like protocol structure for request and response communication. This project is ideal for understanding socket programming, proxy server interactions, and basic network protocols.


## Features

- Proxy Connection: Connects to a proxy server for routing traffic
- SOCKS-Like Protocol: Implements custom request and response structures for client-proxy communication.
- Simple Usage: Accepts host and port as command-line arguments to establish the connection.



## Getting Started

### Prerequisites
- GCC or any C compiler
- Basic understanding of socket programming
- Proxy server running at 127.0.0.1:7777
## Installation

- Clone the repository:

```bash
  git clone <repository_url>
  cd torolize
```
- Compile the source code:
```bash
  gcc -o torolize torolize.c -I.
```   
## Usage
- Run the program with the following syntax:

```bash
./torolize <host> <port>
```

- Example:
```bash
./torolize 192.168.1.1 80
```
## Protocol Specification
The request and response structures are designed as follows:
### Request Structure

| Field    | Size     | Description                          |
|----------|----------|--------------------------------------|
| `VN`     | 1 byte   | Version number                      |
| `CD`     | 1 byte   | Command code                        |
| `DSTPORT`| 2 bytes  | Destination port (network byte order)|
| `DSTIP`  | 4 bytes  | Destination IP address              |
| `USERID` | 8 bytes  | User ID                             |

### Response Structure

| Field      | Size     | Description               |
|------------|----------|---------------------------|
| `VN`       | 1 byte   | Version number            |
| `CD`       | 1 byte   | Command code              |
| `_DSTPORT` | 2 bytes  | Destination port          |
| `__DSTIP`  | 4 bytes  | Destination IP address    |
