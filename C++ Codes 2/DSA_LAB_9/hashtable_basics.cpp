#include <cstring>
#include <string>
#include <iostream>
using namespace std;

struct HashTable{
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void intialize_hashtable(){
        for (int i = 0; i < MAX_LENGTH; i++){
            password[i].clear();
        }
    }

    bool isFull(){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (password[i].empty()){
                return false;
            }
        }
        return true;
    }

    int hashfunc(string user_name){
        int sum = 0;
        for (int i = 0; i < user_name.size(); i++){
            sum += user_name[i];
        }
        int hash = sum % MAX_LENGTH;
        return hash;
    }

    bool is_slot_empty(int hash){
        return password[hash].empty();
    }

    void insert(string user_name, string user_password){
        int hash = hashfunc(user_name);
        if (is_slot_empty(hash)){
            password[hash] = user_password;
            cout << "Password for user " << user_name << " added." << endl;
        } else {
            cout << "The slot for user " << user_name << " is already taken. Password not added." << endl;
        }
    }

    void hash_lookup(string user_name){
        int hash = hashfunc(user_name);
        if (is_slot_empty(hash)){
            cout << "No password found for user " << user_name << endl;
        } else {
            cout << "Password for user " << user_name << ": " << password[hash] << endl;
        }
    }

    void delete_item(string user_name){
        int hash = hashfunc(user_name);
        if (is_slot_empty(hash)){
            cout << "No item found for user " << user_name << endl;
        } else {
            password[hash].clear();
            cout << "Password for user " << user_name << " deleted." << endl;
        }
    }

    void print_hashtable(){
        for (int i = 0; i < MAX_LENGTH; i++){
            cout << "[" << i << "] --> " << password[i] << endl;
        }
    }

};

int main(){
    HashTable * hashtbl = new HashTable;
    hashtbl->intialize_hashtable();

    int command = 0;
    string user_name;
    string password;

    while (command != -1){
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            cout << "Enter user name to delete: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            cout << "Enter user name to look up password: ";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid command." << endl;
            break;
        }
    }

    return 0;
}
