#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char *argv[]) {
	if(argc-1 != 2 )
	{	
		printf("Error: The number of input integers now is %d.\n", argc-1);
		printf("Error: Please input 2 integers.\n"); 
		exit(0);
	}
	char* num = argv[1];
	int first = atoi(num);
	num = argv[2];
	int second = atoi(num);
	if( (first > 0)  && (first < second) && (second < 21)){
		int N = second - first + 1;
		if(N > 7){
			printf("Error: the number of calculated integers is %d, larger than 7.\n", N);
			exit(1);
		}
		if(N <= 3){
			printf("This is the beginning of the program!\n");
			printf("This program will calculate the sum from %d to %d \n", first,second);
			if( N == 3 ){
				printf("The calculation will be calculated in 1 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){	
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					printf("The ID of this child process is %d, adding [1, 2, 3].\n", getpid());
					char mid_arg[20];
					sprintf(mid_arg,"%d",first+1);
					char *arg_vec[]={"./para_sum",argv[1],mid_arg,argv[2], NULL};
					execv("./para_sum", arg_vec);	
				}else{
				        wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
				}

			}else if( N == 2 ){
				printf("The calculation will be calculated in 1 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					printf("The ID of this child process is %d, adding [1, 2].\n", getpid()); 
					char *arg_vec[]={"./para_sum",argv[1],argv[2], NULL};
					execv("./para_sum", arg_vec);
				}else{
					wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status)); 
				}
			}
		}else if(N==4 || N==5){
			printf("This is the beginning of the program!\n");
			printf("This program will calculate the sum from %d to %d \n", first,second);
			if( N == 4 ){
				printf("The calculation will be calculated in 2 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){	
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					fpid = fork();
					if(fpid < 0){
						printf("Error in executing fork!\n");
					}else if (fpid == 0) {
						printf("The ID of this child process is %d, adding [1, 2, 3].\n", getpid());
						char mid_arg[20];
						char mid_arg2[20];
						sprintf(mid_arg,"%d",first+1);
						sprintf(mid_arg2,"%d",first+2);
						char *arg_vec[]={"./para_sum",argv[1],mid_arg,mid_arg2, NULL};
						execv("./para_sum", arg_vec);
					}else{
						wait(&status);
						char child_sum[20];
						
						printf("The ID of this child process is %d, continuing to add [4].\n", getpid());
						sprintf(child_sum,"%d",WEXITSTATUS(status));
						char *arg_vec[]={"./para_sum",child_sum,argv[2], NULL};
						execv("./para_sum", arg_vec);
					}
				}else{
				        wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
				}

			}else if( N == 5  ){
				printf("The calculation will be calculated in 2 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){	
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					fpid = fork();
					if(fpid < 0){
						printf("Error in executing fork!\n");
					}else if (fpid == 0) {
						printf("The ID of this child process is %d, adding [1, 2, 3].\n", getpid());
						char mid_arg[20];
						char mid_arg2[20];
						sprintf(mid_arg,"%d",first+1);
						sprintf(mid_arg2,"%d",first+2);
						char *arg_vec[]={"./para_sum",argv[1],mid_arg,mid_arg2, NULL};
						execv("./para_sum", arg_vec);
					}else{
						wait(&status);
						char child_sum[20];
						char mid_arg[20];
						printf("The ID of this child process is %d, continuing to add [4, 5].\n", getpid());
						sprintf(child_sum,"%d",WEXITSTATUS(status));
						sprintf(mid_arg,"%d",first+3);
						char *arg_vec[]={"./para_sum",child_sum, mid_arg,argv[2], NULL};
						execv("./para_sum", arg_vec);
					}
				}else{
				        wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
				}	

			}
	
		}else if( N == 6 || N == 7){
			printf("This is the beginning of the program!\n");
			printf("This program will calculate the sum from %d to %d \n", first,second);
			if( N == 6 ){
				printf("The calculation will be calculated in 3 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){	
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					fpid = fork();
					if(fpid < 0){
						printf("Error in executing fork!\n");
					}else if (fpid == 0) {
						fpid = fork();
						if (fpid < 0){
							printf("Error in executing fork!\n");
						}else if (fpid == 0) {
							printf("The ID of this child process is %d, adding [1, 2, 3].\n", getpid());
							char mid_arg[20];
							char mid_arg2[20];
							sprintf(mid_arg,"%d",first+1);
							sprintf(mid_arg2,"%d",first+2);
							char *arg_vec[]={"./para_sum",argv[1],mid_arg,mid_arg2, NULL};
							execv("./para_sum", arg_vec);
						}else{
							wait(&status);
							char child_sum[20];
							char mid_arg[20];
							char mid_arg2[20];
							printf("The ID of this child process is %d, continuing to add [4, 5].\n", getpid());
							sprintf(child_sum,"%d",WEXITSTATUS(status));
							sprintf(mid_arg,"%d",second-2);
							sprintf(mid_arg2,"%d",second-1);
							char *arg_vec[]={"./para_sum",child_sum,mid_arg,mid_arg2, NULL};
							execv("./para_sum", arg_vec);
						}
					}else{
						wait(&status);
						char child_sum[20];
						
						printf("The ID of this child process is %d, continuing to add [6].\n", getpid());
						sprintf(child_sum,"%d",WEXITSTATUS(status));
						char *arg_vec[]={"./para_sum",child_sum,argv[2], NULL};
						execv("./para_sum", arg_vec);
					}
				}else{
				        wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
				}

			}else if( N == 7  ){
				printf("The calculation will be calculated in 3 child process(es)!\n\n");
				pid_t fpid = fork();
				int status;
				if (fpid < 0){	
					printf("Error in executing fork!\n");
				}else if (fpid == 0) {
					fpid = fork();
					if(fpid < 0){
						printf("Error in executing fork!\n");
					}else if (fpid == 0) {
						fpid = fork();
						if (fpid < 0){
							printf("Error in executing fork!\n");
						}else if (fpid == 0) {
							printf("The ID of this child process is %d, adding [1, 2, 3].\n", getpid());
							char mid_arg[20];
							char mid_arg2[20];
							sprintf(mid_arg,"%d",first+1);
							sprintf(mid_arg2,"%d",first+2);
							char *arg_vec[]={"./para_sum",argv[1],mid_arg,mid_arg2, NULL};
							execv("./para_sum", arg_vec);
						}else{
							wait(&status);
							char child_sum[20];
							char mid_arg[20];
							char mid_arg2[20];
							printf("The ID of this child process is %d, continuing to add [4, 5].\n", getpid());
							sprintf(child_sum,"%d",WEXITSTATUS(status));
							sprintf(mid_arg,"%d",first+3);
							sprintf(mid_arg2,"%d",first+4);
							char *arg_vec[]={"./para_sum",child_sum, mid_arg, mid_arg2, NULL};
							execv("./para_sum", arg_vec);
						}
					}else{
						wait(&status);
						char child_sum[20];
						char mid_arg[20];
						printf("The ID of this child process is %d, continuing to add [6, 7].\n", getpid());
						sprintf(child_sum,"%d",WEXITSTATUS(status));
						sprintf(mid_arg,"%d",first+5);
						char *arg_vec[]={"./para_sum",child_sum, mid_arg,argv[2], NULL};
						execv("./para_sum", arg_vec);
					}
				}else{
				        wait(&status);
					printf("This is the parent process [ID: %d].\n", getpid());
					printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
				}
			
			}

		}


		}else if( first <= 0 || second <= 0){
			printf("Error: Please input two positive integers.\n");
			exit(1);
		}else if( first >= second){
			printf("Error: The first integer should be smaller than the second one.\n");
			exit(1);
		}else if( second >= 21){
			printf("Error: The second integer should be smaller than 21.\n");
			exit(1);
		}
	
		

	printf("This is the END of program.\n");
	return 0;
}


