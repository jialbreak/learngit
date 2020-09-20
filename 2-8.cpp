/*rightrot:rotate x to the right by n position*/
unsigned rightrot(unsigned x, int n) {
	int wordlength(void);
	int rbit;

	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;
		x = x | rbit;

	}
	return x;
}