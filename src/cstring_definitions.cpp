#include "mbed.h"

extern "C"{
   wchar_t* wmemcpy (wchar_t* destination, const wchar_t* source, size_t num){return nullptr;}
   wchar_t* wmemset (wchar_t* ptr, wchar_t wc, size_t num){return nullptr;}
   int __2swprintf (wchar_t* ws, size_t len, const wchar_t* format, ...){return 0;}
   size_t wcslen( const wchar_t *str ){return 0;}
   long int wcstol (const wchar_t* str, wchar_t** endptr, int base){return 0;}
   unsigned long int wcstoul (const wchar_t* str, wchar_t** endptr, int base){return 0;}
   unsigned long long int wcstoull (const wchar_t* str, wchar_t** endptr, int base){return 0;}
   double __wcstod_int( const wchar_t* str, wchar_t** str_end ){return 0;}
   float __wcstof_int( const wchar_t* str, wchar_t** str_end ){return 0;}
   wchar_t* wmemchr (const wchar_t* ptr, wchar_t wc, size_t num){return 0;}
   int wmemcmp (const wchar_t* ptr1, const wchar_t* ptr2, size_t num){return 0;}
   wchar_t* wmemmove (wchar_t* destination, const wchar_t* source, size_t num){return nullptr;}
   long long int wcstoll (const wchar_t* str, wchar_t** endptr, int base){return 0;}
}