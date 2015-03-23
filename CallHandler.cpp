
#include <queue>
#include <list>

#define NUM_RESPONDENTS 20
#define NUM_MANAGERS 4
#define NUM_DIRECTORS 2


using namespace std;

class CallHandler{
private:
	CallHandler(){}; //private so it can't be called
	CallHandler(CallHandler const&){}; // copy constructor
	CallHandler& operator=(CallHandler const&){};  // assignment operator
	static CallHandler *instance;


	queue<Call> pendingRespondentCalls;
	list<Manager> managerList;
	list<Director> directorList;
	list<queue<Call> > respondentList;

public:
	static CallHandler *Instance();
	Employee getHandlerForCall(Call call){};
	void dispatchCall(Caller caller){};
	void dispatchCall(Call call){};
	bool assignCall(Call call){};
};

CallHandler * CallHander::Instance(){
	if (!instance){
		instance = new CallHandler();
	}
	return instance;
}

class Call{
private:
	Caller caller;
	Rank rank;
	Employee handler;

public:
	Call(Caller c){
		rank = Rank.Responder;
		caller = c;
	}
	void setHandler(Employee handler){};
	void reply(string message){};
	Rank getRank(){};
	void incrementRank(){};
	void disconnect(){};
};

class Employee{
private:
	Name name;
	Rank rank;
	Call currentCall = NULL;

public:
	Employee(){};
	void callComplete(){};
	void escalateAndReassign(){};
	bool assignNewCall(Call call){};
	bool isFree(){};
	Rank getRank(){};


};


