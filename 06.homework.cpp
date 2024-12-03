
#include "06.homework.h"

#include "06_00_homework.cpp"

#include "06_01_homework.cpp"



int main()
{
	std::cout << "LIST CONTAINER" << '\n';
	Liste_princ<int> run_liste_princ;
	Liste_princ<int> rum_liste_princ;
	run_liste_princ.push_back(0);
	run_liste_princ.push_back(1);
	run_liste_princ.push_back(2);
	run_liste_princ.push_back(3);
	run_liste_princ.push_back(4);
	run_liste_princ.push_back(5);
	run_liste_princ.push_back(6);
	run_liste_princ.push_back(7);
	run_liste_princ.push_back(8);
	run_liste_princ.push_back(9);
	//run_liste_princ.print_consis();
	//std::cout<<run_liste_princ[1]<<'\n';
	std::cout << run_liste_princ.begin() << '\n';
	rum_liste_princ = run_liste_princ;
	//std::cout << ' ' << '\n';
	run_liste_princ.print_consis();
	run_liste_princ.size();
	std::cout << "RUM verify" << '\n';
	rum_liste_princ.print_consis();
	std::cout << rum_liste_princ[3] << '\n';
	std::cout << rum_liste_princ.end() << '\n';
	std::cout << ' ' << '\n';
	std::cout << ' ' << '\n';
	int krak[] = { 3,5,7 };
	run_liste_princ.erase(krak);
	run_liste_princ.print_consis();
	std::cout << "How was it" << '\n';
	rum_liste_princ.print_consis();
	std::cout << "Insert" << '\n';
	run_liste_princ.insert(0, 10);
	run_liste_princ.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "Insert" << '\n';
	run_liste_princ.insert(4, 20);
	run_liste_princ.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "Insert" << '\n';
	run_liste_princ.insert(run_liste_princ.size(), 30);
	run_liste_princ.print_consis();
	std::cout << ' ' << '\n';

	std::cout << "SEQUENTIAL CONTAINER" << '\n';
	Consistent<int> run_consistent;
	Consistent<int> rum_consistent;
	run_consistent.push_back(0);
	run_consistent.push_back(1);
	run_consistent.push_back(2);
	run_consistent.push_back(3);
	run_consistent.push_back(4);
	run_consistent.push_back(5);
	run_consistent.push_back(6);
	run_consistent.push_back(7);
	run_consistent.push_back(8);
	run_consistent.push_back(9);
	run_consistent.print_consis();
	std::cout << ' ' << '\n';
	std::cout << run_consistent[1] << '\n';
	std::cout << run_consistent.begin() << '\n';
	rum_consistent = run_consistent;

	std::cout << ' ' << '\n';
	run_consistent.print_consis();
	std::cout << ' ' << '\n';
	run_consistent.size();
	std::cout << "RUM verify" << '\n';
	rum_consistent.print_consis();
	std::cout << rum_consistent[3] << '\n';
	std::cout << rum_consistent.end() << '\n';
	std::cout << ' ' << '\n';
	std::cout << ' ' << '\n';
	int krek[] = { 3,5,7 };
	run_consistent.erase(krek);
	run_consistent.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "How was it" << '\n';
	rum_consistent.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "Insert" << '\n';
	run_consistent.insert(0, 10);
	run_consistent.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "Insert" << '\n';
	run_consistent.insert(4, 20);
	run_consistent.print_consis();
	std::cout << ' ' << '\n';
	std::cout << "Insert" << '\n';
	run_consistent.insert(run_consistent.size(), 30);
	run_liste_princ.print_consis();
	std::cout << ' ' << '\n';
}