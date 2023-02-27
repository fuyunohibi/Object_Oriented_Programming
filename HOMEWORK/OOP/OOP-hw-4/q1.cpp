#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>™
#include <vector>
#include <optional>

template <typename Container>
auto split(const std::string &s, char delimiter, Container &container)
{
    std::istringstream tokenStream(s);
    for (std::string token; std::getline(tokenStream, token, delimiter);)
    {
        container.emplace_back(std::move(token));
    }
}

void run_command(const std::string &cmd, std::unordered_map<std::string, double> &vars)
{
    std::vector<std::string> tokens;
    split(cmd, ' ', tokens);

    if (tokens.empty())
    {
        return;
    }

    if (tokens[0] == "set")
    {
        if (tokens.size() != 3)
        {
            std::cout << "Invalid syntax\n";
            return;
        }
        vars[tokens[1]] = std::stod(tokens[2]);
    }
    else if (tokens[0] == "get")
    {
        if (tokens.size() != 2)
        {
            std::cout << "Invalid syntax\n";
            return;
        }
        auto it = vars.find(tokens[1]);
        if (it != vars.end())
        {
            std::cout << it->second << '\n';
        }
        else
        {
            std::cout << "<N/A>\n";
        }
    }
    else if (tokens[0] == "add" || tokens[0] == "sub")
    {
        if (tokens.size() != 3)
        {
            std::cout << "Invalid syntax\n";
            return;
        }
        auto it1 = vars.find(tokens[1]);
        auto it2 = vars.find(tokens[2]);
        if (it1 != vars.end() && it2 != vars.end())
        {
            auto result = tokens[0] == "add" ? it1->second + it2->second : it1->second - it2->second;
            std::cout << result << '\n';
        }
        else
        {
            std::cout << "<N/A>\n";
        }
    }
    else
    {
        std::cout << "Unknown command\n";
    }
}

void run_console(std::unordered_map<std::string, double> &vars)
{
    std::string line;
    while (true)
    {
        std::cout << "cmd> ";
        std::cout.flush();

        if (!std::getline(std::cin, line))
        {
            break;
        }

        if (line == "quit")
        {
            break;
        }

        run_command(line, vars);
    }
}

int main()
{
    std::unordered_map<std::string, double> vars;
    run_console(vars);
    return 0;
}