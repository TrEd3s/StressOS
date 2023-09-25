/*
 * FileHandler.h
 *
 *  Created on: Sep 23, 2023
 *      Author: edel
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <iostream>
#include <thread>
#include "extra.h"

using namespace std;

class FileHandler {
public:

	static int n; // Numero de procesos identicos que seran creados
	static thread *thrds; // Arreglo de hilos
	static bool *std; // Arreglo para almacenar el estado de cada proceso
	static bool printed;	// Bandera para imprimir solo una vez

	FileHandler() {
	}

	virtual ~FileHandler() {
	}

	/**
	 * Funcion principal del hilo
	 *
	 * Contiene el cuerpo de codigo a ejecutarse en cada hilo. Crea una lista
	 * dinamica ordenada. Los valores en la lista son el fobonacci de numeros
	 * aleatorios generados.
	 *
	 * @param idx Indice del proceso en el arreglo de estados
	 * @param load Indice de carga del proceso. 100 valor promedio
	 * @return void
	 */
	static void ThreadFunction(int idx, int load) {
		SortedList *list = new SortedList();

		int n = load * 100;
		int min = load / 10;
		int max = min + 10;

		// Print once time
		if (printed == false) {
			cout << "Thread load:\t\t" << load << endl;
			cout << "Items in each thread:\t" << n << endl;
			cout << "Min/max Fibonacci:\t" << min << "/" << max << endl;
			printed = true;
		}

		std[idx] = true;	// Marcar en el arreglo que el proceso inicio

		for (int i = 0; i < n; i++) {
			list->insert(fibo(randint(min, max)));
		}

		std[idx] = false; // Marcar en el arreglo que este proceso ha terminado
		delete list;
	}

};

#endif /* FILEHANDLER_H_ */
