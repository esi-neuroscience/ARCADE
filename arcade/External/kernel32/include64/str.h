#ifndef __str_h__
#define __str_h__
/** Strlib.h
 This is our implementation for a general string handling library adapted especially
 to lcc-win32.

The main design goals have been:
 o safety
 o convenience

Authors Friedrich Dominicus/Jacob Navia
date 2003
version 1.0
C-string means a proper ended character or wide_character array.

Motivation
So called strings are a major weakness in C, in fact strings
really do not exist. In C an array of characters ending in \0
is considered a string. Because the are just blocks of memory they
share all the weaknesses of arrays in C. No bounds-checks and nothing
which help not overwriting memory not owned by the actual process.

This is one of the biggest security holes in Programs, written in C.
We try to offer you a solution to be used in lcc-win32 extensions to C.

Our Goals
Our goals are quite simple, we do want to offer an
secure alternative to the mentioned problems.
Therefor we have to care about the following things:
-#	Check every memory access if it’s within the bounds of the array.
-#	Provide a convenient interface to that library.
-#	Check the input parameters for validity.
-#	Do disburden the programmer from memory handling, while using the
        Boehm Weisser GC

Used Tools
Software today means usually a combination of new written and adopted Software
and using of Tools. So for our String library do we have used:
- lcc-win32 with all it's extensions like overloading, References etc
- The Boehm-Weisser GC which we bundle with our software


Implementation
The major datastructure is the String datastructure.
It enables us to check the bounds, in O(1) time, lower bound is 0, upper
bound is count.

Usage notes
We do have followed the naming conventions from the "normal" C character
arrays, with just some slight adoptions.
- instead of str we have prefixed our functions with Str. The mapping is
consitently used. So if you look for somthing for catenating strings,
look not further than \ref Strcat.

- The following functions offer a different interface than what you
expect. \ref Strcat and \ref Strcpy functions do not return a pointer to
the first paramter. The return values never seems to get checked and it
checking them would probably not make sense. Because the first parameter
will have got mangeled anyway.

- The other deviation is \ref Strtok which took three instead of two parameters,
the last keeps track of the last accessed index of the String to be tokenized.
We would recommend not using strtok anyway because it's interface is not
very well thought out.

Now a important thing to consider. Before calling any function from
the library you have to call Strlibinitialize with the number of parameters
and the command line arguments.

So in console programs it looks like this:
int main(void)
  // Initialization
  Strlibinitialize();
  ...
  calls to Strlib.

If you do not do that a crash will eventually occur.


<h2>Error handling</h2>
As mentioned above we do have used GEF for the excption handling. GEF offers
Design-By-Contract (DBC) <a href="http://www.eiffel.com">see Eiffel</a> for C.
That mean we have separated normal control flow and error handling.

DBC means that we state explicitly what conditions we do expect before
calling our function, what holds during the call of our function and how the
result will look. All external functions will use this facilities.

For you as user of the library, we can subsume the following. The paramter
handed over to our functions must be valid Strings. There does exist a function
Strvalid for that purpose. All functions which do access Strings must be valid
otherwise the program will get *aborted*. The only exceptions are the functions
from the Strcat and Strcpy family, they were extended that the first parameter
does not have to be a proper string. But the source of the copy has to be
valid (otherwise we could not do anything). The rule for Strcat and Strcpy
is: If you provide an invalid first parameter you'll simply get a copy
of the source String.

You can catch such assertion violations with the GEF library. We'll provide some
examples on how to do that in our examples collection.
<a href="http://www.q-software-solutions.com/store">lcc-win32 samples</a>

*/
/** Examples for handling Asserion Violations see
	@example examples/strlib_exception_handling.c
*/
#include <stddef.h>
#include <stdbool.h>
#include <wchar.h>
//#include <windows.h>

/** Type tags, there may be a better way */
enum {SMALL=1,
	  WIDE=2};


enum{
	NO_MORE_MEMORY,
	INVALID_TYPE,
	INVALID_STRING,
	INVALID_FILE_OPERATION,
	INVALID_ARG};

/** @defgroup Structures Structure Definitions
   @{
*/

/** String is a relativly simple Datastructure, which enough
information and fields for easy interfacing with normal
C Functions and controlled access. All Strings are allocated
on the Heap and resizable. All Accesses throug the official
interface are checked. So Buffer Overruns should not happen
with the String library.

If you plan to extend this library. Please be careful that
<br>
a) The types is set correctly (either SMALL or WIDE)
<br>
b) Before accessing a field be sure that the index is in
bound, so adjust the count if necessray.
<br>
c) Do not touch Capacity. Use the official interface.
*/
typedef struct _StringA {
	/* Number of valid elements in "content"
	   Invariant: String[count] == 0 if the String is valid */
	size_t count;
	char *content; /* 8 bit chars */
	size_t capacity; /* Potential elemens in content. Invariant: capacity > count */
} StringA;

typedef struct _StringW {
	/* Number of actual elements in "content"
	   Invariant String[count] == 0 if the String is valid */
	size_t count;
	wchar_t *content; /* UNICODE string */
	size_t capacity; /* Potential elemens in content. Invariant: capacity > count */
} StringW;

#ifdef UNICODE
#define String StringW
#else
#define String StringA
#endif

typedef struct _stringpA {
	size_t count;
	char *content;
	StringA *parent;
} StringpA;

typedef struct _stringpW {
	size_t count;
	wchar_t *content;
	StringW *parent;
} StringpW;

#ifdef UNICODE
#define Stringp StringpW
#else
#define Stringp StringpA
#endif

char    * overloaded Strcontent(StringA &a);
wchar_t * overloaded Strcontent(StringW &a);

typedef struct {
	StringA pre;
	/**< is the Element before a split */
	StringA post;
	/**< is the Element after the split */
} StrsimplesplitA;

typedef struct {
	StringW pre;
	/**< is the Element before a split */
	StringW post;
	/**< is the Element after the split */
} StrsimplesplitW;

#ifdef UNICODE
#define Strsimplesplit StrsimplesplitA
#else
#define Strsimplesplit StrsimplesplitW
#endif

extern StringA invalid_stringA;
extern StringW invalid_stringW;
extern StringpA invalid_stringpA;
extern StringpW invalid_stringpW;

int isNullStringA(StringA &);
int isNullStringW(StringW &);

/** @} Structures */

void Strlibinitialize(void);
/** Check if a String is valid.
	@param string String to be checked */
// inline
int StrvalidA(const StringA& string);
int StrvalidW(const StringW& string);
int StrvalidpA(const StringpA& string);
int StrvalidpW(const StringpW& string);
#ifdef UNICODE
#define Strvalid StrvalidW
#define Strvalidp StrvalidpW
#else
#define Strvalid StrvalidA
#define Strvalidp StrvalidpA
#endif


StringA overloaded new_stringA(size_t requested_size);
StringW overloaded new_stringW(size_t requested_size);
StringA overloaded new_stringA(char * from);
StringW overloaded new_stringW(wchar_t * from);

#ifdef UNICODE
#define new_string new_stringW
#else
#define new_string new_stringA
#endif

StringpW overloaded new_stringpW(StringW &string,wchar_t *start);
StringpA overloaded new_stringpA(StringA &string,char *start);
StringpA overloaded new_stringpA(StringA &string,int start);
StringpW overloaded new_stringpW(StringW &string,int start);


#define STR_DEFAULT_CAPACITY	15

/**< Generate a new String from a char* array.
	@param from. char * from which to make the String
	@result a proper allocated String as copy from @a from
	*/
StringW overloaded new_string(wchar_t * from);
/**< Generate a new String from a wchar_t* array.
	@param from make a new string from this.
	@result a proper allocated String as copy from @a from
	*/
int overloaded Strresize(StringW & string,size_t requested_size);
int overloaded Strresize(StringA & string,size_t requested_size);

StringA overloaded ToString(int from,char *fmt);
StringA overloaded ToString(int from);
/**< Generate a new String from an Integer.
	@param from this integer
	@returns A proper String
*/

StringA overloaded ToString(double from,char *fmt);
StringA overloaded Totring(double from);
StringA overloaded ToString(long long from,char *fmt);
StringA overloaded ToString(long long from);
StringA overloaded ToString(long double from,char *fmt);
StringA overloaded ToString(long double from);
StringA overloaded ToString(unsigned from,char *fmt);
StringA overloaded ToString(unsigned from);
StringA overloaded ToString(float from);

StringA overloaded Strdup(StringA & from);
StringW overloaded Strdup(StringW & from);
StringA overloaded Strdup(StringpA &from);
StringW overloaded Strdup(StringpW &from);
StringA overloaded Strdup(char *);
StringW overloaded Strdup(wchar_t *);
StringA overloaded Strdup(StringA &str,int start);
StringW overloaded Strdup(StringW &str,int start);
StringA overloaded Strdup(StringA &str,int start,int end);
StringW overloaded Strdup(StringW &str,int start,int end);

StringA overloaded Strfromfile (char *from,int binarymode);
StringA overloaded Strfromfile (char *from); // binary mode defaults to zero
StringA overloaded Strfromfile(StringA from,int binarymode);

int overloaded Strsizeof(StringA s);
int overloaded Strsizeof(StringW s);

bool StrtofileA(StringA &s,char *filename,int binarymode);
bool StrtofileW(StringW &s,char *filename,int binarymode);
#ifdef UNICODE
#define Strtofile StrtofileW
#else
#define Strtofile StrtofileA
#endif

size_t overloaded Strlen(const StringA& string);
size_t overloaded Strlen(const StringW& string);

/* Accessor for the String struct member count.
*/
size_t get_size_stringA(const StringA &);
size_t get_size_stringW(const StringW &);
#ifdef UNICODE
#define get_size_string get_size_stringW
#else
#define get_size_string get_size_stringA
#endif

size_t overloaded Strcapacity(const StringA&);
size_t overloaded Strcapacity(const StringW&);
/**< Accesssor for the String struct member @a capacity
	@param string from which to get the length
	@return Potential entries to string before running
	out of space */


/** Overloaded operator for making accessing String look more familiar.
	@param string String to be accessed
	@param pos which element should be accessed?
	@return Elements at string[pos]
	@notes Array bounds are checked if one tries to access a String
	out of it's bound an Error will be raised. see implementation details
	in \a str_lib.c
*/
int operator[](const StringA& string, size_t pos);
int operator[](const StringW& string, size_t pos);
int operator[](const StringpA& string, size_t pos);
int operator[](const StringpW& string, size_t pos);
/** Is a synonym for [] that measn str[x] == item(str, x).
	@param string see operator []
	@param pos see operator []
	@return see operator []
*/
int get_element_stringA(const StringA & string, size_t pos);
int get_element_stringW(const StringW & string, size_t pos);
#ifdef UNICODE
#define get_element_string get_element_stringW
#else
#define get_element_string get_element_stringA
#endif


/** @} end of Group Accessors */

/** Setter for one element of string.
	@param string which will get changed.
	@param pos which position to accesss.
	@param new_val New value to be put at string[pos];
	@return old_val of the accessed position
*/
int operator[]= (StringA& string, size_t pos, int newval);
int operator[]= (StringW& string, size_t pos, int newval);
int operator[]=(StringpA& string, size_t index,int newval);
int operator[]=(StringpW& string, size_t index,int newval);

// inline
int set_element_stringA(StringA &StringA, size_t pos, int newval);
int set_element_stringW(StringW &StringW, size_t pos, int newval);
#ifdef UNICODE
#define set_element_string set_element_stringW
#else
#define set_element_string set_element_stringA
#endif



/** For interacting with Functin taking a char*
	@param string to be converted to a char*
	@return char* for use in functions wich take a char*
*/
char *Strsmall(StringA& string);
/** For interaction with Functins taking a wchar_t *
    @param string: String to be converted
	@result wchar_t type converted from string */
wchar_t *Strwide(StringW&);


/** @addtogroup Copiers Copy Functions
	@{
*/
void overloaded Strcpy(StringA &target, StringA & source);
void overloaded Strcpy(StringW &target, StringW & source);
void overloaded Strcpy(StringA & target, char* source);
void overloaded Strcpy(StringW &target, wchar_t * source);
void overloaded Strncpy(StringA &target, StringA & source, size_t count);
void overloaded Strncpy(StringA &target, char* source, size_t count);
void overloaded Strncpy(StringW &target, StringW & source, size_t count);
void overloaded Strncpy(StringW &target, wchar_t* source, size_t count);

/** @} Copiers */

/** @addtogroup Concatenation Concatenation Functions
	@{
*/
int overloaded Strncat(StringA & to, StringA & from, size_t elements_to_cat);
int overloaded Strncat(StringW & to, StringW & from, size_t elements_to_cat);

int overloaded Strncat(StringA & to, char *from, size_t elements_to_cat);
int overloaded Strncat(StringW & to, wchar_t *from, size_t elements_to_cat);
int overloaded Strncat(StringA &str,FILE *f,size_t n);

int overloaded Strcat(StringA &, StringA &);
int overloaded Strcat(StringW &, StringW &);

int overloaded Strcat(StringA &, char*);
int overloaded Strcat(StringW &, wchar_t*);
StringA overloaded Strcatv(char *s,...);
StringW overloaded Strcatv(wchar_t *s,...);

void overloaded Strchcat(StringA &, int );
void overloaded Strchcat(StringW &, int );

/** @} Concatenation */

/** @addtogroup Comparison Comparison functions
   @{

	The Functions from this family do have the following task.
	Compare one String with another.
	For the results of Strcmp it always holds:
	    - -1 s1 < s2
		- 0 if both are equal
		- 1 s1 > s2

	For the operatos the results are always:
	    - 1 if s1 operator s2 == 1
	    - 0 else
	e.g s1 < s2 == 1 => s1 is lexically smaller than s2

	@notes Not clear is the handling of locales at the moment
*/

/** Check examples from @example examples/strcmp_examples.c
*/


/** @section Strcmp Strcmp family */
/** Case insensitive comparison */
int overloaded Stricmp(StringA &s1, StringA & s2);
int overloaded Stricmp(StringW &s1, StringW & s2);

//Strcmp
int overloaded Strcmp(StringA & s1, StringA& s2);
int overloaded Strcmp(StringW & s1, StringW& s2);

int overloaded Strcmp(const char* s1, StringA & s2);

int overloaded Strcmp(StringA & s1, const char* s2);
int overloaded Strcmp(StringW & s1, const wchar_t *s2);
int overloaded Strcmp(const wchar_t * s1, StringW &s2);
int overloaded Strcmp(StringpA s1,StringpA s2);
int overloaded Strcmp(StringpW s1,StringpW s2);
int overloaded Strcmp(StringpA s1,char *s2);
int overloaded Strcmp(StringpW s1,wchar_t *s2);

/** @ref Strcmp family */

int overloaded Strncmp(StringW & s1, StringW & s2, size_t);
int overloaded Strncmp(StringA &s1, StringA &s2, size_t elements);

/** @todo Add documentation what lexical smaller means and
	how the result depends on localization. */

/** Test on equality
	@result 1 if s1 is equal too s2 */
int operator == (const StringA & string1, const StringA & string2);
int operator == (const StringW & string1, const StringW & string2);

int operator != (const StringA & string1, const StringA & string2);
int operator != (const StringW & string1, const StringW & string2);
/** is String s1 smaller than String s2?
	@result 1 if @a s1 < @a s2 (lexical) 0 else
*/
int operator < (const StringA & s1, const StringA & s2);
int operator < (const StringW & s1, const StringW & s2);
int lessString(const String  *string1,const String *string2);

/** Is String s1 smaller equal than String s2?
	@result 1 if @a s1 <= @a s2 (lexical), 0 else
*/
int operator <= (const StringA & s1, const StringA & s2);
int operator <= (const StringW & s1, const StringW & s2);

/** Is String s1 larger than String s2?
	@result 1 if @a s1 > @a s2 (lexical), 0 else
*/
int operator > (const StringA & s1, const StringA & s2);
int operator > (const StringW & s1, const StringW & s2);

/** Is String s1 larger equal than String s2?
	@result 1 if @ s1 >= @a s2 (lexical), 0 else
*/
int operator >= (const StringA &s1, const StringA & s2);
int operator >= (const StringW &s1, const StringW & s2);
int leqString(String  *string1,const String *string2);
int geqString(const String *s1,const String *s2);

int operator !(StringpA s);
int operator !(StringpW s);

int operator !=(StringpA s,void *pv);
int operator != (const Stringp & string1, int i);
int operator != (int i,const Stringp & string1);
int operator == (const Stringp & string1, int i);
int operator == (int i,const StringpW & string1);
int operator == (int i,const StringpA & string1);

StringpA operator+=(StringpA &s1,int n);
StringpW operator+=(StringpW &s1,int n);

StringpA operator+(StringA &s1, int n);
StringpW operator+(StringW &s1, int n);
// Allow the syntax String s = "abc";

StringA  operator=(StringA &a,char *src);
StringW  operator=(StringW &a,wchar_t *src);
char *   operator *(StringA &str);
wchar_t *operator *(StringW &str);
char * operator *(StringpA &str);
wchar_t * operator *(StringpW &str);

/** @invariant
	- s1 < s2 => s2 > s1;
   	- s1 <= s2 => not s1 > s2;
*/

bool Strequalrange (String & s1, String & s2,
					int nelements,
				    int s1_from = 0,
					int s2_from = 0);


/** @} End of group Comparison */
String  get_subrange_string(String &string,int from,int to);
// Strslice
StringA overloaded Strslice(StringA &, int, int);
StringW overloaded Strslice(StringW &, int, int);
// Strmap
StringA overloaded Strmap(StringA & from, int (*map_fun) (int));
StringW overloaded Strmap(StringW & from, int (*map_fun) (int));

StringA  overloaded Strfilter(StringA & from, bool (*pred_fun) (int));
StringW  overloaded Strfilter(StringW & from, bool (*pred_fun) (int));

StringA  overloaded Strfilter(StringA &,char *set);
StringA  overloaded Strfilter(StringA &,wchar_t *set);

StringA  overloaded Strfilter(StringA &,StringA &set);
StringW  overloaded Strfilter(StringW &,StringW &set);

StringA Strupr(StringA & string);
StringA Strlwr(StringA & string);

/*
Finds the first occurrence of word in text. Case sensitive
*/
StringpA overloaded Strstr(StringA &text, StringA &word);
StringpA overloaded Strstr(StringA &text, char *word);
StringpW overloaded Strstr(StringW &text, StringW &word);
StringpW overloaded Strstr(StringW &text, wchar_t *word);
StringpA overloaded Strstr(StringpA text,char *s);
StringpW overloaded Strstr(StringpW text,wchar_t *s);

// Same as Strstr but ignoring case differences
// String Stristr(String &text, String &word);


/**
The strcspn function computes the length of the maximum initial segment of the string
pointed to by @a s1 which consists entirely of characters not from the string
pointed to by @a s2.
@param s1 is searched in
@param s2 elements to be checked if they are contained in @a s1

Returns the length of the segment
*/
size_t overloaded Strcspn(StringA &s1, const StringA &s2);
size_t overloaded Strcspn(StringW &s1, const StringW &s2);

/** The strpbrk function locates the first occurrence in the String
@a s1 of any character from the String containing elements from @a s2.
	@param s1 search for one of the elements of @a s2
	@param s2 check if any of it's elemnts are part of @a s1
	@returns A new String starting from the first character which matches
	one out of @a s2. An invalid string otherwise
*/
String Strpbrk(String &s1,String &s2);
StringpA overloaded Strchr(StringA & string, int element);
StringpW overloaded Strchr(StringW & string, int element);
StringpA overloaded Strchr(StringA & string, int element,int start);
StringpW overloaded Strchr(StringW & string, int element,int start);

StringpA overloaded Strchr(StringpA &s,int element);
StringpW overloaded Strchr(StringpW &s,int element);
StringpA overloaded Strrchr(StringA & string, int element);
StringpW overloaded Strrchr(StringW & string, int element);
// Strspn
size_t overloaded Strspn(const StringA &s1,const StringA &s2);
size_t overloaded Strspn(const StringW &s1,const StringW &s2);

size_t overloaded Strspn(StringA &s1,const char *s2);
size_t overloaded Strspn(String &s1,const wchar_t *s2);

// Strtok
StringpA overloaded Strtok(StringA *string, const StringA &delimiters);
StringpW overloaded Strtok(StringW *string, const StringW &delimiters);

StringpA overloaded Strtok(StringA *string, const char *delimiters);
StringpW overloaded Strtok(StringW *string, const wchar_t *delimiters);

/** Simular to fgets. But the String is proper filled, that means
	if a '\\n' was read it has been replaced by '\\0', to make it
	a proper C-string.
	@param source: String to be filled with maximal @a n elements.
	@param n Number of elements to be read from @a from.
	@param from FILE * to read from the elements.
	@returns number of read elements */
int overloaded Strfgets (StringA & source, int n, FILE *from);
StringA overloaded Strfgets(FILE *from);
StrsimplesplitA overloaded Strsplit(StringA & string, int);
StrsimplesplitW overloaded Strsplit(StringW & string,int);

StringW Strtowide(StringA & string);
StringA Strtosmall(StringW & string);


wchar_t *operator()(StringW &);
char *operator()(StringA &);
char *operator()(StringpA &);
/*
Cast operators to make a String from a normal C string or a wchat_t char array
*/
StringA operator()(char *);
StringW operator()(wchar_t *);
// Strset
void overloaded Strset(StringA &, int, size_t);
void overloaded Strset(StringW &, int, size_t);
// insert_string
bool overloaded Strinsert(StringA &s,size_t pos,int newval);
bool overloaded Strinsert(StringW &s,size_t pos,int newval);
// erase_string
bool overloaded Strdelete(StringA &s,size_t pos);
bool overloaded Strdelete(StringW &s,size_t pos);

int overloaded Strtruncate(StringA &str,size_t n);
int overloaded Strtruncate(StringW &str,size_t n);

bool overloaded Strreverse(StringA &s);
bool overloaded Strreverse(StringW &s);

String Strerror(void);
int overloaded Strfind_first_of(StringA &s,char *set);
int overloaded Strfind_first_of(StringA &s,StringA &set);
int overloaded Strfind_first_of(StringW &s,wchar_t *set);
int overloaded Strfind_first_of(StringW &s,StringW &set);

int overloaded Strfind_last_of(StringA &s,StringA &set);
int overloaded Strfind_last_of(StringA &s,char *set);
int overloaded Strfind_last_of(StringW &s,StringW &set);
int overloaded Strfind_last_of(StringW &s,wchar_t *set);

// Strrepl
int overloaded Strrepl(StringA &inputS, StringA &StrToFind, StringA &StrToReplace);
int overloaded Strrepl(StringA &inputS, char *StrToFind, char *StrToReplace);
int overloaded Strrepl(StringW &inputS, StringW &StrToFind, StringW &StrToReplace);
int overloaded Strrepl(StringW &inputS, wchar_t *StrToFind, wchar_t *StrToReplace);
int overloaded Strrepl(StringA &inputS, int charToFind, int charToReplace);
int overloaded Strrepl(StringW &inputS, int charToFind, int charToReplace);


StringpA overloaded Strnext(StringpA);
StringpW overloaded Strnext(StringpW);

StringpA overloaded Strbegin(StringA &);
StringpW overloaded Strbegin(StringW &);

StringpA overloaded Strbegin(StringA &);
StringpW overloaded Strbegin(StringW &);
size_t   overloaded Strsizeof(StringA &a);
size_t   overloaded Strsizeof(StringW &a);
bool     overloaded Strinsert(StringA &s,size_t pos,int newval);
bool     overloaded Strinsert(StringW &s,size_t pos,int newval);

String overloaded Strfromp(StringpA str,int n);
String overloaded Strfromp(StringpA str1,StringpA str2);

StringA overloaded Strfrompipe(char *cmdline);
StringA overloaded Strfrompipe(String &cmdline);
String overloaded Strfromenv(char *);
String overloaded Strfromenv(String &);

StringA overloaded Strfindfiles(char *dir,char *specs,int flags);
StringW overloaded Strfindfiles(StringA &dir,StringA &specs,int flags);
#define STRFIND_RECURSIVE	1
#define STRFIND_SORT		2
//#pragma lib <containers.lib>
//#pragma lib <gc.lib>
#endif

