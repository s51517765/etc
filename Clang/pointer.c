#include <stdio.h>
#include <cstring> //strcpy,memcpyなど

struct person
{
  char name[4];
  int age;
  int no;
};

int main(void)
{
  struct person taro;
  // char 型の配列へはstrcpyを使う
  strcpy(taro.name, "taro");

  printf("name= %s\n", taro.name); // taro
  printf("age= %d\n", taro.age);   // 10
  printf("-Char\n");
  printf("      0x - 0d   - char - Address\n");
  printf("name= %02x - %04d - %c    - %08d\n", *taro.name, *taro.name, *taro.name, &taro.name);          // t
  printf("name= %02x - %04d - %c    - %08d\n", taro.name[0], taro.name[0], taro.name[0], &taro.name[0]); // t
  printf("name= %02x - %04d - %c    - %08d\n", taro.name[1], taro.name[1], taro.name[1], &taro.name[1]); // a
  printf("name= %02x - %04d - %c    - %08d\n", taro.name[2], taro.name[2], taro.name[2], &taro.name[2]); // r
  printf("name= %02x - %04d - %c    - %08d\n", taro.name[3], taro.name[3], taro.name[3], &taro.name[3]); // o

  struct person jiro;
  strcpy(jiro.name, "jiro");
  char *ptr2 = jiro.name;
  printf("-jiro\n");
  printf("name= %c\n", *(ptr2)++);
  printf("name= %c\n", *ptr2++);
  printf("name= %c\n", *ptr2++);
  printf("name= %c\n", *(ptr2)++);
  printf("name= %c\n", *ptr2);
  // 0 代入無し
  // char *ptr2 = taro.name;
  //  以下のような使い方はできない
  //  ポインタで要素indexでアクセス
  //  printf("name= %d\n", *taro.name[0]);

  // 再代入
  // *ptr = taro.name;
  // ptr2[0] = ptr1[0];
  // 文字列の代入はstrcpy、memcopyなど
  // char *ptr2 = "asdf";  Error

  struct person hana;
  strcpy(hana.name, "hana");
  // https://marycore.jp/prog/c-lang/string-strcpy-strncpy/
  // strcpyにはstrncpy、strlcpyなど似たものがあるが微妙に違う。ときに重大なBugにつながるので注意が必要な場合がある
  hana.age = 4;
  hana.no = 1;
  // ポインタ変数への代入はアドレスを使う
  struct person *ptr3 = &hana;
  struct person *ptr12;
  // ptr2に上書き
  printf("-over write\n");
  memcpy(ptr2, ptr3, sizeof(ptr3));

  printf("name= %d\n", sizeof(ptr3));
  printf("-string\n");
  printf("name= %c\n", *ptr2++);                        // h
  printf("name= %c\n", *ptr2++);                        // a
  printf("name= %c\n", *ptr2++);                        // n
  printf("name= %c\n", *ptr2++);                        // a
  printf("ptr2 size= %d\n", sizeof(ptr2));              // 8 構造体としては12byteだが、ポインタのサイズとして8が出力される(64bitの場合)
  printf("ptr3 size= %d\n", sizeof(ptr3));              // 8
  printf("hana size= %d\n", sizeof(hana));              // 12 構造体のサイズ
  printf("ptr2 address= %d\n", &ptr2);                  // 6421952
  printf("ptr2 address= %d\n", (struct person *)&ptr2); // 6421952
  char src[] = "mori";
  char dst[10];
  strcpy(dst, src);
  printf("dst= ");
  for (int i = 0; i < sizeof(src); i++)
    printf("%c ", dst[i]); // m o r i
                           // strcpyとmemcopyではコピーする長さの指定が違い、memcpyでは長さ指定、strcpyはヌル文字'\0'まで（通常は最後までだが途中に'\0'を含んでいたらそこまでしかコピーされない。）。
                           // そのためstrcpyでは'\0'までコピーするので最後は必ず'\0'。
  printf("\n");
  struct person miki;
  strcpy(miki.name, "miki");
  miki.age = 21;
  miki.no = 0x1234;
  // 構造体の全要素の文字コードを出力する
  char *ptr4 = (char *)&miki;
  for (int i = 0; i < sizeof(ptr4); i++)
  {
    printf("%d ", ptr4[i]);
  }

  printf("\n-sabu\n");
  struct person sabu;
  strcpy(sabu.name, "sabu");
  sabu.age = 54;
  sabu.no = 0x12345678;
  // 構造体の全要素の文字コードを出力する
  unsigned char *ptr5 = (unsigned char *)&sabu;
  printf("0x - 0d  - char\n");
  for (int i = 0; i < sizeof(sabu); i++)
  {
    printf("%02X - %03d - %c\n", ptr5[i], ptr5[i], ptr5[i]);
  }

  /*
  -sabu
  0x - 0d  - char
  73 - 115 - s
  61 - 097 - a
  62 - 098 - b
  75 - 117 - u
  36 - 054 - 6
  00 - 000 -
  00 - 000 -
  00 - 000 -
  78 - 120 - x
  56 - 086 - V
  34 - 052 - 4
  12 - 018 - 
  */

  printf("\n-shiro\n");
  typedef struct
  {
    char name[8];
    int age;
    char address[5];
    int no;
  } man;

  man shiro;
  strcpy(shiro.name, "shiro");
  shiro.age = 54;
  strcpy(shiro.address, "tokyo");
  shiro.no = 0x12345678;

  // 構造体の全要素の文字コードを出力する
  unsigned char *ptr6 = (unsigned char *)&shiro;
  printf("0x - 0d  - char\n");
  for (int i = 0; i < sizeof(shiro); i++)
  {
    printf("%02X - %03d - %c\n", ptr6[i], ptr6[i], ptr6[i]);
  }
  /*
  0x - 0d  - char
73 - 115 - s
68 - 104 - h
69 - 105 - i
72 - 114 - r
6F - 111 - o
00 - 000 -
00 - 000 -
00 - 000 -
36 - 054 - 6
00 - 000 -
00 - 000 -
00 - 000 -
74 - 116 - t
6F - 111 - o
6B - 107 - k
79 - 121 - y
6F - 111 - o
00 - 000 -
40 - 064 - @
00 - 000 -
78 - 120 - x
56 - 086 - V
34 - 052 - 4
12 - 018 - 
  */

  printf("-array1\n");
  int arr1[] = {11, 22, 33, 44, 0x123456, 0x1234};
  printf("0x - 0d  \n");
  for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
  {
    printf("%08X - %08d \n", arr1[i], arr1[i]);
  }
  /*
  -array1
0x - 0d
0000000B - 00000011
00000016 - 00000022
00000021 - 00000033
0000002C - 00000044
00123456 - 01193046
00001234 - 00004660
  */

  printf("-array2\n");
  int arr2[] = {1, 2, 3, 4, 0x123456, 0x7890};
  unsigned char *ptr0 = (unsigned char *)arr2;

  for (int i = 0; i < sizeof(arr2); i++)
  {
    printf("%02x ", *(ptr0 + i));
    if (i % 4 == 3)
      printf("\n");
  }
  /*
01 00 00 00
02 00 00 00
03 00 00 00
04 00 00 00
56 34 12 00
90 78 00 00
  */
}