#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void addNewStudent();
void viewStudents();
void addDailyCalorie();
void viewStudentDetails();
void generateReport();
void deleteAll();


struct Student{
    int id;
    char name[30];
    double height;
    double weight;
    int age;
};
/*
struct Logs{
    int id;
    int cal;
};
*/

int main(){
int option;
while(1){
    printf("\n1.Add new student\n2.View Students\n3.Add daily calorie consumption\n4.View student details\n5.Generate Report\n6.Delete all\n7.Exit\nEnter : ");
    scanf("%d",&option);

    switch(option){
    case 1 :
        addNewStudent();
        break;
    case 2 :
        viewStudents();
        break;
    case 3:
        addDailyCalorie();
        break;
    case 4:
        viewStudentDetails();
        break;
    case 5:
        generateReport();
        break;
    case 6:
        deleteAll();
        break;
    case 7:
        return 0;
    default:
        printf("\nInvalid option");

    }
}
}


void addNewStudent(){

FILE* student = fopen("student.dat","ab");
if(student == NULL){
     printf("Unsuccessful");
     exit(0);
}

struct Student s;
printf("\nEnter Student's Name : ");
scanf("%s",s.name);
printf("\nEnter the Student id: ");
scanf("%d",&s.id);

printf("\nEnter student's age : ");
scanf("%d",&s.age);
printf("\nEnter student's height in cm : ");
scanf("%lf",&s.height);
printf("\nEnter student's weight in kg : ");
scanf("%lf",&s.weight);

fwrite(&s,sizeof(s),1,student);
fclose(student);
printf("\nStudent added successfully");
}

void viewStudents(){
    FILE* student = fopen("student.dat","rb");
    if(student == NULL){
        printf("Something went wrong");
        exit(0);
    }
    struct Student s;
    while(fread(&s,sizeof(s),1,student)){
        printf("\nId : %d\nName : %s\nAge : %d\nHeight : %.2lf\nWeight : %.2lf\n",s.id,s.name,s.age,s.height,s.weight);
    }
    fclose(student);
}

void addDailyCalorie(){

}

void viewStudentDetails(){

}

void  generateReport(){

}

void deleteAll(){
    FILE* student = fopen("student.dat","wb");
    if(student == NULL){
        printf("Something went wrong");
        exit(0);
    }
    printf("\nDeleted successfully");
    fclose(student);

}





