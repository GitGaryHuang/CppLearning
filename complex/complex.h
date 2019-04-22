#include<iostream> //2019/4/1
#pragma once
#ifndef __COMPLEX__
#define __COMPLEX__

class complex;
complex& __doapl (complex* ths, const complex& r);
complex& __doami (complex* ths, const complex& r);
complex& __doaml (complex* ths, const complex& r);

class complex
{
public:
	complex (double r = 0, double i = 0): re (r), im (i) {};//构造函数 考虑初值 传值方式
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real () const { return re; }//inline function
	double imag () const { return im; }
private:
	double re, im;

	friend complex& __doapl(complex*, const complex&);
	friend complex& __doami(complex*, const complex& r);
	friend complex& __doaml(complex*, const complex& r);

};

inline complex& 
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

inline complex&
__doami(complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}

inline complex&
complex::operator -= (const complex& r)
{
	return __doami(this, r);
}

inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;
	return *ths;	
}

inline complex&
complex::operator *= (const complex& r)
{
	return __doaml(this, r);
}


inline complex //存在局部变量 不可传引用
operator + (const complex& x, const complex& y)
{
	return complex (x.real() + y.real(), x.imag() + y.imag());
}

inline complex 
operator + (const complex& x, double y)
{
	return complex(x.real() + y, x.imag());
}

inline complex
operator + (double x, const complex& y)
{
	return complex(x + y.real(), y.imag());
}

inline complex 
operator - (const complex& x, const complex& y)
{
	return complex(x.real() - y.real(), x.imag() - y.imag());
}

inline complex
operator - (const complex& x, double y)
{
	return complex(x.real() - y, x.imag());
}

inline complex
operator - (double x, const complex& y)
{
	return complex(x - y.real(), y.imag());
}

inline complex 
operator * (const complex& x, const complex& y)
{
	return complex(x.real() * y.real() - x.imag() * y.imag(), x.imag() * y.imag() + y.real() * x.imag());
}

inline complex
operator * (const complex& x, double y)
{
	return complex(x.real() * y, x.imag() * y);
}

inline complex
operator * (double x, const complex& y)
{
	return complex(x * y.real(), x * y.imag());
}

inline complex
operator / (const complex& x, double y)
{
	return complex(x.real() / y, x.imag() / y);
}

inline double
imag (const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}

inline complex
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x)
{
	return complex( -x.real(), -x.imag());
}

inline bool
operator == (const complex& x, const complex& y)
{
	return x.real() == y.real() && x.imag() == y.imag();
}

inline bool
operator == (const complex& x, double y)
{
	return x.real() == y && x.imag() == 0;
}

inline bool
operator == (double x, const complex& y)
{
	return y.real() == x && y.imag() == 0;
}

inline bool
operator != (const complex& x, const complex& y)
{
	return x.real() != y.real() || x.imag() != y.imag();
}

inline bool
operator != (const complex& x, double y)
{
	return x.real() != y || x.imag() != 0;
}

inline bool
operator != (double x, const complex& y)
{
	return y.real() != x || y.imag() != 0;
}

#include <cmath>

inline complex
polar(double r, double t)
{
	return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex& x)
{
	return complex(real(x), -imag(x));
}

inline double
norm(const complex& x)
{
	return real(x) * real(x) + imag(x) * imag(x);
}
#endif // !__COMPLEX__

