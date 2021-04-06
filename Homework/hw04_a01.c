#include <stdio.h>

typedef struct
{
	double real;
	double imag;
} Complex;

Complex addComplex(Complex A, Complex B)
{
	Complex add;
	add.real = A.real + B.real;
	add.imag = A.imag + B.imag;

	return add;
}

Complex minusComplex(Complex A, Complex B)
{
	Complex temp;
	temp.real = A.real - B.real;
	temp.imag = A.imag - B.imag;

	return temp;
}

void printComplex(Complex C)
{
	printf("%4.1f + %4.1fi\n", C.real, C.imag);
}

int main()
{
	Complex a = { 10.1,7.9 };
	Complex b = { -5.4,7.3 };
	Complex result;

	result = addComplex(a, b);
	printComplex(result);
	result = minusComplex(a, b);
	printComplex(result);
}
