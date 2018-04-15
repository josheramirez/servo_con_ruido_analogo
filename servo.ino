///////////////////
LIBRERIAS
    #include <Servo.h>

///////////////////
VARIABLES 
    int Lecturas[10]; // guardo las ultima 10 lecturas (una lectura nueva por iteracion de loop)
    int Val, i = 0,
    Total = 0,
    Promedio = 0;
    Servo MiServo;
///////////////////
SETUP
    void setup(){
    MiServo.attach(9);
    Serial.begin(9600);
    for(i=0; i< 10; i++) //inicio vector en 0.
    Lecturas[i] = 0;
    i=0;
    }
///////////////////
LOOP
    void loop(){
    Total = Total – Lecturas[i];
    //Agrega una lectura a la posición actual dentro del vector
    Lecturas[i] = analogRead(A0);
    //agrego al total el nuevo valor leido en esta iteracion
    Total = Total + Lecturas[i];
    i = i + 1;
    //pregunto si ya llevo 10 lecturas ingresadas
    if (i >= 10){
    //reinicio la cuenta
    i = 0;
    //calculo el promedio y escribo en el servo
    Promedio = Total / 10;
    Val = map(Promedio, 0, 1023, 0, 179);
    MiServo.write(Val);
    Serial.println(Val, DEC);
    }
    }
