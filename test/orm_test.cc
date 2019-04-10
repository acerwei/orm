#include "orm_test.h"

void testMarshal() {
    char buff[1024];
    orm_test::Student stu = {123, "acerwei", 4.99};
    printf("json: %s\n", orm_test::jsonMarshal(stu, buff, sizeof(buff)));
    printf("xml: %s\n", orm_test::xmlMarshal(stu, buff, sizeof(buff)));

    orm_test::Course c = {"CS789", "Jing-s Algorithms", 128, 5.0}; 
    printf("json: %s\n", orm_test::jsonMarshal(c, buff, sizeof(buff)));
    printf("xml: %s\n", orm_test::xmlMarshal(c, buff, sizeof(buff)));
}

void testUnmarshal() {
    char buff[1024];
    orm_test::Student b;
    char *buffb11 = "student{\'id\':000000123,\'name\':\'siqiwei\',\'grade\':4.990000}";
    auto res = orm_test::jsonUnmarshal(b, buffb11);
    printf("rest=%d, %s\n", res.err_code, orm_test::jsonMarshal(b, buff, sizeof(buff)));
    char *buffb12 = "student{\'name\': \'siqiwei\', \'id\': 000000123, \'grade\':4.990000}";
    res = orm_test::jsonUnmarshal(b, buffb12);
    printf("rest=%d, %s\n", res.err_code, orm_test::jsonMarshal(b, buff, sizeof(buff)));
    char *buffb13 = "student{\'name\':\'siqiwei\', \n  \'id\':000000123,4.990000}";
    res = orm_test::jsonUnmarshal(b, buffb13);
    printf("rest=%d, %s\n", res.err_code, orm_test::jsonMarshal(b, buff, sizeof(buff)));
    char *buffb2 = "stunt{000000124,siqiwei,4.991000}";
    res = orm_test::jsonUnmarshal(b, buffb2);
    printf("rest=%d at %s\n", res.err_code, res.err_pos);
    char *buffb3 = "student{\'name\':\'siqiwei\',\'id\':000000123,\'dd\': 123}";
    res = orm_test::jsonUnmarshal(b, buffb3);
    printf("rest=%d at %s\n", res.err_code, res.err_pos);
}

int main() {
    testMarshal();
    testUnmarshal();
    return 0;
}