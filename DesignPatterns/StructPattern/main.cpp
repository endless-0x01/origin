#include <string>
#include <algorithm>
#include <iostream>
#include <memory>

class TextBlock {
public:
    virtual std::string render(const std::string& text) = 0;
};

class Text : public TextBlock {
public:
    std::string render(const std::string& text) override {
        return text;
    }
};

class Paragraph : public TextBlock {
    std::unique_ptr<TextBlock> inner;
public:
    explicit Paragraph(std::unique_ptr<TextBlock> inner) : inner(std::move(inner)) {}
    std::string render(const std::string& text) override {
        return "<p>" + inner->render(text) + "</p>";
    }
};

class Reversed : public TextBlock {
    std::unique_ptr<TextBlock> inner;
public:
    explicit Reversed(std::unique_ptr<TextBlock> inner) : inner(std::move(inner)) {}
    std::string render(const std::string& text) override {
        std::string reversed_text = inner->render(text);
        std::reverse(reversed_text.begin(), reversed_text.end());
        return reversed_text;
    }
};

class Link : public TextBlock {
    std::unique_ptr<TextBlock> inner;
    std::string url;
public:
    Link(std::unique_ptr<TextBlock> inner, const std::string& url) : inner(std::move(inner)), url(url) {}
    std::string render(const std::string& text) override {
        return "<a href=" + url + ">" + inner->render(text) + "</a>";
    }
};

class VeryHeavyDatabase {
public:
    virtual std::string GetData(const std::string& key) {
        return "value";
    }
};

class OneShotDB : public VeryHeavyDatabase {
    VeryHeavyDatabase* real_object;
    size_t shots;
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots) : real_object(real_object), shots(shots) {}
    std::string GetData(const std::string& key) override {
        if (shots > 0) {
            --shots;
            return real_object->GetData(key);
        }
        else {
            return "error";
        }
    }
};

int main() {
    auto text = std::make_unique<Text>();
    auto paragraph = std::make_unique<Paragraph>(std::move(text));
    std::cout << paragraph->render("Hello world") << std::endl;

    auto text2 = std::make_unique<Text>();
    auto reversed = std::make_unique<Reversed>(std::move(text2));
    std::cout << reversed->render("Hello world") << std::endl;

    auto text3 = std::make_unique<Text>();
    auto link = std::make_unique<Link>(std::move(text3), "netology.ru");
    std::cout << link->render("Hello world") << std::endl;

    VeryHeavyDatabase real_db;
    OneShotDB limit_db(&real_db, 2);
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

    return 0;
}
