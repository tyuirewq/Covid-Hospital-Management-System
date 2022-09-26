#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

int choice,o = 0,variable1,variable=0,num10 = 0;
void first_page();                    //    first page 
void title();                         //    title function
void last_page();                     //    last page printing thank you
void feature();                       //    main function
void doctorinfo();                    //    Doctor's Information
void book_appointment();              //    book appointment
void view_appointment();              //    view appointment
void appointment();                   //    main appointment function 
void addpatient();                    //    add patient information to corona ward
int billgen();                        //    bill generator function
void medical();                       //    medical facilities
void viewpatient();                   //    view corona ward patient information
void corona();                        //    Corona ward main function 
void room();                          //    main function of room details
void availrooms();                    //    shows room availability
void storeinrooms();                  //    tells available facility in room
void recordofrooms();                 //    record of room
void facility();                      //    facility available in all room's of this hospital
void bookaroom();                     //    booking of room
int icu();                            //    calculates icu chages
int cov_pre();                        //    symptoms identifier
int predict(char a);                  //    function used to count symptoms
int result(int y);                    //    shows whether person is affected or not
struct patient{
    char age[20];
    char gender[20];
    char first_name[20];
    char last_name[20];
    char contact_number[20];
    char address1[50],address2[50];
    char email[40];
    char discharge[40];
    char admitted[40];
     };                      
struct patient record,appoint;        //    basically a  collection of various variable used in functions
void readFile(int maxChars, FILE *file, char str[]);
void stringToWords(char str[], char words[][20]);
void write(FILE *file, char Name[], char expiryDate[], int Stock);
int strToInt(char str[]);
int main(){
    int q;
    first_page();
    feature();
    system("cls");
    last_page();
    return 0;
 }
void first_page(){
    printf("\n\n##########################################################################################\n");
    printf("#                                                                                        #\n");
    printf("#                                                                                        #\n");
    printf("#                                          Welcome to                                    #\n");
    printf("#                                                                                        #\n");
    printf("#                                    This project of Covid19                             #\n");
    printf("#                                                                                        #\n");
    printf("#                                     Management system made by                          #\n");
    printf("#                                                                                        #\n");
    printf("#                                     Developer team Group 56                            #\n");
    printf("#                                                                                        #\n");
    printf("#                                                                                        #\n");
    printf("##########################################################################################\n");
    printf("\n\n\n\nPress enter key to go further.................");
    getchar();
    system("cls"); }
void title(){
    printf("########################################################################################################\n");
    printf("#                                                                                                      #\n");
    printf("#                       Covid-19 Speciality Hospital of Gandhinagar                                    #\n");
    printf("#                                                                                                      #\n");
    printf("########################################################################################################\n");  }
void feature(){
    a:
    system("cls");
    title();
    printf("\n\n                             MAIN MENU                           ");
    printf("\n\n      Choose following option to fetch respective details\n\n");
    printf("      1.  Corona wards details \n\n");
    printf("      2.  Doctor's Appointment  \n\n");
    printf("      3.  Room details  \n\n");
    printf("      4.  Bill Genrator  \n\n");
    printf("      5.  Symptoms Identifiers  \n\n");
    printf("      6.  Medical store \n\n");
    printf("      7.  Exit \n\n");
    scanf("%d",&choice);
    if (choice == 1) {
        corona();
        goto a;
    } 
    if (choice == 2) {
        appointment();
        goto a;
    }
    if (choice == 3) {
        system("cls");
        room();
        goto a;
        }  
    if (choice == 4) {
        system("cls");
        billgen();
        goto a;
        }
    if (choice == 5) {
        system("cls");
        cov_pre(); goto a;   
        system("cls");
        }
    if (choice == 6) {
        system("cls");
        medical();
        system("cls");
        goto a;
    } //Medical store(yet to define) 
    if (choice == 7) return;  
    else {
        printf("\n\nYou have entered option   \n");
        printf("Press enter key to choose again   \n\n");
        getchar();
        getchar();
        goto a;
    } }
void addpatient(){
    system("cls");
    title();
    FILE*jkl = NULL;
    jkl = fopen("patients_records.txt","a");
    printf("\n................................     ADD PATIENT RECORDS      ................................");
    printf("\n\nFirst name of patient  :  ");
    scanf("%s",&record.first_name);
    printf("\nLast name of patient  :  ");
    scanf("%s",&record.last_name);
    printf("\nContact Number  :   ");
    scanf("%s",&record.contact_number);
    printf("\nAge  :  ");
    scanf("%s",&record.age);
    printf("\nGender  :   ");
    scanf("%s",&record.gender);
    printf("\nAddress  :   ");
    scanf("%s %s",&record.address1,&record.address2);
    printf("\nEmail  :   ");
    scanf("%s",&record.email);
    printf("\nAdmitted on   :   ");
    scanf("%s",&record.admitted);
    printf("\nDischarge on   :   ");
    scanf("%s",&record.discharge);
    fprintf(jkl,"\n %s %s %s %s %s %s %s %s %s %s",record.discharge,record.admitted,record.first_name,record.last_name,record.contact_number,record.age,record.gender,record.address1,record.address2,record.email);
    fclose(jkl);
    printf("\n\n\nPatient details has been recorded \n\nPress Enter key to go back     ");
    getchar();
    getchar();  }
void viewpatient(){
    system("cls");
    title();
    printf("\n\n\n.....................................    VIEW PATIENTS DETAILS    ......................................");
    FILE*jkl;
    jkl = fopen("patients_records.txt","r");
    for(o = 1;(fscanf(jkl,"%s %s %s %s %s %s %s %s %s %s",record.discharge,record.admitted,record.first_name,record.last_name,record.contact_number,record.age,record.gender,record.address1,record.address2,record.email) != EOF)&& (o<=10);o++){
        printf("\n%d::\n",o);
        printf("Name of patient            :  %s %s\n",record.first_name,record.last_name);
        printf("Age of patient             :  %s\n",record.age);
        printf("Gender name of patient     :  %s\n",record.gender);
        printf("Address of patient         :  %s  %s\n",record.address1,record.address2);
        printf("Contact number of patient  :  %s\n",record.contact_number);
        printf("Email of patient           :  %s\n",record.email);
        printf("Admitted on                :  %s\n",record.admitted);
        printf("Discharged on              :  %s\n",record.discharge);
        }
        fclose(jkl);
        printf("\n\n\n\nPress enter key to go back ......");
        getchar();
        getchar();
        system("cls"); }
void appointment(){
    c:
    system("cls");
    title();
    printf("\n\n\n\t\t\t\t\t    DOCTORS APPOINTMENTS   ");
    printf("\n\n      Choose Following options............   \n");
    printf("\n         1. Doctor's Information \n");
    printf("\n         2. Book Appointment \n");
    printf("\n         3. View Appointment \n");
    printf("\n         4. To go back \n\n");
    scanf("%d",&choice); 
    if (choice == 1)
    {
        system("cls");
        doctorinfo();
        goto c;
    }
    if (choice == 2)
    {
        system("cls");
        book_appointment();
        goto c;
    }
    if (choice == 3)
    {
        system("cls");
        view_appointment();
        goto c;
    }
    if (choice == 4)
    {
        system("cls");
        return;
    }
    else
    {
        printf("\n\nYOU HAVE ENTERED WRONG OPTIONS.......");
    }
    printf("\n\nPress Enter key to go back      ");
    getchar();
    getchar();
    system("cls");
    return; }
void last_page(){
    printf("\n\n\n\n\n\n\n#############################################################################\n");
    printf("##                                                                         ##\n");
    printf("##                                                                         ##\n");
    printf("##                      .......Thanking you......                          ##\n");
    printf("##                                                                         ##\n");
    printf("##                                                                         ##\n");
    printf("#############################################################################\n\n\n\n\n");}
void doctorinfo(){
    system("cls");
    title();
    printf("\n\n\n\t\t\t1. Dr. Rupesh Verma    (.......Cardiologist........)\n\t\t\tAvailable from 11AM to 4PM\n\t\t\tContact  :-  7896879458\n\t\t\tCharge  :-  500 rupees only");
    printf("\n\n\n\t\t\t2. Dr. Howard Park     (.......Neurologists........)\n\t\t\tAvailable from 2PM to 6PM\n\t\t\tContact  :-  9867896799\n\t\t\tCharge  :-  1000 rupees only");
    printf("\n\n\n\t\t\t3. Dr. Vijay Kher      (.......Gastroenterologists........)\n\t\t\tAvailable from 10AM to 4PM\n\t\t\tContact  :-  8796897868\n\t\t\tCharge  :-  500 rupees only");
    printf("\n\n\n\t\t\t4. Dr. Dia Mirza       (.......Oncologists........)\n\t\t\tAvailable from 10AM to 5PM\n\t\t\tContact  :-  9978696689\n\t\t\tCharge  :-  400 rupees only");
    printf("\n\n\n\t\t\t5. Dr. Suhani Sharma    (.......Dentist........)\n\t\t\tAvailable from 9AM to 3PM\n\t\t\tContact  :-  9667887699\n\t\t\tCharge  :-  200 rupees only\n\n\n\n");
    printf("\n\n\nPress Enter key to go back      ");
    getchar();
    getchar();
    system("cls");}
void room(){ 
    int option;
    e:
    system("cls");
    title();
    printf("\n\n.............Choose following option to fetch respective details..............\n");
    printf("\n\n\n          All room in the hospital    -    10");
    printf("\n\n         1.Check availability of  rooms");
    printf("\n         2.Check store in rooms");
    printf("\n         3.Check record of rooms");
    printf("\n         4.Facilities of rooms");
    printf("\n         5.Book a room");
    printf("\n         6.To go back\n\n\n");
    scanf("%d", &option);
    
    if (option == 1){
        system("cls");
        availrooms();
        goto e;
    } 
    if (option == 2){
        system("cls");
        storeinrooms();
        goto e;
    } 
    if (option == 3){
        system("cls");
        recordofrooms();
        goto e;
    } 
    if (option == 4){
        system("cls");
        facility();
        goto e;
    } 
    if (option == 5){
        system("cls");
        bookaroom();
        goto e;
    }
    if (option == 6){
        system("cls");
        return;
    }
    else {
        printf("\n\n\nYou have entered incorrect option..........      ");
        getchar();
        getchar();
        goto e;
    }
    system("cls");
    return; }
void availrooms(){
    system("cls");
    title();
    printf("\n\n\n        Available rooms    -   04");
    printf("\n        Booked rooms       -   06");
    printf("\n\n\nPress Enter key to go back..........");
    getchar();
    getchar();
    system("cls");}
void storeinrooms(){
    f:
    system("cls");
    int roomno;
    title();
    printf("\n\n............Choose following room number to fetch respective details..........\n");
    printf("\n\n        1.  For room 1");
    printf("\n        2.  For room 2");
    printf("\n        3.  For room 3");
    printf("\n        4.  For room 4");
    printf("\n        5.  For room 5");
    printf("\n        6.  For room 6");
    printf("\n        7.  For room 7");
    printf("\n        8.  For room 8");
    printf("\n        9.  For room 9");
    printf("\n       10.  For room 10\n\n\n");
    printf("\n       11.  To go back\n\n");

    scanf ("%d", &roomno);
    if (roomno <6 && roomno >0)
    {
        system("cls");
        printf("\n\n        *  Executive      ---->     Available");
        printf("\n        *  Medicines      ---->     Not Available");
        printf("\n        *  Oxygen         ---->     Available");
        printf("\n        *  ICU            ---->     Available");
        printf("\n        *  Isolation ICU  ---->     Available");
        printf("\n\nPress Enter key to go back      ");
        getchar();
        getchar();
        system("cls");
        goto f;
    }
    if (roomno <11 && roomno >=6)
    {
        system("cls");
        printf("\n\n        *  Executive      ---->     Available");
        printf("\n        *  Medicines      ---->     Not Available");
        printf("\n        *  Oxygen         ---->     Available");
        printf("\n        *  ICU            ---->     Available");
        printf("\n        *  Isolation ICU  ---->     Not Available");
        printf("\n\nPress Enter key to go back      ");
        getchar();
        getchar();
        system("cls");
        goto f;
    }
    if (roomno == 11){
        system("cls");
        return;
    }
    else{
        printf("\n\n\nYou have entered incorrect option..........");
        getchar();
        getchar();
        goto f;
    }}
void recordofrooms(){
    int roomno;
    g:
    system("cls");
    title();
    printf("\n\n\n..............Choose following room number to find patient's detail..............\n");
    printf("\n\n\n        1.  For room 1");
    printf("\n        2.  For room 2");
    printf("\n        3.  For room 3");
    printf("\n        4.  For room 4");
    printf("\n        5.  For room 5");
    printf("\n        6.  For room 6");
    printf("\n        7.  For room 7");
    printf("\n        8.  For room 8");
    printf("\n        9.  For room 9");
    printf("\n       10.  For room 10\n\n\n");
    printf("\n       11.  To go back\n\n");
    scanf ("%d", &roomno);
    if (roomno >0 && roomno<5)
    {
    system("cls");
    printf("\n\n\n................................    PATIENT DETAILS      ................................");
    printf("\n\n\n        First name of patient :  Ramesh ");
    printf("\n        Last name of patient  :  Tripathi ");
    printf("\n        Contact Number        :  99xxxxxx99 ");
    printf("\n        Age                   :  25yrs ");
    printf("\n        Gender                :  Male ");
    printf("\n        Address               :  78, MN-2, jaipur ");
    printf("\n        Email                 :  ramexxxxx2@gmail.com ");
    printf("\n\nPress Enter key to go back      ");
    getchar();
    getchar();
    system("cls");
    goto g;
    }
    if (roomno >=5 && roomno<=10)
    {
    system("cls");
    printf("\n\n\n................................    PATIENT DETAILS      ................................");
    printf("\n\n\n        First name of patient :  Bala ");
    printf("\n        Last name of patient  :  Saaho ");
    printf("\n        Contact Number        :  99xxxxxx89 ");
    printf("\n        Age                   :  41yrs ");
    printf("\n        Gender                :  Male ");
    printf("\n        Address               :  26, ER-2, Raipur ");
    printf("\n        Email                 :  balaaxxxx2@gmail.com ");
    printf("\n\nPress Enter key to go back      ");
    getchar();
    getchar();
    system("cls");
    goto g;
    }
    if(roomno == 11) {
        system("cls");
        return;
    }
    
    else{
        printf("\n\n\nYou have entered incorrect option..........");
        getchar();
        getchar();
        goto g;
        }
 return; }
void facility(){
    system("cls");
    title();
    printf("\n\n\n............Available facilities in all rooms are same as given below............");
    printf("\n\n\n        Fully air-conditioned Big Rooms ");
    printf("\n        Attached washroom");
    printf("\n        LED Television");
    printf("\n        Refrigerator");
    printf("\n        Microwave");
    printf("\n        Telephone line local, STD/ISD facilities");
    printf("\n\n\nPress Enter key to go back..........");
    getchar();
    getchar();
    system("cls");}
void bookaroom(){ 
    char age[10];
    char gender[10];
    char first_name[20];
    char last_name[20];
    char contact_number[10];
    char address[50];
    char email[30];
    system("cls");
    title();
    printf("\n\n\n................................     ADD PATIENT RECORDS      ................................");
    printf("\n\n        First name of patient  :   ");
    scanf("%s",&first_name);
    printf("\n        Last name of patient   :   ");
    scanf("%s",&last_name);
    printf("\n        Contact Number         :   ");
    scanf("%s",&contact_number);
    printf("\n        Age                    :   ");
    scanf("%s",&age);
    printf("\n        Gender                 :   ");
    scanf("%s",&gender);
    printf("\n        Address                :   ");
    scanf("%s",&address);
    printf("\n        Email                  :   ");
    scanf("%s",&email);
    printf("\n\n\n        Your room has been booked successfully.\n\n        Press Enter kay to go back..........");
    getchar();
    getchar();
    system("cls");}
void book_appointment(){
    d:
    system("cls");
    FILE*jkl = NULL;
    jkl = fopen("hiib.txt","a");
    printf("\n................................     BOOK APPOINTMENTS      ................................");
    printf("\n\nFirst name of patient  :  ");
    scanf("%s",&appoint.first_name);
    printf("\nLast name of patient  :  ");
    scanf("%s",&appoint.last_name);
    printf("\nContact Number  :   ");
    scanf("%s",&appoint.contact_number);
    printf("\nAppointment Time  :  ");
    scanf("%s",&appoint.age);
    printf("\nAppointment with  :  Dr.  ");
    scanf("%s",&appoint.email);
    printf("\nProblem  :   ");
    scanf("%s",&appoint.gender);
    printf("\nAddress  :   ");
    scanf("%s",&appoint.address1,&appoint.address2);
    fprintf(jkl,"\n %s %s %s %s %s %s %s %s",appoint.first_name,appoint.last_name,appoint.contact_number,appoint.age,appoint.gender,appoint.address1,appoint.address2,appoint.email);
    fclose(jkl);
    printf("\n\n\nAppointment has been booked \n\nPress 1 book more appointment\nPress any number to back      ");
    scanf("%d",&choice);
    if(choice == 1){
        system("cls");
        goto d;
    } 
    else {
        system("cls");
        return;}
        system("cls");}
void view_appointment(){
    system("cls"); 
    printf("\n\n\n.....................................    VIEW BOOK APPOINTMENTS   ......................................");
    FILE*jkl;
    jkl = fopen("hiib.txt","r");
    for(o = 1;fscanf(jkl,"%s %s %s %s %s %s %s %s",appoint.first_name,appoint.last_name,appoint.contact_number,appoint.age,appoint.gender,appoint.address1,appoint.address2,appoint.email) != EOF;o++){
        printf("\n%d::\n",o);
        printf("Name of patient  :  %s %s\n",appoint.first_name,appoint.last_name);
        printf("Appointment with  :  Dr. %s\n",appoint.email);
        printf("Appointment Time  :  %s\n",appoint.age); // stores appointment time
        printf("Problem of patient  :  %s\n",appoint.gender);
        printf("Address of patient  :  %s %s\n",appoint.address1,appoint.address2);
        printf("Contact number of patient  :  %s\n",appoint.contact_number);
        }
        fclose(jkl);
        printf("\n\n\n\nPress enter key to go back ......");
        getchar();
        getchar();
        system("cls");}
int billgen(){
    char name[20],srname[20];
	int num,num1,num2;
	int roomrent;
    system("cls");
    title();
    printf("\n\n\n.............      BILL GENERATOR    ..............");
	printf("\n\nEnter your full name.\n");
	scanf("%s %s", &name,&srname);
	printf("\nEnter no. of days you were at the hospital.\n");
	scanf("%d", &num);
	printf("\nEnter the numbers accordingly:\t(1 if yes and 0 if no.)\n1.\tWere you having your own room?\n");
	scanf("%d", &num1);
	switch (num1)
	{
	case 1:
		roomrent = 5000;
		break;
	case 0:
		roomrent = 1000;
		break;
	default:
		printf("\nWrong number entered.\n");
        getchar();
        getchar();
		return 1;
	}
	printf("\n2.\tWere you admitted in ICU?\n");
	scanf("%d", &num2);
	switch(num2)
	{
    case 0:
        variable1 = 1000*num;
        break;
    case 1:
        icu(num);
        variable1 = 1000*(num-num10);
        break;
    default:
        printf("\nInvalid number entered.\n");
        getchar();
        getchar();
        return 1 ;
	}
	int total = roomrent*num + variable + variable1;
	printf("\nRoom rent: %d\nMedical Services: %d\n%s %s your total bill is: %d",roomrent*num,variable+variable1,name,srname,total);
    printf("\n\nPress Enter kay to go back..........");
    getchar();
    getchar();
	return 0;}
int icu(int num){
     t:
    printf("\nEnter the no. of days you were at the ICU.\n");
    scanf("%d",&num10);
   
    if(num<num10){
        printf("Invalid number entered.\n");
       goto t;
    }
    else{
        switch(num10)
        {
            case 0:
                printf("\nYou have entered an invalid number.\n");
                break;
            default:
            variable = num10*8000;
        }
        // variable1 = 1000*(num-num10);
    }
    
    return num10;}
int cov_pre(){
	int count = 0;
	char ans;
    title();
	printf("\n\t\t\t\tWELCOME TO THE CORONA PREDICTOR SECTION\n\t\t\t HERE YOU WILL BE SHOWN THE SYMPTOMS OF CORONA AND YOU HAVE TO ANSWER YES OR NO \n");
	printf("\n\nBEGIN :\n");
	printf("\n Answer y or yes for Yes and n or no for No if you have any one of them");
	printf("\n1.Cold/Cough/Fever \t");
	scanf("%s",&ans);
	count=predict(ans);
	printf("\n2.Fatigue \t");
    scanf("%s",&ans);
	count=predict(ans);
    printf("\n3.Body ache/ Heahache \t");
    scanf("%s",&ans);
    count=predict(ans);
    printf("\n4.Sore Throat \t");
    scanf("%s",&ans);
	count=predict(ans);
    printf("\n5.Pain in chest while breathing \t");
    scanf("%s",&ans);
	count=predict(ans);
    printf("\n6.Nausea or vomiting \t");
    scanf("%s",&ans);
	count=predict(ans);
	printf("\n7.Diareha\t");
    scanf("%s",&ans);
	count=predict(ans);
	printf("\n8.Trouble in breathing \t");
    scanf("%s",&ans);
	count=predict(ans);
	printf("\n9.Persistent pain or pressure in the chest \t");
    scanf("%s",&ans);
	count=predict(ans);
	printf("\n10.Pale, gray, or blue-colored skin, lips, or nail beds, depending on skin tone \t");
    scanf("%s",&ans);
	count=predict(ans);
	printf("\n You have %d symptoms out of 10\n Your covid prediction is that ",count);
	result(count);
    printf("\n\nPress Enter kay to go back..........");
    getchar();
    getchar();
    system("cls");
    return 0;}
int predict(char a){
	static int c=0;
	if(a=='y')
	{
		c++;
	}
	else
	{
		c+=0;
	}
	return c;}
int result(int b){
	if(b<=4)
	{
		printf("  YOU ARE SAFE and not suffering through CORONA\n");
	}
	else
	{
		printf("   YOU ARE SUFFERING FROM CORONA \n\t\t\t\t  PLEASE VISIT THE NEAREST COVID CENTRE\n");
	}
	return 0;}
void corona(){
    b:
    system("cls");
    title();
    printf("\n\n\t\t......CORONA WARD DETAILS......\n\n"); 
    printf("\n\n      Choose following option to fetch respective details\n\n");
    printf("      1.  Add patient details \n\n");
    printf("      2.  View patient details \n\n");
    printf("      3.  To go back \n\n");
    scanf("%d",&choice);
    if (choice == 1) {
        addpatient();
        goto b;
    }
    if (choice == 2) {
        viewpatient();
        goto b;
    }
    if (choice == 3) return; 
    else {
        printf("\n\nYou have entered wrong option");
        printf("\nPress Enter key to go back");
        getchar();
        getchar();
        system("cls");
    }
     }
void medical(){ 
    char Name[50];
    char Contact[15];
    title();
    printf("\n\t\t\t\tWELCOME TO THE MEDICAL STORE SECTION \n\n");
    gets(Name);
    printf("Name of the patient: %s\n",Name);
    gets(Contact);
    printf("Contact details: %s\n",Contact);
        printf("Select the packages as per the patients\n");
        printf("Select a=1 for normally affected patients\n");
        printf("Select a=2 for severely affected patients\n");
        printf("Select a=3 for critically affected patients\n\n");
        int a;
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("Your Medicine bill is: 9,000 (inclusive of all taxes) \n");
                printf("%-35s\n", "2.Medical expenses:");
                printf("%-2s %-35s %-10s\n", " ", "a.Immunity booster:", "4,000");
                printf("%-2s %-35s %-10s\n", " ", "b.Cough syrup:", "1,000");
                printf("%-2s %-35s %-10s\n", " ", "c.Crocin(fever):", "2,000");
                printf("%-3s %-10s\n", "3.Food:", "2,000");
                printf("\n\nPress Enter kay to go back..........");
                getchar();
                getchar();
                system("cls");
                break;
            case 2:
                printf("Your Medicine bill is: 39,500 (inclusive of all taxes) \n");
                printf("%-35s\n", "1.Medical expenses:");
                printf("\t\ta.Immunity booster = 4,500 \n\n\t\tb.Cough syrup = 1,500 \n\t\tc.Crocin(fever) = 2,500 \n\t\td.Alveoliar(for lungs) = 4,500 \n\t\te.Saline = 2,000  \n\t\tf.Corticosteroid Injections(CSI) = 5,000 \n\t\tg.Remdesivir Injection = 6,000 \n\n2.Food: 3,000 \n3.Ventilator : 5,000 \n");
                printf("\n\nPress Enter kay to go back..........");
                getchar();
                getchar();
                system("cls");
                break;
            case 3:
                printf("Your Medicine bill is: 81,500 (inclusive of all taxes) \n");
                printf("1. Medical expenses: \n\n\t\ta.Immunity booster = 5,500 \n\t\tb.Cough syrup = 2,500 \n\t\tc.Crocin(fever) = 3,500 \n\t\td.Alveoliar(for lungs) = 5,500 \n\t\te.Saline = 4,000  \n\t\tf.Corticosteroid Injections(CSI) = 8,000 \n\t\tg.Remdesivir Injection = 10,000 \n\t\th.Corticosteroid injection = 20,000   \n\n2.Food: 5,000 \n3.Ventilator : 8,000 \n4.Oxygen pumps:10,000 \n\n");
                printf("\n\nPress Enter kay to go back..........");
                getchar();
                getchar();
                system("cls");
                break;
            default:
                printf("The option choosen is incorrect\n\n");
                printf("\n\nPress Enter kay to go back..........");
                getchar();
                getchar();
                system("cls");
        }
    }
