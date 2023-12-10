#include <iostream>
#include <fstream>

using namespace std;
void underline(){
    cout << "\t\t\t\t\t__________________________________\n";
}

void newLines(int n){
    for(int i=0;i<n;i++){
    cout << "\n";
    }
}


class shopping{
  private:
  int pcode;
  float price;
  float dis;
  string pname;

  public:
  void menu();
  void administrator();
  void buyer();
  void add();
  void edit();
  void rem();
  void list();
  void receipt();

};

void shopping:: menu(){
  m:
  int choice;
  string email;
  string password;

  cout << "\n\t\t\t\t\t__________________________________\n";
  cout << "\t\t\t\t\t                                  \n";
  cout << "\t\t\t\t\t      Supermarket Main Menu       \n";
  cout << "\t\t\t\t\t                                  \n";
  cout << "\t\t\t\t\t__________________________________\n";

  newLines(4);

  cout << "\t\t\t\t\t         1) Administrator         \n";
  cout << "\t\t\t\t\t         2) Customer              \n";
  cout << "\t\t\t\t\t         3) Exit                  \n";
  
  newLines(4);
  
  cout << "\t\t\t\t\t     Please select an option: ";
  cin >> choice;
  
  
switch(choice){
    case 1:{
        underline();
    newLines(3);
    cout << "\t\t\t\t\t\t  Please Login\n\n\n";
    cout << "\t\t\t\t\t Enter Email: ";
    cin >> email;
    cout << "\t\t\t\t\t Password: ";
    cin >> password;
    
    
    
    if(email == "nikesh@gmail.com" && password == "nikesh@123"){
        underline();
      administrator();
      
    }
    else{
     newLines(3);
      cout << "\t\t\t\t\t     Invalid Email/Password.";
      newLines(3);
      cout << "\t\t\t\t\t*********************************\n";
      cout << "\t\t\t\t\t---------------------------------\n";
      cout << "\t\t\t\t\t*********************************";
    }
    break;
    }


    case 2:
    {
      buyer();
      break;
    }


    case 3:
    {
      exit(0);
      break;
    }


    default:
    {
        newLines(3);
      cout << "\t\t\t\t\tInvalid Command. Please select from the given options.\n";
      underline();
    }
  }
  newLines(6);
  goto m;
}

void shopping:: administrator(){
  m:
    int choice;
    newLines(3);
    cout << "\t\t\t\t\t\tAdministrator Menu";
    newLines(3);
    cout <<"\t\t\t\t\t      1) Add a Product";
    cout << "\n\t\t\t\t\t      2) Modify a Product";
    cout << "\n\t\t\t\t\t      3) Delete a Product";
    cout << "\n\t\t\t\t\t      4) Back to Main Menu";
    newLines(4);
    cout << "\n\t\t\t\t\t    Please select an option: ";
    cin >> choice;
    underline();

    switch(choice){
      case 1:
      add();
      break;

      case 2:
      edit();
      break;

      case 3:
      rem();
      break;
    
      case 4:
      newLines(2);
      cout << "\t\t\t\t\t*********************************\n";
      cout << "\t\t\t\t\t---------------------------------\n";
      cout << "\t\t\t\t\t*********************************";
      newLines(1);
      menu();
      break;

      default:
      cout << "Invalid Choice. \n" ;
    }
    goto m;
}

void shopping:: buyer(){
  m:
  int choice;
    underline();
    newLines(3);
  cout << "\t\t\t\t\t\t   Customer Menu";
  newLines(3);
    cout <<"\t\t\t\t\t      1) Buy a Product";
    cout << "\n\t\t\t\t\t      2) Go Back";
    newLines(4);
    cout << "\t\t\t\t\t    Please select an option: ";
    cin >> choice;

    switch(choice){
    case 1:
    underline();
    receipt();
    break;

    case 2:
    newLines(2);
      cout << "\t\t\t\t\t*********************************\n";
      cout << "\t\t\t\t\t---------------------------------\n";
      cout << "\t\t\t\t\t*********************************";
      newLines(1);
      menu();
    break;

    default: 
    newLines(4); 
    cout << "\t\t\t\t\t\tInvalid Command.\n";
    
    goto m;
    }

}






void shopping::add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    
    newLines(3);
    cout << "\n\t\t\t\t\t\t  Add New Product";
    newLines(3);
    cout << "\n\t\t\t\t\t  *) Enter Product Code: ";
    cin >> pcode;
    cout << "\n\t\t\t\t\t  *) Enter Name of the Product: ";
    cin >> pname;
    cout << "\n\t\t\t\t\t  *) Enter price of the Product: ";
    cin >> price;
    cout << "\n\t\t\t\t\t  *) Enter discount on the Product: ";
    cin >> dis;
    

    data.open("database.text",ios::in);

    if(!data){
      data.open("database.txt",ios::app|ios::out);
      data << " " << pcode<<" " << pname<<" " << price<<" " << dis<<"\n";
      data.close();
    }
    else{
      data >> c >> n >> p >> d;

      while(!data.eof()){
        if(c == pcode){
        token++;
        }
        data >> c >> n >> p >>d;
      }
      data.close();
    
    
    
    if(token == 1){
      goto m;
    }
    else{
      data.open("database.txt",ios::app|ios::out);
      data << " " << pcode<<" " << pname<<" " << price<<" " << dis<<"\n";
      data.close();
    }
    }
    newLines(4);
    cout << "\t\t\t\t\t        Record Inserted!\n";
    underline();
}








void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    
    newLines(3);
    cout << "\n\t\t\t\t\t\t  Modify the Record";
    newLines(3);
    cout << "\n\t\t\t\t\t  Enter the Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if(!data){
        newLines(4);
      cout << "\t\t\t\t\t        No records found to Modify!\n";
      underline();
    }
    else{
      data1.open("database1.txt",ios::app|ios::out);
      data >>pcode>>pname>>price>>dis;
      while(!data.eof()){
        if(pkey == pcode){
          cout << "\n\t\t\t\t\t  *) Enter new product code: ";
          cin >> c;
          cout << "\n\t\t\t\t\t  *) Enter modified name of the Product: ";
          cin >> n;
          cout << "\n\t\t\t\t\t  *) Enter new price of the Product: ";
          cin >> p;
          cout << "\n\t\t\t\t\t  *) Enter new discount on the Product: ";
          cin >> d;
          data1 << " " << c << " " << n <<" " << p << " " << d << "\n";
          newLines(4);
            cout << "\t\t\t\t\t        Record Modified!\n";
            underline();
          token ++;
        }
        else{
          data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
        data >> pcode >> pname >> price >> dis;
      }
      data.close();
      data1.close();

      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token == 0){
          newLines(4);
        cout << "\t\t\t\t\t        Record not Found!\n";
        underline();
      }
    }
}


void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    newLines(3);
    cout << "\n\t\t\t\t\t\t  Delete product";
    newLines(3);
    cout << "\n\t\t\t\t\t  Product code: ";
    cin >> pkey;
    data.open("database.txt",ios:: in);
    if(!data){
        newLines(4);
      cout << "\t\t\t\t\t        No records present to delete!\n";
      underline();
    }
    else{
      data1.open("database1.txt",ios::app|ios::out);
      data >> pcode >> pname >> price >> dis;
      while(!data.eof()){
        if(pcode == pkey){
            newLines(4);
          cout << "\t\t\t\t\t    Product deleted successfully.\n";
          underline();
          token ++;
        }
        else {
          data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
        data >> pcode >> pname >> price >> dis;
      }
      data.close();
      data1.close();
      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token == 0){
          newLines(4);
        cout << "\t\t\t\t\t        Record not found\n";
        underline();
      }
    }
}




void shopping :: list(){
  fstream data;
  data.open("database.txt",ios::in);
  cout << "\t\t\t\t\t__________________________________\n";
  cout << "\t\t\t\t\tProduct No \t Name \t  Price \n";
  cout << "\t\t\t\t\t__________________________________\n";
  data >> pcode >> pname >> price >> dis;
  while (!data.eof()){
      cout << "\t\t\t\t\t";
    cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
    data >> pcode >> pname >> price >> dis;
  }
  newLines(4);
  data.close();
}




void shopping :: receipt(){
  fstream data;

  int arrc[100];
  int arrq[100];
  char choice;
  int c = 0;
  float amount = 0;
  float dis = 0;
  float total = 0;

newLines(3);
  cout << "\t\t\t\t\t\t  Item List";
  newLines(3);
  data.open("database.txt",ios::in);
  if(!data){
      newLines(4);
    cout << "\t\t\t\t\t Empty database. Nothing to Buy.\n";

  }
  else{
    data.close();

    list();
    cout << "\n\t\t\t\t\t__________________________________\n";
    cout << "\n\t\t\t\t\t      Please place your order     \n";
    cout << "\t\t\t\t\t__________________________________\n";

    do
    {
      m:
      newLines(2);
      cout << "\t\t\t\t\t  Enter the product code: ";
      cin >> arrc[c];
      cout << "\n\t\t\t\t\t  Enter the quantity: ";
      cin >> arrq[c];
      for(int i=0; i<c; i++){
        if(arrc[c] == arrc[i]){
            newLines(1);
          cout << "\t\t\t\t\tDuplicate product code. Please try again.\n\n\n\n";
          goto m;
        }
      }
      c++;
      newLines(4);
      cout << "\t\t\t Do you want to buy another product? If yes then press 'y' else 'n'.\n";
      cout << "\t\t\t\t\t\t----> ";
      cin >> choice;
    } while (choice == 'y');

    
    underline();
    newLines(5);
    cout << "\t\t\t\t\t\t   RECEIPT\n";
    cout << "\t\t\t_____________________________________________________________________________________________\n";
    cout << "\t\t\tProduct No \t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount \n";
    cout << "\t\t\t_____________________________________________________________________________________________\n";

    for(int i =0;i<c;i++){
      data.open("database.txt",ios::in);
      data >> pcode >> pname >> price >> dis;
      while (!data.eof()){
        if(pcode == arrc[i]){
          amount = price*arrq[i];
          dis = amount - (amount * dis/100);
          total = total + dis;
          cout << "\n\t\t\t" << pcode <<"\t\t " << pname <<"\t\t\t" << arrq[i] <<"\t\t " << price <<"\t " << amount <<"\t\t" << dis;
        }
        data >> pcode >> pname >> price >> dis;
      }
    }
    data.close();
  }
  cout << "\n\t\t\t_____________________________________________________________________________________________\n";
  cout << "\t\t\t\t\t\tTotal Amount: " << total;
  cout << "\n\t\t\t_____________________________________________________________________________________________\n";
  newLines(5);
      cout << "\t\t\t\t\t*********************************\n";
      cout << "\t\t\t\t\t---------------------------------\n";
      cout << "\t\t\t\t\t*********************************";
}




int main(){
shopping s;
s.menu();
return 0;
}