#include <stdio.h>

int main(int argc, char *argv[]) 
{
	//go through each string in argv

	int i = argc-1;
	while(i >= 0) {
		printf("arg %d: %s\n", i, argv[i]);
		i--;
	}

	// let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	i = 0;
	while(i < argc) {
		states[i] = argv[i];
		i++;
	}

	int num_states = argc;
	i = 0;
	while(i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	return 0;
}
