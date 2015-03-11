#include <stdio.h>
#include <ctype.h>

int total_bytes=0;
int total_word=0;
int total_lines=0;

void wc(FILE *ofile, FILE *ifile, char *inname) {
	int bytes=0;
	int word=0;
	int lines=0;
	int inword=0;
	int buf;
	while( (buf=fgetc(ifile))!= EOF ){
		bytes++;
		total_bytes++;
		if(buf=='\n'){
			lines++;
			total_lines++;
		}
		if(isspace(buf)&&inword){
			word++;
			total_word++;
			inword=0;
		}
		if( !isspace(buf) ) inword=1;
	}

	fprintf(ofile, " %d %d %d %s\n",lines, word, bytes, inname);
}

int main (int argc, char *argv[]) {
	FILE* ofile = stdout;
	FILE* ifile = stdin;
	

	
	for(int i=1;i<argc;i++){
		char* name=argv[i];
		ifile = fopen(argv[i],"r");
		wc(ofile, ifile, name);
		fclose(ifile);
	}
	fprintf(ofile, " %d %d %d total\n",total_lines, total_word, total_bytes);
	
	fclose(ofile);
	return 0;
}
