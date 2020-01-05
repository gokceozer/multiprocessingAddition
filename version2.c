#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int RecursiveFunction( int N, int first, int second, int sum )
{
	pid_t fpid = fork();
	int status;


	if(N>=0){
		if(fpid<0)	
			printf("Error\n");
	else if(fpid==0){
			if(N==0){
				printf("This is the child process [ID: %d].\n", getpid());
				if(first + 1 == second){
					printf("2 START, RETURING %d \n", first + second);
					char mid_arg[20];
					char mid_arg2[20];
					sprintf(mid_arg,"%d",first);
					sprintf(mid_arg2,"%d",first+1);
					char *arg_vec[]={"./para_sum",mid_arg,mid_arg2, NULL};
					printf("2 START, RETURING %d \n", first + second);
					execv("./para_sum", arg_vec);
				}else{
					printf("3 START, RETURING %d \n", first + first + first + 1 + 2);
					char mid_arg[20];
					char mid_arg2[20];
					char mid_arg3[20];
					sprintf(mid_arg,"%d",first);
					sprintf(mid_arg2,"%d",first+1);
					sprintf(mid_arg3,"%d",first+2);
					char *arg_vec[]={"./para_sum",mid_arg,mid_arg2,mid_arg3, NULL};
					execv("./para_sum", arg_vec);
				}

			}else{
				RecursiveFunction(--N,first,second,sum);
				char mid_arg[20];
				char mid_arg2[20];
				char mid_arg3[20];
				printf("ALLAHstatıs %d \n", WEXITSTATUS(status));
				printf("ALLAHsum%d \n", sum);
				sprintf(mid_arg,"%d",WEXITSTATUS(status));
				sprintf(mid_arg2,"%d",first+2);
				sprintf(mid_arg3,"%d",first+3);
				char *arg_vec[]={"./para_sum",mid_arg,mid_arg2,mid_arg3, NULL};
				
				execv("./para_sum", arg_vec);
	
			}

		}else{
			wait(status);
			printf("ALLAHson %d \n", WEXITSTATUS(status));
			printf("This is the parent process [ID: %d].\n", getpid());
			printf("The final calculation result is %d.\n\n", WEXITSTATUS(status));
		}

	return sum;
	
	}
}

int main(int argc,char* argv[])
{
	printf("This is the beginning of program.\n\n");
	char* num = argv[1];
	int first = atoi(num);
	num = argv[2];
	int second = atoi(num);
	int N= round((second - first)/2);
	RecursiveFunction(N, first, second, 0);
	
	printf("This is the END of program.\n\n");
	return 0;
}


