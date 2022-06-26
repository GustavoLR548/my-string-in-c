#include"../../my_string.h"

int main() {

    string s = read_line();

    printf("%s\n", to_char_array(&s));

    free_string(&s);
}