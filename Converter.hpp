#ifndef CONVERTER_HPP_INCLUDED
#define CONVERTER_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;

class Converter{
private:
    const int Caracteres_Size = 39; //Array of characters sorted by number of black pixels
   // string Caracteres[] = {"a","b","c"};
    ofstream result;
    Image Foto;
public:
    Converter(const char* imageLocation,const char* fileLocation){
        //const char* fileAdd = fileLocation.c_str();
        //const char* imageAdd = imageLocation.c_str();
        result.open(fileLocation);
        Foto.loadFromFile(imageLocation);
    }
    ~Converter(){
        result.close();
    }
    void processImage(){
        Vector2u Dimensiones = Foto.getSize();

        Color actual;
        string Caracteres[] = {"@", "N","%","Q", "g", "m", "$", "B", "D", "R","#", "8", "d", "O", "b", "U", "A", "q", "h", "G", "p" ,"X", "k", "u", "n", "x","c", "/","*", "+" ,";", "^", "=", " ´" ,":", " _", " .", " `", " "};
        for(int i=0;i<=Dimensiones.y;i++){
            for(int j=0;j<=Dimensiones.x;j++){
                actual = Foto.getPixel(j,i);
                float GreyScale = (actual.r + actual.g + actual.b)/3;
                int nivelSaturacion = (int)((GreyScale/255)*(Caracteres_Size-1));
                result << Caracteres[nivelSaturacion] << "  ";
            }
            result << "\n";
        }
        cout << "Image converted!" << endl;
    }
};

#endif // CONVERTER_HPP_INCLUDED
