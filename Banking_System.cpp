#include <iostream>
#include <string>
#include <chrono>
#include <thread>

//////////Function declarations 
int main();
void runtime();
void new_user(); 
void existing_user();
void deposit();


//////////main starts 
int main(){
	runtime();
	return 0;
}
/////////main ends

////////////////Member starts
class member {
public: 

//////////////////////Set function declarations starts
	void set_name(std::string a);
	void set_password(std::string b);
	void change_chequings(double c);
	void set_next(member *temp);
////////////////////set function declarations ends

///////////////////get functions starts
	std::string get_name();
	std::string get_password();
	double get_chequings(); 
	member* get_next();
//////////////////get functions ends

	member(std::string start_name, std::string start_password, double start_chequings);
	~member(); 
private: 


	std::string name{ "\0" };
	std::string password{};
	double chequings{};
	member* p_next{nullptr};
};
///////////////////////member ends

/////////////////////Insert starts
void insert(member * a);
////////////////////Insert ends

///////////////////////////p head here
member* p_head{nullptr};
//////////////////////////p head here


//////////////////length starts

int length(member* something);

int length(member* something) {
	int count{};
	if (p_head == nullptr) {
		return 0;
	}
	if (p_head->get_next() == nullptr) {
		return 1;
	}
	for (member* temp{ p_head }; temp->get_next() != nullptr; temp = temp->get_next(),count++) {

	}
	return count;
}
//////////////////length ends

////////////////////////////////////////////////Set member functions starts
///////////////set next starts
void member:: set_next(member* temp) {
	p_next = temp;
}
//////////////set next ends

/////////////set name starts
void member::set_name(std::string a) {
	name = a;
}
////////////set name ends

////////////set password starts
void member::set_password(std::string b) {
	password = b;
}
///////////set password ends

/////////change chequings starts
void member::change_chequings(double c) {
	chequings += c;
}
/////////change chequings ends
////////////////////////////////////////////////Set member functions end


/////////////////////////////////////////////////Get member functions starts
///////////////////get next starts
member *member::get_next() {
	return p_next;
}
/////////////////get next ends

/////////////get name starts
std::string member:: get_name() {
	return name;
}
///////////get name ends

///////////get password starts
std::string member:: get_password() {
	return password;
}
////////////get password ends

/////////////get chequings ends
double member:: get_chequings() {
	return chequings;
}
/////////////get chequings ends
//////////////////////////////////////////get member functions end




/////////////////member constructor starts
member::member(std::string start_name, std::string start_password, double start_chequings) {
	name = start_name;
	password = start_password;
	chequings = start_chequings;
	p_next = nullptr;
}
//////////////member constructor ends


/////////////Insert starts 
void insert(member* a) {
	int done{};
	if (p_head == nullptr) {
		p_head = a;
		done = 1;
	}
	if (p_head->get_next() == nullptr && p_head != nullptr && done != 1) {
		p_head->set_next(a);
	}	

	for (member* tmp{ p_head }; tmp->get_next() != nullptr; tmp = tmp->get_next()) {
		a = tmp;
	}
	
}
///////////Insert ends


//////////runtime starts
void runtime() {
	////////Local variables starts
	std::string user{"\0"};
	std::string new_user_confirm{"\0"};


	////////Local variables end


	std::cout << "Hello, welcome to the Bank of Berisha." << std::endl;
	std::cout << "Do you have an account with us?" << std::endl; 
	std::cout << "1: Yes" << std::endl;
	std::cout << "2: No" << std::endl;
	std::cout << "Please enter 1 or 2 for the options above."<<std::endl;
	std::cin >> user;
	if (user != "1" && user != "2") {
		int too_much{};
		while (user != "1" && user != "2") {
			std::cout << std::endl; 
			if (too_much >= 10) {
				std::cout << "WHAT ARE YOU DOING BRO!" << std::endl;
				std::cout << "Just pick 1 or 2!" << std::endl;
			}
			
			std::cout << "Please enter 1 or 2." << std::endl; 
			std::cout << "1: Existing user" << std::endl; 
			std::cout << "2: Make new account" << std::endl;
			std::cin >> user;
			too_much++;
		}
	}
	if (user == "1") {
		existing_user();
	}
	if (user == "2") {
		std::cout << "Would you like to make a new account with us?" << std::endl;
		std::cout << "1: Yes " << std::endl;
		std::cout << "2: No " << std::endl;
		std::cin >> new_user_confirm;
		if (new_user_confirm == "1") {
			new_user();
		}
		if (new_user_confirm == "2") {
			std::cout << "Thank you banking with us!" << std::endl;
			std::cout << "We hope to see you again" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	} 

}
/////////runtime ends 

////////New user starts
void new_user() {
	////////Local variables start
	std::string new_account{};
	std::string pre_name{ "\0" };
	std::string name_confirm{ "\0" };
	std::string pre_password{ "\0" };
	std::string pre_password_match{ "\0" };
	double initial_deposit{};
	std::string deposit_confirm{ "\0" };
	///////Local variables end

	std::cout << "Welcome new customer!" << std::endl; 
	std::cout << "Would you like to make a new account?" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "1: Yes" << std::endl;
	std::cout << "2: No" << std::endl; 
	std::cin >> new_account;
	if (new_account != "1" && new_account != "2") {
		while (new_account != "1" && new_account != "2") {
			std::cout << std::endl;
			std::cout << "Please enter 1 or 2" << std::endl;
			std::cout << "1: New account" << std::endl;
			std::cout << "2: Exit" << std::endl;
			std::cin >> new_account;
		}
	}
	if (new_account == "1") {
		std::cout << std::endl;
		std::cout << "What would you like your account name to be?" << std::endl;
		std::cout << "Enter here:";
		std::cin >> pre_name;
		std::cout << std::endl;
		std::cout << "You would like your name to be " << pre_name << "?" << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		std::cin >> name_confirm;
		if (name_confirm != "1" && name_confirm != "2") {
			while (name_confirm != "1" && name_confirm != "2") {
				std::cout << std::endl;
				std::cout << "Please select 1 or 2." << std::endl;
				std::cout << "1: Yes. Confirm name." << std::endl;
				std::cout << "2: No. Choose different name." << std::endl;
				std::cin >> name_confirm;
			}
		}
		if (name_confirm == "2") {
			while (name_confirm == "2") {
				std::cout << std::endl;
				std::cout << "What would you like your name to be?" << std::endl;
				std::cout << "Enter here: ";
				std::cin >> pre_name;
				std::cout << "You would like your name to be " << pre_name << "?" << std::endl;
				std::cout << "1: Yes" << std::endl;
				std::cout<<"2: No"<<std::endl;
				std::cin >> name_confirm;
				if (name_confirm != "1" && name_confirm != "2") {
					while (name_confirm != "1" && name_confirm != "2") {
						std::cout << std::endl;
						std::cout << "Please select 1 or 2." << std::endl;
						std::cout << "1: Yes. Confirm name." << std::endl;
						std::cout << "2: No. Choose different name." << std::endl;
						std::cin >> name_confirm;
					}
				}
			}
		}
		if (name_confirm == "1") {
			std::cout << "Please create a password." << std::endl;
			std::cout << "Note - The characters will be visible" << std::endl;
			std::cout << "Enter here: ";
			std::cin >> pre_password;
			std::cout << "Please enter again to confirm." << std::endl;
			std::cin >> pre_password_match;
			if (pre_password != pre_password_match) {
				while (pre_password != pre_password_match) {
					std::cout << "The passwords don't match." << std::endl;
					std::cout << "Please enter password again" << std::endl;
					std::cout << "Enter here: ";
					std::cin >> pre_password;
					std::cout << "Please enter password to confirm" << std::endl;
					std::cout << "Enter here: ";
					std::cin >> pre_password_match;
				}
			}
		}
		member* new_member(new member(pre_name,pre_password,0));
		insert(new_member);

		std::cout << "Your account has been created with the username \'" << pre_name <<"\'"<< std::endl;
		std::cout << "Would you like to make a deposit?" << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		std::cin >> deposit_confirm;
		if (deposit_confirm != "1" && deposit_confirm != "2") {
			while (deposit_confirm != "1" && deposit_confirm != "2") {
				std::cout << "Please select 1 or 2." << std::endl;
				std::cout << "1: Make deposit." << std::endl;
				std::cout << "2: Exit." << std::endl;
				std::cin >> deposit_confirm;
			}
		}
		if (deposit_confirm == "1") {
			deposit();
		}
	}
	if (new_account == "2") {
		std::cout << "Thank you for banking with us." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}
///////New user ends

//////////Deposit starts
void deposit() {
	std::string confirm_depo{"\0"};
	double deposit_amnt{};
	std::string conf_amnt{ "\0" };
	std::string name{"\0"};
	int name_count{};
	std::string pass{"\0"};
	int pass_count{};

	std::cout << std::endl;
	std::cout << "Hello, would you like to make a deposit?" << std::endl;
	std::cout << "1: Yes" << std::endl;
	std::cout<<"2: No"<<std::endl;
	std::cin >> confirm_depo;
	if (confirm_depo != "1" && confirm_depo != "2") {
		while (confirm_depo != "1" && confirm_depo != "2") {
			std::cout << "Please select 1 or 2." << std::endl;
			std::cout << "1: I would like to make a deposit." << std::endl;
			std::cout << "2: I would not like to make a deposit." << std::endl;
			std::cin >> confirm_depo;
		}
	}
	if (confirm_depo == "2") {
	std::cout << "Thank you for banking with us." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	if (confirm_depo == "1") {
		std::cout << "How much would you like to deposit?" << std::endl;
		std::cout << "Enter here: ";
		std::cin >> deposit_amnt;
		std::cout << "You'd like to deposit " << deposit_amnt << "?" << std::endl;
		std::cout<<"1: Yes" << std::endl;
		std::cout << "2: No, get me the hell out of here" << std::endl;
		std::cin >> conf_amnt;
		if (conf_amnt != "1" && conf_amnt != "2") {
			std::cout << "Please select 1 or 2" << std::endl;
			std::cout << "1: That is the correct amount" << std::endl;
			std::cout << "2: No that is incorrect" << std::endl;
			std::cin >> conf_amnt;
		}
	}
	if (conf_amnt == "1") {
		std::cout << "Please enter your name." << std::endl;
		std::cout << "Enter here: ";
		std::cin >> name;
		std::cout << "Please enter your password." << std::endl;
		std::cout << "Note - The characters will be visible." << std::endl;
		std::cout << "Enter here:";
		std::cin >> pass;
		int stop{};
		int count_to_stop{};
		for (member* temp{p_head}; stop != 1 || count_to_stop < length(temp); temp = temp->get_next(),++count_to_stop) {
			name_count = 0;
			pass_count = 0;
			if (temp->get_name() == name) {
				name_count = 1;
			} if (temp->get_password() == pass) {
					pass_count = 1;
			}
			if (name_count == 1 && pass_count == 1) {
				stop = 1;
				std::cout << "Welcome " << name << "!" << std::endl;
				temp->change_chequings(deposit_amnt);
				std::cout << "Your selected amount has been deposited." << std::endl;
				std::cout << "Thank you for banking with us." << std::endl;
			}
		}
		if (stop != 1) {
			std::cout << "We did not find any account with that info." << std::endl;
		}
	}	
}


///////Existing user starts
void existing_user() {
	std::string name{"\0"};
	std::string password{ "\0" };	
	int name_count{};
	int pass_count{};
	int stop{};
	std::cout << "Welcome back" << std::endl;
	std::cout << "Please enter your name and password." << std::endl;
	std::cout << "Name here: ";
	std::cin >> name;
	std::cout << "Password here: ";
	std::cin >> password;
	member* other_temp{ p_head };
	if (other_temp != nullptr) {
		for (member* temp{ p_head }; temp->get_next() != nullptr || stop != 1; temp = temp->get_next()) {

			if (name == temp->get_name()) {
				name_count = 1;
			}
			if (password == temp->get_password()) {
				pass_count = 1;
			}
			if (pass_count == 1 && name_count == 1) {
				stop = 1;
			}
		}
		
	}
	if (pass_count != 1 && name_count != 1) {
		std::cout << "There is no existing user with those credentials." << std::endl;
		std::cout << "Feel free to try again." << std::endl;
	}
}
/////Existing user ends






