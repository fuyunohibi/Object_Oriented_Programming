#ifndef HTML_FOR_Q3_HPP
#define HTML_FOR_Q3_HPP

#include <memory>
#include <sstream>
#include <string>

namespace nse
{
    namespace html
    {

        class node
        {
        public:
            virtual ~node() {}
            virtual std::string to_string() const = 0;
            virtual void set_attribute(const std::string &name, const std::string &value) = 0;
            virtual void add_child(std::unique_ptr<node> child) {}
        };

        class element : public node
        {
        public:
            explicit element(const std::string &tag_name) : tag_name_(tag_name) {}

            std::string to_string() const override
            {
                std::stringstream ss;
                ss << "<" << tag_name_;
                for (const auto &attr : attributes_)
                {
                    ss << " " << attr.first << "=\"" << attr.second << "\"";
                }
                if (children_.empty())
                {
                    ss << "/>";
                }
                else
                {
                    ss << ">";
                    for (const auto &child : children_)
                    {
                        ss << child->to_string();
                    }
                    ss << "</" << tag_name_ << ">";
                }
                return ss.str();
            }

            void set_attribute(const std::string &name, const std::string &value) override
            {
                attributes_.push_back({name, value});
            }

            void add_child(std::unique_ptr<node> child) override
            {
                children_.push_back(std::move(child));
            }

        private:
            std::string tag_name_;
            std::vector<std::pair<std::string, std::string>> attributes_;
            std::vector<std::unique_ptr<node>> children_;
        };

        inline std::unique_ptr<element> make_element(const std::string &tag_name)
        {
            return std::make_unique<element>(tag_name);
        }

    } // namespace html
} // namespace nse

#endif // HTML_FOR_Q3_HPP
