---

# ParaFetech

**ParaFetech** is a simple and customizable system information tool for Windows, designed to provide detailed system statistics in a user-friendly and colorful ASCII art format. This tool is written in C++ and offers a clean, informative display of various system parameters.

## Features

- Displays system information including OS version, architecture, CPU, memory, disk space, uptime, and user name.
- Customizable output with color support using ANSI escape codes.
- Easily extendable to include additional system metrics.

## Requirements

- **C++ Compiler**: Supports g++ or any compatible C++ compiler.
- **Windows OS**: Designed for Windows environments.

## Installation

1. **Clone the repository**:

    ```sh
    git clone https://github.com/yourusername/ParaFetech.git
    ```

2. **Navigate to the project directory**:

    ```sh
    cd ParaFetech
    ```

3. **Build the project**:

    Using `g++`:

    ```sh
    g++ src/main.cpp -o bin/ParaFetech
    ```

4. **Run the tool**:

    ```sh
    bin/ParaFetech
    ```

## Usage

Simply run the executable from the command line to see the system information displayed in a colorful and readable format. The tool outputs various details about the system such as:

- **OS Version**
- **Architecture**
- **CPU Cores**
- **Memory**
- **Disk Space**
- **Uptime**
- **User Name**

## Example Output

```

  ____                   _____    _       _     
 |  _ \ __ _ _ __ __ _  |  ___|__| |_ ___| |__  
 | |_) / _` | '__/ _` | | |_ / _ \ __/ __| '_ \ 
 |  __/ (_| | | | (_| | |  _|  __/ || (__| | | |
 |_|   \__,_|_|  \__,_| |_|  \___|\__\___|_| |_|
                                                
OS: 10.0
Architecture: x64 or x86
CPU: Your CPU CORES
Memory: Total Memory aka RAM (as gib)
x.zy GiB Free
Disk: zyz.00 GiB Total
xyz GiB Free
Uptime: 1 Hours
User: amitx
```

## Customization

To customize the output or add more features, you can edit the `src/main.cpp` file. For example, you can change the colors, add new metrics, or adjust the ASCII art logo.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
