//============================================================================
// Name        : StressOS.cpp
// Author      : Edel Rodriguez
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <sys/time.h>
#include <ctime>
#include <iostream>
#include <thread>
#include <time.h>

#include "ThreadHandler.h"
#include "FileHandler.h"

using namespace std;

// ThreadHandler inicialization
int ThreadHandler::n = 400; // Numero de procesos identicos que seran creados
thread *ThreadHandler::thrds = new thread[n]; 	// Arreglo de hilos
bool *ThreadHandler::std = new bool[n]; // Arreglo para almacenar el estado de cada proceso
bool ThreadHandler::printed = false; 	// Bandera para imprimir solo una vez

// FileHandler inicialization
int FileHandler::n = 50; // Numero de procesos de archivo identicos que seran creados
thread *FileHandler::thrds = new thread[n]; 	// Arreglo de hilos
bool *FileHandler::std = new bool[n]; // Arreglo para almacenar el estado de cada proceso
bool FileHandler::printed = false; 	// Bandera para imprimir solo una vez

int main(int argc, char **argv) {

	long t0, t1;

	// Show Init status
	cout << "RAM threads:\t\t" << ThreadHandler::n << endl;

	t0 = timeSinceEpochMillisec();

	//ThreadHandler::start();		// Inicio de los procesos de RAM y CPU
	FileHandler::start();			// Inicio de los procesos de archivo

	// Ciclo de revision de estado de procesos
	bool fl = true;
	while (fl) {
		fl = false;
		for (int i = 0; i < FileHandler::n; i++) {
			fl = fl || FileHandler::std[i];
		}
	}

	t1 = timeSinceEpochMillisec();

	cout << "System time spent:\t" << (t1 - t0) / 1000.0 << "ms" << endl;

	return 0;
}
