Objetivo general:

Dise�ar, programar e implementar sistema embebido para una calculadora binaria de ocho bits

con las cuatro operaciones aritm�ticas b�sicas.

Objetivos espec�ficos:

1. Identificar cada uno de los cinco puertos de entrada y salida en el microcontrolador.

2. Reconocer caracter�sticas y funciones asociadas a cada una de las terminales de los cinco puertos.

3. Implementar arquitectura hardware/software para la soluci�n de la pr�ctica.

4. Generar proyecto para la aplicaci�n en lenguaje C.

5. Reconocer directivas de preprocesamiento necesarias para que el compilador reconozca la

configuraci�n general del microcontrolador objetivo.

6. Practicar funciones espec�ficas para la configuraci�n, entrada y salida de puertos digitales.

7. Practicar operadores aritm�ticos y l�gicos para la transformaci�n de informaci�n digital.

8. Comprobar resultado de la implementaci�n f�sica de la pr�ctica.

9. Documentar resultado de la implementaci�n f�sica de la pr�ctica.


Requerimientos de la pr�ctica:

1. Datos enteros de ocho bits sin signo para las cuatro operaciones aritm�ticas, ser�n ingresados por

dos DIP switches de ocho posiciones en configuraci�n Pull-Down conectados a los puertos C y D.

2. Cada operaci�n aritm�tica ser� activadas al presionar uno de los cuatro interruptores de presi�n

(push button) normalmente abiertos (NA) en Pull-Down conectados a las terminales RB7:RB4 del

puerto B.

3. El rebote producido por los interruptores de presi�n para la selecci�n de operaci�n deber� ser

eliminado con un arreglo electr�nico anti rebote.

4. El resultado de las operaciones se mostrar� inmediatamente despu�s de la selecci�n en 13 LEDs,

con resistencias limitadoras en serie, conectados a las terminales RA5:RA0, RB3:RB0 y RE2:RE0,

como se indica en la figura 3.1.

5. El suministro de corriente de cada terminal de salida para mostrar resultado, no debe exceder 8.0

mA de corriente para alimentar cada LED.

6. Considerar posiciones m�s y menos significativas del resultado en el formateo para cada puerto

de salida.

7. En la suma y multiplicaci�n no hay orden de ingreso de los datos de entrada. El producto ser�

truncado a 13 bits en todos los casos.

8. En la resta y divisi�n el puerto C ser� minuendo y dividendo respectivamente. En caso de inversi�n

de operandos: la diferencia deber� ser mostrada en C-2 con n=13 bits y rutina de error escogida

en caso de error.

9. Velocidad de procesamiento a 16 Mhz.

10. Voltaje de alimentaci�n a 5.0 Voltios, suministrado por m�dulo reductor y convertidor de Ac a DC

en el rango de 6.5 a 12.0 Voltios con al menos 250 mA de corriente.
