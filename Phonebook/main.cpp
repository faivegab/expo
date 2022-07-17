#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

 class contact{
    private:

          char fname[15], lname[15], address[50], email[25];
             long long phoneno;

    public:

        void createcontact(){

         cout << "Enter your first name: ";
         cin  >> fname;

         cout << "Enter your last name: ";
         cin  >> lname;

         cout << "Enter your address: ";
         cin  >> address;

         cout << "Enter your email: ";
         cin  >> email;

         cout << "Enter your mobile number: ";
         cin  >> phoneno;
        }

     void showcontact(){

       cout << "Name: " << fname << " " << lname   << endl;
       cout << "Phone Number: "  << phoneno << endl;
       cout << "Email Address: " << email   << endl;
       cout << "House Address: " << address << endl;
       }

    void savecontact(){

      char ch;
      ofstream f1;
      f1.open("CMS.dat", ios::binary | ios::app);

      do{
            createcontact();
          f1.write(reinterpret_cast<char*>(this), sizeof(*this));
          cout << "Do you have next data to input?(Y/N)";
          cin >> ch;
          } while(ch=='Y');
          cout << "Contact has been successfully created...";
          f1.close();
          }


     void readfromfile(){

       ifstream f2;
       f2.open("CMS.dat", ios::binary);

       cout << "\n************************************\n";
       cout <<           "List of contact";
       cout << "\n************************************\n";

       while(!f2.eof()){
        if(f2.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            showcontact();
            cout << "\n********************************";
              }
        }
          f2.close();
        }


     void searchonfile(){

         ifstream f3;
         long long phone;
         cout << "Enter phone number: ";
         cin >> phone;

         f3.open("CMS.dat", ios::binary);

         while(!f3.eof()){
            if(f3.read(reinterpret_cast<char*>(this), sizeof(*this)))
         {
             if(phone == phoneno){
                showcontact();
                return;
             }
         }
        } cout << "\n\nNo record found!";
          f3.close();
          }


     void deletecontact() {

         long long phone;
         int flag = 0;

         ofstream f4;
         ifstream f5;

         f5.open("CMS.dat", ios::binary);
         f4.open("temp.dat", ios::binary);

         cout << "Enter the phone number to delete: ";
         cin >> phone;

         while(!f5.eof()){
            if(f5.read(reinterpret_cast<char*>(this), sizeof(*this))){
                if(phoneno != phone){
                    f4.write(reinterpret_cast<char*>(this), sizeof(*this));

                } else flag =1;
                }
            }
              f5.close();
              f4.close();
            remove("CMS.dat");
            rename("temp.dat", "CMS.dat");
            flag == 1;
            }


     void editcontact(){

       long long phone;
       fstream f6;

       cout << "Edit Contact ";
       cout << "\n********************************";
       cout << "\nEnter the phone number to edit:  ";
       cin  >> phone;

       f6.open("CMS.dat", ios::binary|ios::out|ios::in);

       while(!f6.eof()){

        if(f6.read(reinterpret_cast<char*>(this), sizeof(*this))){

            if(phone == phoneno){

                cout << "Enter new record:\n ";
                 createcontact();

                int pos = -1*sizeof(*this);
                f6.seekp(pos, ios::cur);
                f6.write(reinterpret_cast<char*>(this), sizeof(*this)) ;
                cout << endl << endl << "Contact has successfully been updated!";
                return;
            }
        }
       }
     cout << "\n\nNo record found!";
     f6.close();

     }
     };

     int main(){
     system("cls");
     system ("color 09");

     cout <<"\n\n\n\nWelcome to Ced's Phonebook Management System...";
     getch();

     while(1){
        contact c1;
        int choice;
        system ("cls");
        system ("color 03");

        cout << "\nCONTACT MANAGEMENT SYSTEM";
        cout << "\n MAIN MENUE";
        cout << "\n***************************\n";
        cout << "\n[1] Add new contact";
        cout << "\n[2] List all contact";
        cout << "\n[3] Search for contact";
        cout << "\n[4] Delete a contact";
        cout << "\n[5] Edit a contact";
        cout << "\n[0] Exit ";
        cout << "\n***************************\n";
        cout << "\n Enter your choice";
        cin >> choice;

        switch(choice){
            case 1: system("cls");
            c1.createcontact();
            break;

            case 2: system("cls");
            c1.readfromfile();
            break;

            case 3:system("cls");
            c1.searchonfile();
            break;

            case 4: system("cls");
            c1.deletecontact();
            break;

            case 5: system("cls");
            c1.editcontact();
            break;

            case 0: system("cls");
            cout << "Thank you for using Ced's Phonebook Manegement System..." << endl << endl;
            exit(0);
            break;
            default:
            continue;
            }
            int opt;
            cout << "\n\nEnter the choice:\n[1]\t\t[0]Exit\n";
            cin >> opt;

            switch(opt){
            case 0: system("cls");
            cout << "Thank you for using Ced's Phonebook Manegement System..." << endl << endl;
            exit(0);
            break;
            default:
            continue;


            }

     }
     return 0;
     }
