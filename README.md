#  my-string in C

This repository contains an implementation of String in C. It is basically a struct with all basic functionalities of Strings in high-level programming languages.

Here is a list of the already implemented functions

### Constructors

* create empty string
* create string from char*
* create an array of strings

### Functions

```
char* to_char_array(string* s);
size_t length(string* s);
void append_char(string* dest,const char src);
void append_char_array(string* dest,const char* src);
bool contains_char_array(const string* str1, const char* str2);
string* strip(string* s);
string* substring(const string* s, int startIndex, int endIndex);
string* split(string* s, const char* pattern);
bool equals(const string* s,const char* arr);
```
