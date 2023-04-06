#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// TODO: Implement the HTMLWriter class and the write_document function in the Doc_element class

class Writer
{
public:
    virtual void write(const std::string &str) const = 0;
    virtual ~Writer() = default;
};

class HTMLWriter : public Writer
{
public:
    HTMLWriter(std::ostream &output) : output_file_(output) {}

    void write(const std::string &str) const override
    {
        output_file_ << str;
    }

private:
    std::ostream &output_file_;
};

class Doc_element
{
public:
    void write_document(const Writer &w) const;
    void write_to(const Writer &w, int lv) const;
    static Doc_element text(const std::string &t);
    explicit Doc_element(const std::string &n);
    Doc_element(const std::string &n, const std::vector<Doc_element> &children);

private:
    std::string name_;
    std::vector<Doc_element> children_;

    void write_indent(const Writer &w, int lv) const;
};

void Doc_element::write_indent(const Writer &w, int lv) const
{
    for (int i = 0; i < lv; ++i)
    {
        w.write("  ");
    }
}

void Doc_element::write_document(const Writer &w) const
{
    w.write("<!DOCTYPE html>\n"); // Include the HTML declaration
    write_to(w, 0);
}

void Doc_element::write_to(const Writer &w, int lv) const
{
    write_indent(w, lv);
    w.write("<" + name_ + ">\n");

    for (const auto &child : children_)
    {
        child.write_to(w, lv + 1);
    }

    write_indent(w, lv);
    w.write("</" + name_ + ">\n");
}

Doc_element Doc_element::text(const std::string &t)
{
    return Doc_element("p", {Doc_element("em", {Doc_element::text(t)})});
}

Doc_element::Doc_element(const std::string &n)
    : name_(n) {}

Doc_element::Doc_element(const std::string &n, const std::vector<Doc_element> &children)
    : name_(n), children_(children) {}

int main()
{
    auto t = Doc_element::text("Text001");
    auto tr = Doc_element("tr", {Doc_element("td", {t}), Doc_element("td", {t}), Doc_element("td", {t})});
    auto tbl = Doc_element("table", {tr, tr, tr});

    // Define Writer object to output the HTML document
    std::ofstream file("output.html");
    HTMLWriter html_writer(file);

    // Output the HTML document with <html> tag
    Doc_element html = Doc_element("html", {tbl});
    html.write_document(html_writer);

    return 0;
}
