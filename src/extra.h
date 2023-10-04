/*
 * extra.h
 *
 *  Created on: Sep 17, 2023
 *      Author: edel
 */

#ifndef EXTRA_H_
#define EXTRA_H_

#include "string"

using namespace std;

/**
 * Retorna el tiempo en milisegundos desde 1970
 *
 * */
uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

/**
 * Calcula la sesion de fibonacci de un numero
 * @param n
 * @return fibonacci de n
 */
double fibo(double n) {
  if (n == 1 || n == 2) {
	return 1;
  } else {
	return fibo(n - 2) + fibo(n - 1);
  }
}

/**
 * Calcula el factorial de un numero
 * @param n
 * @return factorial de n
 */
double factorial(double n) {
  if (n == 1) {
	return 1;
  } else {
	return n * factorial(n - 1);
  }
}

/**
 * Genera numeros aleatorios enteros entre dos valores dados (incluidos)
 * @param min
 * @param max
 * @return Numero aletorio entero
 */
int randint(int min, int max) {
  // Establecer semilla
  // srand(time(NULL));

  return (rand() % (max - min)) +min;
}

/**
 * Genera nombre aleatorios (Secuencias de carcateres)
 * Cada nombre tiene una longitud de 15 caracteres
 * @return Nombre aleatorio
 */
string randFileName() {

	string name = "";

	for (int var = 0; var < 15; ++var) {
		name = name + char(randint(97,122));
	}

	return name;
}

#endif /* EXTRA_H_ */
