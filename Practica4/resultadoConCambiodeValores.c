#include <18F4620.h>
#include <stdlib.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT 
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(UART1,BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_B0,RCV=PIN_B1,STOP=1)  
#use standard_io(b)

void main(void)
{
   //Configuraciones
   setup_oscillator(OSC_16MHZ);
   //Variables
   unsigned int8 primerOperando=0, segundoOperando=0, operacion=0;
   float resultado;
   char opcion;
   char cifra[3];             //Variable para obtener la cifra de los numeros de los dos operandos
   ////
   printf("Practica No. 4\r");
   printf("Calculadora Aritmetica \r\r");
   printf("Ingresa el primer operando \r");    //Indica al usuario que ingrese el primer operando
   gets(cifra);                                //Obtiene la cifra en forma de cadena
   primerOperando=atoi(cifra);                 //Asigna la cifra casteandola a un entero, a primer operando en "primerOperando"
   printf("%u\r",primerOperando);              //Muestra el operando ingresado
   printf("Ingresa el segundo operando \r");   //Indica al usuario que ingrese el segundo operando
   gets(cifra);                                //Obtiene la cifra en forma de cadena           
   segundoOperando=atoi(cifra);                 //Asigna la cifra casteandola a un entero, a segundo operando en "segundoOperando"
   printf("%u\r",segundoOperando);              //Muestra el operando ingresado
   printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");    //Indica al usuario que selecione segun su n�mero, una operaci�n
   operacion=(getch())-48;              //Ingresa la operaci�n seleccionada
   while(true)
   {
      //Saca resultado con los dos operadores ingresados y deacuerdo a la operaci�n seleccionada
      if(operacion==1)   resultado=(float)primerOperando+(float)segundoOperando;     //suma
      else if(operacion==2)   resultado=(float)primerOperando-(float)segundoOperando;     //resta
      else if(operacion==3)   resultado=(float)primerOperando*(float)segundoOperando;     //multiplicacion
      else if(operacion==4)   resultado=(float)primerOperando/(float)segundoOperando;     //divicion
      //Muestra resultado
      printf("El resultado de la operacion es: %f\r\r",resultado);
      printf("�Que parametro desea cambiar?\r   P)Primer operando  S)Segundo operando  O)Operacion\r");  //Muestra opciones para cambiar parametros
      opcion=getch();    //Guarda que parametro eligio cambiar en "opcion"
      if(opcion=='P')   //Si desea cambiar el primer operando, entonces
      {
         printf("Ingresa el primer operando \r");   //Indica al usuario que ingrese el primer operando
         gets(cifra);                                //Obtiene la cifra en forma de cadena
         primerOperando=atoi(cifra);                 //Asigna la cifra casteandola a un entero, a primer operando en "primerOperando"
         printf("%u\r",primerOperando);              //Muestra el operando ingresado
      }
      else if(opcion=='S')   //Si desea cambiar el segundo operando, entonces
      {
         printf("Ingresa el segundo operando \r");   //Indica al usuario que ingrese el segundo operando
         gets(cifra);                                //Obtiene la cifra en forma de cadena           
         segundoOperando=atoi(cifra);                 //Asigna la cifra casteandola a un entero, a segundo operando en "segundoOperando"
         printf("%u\r",segundoOperando);              //Muestra el operando ingresado
      }
      else if(opcion=='O')  //Si desea cambiar la operaci�n, entonces
      {
         printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");    //Indica al usuario que selecione segun su n�mero, una operaci�n
         operacion=(getch())-48;              //Ingresa la operaci�n seleccionada
      }
   }
}