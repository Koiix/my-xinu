#include <xinu.h>
#define LS_USAGE
"Usage: ls [flags] [path] \
\n\nDescription: \
\n\tDisplays contents of directory pointed to by path.\
If no path is specified, then the current working directory \
is used to display contents.\
\n\nflags: \
\n\t-a\t\tinclude directory entries whose names begin with a dot (.) \
\n\t-l\t\tlist in long format "

shellcmd ls(int32 nargs, char * args[]){

  struct lfdir * dir;
  struct dentry * file;
  int32 i, j;
  int32 cols, spac, lines;
  int32 nfiles = dir->lfd_nfiles;

/* Calculate the number of command names per line */

  cols = 80/(LF_NAME_LEN+1);
	if (cols > 6) {
		cols = 6;
	}

  /* Calculate the width of a column */

	spac = 80/cols;

	/* Calculate the number of lines of output */

	lines = (nfiles+(cols-1))/cols;



  for (i=0; i<lines; i++) {
    for (j=i; j< nfiles; j+=lines) {
      struct dentry * file = dir->lfd_files[j];
      len = strnlen(file->ld_name,80);
      printf("%s", file->ld_name);
      while (len < spac) {
        printf(" ");
        len++;
      }
    }
    printf("\n");
  }

}
