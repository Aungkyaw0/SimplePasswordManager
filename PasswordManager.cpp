//Developeded BY AKT 2/10/2022
#include <iostream>
#include <string.h>
#include <fstream>
#define SIZE 100
#define FILE "pass3.txt"
using namespace std;
typedef unsigned int usi;
int m_size = 0;
char file[SIZE];
void clear()
{
    system("clear");//Change clear to cls if you are using window instead of linux
}
void Enter()
{
    cout << "\n--------- Press Enter To Continue ----------\n";    
    cin.clear();
    cin.ignore();
    char test = 'x';
    while (test != '\n')
    {
        cin.get(test);
    }
}
class Master
{
    protected:
        char masterEmail[SIZE];
        char masterPass[SIZE];  
    public:
        void setData(char email[SIZE], char pass[SIZE])
        {
            strcpy(masterEmail, email);
            strcpy(masterPass, pass);
        }
        void view()
        {
            cout << "MasterEmail ::> " << this->masterEmail << endl;
            cout << "Master Password ::> " << this-> masterPass << endl;  
        }
        void wrote();
        int checkCredential(char fName[]);
        

        
};

class PM
{
    private:
        int id;
        char Desciption[SIZE];
        char userName[SIZE];
        char userEmail[SIZE];
        char userPass[SIZE];
    public:
        PM()
        {
            id = 0;
        }
        int CheckFile(char file[]);
        void MainMenu();
        void Register();
        void checkEmail();
        void Login();
        void ChangeMP();
        void userMenu();
        ///Method For UserMenu
        void printData();
        int idHandle();
        void AddData();
        void DataHandle(int status);
        void ViewData();
        void ViewAllData();
        void UpdateData();
};  
//Methods From Master
void Master::wrote()
{
    strcat(file, ".");
    strcat(file, this->masterEmail);
    strcat(file, ".db");
    //cout << "FIleName ::> " << file << endl;
    fstream obj;
        obj.open(file, ios::binary | ios::out);
        if(!obj)
        {
            cout << "Sorry Can't Open File";
        }
        else
        {
            Master tmp2;
            strcpy(tmp2.masterEmail, this->masterEmail);
            strcpy(tmp2.masterPass, this->masterPass);
            obj.write((char *)&tmp2, sizeof(tmp2));
            cout << "Creating user Successfull" << endl;
            Enter();
        }
        obj.close();
}

int Master::checkCredential(char fName[])
{
    
    int status = 404;
    usi u_status = 0, p_status = 0;
    Master tmp;
    fstream obj;
    obj.open(fName, ios::binary | ios::in);
    if(!obj)
    {
        cout << "\n!!!! There is not Data For Useremail :: " << this->masterEmail << "!!!!" << endl;
        Enter();
    }
    else
    {
        obj.read((char *)&tmp, sizeof(tmp));
        if(strcmp(this->masterEmail, tmp.masterEmail) == 0)
        {
            u_status = 1;
            if(strcmp(this->masterPass, tmp.masterPass) == 0)
            {
                clear();
                cout << "Welcome User :: " << this->masterEmail << endl;
                m_size = sizeof(tmp);
                status = 200;
                Enter();
            }
            else
            {
                cout << "Password Is Not Correct" << endl;
            }
        }
        if(u_status == 0)
        {
            cout << "Invalid User Email" << endl;
        }
    
    obj.close();
    }

    return status;
}

//Methods From PM
int PM::CheckFile(char f[])
{
    char file_name[SIZE] = "";
    char *p;
    p = file_name;
    strcat(file_name, ".");
    strcat(file_name, f);
    strcat(file_name, ".db");
   
    ifstream obj;
    int i = 0;
    obj.open(file_name, ios::binary | ios::in);
    if(obj)// if user exist
    {
        i = 404;
    }
    else
    {
        i = 200;
    }
    obj.close();
    while(*p != '\0')
    {
        strcpy(p, "\0");
        p++;
    }
    
    return i;
}

void PM::MainMenu()
{   usi op = 0;
    while(true)
    {
        clear();
        cout << "Welcome From Password Manager\n--------------------------------\n";
        cout << "1. Register\n2. Login\n3. Change Password\n4. Exit\nEnter the option ::> ";
        cin >> op;
        switch(op)
        {
            case 1:
                Register();
                break;
            case 2:
                Login();
                break;
            case 3: 
                break;
            case 4:
                exit(1);
                break;
            default:
                break;
        }
    }
}
void PM::Register()
{
    int check_usr_name = 0;
    char rEmail[SIZE];
    char rPass[SIZE], cpass[SIZE];
    cin.clear();cin.ignore();
    cout << "Enter the email ::> ";
    cin.getline(rEmail, SIZE);
    cout << "Enter the password ::> ";
    cin.getline(rPass, SIZE);
    cout << "Enter confirm password ::> ";
    cin.getline(cpass, SIZE);
    if(strcmp(rPass, cpass) != 0)
    {
        cout << "!!Your passwords are not match Each Other!!" << endl;
        cout << "!!PLEASE REGISTER AGAIN!!";
        Register();
    }
    check_usr_name = CheckFile(rEmail);
    //If Success
    if(check_usr_name == 200)
    {
        Master regi;
        regi.setData(rEmail, rPass);
        regi.wrote();
        MainMenu();
    }
    else
    {
        cout << "Sorry UserEmail \"\"" << rEmail << "\"\" existed in the system" << endl;
        Enter();
    }
}

void PM::Login()
{
    clear();
    char ff[SIZE] = "";
    int lstatus = 0;
    char lEmail[SIZE], lPass[SIZE];
    cout << "Welcome From Login Panel\n----------------------\n";
    cin.clear();cin.ignore();
    cout << "Enter the email ::> ";
    cin.getline(lEmail, SIZE);
    cout << "Enter the password ::> ";
    cin.getline(lPass, SIZE);
    if(ff[0] == '\0')
    {
        printf("Same");
        strcat(ff, ".");
        strcat(ff, lEmail);
        strcat(ff, ".db");
        if(file[0] == '\0')
        {
            strcpy(file, ff);
        }
    }
    
    //strcat(file, ".");
    //strcat(file, lEmail);
    //strcat(file, ".db");
    Master tmp1;
    tmp1.setData(lEmail, lPass);
    lstatus =  tmp1.checkCredential(ff);
    if(lstatus == 200)
    {
        userMenu();
    }
    
}

void PM::userMenu()
{
    usi u_op = 0;
    
    while(true)
    {
        clear();
        cout << "Welcome From DataBase\n--------------------\n";
        cout << "1. Add New Data\n2. View Data\n3. View All Data\n4. Update Data\n5. Exit" << endl;
        cout << "Enter the option ::> ";
        cin >> u_op;
        if(u_op == 1)
        {
            AddData();
        }
        else if(u_op == 2)
        {
            DataHandle(1);
        }
        else if(u_op == 3)
        {
            ViewAllData();
        }
        else if(u_op == 4)
        {
            DataHandle(2);
        }
        else if(u_op == 5)
        {
            break;
            MainMenu();
        }

    }
}
void PM::printData()
{
    cout << "\n";
    cout << "ID ::> " << this->id << endl;
    cout << "Description ::> " << this->Desciption << endl;
    cout << "UserName ::> " << this->userName << endl;
    cout << "Email ::> " << this->userEmail << endl;
    cout << "Password ::> " << this->userPass << endl;
};

int PM::idHandle()
{
    int x = 0;
    fstream obj;
    obj.open(file, ios::binary | ios::in);
    if(!obj)
    {
        cout << "Can't Open IN ID";
    }
    else
    {
        PM tmp;
        obj.seekp(0);
        obj.seekp(m_size);
        while(true)
        {
            if(obj.eof())
            {
                break;
            }
            obj.read((char *)&tmp, sizeof(tmp));
        }
        obj.close();
        x = tmp.id;
    }
    return x + 1;
}

void PM::AddData()
{
    usi loo = 1;
    PM tmp1;
    while(loo)
    {
        clear();
        char c = 'a';
        cin.clear();
        cin.ignore();
        cout << "Welcome From Adding Data\n--------------------------\n";
        tmp1.id = tmp1.idHandle();
        cout << "Enter the description ::> ";
        cin.getline(tmp1.Desciption, SIZE);
        cout << "Enter the username ::> ";
        cin.getline(tmp1.userName, SIZE);
        cout << "Enter the email ::> ";
        cin.getline(tmp1.userEmail, SIZE);
        cout << "Enter the password ::> ";
        cin.getline(tmp1.userPass, SIZE);
        tmp1.printData();
        cout << "Are you sure to write this data to database (y,n)::> ";
        cin >> c;
        if(c == 'y' || c == 'Y')
        {
            fstream obj;
            obj.open(file, ios::app);
            if(!obj)
            {
                cout << "Sorry Can't Open FIle";
                break;
            }
            else
            {
                obj.write((char *)&tmp1, sizeof(tmp1));
                cout << "----------Adding Success-----------";
                Enter();
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void PM::ViewAllData()
{
    PM tmp;
    fstream obj;
    obj.open(file, ios::binary | ios::in);
    if(!obj)
    {
        cout << "Sorry Can't Open File";

    }
    else
    {
        
        obj.seekp(0);
        obj.seekp(m_size);
        while(true)
        {
            obj.read((char *)& tmp, sizeof(tmp));
            if(obj.eof())
            {
                break;
            }
            
            tmp.printData();
            cout << "\n";
            
        }
        Enter();
        
        
    }


}

void PM::DataHandle(int status)
{
    while(1)
    {
        clear();
        cout << "Welcome From Credential Database\n---------------------------------------" << endl;
        cout << "Available Description ::> ";
        fstream obj;
        obj.open(file, ios::binary | ios:: in);
        if(!obj)
        {
            cout << "Sorry Can't Open File";
        }
        else
        {
            PM tmp;
            char choice = 'a';
            usi dStatus = 0;
            int counter = 0;
            char des[SIZE];
            obj.seekg(m_size, ios::beg);
            while(1)
            {

                obj.read((char *)&tmp, sizeof(tmp));
                if(obj.eof())
                {
                    break;
                }
                cout << tmp.Desciption << ", ";

            }
            obj.close();
            cout << "\n";
            obj.open(file, ios::binary | ios::in);
            obj.seekg(m_size, ios::beg);
            cout << "Enter the description name to view ::> ";
            cin.clear();cin.ignore();
            cin.getline(des, SIZE);
            
            while(1)
            {
                obj.read((char *)&tmp, sizeof(tmp));
                if(obj.eof())
                {
                    break;
                }
                if(strcmp(tmp.Desciption, des) == 0)
                {
                    dStatus = 1;
                    break;
                }        
                counter++;
            }
            obj.close();
            //View Data
            if(dStatus == 1 && status == 1)//1 For ViewData
            {
                cout << "\nData For " << tmp.Desciption << "\n----------------------" << endl;
                cout << "Username ::> " << tmp.userName << endl;
                cout << "Email ::> " << tmp.userEmail << endl;
                cout << "Password ::> " << tmp.userPass << endl;
            }
            //Update Data
            else if(dStatus == 1 && status == 2)
            {
                char insert = 'a';
                
                cout << "Before Data Change\n---------------\n";
                cout << "ID ::> " << tmp.id << endl;
                cout << "Username ::> " << tmp.userName << endl;
                cout << "Email ::> " << tmp.userEmail << endl;
                cout << "Password ::> " << tmp.userPass << endl;
                cout << "Updating Data......\n--------------------\n";
                cout << "ID ::> " << tmp.id << endl;
                cout << "Enter the new Description ::> ";
                cin.getline(tmp.Desciption, SIZE);  
                cout << "Enter the new UserName ::> ";
                cin.getline(tmp.userName, SIZE);
                cout << "Enter the new email ::> ";
                cin.getline(tmp.userEmail, SIZE);
                cout << "Enter the new password ::> ";
                cin.getline(tmp.userPass, SIZE);
                cout << "Are you sure to update this data (y,n) ::> ";
                cin >> insert;
                if(insert == 'y' || insert == 'Y')
                {
                    obj.open(file, ios::in | ios::binary | ios::out);
                    obj.seekp(m_size, ios::beg);
                    obj.seekp((sizeof(tmp) * (counter)), ios::cur);
                    obj.write((char *)&tmp, sizeof(tmp));
                    cout << "---------Updating Done--------------" << endl;
                }
            
            }
            else
            {
                cout << "There is not data for Description \"\"" << des << "\"\"" << endl;
                break; 
            } 
            cout << "Do you want to try again (y,n)::> ";     
            cin >> choice;
            if(choice == 'n' || choice == 'N')
            {
                break;
            }
        }
    }
}




int main()
{
    PM _obj;
    _obj.MainMenu();
}
