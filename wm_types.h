// CONTEXT PREFIX
// g_Global			: g_ = Global
// i_Input			: i_ = Input
// l_Local			: l_ = Local
// m_Member			: m_ = Member
// o_Output			: o_ = Output
// p_Protected		: p_ = Protected, or Private
// ...				: use your imagination

// TYPE PREFIX
// aArray			: a  = Array		(array)
// bBool			: b  = Boolean		(boolean, TRUE/FALSE)
// cConstant		: c  = Constant		(constant, whatever...)
// dDefine			: d  = Define		(simple define, defined value or defined type)
// eEnum			: e  = Enum			(enum list element)
// fFunction		: f  = Function 	(typically a function pointer)
// hHandle			: h  = Handle		(handle, identifier, implementation dependent)
// iIterator		: i  = Iterator		(like STL iterator)
// mMacro			: m  = Macro		(preprocessor macro, mostly compiler dependent, beware)
// nNumber			: n  = Number		(char, long, int, float, double, complex, rational, whatever...)
// oObject			: o  = Object		(C++ class, complex structure with embedded functions, ...)
// pPointer			: p  = Pointer		(typically a 32 bits address)
// rReference		: r  = Reference	(reference, unlike pointer, can't be changed once assigned at initialization)
// sStruct			: s  = Struct		(structure)
// tTemplate		: t  = Template		(template, mostly C++ only, can be emulated using macro)
// uUnion			: u  = Union		(join two or more values of the same size under a common name)
// vVolatile		: v  = Volatile		(volatile data, not constant)

// TYPE PREFIX COMPOSITION
// anArrayNumber	: an = Array of Number, typically a string
// csConstantStruct	: cs = Constant Struct
// poRemoteClass	: po = Pointer on Object
// ...				: use your imagination

// EXAMPLE
// o_psBitmap		: CBitmap::GetBitmap((BITMAP*) o_psBitmap); // s = BITMAP, p = *, o_ means it's an output

// https://www.codeproject.com/Articles/4204/CSkinProgress

#if !defined(_WM_TYPES_H_)
#define _WM_TYPES_H_

#include "wm_cdefs.h"

// - - - CONSTANT DEFINITION - - - - - - - - - - - - - - - - - - - - - - - - - -

/* Boolean values for 'b1' aka 'bool' type */

#if !defined(FALSE)
	#define FALSE				(0)
#endif	// !defined(FALSE)

#if !defined(TRUE)
	#define TRUE				(1)
#endif	// !defined(TRUE)

#define DISABLED				(FALSE)
#define ENABLED					(TRUE)

#if !defined(false)								// <stdbool.h>
	#define false				(FALSE)
	#define true				(TRUE)
#endif	// !defined(false)

#if !defined(NULL)
	#define NULL				(FALSE)
#endif	// !defined(NULL)

#define OFF						(FALSE)
#define ON						(TRUE)

#define LOW						(FALSE)
#define HIGH					(TRUE)

// Standard returned values of function
#define KO						(-1)
#define OK						(0)

// Standard compared values of sorting
#define LT						(-1)
#define EQ						(0)
#define GT						(1)

/* Peripheral not Initialized */
//#define STATE_RESET			(0)

/* Peripheral Initialized and ready for use */
//#define STATE_READY			(1)

/* an internal process is ongoing */
//#define STATE_BUSY			(2)

// - - - DATATYPE DEFINITION - - - - - - - - - - - - - - - - - - - - - - - - - -

// UTILS SYSTEM WIDE DATA TYPES
// FIXME sw evolution : add new data type here

typedef signed int				bool_t;

typedef signed char				int8_t;
typedef signed short int		int16_t;
#if defined(WIN32)
typedef signed int				int32_t;
#else	// defined(WIN32)
typedef signed long int			int32_t;
#endif	// defined(WIN32)
#if defined(__LP64__)
typedef signed long long int	int64_t;
#else	// defined(__LP64__)
typedef signed long long int	int64_t;
#endif	// defined(__LP64__)

typedef unsigned char			byte_t;		// 1 byte
typedef unsigned char			u_int8_t;
typedef unsigned short int		u_int16_t;
#if defined(WIN32)
typedef unsigned int			u_int32_t;
#else	// defined(WIN32)
typedef unsigned long int		u_int32_t;
#endif	// defined(WIN32)
#if defined(__LP64__)
typedef unsigned long int		u_int64_t;
#else	// defined(__LP64__)
typedef unsigned long long int	u_int64_t;
#endif	// defined(__LP64__)

#if defined(__LP64__)
	#define BIT_TOP				S64(0x8000000000000000)
	#define NBITS				(64)
	typedef unsigned long		uint_t;  // preferred int type on platform
	typedef long				int_t;
	typedef int64_t				offset_t;
	typedef u_int64_t			index_t;
	typedef int64_t				ptrint_t; // pointer-size int
	typedef u_int64_t			u_ptrint_t;
#if defined(WIN32)
	typedef int64_t				ssize_t;
#endif	// defined(WIN32)
//	typedef u_int64_t			size_t;

#else	// defined(__LP64__)

	#define BIT_TOP				S32(0x80000000)
	#define NBITS				(32)
	typedef unsigned long		uint_t;
	typedef long				int_t;
	typedef int32_t				offset_t;
	typedef u_int32_t			index_t;
	typedef int32_t				ptrint_t;
	typedef u_int32_t			u_ptrint_t;
#if defined(WIN32)
	typedef int32_t				ssize_t;
#endif	// defined(WIN32)
//	typedef u_int32_t			size_t;
#endif	// defined(__LP64__)

typedef u_int8_t				uint8_t;
typedef u_int16_t				uint16_t;
typedef u_int32_t				uint32_t;
typedef u_int64_t				uint64_t;
typedef u_ptrint_t				uptrint_t;

#if !defined(_BOOL_DEFINED_)
//	typedef int					bool;
	#define _BOOL_DEFINED_
#endif // _BOOL_DEFINED_

#if !defined(__STD_UTF_16__)
//typedef uint_least16_t		char16_t;
#endif	// !defined(__STD_UTF_16__)

#if !defined(__STD_UTF_32__)
//typedef uint_least32_t		char32_t;
#endif	// !defined(__STD_UTF_32__)

// Old definitions (/!\ legacy support)
typedef bool					b1;				// bool

typedef int8_t					s8;				// /!\ ARM FPU register name
typedef uint8_t					u8;
typedef int16_t					s16;			// /!\ ARM FPU register name
typedef uint16_t				u16;
#if 1
typedef int32_t					s32;			// /!\ Platform dependent
typedef uint32_t				u32;

#else	// 0

typedef long int				s32;
typedef long unsigned int		u32;
#endif	// 0
typedef int64_t					s64;
typedef uint64_t				u64;

typedef float					f32;
typedef double					f64;
typedef long double				f96;
#if 0
typedef __float128				f128;
typedef __float256				f256;
#endif	// 0

#if !defined(ascii)
typedef char					ascii;			// /!\ Might be unsigned using compiler flag
#endif	// !defined(ascii)

#define DECL_IDENTITY(id)													\
			d ## id

#if 1
#define DECL_DERIVATE__ID(id)												\
			id

#else	// 1

#define DECL_DERIVATE__ID(id)												\
			id,				const c ## id,		volatile v ## id
#endif	// 1

#if defined(__cplusplus) || defined(c_plusplus)
#define DECL_DERIVATE__REF(id)												\
			& r ## id

#else	// defined(__cplusplus) || defined(c_plusplus)

#define DECL_DERIVATE__REF(id)
#endif	// defined(__cplusplus) || defined(c_plusplus)

#define DECL_DERIVATE__CORE(id)												\
			** pp ## id,	** const cpp ## id,	** volatile vpp ## id,		\
			* p ## id,		* const cp ## id,	* volatile vp ## id,		\
			DECL_DERIVATE__ID(id)

#define DECL_DERIVATE(id)													\
			DECL_DERIVATE__REF(id),											\
			DECL_DERIVATE__CORE(id)

#define DECL_FUNCTION(type, id, ...)										\
			typedef	type (** volatile const	vcpp ## id)	__VA_ARGS__;		\
			typedef	type (** volatile		vpp ## id)	__VA_ARGS__;		\
			typedef	type (** const			cpp ## id)	__VA_ARGS__;		\
			typedef	type (**				pp ## id)	__VA_ARGS__;		\
			typedef	type (* volatile const	vcp ## id)	__VA_ARGS__;		\
			typedef	type (* volatile		vp ## id)	__VA_ARGS__;		\
			typedef	type (* const			cp ## id)	__VA_ARGS__;		\
			typedef	type (*					p ## id)	__VA_ARGS__

#define DECL_NUMERIC(type, id)												\
			typedef	volatile const	type	DECL_DERIVATE(vc ## id);		\
			typedef	volatile		type	DECL_DERIVATE(v ## id);			\
			typedef	const			type	DECL_DERIVATE(c ## id);			\
			typedef					type	DECL_DERIVATE(id)

#if defined(__cplusplus) || defined(c_plusplus)
#define DECL_TYPEDEF(type, id)												\
			DECL_TYPEDEF_##type(id)

#define DECL_INSTANCE(type, id)												\
			DECL_INSTANCE_##type(id)

#define DECL_INSTANCE_CORE(type, id)										\
			typedef	volatile const	type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(vc ## id);		\
			typedef	volatile		type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(v ## id);			\
			typedef	const			type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(c ## id);			\
			typedef					type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(id)

#define DECL_TYPEDEF_PRE(type, id)											\
			DECL_INSTANCE_CORE(type, id);									\
			DECL_TYPEDEF_POST(type, id)

#define DECL_INSTANCE_PRE(type, id)											\
											DECL_DERIVATE(id)

#define DECL_TYPEDEF_POST(type, id)											\
			typedef					type	DECL_IDENTITY(id)

#define DECL_INSTANCE_POST(type, id)										\
			DECL_INSTANCE_PRE(type, id);									\
			DECL_INSTANCE_CORE(type, id)

// Enum

#define DECL_TYPEDEF_enum(id)												\
			DECL_TYPEDEF_POST(enum, id)

#define DECL_INSTANCE_enum(id)												\
			DECL_INSTANCE_POST(enum, id)

// Struct

#define DECL_TYPEDEF_struct(id)												\
			DECL_TYPEDEF_PRE(struct, id)

#define DECL_INSTANCE_struct(id)											\
			DECL_INSTANCE_PRE(struct, id)

// Union

#define DECL_TYPEDEF_union(id)												\
			DECL_TYPEDEF_PRE(union, id)

#define DECL_INSTANCE_union(id)												\
			DECL_INSTANCE_PRE(union, id)

#else	// defined(__cplusplus) || defined(c_plusplus)

#define DECL_TYPEDEF(type, id)												\
			typedef	volatile const	type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(vc ## id);		\
			typedef	volatile		type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(v ## id);			\
			typedef	const			type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(c ## id);			\
			typedef					type	DECL_IDENTITY(id)				\
											DECL_DERIVATE(id);				\
			typedef					type	DECL_IDENTITY(id)

#define DECL_INSTANCE(type, id)												\
											DECL_DERIVATE(id)
#endif	// defined(__cplusplus) || defined(c_plusplus)

DECL_NUMERIC(ssize_t, Size);
DECL_NUMERIC(time_t, Time);

// Boolean

DECL_NUMERIC(b1, bB1);

// Signed integer

DECL_NUMERIC(int, nS);							// /!\ Architecture dependent
DECL_NUMERIC(s8, nS8);
DECL_NUMERIC(s16, nS16);
DECL_NUMERIC(s32, nS32);
DECL_NUMERIC(s64, nS64);

DECL_TYPEDEF(union, uS)
{ nS8				_8
; nS16				_16
; nS32				_32
; nS64				_64
//
; nS64				_							// Biggest sized member
;}	DECL_INSTANCE(union, uS);

// Unsigned integer

DECL_NUMERIC(unsigned int, nU);					// /!\ Architecture dependent
DECL_NUMERIC(u8, nU8);
DECL_NUMERIC(u16, nU16);
DECL_NUMERIC(u32, nU32);
DECL_NUMERIC(u64, nU64);

DECL_TYPEDEF(union, uU)
{ nU8				_8
; nU16				_16
; nU32				_32
; nU64				_64
//
; nU64				_							// Biggest sized member
;}	DECL_INSTANCE(union, uU);

// Floating point

DECL_NUMERIC(f32, nF);							// /!\ Architecture (almost) dependent
DECL_NUMERIC(f32, nF32);
DECL_NUMERIC(f64, nF64);
DECL_NUMERIC(f96, nF96);

DECL_TYPEDEF(union, uF)
{ nF32				_32
; nF64				_64
//
; nF64				_							// Biggest sized member
;}	DECL_INSTANCE(union, uF);

// Void and basic function pointer

#undef DECL_DERIVATE
#define DECL_DERIVATE(id)													\
			DECL_DERIVATE__CORE(id)
// /!\ Disable '&' reference support on 'void'
DECL_NUMERIC(void, Void);
DECL_TYPEDEF(struct, sVoid)
{ bB1				dummy[1]					// C++ doesn't allow empty array
;}	DECL_INSTANCE(struct, sVoid);
// /!\ Restore '&' reference support on 'void'
#undef DECL_DERIVATE
#define DECL_DERIVATE(id)													\
			DECL_DERIVATE__REF(id),											\
			DECL_DERIVATE__CORE(id)

DECL_NUMERIC(pVoid, hHandle);
DECL_NUMERIC(pVoid, HANDLE);					// For Windows(C)(R)TM compatibility

#define HANDLE_INVALID			((hHandle) -1)
#define HANDLE_ITSELF			((hHandle) -2)
#define HANDLE_ROOT				((hHandle) -3)
#define HANDLE_ANY				((hHandle) -4)

DECL_FUNCTION(Void, fVoid_Void, (Void));
DECL_FUNCTION(Void, fVoid_pVoid, (pVoid));
DECL_FUNCTION(nU32, fU32_Void, (Void));
DECL_FUNCTION(bB1, fB1_Void, (Void));

// - - - EXTERNAL DECLARATION  - - - - - - - - - - - - - - - - - - - - - - - - -


// - - - HIERARCHIC INCLUSION  - - - - - - - - - - - - - - - - - - - - - - - - -


// - - - PROTOTYPE DEFINITION  - - - - - - - - - - - - - - - - - - - - - - - - -


// - - - MACRO DEFINITION  - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define unless(cond)			if (!(cond))
#define until(cond)				while (!(cond))

#define force_const(...)		(__builtin_choose_expr(__builtin_constant_p(__VA_ARGS__), (__VA_ARGS__), (void) 0))

#if defined(_NDEBUG) || defined(_RELEASE) || defined(__RELEASE)
	#define CHECK_ASSERT(...)	(true) // ((true)||(x))

#else // defined(_NDEBUG) || defined(_RELEASE) || defined(__RELEASE)

	#define CHECK_ASSERT(...)	( __VA_ARGS__ )
#endif // defined(_NDEBUG) || defined(_RELEASE) || defined(__RELEASE)

// Manipulating preprocessor

#define MACRO_STRING_(s)		#s
#define MACRO_STRING(s)			MACRO_STRING_(s)

#define MACRO_CONCAT_(a, b)		a ## b
#define MACRO_CONCAT(a, b)		MACRO_CONCAT_(a, b)

#define MACRO_TOKEN(token)		__ ## token ## __

#define ICE_P(...)				(sizeof(int) == sizeof(*(1 ? ((void*)((__VA_ARGS__) * 0l)) : (int*) 1)))

//#define __DIM(x)				(sizeof(x) / sizeof(*(x)))
#define __DIM(x)				(sizeof(x) / sizeof(x[0]))

#define WAIT(...)				while ( __VA_ARGS__ ) { ; }

// Manipulating memory

#define WORD_SIZE				sizeof(int)
#define WORD_SIZE_BITS			(WORD_SIZE * 8)

#define ALIGN_POWER				(3)				// 2^3 or 1<<3 = 8 bytes
#define ALIGN_SIZE				(1 << ALIGN_POWER)

#define MEM_ALIGN(x)			(((x) + (ALIGN_SIZE - 1)) & (0 - (1 << (ALIGN_POWER - 0))))
#define REF_ALIGN(r)			(((r) + (ALIGN_SIZE - 0)) & (0 - (1 << (ALIGN_POWER - 1))))

// Manipulating integer

#define S8(x)					(x ## HH)
#define U8(x)					(x ## UHH)
#define S16(x)					(x ## H)
#define U16(x)					(x ## UH)

#define S32(x)					(x ## L)
#define U32(x)					(x ## UL)
#define S64(x)					(x ## LL)
#define U64(x)					(x ## ULL)

#if defined(__LP64__)
#define S(x)					S64(x)

#else	// defined(__LP64__)

#define S(x)					S32(x)
#endif	// defined(__LP64__)

#define U(x)					( x ## U)
#define H(h)					(0x ## h)

#define __C8(...)				((cnS8) __VA_ARGS__ )
#define __S8(...)				((nS8) __VA_ARGS__ )
#define __U8(...)				((nU8) __VA_ARGS__ )
#define __C16(...)				((cnS16) __VA_ARGS__ )
#define __S16(...)				((nS16) __VA_ARGS__ )
#define __U16(...)				((nU16) __VA_ARGS__ )

#define __C32(...)				((cnS32) __VA_ARGS__ )
#define __S32(...)				((nS32) __VA_ARGS__ )
#define __U32(...)				((nU32) __VA_ARGS__ )
#define __C64(...)				((cnS64) __VA_ARGS__ )
#define __S64(...)				((nS64) __VA_ARGS__ )
#define __U64(...)				((nU64) __VA_ARGS__ )

#if defined(__LP64__)
#define __C(...)				__C64( __VA_ARGS__ )
#define __S(...)				__S64( __VA_ARGS__ )
#define __U(...)				__U64( __VA_ARGS__ )

#else	// defined(__LP64__)

#define __C(...)				__C32( __VA_ARGS__ )
#define __S(...)				__S32( __VA_ARGS__ )
#define __U(...)				__U32( __VA_ARGS__ )
#endif	// defined(__LP64__)

// Manipulating float

#define F32(x)					(x ## f)
#define F64(x)					(x)
#define F96(x)					(x)

#if 0
#define F128(x)					(x)
#define F256(x)					(x)
#endif	// 0

#define F(x)					F32(x)

#define __F32(...)				((nF32) __VA_ARGS__ )
#define __F64(...)				((nF64) __VA_ARGS__ )
#define __F96(...)				((nF96) __VA_ARGS__ )

// Manipulating BCD (Binary Coded Decimal)

#define DEC2BCD(byte)			((byte % 10) | ((byte / 10) << 4))
#define BCD2DEC(byte)			(BIT_READ(byte, 0x0F) + 10 * ((byte >> 4) & 0x0F))

// Manipulating endianess

#define E08(x)					((x) & 0x0FF)
#define E16(x)					((E08((x) >> 8))  | (E08((x) & __U16(0x00FF))) << 8)
#define E32(x)					((E16((x) >> 16)) | (E16((x) & __U32(0x0000FFFF))) << 16)
#define E64(x)					((E32((x) >> 32)) | (E32((x) & __U64(0x00000000FFFFFFFF))) << 32)

// Manipulating data

#define CLEAR(reg)				((reg)  =  0)
#define SET(reg, val)			((reg)  =  (val))
#define IS_SET(reg)				((reg) !=  0)

#define REG_READ(reg)			((reg))
#define REG_CLEAR(reg)			((reg)  = U(0x0))
#define REG_WRITE(reg, val)		((reg)  =  (val))
#define REG_MODIFY(reg, clear, set)											\
								REG_WRITE									\
								( (reg)										\
								,	(	( (REG_READ(reg))					\
										& (~(clear))						\
										)									\
									| (set)									\
									)										\
								)

#define MSK_READ(reg, msk)		((reg) &   (msk))
#define MSK_CLEAR(reg, msk)		((reg) &= ~(msk))
#define MSK_NOT(reg, msk)		((reg) &  ~(msk))
#define MSK_SET(reg, msk)		((reg) |=  (msk))
#define MSK_IS_SET(reg, msk)	(MSK_READ(reg, msk) != 0)

#define BIT_READ(reg, bit)		((reg) &   (1 << bit))
#define BIT_CLEAR(reg, bit)		((reg) &= ~(1 << bit))
#define BIT_NOT(reg, bit)		((reg) &  ~(1 << bit))
#define BIT_SET(reg, bit)		((reg) |=  (1 << bit))
#define BIT_IS_SET(reg, bit)	(BIT_READ(reg, bit)	!= 0)

// Manipulating cast

#if !defined(__INT)
	#define __INT(...)		__S( __VA_ARGS__ )
#endif // __INT

#if !defined(__PTR)
	#define __PTR(...)		((pVoid) __INT( __VA_ARGS__ ))
#endif // !defined(__PTR)

#if !defined(__PPTR)
	#define __PPTR(...)		&(pVoid) { (pVoid) __VA_ARGS__ }
#endif // !defined(__PPTR)

// Manipulating structure

#if !defined(OFFSET_OF)
	#define OFFSET_OF(type, member)											\
				((nU32) &(((type*) 0)->member))
#endif // !defined(OFFSET_OF)

#if !defined(OFFSETOF)
	#define OFFSETOF(type, member)											\
				OFFSET_OF(type, member)
#endif // !defined(OFFSETOF)

#if !defined(MEMBER_SIZE)
	#define MEMBER_SIZE(type, member)										\
				sizeof(((type*) 0)->member)
#endif // !defined(MEMBER_SIZE)

#if !defined(OFFSET_AND_SIZE_OF)
	#define OFFSET_AND_SIZE_OF(type, member)								\
		OFFSET_OF(type, member), MEMBER_SIZE(type, member)
#endif // !defined(OFFSET_AND_SIZE_OF)

#if !defined(OSOF)
	#define OSOF(type, member)												\
		OFFSET_AND_SIZE_OF(type, member)
#endif // !defined(OSOF)

#if !defined(CONTAINER_OF)
#if 0
	#define CONTAINER_OF(ptr, type, member)									\
				{ const typeof(((type*) 0)->member)							\
					*__mptr = (ptr);										\
				(type*)														\
					( (char*) __mptr										\
					- OFFSET_OF(type, member)								\
					);														\
				}

#else	// 0

	#define CONTAINER_OF(ptr, type, member)									\
				(type*)														\
					( (char*)(1 ? (ptr) : &((type*) 0)->member)				\
					- OFFSET_OF(type, member)								\
					)
#endif	// 0
#endif // !defined(CONTAINER_OF)

#if !defined(ADDRESS_OF)
	#define ADDRESS_OF(base, type, member)									\
				__PTR(__INT(base) + OFFSET_OF(type, member))
#endif // !defined(ADDRESS_OF)

// Looping

#if !defined(FOR_EACH_INC)
	#define FOR_EACH_INC(var, val)											\
				for (var = 0; var < val; var += 1)
#endif // !defined(FOR_EACH_INC)

#if !defined(FOR_EACH_DEC)
	#define FOR_EACH_DEC(var, val)											\
				for (var = val - 1; 0 <= var; var -= 1)
#endif // !defined(FOR_EACH_DEC)

#if !defined(FOR_EACH_PTR)
	#define FOR_EACH_PTR(var, val, nxt)										\
				for (var = val; NULL != var; var = nxt)
#endif // !defined(FOR_EACH_PTR)

#if !defined(FOR_EACH)
	#define FOR_EACH(var, max)												\
				FOR_EACH_INC(var, max)
#endif // !defined(FOR_EACH)

// - - - INLINE DEFINITION - - - - - - - - - - - - - - - - - - - - - - - - - - -


#endif	// _WM_TYPES_H_
