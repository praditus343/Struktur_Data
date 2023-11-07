#include <stdio.h>
#include <string.h>

main()
{
    int hitung;
    char kata[100];

    printf("masukkan kata yang ingin dibalik : ");
    scanf("%s", &kata);
    hitung=strlen(kata);
    printf("kata setelah dibalik : \n");
    for(hitung-1;hitung>0;hitung--)
    {
    printf("%c", kata[hitung-1]);
    }
    printf("\n");

    return 0;
}
