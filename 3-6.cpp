#define abs(x) ((x) < 0 ? -(x):(x))

/*itoa:convert n to charcters in s,w characters wide */

void itoa(int n, char s[], int w) {
	int i, sign;
	void reverse(char s[]);

	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	while (i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}