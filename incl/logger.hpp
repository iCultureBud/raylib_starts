#pragma once

#include <string>

namespace icuray
{
    class Logger
    {
    public:
        Logger(const std::string& logFilePath);
        ~Logger();

        void printHello() const;

        void log_info(const std::string& content) const;
        void log_debug(const std::string& content) const;
        void log_error(const std::string& content) const;

    private:
        void setupLogFile() const;

        time_t getFormattedNow() const;

        const std::string m_logFilePath;
        const std::string m_name { "Tester" };

    }; // class Logger

} // namespace icuray
