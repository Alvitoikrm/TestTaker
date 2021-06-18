#define SIZE 256 // besarnya buffer untuk struct

// untuk mempermudah penamaan, 
// kumpulan soal dan jawaban dinamakan section
struct Soal_N_Jawaban{ 
	char soal[SIZE];	   
	char jawaban_a[SIZE];
	char jawaban_b[SIZE];
	char jawaban_c[SIZE];
	char jawaban_d[SIZE];
};

void SetCursorPosition(int XPos, int YPos) {
	COORD coord;
	coord.X = XPos; 
	coord.Y = YPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void timer(int time, int *flag_ujian){
	int minutes, seconds;
	
	while (time != 0){
		minutes = time / 60;
		seconds = time % 60;
		
		// adjust cursor position as necessary
		SetCursorPosition(0, 0);
		printf("%02d:%02d", minutes, seconds);
		SetCursorPosition(0, 2);
		
		time -= 1;
		Sleep(1000); // interval 1 detik
	}
	
	*flag_ujian = 0;
}

// menghitung banyaknya line pada file
int count_lines(char filename[]){
	char c;
	int count = 0;
	FILE *file = fopen(filename, "r"); 
	
	for (c = getc(file); c != EOF; c = getc(file)){
		// jika menemukan newline maka increment
		if (c == '\n') count++;
	}
    fclose(file);
	return count;	
}

// fungsi ini mengkopi section tertentu dari bagian file yang telah ditentukan ke struct
// pada dasarnya mengkopi tiap 5 line data dari file yang ditentukan ke struct
void section_to_struct(struct Soal_N_Jawaban *pointer_section, char filename[], int section_num){
	struct Soal_N_Jawaban temp;
	
	temp = *pointer_section;
	FILE *file = fopen(filename, "r"); 
	
	// tiap section mempunyai 5 bagian. point ke section n berarti
	// read 5 line mulai dari (section_num-1)*5+1
	int n = (section_num - 1) * 5 + 1;  // batas bawah
	int m = n + 5;	   				    // batas atas
	int max_section = count_lines(filename)/5;
	
	// kembalikan null jika jumlah section tidak sesuai dengan yang ada di file
	if (section_num < 0 || section_num > max_section){
		temp.soal[0] = '\0';
		temp.jawaban_a[0] = '\0';
		temp.jawaban_b[0] = '\0';
		temp.jawaban_c[0] = '\0';
		temp.jawaban_d[0] = '\0';
	}
	else{
		char line[SIZE];
		int line_num = 1;
		int rem;
		
		while (fgets(line, sizeof(line), file)){
			if (line_num == m){
				break;
			}
			if (line_num >= n && line_num < m){
				rem = line_num % 5;
				if (rem == 1) strcpy(temp.soal, line);
				else if (rem == 2) strcpy(temp.jawaban_a, line);
				else if (rem == 3) strcpy(temp.jawaban_b, line);
				else if (rem == 4) strcpy(temp.jawaban_c, line);
				else if (rem == 0) strcpy(temp.jawaban_d, line);
			}	
			line_num++;
		}
	}

	*pointer_section = temp;
	fclose(file);
}

