
#include <stdio.h>
#include <ctype.h>
#include "lcfg_static.h"
#include "config.h"
#include "string.h"

enum lcfg_status processKeyValue(const char *key, void *data, size_t len, void *user_data);

/*  */
 int parseConfigFile(const char *filename) {
    
    struct lcfg *c = lcfg_new(filename);
    
    if( lcfg_parse(c) != lcfg_status_ok ) {
        printf("lcfg error: %s\n", lcfg_error_get(c));
    } else {
        lcfg_accept(c, processKeyValue, 0);
    }
    lcfg_delete(c); 
    
    return 0;
}


 enum lcfg_status processKeyValue(const char *key, void *data, size_t len, void *user_data) {
    
#if VERBOSE_CF == 1
    int i;
    char c;
    printf("config.c:processKeyValue: Read %s = \"", key);
    for( i = 0; i < len; i++ ) {
        c = *((const char *)(data + i));
        printf("%c", isprint(c) ? c : '.');
    }
    puts("\"");
#endif
    
    if( strcmp("__execute",(const char*) data) == 0 ){
        //executeProcedure(key);
    }
    setKeyValuePairInConfigurationMap(key, (const char*) data);
    
    return lcfg_status_ok;
}
