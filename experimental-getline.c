#include <stdio.h>

#define LIM 1000

int getLine(char s[], int limit);
void squeeze(char s[], int c);

int main() {
  char s[LIM];
  int len, c;

  while ((len = getLine(s, LIM)) > 0) {
    printf("%s", s);
    squeeze(s, 'f');
    printf("Squeezed 'f'\t: %s\n\n", s);
  }
}


/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i ) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
  int i, j;

  for (i=j=0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';
}
