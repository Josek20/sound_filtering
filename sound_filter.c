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
	header = malloc(sizeof(struct wave_header));
	data = malloc(sizeof(struct wave_data));	
	fp = fopen(argv[argc-1],"rb");
	if(fp==NULL){
		printf("Cannot open file\n");
		exit(1);
	}

	//Reading header 
	fread(header,1,sizeof(header),fp);
	fread(data,1,sizeof(data),fp);
		
	//allocating memory for storing data
	//float buff[header->numChannels][data->subchunk2Size];
	int** buff;
	for(int i=0;i<header->numChannels+1;i++){
		buff[i] = (int *)malloc((header->numChannels+1)*data->subchunk2Size);
	}

	//Reading the sound 
	while(1){
		for(int i=0;i<header->numChannels+1;i++){
			fread(buff[i],sizeof(int),(header->numChannels+1)*data->subchunk2Size,fp);
		}	
		
		if(feof(fp)){
			break;
		}
	}
	printf("%d\n",buff[0][443223]);

	printf("%d\n",data->subchunk2Size);
	printf("%d\n",header->audioFormat);
	printf("%d\n",header->sampleRate);
	printf("%d\n",header->blockAlign);
	printf("%d\n",header->bitsPerSample);
	fclose(fp);
	//free memory after use
	free(header);
	free(data);
	for(int i=0;i<header->numChannels+1;i++){
		free(buff[i]);
	}
	printf("%d,%s",argc,*argv);	
	return 0;
}
