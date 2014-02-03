# 1 "prueba.c"
# 1 "<línea-de-orden>"
# 1 "prueba.c"
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 1 3
# 19 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/_mingw.h" 1 3
# 32 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/_mingw.h" 3
       
# 33 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/_mingw.h" 3
# 20 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 2 3






# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 1 3 4
# 213 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 3 4
typedef unsigned int size_t;
# 325 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 3 4
typedef short unsigned int wchar_t;
# 354 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 3 4
typedef short unsigned int wint_t;
# 27 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 2 3

# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stdarg.h" 1 3 4
# 40 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 29 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 2 3
# 129 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
typedef struct _iobuf
{
 char* _ptr;
 int _cnt;
 char* _base;
 int _flag;
 int _file;
 int _charbuf;
 int _bufsiz;
 char* _tmpfname;
} FILE;
# 154 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
extern __attribute__ ((__dllimport__)) FILE _iob[];
# 169 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fopen (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) freopen (const char*, const char*, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fflush (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fclose (FILE*);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) remove (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rename (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpfile (void);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpnam (char*);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _tempnam (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _rmtmp(void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _unlink (const char*);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tempnam (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rmtmp(void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) unlink (const char*);



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setvbuf (FILE*, char*, int, size_t);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setbuf (FILE*, char*);
# 204 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_fprintf(FILE*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_printf(const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_sprintf(char*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_snprintf(char*, size_t, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vfprintf(FILE*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vprintf(const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsprintf(char*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsnprintf(char*, size_t, const char*, __gnuc_va_list);
# 293 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fprintf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) printf (const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) sprintf (char*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfprintf (FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vprintf (const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsprintf (char*, const char*, __gnuc_va_list);
# 308 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_fprintf(FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_printf(const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_sprintf(char*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vfprintf(FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vprintf(const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vsprintf(char*, const char*, __gnuc_va_list);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snprintf (char*, size_t, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnprintf (char*, size_t, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscprintf (const char*, __gnuc_va_list);
# 331 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snprintf (char *, size_t, const char *, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnprintf (char *, size_t, const char *, __gnuc_va_list);

int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vscanf (const char * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfscanf (FILE * __restrict__, const char * __restrict__,
       __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsscanf (const char * __restrict__,
       const char * __restrict__, __gnuc_va_list);







 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fscanf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) scanf (const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) sscanf (const char*, const char*, ...);




 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetc (FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgets (char*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputc (int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputs (const char*, FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) gets (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) puts (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetc (int, FILE*);







 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _filbuf (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _flsbuf (int, FILE*);



extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getc (FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putc (int __c, FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    : _flsbuf (__c, __F);
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getchar (void)
{
  return (--(&_iob[0])->_cnt >= 0)
    ? (int) (unsigned char) *(&_iob[0])->_ptr++
    : _filbuf ((&_iob[0]));
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putchar(int __c)
{
  return (--(&_iob[1])->_cnt >= 0)
    ? (int) (unsigned char) (*(&_iob[1])->_ptr++ = (char)__c)
    : _flsbuf (__c, (&_iob[1]));}
# 412 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fread (void*, size_t, size_t, FILE*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwrite (const void*, size_t, size_t, FILE*);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fseek (FILE*, long, int);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ftell (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rewind (FILE*);
# 455 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
typedef long long fpos_t;




 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetpos (FILE*, fpos_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fsetpos (FILE*, const fpos_t*);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) feof (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ferror (FILE*);
# 480 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) clearerr (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) perror (const char*);






 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _popen (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _pclose (FILE*);


 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) popen (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) pclose (FILE*);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _flushall (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fgetchar (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fputchar (int);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fdopen (int, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fileno (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fcloseall (void);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fsopen (const char*, const char*, int);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getmaxstdio (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _setmaxstdio (int);
# 522 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetchar (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputchar (int);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fdopen (int, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fileno (FILE*);
# 534 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/sys/types.h" 1 3
# 21 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/sys/types.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 1 3 4
# 150 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 22 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/sys/types.h" 2 3





typedef long __time32_t;




typedef long long __time64_t;
# 45 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/sys/types.h" 3
typedef __time32_t time_t;






typedef long _off_t;


typedef _off_t off_t;







typedef unsigned int _dev_t;





typedef _dev_t dev_t;






typedef short _ino_t;


typedef _ino_t ino_t;






typedef int _pid_t;


typedef _pid_t pid_t;






typedef unsigned short _mode_t;


typedef _mode_t mode_t;






typedef int _sigset_t;


typedef _sigset_t sigset_t;





typedef int _ssize_t;


typedef _ssize_t ssize_t;





typedef long long fpos64_t;




typedef long long off64_t;



typedef unsigned int useconds_t;
# 535 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 2 3
extern __inline__ FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fopen64 (const char* filename, const char* mode)
{
  return fopen (filename, mode);
}

int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fseeko64 (FILE*, off64_t, int);






extern __inline__ off64_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ftello64 (FILE * stream)
{
  fpos_t pos;
  if (fgetpos(stream, &pos))
    return -1LL;
  else
   return ((off64_t) pos);
}
# 563 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwprintf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wprintf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snwprintf (wchar_t*, size_t, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwprintf (FILE*, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnwprintf (wchar_t*, size_t, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwscanf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wscanf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swscanf (const wchar_t*, const wchar_t*, ...);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputwc (wchar_t, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetwc (wchar_t, FILE*);



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swprintf (wchar_t*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vswprintf (wchar_t*, const wchar_t*, __gnuc_va_list);



 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetws (wchar_t*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputws (const wchar_t*, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwchar (void);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getws (wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwc (wint_t, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putws (const wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwchar (wint_t);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfdopen(int, const wchar_t *);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfopen (const wchar_t*, const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfreopen (const wchar_t*, const wchar_t*, FILE*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfsopen (const wchar_t*, const wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtmpnam (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtempnam (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wrename (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wremove (const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wperror (const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wpopen (const wchar_t*, const wchar_t*);



int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snwprintf (wchar_t* s, size_t n, const wchar_t* format, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, __gnuc_va_list arg);





int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwscanf (const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwscanf (FILE * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vswscanf (const wchar_t * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
# 625 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wpopen (const wchar_t*, const wchar_t*);






 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fgetwchar (void);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fputwchar (wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getw (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putw (int, FILE*);


 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetwchar (void);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputwchar (wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getw (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putw (int, FILE*);
# 2 "prueba.c" 2
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 1 3
# 21 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 1 3 4
# 22 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 2 3
# 71 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
extern int _argc;
extern char** _argv;




extern int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___argc(void);
extern char*** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___argv(void);
extern wchar_t*** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___wargv(void);
# 112 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
   extern __attribute__ ((__dllimport__)) int __mb_cur_max;
# 137 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _errno(void);


 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __doserrno(void);
# 149 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
  extern char *** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__environ(void);
  extern wchar_t *** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__wenviron(void);
# 172 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
  extern __attribute__ ((__dllimport__)) int _sys_nerr;
# 196 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
extern __attribute__ ((__dllimport__)) char* _sys_errlist[];
# 209 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__osver(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winver(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winmajor(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winminor(void);







extern __attribute__ ((__dllimport__)) unsigned int _osver;
extern __attribute__ ((__dllimport__)) unsigned int _winver;
extern __attribute__ ((__dllimport__)) unsigned int _winmajor;
extern __attribute__ ((__dllimport__)) unsigned int _winminor;
# 260 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
 char** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__pgmptr(void);

 wchar_t** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__wpgmptr(void);
# 293 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
extern __attribute__ ((__dllimport__)) int _fmode;
# 303 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atof (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoi (const char*);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atol (const char*);

 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtof (const wchar_t *);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtoi (const wchar_t *);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtol (const wchar_t *);


double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __strtod (const char*, char**);
extern double __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
strtod (const char* __restrict__ __nptr, char** __restrict__ __endptr);
float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtof (const char * __restrict__, char ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtold (const char * __restrict__, char ** __restrict__);




 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtol (const char*, char**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoul (const char*, char**, int);



 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstol (const wchar_t*, wchar_t**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstoul (const wchar_t*, wchar_t**, int);
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstod (const wchar_t*, wchar_t**);

float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstof( const wchar_t * __restrict__, wchar_t ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);


 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wgetenv(const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wputenv(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsearchenv(const wchar_t*, const wchar_t*, wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsystem(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wmakepath(wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsplitpath (const wchar_t*, wchar_t*, wchar_t*, wchar_t*, wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfullpath (wchar_t*, const wchar_t*, size_t);




 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstombs (char*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wctomb (char*, wchar_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mblen (const char*, size_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbstowcs (wchar_t*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbtowc (wchar_t*, const char*, size_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rand (void);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) srand (unsigned int);

 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) calloc (size_t, size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) malloc (size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) realloc (void*, size_t);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) free (void*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abort (void) __attribute__ ((__noreturn__));
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) exit (int) __attribute__ ((__noreturn__));


int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atexit (void (*)(void));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) system (const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getenv (const char*);


 void* __attribute__((__cdecl__)) bsearch (const void*, const void*, size_t, size_t,
          int (*)(const void*, const void*));
 void __attribute__((__cdecl__)) qsort(void*, size_t, size_t,
      int (*)(const void*, const void*));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abs (int) __attribute__ ((__const__));
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) labs (long) __attribute__ ((__const__));
# 385 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 div_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) div (int, int) __attribute__ ((__const__));
 ldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ldiv (long, long) __attribute__ ((__const__));







 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _beep (unsigned int, unsigned int) __attribute__ ((__deprecated__));

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _seterrormode (int) __attribute__ ((__deprecated__));
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _sleep (unsigned long) __attribute__ ((__deprecated__));

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _exit (int) __attribute__ ((__noreturn__));



typedef int (* _onexit_t)(void);
_onexit_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _onexit( _onexit_t );

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putenv (const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _searchenv (const char*, const char*, char*);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _gcvt (double, int, char*);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _makepath (char*, const char*, const char*, const char*, const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _splitpath (const char*, char*, char*, char*, char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fullpath (char*, const char*, size_t);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _itoa (int, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ltoa (long, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ultoa(unsigned long, char*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _itow (int, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ltow (long, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ultow (unsigned long, wchar_t*, int);


 long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _atoi64(const char *);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _i64toa(long long, char *, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ui64toa(unsigned long long, char *, int);
 long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtoi64(const wchar_t *);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _i64tow(long long, wchar_t *, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ui64tow(unsigned long long, wchar_t *, int);

 unsigned int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_rotl)(unsigned int, int) __attribute__ ((__const__));
 unsigned int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_rotr)(unsigned int, int) __attribute__ ((__const__));
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_lrotl)(unsigned long, int) __attribute__ ((__const__));
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_lrotr)(unsigned long, int) __attribute__ ((__const__));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _set_error_mode (int);
# 477 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putenv (const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) searchenv (const char*, const char*, char*);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) itoa (int, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ltoa (long, char*, int);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) gcvt (double, int, char*);
# 497 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/stdlib.h" 3
void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _Exit(int) __attribute__ ((__noreturn__));





typedef struct { long long quot, rem; } lldiv_t;

lldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lldiv (long long, long long) __attribute__ ((__const__));

long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) llabs(long long);





long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoll (const char* __restrict__, char** __restrict, int);
unsigned long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoull (const char* __restrict__, char** __restrict__, int);


long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoll (const char *);


long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wtoll (const wchar_t *);
char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lltoa (long long, char *, int);
char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ulltoa (unsigned long long , char *, int);
wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lltow (long long, wchar_t *, int);
wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ulltow (unsigned long long, wchar_t *, int);
# 3 "prueba.c" 2
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 1 3
# 24 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 1 3 4
# 25 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 2 3
# 36 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memchr (const void*, int, size_t) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcmp (const void*, const void*, size_t) __attribute__ ((__pure__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcpy (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memmove (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memset (void*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcat (char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strchr (const char*, int) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcmp (const char*, const char*) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcpy (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strerror (int);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strlen (const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncat (char*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncmp (const char*, const char*, size_t) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncpy (char*, const char*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strpbrk (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strrchr (const char*, int) __attribute__ ((__pure__));
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strstr (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtok (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strxfrm (char*, const char*, size_t);





 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strerror (const char *);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strdup (const char*) __attribute__ ((__malloc__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _stricmp (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strlwr (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnicmp (const char*, const char*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strrev (char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strset (char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strupr (char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _swab (const char*, char*, size_t);


 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strncoll(const char*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnicoll(const char*, const char*, size_t);
# 90 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strdup (const char*) __attribute__ ((__malloc__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) stricmp (const char*, const char*);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcasecmp (const char*, const char *);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strlwr (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strnicmp (const char*, const char*, size_t);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncasecmp (const char *, const char *, size_t);





 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strrev (char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strset (char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strupr (char*);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swab (const char*, char*, size_t);
# 126 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscat (wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcschr (const wchar_t*, wchar_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscpy (wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscspn (const wchar_t*, const wchar_t*);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcslen (const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncat (wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncmp(const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncpy(wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcspbrk(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsrchr(const wchar_t*, wchar_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsspn(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsstr(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstok(wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsxfrm(wchar_t*, const wchar_t*, size_t);
# 152 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsdup (const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsupr (wchar_t*);


 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsncoll(const wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnicoll(const wchar_t*, const wchar_t*, size_t);
# 173 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/string.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscmpi (const wchar_t * __ws1, const wchar_t * __ws2);





 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsdup (const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsupr (wchar_t*);
# 4 "prueba.c" 2
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 1 3
# 20 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
# 1 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/include/stddef.h" 1 3 4
# 21 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 2 3
# 48 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isalnum(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isalpha(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iscntrl(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isdigit(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isgraph(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) islower(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isprint(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ispunct(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isspace(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isupper(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isxdigit(int);



int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isblank (int);



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _isctype (int, int);



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tolower(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) toupper(int);
# 83 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _tolower(int);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _toupper(int);
# 112 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
  extern __attribute__ ((__dllimport__)) unsigned short _ctype[];


  extern __attribute__ ((__dllimport__)) unsigned short* _pctype;
# 188 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
typedef wchar_t wctype_t;



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswalnum(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswalpha(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswascii(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswcntrl(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswctype(wint_t, wctype_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) is_wctype(wint_t, wctype_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswdigit(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswgraph(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswlower(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswprint(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswpunct(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswspace(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswupper(wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswxdigit(wint_t);



int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iswblank (wint_t);





 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) towlower (wint_t);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) towupper (wint_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isleadbyte (int);
# 246 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __isascii (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __toascii (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __iscsymf (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __iscsym (int);
# 260 "c:\\mingw\\bin\\../lib/gcc/mingw32/4.7.0/../../../../include/ctype.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) isascii (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) toascii (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iscsymf (int);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) iscsym (int);
# 5 "prueba.c" 2

# 1 "error.c" 1

char *errIO[ 5 ] =
{ "No se pudo abrir el archivo",
  "Las dimensiones del mapa son muy chicas",
  "Las dimensiones del mapa son muy grandes",
  "Las dimensiones del mapa no concuerdan",
  "El archivo a guardar no se pudo crear" };

void error( char* txt ){
   puts( txt );
   exit( 1 );
}
# 7 "prueba.c" 2
# 1 "mapa/mapa.c" 1
typedef unsigned char uchar;
typedef uchar dir;
# 17 "mapa/mapa.c"
dir d_arr[ 6 ] = { (1 << 5) , (1 << 3) , (1 << 1) , (1 << 0) , (1 << 2) , (1 << 4) };


typedef struct mapa{
   uchar *coord;
   int meta_i, meta_f;
   int long_x, long_y, long_z;
}mapa;

typedef struct punto{
   int x, y, z;
   dir ds;
   struct punto *next;
}punto;



mapa* crearMapa( int , int , int );


mapa* borrarMapa( mapa** );

void obtenMetas( mapa *m );

punto* crearPunto( int , int , int );


int esPuntoValido( punto *p , mapa *m );


int indP( punto *p , mapa *m );


uchar* coordP( punto *p , mapa *m );


dir dirContr( dir d );


punto* irA( dir d , punto *p );

int esPasillo( punto *p , mapa *m );

int esMuro( punto *p , mapa *m );


int esElevA( punto *p , mapa *m );


int esElevB( punto *p , mapa *m );


int esElev( punto *p , mapa *m );


punto* convierteAPasillo( punto *p , mapa *m );




mapa* crearMapa( int x , int y , int z ){
   int i, j, k;
   mapa *m = (mapa*)malloc((1)*sizeof(mapa));
   if( m == ((void *)0) ) return ((void *)0);
      m->long_x = x;
      m->long_y = y;
      m->long_z = z;
   m->coord = (uchar*)(x*y*z*sizeof( uchar* )*)malloc((1)*sizeof(x*y*z*sizeof( uchar* )));
   if( m->coord == ((void *)0) ) return borrarMapa( &m );

   for(k = 0; k < z; k++)
      for(j = 0; j < y; j++)
         for(i = 0; i < x; i++)
            m->coord[ k*y*x + j*x + i ] = ( 0 );

   return m;
}

mapa* borrarMapa( mapa **m ){
   if( *m == ((void *)0) ) return ((void *)0);
   free( *m ); *m = ((void *)0);
   return *m;
}

void obtenMetas( mapa *m ){
   int i = 0, j = (m->long_x)*(m->long_y)*(m->long_z);

   for(; i < j; i++)
      if( m->coord[ i ] == ((1 << 3)+1) ){ m->meta_i = i++; break; }
   for(; i < j; i++)
      if( m->coord[ i ] == ((1 << 3)+1) ){ m->meta_f = i; break; }
}

punto* crearPunto( int x , int y , int z ){
   punto *p = (punto*)(sizeof( punto )*)malloc((1)*sizeof(sizeof( punto )));
   if( p == ((void *)0) ) return ((void *)0);
      p->x = x; p->y = y; p->z = z;
      p->next = ((void *)0);
   return p;
}

int esPuntoValido( punto *p , mapa *m ){
   return 0 <= p->x && p->x < m->long_x &&
          0 <= p->y && p->y < m->long_y &&
          0 <= p->z && p->z < m->long_z;
}

int indP( punto *p , mapa *m ){
   return (p->z)*(m->long_y)*(m->long_x) +
          (p->y)*(m->long_x) +
          (p->x);
}

uchar* coordP( punto *p , mapa *m ){
   return m->coord + indP( p , m );
}

dir dirContr( dir d ){
   switch( d ){
      case (1 << 5): return (1 << 4);
      case (1 << 4): return (1 << 5);
      case (1 << 0): return (1 << 1);
      case (1 << 3): return (1 << 2);
      case (1 << 2): return (1 << 3);
      case (1 << 1): return (1 << 0);
   }
   return ( 0 );
}

punto* irA( dir d , punto *p ){
   switch( d ){
      case (1 << 5): p->z--; return p;
      case (1 << 4): p->z++; return p;
      case (1 << 0): p->x--; return p;
      case (1 << 3): p->y--; return p;
      case (1 << 2): p->y++; return p;
      case (1 << 1): p->x++; return p;
   }
   return p;
}

int esPasillo( punto *p , mapa *m ){
   return *( coordP( p , m ) ) & (1 << 3);
}

int esMuro( punto *p , mapa *m ){ return !esPasillo( p , m ); }

int esElevA( punto *p , mapa *m ){
   if( esMuro( p , m ) ) return 0;
   irA( (1 << 5) , p );
   if( esPuntoValido( p , m ) && esPasillo( p , m ) ){
      irA( (1 << 4) , p );
      return 1;
   }
   irA( (1 << 4) , p );
   return 0;
}

int esElevB( punto *p , mapa *m ){
   if( esMuro( p , m ) ) return 0;
   irA( (1 << 4) , p );
   if( esPuntoValido( p , m ) && esPasillo( p , m ) ){
      irA( (1 << 5) , p );
      return 1;
   }
   irA( (1 << 5) , p );
   return 0;
}

int esElev( punto *p , mapa *m ){
   return esElevA( p , m ) && esElevB( p , m );
}

punto* convierteAPasillo( punto *p , mapa *m ){
   *( coordP( p , m ) ) = (1 << 3);
   return p;
}
# 8 "prueba.c" 2
# 1 "io/pantalla.c" 1







char pantalla[ 40 ][ 80 + 1 ];

void iniciarPantalla(){
   int i , j;
   for( i = 0 ; i < 40 ; i++ )
      for( j = 0 ; j < 80 + 1 ; j++ )
         if( j == 80 )
            pantalla[ i ][ j ] = '\0';
         else
            pantalla[ i ][ j ] = '.';
}


void pintarEnPantalla( char** obj ,
                       int x , int y ,
                       int w , int h ){
   int i , j;
   for( i = 0 ; i < w ; i++ )
      for( j = 0 ; j < h ; j++ )
         pantalla[ y+j ][ x+i ] = obj[ j ][ i ];
}

void pintarMuro( int x , int y , int n ){
   char *muro[ 5 ] = { "+---+" ,
                       "|+ +|" ,
                       "| + |" ,
                       "|+ +|" ,
                       "+---+" };
   pintarEnPantalla( muro , 5*x , 5*y , 5 , 5 );
}

void pintarPasillo( int x , int y ){
   char *paso[ 5 ] = { "     " ,
                       "     " ,
                       "     " ,
                       "     " ,
                       "     " };
   pintarEnPantalla( paso , 5*x , 5*y , 5 , 5 );
}

void pintarElevador( int x , int y ){
   char *elev[ 5 ] = { "     " ,
                       " ||| " ,
                       " ||| " ,
                       " ||| " ,
                       "     " };
   pintarEnPantalla( elev , 5*x , 5*y , 5 , 5 );
}

void pintarPunto( int x , int y ){
   char *punt[ 5 ] = { "     " ,
                       " OOO " ,
                       " OOO " ,
                       " OOO " ,
                       "     " };
   pintarEnPantalla( punt , 5*x , 5*y , 5 , 5 );
}

void pintarMapa( punto *p , mapa *m ){
   punto *aux = crearPunto( p->x , p->y , p->z );

   iniciarPantalla();
   int i, j;
   for(j = 0; j < 8; j++){
      for(i = 0; i < 16; i++){
         aux->x = p->x + i - 7;
         aux->y = p->y + j - 3;
         if( esPuntoValido( aux , m ) ){
            if( aux->x == p->x && aux->y == p->y )
               pintarPunto( i , j );
            else if( esElevA( aux , m ) || esElevB( aux , m ) )
               pintarElevador( i , j );
            else if( esPasillo( aux , m ) )
               pintarPasillo( i , j );
            else if( esMuro( aux , m ) )
               pintarMuro( i , j , *( coordP( p , m ) ) );
         }
      }
   }
   free( aux );
}

void imprimirPantalla(){
   int i;
   system( "CLS" );
   for(i = 0; i < 40; i++)
      printf("%s",pantalla[ i ]);
}
# 9 "prueba.c" 2
# 1 "io/consola.c" 1





char* leerDeConsola();



punto* mover( char c , punto *p , mapa *m );

char* leerDeConsola(){
   static char str[ 1024 ];

   fgets( str , sizeof( str ) , (&_iob[0]) );
   if(str[strlen(str) - 1] == '\n'){
      str[strlen(str) - 1] = '\0';
   }else{
      char dummy[2];
      do{ fgets( dummy , sizeof(dummy) , (&_iob[0]) );
      }while( dummy[strlen(dummy) - 1] != '\n' );
   }

   int i = 0, j = 0;
   while( *(str + j) != '\0'){
      if( *(str + j) != ' ' ){
         *(str + i) = *(str + j); i++;
      }
      j++;
   }
   *(str + i) = '\0';
   return str;
}

punto* mover( char c , punto *p , mapa *m ){
   dir d = ( 0 );
   switch( c ){
      case 'w': d = (1 << 3); break;
      case 's': d = (1 << 2); break;
      case 'a': d = (1 << 0); break;
      case 'd': d = (1 << 1); break;
      case 'e': d = (1 << 5); break;
      case 'f': d = (1 << 4); break;
   }
   irA( d , p );
   if( !esPuntoValido( p , m ) || !esPasillo( p , m ) )
      irA( dirContr( d ) , p );

   return p;
}
# 10 "prueba.c" 2
# 1 "estructuras/stack.c" 1
# 59 "estructuras/stack.c"
int stack_gen = 1;
# 11 "prueba.c" 2
# 1 "estructuras/queue.c" 1
# 68 "estructuras/queue.c"
int queue_gen = 1;
# 12 "prueba.c" 2
# 1 "io/lectura.c" 1
typedef struct ent{
   uchar dato;
   struct ent *next;
}ent;

typedef struct queue_ent{ ent *front; ent *back; }queue_ent; queue_ent* crear_queue_ent(){ queue_ent *q = (queue_ent*)(sizeof(queue_ent)*)malloc((1)*sizeof(sizeof(queue_ent))); if( q == ((void *)0) ) return q; q->front = ((void *)0); q->back = ((void *)0); return q; } int empty_queue_ent(queue_ent *q){ return q->front == ((void *)0); } ent* front_ent(queue_ent *q){ return q->front; } void insert_queue_ent(ent *n,queue_ent *q){ if( n == ((void *)0) ) return; if(empty_queue_ent(q)) q->front = n; else q->back->next = n; q->back = n; q->back->next = ((void *)0); } ent* remove_queue_ent(queue_ent *q){ if(empty_queue_ent(q)) return ((void *)0); ent *aux = q->front; q->front = q->front->next; aux->next = ((void *)0); return aux; } void drop_queue_ent(queue_ent **q){ while(!empty_queue_ent(*q)) free(remove_queue_ent(*q)); free(*q);}

ent* nuevo_ent( int dato ){
   ent *e = (ent*)(sizeof(ent)*)malloc((1)*sizeof(sizeof(ent)));
      e->dato = dato;
   return e;
}


mapa* leerMapa( char* nombre );


void guardarMapa( char* nombre , mapa *m );

mapa* leerMapa( char* nombre ){
   FILE* fp;
   queue_ent *q;
   mapa *m;
   int tam = 0, x, y, z;
   char s[ 10 ];
   uchar c;

   fp = fopen( nombre , "r" );
   if( fp == ((void *)0) ) error( errIO[ 0 ] );

   fgets( s , sizeof( s ) , fp );
      x = atoi( s );
   fgets( s , sizeof( s ) , fp );
      y = atoi( s );
   fgets( s , sizeof( s ) , fp );
      z = atoi( s );

   if( x <= 1 || y <= 1 || z <= 1 ) error( errIO[ 1 ] );
   if( 1024 < x || 1024 < y || 1024 < z ) error( errIO[ 2 ] );

   q = crear_queue_ent();
   while( !((fp)->_flag & 0x0010) ){
      c = fgetc ( fp );
      if( isdigit( c ) ){
         insert_queue_ent( nuevo_ent( c - '0' ) , q );
         tam++;
      }
   }
   fclose( fp );

   if( tam != x*y*z ){
      drop_queue_ent( &q );
      error( errIO[ 3 ] );
   }

   m = crearMapa( x , y , z );
   tam = 0;
   while( !empty_queue_ent( q ) ){
      m->coord[ tam++ ] = front_ent( q )->dato;
      free( remove_queue_ent( q ) );
   }
   obtenMetas( m );

   drop_queue_ent( &q );

   return m;
}

void guardarMapa( char* nombre , mapa *m ){
   FILE *fp = fopen( nombre , "w" );
   if( fp == ((void *)0) ) error( errIO[ 4 ] );

   fprintf( fp , "%d\n" , m->long_x );
   fprintf( fp , "%d\n" , m->long_y );
   fprintf( fp , "%d\n" , m->long_z );

   int i, j, k, x = m->long_x, y = m->long_y, z = m->long_z;
   for(k = 0; k < z; k++){
      for(j = 0; j < y; j++){
         for(i = 0; i < x; i++){
            fprintf( fp , "%d" , m->coord[ i + j*x + k*x*y ] );
         }
         fprintf( fp , "\n" );
      }
      fprintf( fp , "------------------------------------\n" );
   }

   fclose( fp );
}
# 13 "prueba.c" 2

typedef struct stack_punto{ punto *top; }stack_punto; stack_punto* crear_stack_punto(){ stack_punto *s = (stack_punto*)(sizeof(stack_punto)*)malloc((1)*sizeof(sizeof(stack_punto))); if( s != ((void *)0) ) s->top = ((void *)0); return s; } int empty_stack_punto(stack_punto *s){ return s->top == ((void *)0); } punto* top_punto(stack_punto *s){ return s->top; } void push_punto(punto *n,stack_punto *s){ n->next = s->top; s->top = n; } punto* pop_punto(stack_punto *s){ punto *aux = s->top; if(aux != ((void *)0)){ s->top = s->top->next; aux->next = ((void *)0); } return aux; } void drop_stack_punto(stack_punto **s){ while(!empty_stack_punto(*s)) free(pop_punto(*s)); free(*s); }
typedef struct queue_punto{ punto *front; punto *back; }queue_punto; queue_punto* crear_queue_punto(){ queue_punto *q = (queue_punto*)(sizeof(queue_punto)*)malloc((1)*sizeof(sizeof(queue_punto))); if( q == ((void *)0) ) return q; q->front = ((void *)0); q->back = ((void *)0); return q; } int empty_queue_punto(queue_punto *q){ return q->front == ((void *)0); } punto* front_punto(queue_punto *q){ return q->front; } void insert_queue_punto(punto *n,queue_punto *q){ if( n == ((void *)0) ) return; if(empty_queue_punto(q)) q->front = n; else q->back->next = n; q->back = n; q->back->next = ((void *)0); } punto* remove_queue_punto(queue_punto *q){ if(empty_queue_punto(q)) return ((void *)0); punto *aux = q->front; q->front = q->front->next; aux->next = ((void *)0); return aux; } void drop_queue_punto(queue_punto **q){ while(!empty_queue_punto(*q)) free(remove_queue_punto(*q)); free(*q);}

# 1 "debug.c" 1







void debug( int debugType , void *var , char *s ){
   printf("%s:", s );
   punto *a; dir *b;
   dir arr[ 6 ] = {(1 << 5),(1 << 4),(1 << 0),(1 << 3),(1 << 2),(1 << 1)};
   char *arr_s[ 6 ] = {"AR","AB","OE","NO","SU","ES"};
   int i;
   switch( debugType ){
      case 3450:
         a = (punto*)var;
         printf("(%d,%d,%d),", a->x , a->y , a->z );
         break;
      case 3451:
         b = (dir*)var;
         for(i = 0; i < 6; i++)
            if( (*b) & arr[ i ] ) printf("%s:", arr_s[ i ] );
         printf(",");
         break;
   }
}
# 18 "prueba.c" 2
# 1 "generar.c" 1





punto* puntoAleatorio( mapa *m );

dir dirAleatoria( dir *d );

int esDestruible( punto *p , mapa *m );

dir dirDestruibles( punto *p , mapa *m );

void actualizaMurosAdy( punto *p , mapa *m );

void borrarDir( dir *elim , dir *d );

void generarLaberinto( mapa *m );



punto* puntoAleatorio( mapa *m ){
   return crearPunto( rand()%(m->long_x) ,
                      rand()%(m->long_y) ,
                      rand()%(m->long_z) );
}


dir dirAleatoria( dir *d ){
   dir opciones[ 4*(500) + 2 ];
   int num_op = 0, i , j;

   for(i = 0; i < 6; i++){
      if( (*d) & d_arr[ i ] ){
         if( d_arr[ i ] == (1 << 5) || d_arr[ i ] == (1 << 4) )
            opciones[ num_op++ ] = d_arr[ i ];
         else{
            for(j = 0; j < (500); j++)
            opciones[ num_op++ ] = d_arr[ i ];
         }
      }
   }

   if( num_op == 0 ) return ( 0 );
   if( num_op == 1 ) return opciones[ 0 ];
   return opciones[ rand()%num_op ];
}

int esDestruible( punto *p , mapa *m ){
   return esMuro( p , m ) && *( coordP( p , m ) ) == 1;
}

dir dirDestruibles( punto *p , mapa *m ){
   if( !esPuntoValido( p , m ) ) return ( 0 );
   dir ds = ( 0 );
   int i;

   for(i = 0; i < 6; i++){
      irA( d_arr[ i ] , p );
      if( esPuntoValido( p , m ) && esDestruible( p , m ) )
         ds += d_arr[ i ];
      irA( dirContr( d_arr[ i ] ) , p );
   }

   return ds;
}

void actualizaMurosAdy( punto *p , mapa *m ){
   int i;
   for(i = 0; i < 6; i++){
      irA( d_arr[ i ] , p );
      if( esPuntoValido( p , m ) && esMuro( p , m ) )
         *( coordP( p , m ) ) += 1;
      irA( dirContr( d_arr[ i ] ) , p );
   }
}

void borrarDir( dir *elim , dir *d ){ *d &= !( *elim ); }

void generarLaberinto( mapa *m ){
   stack_punto *pila = crear_stack_punto();
   queue_punto *cola = crear_queue_punto();

   dir d = ( 0 );
   int esNuevaRama = 1;


   punto *p = crearPunto( 0 , 0 , 0 );
      convierteAPasillo( p , m );
      actualizaMurosAdy( p , m );
# 101 "generar.c"
   if( 0 )
      do{ pintarMapa( p , m ); imprimirPantalla(); debug( 0 , m , "Inicio-------------" ); debug( 3450 , p , "Punto" ); debug( 3451 , &d , "Dir" ); leerDeConsola(); }while( 0 );
   do{
      d = dirDestruibles( p , m );
      if( 0 ) do{ pintarMapa( p , m ); imprimirPantalla(); debug( 0 , m , "Antes   de decision" ); debug( 3450 , p , "Punto" ); debug( 3451 , &d , "Dir" ); leerDeConsola(); }while( 0 );
      if( d != ( 0 ) ){
         push_punto( p , pila );
         p = crearPunto( p->x , p->y , p->z );
            irA( dirAleatoria( &d ) , p );
            convierteAPasillo( p , m );
            actualizaMurosAdy( p , m );
         esNuevaRama = 1;
      }else{
         if( esNuevaRama )
            insert_queue_punto( p , cola );
         else
            free( p );
         p = pop_punto( pila );
         esNuevaRama = 0;
      }
      if( p != ((void *)0) ) if( 0 )
      do{ pintarMapa( p , m ); imprimirPantalla(); debug( 0 , m , "Despues de decision" ); debug( 3450 , p , "Punto" ); debug( 3451 , &d , "Dir" ); leerDeConsola(); }while( 0 );
   }while( p != ((void *)0) );
   drop_queue_punto( &cola );






}
# 19 "prueba.c" 2

int main( int argc , char** argv ){

   mapa *m =
                            leerMapa( "nuevoMapa2.txt" );
   punto *jug = crearPunto( 0 , 0 , 0 );
   char *s = ((void *)0);
   while( 1 ){
      pintarMapa( jug , m );
      imprimirPantalla();
      s = leerDeConsola();
      if( s[ 0 ] == '0' ){ break; }
      mover( s[ 0 ] , jug , m );
   }




   free( jug );
   borrarMapa( &m );

   return 0;
}
