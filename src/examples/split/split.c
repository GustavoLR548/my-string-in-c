#include"../../my_string.h"
#include<string.h>
#include<stdlib.h>

int main() {

    string* s = new_string_from_char_array("1423<tag>244<tag>33<tag>774<tag>00055");

    string* splitted = split(s,"<tag>");
    printf("split length = %ld\n", splitted->split_length);
    for (int i = 0; i < splitted->split_length; i++) {
        printf("-> <%s>\n", to_char_array(&splitted[i]));
    }
}