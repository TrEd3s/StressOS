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
#include <filesystem>
#include "extra.h"
#include <fstream>

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
	 * @filename Nombre del archivo
	 * @param size Tamaño del archivo en MB
	 * @return void
	 */
	static void ThreadFunction(int idx, string arg_filename, int size) {

		std[idx] = true;	// Marcar en el arreglo que el proceso inicio

		// Locate tmp forder
		string tmp_path = filesystem::temp_directory_path();
		string filename = tmp_path + "/" + arg_filename;

		// Create file
		ofstream ofile;
		ofile.open(filename);

		// Write in file
		for (int i = 0; i < (size * 1000); ++i) {
			srand(time(0x0) + i);
			ofile << randFileName() << endl;
		}

		// Flush buffer
		flush(ofile);

		// Close file
		ofile.close();

		// Open File
		ifstream ifile;
		ifile.open(filename);

		// Get file size
		unsigned long filesize = filesystem::file_size(filename);
//		cout << "File size:" << filesize << endl;

		// Read File
		for (unsigned long i = 0; i < filesize; ++i) {
			ifile.get();
		}

		// Close file
		ifile.close();

		// Delete file
		remove(filename.c_str());

		std[idx] = false; // Marcar en el arreglo que este proceso ha terminado
	}

	/**
	 * Crea e inicia todos los hilos
	 */
	static int start() {

		// Display
		int size = 50;
		cout << "Files Threads:\t\t" << n << endl;
		cout << "File size:\t\t" << size * 1000 << endl;

		// Iniciar todos los hilos
		for (int i = 0; i < n; i++) {
			srand(time(0x0) + i);
			thrds[i] = thread(ThreadFunction, i, randFileName(), size);
		}

		return 0;
	}

};

#endif /* FILEHANDLER_H_ */
