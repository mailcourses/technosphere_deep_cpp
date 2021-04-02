#include <iostream>

struct Device
{
    virtual void log(const std::string &message) = 0;
};

struct Console : Device
{
    virtual void log(const std::string &message) override
    {
        std::cout << "[Console::log] " << message << std::endl;
    }
};

struct Printer : Device
{
    virtual void log(const std::string &message) override
    {
        std::cout << "[Printer::log] " << message << std::endl;
    }
};

enum class Devices
{
    PRINTER,
    CONSOLE
};

class Endpoint
{
public:
    Endpoint(const Devices &device_type);
    // ЗАПРЕЩАЕМ копировать объекты.
    Endpoint(const Endpoint&) = delete;
    Endpoint& operator=(const Endpoint&) = delete;

    void send_query(const std::string &query) const;
private:
    mutable Device *device_;
};

Endpoint::Endpoint(const Devices &device_type)
{
    if (device_type == Devices::CONSOLE) {
        device_ = new Console();
    } else if (device_type == Devices::PRINTER) {
        device_ = new Printer();
    }
}

void
Endpoint::send_query(const std::string &query) const
{
    std::cout << "Endpoint::send_query" << std::endl;
    device_->log(query);
}

int main()
{
    Endpoint endpoint1(Devices::CONSOLE);
    endpoint1.send_query("q=daschunds");
    // Ошибка компиляции.
    // Endpoint endpoint2 = endpoint1;
}
