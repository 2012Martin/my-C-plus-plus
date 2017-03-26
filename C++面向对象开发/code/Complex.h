#ifndef __COMPLEX__
#define __COMPLEX__

//ǰ������----------------------------------------------------------
class Complex;

Complex& __doapl(Complex* ths, const Complex& r);

//������------------------------------------------------------------
class Complex
{
public:
	Complex(double r=0, double i=0)
		: re(r), im(i)//��ֵ��
	{
	}

	inline double getReal() const {return re;}//inline������const
	inline double getImag() const {return im;}

	Complex& operator += (const Complex& r);//����Ϊ����-->֧�����Ӳ���
	
private:
	double re;
	double im;

	friend Complex& __doapl(Complex* ths, const Complex& r);//friends-->����Ϳ���ֱ��ȡ˽�еĳ�Ա����

};


//�ඨ��------------------------------------------------------------
inline Complex& 
Complex::operator +=(const Complex& r)
{
	return __doapl(this,  r);
}

//------------------------------------------------------------------------------------
//������ȫ�ֺ���
inline Complex&
__doapl(Complex* ths, const Complex& r)//�˺���ΪComplex��friends�����Զ������ֱ��ȡ˽������
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

//�� �����
inline Complex 
operator + (const Complex& x, const Complex& y)
{
	return Complex(x.getReal() + y.getReal(), x.getImag() + y.getImag());
}

//ȡ�� �����
inline Complex
operator + (const Complex& x)
{
	return x;
}

//ȡ�� �����
inline Complex
operator - (const Complex& x)
{
	return Complex(-x.getReal(), -x.getImag());
}

//��� �����
inline bool
operator == (const Complex x, const Complex y)
{
	if (x.getReal() == y.getReal() && x.getImag() == y.getImag())
		return true;
	else
		return false;
}

//����� �����
inline bool
operator != (const Complex x, const Complex y)
{
	if (x.getReal() != y.getReal() || x.getImag() != y.getImag())
		return true;
	else
		return false;
}

//<< �����
#include <IOSTREAM.H>
inline ostream&//û�з���void���ǿ��ǵ�cout << c1 << conj(c1);�����÷������ܼ�const
operator << (ostream& os, Complex& r)//�˴���һ���������ܼ�const
{
	return cout << '(' << r.getReal() << ',' << r.getImag() << ')' << endl;
}


#endif