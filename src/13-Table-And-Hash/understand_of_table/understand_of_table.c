#include <stdio.h>

typedef struct EmployeeInfo {
	int id;
	int age;
} EmpInfo;

int main() {
	EmpInfo emp_info_arr[1000];
	EmpInfo emp_info;
	int id_to_search;
	
	printf("Enter Id and age: ");
	scanf("%d %d", &(emp_info.id), &(emp_info.age));
	emp_info_arr[emp_info.id] = emp_info;
	
	printf("Enter employee's Id to view info: ");
	scanf("%d", &id_to_search);
	
	emp_info = emp_info_arr[id_to_search];
	printf("ID %d, age %d \n", emp_info.id, emp_info.age);
	return 0;
}