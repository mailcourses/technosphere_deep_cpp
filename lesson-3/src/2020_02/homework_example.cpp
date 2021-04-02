class Parser
{
    void DigitTokenHandler(token)
    {

    }
    void parse(const std::string &text)
    {
        // ...
        std::string token = read_next_token();
        if (isDigit(token)){
            DigitTokenHandler(token);
        }
    }
}

int main()
{
    Parser parser;
    std::string text("123 abc 12ab");
    // ...
    // parser.setCallbackDigitToker(my_token_func);
    // Очень плохое наименование.
    parser.parse(text);
}
