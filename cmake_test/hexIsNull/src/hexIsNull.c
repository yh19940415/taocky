#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int ms_ctoi(char c)
{
  if ('0' <= c && c <= '9') return c - '0';
  if ('A' <= c && c <= 'F') return 0xa + c - 'A';
  if ('a' <= c && c <= 'f') return 0xa + c - 'a';

  return 0;
}

static int ms_hex2bin(const char *h, uint8_t *b, int len)
{
  int n = 0;
  uint8_t item;
  while (*h && n < len) {
    printf("h[0]%c h[1]:%c\n", h[0], h[1]);
    printf("h[0]%d h[1]:%d\n", ms_ctoi(h[0]), ms_ctoi(h[1]));
    item = (ms_ctoi(h[0])  << 4) + ms_ctoi(h[1]);
    b[n++] = item;
    printf("item:%d\n", item);
    printf("%d:%u %u\n", n, b[n-1], b[n]);
    if (!h[1]) break;
    h += 2;
  }

  return n;
}

int main(int argc, char **argv)
{
  uint8_t buf[1024];


  memset(buf, '0', 1024);

  int len = ms_hex2bin("1A1B1C1", buf, 1024);
/*
  uint8_t i = 0;
  uint8_t *p = NULL;
  p = &i;
  for (i = 0; i < 512; i++) {
    printf("!p[0] %d\n", !p[0]);
  }
*/
  printf("hexIsNull test over\n");
}
