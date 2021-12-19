#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char* first(char* str)
{
   int len = strlen(str);
   char* temp = malloc((len + 1) * sizeof(char));
   int f = 0;
   int l = 0;
   int flag = 0;
   int d = 0;

   for (int i = 0; i < strlen(str); i++)
   {
      if (flag == 0 && str[i] == ' ')
      {
         f = i;
         flag = 1;
      }
      if (str[i] == ' ')
         l = i;
   }
   for (int i = l + 1; i < strlen(str); i++) {
      temp[d] = str[i];
      d++;
   }
   temp[d] = ' ';
   d++;
   for (int i = f + 1; i < l; i++)
   {
      temp[d] = str[i];
      d++;
   }
   temp[d] = ' ';
   d++;
   for (int i = 0; i < f; i++)
   {
      temp[d] = str[i];
      d++;
   }
   temp[d] = '\0';
   str = temp;

   return str;
}

void Third()
{
   FILE* F = NULL;
   FILE* G = NULL;

   errno_t err;
   err = fopen_s(&F, "f.txt", "r");
   if (err)
   {
      perror("f.txt opening error");
      return;
   }
   if (F == NULL)
   {
      perror("f.txt opening error");
      return;
   }
   err = fopen_s(&G, "g.txt", "w");
   if (err)
   {
      perror("g.txt opening error");
      return;
   }
   if (G == NULL)
   {
      perror("g.txt opening error");
      return;
   }
   int t = 1;

   for (char sym; fscanf_s(F, "%c", &sym,4) != EOF;)
   {
      if (sym == ' ')
         ++t;
      if (sym == 'Ï' || sym == 'ï' || t % 4 == 0)
      {
         while (sym != ' ')
            fscanf_s(F, "%c", &sym,4);
      }
      else
         fprintf_s(G, "%c", sym);
   }
}
