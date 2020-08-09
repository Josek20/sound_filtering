#include<stdio.h>
#include<math.h>
#include<stdlib.h>


struct wave_header{
	//Header
	char chunkID[4]; 
	int chunkSize;
	char format[4];
	//fmt 
	char subChank1ID[4];
	int subchunk1Size;
    	short int audioFormat;
    	short int numChannels;
    	int sampleRate;
    	int byteRate;
    	short int blockAlign;
   	short int bitsPerSample;
    	short int extraParamSize;
    	char subchunk2ID[4];
    	int subchunk2Size;
};
struct wave_data{
	char subchunk2ID[4];
	int subchunk2Size;
};

struct wave_data *data;
struct wave_header *header;


//int freq = 100;
//int ampl = 20;
//void read(FILE *fp,int buff
int main(int argc,char *argv[]){
	FILE *fp;
	//char *buff;
	header = malloc(sizeof(struct wave_header));
	
	fp = fopen(argv[argc-1],"rb");
	if(fp==NULL){
		printf("Cannot open file\n");
		exit(1);
	}

	//Reading header 
	fread(header,1,sizeof(header),fp);
	fread(data,1,sizeof(data),fp);
	//char buff[dara->subchank2Size];	
	//Reading data
	int buff[header->numChannels][data->subchunk2Size];
	while(!feof(fp)){
		/*if(header->bitsPerSample == 8){
			
		}
		if(header->bitsPerSample == 16){
		
		}
		if(header->bitsPerSample == 32){
			
		}*/
	}

	printf("%s\n",header->chunkID);
	printf("%d\n",header->chunkSize);
	printf("%s\n",header->format);	
	
	fclose(fp);
	printf("%d,%s",argc,*argv);	
	return 0;
}
