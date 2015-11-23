//=======================================================================================
//!	@file	:	TypeTraits.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/11/24
//! @brief	:	Implement TypeTraits Template
//=======================================================================================
#pragma once

namespace Chocolat
{
namespace Generics
{

template<class Base, class Derived>
class IsBaseOfHelper
{
public:
	operator Base*() const;
	operator Derived*();
};

template<class Base, class Derived>
class IsBaseOf
{
private:
	template<class T>
	static char check(Derived*, T);
	static int  check(Base*, int);

public:
	static const bool value = sizeof(check(IsBaseOfHelper<Base, Derived>(), int())) == sizeof(char);
};

template<class Base, class Derived>
class IsBaseOf < Base, const Derived >
{
private:
	template<class T>
	static char check(Derived*, T);
	static int  check(Base*, int);

public:
	static const bool value = sizeof(check(IsBaseOfHelper<Base, Derived>(), int())) == sizeof(char);
};

template<class Base, class Derived>
class IsBaseOf < Base&, Derived& >
{
public:
	static const bool value = false;
};

template<class Type>
class IsBaseOf < Type, Type >
{
public:
	static const bool value = true;
};

template<class Type>
class IsBaseOf < Type, const Type >
{
public:
	static const bool value = true;
};

template<bool B, typename T = void>
struct enable {};

template<typename T>
struct enable < true, T > { typedef T Type; };

template<bool B, typename T>
struct disable : public enable < !B, T > { };

}
}