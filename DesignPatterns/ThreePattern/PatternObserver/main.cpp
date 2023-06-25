#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyWarning(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onWarning(message);
        }
    }

    void notifyError(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onError(message);
        }
    }

    void notifyFatalError(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onFatalError(message);
        }
    }

    void warning(const std::string& message) const {
        notifyWarning(message);
    }

    void error(const std::string& message) const {
        notifyError(message);
    }

    void fatalError(const std::string& message) const {
        notifyFatalError(message);
    }
};

class ConsoleWarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};

class FileErrorObserver : public Observer {
private:
    std::ofstream file;

public:
    explicit FileErrorObserver(const std::string& filePath) {
        file.open(filePath);
    }

    ~FileErrorObserver() {
        file.close();
    }

    void onError(const std::string& message) override {
        if (file.is_open()) {
            file << "Error: " << message << std::endl;
        }
    }

    void onFatalError(const std::string& message) override {
        if (file.is_open()) {
            file << "Fatal Error: " << message << std::endl;
        }
    }
};

class ConsoleAndFileFatalErrorObserver : public Observer {
private:
    std::ofstream file;

public:
    explicit ConsoleAndFileFatalErrorObserver(const std::string& filePath) {
        file.open(filePath);
    }

    ~ConsoleAndFileFatalErrorObserver() {
        file.close();
    }

    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error: " << message << std::endl;
        if (file.is_open()) {
            file << "Fatal Error: " << message << std::endl;
        }
    }
};

int main() {
    Subject subject;

    ConsoleWarningObserver consoleWarningObserver;
    FileErrorObserver fileErrorObserver("error_log.txt");
    ConsoleAndFileFatalErrorObserver consoleAndFileFatalErrorObserver("fatal_error_log.txt");

    subject.addObserver(&consoleWarningObserver);
    subject.addObserver(&fileErrorObserver);
    subject.addObserver(&consoleAndFileFatalErrorObserver);

    subject.warning("This is a warning message.");
    subject.error("This is an error message.");
    subject.fatalError("This is a fatal error message.");

    subject.removeObserver(&consoleAndFileFatalErrorObserver);

    subject.warning("Another warning message.");
    subject.error("Another error message.");
    subject.fatalError("Another fatal error message.");

    return 0;
}
