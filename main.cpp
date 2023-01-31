#include <iostream>
#include <string>
#include <vector>
#include <map>


class Phone{
public:
    std::string command;
    std::map<std::string, std::vector <std::string>> phoneBook_name;
    std::map<std::string, std::string> phoneBook_phone;

    void add(){
        std::cout<<"If you want add new contact input 'n'. If you want add phone number to existing contact input 'e'"
        <<std::endl;
        std::cin>>command;

        if(command=="n"){
            std::string oneNumber;
            std::vector<std::string> numbers;
            std::cout<<"Please input contact's name:"<<std::endl;
            std::cin.sync();
            std::getline(std::cin,command);
            std::cout<<"Please input contact's number:"<<std::endl;
            std::cin>>oneNumber;
            numbers.resize(1);
            numbers.push_back(oneNumber);
            phoneBook_phone.insert(std::pair<std::string, std::string>(oneNumber, command));
            phoneBook_name.insert(std::pair<std::string, std::vector <std::string>>(command, numbers));

        }else if(command=="e"){
            std::cout<<"Please input contact's name:"<<std::endl;
            std::cin>>command;
            auto searchNumber = phoneBook_name.find(command);

            if (searchNumber==phoneBook_name.end()) {
                std::cout<<"Contact not found!"<<std::endl;
            }else{
                std::cout << "Input number to add" << std::endl;
                std::cin >> command;
                searchNumber->second.push_back(command);
            }
        }
    }
    void call(){

    }
    void sms(){

    }
};

int main(){

    Phone myPhone;
    int i=0;

    while(i<5){
        myPhone.add();
        i++;
    }

    for (auto it=myPhone.phoneBook_name.begin(); it!=myPhone.phoneBook_name.end(); it++){

        std::cout << it->first << std::endl;

        for(int i = 0; i<it->second.size();i++){
            std::cout << it->second[i] << std::endl;
        }

    }

    for (auto at=myPhone.phoneBook_phone.begin(); at!=myPhone.phoneBook_phone.end(); at++){

        std::cout << at->first << " " << at->second << std::endl;

    }

    return 0;

}