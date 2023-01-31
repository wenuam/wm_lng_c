#ifndef _WM_CDEFS_H_
#define _WM_CDEFS_H_

//#define WARNING_INTERNALS

// Compiler constants
// __FILE__				= "/usr/local/include/myheader.h"
// __LINE__				= line number can be modified using #line
// __DATE__				= "Feb 12 1996"
// __TIME__				= "23:59:01"
// __TIMESTAMP__		= "Day Mmm dd hh:mm:ss yyyy"

// __func__				= function name being compiled "sub" (C99)
// __FUNCTION__			= function name being compiled "sub"
// __PRETTY_FUNCTION__	= function name with arguments "void class::sub(int)"

#if defined(__GNUC__)
	#define __FUNC__	__PRETTY_FUNCTION__
#else	// defined(__GNUC__)
	#define __FUNC__	__FUNCSIG__
//	#define __FUNC__	__FUNCTION__
//	#define __FUNC__	__FUNCDNAME__
#endif	// defined(__GNUC__)

// __ANSI__				= defined if ANSI C
// __STDC__				= 1 if ISO C
// __STDC_VERSION__		= 199409L -> C89 amended in 09/1994
// __STDC_HOSTED__		= 1 if hosted environment, entire standard library

// __STDCPP_THREADS__
// __STDCPP_STRICT_POINTER_SAFETY__

// __STDC_ISO_10646__
// __STDC_MB_MIGHT_NEQ_WC__

// __ASSEMBLER__		= 1 if assembler
// __OBJC__				= 1 if Objective-C compiler
// __cplusplus			= defined if C++ compiler

// __BYTE_ORDER			= either __LITTLE_ENDIAN or __BIG_ENDIAN
// LITTLE_ENDIAN		= defined if LE

#if defined(WIN32)
	#if !defined(WIN32_LEAN_AND_MEAN)
//		#define WIN32_LEAN_AND_MEAN
	#endif	// !defined(WIN32_LEAN_AND_MEAN)
	#if defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 1)
		// Logic using the traditional preprocessor
		#error You''re gonna have a bad time, without proper preprocessor conformance
	#else	// defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 1)
		// Logic using cross-platform compatible preprocessor
	#endif	// defined(_MSVC_TRADITIONAL) && (_MSVC_TRADITIONAL == 1)
#else	// defined(WIN32)
#endif	// defined(WIN32)

#define _CTYPE_H_
#define _DEFAULT_SOURCE							// For '__BSD_VISIBLE' -> 'M_PI_x'

#define DO_PRAGMA(x)			_Pragma (#x)
#define COMPILING()				DO_PRAGMA(message ("Compiling " __FILE__ "..."))
#define TODO(x)					DO_PRAGMA(message ("TODO - " #x))

#if defined(__GLIBC__)
	// Env vars to kill gnu libstdc++ allocation pools, a bit slower but more stable
	#define GLIBCPP_FORCE_NEW	1
	#define GLIBCXX_FORCE_NEW	1
#endif	// defined(__GLIBC__)

#define ASSERT_AT_BUILD(cond)	{ ((void) sizeof(char[2*!!( cond )) - 1])) }

#if 0
// Kill the '_EXFUN' macro from '_ansi.h'
#define _ANSIDECL_H_
#define _PTR					void *
#define _EXFUN(name, proto)		__ ## fun (void)
#define _EXFNPTR(name, proto)	__ ## fun (void)
#endif	// 0

#define STD_DECLARE
#if defined(STD_DECLARE)
	#define FREESTANDING
	#if defined(FREESTANDING)
		#include <float.h>
//		#include <iso646.h>
		#include <limits.h>						// *_MAX
		#include <stdarg.h>						// va_list, va_start, va_arg, va_end
		#include <stdbool.h>					// bool
//		#include <stddef.h>
		#include <stdint.h>

		int main(void);
	#else	// defined(FREESTANDING)
		int main(int argv, char* argv[], char* env[]);
	#endif	// defined(FREESTANDING)

		#include <assert.h>
//		#include <complex.h>
//		#include <ctype.h>
//		#include <dirent.h>
//		#include <dlfcn.h>
//		#include <errno.h>
//		#include <fcntl.h>
//		#include <fenv.h>
//		#include <inttypes.h>
//		#include <locale.h>
//		#include <math.h>						// cos, sin, tan, atan, atan2, pow, sqrt
//		#include <pthread.h>
//		#include <setjmp.h>						// setjmp, longjmp, jmp_buf
//		#include <signal.h>
//		#include <stdio.h>						// printf, sprintf, snprintf, fopen, fclose
//		#include <stdlib.h>						// abs, div, malloc, free, rand, srand
//		#include <string.h>						// memset
//		#include <sys/stat.h>
//		#include <sys/types.h>
//		#include <sys/unistd.h>
//		#include <tgmath.h>
//		#include <time.h>						// tm, time_t
//		#include <uchar.h>						//
//		#include <utime.h>
//		#include <wchar.h>
//		#include <wctype.h>
#else	// defined(STD_DECLARE)
#endif	// defined(STD_DECLARE)

#if !defined(USE_HAL_DRIVER) && !defined(STD_REPLACE)
	#define STD_EMULATE
#endif	// !defined(USE_HAL_DRIVER) && !defined(STD_REPLACE)

#if defined(WIN32)
	#define STDCALL __stdcall

	#if defined(IMPORT_EXPORTS)
		#define DLLEXPORT __declspec(dllimport)
	#else	// IMPORT_EXPORTS
		#define DLLEXPORT __declspec(dllexport)
	#endif	// IMPORT_EXPORTS
#else	// defined(WIN32)
	#define STDCALL
	#define DLLEXPORT __attribute__ ((visibility("default")))
#endif	// defined(WIN32)

#if defined(__INTEL_COMPILER) && defined(WIN32)
	#define STATIC_INLINE		static
	#define INLINE

	#if defined(__LP64__)
		typedef unsigned long	size_t;
	#else	// defined(__LP64__)
		typedef unsigned int	size_t;
	#endif	// defined(__LP64__)
#else	// defined(__INTEL_COMPILER) && defined(WIN32)
	#define STATIC_INLINE		static inline
	#define INLINE 				inline
#endif	// defined(__INTEL_COMPILER) && defined(WIN32)

#if !defined(ssize_t)
	#if defined(__LP64__)
		typedef long			ssize_t;
	#else	// defined(__LP64__)
		typedef int				ssize_t;
	#endif	// defined(__LP64__)
#endif	// !defined(ssize_t)

//#if defined(WIN32)
#if !defined(_TIME_T_DECLARED) && !defined(_TIME_T_DEFINED)
	#define _TIME_T_DECLARED
		typedef int				time_t;
#endif	// !defined(_TIME_T_DECLARED) && !defined(_TIME_T_DEFINED)
//#endif	// defined(WIN32)

#if !defined(__EXTERN)
	#define __EXTERN			extern
#endif	// defined(__EXTERN)

#if !defined(__STATIC)
	#define __STATIC			static
#endif	// defined(__STATIC)

#if !defined(__VOLATILE)
	#define __VOLATILE			volatile
#endif	// defined(__VOLATILE)

//#if defined(__clang__) || defined(__clang_major__) || defined(__clang_minor__) || defined(__clang_patchlevel__) || defined(__clang_version__)
//#if defined(__GNUC__) || defined(__GNUG__) || defined(__GNUC_MINOR__) || defined(__GNUC_PATCHLEVEL__)
//#if defined(__HP_aCC) || defined(__HP_cc)
//#if defined(__IBMC__) || defined(__IBMCPP__)
//#if defined(__ICC)
//#if defined(__INTEL_COMPILER) || defined(__INTEL_COMPILER_BUILD_DATE)
//#if defined(__PGI) || defined(__PGIC__) || defined(__PGIC_MINOR__) || defined(__PGIC_PATCHLEVEL__)
//#if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
//#if defined(__VERSION__)
//#if defined(__xlc__) || defined(__xlC__) || defined(__xlC_ver__)
//#if defined(_MSC_BUILD) || defined(_MSC_FULL_VER) || defined(_MSC_VER)

#if defined(__CC_ARM)
	#if !defined(__ALIAS)
		#define __ALIAS(x)		__alias x
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(__CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		__inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__interrupt
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__long_call
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__naked
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__noreturn
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__optimize x
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__packed
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__section x
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__sentinel
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__unused
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__used
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__weak
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__zero_init
	#endif	// defined(__ZERO_INIT)

#elif defined(__clang__)

	#if !defined(__ALIAS)
		#define __ALIAS(x)
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT
	#endif	// defined(__ZERO_INIT)

#elif defined(__ICCARM__)

	#if !defined(__ALIAS)
		#define __ALIAS(x)		__alias x
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__interrupt
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__long_call
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__naked
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__noreturn
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__optimize x
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__packed
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__section x
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__sentinel
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__unused
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__used
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__weak
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__zero_init
	#endif	// defined(__ZERO_INIT)

#elif defined(__GCC__)

	#if !defined(__ALIAS)
		#define __ALIAS(x)		__alias x
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		inline	// __inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__interrupt
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__long_call
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__naked
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__noreturn
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__optimize x
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__packed
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__section x
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__sentinel
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__unused
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__used
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__weak
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__zero_init
	#endif	// defined(__ZERO_INIT)

#elif defined(__GNUC__)

	#if !defined(__ALIAS)
		#define __ALIAS(x)		__attribute__((alias( x )))
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__attribute__((at( x )))
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#if 0	//(__GNUC__ >= 7)
			#error GCC is a complete mess
			#define __FALLTHRU	__attribute__((fallthrough))	// C and C++03
//			#define __FALLTHRU	[[gnu::fallthrough]]			// C++11 and C++14
//			#define __FALLTHRU	[[fallthrough]]					// C++17 and above
		#else	// (__GNUC__ >= 7)
			#define __FALLTHRU
		#endif	// (__GNUC__ >= 7)
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__attribute__((always_inline))	__INLINE
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__attribute__((interrupt))
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__attribute__((long_call))
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__attribute__((naked))
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__attribute__((noinline))
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__attribute__((noreturn))
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__attribute__((optimize( x )))
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__attribute__((packed))
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__attribute__((section( x )))
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__attribute__((sentinel))
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__attribute__((unused))
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__attribute__((used))
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__attribute__((weak))
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__attribute__((zero_init))
	#endif	// defined(__ZERO_INIT)

#elif defined(__TASKING__)

	#if !defined(__ALIAS)
		#define __ALIAS(x)		__alias x
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__interrupt
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__long_call
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__naked
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__noreturn
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__optimize x
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__packed
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__section x
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__sentinel
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__unused
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__used
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__weak
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__zero_init
	#endif	// defined(__ZERO_INIT)

#elif defined(WIN32)

	#if !defined(__ALIAS)
		#define __ALIAS(x)
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		__inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT
	#endif	// defined(__ZERO_INIT)

#elif defined(WIN32X)

// https://msdn.microsoft.com/en-us/library/w5405h95.aspx
// https://msdn.microsoft.com/fr-fr/library/h7k3a0bw.aspx

	#if !defined(__ALIAS)
		#define __ALIAS(x)		__alias x
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM			__asm
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE		&
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)		( __VA_ARGS__ )
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE		__inline
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS	__forceinline
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT		__interrupt
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL		__long_call
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED			__naked
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE		__noinline
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN		__noreturn
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)	__optimize x
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)		__pack x
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED		__packed
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)	__section x
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL		__sentinel
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED		__unused
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED			__used
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK			__declspec(selectany)
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT		__zero_init
	#endif	// defined(__ZERO_INIT)

#else

	#if !defined(__ALIAS)
		#define __ALIAS(x)
	#endif	// defined(__ALIAS)
	#if !defined(__ASM)
		#define __ASM
	#endif	// defined(__ASM)
	#if !defined(__AT)
		#define __AT(x)			__at x
	#endif	// defined(__AT)
	#if !defined(__CAPTURE)
		#define	__CAPTURE
	#endif // !defined(__CAPTURE)
	#if !defined(__CAST)
		#define	__CAST(...)
	#endif // !defined(CAST)
	#if !defined(__FALLTHRU)
		#define __FALLTHRU
	#endif	// defined(__FALLTHRU)
	#if !defined(__INLINE)
		#define __INLINE
	#endif	// defined(__INLINE)
	#if !defined(__INLINE_ALWAYS)
		#define __INLINE_ALWAYS
	#endif	// defined(__INLINE_ALWAYS)
	#if !defined(__INTERRUPT)
		#define __INTERRUPT
	#endif	// defined(__INTERRUPT)
	#if !defined(__LONG_CALL)
		#define __LONG_CALL
	#endif	// defined(__LONG_CALL)
	#if !defined(__NAKED)
		#define __NAKED
	#endif	// defined(__NAKED)
	#if !defined(__NO_INLINE)
		#define __NO_INLINE
	#endif	// defined(__NO_INLINE)
	#if !defined(__NO_RETURN)
		#define __NO_RETURN
	#endif	// defined(__NO_RETURN)
	#if !defined(__OPTIMIZE)
		#define __OPTIMIZE(x)
	#endif	// defined(__OPTIMIZE)
	#if !defined(__PACK)
		#define __PACK(x)
	#endif	// defined(__PACK)
	#if !defined(__PACKED)
		#define __PACKED
	#endif	// defined(__PACKED)
	#if !defined(__SECTION)
		#define __SECTION(x)
	#endif	// defined(__SECTION)
	#if !defined(__SENTINEL)
		#define __SENTINEL
	#endif	// defined(__SENTINEL)
	#if !defined(__UNUSED)
		#define __UNUSED
	#endif	// defined(__UNUSED)
	#if !defined(__USED)
		#define __USED
	#endif	// defined(__USED)
	#if !defined(__WEAK)
		#define __WEAK
	#endif	// defined(__WEAK)
	#if !defined(__ZERO_INIT)
		#define __ZERO_INIT
	#endif	// defined(__ZERO_INIT)
#endif

#if !defined(__ASM_VOLATILE)
	#define __ASM_VOLATILE		__ASM __VOLATILE
#endif	// defined(__ASM_VOLATILE)

#if !defined(__STATIC_INLINE)
	#define __STATIC_INLINE		__STATIC __INLINE
#endif	// defined(__STATIC_INLINE)

#if defined _MSC_VER && defined __EDG__ && !defined __cplusplus
	#define inline
#endif

#if !defined(__cast)
	#define	__cast				__CAST
#endif // defined(__weak)

#if !defined(__inline__)
	#define	__inline__			__INLINE
#endif // defined(__inline__)

#if !defined(__packed)
	#define	__packed			__PACKED
#endif // defined(__packed)

#if !defined(__weak)
	#define	__weak				__WEAK
#endif // defined(__weak)

#if !defined(fallthrough)
	#define fallthrough			__FALLTHRU
#endif	// !defined(fallthrough)

#if !defined(UNUSED)
//	#define UNUSED(var)			((void)(var))
#endif	// !defined(UNUSED)

#if !defined(WIN32) && (defined(UNIX) || defined(unix) || defined(__unix) || defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)))
	// UNIX-style OS ----------------------------------------------------------
	#include <unistd.h>
	#if defined(_POSIX_IPV6) || defined(_POSIX_MAPPED_FILES) || defined(_POSIX_SEMAPHORES) || defined(_POSIX_THREADS) || defined(_POSIX_VERSION)
		// POSIX compliant ----------------------------------------------------
	#endif	// defined(_POSIX_IPV6) || defined(_POSIX_MAPPED_FILES) || defined(_POSIX_SEMAPHORES) || defined(_POSIX_THREADS) || defined(_POSIX_VERSION)
	#if (defined(UNIX) || defined(unix) || defined(__unix) || defined(__unix__)) || (defined(__APPLE__) && defined(__MACH__))
		#include <sys/param.h>
		#if defined(BSD)
			// BSD (DragonFly BSD, FreeBSD, OpenBSD, NetBSD). -----------------
		#endif	// defined(BSD)
	#endif	// (defined(UNIX) || defined(unix) || defined(__unix) || defined(__unix__)) || (defined(__APPLE__) && defined(__MACH__))
	#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__gnu_linux)
		// Linux -----------
		#include <features.h>
		#include <endian.h>

		#define LITTLE_ENDIAN		__LITTLE_ENDIAN
		#define BIG_ENDIAN			__BIG_ENDIAN
		#define PDP_ENDIAN			__PDP_ENDIAN
		#define BYTE_ORDER			__BYTE_ORDER
	#endif	// defined(linux) || defined(__linux) || defined(__linux__) || defined(__gnu_linux)
	#if defined(__APPLE__) && defined(__MACH__)
		// Apple OSX and iOS (Darwin) -----------------------------------------
		#include <TargetConditionals.h>
		#include <machine/endian.h>

		#define __LITTLE_ENDIAN		LITTLE_ENDIAN
		#define __BIG_ENDIAN		BIG_ENDIAN
		#define __PDP_ENDIAN		PDP_ENDIAN
		#define __BYTE_ORDER		BYTE_ORDER

		#if TARGET_IPHONE_SIMULATOR == 1
			// iOS in Xcode simulator -----------------------------------------
		#elif TARGET_OS_EMBEDDED == 1
			// OS embedded ----------------------------------------------------
		#elif TARGET_OS_IPHONE == 1
			// iOS on iPhone, iPad, etc. --------------------------------------
		#elif TARGET_OS_MAC == 1
			// OS X -----------------------------------------------------------
		#endif
	#endif	// defined(__APPLE__) && defined(__MACH__)
	#if (defined(__CYGWIN32__) || defined(__CYGWIN__)) && !defined(WIN32)
		// Cygwin POSIX under Microsoft Windows. ------------------------------
	#endif	// (defined(__CYGWIN32__) || defined(__CYGWIN__)) && !defined(WIN32)
	#if defined(__MINGW32__) || defined(__MINGW64__)
		// MingW under Microsoft Windows. -------------------------------------
	#endif	// defined(__MINGW32__) || defined(__MINGW64__)
	#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
	#endif	// defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
	#if defined(__SVR4) || defined(__svr4__)
	#endif	// defined(__SVR4) || defined(__svr4__)
	#if defined(hpux) || defined(__hpux)
	#endif	// defined(hpux) || defined(__hpux)
	#if defined(sun) || defined(__sun) || defined(__SunOS) || defined(__sun__)
	#endif	// defined(sun) || defined(__sun) || defined(__SunOS) || defined(__sun__)
#else	// Non UNIX-style OS.
	#if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__WIN64__)
		// Microsoft Windows (64-bit) -----------------------------------------
		#define __LITTLE_ENDIAN		1234
		#define __BIG_ENDIAN		4321
		#define __PDP_ENDIAN		3412
		#define __BYTE_ORDER		__LITTLE_ENDIAN
		#define __FLOAT_WORD_ORDER	__LITTLE_ENDIAN

		#define LITTLE_ENDIAN		__LITTLE_ENDIAN
		#define BIG_ENDIAN			__BIG_ENDIAN
		#define PDP_ENDIAN			__PDP_ENDIAN
		#define BYTE_ORDER			__BYTE_ORDER
	#elif defined(WIN32) || defined(WIN32) || defined(__WIN32) || defined(__WIN32__)
		// Microsoft Windows (32-bit) -----------------------------------------
		#define __LITTLE_ENDIAN		1234
		#define __BIG_ENDIAN		4321
		#define __PDP_ENDIAN		3412
		#define __BYTE_ORDER		__LITTLE_ENDIAN
		#define __FLOAT_WORD_ORDER	__LITTLE_ENDIAN

		#define LITTLE_ENDIAN		__LITTLE_ENDIAN
		#define BIG_ENDIAN			__BIG_ENDIAN
		#define PDP_ENDIAN			__PDP_ENDIAN
		#define BYTE_ORDER			__BYTE_ORDER
	#elif defined(WINNT) || defined(__WINNT) || defined(__WINNT__)
		// Microsoft Windows NT -----------------------------------------------
	#endif	//  defined(WINNT) || defined(__WINNT) || defined(__WINNT__)
#endif

#if defined(__GNUC__)
	#define FORCE_BIG_ENDIAN	__attribute__((__target__("little-endian")))
	#define FORCE_LITTLE_ENDIAN	__attribute__((__target__("big-endian")))
#else	// defined(__GNUC__)
	#define FORCE_BIG_ENDIAN
	#define FORCE_LITTLE_ENDIAN
#endif	// defined(__GNUC__)

#if !defined(INTMAX_T)
	#if HAVE_INTMAX_T || defined(intmax_t)
		#define INTMAX_T			intmax_t
	#else	// HAVE_INTMAX_T || defined(intmax_t)
		#define INTMAX_T			LLONG
	#endif	// HAVE_INTMAX_T || defined(intmax_t)
#endif	// !defined(INTMAX_T)

#if defined(UINTMAX_T)
	#undef UINTMAX_T
#endif	// defined(UINTMAX_T)
#if HAVE_UINTMAX_T || defined(uintmax_t)
	#define UINTMAX_T				uintmax_t
	#ifndef UINTMAX_MAX
		#define UINTMAX_MAX			ULLONG_MAX
	#endif	// !defined(UINTMAX_MAX)
#else	// HAVE_UINTMAX_T || defined(uintmax_t)
	#define UINTMAX_T				ULLONG
	#if defined(UINTMAX_MAX)
		#undef UINTMAX_MAX
	#endif	// defined(UINTMAX_MAX)
	#define UINTMAX_MAX				ULLONG_MAX
#endif	// HAVE_UINTMAX_T || defined(uintmax_t)

#if !defined(ULONG_MAX)
	// We may need ULONG_MAX as a fallback.
	#if defined(UINT_MAX)
		#define ULONG_MAX			UINT_MAX
	#else	// defined(UINT_MAX)
		#define ULONG_MAX			INT_MAX
	#endif	// defined(UINT_MAX)
#endif	// !defined(ULONG_MAX)

#if !defined(LLONG)
	#if HAVE_LONG_LONG_INT
		typedef long long int		LLONG;
	#else	// HAVE_LONG_LONG_INT
		typedef long int			LLONG;
	#endif	// HAVE_LONG_LONG_INT
#endif	// !defined(LLONG)

#if defined(ULLONG)
	#undef ULLONG
#endif	// defined(ULLONG)
#if HAVE_UNSIGNED_LONG_LONG_INT
	typedef unsigned long long int	ULLONG;
	#if !defined(ULLONG_MAX)
		#define ULLONG_MAX			ULONG_MAX
	#endif	// !defined(ULLONG_MAX)
#else	// HAVE_UNSIGNED_LONG_LONG_INT
	typedef unsigned long int		ULLONG;
	#if defined(ULLONG_MAX)
		#undef ULLONG_MAX
	#endif	// defined(ULLONG_MAX)
	#define ULLONG_MAX				ULONG_MAX
#endif	// HAVE_LONG_LONG_INT

#ifndef LDOUBLE
	#if HAVE_LONG_DOUBLE
		typedef long double			LDOUBLE;
		#define LDOUBLE_MIN_10_EXP	LDBL_MIN_10_EXP
		#define LDOUBLE_MAX_10_EXP	LDBL_MAX_10_EXP
	#else	// HAVE_LONG_DOUBLE
		typedef double				LDOUBLE;
		#define LDOUBLE_MIN_10_EXP	DBL_MIN_10_EXP
		#define LDOUBLE_MAX_10_EXP	DBL_MAX_10_EXP
	#endif	// HAVE_LONG_DOUBLE
#endif	// !defined(LDOUBLE)

#if !defined(UINTPTR_T)
	#if HAVE_UINTPTR_T || defined(uintptr_t)
		typedef uintptr_t			UINTPTR_T;
	#else	// HAVE_UINTPTR_T || defined(uintptr_t)
		typedef unsigned long int	UINTPTR_T;
	#endif	// HAVE_UINTPTR_T || defined(uintptr_t)
#endif	// !defined(UINTPTR_T)

#if !defined(PTRDIFF_T)
	#if HAVE_PTRDIFF_T || defined(ptrdiff_t)
		typedef ptrdiff_t			PTRDIFF_T;
	#else	// HAVE_PTRDIFF_T || defined(ptrdiff_t)
		typedef long int			PTRDIFF_T;
	#endif	// HAVE_PTRDIFF_T || defined(ptrdiff_t)
#endif	// !defined(PTRDIFF_T)

#if !defined(UPTRDIFF_T)
	typedef PTRDIFF_T				UPTRDIFF_T;
#endif	// !defined(UPTRDIFF_T)

#if !defined(SSIZE_T)
	#if defined(_WIN64)
		typedef long long 			SSIZE_T;
	#else	// defined(__LP64__)
		typedef long 	 			SSIZE_T;
	#endif	// defined(__LP64__)
#endif	// !defined(SSIZE_T)

#endif	// defined(_WM_CDEFS_H_)
