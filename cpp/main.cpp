#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> split(string s, char del) {
    vector<string> arr;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        arr.push_back(word);
    }
    return arr;
}
int indexOf(vector<string> arr, string item) { 
    auto it = find(arr.begin(), arr.end(), item);
    if (it != arr.end()) { 
        int index = it - arr.begin(); 
        return index;
    } 
    else { 
        return 0;
    } 
} 
string var(vector<string> valsV, vector<string> namesV, string content) {
    vector<string> list = split(content, '|');
    bool isString = true;
    string val = "";
    for(int i = 0; i < list.size(); i++) {
        if(isString == true) {
            val += list[i];
        } else {
            val += valsV.at(indexOf(namesV,list[i]));
        }
        isString = !isString;
    }
    return val;
}
int main() {
    vector<string> names;
    names.push_back("");
    names.push_back(":p");
    names.push_back(":n");
    vector<string> vals;
    vals.push_back("undefined");
    vals.push_back("|");
    vals.push_back("\n");
    string username;
    string userpasswd;
    string password;
    string cmd;
    cout << "Welcome to CST Terminal, c++ version.\nThis document is the intellectual property of @Cesium72, @sevinATEnine, and @sevinATEnine-alt\n\n";
    ifstream config(".cstconf");
    if(!config) {
        config.close();
        cout << "Welcome to cst! It seems like it's your first time! Please enter a username (no spaces): ";
        cin >> username;
        cin.ignore(256, '\n');
        cout << "Welcome, " << username << "! Please enter a password to guard your account (also no spaces): ";
        cin >> userpasswd;
        cin.ignore(256, '\n');
        cout << "Awesome! You're all set up now. If you ever need a list of commands, type 'help'\n";
        ofstream config(".cstconf");
        config << username << "\n" << userpasswd;
        config.close();
    } else {
        getline(config,username);
        getline(config,userpasswd);
        config.close();
        cout << "Welcome back, " << username << "!\n";
    }
    login:
    cout << "Enter password: ";
    getline(cin,password);
    if(password != userpasswd) {
        cout << "Invalid \n";
        goto login;
    }
    cout << "Login successful.\n\n";
    command:
    cout << "CST/" << username << "-->";
    getline(cin, cmd);
    vector<string> cmdSplit = split(cmd, ' ');
    if(cmdSplit[0] == "help") {
        cout << "Note: all relative filepaths are based on the directory of this program.\n\nhelp: prints list of commands\ncreate [filename]: creates or truncates file 'filename'\necho [text...] returns 'text'\ndrop [filepath]: deletes file 'filepath'\nread [filepath]: reads file of 'filepath'\nbash [command]: executes terminal command 'command'\nquit: closes terminal\ndrop-alias [alias]: deletes alias with name 'alias'\nalias [name] [value...]: creates alias of 'name' with value 'value'\nappend [filepath] [text...]: appends 'text' to file 'filepath'\nappendl [filepath] [text...]: appends 'text' and newline to file 'filepath'\nset-pswrd [cur] [new]: changes password to 'new.' current password 'cur' must be specified\nset-name [cur] [new]: changes name to 'new.' current password 'cur' must be specified\nreset [password]: RESETS TERMINAL!!! Password must be specified!";
    } else if(cmdSplit[0] == "quit") {
        return 0;
    } else if(cmdSplit[0] == "set-pswrd") {
        if(cmdSplit[1] == userpasswd) {
            userpasswd = cmdSplit[2];
            ofstream config(".cstconf");
            config << username << "\n" << userpasswd;
            config.close();
            cout << "Password reset";
        } else {
            cerr << "Error 06: Authentication failed.";
        }
    } else if(cmdSplit[0] == "set-name") {
        if(cmdSplit[1] == userpasswd) {
            username = cmdSplit[2];
            ofstream config(".cstconf");
            config << username << "\n" << userpasswd;
            config.close();
            cout << "Name reset";
        } else {
            cerr << "Error 06: Authentication failed.";
        }
    } else if(cmdSplit[0] == "reset") {
        if(cmdSplit[1] == userpasswd) {
            string path = ".cstconf";
            remove(path.c_str());
            cout << "Terminal reset\n";
            return 0;
        } else {
            cerr << "Error 06: Authentication failed.";
        }
    } else if(cmdSplit[0] == "bash") {
        string orig = var(vals,names,cmd.substr(5));
        char script[orig.length() + 1];
        strcpy(script, orig.c_str());
        system(script);
    } else if(cmdSplit[0] == "alias") {
        names.push_back(var(vals,names,cmdSplit[1]));
        vals.push_back(var(vals,names,cmd.substr(7 + cmdSplit[1].length())));
    } else if(cmdSplit[0] == "drop-alias") {
        int idx = indexOf(names, var(vals,names,cmdSplit[1]));
        names.erase(names.begin() + idx);
        vals.erase(vals.begin() + idx);
    } else if(cmdSplit[0] == "echo") {
        cout << var(vals,names,cmd.substr(5));
    } else if(cmdSplit[0] == "append") {
        ofstream file(var(vals,names,cmdSplit[1]), ios::app);
        if(file) {
        file << var(vals,names,cmd.substr(8 + cmdSplit[1].length()));
        cout << "'" << var(vals,names,cmd.substr(8 + cmdSplit[1].length())) << "' appended to file '" << var(vals,names,cmdSplit[1]) << "' successfully.";
        } else {
            cerr << "Error 05: Unable to append to file";
        }
        file.close();
    } else if(cmdSplit[0] == "appendl") {
        ofstream file(var(vals,names,cmdSplit[1]), ios::app);
        if(file) {
        file << var(vals,names,cmd.substr(8 + cmdSplit[1].length())) << "\n";
        cout << "'" << var(vals,names,cmd.substr(8 + cmdSplit[1].length())) << "' appended to file '" << var(vals,names,cmdSplit[1]) << "' as a line successfully.";
        } else {
            cerr << "Error 05: Unable to append to file";
        }
        file.close();
    } else if(cmdSplit[0] == "drop") {
        string orig = var(vals,names,cmdSplit[1]);
        char filename[orig.length() + 1];
        char ans;
        strcpy(filename,orig.c_str());
        cout << "Delete file " << var(vals,names,cmdSplit[1]) << "? [Y/n] ";
        cin >> ans;
        cin.ignore(256,'\n');
        if(ans == 'Y') {
            if(remove(filename) != -1) {
                cout << "File " << var(vals,names,cmdSplit[1]) << " deleted successfully.";
            } else {
                cerr << "Error 04: Unable to delete file '" << var(vals,names,cmdSplit[1]) << "'";
            }
        }
    } else if(cmdSplit[0] == "read") {
        string line;
        ifstream file(var(vals,names,cmdSplit[1]));
        if(file) {
            while(getline(file,line)) {
                cout << line << "\n";
            }
            file.close();
        } else {
            cerr << "Error 02: Unable to access file";
        }
    } else if(cmdSplit[0] == "create") {
        ofstream file(var(vals,names,cmdSplit[1]));
        if(!file) {
            cerr << "Error 03: Unable to create/truncate file";
        } else {
            cout << "File created/truncated successfully.";
        }
        file.close();
    } else {
        cerr << "Error 01: Invalid command";
    }
    cout << "\n";
    goto command;
}
