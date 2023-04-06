#include <iostream>
#include <vector>
#include <string>

class Writer
{
public:
    virtual void write(const std::string &str) const = 0;
    virtual ~Writer() = default;
};

class HTMLWriter : public Writer
{
public:
    void write(const std::string &str) const override
    {
        std::cout << str;
    }
};

class Doc_element
{
public:
    void write_document(const Writer &w) const
    {
        write_to(w, 0);
    }

    void write_to(const Writer &w, int lv) const
    {
        for (int i = 0; i < lv; ++i)
            w.write("  ");
        w.write("<" + name_ + ">\n");
        for (const auto &child : children_)
            child.write_to(w, lv + 1);
        for (int i = 0; i < lv; ++i)
            w.write("  ");
        w.write("</" + name_ + ">\n");
    }

    static Doc_element text(const std::string &t)
    {
        return Doc_element(t);
    }

    explicit Doc_element(const std::string &n) : name_(n) {}

    Doc_element(const std::string &n, const std::vector<Doc_element> &children)
        : name_(n), children_(children) {}

private:
    std::string name_;
    std::vector<Doc_element> children_;
};

int main()
{
    auto t = Doc_element::text("Text001");
    auto e = Doc_element("em", {t, Doc_element("p", {t})});
    auto tr = Doc_element("tr", {Doc_element("td", {t}), Doc_element("td", {t}), Doc_element("td", {t})});
    auto tbl = Doc_element("table", {tr, tr, tr});
    HTMLWriter html_writer;
    tbl.write_document(html_writer);
    return 0;
}
