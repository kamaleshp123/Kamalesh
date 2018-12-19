#include<stdio.h>
struct typeU
{
      int id;
          int name_len;

          struct  
                    {
                              char _16[16];
                                      char _32[32];
                                          } name;

                  int value1;
                      int value2;
                          int value3;
                              int value4;
};

void typeU_print(struct typeU *t)
{
      printf("%i\n", t->id);

          switch (t->name_len)
                {
                          case 16:
                                        printf("%s\n", t->name._16);
                                                break;

                                                        case 32:
                                                            printf("%s\n", t->name._32);
                                                                    break;
                                                                        }

              printf("%i\n", t->value1);
                  printf("%i\n", t->value2);
                      printf("%i\n", t->value3);
                          printf("%i\n", t->value4);
}


main()
{
  struct typeU st;
  st.id=500;
  st.name_len=32;
  st.value1=100;
  st.value2=200;
  strcpy(st.name._16,"kamalesh");
  strcpy(st.name._32,"patil*********************");
  st.value3=300;
  st.value4=400;
typeU_print(&st);
}
