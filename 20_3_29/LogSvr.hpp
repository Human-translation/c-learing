#pragma once
#include <iostream>
#include <cstdio>
#include <sys/time.h>
#include <stdlib.h>
#include <string>
//[时间 info/warning/error.fatal.debug 文件 行号] 具体的错误信息

const char* Level[] = {
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL",
    "DEBUG"
};

enum LogLevel
{
    INFO = 0,
    WARNING,
    ERROR,
    FATAL,
    DEBUG
};

inline class LogTime
{
    public:
        static int64_t GetTimeStamp()
        {
            struct timeval tv;
            gettimeofday(&tv,NULL);
            return tv.tv_sec;
        }

        static void GetTimerStamp(std::string& timestamp)
        {
            time_t SysTime;
            time(&SysTime);

            struct tm* ST = localtime(&SysTime);
            char TimeNow[23] = {'/0'};
            snprintf(TimeNow,sizeof(TimeNow)-1,"%04d-%02d-%02d %02d-%02d-%02d",ST->tm_year + 1900,ST->tm_mon + 1,ST->tm_mday,
            ST->tm_hour,ST->tm_min,ST->tm_sec);
            timestamp.assign(TimeNow,strlen(TimeNow));
        }
}; 



void Log(LogLevel lev,const char* file,int line,std::string& logmsg)
{
    std::string level_info = Level[lev];
    std::string timer_stamp;

    LogTime::GetTimerStamp(timer_stamp);

    std::cout << "[" << timer_stamp << " " << level_info << " " << file << ";" << line << "]" << logmsg << std::endl;
}

