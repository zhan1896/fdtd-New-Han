
#include <iostream>
#include "config.h"
#include <map>
#include <string.h>
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

std::map<std::string, std::string> mapping;

 void initConfigurationMap(){
    setKeyValuePairInConfigurationMap("1", "Request System Info");
    setKeyValuePairInConfigurationMap("2", "Change System Info");
    setKeyValuePairInConfigurationMap("10", "Unknown Error");
}

 void resetConfigurationMap(){
    //
}
    
 int setKeyValuePairInConfigurationMap( const char *key, const char *value ){
    mapping.erase(key);
    mapping.insert(std::make_pair(key, value));
    
#if VERBOSE_CFMAP == 1
    std::cout << "config_map.cpp:setKeyValuePairInConfigurationMap: Setting " << key << " = " << value << "\n";
#endif
    
    return 0;
}

 const char *getKeyValuePairFromConfigurationMap( const char *key ){
    
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end())
    {
        // iter->second contains your string
        // iter->first contains the number you just looked up
        //std::cout << (iter->second);
        
#if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
#endif

        
    }
    return (iter->second).c_str();
}

 double getParamFromConfigFile_double( const char *key ){
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end()){   
        #if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
        #endif
        return atof((iter->second).c_str());
    }
    printf("Error bad key %s\n",key);
    exit(0);
}

 double getParamFromConfigFileWDefault_double( const char *key, double defaultValue ){
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end()){   
    #if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
    #endif
        return atof((iter->second).c_str());
    }
    return(defaultValue);
}

 double getParamFromConfigFile_double2( const char *prefix, const char *key ){
    
    char str[1000];
    strcpy(str,prefix);
    strcat(str,key);
    
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(str);
    if (iter != mapping.end())
    {
        
#if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
#endif
        return atof((iter->second).c_str());
    }
    printf("Error bad key %s\n",str);
    exit(0);
}

 int getParamFromConfigFile_int( const char *key ){
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end()){
        #if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
        #endif
        return atoi((iter->second).c_str());
    }
    printf("Error bad key %s\n",key);
    exit(0);
}

 int getParamFromConfigFileWDefault_int( const char *key, int defaultValue ){
    
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end()){   
        #if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
        #endif
        return atoi((iter->second).c_str());
    }
    return defaultValue;
}

 const char *getParamFromConfigFile_str( const char *key ){
    
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end())
    {
        
#if VERBOSE_CFMAP == 1
        std::cout << "config_map.cpp:getKeyValuePairFromConfigurationMap: Getting " << (iter->first) << " = " << (iter->second) << "\n";
#endif
        
        
    }
    return (iter->second).c_str();
}

 int getParamFromConfigFile_strcpy( const char *key, char *testkey ){
    
    std::map<std::string, std::string>::const_iterator iter =
    mapping.find(key);
    if (iter != mapping.end())
    {
        strcpy(testkey, (iter->second).c_str() );    
    }
    return 0;
}
