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
	 * Contiene el cuerpo de codigo a ejecutarse en cada hilo. Crea un archivo de
	 * un tamaño determinado y valores (BYTES) aleatorios de uno en uno, luego de
	 * cerrar el archivo vuelve a abrirse para entonces leerlo de uno en uno
	 *
	 * @param idx Indice del proceso en el arreglo de estados
	 * @param size Tamaño del archivo en MB
	 * @return void
	 */
	static void ThreadFunction(int idx, int size) {

		// Print once time
		if (printed == false) {
			cout << "Files Threads:\t\t" << n << endl;
			cout << "File size:\t" << size << endl;
			printed = true;
		}

		std[idx] = true;	// Marcar en el arreglo que el proceso inicio

		for (int i = 0; i < n; i++) {
			//list->insert(fibo(randint(min, max)));
		}

		std[idx] = false; // Marcar en el arreglo que este proceso ha terminado
	}

	/**
	 * Crea e inicia todos los hilos
	 */
	static int start() {

		// Iniciar todos los hilos
		for (int i = 0; i < n; i++) {
			thrds[i] = thread(ThreadFunction, i, 100);
		}

		return 0;
	}


};

#endif /* FILEHANDLER_H_ */
