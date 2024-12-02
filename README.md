# Torolizer


### Torolize is a C-based project that establishes a connection to a proxy server and routes traffic to a specified host and port. It uses a SOCKS-like protocol structure for request and response communication. This project is ideal for understanding socket programming, proxy server interactions, and basic network protocols.

---

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)


---

## Features
- Proxy Connection: Connects to a proxy server for routing traffic.
- SOCKS-Like Protocol: Implements custom request and response structures for client-proxy communication.
- Simple Usage: Accepts host and port as command-line arguments to establish the connection

---

## Installation

### Prerequisites
1. GCC or any C compiler
2. Basic understanding of socket programming
3. Proxy server running at 127.0.0.1:7777

### Steps
``bash
# Clone the repository
git clone <repository_url>
cd torolize

Compile the source code:
gcc -o torolize torolize.c -I.

