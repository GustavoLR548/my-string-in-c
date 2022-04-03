#include"../../my_string.h"

int main() {

    string* array = new_string_array(5);
    
    for(int i = 0; i < 5; i++) {
        array[i] = *(read_line());
    }

    for(int i = 0; i < 5; i++) {
        printf("%s\n", to_char_array(&array[i]));
    }
}