/*
 * ThreadHandler.h
 *
 *  Created on: Sep 17, 2023
 *      Author: edel
 */

#ifndef THREADHANDLER_H_
#define THREADHANDLER_H_

#include <iostream>
#include <thread>
#include "extra.h"
#include "SortedList.h"

using namespace std;

class ThreadHandler {
private:

public:

	static int n; // Numero de procesos identicos que seran creados
	static thread *thrds; // Arreglo de hilos
	static bool *std; // Arreglo para almacenar el estado de cada proceso
	static bool printed;	// Bandera para imprimir solo una vez

	ThreadHandler() {
	}

	virtual ~ThreadHandler() {
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

		int n_items = load * 100;		// List items amount
		int min = load / 10;
		int max = min + 10;

		std[idx] = true;	// Marcar en el arreglo que el proceso inicio

		for (int i = 0; i < n_items; i++) {
			list->insert(fibo(randint(min, max)));
		}

		std[idx] = false; // Marcar en el arreglo que este proceso ha terminado
		delete list;
	}

	/**
	 * Crea e inicia todos los hilos
	 */
	static int start() {

		// Inits calcs
		int load = 100;

		// Display
		cout << "RAM threads:\t\t" << ThreadHandler::n << endl;
		cout << "Thread load:\t\t" << load << endl;
		cout << "Items in each thread:\t" << load * 100 << endl;

		// Iniciar todos los hilos
		for (int i = 0; i < n; i++) {
			thrds[i] = thread(ThreadFunction, i, load);
		}

		return 0;
	}

};

#endif /* THREADHANDLER_H_ */
