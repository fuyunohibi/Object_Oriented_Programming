#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Writer
{
public:
    // TODO: pure virtual function write needs to be implemented
    virtual void write(const string &str) const = 0;
    virtual ~Writer() = default;
};

// Implement the Writer class for HTML output
class HTMLWriter : public Writer
{
public:
    HTMLWriter(ofstream &ofs) : ofs_(ofs) {}

    void write(const string &str) const override
    {
        ofs_ << str; // write to the file stream instead of cout
    }

private:
    ofstream &ofs_;
};

// class for generic HTML element
class Doc_element
{
private:
    string name_;
    vector<Doc_element> children_;

public:
    void write_document(const Writer &w) const
    {
        w.write("<!DOCTYPE html>\n");
        w.write("<html>\n");
        write_to(w, 1); // Write the contents of the document
        w.write("</html>\n");
    }

    // Write the contents of this element and its children to the specified writer
    void write_to(const Writer &w, int lv) const
    {
        // Write the opening tag
        for (int i = 0; i < lv; ++i)
            w.write("  "); // Indent according to the current level
        if (children_.empty())
        {
            // text node, don't add angle brackets
            w.write(name_ + "\n");
        }
        else
        {

            // not a text node, add angle brackets
            w.write("<" + name_ + ">\n");

            // Write - children nodes
            for (const auto &child : children_)
                child.write_to(w, lv + 1);

            // Write - closing tag
            for (int i = 0; i < lv; ++i)
                w.write("  "); // Indent according to the current level
            w.write("</" + name_ + ">\n");
        }
    }

    // Create a text node with the specified content
    static Doc_element text(const string &t)
    {
        return Doc_element(t);
    }

    // Create an element with the specified name and children
    explicit Doc_element(const string &n) : name_(n) {}

    Doc_element(const string &n, const vector<Doc_element> &children)
        : name_(n), children_(children) {}
};

int main()
{
    ofstream ofs("output.html");
    HTMLWriter html_writer(ofs);
    auto t = Doc_element::text("Text001");
    auto e = Doc_element("em", {t, Doc_element("p", {t})});
    auto tr = Doc_element("tr", {Doc_element("td", {t}), Doc_element("td", {t}), Doc_element("td", {t})});
    auto tbl = Doc_element("table", {tr, tr, tr});
    tbl.write_document(html_writer);
    return 0;
}
