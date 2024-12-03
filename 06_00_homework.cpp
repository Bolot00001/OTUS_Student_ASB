using namespace std;

template <typename T>
class Consistent {
public:
	Consistent() :last_{ 0 }, value_n{ nullptr }, value_r{ nullptr } {}
	virtual ~Consistent() {}
	void push_back(const T& v) {
		T* value_n = new T[last_ + 1];
		for (size_t i = 0; i < last_; ++i) {
			value_n[i] = value_r[i];
		}
		value_n[last_] = v;
		delete[] value_r;
		value_r = value_n;
		last_ += 1;
	}
	bool insert(const size_t& itx, const T& v) {
		if (itx > last_) {
			std::cout << "Error index value " << '\n';
			return false;
		}
		T* value_n = new T[last_ + 1];
		int acc = 0;
		size_t ii = 0;
		for (size_t i = 0; i <= last_; ++i) {
			if (itx == i) {
				value_n[ii] = v;
				++ii;
				value_n[ii] = value_r[i];
				++ii;
			}
			else {
				value_n[ii] = value_r[i];
				++ii;
			}
		}
		//delete[] value_r;
		value_r = value_n;
		last_ += 1;
		return true;
	}
	bool erase(int* itx) {
		T* value_n = new T[last_ + 1];
		bool not_work = true;
		int acc = 0;
		size_t ii = 0;
		for (size_t i = 0; i < last_; ++i) {
			for (size_t ki = 0; ki < sizeof(itx); ++ki) {
				if ((i == itx[ki] - 1)) {
					not_work = false;
				}
			}

			if (not_work) {
				value_n[ii] = value_r[i];
				ii++;
			}
			else {
				acc++;
				not_work = true;
			}
		}
		delete[] value_r;
		value_r = value_n;
		last_ = last_ - acc;
		return true;
	}
	Consistent& operator=(const Consistent& rhs) {
		if (this != &rhs) {
			this->value_r = new T[rhs.last_];
			for (size_t i = 0; i < rhs.last_; ++i) {
				this->value_r[i] = rhs.value_r[i];
			}
			this->last_ = rhs.last_;
		}
		return *this;
	}
	size_t size() {
		std::cout << last_ << '\n';
		return last_;
	};
	T begin() {
		//std::cout << value_r[0] << '\n';
		return value_r[0];
	};
	T end() {
		//std::cout << value_r[last_ - 1] << '\n';
		return value_r[last_ - 1];
	};
	T& operator[](size_t itx) {
		//std::cout << value_r[itx] << '\n';
		return value_r[itx];
	}
	void print_consis() {
		for (size_t i = 0; i < last_; i++) {
			std::cout << value_r[i] << ',';
		}
	}
private:
	T* value_r;
	T* value_n;
	size_t last_;
};
