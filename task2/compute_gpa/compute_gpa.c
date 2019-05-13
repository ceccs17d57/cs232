#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getCredit(char subject[]) {
	if (!strcmp("MA101", subject)) {
		return 4;
	} else if (!strcmp("PH100", subject)) {
		return 4;
	} else if (!strcmp("BE100", subject)) {
		return 4;
	} else if (!strcmp("BE10105", subject)) {
		return 3;
	} else if (!strcmp("BE103", subject)) {
		return 3;
	} else if (!strcmp("EE100", subject)) {
		return 3;
	} else if (!strcmp("PH110", subject)) {
		return 1;
	} else if (!strcmp("EE110", subject)) {
		return 1;
	} else if (!strcmp("CS110", subject)) {
		return 1;
	} else if (!strcmp("MA102", subject)) {
		return 4;
	} else if (!strcmp("CY100", subject)) {
		return 4;
	} else if (!strcmp("BE110", subject)) {
		return 3;
	} else if (!strcmp("BE102", subject)) {
		return 3;
	} else if (!strcmp("CY110", subject)) {
		return 1;
	} else if (!strcmp("EC100", subject)) {
		return 3;
	} else if (!strcmp("EC110", subject)) {
		return 1;
	} else if (!strcmp("CS120", subject)) {
		return 1;
	} else if (!strcmp("CS100", subject)) {
		return 3;
	} else {
		printf("Invalid subject : |%s|\n", subject);
	}
}
float computeGPA(char buf[]) {
	int i, j, k, count=0, credit, totalcredit=0;
	float total=0;
	char grade[3], subject[10];
	for (i=0; buf[i] != '\0'; i++) {
		if (buf[i] == ' ' && buf[i+1] != ' ' && buf[i+1] != '\n' && buf[i+1] != '\0') {
			k=0;
			i++;
			while (buf[i] != '(') {
				subject[k++] = buf[i++];
			}
			subject[k] = '\0';
			credit = getCredit(subject);
			totalcredit += credit;
			if (buf[i] == '(') {
				j=0;
				i++;
				count++;
				while(buf[i] != ')') {
					grade[j++] = buf[i++];
				}
				grade[j] = '\0';
				if (!strcmp(grade, "O")) {
					total += 10*credit;
				} else if (!strcmp(grade, "A+")) {
					total += 9*credit;
				} else if (!strcmp(grade, "A")) {
					total += 8.5*credit;
				} else if (!strcmp(grade, "B+")) {
					total += 8*credit;
				} else if (!strcmp(grade, "B")) {
					total += 7*credit;
				} else if (!strcmp(grade, "C")) {
					total += 6*credit;
				} else if (!strcmp(grade, "P")) {
					total += 5*credit;
				} else {
					total += 0;
				}
			}
		}
	}
	return (float)(total/totalcredit);
}
void getRegNo(char buf[], char regNo[]) {
	int i;
	for (i=0; i<10; i++) {
		regNo[i] = buf[i];
	}
	regNo[i] = '\0';
}
void getName(char buf[], char name[]) {
	int i=11, j=0;
	while (buf[i]!='\0') {
		if (buf[i] == ' ' && buf[i+1] == ' ') {
			break;
		}
		name[j++] = buf[i++];
	}
	name[j] = '\0';
}
int main(int argc, char **args) {
	char buf[BUFSIZ], regNo[11], name[100];
	float gpa;
	while (fgets(buf, sizeof(buf), stdin)) {
		if ( buf[0] == '\n') {
			break;
		}
		//gpa = computeCGPA(buf);
		//printf("%s", buf);
		getRegNo(buf, regNo);
		//getName(buf, name);
		gpa = computeGPA(buf);
		printf("%s| %.2f\n", regNo, name, gpa);
	}
}
