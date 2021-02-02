#include <stdio.h>
#include <string.h>

int main() {
	char start_delimeter[10];
	char end_delimeter[10];
	char string[100];
	char stuffing[10];
	char stuffed_string[100];
	char esc[] = "esc";
	int k = 0;
	printf("Enter the string :");
	scanf("%s", string);
	printf("Enter starting delimiter :");
	scanf("%s", start_delimeter);
	printf("Enter ending delimiter :");
	scanf("%s", end_delimeter);
	printf("Enter stuffed string :");
	scanf("%s", stuffing);

	for (int i = 0; i <strlen(start_delimeter); i++) {
		stuffed_string[k] = start_delimeter[i];
		k++;
	}

	for (int i = 0; i < strlen(string); i++) {
		int count = 0;
		for (int j = i, l = 0; j < (i + strlen(start_delimeter)); j++,l++) {
			if (string[j] == start_delimeter[l]) {
				count++;
			} else {
				break;
			}
		}
		if (count == strlen(start_delimeter)) {
			for (int x = 0; x < strlen(stuffing); x++) {
				stuffed_string[k] = stuffing[x];
				k++;
			}
		}
		count = 0;
		for (int j = i, l = 0; j < (i + strlen(end_delimeter)); j++,l++) {
                        if (string[j] == end_delimeter[l]) {
                                count++;
                        } else {
                                break;
                        }
                }
                if (count == strlen(end_delimeter)) {
                        for (int x = 0; x < strlen(stuffing); x++) {
                                stuffed_string[k] = stuffing[x];
                                k++;
                        }
                }
		count = 0;
		for (int j = i, l = 0; j < (i + strlen(esc)); j++,l++) {
                        if (string[j] == esc[l]) {
                                count++;
                        } else {
                                break;
                        }
                }
                if (count == strlen(esc)) {
                        for (int m = 0; m < strlen(stuffing); m++) {
                                stuffed_string[k] = stuffing[m];
                                k++;
                        }
                }
		 
		stuffed_string[k] = string[i];
		k++;
	}

	for (int i = 0; i <strlen(end_delimeter); i++) {
                stuffed_string[k] = end_delimeter[i];
                k++;
        }
	
	stuffed_string[k] = '\0';

	printf("After Stuffing: %s\n", stuffed_string);
	return 0;
}
