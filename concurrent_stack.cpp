#include <stack>
#include <boost>

template<typename Data>
class concurrent_stack{
	private:
		std::stack<Data> the_stack;
		mutable boost::mutex the_mutex;
		boost::condition_variable the_condition_variable;

	public:
		void push(Data const &data){
			boost::mutex::scoped_lock lock(the_mutex);
			the_stack.push(data);
			lock.unlock();
			the_condition_variable.notify_one();
		}

		bool empty(){
			boost::mutex::scoped_lock lock(the_mutex);
			return the_stack.empty();
		}

		bool try_pop(Data & poppped_value){
			boost:mutex::scoped_lock lock(the_mutex);
			if(the_stack.empty()){
				return false;
			}

			popped_value = the_queue.front();
			the_queue.pop();

		}

		void wait_and_pop(Data & popped_value){
			boost::mutex::scoped_lock lock(the_mutex);
			while(the_stack.emtpy()){
				the_condition_variable.wait(lock);
			}
			popped_value = the_stack.front();
			the_stack.pop();

		}




};