#define ORM_CLASS_MISMATCH 101
#define ORM_UNMARSHAL_EXCEPTION 102
#define ORM_UNEXPECTEDFIELD 103
struct OrmError {
    int err_code;
    char * err_pos;
};