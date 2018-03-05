//
//  config.h
//
//  Created by Han Zhang on 3/2/18.
//  
//


#define VERBOSE_CF    0
#define VERBOSE_CFMAP 0

int parseConfigFile(const char *filename);

int executeProcedure(char *key);

#ifdef __cplusplus
extern "C"
#endif
void initConfigurationMap();

#ifdef __cplusplus
extern "C"
#endif
void testMap();

#ifdef __cplusplus
extern "C"
#endif
void resetConfigurationMap();

#ifdef __cplusplus
extern "C"
#endif
int setKeyValuePairInConfigurationMap( const char *key, const char *value );

#ifdef __cplusplus
extern "C"
#endif
const char *getKeyValuePairFromConfigurationMap( const char *key );

#ifdef __cplusplus
extern "C"
#endif
double getParamFromConfigFile_double( const char *key );

#ifdef __cplusplus
extern "C"
#endif
double getParamFromConfigFileWDefault_double( const char *key, double defaultValue );

#ifdef __cplusplus
extern "C"
#endif
double getParamFromConfigFile_double2( const char *prefix, const char *key );

#ifdef __cplusplus
extern "C"
#endif
int getParamFromConfigFile_int( const char *key );

#ifdef __cplusplus
extern "C"
#endif
int getParamFromConfigFileWDefault_int( const char *key, int defaultValue );

#ifdef __cplusplus
extern "C"
#endif
const char * getParamFromConfigFile_str( const char *key );

#ifdef __cplusplus
extern "C"
#endif
int getParamFromConfigFile_strcpy( const char *key, char *testkey );


