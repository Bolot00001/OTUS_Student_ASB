#include "06_01_homework.h"


template <typename T>
class Liste_princ {
public:
	Liste_princ() :last_{ 0 }, p_last{ nullptr } {}
	virtual ~Liste_princ() {}
	void push_back(const T& v) {
		Persep* new_pers = new Persep{};
		new_pers->next = nullptr;
		new_pers->prev = p_last;
		new_pers->value_d = v;
		if (p_last != nullptr) {
			p_last->next = new_pers;
		}
		p_last = new_pers;
		last_ += 1;
	}
	bool insert(const size_t& itx, const T& v) {
		begin();
		Persep* new_pers = new Persep{};
		Persep* current;
		size_t i = 0;
		if (itx > last_) {
			std::cout << "Error index value " << '\n';
			return false;
		}
		while (p_last->next != nullptr) {
			if (itx == i) {
				if (p_last->prev != nullptr) {
					current = p_last->prev;
					new_pers->prev = current;
					new_pers->next = p_last;
					new_pers->value_d = v;
					current->next = new_pers;
					p_last->prev = new_pers;
					++i;
				}
				else {
					new_pers->prev = nullptr;
					new_pers->next = p_last;
					new_pers->value_d = v;
					p_last->prev = new_pers;
					++i;
				}
			}
			else {
				p_last = p_last->next;
				++i;
			}
		}
		if ((itx == last_)&&(p_last->next == nullptr)) {
			current = p_last->prev;
			new_pers->prev = current;
			new_pers->next = nullptr;
			new_pers->value_d = v;
			current->next = new_pers;
			last_ += 1;
			return true;
		}
		last_ += 1;
		begin();
		return true;
	}
	bool erase(int* itx) {
		Persep* current = p_last;
		Persep* curr = p_last;
		T itr = begin();
		int acc = 0;
		bool not_work = true;
		size_t ii = 1;
		while (p_last->next != nullptr) {
			for (size_t ki = 0; ki < sizeof(itx); ++ki) {
				if ((ii == itx[ki])) {
					not_work = false;
				}
			}

			if (not_work) {
				p_last = p_last->next;
				ii++;
			}
			else {
				acc++;
				curr = p_last->prev;
				current = p_last->next;
				delete p_last;
				curr->next = current;
				current->prev = curr;
				p_last = current;
				//std::cout << curr->value_d << '\n';
				not_work = true;
				ii++;
			}
		}
		last_ = last_ - acc;
		return true;
	}
	Liste_princ& operator=(const Liste_princ& rhs) {
		if (this != &rhs) {
			//if (p_last != nullptr) {
			//	delete [] p_last;
			//}
			Liste_princ current = rhs;
			while (current.p_last != nullptr) {
				Persep* new_pers = new Persep{};
				new_pers->prev = p_last;
				new_pers->next = nullptr;
				new_pers->value_d = current.p_last->value_d;
				if (p_last != nullptr) {
					p_last->next = new_pers;
				}
				p_last = new_pers;
				current.p_last = current.p_last->next;
			}
		}
		last_ = rhs.last_;
		return *this;
	}
	size_t size() {
		std::cout << last_ << '\n';
		return last_;
	};
	T begin() {
		if (p_last->prev != nullptr) {
			while (p_last->prev != nullptr) {
				p_last = p_last->prev;
			}
		}
		return p_last->value_d;
	}
	T end() {
		Persep* current = p_last;
		while (current->next != nullptr) {
			//std::cout << current->value_d << " ";
			current = current->next;
		}
		return current->value_d;
	};
	T& operator[](size_t itx) {
		Persep* current = p_last;
		for(size_t i = 0; i < itx; ++i) {
			current = current->next;
		}
		return current->value_d;
		//std::cout << current->value_d << '\n';
	}
	void print_consis() {
		begin();
		Persep* current = p_last;
			while (current != nullptr){
				std::cout << current->value_d << " ";
				current = current->next;
			}
		//}
		std::cout << std::endl;
	}
		//for (size_t i = 0; i < last_; i++) {
		//	std::cout << value_r[i] << ',';
		//}	
private:
	struct Persep {
		Persep* next;
		Persep* prev;
		T value_d;
	};
	Persep* p_last;
	//Persep* value_r{nullptr};
	//Persep* value_n;
	size_t last_;
};



