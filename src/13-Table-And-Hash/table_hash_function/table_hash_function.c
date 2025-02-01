#include <stdio.h>

typedef struct EmployeeInfo {
	int id;
	int age;
} EmpInfo;

int GetHashValue(int emp_id) {
	return emp_id % 100;  // use the remainder of emp_id divided by 100 as the hash value
}

int main(void) {
	EmpInfo emp_info_arr[100];
	
	EmpInfo emp1 = {20120003, 42};
	EmpInfo emp2 = {20130012, 33};
	EmpInfo emp3 = {20170049, 27};
	
	EmpInfo r1, r2, r3;
	
	emp_info_arr[GetHashValue(emp1.id)] = emp1;
	emp_info_arr[GetHashValue(emp2.id)] = emp2;
	emp_info_arr[GetHashValue(emp3.id)] = emp3;
	
	r1 = emp_info_arr[GetHashValue(20120003)];
	r2 = emp_info_arr[GetHashValue(20130012)];
	r3 = emp_info_arr[GetHashValue(20170049)];
	
	printf("ID: %d, Age: %d \n", r1.id, r1.age);
	printf("ID: %d, Age: %d \n", r2.id, r2.age);
	printf("ID: %d, Age: %d \n", r3.id, r3.age);
	
	return 0;
}