#ifndef HTML_HPP
#define HTML_HPP

#include <string>

namespace html
{
    // Define HTML tags as functions
    std::string table();
    std::string table_end();
    std::string tr(const std::string &content);
    std::string td(const std::string &content);

    // Implementations of the HTML tag functions
    inline std::string table()
    {
        return "<table>";
    }

    inline std::string table_end()
    {
        return "</table>";
    }

    inline std::string tr(const std::string &content)
    {
        return "<tr>" + content + "</tr>";
    }

    inline std::string td(const std::string &content)
    {
        return "<td>" + content + "</td>";
    }
}

#endif
