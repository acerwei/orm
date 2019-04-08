//*************************************************************Object to Mapping / Relation************************************************/
//TO IMPROVE
//  - Case (in-)sensitivity
//  - Delimiter / Special chars handling (eg. "" '', ``, /\, <>, ,)
//  - Trimming and space skipping
//  - Error / Exception handling
//  - Complex Fields
//      - List / Set as Field (Simple)
//      - Map as Field (Easy OTM, more work in MTO)
//      - Struct / Object as Field (More work)
//

#ifdef ORM_OTM_JSON
#define OrmClassBegin(Obj, Map)  \
    const char* jsonMarshal(Obj obj, char *buf, int len) { \
        char *bpos = buf; \
        memset(buf, 0, len); \
        sprintf(bpos, Map "{"); \
        bpos += strlen(bpos);
#define OrmField(field, str, informat, outformat) \
        sprintf(bpos, "'" str "':" outformat ",", obj.OTM_ACCESS(field)); \
        bpos += strlen(bpos); 
#define OrmCStringField(field, str, informat, outformat) \
        sprintf(bpos, "\'" str "\':\'" outformat "\',", obj.OTM_ACCESS(field)); \
        bpos += strlen(bpos); 
#define OrmClassEnd(Obj, Map) \
        *(bpos-1) = '}'; \
        return buf; \
    }

#include ORM_PROTO_DEF

#undef OrmClassBegin
#undef OrmField
#undef OrmCStringField
#undef OrmClassEnd

#endif //ORM_OTM_JSON


#ifdef ORM_OTM_XML
#define OrmClassBegin(Obj, Map)  \
    const char* xmlMarshal(Obj obj, char *buf, int len) { \
        char *bpos = buf; \
        memset(buf, 0, len); \
        sprintf(bpos, "<" Map ">"); \
        bpos += strlen(bpos);
#define OrmField(field, str, informat, outformat) \
        sprintf(bpos, "<" str ">" outformat "</" str ">", obj.OTM_ACCESS(field)); \
        bpos += strlen(bpos); 
#define OrmCStringField(field, str, informat, outformat) OrmField(field, str, informat, outformat)
#define OrmClassEnd(Obj, Map) \
        sprintf(bpos, "</" Map ">"); \
        return buf; \
    }

#include ORM_PROTO_DEF

#undef OrmClassBegin
#undef OrmField
#undef OrmCStringField
#undef OrmClassEnd
#endif //ORM_OTM_XML




