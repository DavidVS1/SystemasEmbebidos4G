#include <18F4620.h>
#include <stdlib.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT 
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7,STOP=1)  
#use standard_io(c)
#define tamanoBufer 11
//Variables globales
char Bufer[11];
int datoMalo=0;
int posicion=0;
int terminadoRDA=0;
int timeOut=0;
#int_rda
void rda_isr()
{     
      Bufer[posicion]=getc();
      if(Bufer[posicion]==0x0A || Bufer[posicion]==0x0D)     //Si recivio enter
      {
         terminadoRDA=1;
      }
      if(!(posicion<tamanoBufer-1))                         //Si no es menor de 9 (la ultima posici�n del vector para escribir), activa bandera para que termine la interrupci�n
      {
         terminadoRDA=1;
      }
      if(((Bufer[posicion]<'0' && Bufer[posicion]>'9') && Bufer[posicion]!='-' && Bufer[posicion]!='.'))     //Si no ingreso un numero, un - o un .   El dato no es valido
      {
         datoMalo=1;
      }
      posicion++;

}
void limpiarBufer();
void main(void)
{
   //Configuraciones del microcontrolador
   setup_oscillator(OSC_16MHZ);
   enable_interrupts(global);
   enable_interrupts(int_rda);
   SETUP_ADC_PORTS(NO_ANALOGS);
   //Variables
   inicio:   //Punto de retorno
   float primerOperando=0, segundoOperando=0, resultado=0;
   char operacion='0';
   ////
   while(true)
   {   
      //Inicializamos variables a 0 y limpiamos Bufer
      posicion=0;
      datoMalo=0;
      terminadoRDA=0;
      timeOut=0;
      limpiarBufer();
      
      printf("Practica No. 4\r");
      printf("Calculadora Aritmetica \r\r");
                                                  //primerOperando
      printf("Ingresa el primer operando \r");    //Indica al usuario que ingrese el primer operando    
      While(terminadoRDA==0);                   //Mientras no aya terminado de recivir la trama se queda ciclado
      if(datoMalo==1)                            //Si el dato ingresado no es correcto
      {
         printf("Error \r");
         if(timeOut==1)
         {
            printf("Se ha terminado el tiempo");
         }
         goto inicio;
      }
       if(Bufer[posicion-1]==0x0A || Bufer[posicion-1]==0x0D)     //Si la ultima tecla presionada fue enter, la hace igual a NULL
      {
         Bufer[posicion-1]=0;
      }
      primerOperando=atof(Bufer);                 //Asigna la cifra casteandola a un flotante, a primer operando en "primerOperando
      printf("%4.4f\r",primerOperando);              //Muestra el operando ingresado
      posicion=0;
      datoMalo=0;
      terminadoRDA=0;
      timeOut=0;
      limpiarBufer();
                                                    //segundoOperando
      printf("Ingresa el segundo operando \r");          //Indica al usuario que ingrese el segundo operando
      While(terminadoRDA==0);                   //Mientras no aya terminado de recivir la trama se queda ciclado
      if(datoMalo==1)                            //Si el dato ingresado no es correcto
      {
         printf("Error \r");
         if(timeOut==1)
         {
            printf("Se ha terminado el tiempo");
         }
         goto inicio;
      }
       if(Bufer[posicion-1]==0x0A || Bufer[posicion-1]==0x0D)     //Si la ultima tecla presionada fue enter, la hace igual a NULL
      {
         Bufer[posicion-1]=0;
      }
      segundoOperando=atof(Bufer);                    //Asigna la cifra casteandola a un flotante, a segundo operando en "segundoOperando"
      printf("%4.4f\r",segundoOperando);              //Muestra el operando ingresado
      posicion=0;
      datoMalo=0;
      terminadoRDA=0;
      timeOut=0;
      limpiarBufer();
      
                                                                 //Operacion
      printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");    //Indica al usuario que selecione segun su n�mero, una operaci�n 
      While(terminadoRDA==0);                   //Mientras no aya terminado de recivir la trama se queda ciclado
      if(datoMalo==1)                            //Si el dato ingresado no es correcto
      {
         printf("Error \r");
         if(timeOut==1)
         {
            printf("Se ha terminado el tiempo");
         }
         goto inicio;
      }
       if(Bufer[posicion-1]==0x0A || Bufer[posicion-1]==0x0D)     //Si la ultima tecla presionada fue enter, la hace igual a NULL
      {
         Bufer[posicion-1]=0;
      }
      operacion=Bufer[0];                      //Asigna la operaci�n casteandola a un flotante, a operacion
  
      //Saca resultado con los dos operadores ingresados y deacuerdo a la operaci�n seleccionada
      if(operacion=='1')   resultado=primerOperando+segundoOperando;          //suma
      else if(operacion=='2')   resultado=primerOperando-segundoOperando;     //resta
      else if(operacion=='3')   resultado=primerOperando*segundoOperando;     //multiplicacion
      else if(operacion=='4')   resultado=primerOperando/segundoOperando;     //divicion
      //Muestra resultado
      printf("El resultado de la operacion es: %4.4f\r\r",resultado);
   } 
}
void limpiarBufer()
{
   int i=0;
   for(i=0; i<tamanoBufer; i++)
   {
      Bufer[i]=0;
   }
}
