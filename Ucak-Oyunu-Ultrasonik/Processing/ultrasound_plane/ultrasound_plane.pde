//Uçak Oyunu -

int i, j; 

float Hauteur; //en Y
float Angle;
int DistanceUltra;
int IncomingDistance;
//float Pas; //pour deplacements X

float BirdX;
float BirdY;




String DataIn; //incoming data

//5 a 32 cm


float [] CloudX = new float[6];
float [] CloudY = new float[6];

//vitesse constante hein


PImage Cloud;
PImage Bird;



// serial port config
import processing.serial.*; 
Serial myPort;    



//preparation
void setup() 
{

    myPort = new Serial(this, Serial.list()[0], 9600); 


    myPort.bufferUntil(10);   //end the reception as it detects a carriage return

    frameRate(30); 

    size(800, 600);
    rectMode(CORNERS) ; //we give the corners coordinates 
    noCursor(); //why not ?
    textSize(16);

    Hauteur = 300; //initial plane value


    Cloud = loadImage("cloud.png");  //load a picture
    Bird = loadImage("bird.png");  

    //int clouds position
    for  (int i = 1; i <= 5; i = i+1) {
        CloudX[i]=random(1000);
        CloudY[i]=random(400);
    }
}



//incoming data event on the serial port
void serialEvent(Serial p) { 
    DataIn = p.readString(); 
    // println(DataIn);

    IncomingDistance = int(trim(DataIn)); //conversion from string to integer

    println(IncomingDistance); //checks....

    if (IncomingDistance>1  && IncomingDistance<100 ) {
        DistanceUltra = IncomingDistance; //save the value only if its in the range 1 to 100     }
    }
}


//main drawing loop
void draw() 
{
    background(0, 0, 0);
    Ciel();
    fill(5, 72, 0);

    rect(0, 580, 800, 600); //some grass

    text(Angle, 10, 30); //debug things...
    text(Hauteur, 10, 60); 


    //Angle = mouseY-300; //uncomment this line and comment the next one if you want to play with the mouse
    Angle = (18- DistanceUltra)*4;  // you can increase the 4 value...

    Hauteur = Hauteur + sin(radians(Angle))*10; //calculates the vertical position

    //check the height range to keep the plane on the screen 
    if (Hauteur < 0) {
        Hauteur=0;
    }

   
    if (Hauteur > 600) {
        Hauteur=600;
    }

    TraceAvion(Hauteur, Angle);

    BirdX =   BirdX -  cos(radians(Angle))*10;

    if (BirdX < -30) {
        BirdX=900;
        BirdY = random(600);
    }

    //draw and move the clouds
    for  (int i = 1; i <= 5; i = i+1) {
        CloudX[i] =   CloudX[i] -  cos(radians(Angle))*(10+2*i);

        image(Cloud, CloudX[i], CloudY[i], 300, 200);

        if (CloudX[i] < -300) {
            CloudX[i]=1000;
            CloudY[i] = random(400);
        }
    }

    image(Bird, BirdX, BirdY, 120, 43); //displays the useless bird. 59 and 38 are the size in pixels of the picture
}


void Ciel() {
    //draw the sky

    noStroke();
    rectMode(CORNERS);

    for  (int i = 1; i < 600; i = i+10) {
        fill( 49    +i*0.165, 118   +i*0.118, 181  + i*0.075   );
        rect(0, i, 800, i+10);
    }
}


void TraceAvion(float Y, float AngleInclinaison) {
    //draw the plane at given position and angle

    noStroke();
    pushMatrix();
    translate(400, Y);
    rotate(radians(AngleInclinaison)); //in degres  ! 


    /*
    Drawing concept :  ;-)
     
     |\___o__
     ________>     
     
     */

    scale(0.5);  //0.2 pas mal
    fill(255, 0, 0);
    stroke(0, 0, 0);
    strokeWeight(2);
    ellipse(292-228, 151-85, 45, 45); //roue

    line(373-228, 145-85, 373-228, 20-85); //helice


    strokeWeight(1); //main thickness


    beginShape();
    //poorly drawn plane

    vertex(214, 120);
    vertex(32, 82);
    vertex(32, 76 );
    vertex(15, 71);
    vertex(35, 69);
    vertex(35, 21);
    vertex(49, 21);
    vertex(57, 24);
    vertex(70, 30);
    vertex(79, 43);
    vertex(81, 58);
    vertex(95, 68);
    vertex(161, 62);
    vertex(187, 59);
    vertex(239, 59);
    vertex(242, 42);
    vertex(296, 40);
    vertex(297, 58);
    vertex(351, 59);
    vertex(365, 67);
    vertex(373, 82);
    vertex(364, 98);
    vertex(339, 109);
    vertex(305, 118);
    vertex(273, 133);

    translate(-228, -85); //centering...

    endShape(CLOSE);

    fill(0, 0, 0);

    fill(255, 128, 0);

    popMatrix();
}

//file end