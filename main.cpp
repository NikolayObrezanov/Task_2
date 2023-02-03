#include <iostream>
#include <string>
#include <vector>
#include <map>


class Phone{
public:
    std::string command;
    std::map<std::string, std::vector <std::string>> phoneBook_name;
    std::map<std::string, std::string> phoneBook_phone;

    void input(){
        std::cin.sync();
        std::getline(std::cin,command);
    }
    void chooseNumber(std::string phrase){
        auto searchNumber = phoneBook_name.find(command);
        if(searchNumber==phoneBook_name.end()){
            std::cout<<"Contact wasn't find."<<std::endl;
        }else if(searchNumber->second.size()>1){
            int row;
            for (int i = 0; i<searchNumber->second.size(); i++) {
                std::cout << i + 1 << ". " << searchNumber->second[i] << std::endl;
            }
            std::cout<<"Please choose contact's number. Input number's number in the row."<<std::endl;
            std::cin >> row;
            std::cout<< phrase << searchNumber->second[row-1] << std::endl;
        }else{
            std::cout<< phrase << searchNumber->second[0] << std::endl;
        }
    }
    void add(){
        std::cout<<"If you want add new contact input 'n'. If you want add phone number to existing contact input 'e'"
        <<std::endl;
        std::cin>>command;

        if(command=="n"){
            std::string oneNumber;
            std::vector<std::string> numbers;
            std::cout<<"Please input contact's name:"<<std::endl;
            input();
            std::cout<<"Please input contact's number:"<<std::endl;
            std::cin>>oneNumber;
            numbers.resize(0);
            numbers.push_back(oneNumber);
            phoneBook_phone.insert(std::pair<std::string, std::string>(oneNumber, command));
            phoneBook_name.insert(std::pair<std::string, std::vector <std::string>>(command, numbers));

        }else if(command=="e"){
            std::cout<<"Please input contact's name:"<<std::endl;
            input();
            auto searchNumber = phoneBook_name.find(command);

            if (searchNumber==phoneBook_name.end()) {
                std::cout<<"Contact not found!"<<std::endl;
            }else{
                std::cout << "Input number to add" << std::endl;
                std::cin >> command;
                searchNumber->second.push_back(command);
                phoneBook_phone.insert(std::pair<std::string, std::string>(command, searchNumber->first));
            }
        }
    }
    void call(){
        std::cout<<"Please input contact's name or number for call:"<<std::endl;
        input();
        char *check = &command[0];
        if(check[0]=='+' && check[1]=='7'){
            std::cout<<"CALL: "<< command << std::endl;
        }else {
            chooseNumber("CALL: ");
        }
    }
    void sms(){
        std::cout<<"Please input contact's name or number for sms:"<<std::endl;
        input();
        char *check = &command[0];
        if(check[0]=='+' && check[1]=='7'){
            std::cout<<"Please input SMS to number: "<< command << std::endl;
            input();
            std::cout<<"SMS sent!" << std::endl;
        }else {
            chooseNumber("Please input SMS to number: ");
            input();
            std::cout<<"SMS sent!" << std::endl;
        }
    }
};

int main(){

    Phone myPhone;

    while(myPhone.command!="e"){
        std::cout<<"If you want add new contact input 'add'. For call input 'call'. For sms input 'sms'. For exit - 'e'"
            <<std::endl;
        std::cin>>myPhone.command;
        if(myPhone.command=="add"){
            myPhone.add();
        }else if(myPhone.command=="call"){
            myPhone.call();
        }else if(myPhone.command=="sms"){
            myPhone.sms();
        }
    }

    return 0;

}