#pragma once

#include <chrono>
#include <iostream>

using namespace std::chrono;

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__){message};

class LogDuration
{
private:
    /* data */
    steady_clock::time_point start;
    std::string message;

public:
    explicit LogDuration(const std::string &msg = "")
        : start(steady_clock::now()),
          message(msg + ": "){};

    ~LogDuration()
    {
        auto finish = steady_clock::now();
        auto duration = finish - start;
        std::cerr << message << duration_cast<milliseconds>(duration).count() << " ms" << std::endl;
    };
};