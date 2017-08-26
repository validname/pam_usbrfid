all:
	gcc -fPIC -DPIC -shared -rdynamic -o pam_usbrfid.so pam_usbrfid.c

