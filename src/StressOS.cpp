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

#include "ThreadHandler.h"

using namespace std;

int ThreadHandler::n = 400; // Numero de procesos identicos que seran creados
thread *ThreadHandler::thrds = new thread[n]; 	// Arreglo de hilos
bool *ThreadHandler::std = new bool[n]; // Arreglo para almacenar el estado de cada proceso
bool ThreadHandler::printed = false; 	// Bandera para imprimir solo una vez

int main(int argc, char **argv) {

	long t0, t1;

	// Show Init status
	cout << "RAM threads:\t\t" << ThreadHandler::n << endl;

	t0 = timeSinceEpochMillisec();
	ThreadHandler::start();
	t1 = timeSinceEpochMillisec();

//	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "System time spent:\t" << (t1 - t0) / 1000.0 << "ms" << endl;

	return 0;
}
