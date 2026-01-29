#ifndef __CLOG_H__
#define __CLOG_H__
 
#include "Logger.hpp"
 
/*
全局接口的设置
1.提供获取指定日志器的全局接口（避免用户自己创建单例对象）
2.使用宏函数对日志器的接口进行代理（代理模式）
3.提供宏函数，直接通过默认日志器进行标准输出的打印（不需要获取日志器）
*/
 
namespace clog
{
    // 提供获取日志器的全局接口
    Logger::ptr GetLogger(const std::string &name)
    {
        return clog::LoggerManager::GetInstance().getLogger(name);
    }
 
    Logger::ptr GetRootLogger()
    {
        return clog::LoggerManager::GetInstance().getRootLooger();
    }
 
    // 使用宏函数对日志器的接口进行代理
    #define debug(fmt, ...) debug(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define info(fmt, ...) info(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define warn(fmt, ...) warn(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define error(fmt, ...) error(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define fatal(fmt, ...) fatal(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
 
    // 使用宏函数，直接通过默认日志器进行标准输出的打印
    #define DEBUG(fmt, ...) clog::GetRootLogger()->debug(fmt, ##__VA_ARGS__)
    #define INFO(fmt, ...) clog::GetRootLogger()->info(fmt, ##__VA_ARGS__)
    #define WARN(fmt, ...) clog::GetRootLogger()->warn(fmt, ##__VA_ARGS__)
    #define ERROR(fmt, ...) clog::GetRootLogger()->error(fmt, ##__VA_ARGS__)
    #define FATAL(fmt, ...) clog::GetRootLogger()->fatal(fmt, ##__VA_ARGS__)
 
    
}
 
#endif