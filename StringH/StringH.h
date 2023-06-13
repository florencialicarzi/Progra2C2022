#ifndef STRINGH_H_INCLUDED
#define STRINGH_H_INCLUDED

size_t mi_strlen(const char* cad);
char* mi_strcpy(char* s1, const char* s2);
int mi_strcmp( const char* s1, const char* s2);
int mi_strncmp( const char* s1, const char* s2, size_t n);
int mi_strcmpi(const char* cad1, const char* cad2);
int mi_strnicmp( const char* s1, const char* s2, size_t n);
char* mi_strcat(char* cad1, const char *cad2);
char* mi_strchr(char*s, int c);
char* mi_strrchr(char*s, int c);
char* mi_strstr( const char* s1, const char* s2);



void normalizarCad(char* cad);

#endif // STRINGH_H_INCLUDED
