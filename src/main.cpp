#include <windows.h>
#include <Lmcons.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "ColorManager.hpp"

// Include Version Helpers header
#include <VersionHelpers.h>

/**
 * @brief Retrieves the operating system version.
 *
 * @return A string representing the OS version.
 */
std::string GetOSVersion()
{
    std::ostringstream oss;

    if (IsWindows10OrGreater())
    {
        oss << "10";
    }
    else if (IsWindows8OrGreater())
    {
        oss << "8";
    }
    else if (IsWindows7OrGreater())
    {
        oss << "7";
    }
    else
    {
        oss << "Unknown";
    }

    return oss.str();
}

/**
 * @brief Retrieves the system architecture (e.g., x64, ARM).
 *
 * @return A string representing the system architecture.
 */
std::string GetSystemArchitecture()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    switch (si.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_AMD64:
        return "x64";
    case PROCESSOR_ARCHITECTURE_ARM:
        return "ARM";
    case PROCESSOR_ARCHITECTURE_IA64:
        return "IA64";
    case PROCESSOR_ARCHITECTURE_INTEL:
        return "x86";
    default:
        return "Unknown";
    }
}

/**
 * @brief Retrieves the number of CPU cores.
 *
 * @return A string representing the number of CPU cores.
 */
std::string GetCPUInfo()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    std::ostringstream oss;
    oss << si.dwNumberOfProcessors << " Cores";
    return oss.str();
}

/**
 * @brief Retrieves the system memory information.
 *
 * @return A string representing the total and free memory.
 */
std::string GetMemoryInfo()
{
    MEMORYSTATUSEX ms;
    ms.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&ms))
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2)
            << (ms.ullTotalPhys / (1024.0 * 1024 * 1024)) << " GiB Total\n"
            << (ms.ullAvailPhys / (1024.0 * 1024 * 1024)) << " GiB Free";
        return oss.str();
    }
    return "Unknown";
}

/**
 * @brief Retrieves the disk space information for drive C:\.
 *
 * @return A string representing the total and free disk space.
 */
std::string GetDiskSpace()
{
    ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
    if (GetDiskFreeSpaceExW(L"C:\\", &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes))
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2)
            << (totalNumberOfBytes.QuadPart / (1024.0 * 1024 * 1024)) << " GiB Total\n"
            << (totalNumberOfFreeBytes.QuadPart / (1024.0 * 1024 * 1024)) << " GiB Free";
        return oss.str();
    }
    return "Unknown";
}

/**
 * @brief Retrieves the system uptime in hours.
 *
 * @return A string representing the system uptime.
 */
std::string GetUptime()
{
    ULONGLONG uptime = GetTickCount64();
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2)
        << (uptime / (1000.0 * 60 * 60)) << " Hours";
    return oss.str();
}

/**
 * @brief Retrieves the username of the currently logged-in user.
 *
 * @return A string representing the username.
 */
std::string GetUserName()
{
    char name[UNLEN + 1];
    DWORD size = sizeof(name);
    if (GetUserNameA(name, &size))
    {
        return std::string(name);
    }
    return "Unknown";
}

/**
 * @brief Retrieves the hostname of the computer.
 *
 * @return A string representing the hostname.
 */
std::string GetHostname()
{
    char hostname[256];
    if (GetComputerNameA(hostname, nullptr))
    {
        return std::string(hostname);
    }
    return "Unknown";
}

/**
 * @brief Prints a logo in the console.
 */
void PrintLogo()
{
    std::cout << Color::CYAN() <<
        R"(
  ____                   _____    _       _     
 |  _ \ __ _ _ __ __ _  |  ___|__| |_ ___| |__  
 | |_) / _` | '__/ _` | | |_ / _ \ __/ __| '_ \ 
 |  __/ (_| | | | (_| | |  _|  __/ || (__| | | |
 |_|   \__,_|_|  \__,_| |_|  \___|\__\___|_| |_|
                                                
)" << Color::RESET()
              << std::endl;
}

int main()
{
    PrintLogo();
    std::cout << "OS: " << Color::BRIGHT_GREEN() << GetOSVersion() << Color::RESET() << std::endl;
    std::cout << "Architecture: " << Color::BRIGHT_BLUE() << GetSystemArchitecture() << Color::RESET() << std::endl;
    std::cout << "CPU: " << Color::BRIGHT_YELLOW() << GetCPUInfo() << Color::RESET() << std::endl;
    std::cout << "Memory: " << Color::BRIGHT_CYAN() << GetMemoryInfo() << Color::RESET() << std::endl;
    std::cout << "Disk: " << Color::BRIGHT_MAGENTA() << GetDiskSpace() << Color::RESET() << std::endl;
    std::cout << "Uptime: " << Color::BRIGHT_RED() << GetUptime() << Color::RESET() << std::endl;
    std::cout << "User: " << Color::BRIGHT_WHITE() << GetUserName() << Color::RESET() << std::endl;
    std::cout << "Hostname: " << Color::BRIGHT_BLACK() << GetHostname() << Color::RESET() << std::endl;
    return 0;
}
