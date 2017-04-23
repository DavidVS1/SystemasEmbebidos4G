#include <18F4620.h>
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
   int8 primerOperando, segundoOperando, operacion;
   float resultado;
   char opcion;
   ////
   printf("Practica No. 4\r");
   printf("Calculadora Aritmetica \r\r");
   printf("Ingresa el primer operando \r");
   primerOperando=(getch())-48;;
   printf("Ingresa el segundo operando \r");
   segundoOperando=(getch())-48;
   printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");
   operacion=(getch())-48;
   while(true)
   {
      //Saca resultado con los dos operadores ingresados y deacuerdo a la operación seleccionada
      if(operacion==1)   resultado=primerOperando+segundoOperando;     //suma
      else if(operacion==2)   resultado=primerOperando-segundoOperando;     //resta
      else if(operacion==3)   resultado=primerOperando*segundoOperando;     //multiplicacion
      else if(operacion==4)   resultado=primerOperando/segundoOperando;     //divicion
      //Muestra resultado
      printf("El resultado de la operacion es: %f\r",resultado);
      getch(); //Espera toque de tecla
   }
}
 
