#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int	main(void)
{
	int	square;

	square = 13;
	printf("square root of %d = %f\n", square, sqrt((double)square));
	return (0);
}
