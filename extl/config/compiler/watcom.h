/* ///////////////////////////////////////////////////////////////////////
 * File:		watcom.h		
 *
 * Created:		08.02.02				
 * Updated:		08.04.14
 *
 * Brief: Watcom C++ compiler traits.
 *
 * [<Home>]
 * Copyright (c) 2008-2020, Waruqi All rights reserved.
 * //////////////////////////////////////////////////////////////////// */

#ifndef  EXTL_CONFIG_COMPILER_H
#	error This file must be included of config.h
#endif

#ifndef EXTL_COMPILER_IS_WATCOM
#	error This file has been erroneously included for a compiler other than Watcom C/C++ 
#endif 

/* ///////////////////////////////////////////////////////////////////////
 * Workaround
 */
#ifdef EXTL_WORKAROUND_WATCOM
#	undef EXTL_WORKAROUND_WATCOM	
#endif

#define EXTL_WORKAROUND_WATCOM(cmp, ver)	( (__WATCOMC__ != 0) && ( (__WATCOMC__) cmp (ver) ) )

/* ///////////////////////////////////////////////////////////////////////
 * Interger 
 */

/* 8-bit */
#define EXTL_8BIT_INT_SUPPORT
#define EXTL_SI08_BASE_TYPE    signed      char
#define EXTL_UI08_BASE_TYPE    unsigned    char

/* 16-bit */
#define EXTL_16BIT_INT_SUPPORT
#define EXTL_SI16_BASE_TYPE    signed      short
#define EXTL_UI16_BASE_TYPE    unsigned    short

/* 32-bit */
#define EXTL_32BIT_INT_SUPPORT
#define EXTL_SI32_BASE_TYPE    signed      int
#define EXTL_UI32_BASE_TYPE    unsigned    int

/* 64-bit */
#define EXTL_64BIT_INT_SUPPORT
#define EXTL_64BIT_INT_IS_long_long
#define EXTL_SI64_BASE_TYPE    signed      long long
#define EXTL_UI64_BASE_TYPE    unsigned    long long


/* ///////////////////////////////////////////////////////////////////////
 * Class member constants support
 */
#define EXTL_MEMBER_CONSTANT_SUPPORT

/* 64-bit Class member constants
 * e.g.
	struct type
	{
		static const e_int64_t value = 10;
	};
 */
#ifdef EXTL_MEMBER_CONSTANT_SUPPORT
#	define EXTL_MEMBER_CONSTANT_64BIT_SUPPORT 
#endif

/* ///////////////////////////////////////////////////////////////////////
 * Namespace support
 */
#if __WATCOMC__ < 1240
#	define EXTL_NO_NAMESPACE
#endif 

#define EXTL_NAMESPACE_SUPPORT

#if __WATCOMC__ >= 1270
#	define EXTL_STD_NAMESPACE 
#endif
/* ///////////////////////////////////////////////////////////////////////
 * Template support
 */
#define EXTL_TEMPLATE_SUPPORT

/* Class member template function support */
#if __WATCOMC__ >= 1270
#	define EXTL_MEMBER_TEMPLATE_FUNCTION_SUPPORT 
#endif

/* Class member template function overload discriminated support */
/* #define EXTL_MEMBER_TEMPLATE_FUNC_OVERLOAD_DISCRIMINATED_SUPPORT */

/* Class member template constructor support */
#if __WATCOMC__ >= 1270
#	define EXTL_MEMBER_TEMPLATE_CTOR_SUPPORT 
#endif

/* Class member template constructor overload discriminated support */
/* #define EXTL_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED_SUPPORT */

/* Template specialization support */
 #define EXTL_TEMPLATE_SPEC_SUPPORT 

/* Template specialization syntax support: template<> */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_SPEC_SYNTAX_SUPPORT 
#endif

/* Template partial specialization support */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_PARTIAL_SPEC_SUPPORT 
#endif

/* Template partial specialization with array type support */
/* #define EXTL_TEMPLATE_PARTIAL_SPEC_ARRAY_TYPE_SUPPORT */

/* Template partial specialization about function pointer support */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_PARTIAL_SPEC_FUNC_PTR_SUPPORT
#endif

/* Template partial specialization about member function pointer support */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_PARTIAL_SPEC_MEM_FUNC_PTR_SUPPORT 
#endif

/* Template partial specialization with function calling convention support 
 * e.g. <int (__cdecl*)()>
 */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_PARTIAL_SPEC_WITH_FUNC_CALL_CONV_SUPPORT
#endif

/* Distinguishes different function calling convention in template partial specialization support
 * CDECL, FASTCALL and STDCALL are different function calling convention
 */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_PARTIAL_SPEC_DISTINGUISH_DIFFERENT_FUNC_CALL_CONV_SUPPORT	
#endif

/* Template class default argument support */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_CLASS_DEFAULT_ARGUMENT_SUPPORT 
#endif

/* Member template class support */
#if __WATCOMC__ >= 1270
#	define EXTL_MEMBER_TEMPLATE_CLASS_SUPPORT 
#endif

/* Member template friend support */
/* #define EXTL_MEMBER_TEMPLATE_FRIEND_SUPPORT */

/* Template type required in template function argument list */
#define EXTL_TEMPLATE_TYPE_REQUIRED_IN_ARGLIST

/* Function template non-type param support eg:template <typename T, int N> */
/* #define EXTL_FUNCTION_TEMPLATE_NON_TYPE_PARAM_SUPPORT */

/* template non-type parameter dependent support
 * e.g.
 * 
	template<	int N = 1	
			,	typename T	= class1<N>	//<=
			>
 */
/* #define EXTL_TEMPLATE_NON_TYPE_DEFAULT_PARAM_DEPENDENT_SUPPORT */

/* Some compilers just generate one instantiation of function templates whose
 * template parameters don't appear in the function parameter list
 * e.g.
	template <int N>
	func1()	{ printf("%d\n", N);	}

	template <typename T>
	func2()	{ printf("%s\n", typeid(T).name());	}

	int main()
	{
		func1<1>();
		func1<2>();
		func2<int>();
		func2<double>();

 * If it is supported, the output is: 1 2 int double
 * otherwise, the output is: 2 2 double double
 */
#define EXTL_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS_SUPPORT

/* Member function as template param support */
/* #define EXTL_MEM_FUNC_AS_TEMPLATE_PARAM_SUPPORT */

/* template<typenam T, T N> support */
#if __WATCOMC__ >= 1270
#	define EXTL_TEMPLATE_TYPENAME_T_T_N_SUPPORT
#endif

/* Template template support
 * e.g.
 *
	template<typename T>
	struct class_1{};

	template<template<typename T> class class_temp = class_1 >
	struct class_2{};
 *
 */
/* #define EXTL_TEMPLATE_TEMPLATE_SUPPORT */

/* Template specialization within template classes support */
#define EXTL_TEMPLATE_SPEC_WITHIN_TEMPLATE_CLASS_SUPPORT 

/* ///////////////////////////////////////////////////////////////////////
 * Native bool support
 */
#ifdef __cplusplus
#	define EXTL_NATIVE_BOOL_SUPPORT
#endif 

/* ///////////////////////////////////////////////////////////////////////
 * wchar_t support
 */
#if __WATCOMC__ >= 1200
#	define EXTL_NATIVE_WCHAR_T_SUPPORT
#endif 

/* ///////////////////////////////////////////////////////////////////////
 * Current function name
 */
#define EXTL_CURRENT_FUNCTION	"Unknown Function"

/* ///////////////////////////////////////////////////////////////////////
 * Static array size determination support
 */
/* #define EXTL_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * #pragma message support
 */
#define EXTL_PRAGMA_MESSAGE_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * #pragma once support
 */
#if __WATCOMC__ >= 1200
#	define EXTL_PRAGMA_ONCE_SUPPORT
#endif

/* ///////////////////////////////////////////////////////////////////////
 * Member constant initialization support
 */
/* #define EXTL_MEMBER_CONST_INIT_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Inline assembly support
 */
#define EXTL_INLINE_ASM_SUPPORT

/* inline assembly is supported in static function */
/* #define EXTL_INLINE_ASM_IN_INLINE_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Inline support
 */
#define EXTL_C99_INLINE

/* ///////////////////////////////////////////////////////////////////////
 * cv-qualified void specialization support
 */
#define EXTL_CV_VOID_SPEC_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * cv-qualified specialization support
 */
#define EXTL_CV_SPEC_SUPPORT 

/* ///////////////////////////////////////////////////////////////////////
 * Call convention support
 */
#define EXTL_CDECL_SUPPORT
#define EXTL_STDCALL_SUPPORT

#ifdef EXTL_CDECL_SUPPORT
#	define EXTL_CDECL				__cdecl
#endif 
#ifdef EXTL_STDCALL_SUPPORT
#	define EXTL_STDCALL				__stdcall
#endif

/* ///////////////////////////////////////////////////////////////////////
 * Ellipsis in function testing support 
 * eg: void func(...);
 */
#define	EXTL_ELLIPSIS_IN_FUNC_TESTING_SUPPORT	

/* ///////////////////////////////////////////////////////////////////////
 * Ellipsis in template partial specializtion about function testing support 
 * eg: template <typename T> struct type<void (*)(...)>
 */
#define EXTL_ELLIPSIS_IN_TEMPLATE_PARTIAL_SPEC_FUNC_TESTING_SUPPORT	

/* ///////////////////////////////////////////////////////////////////////
 * Keywords support 
 */

/* typename eg: template < typename T > or template < class T > */
#if __WATCOMC__ >= 1270
#	define EXTL_TYPENAME_PARAM_KEYWORD_SUPPORT 
#endif

/* typename typename eg: typedef typename template_class<T>::type type; */
#if __WATCOMC__ >= 1270
#	define EXTL_TYPENAME_TYPE_KEYWORD_SUPPORT 
#endif

/* typename eg: template< class A = typename template_class<T>::type > */
/* #define EXTL_TYPENAME_TYPE_DEF_KEYWORD_SUPPORT */

/* typename qualifier in constructor initialiser lists */
/* #define EXTL_TYPENAME_TYPE_MIL_KEYWORD_SUPPORT */

/* typename eg: typename template_class<T>::type func(); */
/* #define EXTL_TYPENAME_TYPE_RET_KEYWORD_SUPPORT */

/* template eg: typedef A::template a<T>::type type; */
/* #define EXTL_TEMPLATE_QUAL_KEYWORD_SUPPORT */

/* mutable */
#define EXTL_MUTABLE_KEYWORD_SUPPORT

/* explicit */
#define EXTL_EXPLICIT_KEYWORD_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * Exception support
 */
#if defined(_CPPUNWIND) || \
		defined(__CPPUNWIND)
#	define EXTL_EXCEPTION_SUPPORT
#endif

/* Exception signature support (eg: void func() throw(e1, e2, ...);) */
#ifdef __CPPUNWIND
#	define EXTL_EXCEPTION_SIGNATURE_SUPPORT
#endif

/* throw std::bad_alloc() support */
/* #define EXTL_THROW_BAD_ALLOC_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Return void support 
 * eg: return (void)0;
 */
/* #define EXTL_RETURN_VOID_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Member pointer as bool return support 
 * eg: int (class_type::*) func(){return &class_type::member;}
 * if(func()){...};
 *
 * Note: if(p1 && p2) can not be compiles sucessfully
 */

/* #define EXTL_MEM_PTR_AS_BOOL_RET_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * 64-bit interger format output support 
 * eg: printf("%I64d", ...);
 */

#define EXTL_PRINTF_I64_FORMAT_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * Named return value optimization support 
 */
/* #define EXTL_NRVO_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Property support (no test)
 * Note: Compiler extensibity
 */
/*#define EXTL_PROPERTY_SUPPORT*/
#define EXTL_PROPERTY_GET(type, property_name, method)								
#define EXTL_PROPERTY_SET(type, property_name, method)								
#define EXTL_PROPERTY_GETSET(type, property_name, get_method, set_method)		

/* ///////////////////////////////////////////////////////////////////////
 * CRTP support 
 * eg: class derived_class : public base_class< derived_class > {};
 */
#define EXTL_CRTP_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * EBO(empty base optimization) support 
 */

/* EBO1:
 * empty_child - empty_base
 */
#define EXTL_EBO_FORM_1_SUPPORT

/* EBO2:
 * non_empty_child - empty_base
 */
#define EXTL_EBO_FORM_2_SUPPORT

/* EBO3:
 * empty_child - empty_base2 - empty_base1
 */
#define EXTL_EBO_FORM_3_SUPPORT

/* EBO4:
 * non_empty_child - empty_base2 - empty_base1
 */
#define EXTL_EBO_FORM_4_SUPPORT

/* EBO5:
 *						empty_base1
 *					/	
 * empty_child	-
 *					\
 *						empty_base2
 */
#define EXTL_EBO_FORM_5_SUPPORT

/* EBO6:
 *							empty_base1
 *						/	
 * non_empty_child	-
 *						\
 *							empty_base2
 */
/*#define EXTL_EBO_FORM_6_SUPPORT*/

/* EBO7:
 *						empty_base1
 *					/	
 * empty_child	-
 *					\
 *						non_empty_base2
 */
#define EXTL_EBO_FORM_7_SUPPORT


/* ///////////////////////////////////////////////////////////////////////
 * EDO(empty derived optimization) support 
 */

/* EDO1:
 * empty_child - empty_base
 */
#define EXTL_EDO_FORM_1_SUPPORT

/* EDO2:
 * empty_child_template - empty_base
 */
#define EXTL_EDO_FORM_2_SUPPORT

/* EDO3:
 * empty_child - non_empty_base
 */
#define EXTL_EDO_FORM_3_SUPPORT

/* EDO4:
 * empty_child_template - non_empty_base
 */
#define EXTL_EDO_FORM_4_SUPPORT

/* EDO5:
 *						empty_base1
 *					/	
 * empty_child	-
 *					\
 *						empty_base2
 */
#define EXTL_EDO_FORM_5_SUPPORT

/* EDO6:
 *								empty_base1
 *							/	
 * empty_child_template	-
 *							\
 *								empty_base2
 */
#define EXTL_EDO_FORM_6_SUPPORT

/* EDO7:
 *						empty_base1
 *					/	
 * empty_child	-
 *					\
 *						non_empty_base2
 */
#define EXTL_EDO_FORM_7_SUPPORT

/* EDO8:
 *								empty_base1
 *							/	
 * empty_child_template	-
 *							\
 *								non_empty_base2
 */
#define EXTL_EDO_FORM_8_SUPPORT

/* ///////////////////////////////////////////////////////////////////////
 * c++0x support 
 */

/* Rvalue references support */
/* #define EXTL_0x_RVALUE_REFERENCE_SUPPORT */

/* Variadic templates support */
/* #define EXTL_0x_VARIADIC_TEMPLATE_SUPPORT */

/* Static assertions support */
/* #define EXTL_0x_STATIC_ASSERT_SUPPORT */

/* Right angle brackets support 
 * e.g. vector<vector<int>> will be compiled sucessfully
 */
/* #define EXTL_0x_RIGHT_ANGLE_BRACKET_SUPPORT */

/* Inline namespaces support
 * e.g. inline namespace{}
 */
/* #define EXTL_0x_INLINE_NAMESPACE_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * type alias friend support 
 * e.g.
 * typedef class_type<T>	friend_type;
 * friend					friend_type;
 */
/* #define EXTL_TYPE_ALIAS_FRIEND_SUPPORT */

/* ///////////////////////////////////////////////////////////////////////
 * Suppress warning 
 */

/* do{} while(0) : expression for 'while' is always false . */
#pragma warning	555	10

/* conditional expression in if statement is always true */
#pragma warning	367	10

/* conditional expression in if statement is always false */
#pragma warning	368	10

/* conditional expression is always true (non-zero)  */
#pragma warning	689	10

/* conditional expression is always false (zero)  */
#pragma warning	690	10

/* unreachable code */
#pragma warning	13	10

/* 'sizeof' operand contains compiler generated information 
 * from file: "extl\counter\shared_counter.h" - sizeof(shared_info_type)
 */
#pragma warning	549	10

/* integral value may be truncated during assignment or initialization 
 * for std/algorithm.h - std_distance()
 */
#pragma warning	389	10
