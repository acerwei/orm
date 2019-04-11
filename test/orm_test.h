#include <cstdio>
#include <cstdlib>
#include <cstring>
namespace orm_test
{
struct Student {
    uint64_t Id;
    char Name[64];
    double Grade;
};
struct Course {
    char Code[10];
    char Title[64];
    int Size;
    double Rating;
};

#define ORM_PROTO_DEF "../test/ormproto.h"
#define ORM_OTM_JSON true
#define ORM_MTO_JSON true
#define ORM_OTM_XML true

#include "../orm/orm_base.h"
#include "../orm/orm_otm.h"
#include "../orm/orm_mto.h"

#undef ORM_OTM_JSON
#undef ORM_MTO_JSON
#undef ORM_OTM_XML
#undef ORM_PROTO_DEF

}