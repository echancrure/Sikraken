#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

#ifdef _MSC_VER
	#include <io.h>
	#define fopen_safe(pFile, filename, mode) fopen_s(pFile, filename, mode)
	#define access_safe(path, mode) _access(path, mode)
	#define strcpy_safe(dest, destsz, src) strcpy_s(dest, destsz, src)
	#define strcat_safe(dest, destsz, src) strcat_s(dest, destsz, src)
	#define sprintf_safe(buffer, size, format, ...) sprintf_s(buffer, size, format, __VA_ARGS__)
#else
	#include <unistd.h>
	#include <errno.h>
	#define fopen_safe(pFile, filename, mode) ((*pFile = fopen(filename, mode)) == NULL ? errno : 0)
	#define access_safe(path, mode) access(path, mode)
	#define strcpy_safe(dest, destsz, src) strncpy(dest, src, destsz)
	#define strcat_safe(dest, destsz, src) strncat(dest, src, destsz)
	/* allow calling sprintf_safe(buffer,size, "fmt") or with extra args */
	#if defined(__GNUC__) || defined(__clang__)
	#define sprintf_safe(buffer, size, format, ...) snprintf(buffer, size, format, ##__VA_ARGS__)
	#else
	/* conservative fallback for other compilers -- ensure callers pass at least format */
	#define sprintf_safe(buffer, size, format, ...) snprintf(buffer, size, format, __VA_ARGS__)
	#endif
#endif

char* to_prolog_var(const char *input);
void* safe_malloc(size_t size);
void simple_str_copy(char **SS, char *S1);
void simple_str_lit_copy(char **SS, const char *S1);

#endif // UTILS_H
