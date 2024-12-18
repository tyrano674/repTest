#include "2.h"

void Switch::Initialize() { std::cout << manufacturer << R"(:)" << name << R"(: Up )" << number_of_ports << " ports \v"; }
int Switch::getNumPort() { return number_of_ports; }
std::string_view Switch::getFullName() { return " " + manufacturer + ":" + name; }


CiscoSwitch::CiscoSwitch(std::string_view name, int ports) : name(name), number_of_ports(ports) {}
HuaweiSwitch::HuaweiSwitch(std::string_view name, int ports) : name(name), number_of_ports(ports) {}
JuniperSwitch::JuniperSwitch(std::string_view name, int ports) : name(name), number_of_ports(ports) {}