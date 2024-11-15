#include <iostream>
#include <limits>
#include <string>
#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{ std::numeric_limits<double>::lowest() } {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char* name() const override {
		return "max";
	}

private:
	double m_max; 
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{ std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		m_mean = m_mean +next;
		count_e++;
	}

	double eval() const override {
		return m_mean / count_e;
	}

	const char* name() const override {
		return "mean";
	}

private:
	double m_mean = 0;
	int count_e = 0;
};

class Std : public IStatistics {
public:
	Std() : m_std{ std::numeric_limits<double>::min() } {
	}

	void update(double next) override {
		cont_std.push_back(next);
		Std_res(cont_std, m_std);
	}
	double eval() const override {
		return m_std;
	}

	const char* name() const override {
		return "std";
	}

private:
	void Std_res(std::vector<double> cont_sstd, double& m_sstd) {
		double sum_all = 0.0;
		double mean = 0.0;
		double sum_pw = 0.0;
		double std_inc = 0.0;
		for (const auto& cont_s : cont_sstd) {
			sum_all += cont_s;
		}
		mean = sum_all / (cont_sstd.size());

		for (const auto& cont_pw : cont_sstd) {
			sum_pw += pow(cont_pw - mean, 2) / (cont_sstd.size() - 1);
			
		}
		m_sstd = sqrt(sum_pw);
		//return std_inc;
	}
	double m_std = 0;
	std::vector<double> cont_std;
};


int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};

	double val = std::numeric_limits<double>::max();
	
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << std::to_string(statistics[i]->eval()) << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}