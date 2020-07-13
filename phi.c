#include <stdio.h>
#include <stdlib.h>

unsigned long long n;
unsigned __int128 phi;

unsigned long long factorize(unsigned long long **arr, unsigned long long value)
{
	unsigned long long ret = 0;
	*arr=NULL;
	phi = 1;
	while (value > 1)
	{
		for (unsigned long long i = 2; i <= value; ++i)
		{
			if (value % i == 0)
			{
				value /= i;
				char present = 0;
				for (int k = 0; k < ret && present == 0; ++k)
				{
					if ((*arr)[k]==i)
					{
						present = 1;
					}
				}
				if (present == 0)
				{
					*arr=(unsigned long long*)realloc(*arr,(++ret)*sizeof(unsigned long long));
					(*arr)[ret-1]=i;
					phi *= i-1;
				}
				break;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	n = strtoull(argv[1],argv+2, 10);
	unsigned long long *a;
	unsigned long long len;
	unsigned long long **factors=&a;
	len=factorize(factors, n);
	phi *= n;
	for (unsigned long long i = 0; i < len; ++i)
	{
		unsigned long long val = (*factors)[i];
		phi /= val;
	}
	printf ("%llu\n", (unsigned long long)phi);
	return 0;
}
