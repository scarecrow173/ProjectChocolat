//=======================================================================================
//!	@file	:	Vector2.h
//!	@author	:	è¨éR âlå\
//!	@date	:	2014/12/30
//! @brief	:	Vector2 2é≤ÉxÉNÉgÉã
//=======================================================================================
#ifndef __CHOCOLAT_MATH_VECTOR2__
#define __CHOCOLAT_MATH_VECTOR2__

#include "Core.h"

namespace Chocolat
{
namespace Math
{
	class Vector2
	{
	public:
		static const Vector2 Zero;

		Vector2();
		virtual ~Vector2();

		Vector2&	Normalize();
		Vector2		Normalize() const;
		
		Core::F32		Distance(const Vector2& v) const;
		Core::F32		DistanceSquared(const Vector2& v) const;
		Core::F32		Dot(const Vector2& v) const;
		Core::F32		Length(const Vector2& v) const;
		Core::F32		DistanceSquared(const Vector2& v) const;


		Vector2&		operator =	(const Vector2&		v);
		Vector2&		operator +=	(const Vector2&		v);
		Vector2&		operator -=	(const Vector2&		v);
		Vector2&		operator *=	(const Vector2&		v);
		Vector2&		operator *=	(const Core::F32	v);
		Vector2&		operator /=	(const Vector2&		v);
		Vector2&		operator /=	(const Core::F32	v);

	private:

	};
}
}
#endif
//===============================================================
//	End of File
//===============================================================