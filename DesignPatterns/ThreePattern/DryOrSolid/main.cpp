#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
};

class HTMLData : public Printable
{
public:
    HTMLData(std::string data) : data_(std::move(data)) {}

    std::string print() const override
    {
        return "<html>" + data_ + "<html/>";
    }
private:
    std::string data_;
};

class TextData : public Printable
{
public:
    TextData(std::string data) : data_(std::move(data)) {}

    std::string print() const override
    {
        return data_;
    }
private:
    std::string data_;
};

class JSONData : public Printable
{
public:
    JSONData(std::string data) : data_(std::move(data)) {}

    std::string print() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
private:
    std::string data_;
};

void saveTo(std::ofstream& file, const Printable& printable)
{
    file << printable.print();
}


int main()
{
    // Data in different formats
    HTMLData htmlData("<body>Hello, World!</body>");
    TextData textData("Hello, World!");
    JSONData jsonData("Hello, World!");

    // Save to file in HTML format
    std::ofstream htmlFile("file.html");
    saveTo(htmlFile, htmlData);
    htmlFile.close();

    // Save to file in Text format
    std::ofstream textFile("file.txt");
    saveTo(textFile, textData);
    textFile.close();

    // Save to file in JSON format
    std::ofstream jsonFile("file.json");
    saveTo(jsonFile, jsonData);
    jsonFile.close();

    return 0;
}
