#include <stdio.h>
#include <conio.h>
#include <string.h>

#define ID3_MAX_SIZE 128

typedef struct IDv3Tag
{
    char signature[3];
    char name[30];
    char artist[30];
    char album[30];
    char year[4];
    char description[30];
    unsigned short ganre;
} ID3TAG;

long idv3_file_offset(FILE* fp)
{
    fseek(fp, 0L, SEEK_END);
    return ftell(fp) - ID3_MAX_SIZE;
}

int main()
{
    FILE* fp = NULL;
    const char* filename = "bangosteve_feat_el_perforator_one.mp3";
    if ((fp = fopen(filename,"r")) == NULL)
        printf("Unable to open file %s for reading\n", filename);

    char* buf = new char[ID3_MAX_SIZE];
    memset((void*)buf, 0x00, ID3_MAX_SIZE);

    fseek(fp, idv3_file_offset(fp), SEEK_SET);
    fread(buf, 1, ID3_MAX_SIZE, fp);

    ID3TAG* pId3Tag = NULL;
    if ((pId3Tag = reinterpret_cast<ID3TAG*>(buf)) != NULL)
    {
        printf("NAME %s\n",pId3Tag->name);
        printf("CHEY ALBOM BLYAT\n",pId3Tag->artist);
        printf("ALBOM NAME\n",pId3Tag->album);
        printf("YEAR%s\n",pId3Tag->year);
        printf("DESCTIPRION%s\n",pId3Tag->description);
        printf("GANRE%d\n",pId3Tag->ganre);
    }
    fclose(fp);
    return 0;
}