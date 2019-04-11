#include <ctype.h>

#ifndef ORM_SKIPPING
#define ORM_SKIPPING(buff) while(buff && isspace(*buff)) buff++;
#endif

#ifndef MTO_ACCESS
#define MTO_ACCESS(x) x
#endif
//************************************************************* Mapping / Relation to Object************************************************/
//REF: ORM_OTM.h TO IMPROVE
#ifdef ORM_MTO_JSON
#define OrmClassBegin(Obj, Map)  \
    OrmError jsonUnmarshal(Obj &obj, char* buf) { \
        char * bpos = strstr(buf, Map); \
        try { \
            if (!bpos) return {ORM_CLASS_MISMATCH, bpos}; \
            bpos = buf + strlen(Map) + 1; \
            ORM_SKIPPING(bpos) bpos++; \
            char * cpos = strstr(bpos, "\':"); \ 
            while (cpos) { \
                if (!strcmp(bpos, "NULL")) {}
#define OrmField(field, str, informat, outformat) \
                else if (!strncmp(bpos, str, strlen(str))) { \
                    bpos = cpos + 2; \
                    sscanf(bpos, informat, &obj.MTO_ACCESS(field)); \
                    bpos = strchr(bpos, ',');  \ 
                    if (bpos) {bpos++; ORM_SKIPPING(bpos) bpos++;} \
                    else break; \
                    cpos = strstr(bpos, "\':"); \    
                }
#define OrmCStringField(field, str, informat, outformat) \
                else if (!strncmp(bpos, str, strlen(str))) { \
                    bpos = cpos + 3; \
                    cpos = strchr(bpos, '\'');  \     
                    memmove(&obj.MTO_ACCESS(field), bpos, cpos - bpos); \
                    bpos = strchr(cpos, ','); \
                    if (bpos) {bpos++; ORM_SKIPPING(bpos) bpos++;} \
                    else break; \
                    cpos = strstr(bpos, "\':"); \
                }
#define OrmClassEnd(Obj, Map) \
                else { \
                    return {ORM_UNEXPECTEDFIELD, bpos}; \
                } \
            } \
        } \
        catch (...) { \
            return {ORM_UNMARSHAL_EXCEPTION, bpos}; \
        } \
        return {0, NULL}; \
    }

#include ORM_PROTO_DEF

#undef OrmClassBegin
#undef OrmField
#undef OrmClassEnd
#endif //ORM_MTO_JSON


#undef ORM_SKIPPING
#undef MTO_ACCESS
