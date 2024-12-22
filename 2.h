#pragma once


#include <iostream>
#include <algorithm>
#include <string_view>
#include <ranges>
#include <vector>



class Switch
{
public:

    void Initialize();
    int getNumPort();
    std::string_view getFullName();

private:
    std::string name = "sw1";
    std::string manufacturer = "Cisco";
    int number_of_ports = 48;
};


class CiscoSwitch : public Switch
{
public:
    CiscoSwitch(std::string_view name, int ports);

private:
    std::string name;
    std::string manufacturer;
    int number_of_ports;
};

class HuaweiSwitch : public Switch
{
public:
    HuaweiSwitch(std::string_view name, int ports);

private:
    std::string name;
    std::string manufacturer;
    int number_of_ports;
};

class JuniperSwitch : public Switch
{
public:
    JuniperSwitch(std::string_view name, int ports);

private:
    std::string name;
    std::string manufacturer;
    int number_of_ports;
};