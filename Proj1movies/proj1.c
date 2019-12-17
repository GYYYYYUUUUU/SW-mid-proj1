/*********************************************************
**********************************************************
**                SW MID-level project                  **
** Originally constructed and copyright by Gyu Sang Cho **
**                For educational use                   **
**                                                      **
**********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_THEATER 5

/**********************************************
 INITIALIZING, DECLARING FUNCTIONS & VARIABLES
 **********************************************/

/*
	ENUM GENRE, 
        possible genres : we will only think about 5 genres; action, adventure, thriller, horror, comedy
*/
typedef enum genre{
 G_NONE=0,
 G_ACTION=1, G_ADVENTURE=2, G_THRILLER=4, G_HORROR=8, G_COMEDY = 16
} GENRE;

/*
	STRUCT movie
	contains information a movie will have.
*/
typedef struct movie{
 int mov_no;
 char title[50];
 int year;
 GENRE g;
 struct movie* next; 
} MOV_T;

/*
	STRUCT mov_header,
	  contains the movie-list information. 

*/
typedef struct mov_header{
 MOV_T* first;
 int list_length;
} MOV_H;


/***************
 global variables
***************/
MOV_T* movie_theater[MAX_THEATER];
MOV_H movie_list;
FILE *fp1, *fp2;
int movie_id = 0;

/* functions */
MOV_T* manual_input_movie();
void file_input_movie();
void theater_input();

MOV_T* new_movie(char *, int);
void initialize_movie_theater();
void theater_update(int);

void print_one_movie(MOV_T*);
void print_all_movie();
void print_movie_theater();

MOV_T* last_in_list();
void put_movie_on_list(MOV_T*);

 

/*************************************************
                   MAIN FUNCTION
**************************************************/

int main(){
 file_input_movie();
 print_all_movie();
 initialize_movie_theater();
 theater_input();
 print_movie_theater();
}


/**************************************************
                  OTHER FUNCTIONS
 **************************************************/

/********** INPUTS ***********/

/* input movie manually, not using file input/output  */
MOV_T* manual_input_movie(){
 char t_title[30];
 int t_year;
 MOV_T* mov;
 printf("input the title : ");
 gets(t_title);
 printf("input the year : ");
 scanf("%d",&t_year);
 mov = new_movie(t_title, t_year);
 put_movie_on_list(mov);
 return mov;
}

/* 
input movie by file, this should run without error 
 	 Q3. IMPLEMENT HERE
	HANDLE the genres
*/
void file_input_movie(){
 char line[MAX_LEN], temp[MAX_LEN];
 char *token1, *token2;

 char *token1_1, *token1_2;
 MOV_T *mov;
 fp1 = fopen("movie.txt","r");
 
 while(fgets(line, MAX_LEN, fp1)!=NULL){
 
  token1 = strtok(line,",");
  token1 = strtok(NULL,",");
  token2 = strtok(NULL,",");
  strcpy(temp,token1);
  token1_1 = strtok(temp, "(");
  token1_2 = strtok(NULL, ")");
  mov = new_movie(token1_1, atoi(token1_2));

  mov->g = G_NONE;

  put_movie_on_list(mov);
 }
 fclose(fp1);
}

/* input used to implement part 2..... */
void theater_input(){
 int upd_n;
 fp2=fopen("theater.txt","r");
 while(fscanf(fp2,"%d",&upd_n) >= 0){
  theater_update(upd_n);
 }
 fclose(fp2);
}

/***************PROCESSING FUNCTIONS****************/

/* making a movie struct. DO NOT MODIFY THIS FUNCTION */
MOV_T* new_movie(char *t_title, int t_year){
 MOV_T* mov = malloc(sizeof(MOV_T));	
 strcpy(mov->title,t_title);
 mov->mov_no=movie_id++;
 mov->year = t_year;
 mov->next = NULL;
 return mov; 
}

/* initializing movie theater. */
void initialize_movie_theater(){
 int i;
 for(i=0;i<MAX_THEATER;i++){
  movie_theater[i] = movie_list.first;
 }
}

/* movie theater update. Q5 IMPLEMENT HERE.*/
void theater_update(int update_no){
 
}

/****************PRINTING FUNCTIONS****************

	USE BELOW FUNCTIONS TO DEBUG YOUR CODE

***************************************************/

/* print_one_movie ; prints information about a movie. 
	NO NEED TO MODIFY
*/
void print_one_movie(MOV_T* mov){
 printf("-------------------\n");
 printf("mov_no : %d\n",mov->mov_no);
 printf("title : %s\n",mov->title);
 printf("year : %d\n",mov->year);
 printf("genre : %d\n",mov->g);
 printf("-------------------\n"); 
}


/* Q1. Implement below function using print_one_movie. 
	This has to print out all the movies in the list.
*/
void print_all_movie(){
 printf("\n-------- print_all_movie -------- \n");
 printf("--------------------------------- \n\n");
}

/* prints out theater information and movies screened in the theater.
	NO NEED TO MODIFY
*/
void print_movie_theater(){
 int i;
 for(i=0;i<MAX_THEATER;i++){
  printf("******* theater no : %d *******\n",i+1);
  print_one_movie(movie_theater[i]);
  printf("*******************************\n\n");
 }
}


/*****************LIST HANDLING FUNCTIONS*****************/

/* returning the last movie of movie_list. NO NEED TO MODIFY*/
MOV_T* last_in_list(){
 MOV_T* mov = movie_list.first;
 if(mov == NULL) return NULL;
 else{
  while((mov -> next) != NULL){
   mov = mov->next;
  }
 return mov;
 }
}

/* inserts a movie into the movie_list at the end. 
	Q2. IMPLEMENT HERE
	Update the list length when list is changed.
*/
void put_movie_on_list(MOV_T* mov){
 MOV_T* last = last_in_list();
 if(last == NULL) movie_list.first = mov;
 else last->next = mov;
}

/* Q4. IMPLEMENT HERE
	Take the integer num as an argument, returns the proper movie struct pointer.
 */
MOV_T* search_list_by_no(int num){
 MOV_T* mov = movie_list.first;


 return mov; 
}
