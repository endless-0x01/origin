#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "Console Log: " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    explicit FileLogCommand(const std::string& filePath) : filePath_(filePath) {}

    void print(const std::string& message) override {
        std::ofstream outputFile(filePath_, std::ios::app);
        if (outputFile.is_open()) {
            outputFile << "File Log: " << message << std::endl;
            outputFile.close();
        }
        else {
            std::cout << "Failed to open file: " << filePath_ << std::endl;
        }
    }

private:
    std::string filePath_;
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main() {
    ConsoleLogCommand consoleLog;
    FileLogCommand fileLog("log.txt");

    print(consoleLog, "This is a console log message.");
    print(fileLog, "This is a file log message.");

    return 0;
}
