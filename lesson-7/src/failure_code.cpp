#include <iostream>
#include <system_error>

enum class HttpError
{
    NoError = 200,
    NotFound = 404
};

class HttpCategory : public std::error_category
{
public:
    HttpCategory() = default;
    ~HttpCategory() = default;
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int err) const override
    {
        switch(err) {
            case 200:
                return std::string("ok");
            case 404:
                return std::string("not found");
        }
        return std::string("undefined error");
    }
public:
    HttpError err;
};

std::error_code make_error_code(HttpError error)
{
    static HttpCategory instance;
    return std::error_code(static_cast<int>(error), instance);
}

std::error_code download( const std::string & url )
{
    //...
    return make_error_code(HttpError::NotFound);
}

int main()
{
    auto err = download("https://google.com");
    std::cerr << err << std::endl;
    std::cerr << err.message() << std::endl;
    return 0;
}
