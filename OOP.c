#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parent class
typedef struct Person{
    void (*change)(struct Person*); //method pointer for polymorphism
}Person;

//child class
typedef struct Student{
    Person person; //inheritance from person
    char* name;
    char* grade;
}Student;

typedef struct Employee{
    Person person;
    char* name;
    char* company;
}Employee;

//method for student
void student_change(Person* person){
    Student* student =  (Student*)person; //caste base class to child class
    int ch;
    printf("Enter 1 to change name and 2 to change grade: ");
    scanf("%d", &ch);

    if (ch == 1){
        char name[100];
        printf("Enter new name: ");
        scanf("%s", name);
        free(student->name);
        student->name = strdup(name); //i used strdup for proper copying of string
    }
    else{
        char grade[100];
        printf("Enter new grade: ");
        scanf("%s", grade);
        free(student->grade);
        student->grade = strdup(grade);
    }
}

void employee_change(Person* person){
    Employee* employee =  (Employee*)person;
    int ch;
    printf("Enter 1 to change name and 2 to change company: ");
    scanf("%d", &ch);

    if (ch == 1){
        char name[100];
        printf("Enter new name: ");
        scanf("%s", name);
        free(employee->name);
        employee->name = strdup(name);
    }
    else{
        char company[100];
        printf("Enter new company: ");
        scanf("%s", company);
        free(employee->company);
        employee->company = strdup(company);
    }
}

//contructors for student and employee
Student* new_student(char* name, char* grade){
    Student* student = (Student*)malloc(sizeof(Student));
    student->person.change = student_change; //assign student specific method for change
    student->name = strdup(name);
    student->grade = strdup(grade);
    return student;
}

Employee* new_employee(char* name, char* company){
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    employee->person.change = employee_change; //assign employee specific method for change
    employee->name = strdup(name);
    employee->company = strdup(company);
    return employee;
}

int main(void){
    //make objects
    Student* student = new_student("ramesh", "thadumal");
    Employee* employee = new_employee("bhavesh", "unemployed");

    printf("Student name is %s and study at %s\n", student->name, student->grade);
    printf("Employee is %s and is %s\n", employee->name, employee->company);

    //polymorphism here, using base class pointer to call method of child
    Person* person1 = (Person*)student;
    Person* person2 = (Person*)employee;

    person1->change(person1); //call student change
    person2->change(person2); //call employee change

    printf("Student name is %s and study at %s\n", student->name, student->grade);
    printf("Employee is %s and is %s\n", employee->name, employee->company);

    free(student->name);
    free(student->grade);
    free(student);
    free(employee->name);
    free(employee->company);
    free(employee);

    return 0;
}
