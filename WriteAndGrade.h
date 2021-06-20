//fungsi untuk menghitung nilai user berdasarkan jumlah benar dan total soal
int get_grade(){
  
  FILE *fptr = fopen(file_jawaban, "r");
  char answer[150];
  fgets(answer, 150, fptr);

  int banyak_soal = strlen(answer); 
  int correctAns = 0;
  float grade = 0;
  int i;

  for(i=0; i < banyak_soal; i++){
		if(jawaban_sementara[i] == answer[i]){
			correctAns ++;
		}
	}
	grade = (float)correctAns/banyak_soal
	fclose(fptr);
	return grade;

}


//fungsi untuk menampilkan nilai user setelah menjawab soal
void display_grade(float nilai){
	printf("Your final grade is %.2f\n", grade);
}


//fungsi untuk menyimpan hasil dari ujian ke dalam teks file
void write_jawaban(char nama[], int npm, char jawaban_sementara[], float nilai)
{
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime = localtime(&currentTime);
	
	FILE *fptr = fopen(file_data_dan_jawaban, "a");
	fprintf(fptr, "%s-%s-%s-%.2f-%i/%i/%i, %i:%i", nama, npm, jawaban_sementara, nilai, myTime->tm_mday, myTime->tm_mon + 1, myTime->tm_year + 1900, myTime->tm_hour,
	        myTime->tm_min);
	fclose(fptr);
}


//fungsi untuk mengecek apakah array jawaban sementara penuh
bool isFullArray(char jawaban_sementara[], int back)
{
	if(back == strlen(jawaban_sementara){
		return true;
	}
	else 
	return false;
}


//fungsi untuk mengecek apakah array jawaban sementara kosong
bool isEmptyArray(int back){
	if(back == 0){
		return true;
	}
	else 
	return false;
}


//fungsi untuk menyimpan jawaban sementara ke jawaban asli
void enqueueArray(char jawaban_sementara[], char jawaban_asli[], int* front, int* back){
	int i;
	if(isFullArray(jawaban, back)){
		printf("jawaban melebihi batas!\n");
	}
	else{
		for(i=0; i < strlen(jawaban_sementara); i++)
		if(isEmptyArray(back)){ 
			strcpy(jawaban_asli[i], jawaban_sementara[i]);
			*front = *front + 1;
			*back = *back + 1;
		}
		else{
			strcpy(jawaban_asli[i], jawaban_sementara[i]);
			*back = *back + 1;
			
		}
	}
}
//fungsi untuk menghapus jawaban yang telah tersimpan
void clearArray(char jawaban_sementara[], char jawaban_asli[], int* back){
	int i;
	if(isEmptyArray(back)) { 
		printf("jawaban kosong!\n");
	}
	else{
		for(i=0; i < back; i++){
			strcpy(jawaban_asli[i], "");
			*back = *back - 1;
		}
		
	}
}


