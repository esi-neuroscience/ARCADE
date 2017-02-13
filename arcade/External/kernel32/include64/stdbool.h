/*
WG14/N869 January 18, 1999 Page 257
7.16 Boolean type and values <stdbool.h>
1 The header <stdbool.h> defines four macros.
2 The macro
bool
expands to _Bool.
3 The remaining three macros are suitable for use in #if preprocessing 
directives. They are
true
which expands to the integer constant 1,
false
which expands to the integer constant 0, and
_ _bool_true_false_are_defined
which expands to the decimal constant 1.
4 Notwithstanding the provisions of 7.1.3, a program is permitted to undefine and perhaps
then redefine the macros bool, true, and false
*/
#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

