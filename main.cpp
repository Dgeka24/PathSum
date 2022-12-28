#include "gentests.h"

int main() {
    // первые 2 теста это пример
    for (int i = 3; i <= 10; ++i) {
        gen_test(i, 2, 5);
    }
    for (int i = 11; i <= 30; ++i) {
        gen_test(i, 10, 100);
    }
    for (int i = 31; i <= 80; ++i) {
        gen_test(i, 100, 1000);
    }
    for (int i = 81; i <= 120; ++i) {
        gen_test(i, 900, 1000);
    }
    return 0;
}
