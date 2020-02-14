Author: Vikram Gardella

Contents:

	kstring.c: implementation of kstring functions
	kstring.h: declaration of kstring functions
	Makefile: for compiling and linking files
	README.txt: documentation

Running: Run test-full or test-abbrev

Implementation Notes: Made functions for converting size_t to int and int to size_t

Limitations: Minute memory leakage of approximately 23 bytes. Test 5/26 when running test-full is skipped.

References: The design of kstralloc benefitted from discussions with my friend Thomas Underwood.
