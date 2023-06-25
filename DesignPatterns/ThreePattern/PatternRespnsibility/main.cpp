#include <iostream>
#include <fstream>
#include <stdexcept>


enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};


class LogMessage {
public:
    LogMessage(Type type, const std::string& message)
        : m_type(type), m_message(message) {}

    Type type() const {
        return m_type;
    }

    const std::string& message() const {
        return m_message;
    }

private:
    Type m_type;
    std::string m_message;
};


class Handler {
public:
    virtual ~Handler() {}

    void setNext(Handler* next) {
        m_next = next;
    }

    void handle(const LogMessage& message) {
        if (canHandle(message)) {
            process(message);
        }
        else if (m_next) {
            m_next->handle(message);
        }
        else {
            throw std::runtime_error("Unhandled message: " + message.message());
        }
    }

protected:
    virtual bool canHandle(const LogMessage& message) const = 0;
    virtual void process(const LogMessage& message) = 0;

    Handler* m_next = nullptr;
};


class FatalErrorHandler : public Handler {
protected:
    bool canHandle(const LogMessage& message) const override {
        return message.type() == Type::FatalError;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Fatal error: " + message.message());
    }
};


class ErrorHandler : public Handler {
public:
    ErrorHandler(const std::string& filePath)
        : m_filePath(filePath) {}

protected:
    bool canHandle(const LogMessage& message) const override {
        return message.type() == Type::Error;
    }

    void process(const LogMessage& message) override {
        std::ofstream file(m_filePath, std::ios::app);
        if (file.is_open()) {
            file << "Error: " << message.message() << std::endl;
            file.close();
        }
        else {
            throw std::runtime_error("Failed to open log file.");
        }
    }

private:
    std::string m_filePath;
};


class WarningHandler : public Handler {
protected:
    bool canHandle(const LogMessage& message) const override {
        return message.type() == Type::Warning;
    }

    void process(const LogMessage& message) override {
        std::cout << "Warning: " << message.message() << std::endl;
    }
};


class UnknownHandler : public Handler {
protected:
    bool canHandle(const LogMessage& message) const override {
        return message.type() == Type::Unknown;
    }

    void process(const LogMessage& message) override {
        throw std::runtime_error("Unknown message: " + message.message());
    }
};

int main() {

    Handler* handlerChain = new FatalErrorHandler();
    handlerChain->setNext(new ErrorHandler("log.txt"));
    handlerChain->setNext(new WarningHandler());
    handlerChain->setNext(new UnknownHandler());

    LogMessage message1(Type::Error, "Something went wrong!");
    LogMessage message2(Type::Warning, "Be careful!");
    LogMessage message3(Type::FatalError, "Critical error occurred!");
    LogMessage message4(Type::Unknown, "Unknown message type.");

    try {
        handlerChain->handle(message1);
        handlerChain->handle(message2);
        handlerChain->handle(message3);
        handlerChain->handle(message4);
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }


    delete handlerChain;

    return 0;
}
